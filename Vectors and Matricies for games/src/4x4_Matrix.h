#pragma once

#include <math.h>
#include "Vector3.h"

namespace math {

	class Matrix4x4 {
	public:
		Matrix4x4( ) = default;

		explicit	Matrix4x4( const float* _elements_ptr, bool is_row_major );

		explicit	Matrix4x4( float _e00, float _e01, float _e02, float _e03,
							   float _e10, float _e11, float _e12, float _e13,
							   float _e20, float _e21, float _e22, float _e23,
							   float _e30, float _e31, float _e32, float _e33,
							   bool row_major );

		Matrix4x4( const Matrix4x4& _matrix, bool is_row_major );

		void get( float* _elements_ptr, bool is_row_major );

		void set( const float* _elements_ptr, bool is_row_major );

		Matrix4x4& operator= ( const Matrix4x4& _matrix );

		Matrix4x4& operator+ ( const Matrix4x4& _matrix );

		Matrix4x4& operator+ ( const float& _f );

		Matrix4x4& operator- ( const Matrix4x4& _matrix );

		Matrix4x4& operator- ( const float& _f );

		/*  Matrix multiplication
			----------------------
			Row - Column, i.e. given A and B matricies
			A.00 * B.00 + A.01 * B.10 + ...
			A.10 * B.00 + A.11 * B.20 + ...
		*/
		Matrix4x4& operator* ( const Matrix4x4& _matrix );

		/*	useful for inverting (orthogonal matricies)	Quite simply,
			take row element and swap for corrisponding column element.
			i.e. e01 -> e10, e02 -> e20, etc... e00 and e33 dont have a corrisponding element

			basically, read diagonally, right -> left
		*/
		void transpose( );

		/*	diagonal transpose, diagonal elements must be non-zero 
			computes the reciprocal (1/x) of each diagonal element
		*/
		void diagonal_transpose_nonzero( );

		// TODO: find non-zero non-diagonal elements
		/*	diagonal transpose, diagonal elements must be one and
			either a row or column must be non-zero.
			negates the non-zero non-diagonal elements
		*/
		void diagonal_transpose_identity( );

		/*	useful for inverting (orthogonal matricies) also inverts rotations
			Quite simply, take row element and swap for corrisponding column element.
			i.e. e01 -> e10, e02 -> e20, etc... e00 and e33 dont have a corrisponding element

			basically, read diagonally, right -> left
		*/
		static Matrix4x4 transpose( const Matrix4x4& _m );

		/*	transposes matrix and applies -_v.z and _v.xy into the position elements
			replicating a mirror
			i.e. super mario 64 mirror room (for mario)
			https://youtu.be/ITlH2cMOdd8?t=15s
		*/
		static Matrix4x4 reflection( const Matrix4x4& _m, const Vector3& _v );
		Matrix4x4 InverseAffineMatrix( const Matrix4x4& _matrix );

		/*	tranforming points and vectors has differences, even though they look ostensibly the same.
			This is seen within homogeneous coordinates. vectors 4th element is 0, points 4th element is 1.
			The numbers are used to differentiate between the two.
			For more info: (GDC) Math for Game Programmers: Understanding Homogeneous Coordinates
			https://www.youtube.com/watch?v=o1n02xKP138
		*/

		// TODO: once vec4 implemented
		//Vector4 tranform( const Vector4& _vector );

		/* for points, 4th element is defined as 1 */
		Vector3 tranform_point( const Vector3& _v );

		/* for vectors, 4th element is defined as 0 */ 
		Vector3 tranform_vector( const Vector3& _v );

		/* Affine Transformations */

		void scale_x( const float _rate );

		void scale_y( const float _rate );

		void scale_z( const float _rate );

		void scale( const Vector3& _rates );

		void scale( const float _rate );

		/*	Mathematical definition of a tranlation matrix operation
			---------------------------------------------------------
			T(O) = T + O = tx * i + ty * i + tz * i + O
			---------------------------------------------------------
			T = translation matrix
			O = Origin
			i = vector of translation values
			_________________________________________________________
			Practical usage:
			tx * i + ty * i + tx * i
			---------------------------------------------------------
			**O removed since origin is normally 0
		*/
		void move_local( const Vector3& _rates );

		/*  Mathematical definition of a tranlation matrix operation
			*( for a given axis )*
			---------------------------------------------------------
			T(O) = T + O = tx * i + O
			---------------------------------------------------------
			T = translation matrix
			O = Origin
			i = vector of translation values
			_________________________________________________________
			Practical usage:
			tx * i		

			locally translating z
			---------------------
			1	0  |0| |pX|
			0	1  |0| |pY|
			0	0  |1| |pZ|
			0	0	0	1

			|eXX| == element slots used
		*/
		void move_local_x( const float _rate );

		void move_local_y( const float _rate );

		void move_local_z( const float _rate );

		// rotate_pitch == rotate_x
		inline void rotate_pitch( const float _rate );

		// rotate_yaw == rotate_y
		inline void rotate_yaw( const float _rate );

		// rotate_roll == rotate_z
		inline void rotate_roll( const float _rate );

		/*	Y Rotation matrix
			------------------
			cos0	0	sin0
			0		1	0
			-sin0	0	cos0
			------------------
		
			Mathematical definition of a rotation matrix operation
			for the Y axis
			--------------------------------------------------------------
			x' = z sin0 + x cos0
			y' = y
			z' = z cos0 - x sin0
			______________________________________________________________
			Practical usage: (can flip the sin/cos operands with element,
			eXX corrispond to Y axis rotation matrix elements)
			--------------------------------------------------------------
			e00 = e02 sin0 + e00 cos0
			e02 = e02 cos0 - e00 sin0
			--------------------------------------------------------------
		*/
		void rotate_x( const float _rate, bool flight_mode = false );

		void rotate_y( const float _rate );

		void rotate_z( const float _rate );

		/*	Concatenated matrix for all 3 angles, ordering is important
			The order is dependent on how your axis define roll, pitch and yaw
			for example, this function will only do ZXY, because our axis are:
			Z == roll
			X == pitch
			Y == Yaw
			Some games engines use XYZ i.e. Unreal Engine

			help: https://www.geometrictools.com/Documentation/EulerAngles.pdf (2.5: Rz Rx Ry)
		*/
		void RotationMatrix( const Vector3 _rotations );

		// TODO: look_at() when vectors fully implemented
		void look_at( const Vector3& _point );

		void set_position( const float &&_x, const float &&_y, const float &&_z );

		void set_position( const Vector3&& _vector );

		Vector3 get_position( ) const;

		Vector3 get_facing( ) const;

		Vector3 get_up( ) const;

		Vector3 get_right( ) const;

		// Matrix elements
		float e00, e01, e02, e03;
		float e10, e11, e12, e13;
		float e20, e21, e22, e23;
		float e30, e31, e32, e33;
	};

	// TODO: once vec4 implemented
	/*	pre/post multiplication for different matricies order (row major/column major)
		https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/row-major-vs-column-major-vector
	*/

	/*	matrix *then* vector (non-commutative)
		row element * vector element + ...
	*/
	//Vector4 operator* ( const Matrix4x4& _matrix, const Vector4& _vector ) {
	//	return Vector4( _matrix.e00 * _vector.x + _matrix.e01 * _vector.y + _matrix.e02 * _vector.z + _matrix.e03 * _vector.w,
	//					_matrix.e10 * _vector.x + _matrix.e11 * _vector.y + _matrix.e12 * _vector.z + _matrix.e13 * _vector.w,
	//					_matrix.e20 * _vector.x + _matrix.e21 * _vector.y + _matrix.e22 * _vector.z + _matrix.e23 * _vector.w,
	//					_matrix.e30 * _vector.x + _matrix.e31 * _vector.y + _matrix.e32 * _vector.z + _matrix.e33 * _vector.w );
	//}

	/*	vector *then* matrix (non-commutative)
		vector element * column element + ...
	*/
	//Vector4 operator* ( const Vector4& _vector, const Matrix4x4& _matrix ) {
	//	return Vector4( _vector.x * _matrix.e00 + _vector.y * _matrix.e10 + _vector.z * _matrix.e20 + _vector.w * _matrix.e30,
	//					_vector.x * _matrix.e01 + _vector.y * _matrix.e11 + _vector.z * _matrix.e21 + _vector.w * _matrix.e31,
	//					_vector.x * _matrix.e02 + _vector.y * _matrix.e12 + _vector.z * _matrix.e22 + _vector.w * _matrix.e32,
	//					_vector.x * _matrix.e03 + _vector.y * _matrix.e13 + _vector.z * _matrix.e23 + _vector.w * _matrix.e33 );
	//}
}