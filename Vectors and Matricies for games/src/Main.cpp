// Main.cpp: A program using the TL-Engine

#include "4x4_Matrix.h"

#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;
using namespace math;

void text_update( );
void game_update( float _delta );
void ViewportPosition( float* _x, float* _y );

I3DEngine* myEngine = New3DEngine( kTLX );

/* font pointer */
IFont*  game_text;
/* text variables */
std::string angle_str;
std::string direction_str;

/* camera pointer */
ICamera* main_camera;

/* mesh pointers */
IMesh*	 box_mesh;
IMesh*	 floor_mesh;

/* model pointers */
IModel*	 controllable_model;
IModel*	 mirror_box_model;
IModel*	 target_box_model;
IModel*	 floor_model;

/* models' matricies, and intermediate arrays to communicate through the api */
float     controllable_cube_matrix_elements_copy[16];
Matrix4x4 controllable_cube_matrix;

float     mirror_cube_matrix_elements_copy[16];
Matrix4x4 mirror_cube_matrix;

float     target_cube_matrix_elements_copy[16];
Matrix4x4 target_cube_matrix;

// Fixed update rate
const float MONITOR_REFRESH_RATE = 1.f / 60.f;
float		timerCurrent = 0.f;
const float timerTotal = 1.f;

/* translation/rotation/scaling speeds */
const float rotatation_rate = 1.5f;
const float translation_rate = 10.f;
const float scale_rate = 1.1f;

void main( ) {
	// Create a 3D engine (using TLX engine here) and open a window for it	
	myEngine->StartWindowed( );

	/* local media folder */
	myEngine->AddMediaFolder( ".\\Media" );

	main_camera = myEngine->CreateCamera( kManual, 50.0f, 50.0f, 0.0f );
	main_camera->RotateLocalY( 270.f );

	/* assign mesh and instantiate instances */
	box_mesh			= myEngine->LoadMesh( "Cube.x" );
	controllable_model	= box_mesh->CreateModel( 0.0f, 0.0f, 0.0f );
	mirror_box_model	= box_mesh->CreateModel( 0.0f, 0.0f, 0.0f );
	target_box_model	= box_mesh->CreateModel( 0.0f, 0.0f, 50.0f );

	floor_mesh	= myEngine->LoadMesh( "Floor.x" );
	floor_model = floor_mesh->CreateModel( 0.0f, -50.0f, 0.0f );

	/* load text font */
	game_text = myEngine->LoadFont( "Font1.bmp" );

	// The main game loop, repeat until engine is stopped
	while( myEngine->IsRunning( ) ) {
		// Draw the scene
		myEngine->DrawScene( );

		float frameTime = myEngine->Timer( );
		while( frameTime < MONITOR_REFRESH_RATE ) frameTime += myEngine->Timer( );

		game_update( frameTime );
		text_update( );
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete( );
}

void text_update( ) {
	/* angle text */
	float text_x_pos = 10.0f;
	float text_y_pos = 20.0f;
	ViewportPosition( &text_x_pos, &text_y_pos );
	/* double drawing, makes text stand out */
	game_text->Draw( angle_str, text_x_pos - 1.f, text_y_pos + 1.0f, kBlack, kRight );
	game_text->Draw( angle_str, text_x_pos, text_y_pos, kWhite, kRight );

	/* direction text */
	text_x_pos = 10.0f;
	text_y_pos = 25.0f;
	ViewportPosition( &text_x_pos, &text_y_pos );
	game_text->Draw( direction_str, text_x_pos - 1.f, text_y_pos + 1.0f, kBlack, kRight );
	game_text->Draw( direction_str, text_x_pos, text_y_pos, kWhite, kRight );
}

void game_update( float _delta ) {
	/* perform look at */
	main_camera->LookAt( controllable_model->GetLocalX( ), controllable_model->GetLocalY( ), controllable_model->GetLocalZ( ) );

	/* update our matrix with current matrix of cube */
	controllable_model->GetMatrix( controllable_cube_matrix_elements_copy );
	controllable_cube_matrix.set( controllable_cube_matrix_elements_copy );

	{	/* find angle and direction between the controllable cube and the target cube */
		target_box_model->GetMatrix( target_cube_matrix_elements_copy );
		target_cube_matrix.set( target_cube_matrix_elements_copy );

		float angle		= Vector3::FindAngleBetween( controllable_cube_matrix.get_position( ), target_cube_matrix.get_position( ), controllable_cube_matrix.get_facing( ) );
		bool  direction = Vector3::FindDirectionBetween( controllable_cube_matrix.get_position( ), target_cube_matrix.get_position( ), controllable_cube_matrix.get_right( ) );

		/* update text variables */
		angle_str = to_string( angle );
		direction ? direction_str = "right" : direction_str = "left";
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

		/*	transpose our controllable cube matrix
			and apply the negative position of the controllable cube
		*/
		mirror_cube_matrix = Matrix4x4::mirror( controllable_cube_matrix, tmp_position );

		/* retrieve the matrix and apply to mirror cube */
		mirror_cube_matrix.get( mirror_cube_matrix_elements_copy );
		mirror_box_model->SetMatrix( mirror_cube_matrix_elements_copy );
	}

	/* apply modifications to our matrix to the cube's matrix */
	controllable_cube_matrix.get( controllable_cube_matrix_elements_copy );
	controllable_model->SetMatrix( controllable_cube_matrix_elements_copy );

	if( myEngine->KeyHit( Key_Escape ) ) {
		myEngine->Stop( );
	}
}

/*	Resolution independent 2d positioning (not NDC coords, just a quick hack)
	_x == percent of width
	_y == percent of height
*/
void ViewportPosition( float* _x, float* _y ) {
	const float viewport_width  = myEngine->GetWidth( );
	const float viewport_height = myEngine->GetHeight( );
	*_x = (viewport_width  * (*_x / 100.0f));
	*_y = (viewport_height * (*_y / 100.0f));
}