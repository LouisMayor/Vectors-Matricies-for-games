#pragma once

#include <math.h>
#include "Vector3.h"

namespace math {
	/*
		Position stored in
		-------------------
		1	0	0	pX
		0	1	0	pY
		0	0	1	pZ
		0	0	0	1

		X Rotation matrix
		------------------
		1	0		0
		0	cos0   -sin0
		0	sin0	cos0

		Y Rotation matrix
		------------------
		cos0	0	sin0
		0		1	0
	   -sin0	0	cos0

		Z Rotation matrix
		------------------
		cos0	-sin0	0
		sin0	cos0	0
		0		0		1
	*/

	class Matrix4x4 {
	public:
		Matrix4x4( ) = default;
		Matrix4x4( const float* _elements_ptr ) {
			e00 = _elements_ptr[0];
			e10 = _elements_ptr[1];
			e20 = _elements_ptr[2];
			e30 = _elements_ptr[3];
			e01 = _elements_ptr[4];
			e11 = _elements_ptr[5];
			e21 = _elements_ptr[6];
			e31 = _elements_ptr[7];
			e02 = _elements_ptr[8];
			e12 = _elements_ptr[9];
			e22 = _elements_ptr[10];
			e32 = _elements_ptr[11];
			e03 = _elements_ptr[12];
			e13 = _elements_ptr[13];
			e23 = _elements_ptr[14];
			e33 = _elements_ptr[15];
		}

		Matrix4x4( float _e00, float _e01, float _e02, float _e03,
				   float _e10, float _e11, float _e12, float _e13,
				   float _e20, float _e21, float _e22, float _e23,
				   float _e30, float _e31, float _e32, float _e33 ) {
			e00 = _e00;
			e10 = _e10;
			e20 = _e20;
			e30 = _e30;
			e01 = _e01;
			e11 = _e11;
			e21 = _e21;
			e31 = _e31;
			e02 = _e02;
			e12 = _e12;
			e22 = _e22;
			e32 = _e32;
			e03 = _e03;
			e13 = _e13;
			e23 = _e23;
			e33 = _e33;
		}

		void get( float* _elements_ptr ) {
			_elements_ptr[0] = e00;
			_elements_ptr[1] = e10;
			_elements_ptr[2] = e20;
			_elements_ptr[3] = e30;
			_elements_ptr[4] = e01;
			_elements_ptr[5] = e11;
			_elements_ptr[6] = e21;
			_elements_ptr[7] = e31;
			_elements_ptr[8] = e02;
			_elements_ptr[9] = e12;
			_elements_ptr[10] = e22;
			_elements_ptr[11] = e32;
			_elements_ptr[12] = e03;
			_elements_ptr[13] = e13;
			_elements_ptr[14] = e23;
			_elements_ptr[15] = e33;
		}

		void set( const float* _elements_ptr ) {
			e00 = _elements_ptr[0];
			e10 = _elements_ptr[1];
			e20 = _elements_ptr[2];
			e30 = _elements_ptr[3];
			e01 = _elements_ptr[4];
			e11 = _elements_ptr[5];
			e21 = _elements_ptr[6];
			e31 = _elements_ptr[7];
			e02 = _elements_ptr[8];
			e12 = _elements_ptr[9];
			e22 = _elements_ptr[10];
			e32 = _elements_ptr[11];
			e03 = _elements_ptr[12];
			e13 = _elements_ptr[13];
			e23 = _elements_ptr[14];
			e33 = _elements_ptr[15];
		}

		Matrix4x4& operator= ( const Matrix4x4& _matrix ) {
			e00 = _matrix.e00;
			e01 = _matrix.e01;
			e02 = _matrix.e02;
			e03 = _matrix.e03;
			e10 = _matrix.e10;
			e11 = _matrix.e11;
			e12 = _matrix.e12;
			e13 = _matrix.e13;
			e20 = _matrix.e20;
			e21 = _matrix.e21;
			e22 = _matrix.e22;
			e23 = _matrix.e23;
			e30 = _matrix.e30;
			e31 = _matrix.e31;
			e32 = _matrix.e32;
			e33 = _matrix.e33;
			return (*this);
		}

		Matrix4x4& operator+( const Matrix4x4& _matrix ) {
			e00 += _matrix.e00;
			e01 += _matrix.e01;
			e02 += _matrix.e02;
			e03 += _matrix.e03;
			e10 += _matrix.e10;
			e11 += _matrix.e11;
			e12 += _matrix.e12;
			e13 += _matrix.e13;
			e20 += _matrix.e20;
			e21 += _matrix.e21;
			e22 += _matrix.e22;
			e23 += _matrix.e23;
			e30 += _matrix.e30;
			e31 += _matrix.e31;
			e32 += _matrix.e32;
			e33 += _matrix.e33;
			return (*this);
		}

		Matrix4x4& operator+( const float& _f ) {
			e00 += _f;
			e01 += _f;
			e02 += _f;
			e03 += _f;
			e10 += _f;
			e11 += _f;
			e12 += _f;
			e13 += _f;
			e20 += _f;
			e21 += _f;
			e22 += _f;
			e23 += _f;
			e30 += _f;
			e31 += _f;
			e32 += _f;
			e33 += _f;
			return (*this);
		}

		Matrix4x4& operator-( const Matrix4x4& _matrix ) {
			e00 -= _matrix.e00;
			e01 -= _matrix.e01;
			e02 -= _matrix.e02;
			e03 -= _matrix.e03;
			e10 -= _matrix.e10;
			e11 -= _matrix.e11;
			e12 -= _matrix.e12;
			e13 -= _matrix.e13;
			e20 -= _matrix.e20;
			e21 -= _matrix.e21;
			e22 -= _matrix.e22;
			e23 -= _matrix.e23;
			e30 -= _matrix.e30;
			e31 -= _matrix.e31;
			e32 -= _matrix.e32;
			e33 -= _matrix.e33;
			return (*this);
		}

		Matrix4x4& operator-( const float& _f ) {
			e00 -= _f;
			e01 -= _f;
			e02 -= _f;
			e03 -= _f;
			e10 -= _f;
			e11 -= _f;
			e12 -= _f;
			e13 -= _f;
			e20 -= _f;
			e21 -= _f;
			e22 -= _f;
			e23 -= _f;
			e30 -= _f;
			e31 -= _f;
			e32 -= _f;
			e33 -= _f;
			return (*this);
		}

		/*  Matrix multiplication
			----------------------
			Row - Column, i.e. given A and B matricies
			A.00 * B.00 + A.01 * B.10 + ...
			A.10 * B.00 + A.11 * B.20 + ...
		*/
		Matrix4x4& operator*( const Matrix4x4& _matrix ) {
			// as per usual keep copy of original value
			float _x, _y, _z;
			// pre-compute first three elements
			_x  = e00 * _matrix.e00 + e01 * _matrix.e10 + e02 * _matrix.e20 + e03 * _matrix.e30;
			_y  = e00 * _matrix.e01 + e01 * _matrix.e11 + e02 * _matrix.e21 + e03 * _matrix.e31;
			_z  = e00 * _matrix.e02 + e01 * _matrix.e12 + e02 * _matrix.e22 + e03 * _matrix.e32;
			e03 = e00 * _matrix.e03 + e01 * _matrix.e13 + e02 * _matrix.e23 + e03 * _matrix.e33;
			e00 = _x;
			e01 = _y;
			e02 = _z;
			//
			_x  = e10 * _matrix.e00 + e11 * _matrix.e10 + e12 * _matrix.e20 + e13 * _matrix.e30;
			_y  = e10 * _matrix.e01 + e11 * _matrix.e11 + e12 * _matrix.e21 + e13 * _matrix.e31;
			_z  = e10 * _matrix.e02 + e11 * _matrix.e12 + e12 * _matrix.e22 + e13 * _matrix.e32;
			e13 = e10 * _matrix.e03 + e11 * _matrix.e13 + e12 * _matrix.e23 + e13 * _matrix.e33;
			e10 = _x;
			e11 = _y;
			e12 = _z;
			//
			_x  = e20 * _matrix.e00 + e21 * _matrix.e10 + e22 * _matrix.e20 + e23 * _matrix.e30;
			_y  = e20 * _matrix.e01 + e21 * _matrix.e11 + e22 * _matrix.e21 + e23 * _matrix.e31;
			_z  = e20 * _matrix.e02 + e21 * _matrix.e12 + e22 * _matrix.e22 + e23 * _matrix.e32;
			e23 = e20 * _matrix.e03 + e21 * _matrix.e13 + e22 * _matrix.e23 + e23 * _matrix.e33;
			e20 = _x;
			e21 = _y;
			e22 = _z;
			//
			_x  = e30 * _matrix.e00 + e31 * _matrix.e10 + e32 * _matrix.e20 + e33 * _matrix.e30;
			_y  = e30 * _matrix.e01 + e31 * _matrix.e11 + e32 * _matrix.e21 + e33 * _matrix.e31;
			_z  = e30 * _matrix.e02 + e31 * _matrix.e12 + e32 * _matrix.e22 + e33 * _matrix.e32;
			e33 = e30 * _matrix.e03 + e31 * _matrix.e13 + e32 * _matrix.e23 + e33 * _matrix.e33;
			e30 = _x;
			e31 = _y;
			e32 = _z;
			return (*this);
		}

		/*	useful for inverting (orthogonal matricies)	Quite simply,
			take row element and swap for corrisponding column element.
			i.e. e01 -> e10, e02 -> e20, etc... e00 and e33 dont have a corrisponding element

			basically, read diagonally, right -> left
		*/
		void transpose( ) {
			// copy original value
			float tmp;
			//
			tmp = e01;
			e01 = e10;
			e10 = tmp;
			//
			tmp = e02;
			e02 = e20;
			e20 = tmp;
			//
			tmp = e12;
			e12 = e21;
			e21 = tmp;
			//
			tmp = e03;
			e03 = e30;
			e30 = tmp;
			//
			tmp = e13;
			e13 = e31;
			e31 = tmp;
			//
			tmp = e23;
			e23 = e32;
			e32 = tmp;
		}

		/*	diagonal transpose, diagonal elements must be non-zero 
			computes the reciprocal (1/x) of each diagonal element
		*/
		void diagonal_transpose_nonzero( ) {
			// copy original value
			float tmp;
			//
			tmp = 1 / e00;
			e00 = tmp;
			//
			tmp = 1 / e11;
			e11 = tmp;
			//
			tmp = 1 / e22;
			e22 = tmp;
			//
			tmp = 1 / e33;
			e33 = tmp;
		}

		// TODO: find non-zero non-diagonal elements
		/*	diagonal transpose, diagonal elements must be one and
			either a row or column must be non-zero.
			negates the non-zero non-diagonal elements
		*/
		void diagonal_transpose_identity( ) {
		}

		/*	useful for inverting (orthogonal matricies)	Quite simply,
			take row element and swap for corrisponding column element.
			i.e. e01 -> e10, e02 -> e20, etc... e00 and e33 dont have a corrisponding element

			basically, read diagonally, right -> left
		*/
		static Matrix4x4 transpose( const Matrix4x4& _m ) {
			return Matrix4x4( _m.e00, _m.e10, _m.e20, _m.e30,
							  _m.e01, _m.e11, _m.e21, _m.e31,
							  _m.e02, _m.e12, _m.e22, _m.e32,
							  _m.e03, _m.e13, _m.e23, _m.e33 );
		}

		/*	transposes matrix and applies -_v.z and _v.xy into the position elements
			replicating a mirror
			i.e. super mario 64 mirror room (for mario)
			https://youtu.be/ITlH2cMOdd8?t=15s
		*/
		static Matrix4x4 mirror( const Matrix4x4& _m, const Vector3& _v ) {
			return Matrix4x4( _m.e00, _m.e10, _m.e20,   _v.x,
							  _m.e01, _m.e11, _m.e21,   _v.y,
							  _m.e02, _m.e12, _m.e22,  -_v.z,
							  _m.e03, _m.e13, _m.e23, _m.e33 );
		}

		/*	tranforming points and vectors has differences, even though they look ostensibly the same.
			This is seen within homogeneous coordinates. vectors 4th element is 0, points 4th element is 1.
			The numbers are used to differentiate between the two.
			For more info: (GDC) Math for Game Programmers: Understanding Homogeneous Coordinates
			https://www.youtube.com/watch?v=o1n02xKP138
		*/

		//Vector4 tranform( const Vector4& _vector ) {
		//	return Vector4( _vector.x * e00 + _vector.y * e10 + _vector.z * e20 + _vector.w * e30,
		//					_vector.x * e01 + _vector.y * e11 + _vector.z * e21 + _vector.w * e31,
		//					_vector.x * e02 + _vector.y * e12 + _vector.z * e22 + _vector.w * e32,
		//					_vector.x * e03 + _vector.y * e13 + _vector.z * e23 + _vector.w * e33 );
		//}

		/* for points, 4th element is defined as 1 */
		Vector3 tranform_point( const Vector3& _v ) {
			return Vector3( _v.x * e00 + _v.y * e10 + _v.z * e20 + e30,
							_v.x * e01 + _v.y * e11 + _v.z * e21 + e31,
							_v.x * e02 + _v.y * e12 + _v.z * e22 + e32 );
		}

		/* for vectors, 4th element is defined as 0 */
		Vector3 tranform_vector( const Vector3& _v ) {
			return Vector3( _v.x * e00 + _v.y * e10 + _v.z * e20,
							_v.x * e01 + _v.y * e11 + _v.z * e21,
							_v.x * e02 + _v.y * e12 + _v.z * e22 );
		}

		/* Affine Transformations */

		void scale_x( const float _rate ) {
			e00 *= _rate;
			e10 *= _rate;
			e20 *= _rate;
		}

		void scale_y( const float _rate ) {
			e01 *= _rate;
			e11 *= _rate;
			e21 *= _rate;
		}

		void scale_z( const float _rate ) {
			e02 *= _rate;
			e12 *= _rate;
			e22 *= _rate;
		}

		void scale( const Vector3& _rates ) {
			e00 *= _rates.x;
			e10 *= _rates.x;
			e20 *= _rates.x;
			e01 *= _rates.y;
			e11 *= _rates.y;
			e21 *= _rates.y;
			e02 *= _rates.z;
			e12 *= _rates.z;
			e22 *= _rates.z;
		}

		void scale( const float _rate ) {
			e00 *= _rate;
			e10 *= _rate;
			e20 *= _rate;
			e01 *= _rate;
			e11 *= _rate;
			e21 *= _rate;
			e02 *= _rate;
			e12 *= _rate;
			e22 *= _rate;
		}

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

		void move_local( const Vector3& _rates ) {
			e03 += e00 * _rates.x + e10 * _rates.y + e20 * _rates.z;
			e13 += e01 * _rates.x + e11 * _rates.y + e21 * _rates.z;
			e23 += e02 * _rates.x + e12 * _rates.y + e22 * _rates.z;
		}

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
		*/

		/*	locally translating z
			---------------------
			1	0  |0| |pX|
			0	1  |0| |pY|
			0	0  |1| |pZ|
			0	0	0	1

			|eXX| == element slots used
		*/

		void move_local_x( const float _rate ) {
			e03 += e00 * _rate;
			e13 += e10 * _rate;
			e23 += e20 * _rate;
		}

		void move_local_y( const float _rate ) {
			e03 += e01 * _rate;
			e13 += e11 * _rate;
			e23 += e21 * _rate;
		}

		void move_local_z( const float _rate ) {
			e03 += e02 * _rate;
			e13 += e12 * _rate;
			e23 += e22 * _rate;
		}

		// rotate_pitch == rotate_x
		inline void rotate_pitch( const float _rate ) {
			rotate_x( _rate );
		}

		// rotate_yaw == rotate_y
		inline void rotate_yaw( const float _rate ) {
			rotate_y( _rate );
		}

		// rotate_roll == rotate_z
		inline void rotate_roll( const float _rate ) {
			rotate_z( _rate );
		}

		/*	Y Rotation matrix
			------------------
			cos0	0	sin0
			0		1	0
			-sin0	0	cos0
			------------------
		*/
		/*	Mathematical definition of a rotation matrix operation
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

		void rotate_x( const float _rate, bool flight_mode = false ) {
			float rotation = flight_mode ? -_rate : _rate;
			// compute sin/cos of input
			float sine   = sinf( rotation );
			float cosine = cosf( rotation );
			// keep copy of orignal rotation tranform
			// of respective elements
			float tmp;
			//
			tmp = e01 * sine   + e02 * cosine;
			e01 = e01 * cosine - e02 * sine;
			e02 = tmp;
			//
			tmp = e11 * sine   + e12 * cosine;
			e11 = e11 * cosine - e12 * sine;
			e12 = tmp;
			//
			tmp = e21 * sine   + e22 * cosine;
			e21 = e21 * cosine - e22 * sine;
			e22 = tmp;
		}

		void rotate_y( const float _rate ) {
			// compute sin/cos of input
			float sine   = sinf( _rate );
			float cosine = cosf( _rate );
			// keep copy of orignal rotation tranform
			// of respective elements
			float tmp;
			//
			tmp = e02 * cosine - e00 * sine;
			e00 = e00 * cosine + e02 * sine;
			e02 = tmp;
			//
			tmp = e12 * cosine - e10 * sine;
			e10 = e10 * cosine + e12 * sine;
			e12 = tmp;
			//
			tmp = e22 * cosine - e20 * sine;
			e20 = e20 * cosine + e22 * sine;
			e22 = tmp;
		}

		void rotate_z( const float _rate ) {
			// compute sin/cos of input
			float sine   = sinf( _rate );
			float cosine = cosf( _rate );
			// keep copy of orignal rotation tranform
			// of respective elements
			float tmp;
			//
			tmp = e00 * sine   + e01 * cosine;
			e00 = e00 * cosine - e01 * sine;
			e01 = tmp;
			//
			tmp = e10 * sine   + e11 * cosine;
			e10 = e10 * cosine - e11 * sine;
			e11 = tmp;
			//
			tmp = e20 * sine   + e21 * cosine;
			e20 = e20 * cosine - e21 * sine;
			e21 = tmp;
		}

		// TODO: look_at() when vectors fully implemented
		void look_at( const Vector3& _point ) {

		}

		void set_position( const float &&_x, const float &&_y, const float &&_z ) {
			e03 = _x;
			e13 = _y;
			e23 = _z;
		}

		void set_position( const Vector3&& _vector ) {
			e03 = _vector.x;
			e13 = _vector.y;
			e23 = _vector.z;
		}

		Vector3 get_position( ) const {
			return Vector3( e03, e13, e23 );
		}

		// Matrix elements
		float e00, e01, e02, e03;
		float e10, e11, e12, e13;
		float e20, e21, e22, e23;
		float e30, e31, e32, e33;
	};

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