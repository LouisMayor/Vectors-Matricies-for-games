// Main.cpp: A program using the TL-Engine

#include "4x4_Matrix.h"

#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;
using namespace math;

void game_update( float _delta );

I3DEngine* myEngine = New3DEngine( kTLX );

ICamera* main_camera;

IMesh*	 box_mesh;
IModel*	 box_model;
IModel*	 mirror_box_model;
IMesh*	 floor_mesh;
IModel*	 floor_model;

float    elements_copy[16];
Matrix4x4 example;

// Fixed update rate
const float MONITOR_REFRESH_RATE = 1.f / 60.f;  // In Hertz
float		timerCurrent = 0.f;
const float timerTotal = 1.f;

const float rotatation_rate = 1.5f;
const float translation_rate = 10.f;
const float scale_rate = 1.1f;

void main( ) {
	// Create a 3D engine (using TLX engine here) and open a window for it	
	myEngine->StartWindowed( );

	// local media folder
	myEngine->AddMediaFolder( ".\\Media" );

	main_camera = myEngine->CreateCamera( kManual, 50.0f, 0.0f, -20.0f );
	main_camera->RotateLocalY( 270.f );

	box_mesh = myEngine->LoadMesh( "Cube.x" );
	box_model = box_mesh->CreateModel( 0.0f, 0.0f, 0.0f );
	mirror_box_model = box_mesh->CreateModel( 0.0f, 0.0f, 0.0f );

	floor_mesh = myEngine->LoadMesh( "Floor.x" );
	floor_model = floor_mesh->CreateModel( 0.0f, -50.0f, 0.0f );

	// The main game loop, repeat until engine is stopped
	while( myEngine->IsRunning( ) ) {
		// Draw the scene
		myEngine->DrawScene( );

		float frameTime = myEngine->Timer( );
		while( frameTime < MONITOR_REFRESH_RATE ) frameTime += myEngine->Timer( );

		game_update( frameTime );
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete( );
}

void game_update( float _delta ) {
	// perform look at
	main_camera->LookAt( box_model->GetLocalX( ), box_model->GetLocalY( ), box_model->GetLocalZ( ) );

	// update our matrix with current matrix of cube
	box_model->GetMatrix( elements_copy );
	example.set( elements_copy );

	if( myEngine->KeyHeld( Key_W ) ) {
		example.move_local_z( translation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_S ) ) {
		example.move_local_z( -translation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_D ) ) {
		example.move_local_x( translation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_A ) ) {
		example.move_local_x( -translation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_T ) ) {
		math::Vector3 up = Vector3::Cross( Vector3::Right, Vector3::Forward );
		example.move_local( up );
	}

	if( myEngine->KeyHeld( Key_E ) ) {
		example.rotate_y( -rotatation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_Q ) ) {
		example.rotate_y( rotatation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_Up ) ) {
		example.rotate_x( rotatation_rate *_delta, true );
	}

	if( myEngine->KeyHeld( Key_Down ) ) {
		example.rotate_x( -rotatation_rate * _delta, true );
	}

	if( myEngine->KeyHeld( Key_Right ) ) {
		example.rotate_z( rotatation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_Left ) ) {
		example.rotate_z( -rotatation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_J ) ) {
		example.scale_x( scale_rate );
	}

	if( myEngine->KeyHeld( Key_K ) ) {
		example.scale_y( scale_rate );
	}

	if( myEngine->KeyHeld( Key_L ) ) {
		example.scale_z( scale_rate );
	}

	if( myEngine->KeyHeld( Key_I ) ) {
		example.scale( scale_rate );
	}

	{ /* transposing (using mirror for more interesting results) */
		Vector3 tmp_position = Vector3( example.get_position( ) );
		Matrix4x4 tmp_matrix;
		float tmp_array[16];

		// transpose our controllable cube matrix
		// and apply the negative position of the controllable cube
		tmp_matrix = Matrix4x4::mirror( example, tmp_position );

		// retrieve the matrix and apply to mirror cube
		tmp_matrix.get( tmp_array );
		mirror_box_model->SetMatrix( tmp_array );
	}

	// apply modifications to our matrix to the cube's matrix
	example.get( elements_copy );
	box_model->SetMatrix( elements_copy );

	if( myEngine->KeyHit( Key_Escape ) ) {
		myEngine->Stop( );
	}
}
