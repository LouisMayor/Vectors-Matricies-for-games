// Main.cpp: A program using the TL-Engine

#include "4x4_Matrix.h"

#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;
using namespace math;

void game_update( float _delta );

I3DEngine* myEngine = New3DEngine( kTLX );

ICamera* main_camera;

IMesh*	 box_mesh;
IModel*	 controllable_model;
IModel*	 mirror_box_model;
IModel*	 target_box_model;
IMesh*	 floor_mesh;
IModel*	 floor_model;

float     controllable_cube_matrix_elements_copy[16];
Matrix4x4 controllable_cube_matrix;

float     mirror_cube_matrix_elements_copy[16];
Matrix4x4 mirror_cube_matrix;

float     target_cube_matrix_elements_copy[16];
Matrix4x4 target_cube_matrix;

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

	main_camera = myEngine->CreateCamera( kManual, 50.0f, 50.0f, 0.0f );
	main_camera->RotateLocalY( 270.f );

	box_mesh = myEngine->LoadMesh( "Cube.x" );
	controllable_model = box_mesh->CreateModel( 0.0f, 0.0f, 0.0f );
	mirror_box_model = box_mesh->CreateModel( 0.0f, 0.0f, 0.0f );
	target_box_model = box_mesh->CreateModel( 0.0f, 0.0f, 50.0f );

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
	main_camera->LookAt( controllable_model->GetLocalX( ), controllable_model->GetLocalY( ), controllable_model->GetLocalZ( ) );

	// update our matrix with current matrix of cube
	controllable_model->GetMatrix( controllable_cube_matrix_elements_copy );
	controllable_cube_matrix.set( controllable_cube_matrix_elements_copy );

	{	/* find angle and direction between the controllable cube and the target cube*/
		target_box_model->GetMatrix( target_cube_matrix_elements_copy );
		target_cube_matrix.set( target_cube_matrix_elements_copy );

		float direction_value;
		float angle		= Vector3::FindAngleBetween( controllable_cube_matrix.get_position( ), target_cube_matrix.get_position( ), controllable_cube_matrix.get_facing( ) );
		bool  direction = Vector3::FindDirectionBetween( controllable_cube_matrix.get_position( ), target_cube_matrix.get_position( ), controllable_cube_matrix.get_right( ) );
	}

	if( myEngine->KeyHeld( Key_W ) ) {
		controllable_cube_matrix.move_local_z( translation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_S ) ) {
		controllable_cube_matrix.move_local_z( -translation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_D ) ) {
		controllable_cube_matrix.move_local_x( translation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_A ) ) {
		controllable_cube_matrix.move_local_x( -translation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_T ) ) {
		math::Vector3 up = Vector3::Cross( Vector3::Right, Vector3::Forward );
		controllable_cube_matrix.move_local( up );
	}

	if( myEngine->KeyHeld( Key_E ) ) {
		controllable_cube_matrix.rotate_y( -rotatation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_Q ) ) {
		controllable_cube_matrix.rotate_y( rotatation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_Up ) ) {
		controllable_cube_matrix.rotate_x( rotatation_rate *_delta, true );
	}

	if( myEngine->KeyHeld( Key_Down ) ) {
		controllable_cube_matrix.rotate_x( -rotatation_rate * _delta, true );
	}

	if( myEngine->KeyHeld( Key_Right ) ) {
		controllable_cube_matrix.rotate_z( rotatation_rate *_delta );
	}

	if( myEngine->KeyHeld( Key_Left ) ) {
		controllable_cube_matrix.rotate_z( -rotatation_rate * _delta );
	}

	if( myEngine->KeyHeld( Key_J ) ) {
		controllable_cube_matrix.scale_x( scale_rate );
	}

	if( myEngine->KeyHeld( Key_K ) ) {
		controllable_cube_matrix.scale_y( scale_rate );
	}

	if( myEngine->KeyHeld( Key_L ) ) {
		controllable_cube_matrix.scale_z( scale_rate );
	}

	if( myEngine->KeyHeld( Key_I ) ) {
		controllable_cube_matrix.scale( scale_rate );
	}

	{ /* transposing (using mirror for more interesting results) */
		Vector3 tmp_position = Vector3( controllable_cube_matrix.get_position( ) );

		// transpose our controllable cube matrix
		// and apply the negative position of the controllable cube
		mirror_cube_matrix = Matrix4x4::mirror( controllable_cube_matrix, tmp_position );

		// retrieve the matrix and apply to mirror cube
		mirror_cube_matrix.get( mirror_cube_matrix_elements_copy );
		mirror_box_model->SetMatrix( mirror_cube_matrix_elements_copy );
	}

	// apply modifications to our matrix to the cube's matrix
	controllable_cube_matrix.get( controllable_cube_matrix_elements_copy );
	controllable_model->SetMatrix( controllable_cube_matrix_elements_copy );

	if( myEngine->KeyHit( Key_Escape ) ) {
		myEngine->Stop( );
	}
}