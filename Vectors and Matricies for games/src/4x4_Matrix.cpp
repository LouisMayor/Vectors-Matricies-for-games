#include "4x4_Matrix.h"

/*	Left handed, row major matrix */
namespace math {
	Matrix4x4::Matrix4x4( const float* _elements_ptr, bool is_row_major ) {		
		if( is_row_major ) {
			e00 = _elements_ptr[0];
			e01 = _elements_ptr[1];
			e02 = _elements_ptr[2];
			e03 = _elements_ptr[3];
			e10 = _elements_ptr[4];
			e11 = _elements_ptr[5];
			e12 = _elements_ptr[6];
			e13 = _elements_ptr[7];
			e20 = _elements_ptr[8];
			e21 = _elements_ptr[9];
			e22 = _elements_ptr[10];
			e23 = _elements_ptr[11];
			e30 = _elements_ptr[12];
			e31 = _elements_ptr[13];
			e32 = _elements_ptr[14];
			e33 = _elements_ptr[15];
		} else { /* input values from column major matrix, need to transpose elements */
			e00 = _elements_ptr[0];
			e01 = _elements_ptr[4];
			e02 = _elements_ptr[8];
			e03 = _elements_ptr[12];
			e10 = _elements_ptr[1];
			e11 = _elements_ptr[5];
			e12 = _elements_ptr[9];
			e13 = _elements_ptr[13];
			e20 = _elements_ptr[2];
			e21 = _elements_ptr[6];
			e22 = _elements_ptr[10];
			e23 = _elements_ptr[14];
			e30 = _elements_ptr[3];
			e31 = _elements_ptr[7];
			e32 = _elements_ptr[11];
			e33 = _elements_ptr[15];
		}
	}

	Matrix4x4::Matrix4x4
	(	
		float _e00, float _e01, float _e02, float _e03,
		float _e10, float _e11, float _e12, float _e13,
		float _e20, float _e21, float _e22, float _e23,
		float _e30, float _e31, float _e32, float _e33,
		bool is_row_major
	) {
		if( is_row_major ) {
			e00 = _e00;
			e01 = _e01;
			e02 = _e02;
			e03 = _e03;
			e10 = _e10;
			e11 = _e11;
			e12 = _e12;
			e13 = _e13;
			e20 = _e20;
			e21 = _e21;
			e22 = _e22;
			e23 = _e23;
			e30 = _e30;
			e31 = _e31;
			e32 = _e32;
			e33 = _e33;
		} else { /* input values from column major matrix, need to transpose elements */
			e00 = _e00;
			e01 = _e10;
			e02 = _e20;
			e03 = _e30;
			e10 = _e01;
			e11 = _e11;
			e12 = _e21;
			e13 = _e31;
			e20 = _e02;
			e21 = _e12;
			e22 = _e22;
			e23 = _e32;
			e30 = _e03;
			e31 = _e13;
			e32 = _e23;
			e33 = _e33;
		}
	}

	Matrix4x4::Matrix4x4( const Matrix4x4& _matrix, bool is_row_major ) {
		if( is_row_major ) {
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
		} else { /* input values from column major matrix, need to transpose elements */
			e00 = _matrix.e00;
			e01 = _matrix.e10;
			e02 = _matrix.e20;
			e03 = _matrix.e30;
			e10 = _matrix.e01;
			e11 = _matrix.e11;
			e12 = _matrix.e21;
			e13 = _matrix.e31;
			e20 = _matrix.e02;
			e21 = _matrix.e12;
			e22 = _matrix.e22;
			e23 = _matrix.e32;
			e30 = _matrix.e03;
			e31 = _matrix.e13;
			e32 = _matrix.e23;
			e33 = _matrix.e33;
		}
	}
	
	void Matrix4x4::get( float* _elements_ptr, bool is_row_major ) {
		if( is_row_major ) {
			_elements_ptr[0]  = e00;
			_elements_ptr[1]  = e01;
			_elements_ptr[2]  = e02;
			_elements_ptr[3]  = e03;
			_elements_ptr[4]  = e10;
			_elements_ptr[5]  = e11;
			_elements_ptr[6]  = e12;
			_elements_ptr[7]  = e13;
			_elements_ptr[8]  = e20;
			_elements_ptr[9]  = e21;
			_elements_ptr[10] = e22;
			_elements_ptr[11] = e23;
			_elements_ptr[12] = e30;
			_elements_ptr[13] = e31;
			_elements_ptr[14] = e32;
			_elements_ptr[15] = e33;
		} else { /* outputting to column major matrix, need to transpose elements */
			_elements_ptr[0]  = e00;
			_elements_ptr[4]  = e01;
			_elements_ptr[8]  = e02;
			_elements_ptr[12] = e03;
			_elements_ptr[1]  = e10;
			_elements_ptr[5]  = e11;
			_elements_ptr[9]  = e12;
			_elements_ptr[13] = e13;
			_elements_ptr[2]  = e20;
			_elements_ptr[6]  = e21;
			_elements_ptr[10] = e22;
			_elements_ptr[14] = e23;
			_elements_ptr[3]  = e30;
			_elements_ptr[7]  = e31;
			_elements_ptr[11] = e32;
			_elements_ptr[15] = e33;
		}
	}

	void Matrix4x4::set( const float* _elements_ptr, bool is_row_major ) {
		if( is_row_major ) {
			e00 = _elements_ptr[0];
			e01 = _elements_ptr[1];
			e02 = _elements_ptr[2];
			e03 = _elements_ptr[3];
			e10 = _elements_ptr[4];
			e11 = _elements_ptr[5];
			e12 = _elements_ptr[6];
			e13 = _elements_ptr[7];
			e20 = _elements_ptr[8];
			e21 = _elements_ptr[9];
			e22 = _elements_ptr[10];
			e23 = _elements_ptr[11];
			e30 = _elements_ptr[12];
			e31 = _elements_ptr[13];
			e32 = _elements_ptr[14];
			e33 = _elements_ptr[15];
		} else { /* input values from column major matrix, need to transpose elements */
			e00 = _elements_ptr[0];
			e01 = _elements_ptr[4];
			e02 = _elements_ptr[8];
			e03 = _elements_ptr[12];
			e10 = _elements_ptr[1];
			e11 = _elements_ptr[5];
			e12 = _elements_ptr[9];
			e13 = _elements_ptr[13];
			e20 = _elements_ptr[2];
			e21 = _elements_ptr[6];
			e22 = _elements_ptr[10];
			e23 = _elements_ptr[14];
			e30 = _elements_ptr[3];
			e31 = _elements_ptr[7];
			e32 = _elements_ptr[11];
			e33 = _elements_ptr[15];
		}
	}

	Matrix4x4& Matrix4x4::operator= ( const Matrix4x4& _matrix ) {
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

	Matrix4x4& Matrix4x4::operator+( const Matrix4x4& _matrix ) {
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

	Matrix4x4& Matrix4x4::operator+( const float& _f ) {
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

	Matrix4x4& Matrix4x4::operator-( const Matrix4x4& _matrix ) {
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

	Matrix4x4& Matrix4x4::operator-( const float& _f ) {
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

	Matrix4x4& Matrix4x4::operator*( const Matrix4x4& _matrix ) {
		// as per usual keep copy of original value
		float _x, _y, _z;
		// pre-compute first three elements
		_x	= e00 * _matrix.e00 + e01 * _matrix.e10 + e02 * _matrix.e20 + e03 * _matrix.e30;
		_y	= e00 * _matrix.e01 + e01 * _matrix.e11 + e02 * _matrix.e21 + e03 * _matrix.e31;
		_z	= e00 * _matrix.e02 + e01 * _matrix.e12 + e02 * _matrix.e22 + e03 * _matrix.e32;
		e03 = e00 * _matrix.e03 + e01 * _matrix.e13 + e02 * _matrix.e23 + e03 * _matrix.e33;
		e00 = _x;
		e01 = _y;
		e02 = _z;
		//
		_x	= e10 * _matrix.e00 + e11 * _matrix.e10 + e12 * _matrix.e20 + e13 * _matrix.e30;
		_y	= e10 * _matrix.e01 + e11 * _matrix.e11 + e12 * _matrix.e21 + e13 * _matrix.e31;
		_z	= e10 * _matrix.e02 + e11 * _matrix.e12 + e12 * _matrix.e22 + e13 * _matrix.e32;
		e13 = e10 * _matrix.e03 + e11 * _matrix.e13 + e12 * _matrix.e23 + e13 * _matrix.e33;
		e10 = _x;
		e11 = _y;
		e12 = _z;
		//
		_x	= e20 * _matrix.e00 + e21 * _matrix.e10 + e22 * _matrix.e20 + e23 * _matrix.e30;
		_y	= e20 * _matrix.e01 + e21 * _matrix.e11 + e22 * _matrix.e21 + e23 * _matrix.e31;
		_z	= e20 * _matrix.e02 + e21 * _matrix.e12 + e22 * _matrix.e22 + e23 * _matrix.e32;
		e23 = e20 * _matrix.e03 + e21 * _matrix.e13 + e22 * _matrix.e23 + e23 * _matrix.e33;
		e20 = _x;
		e21 = _y;
		e22 = _z;
		//
		_x	= e30 * _matrix.e00 + e31 * _matrix.e10 + e32 * _matrix.e20 + e33 * _matrix.e30;
		_y	= e30 * _matrix.e01 + e31 * _matrix.e11 + e32 * _matrix.e21 + e33 * _matrix.e31;
		_z	= e30 * _matrix.e02 + e31 * _matrix.e12 + e32 * _matrix.e22 + e33 * _matrix.e32;
		e33 = e30 * _matrix.e03 + e31 * _matrix.e13 + e32 * _matrix.e23 + e33 * _matrix.e33;
		e30 = _x;
		e31 = _y;
		e32 = _z;
		return (*this);
	}

	void Matrix4x4::transpose( ) {
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

	void Matrix4x4::diagonal_transpose_nonzero( ) {
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

	void Matrix4x4::diagonal_transpose_identity( ) {
	}

	Matrix4x4 Matrix4x4::transpose( const Matrix4x4& _m ) {
		return Matrix4x4( _m.e00, _m.e10, _m.e20, _m.e30,
						  _m.e01, _m.e11, _m.e21, _m.e31,
						  _m.e02, _m.e12, _m.e22, _m.e32,
						  _m.e03, _m.e13, _m.e23, _m.e33,
						  true );
	}

	Matrix4x4 Matrix4x4::reflection( const Matrix4x4& _m, const Vector3& _v ) {
		return Matrix4x4( _m.e00, _m.e10, _m.e20, _m.e30,
						  _m.e01, _m.e11, _m.e21, _m.e31,
						  _m.e02, _m.e12, _m.e22, _m.e32,
						  _v.x,	    _v.y,  -_v.z, _m.e33,
						  true );
	}


	Matrix4x4 Matrix4x4::InverseAffineMatrix( const Matrix4x4& _matrix ) {
		return Matrix4x4( );
	}
	
	//Vector4 Matrix4x4::tranform( const Vector4& _vector ) {
	//	return Vector4( _vector.x * e00 + _vector.y * e10 + _vector.z * e20 + _vector.w * e30,
	//					_vector.x * e01 + _vector.y * e11 + _vector.z * e21 + _vector.w * e31,
	//					_vector.x * e02 + _vector.y * e12 + _vector.z * e22 + _vector.w * e32,
	//					_vector.x * e03 + _vector.y * e13 + _vector.z * e23 + _vector.w * e33 );
	//}

	/* for points, 4th element is defined as 1 */
	Vector3 Matrix4x4::tranform_point( const Vector3& _v ) {
		return Vector3( _v.x * e00 + _v.y * e10 + _v.z * e20 + e30,
						_v.x * e01 + _v.y * e11 + _v.z * e21 + e31,
						_v.x * e02 + _v.y * e12 + _v.z * e22 + e32 );
	}

	/* for vectors, 4th element is defined as 0 */
	Vector3 Matrix4x4::tranform_vector( const Vector3& _v ) {
		return Vector3( _v.x * e00 + _v.y * e10 + _v.z * e20,
						_v.x * e01 + _v.y * e11 + _v.z * e21,
						_v.x * e02 + _v.y * e12 + _v.z * e22 );
	}

	void Matrix4x4::scale_x( const float _rate ) {
		e00 *= _rate;
		e01 *= _rate;
		e02 *= _rate;
	}

	void Matrix4x4::scale_y( const float _rate ) {
		e10 *= _rate;
		e11 *= _rate;
		e12 *= _rate;
	}

	void Matrix4x4::scale_z( const float _rate ) {
		e20 *= _rate;
		e21 *= _rate;
		e22 *= _rate;
	}

	void Matrix4x4::scale( const Vector3& _rates ) {
		e00 *= _rates.x;
		e01 *= _rates.x;
		e02 *= _rates.x;
		e10 *= _rates.y;
		e11 *= _rates.y;
		e12 *= _rates.y;
		e20 *= _rates.z;
		e21 *= _rates.z;
		e22 *= _rates.z;
	}

	void Matrix4x4::scale( const float _rate ) {
		e00 *= _rate;
		e01 *= _rate;
		e02 *= _rate;
		e10 *= _rate;
		e11 *= _rate;
		e12 *= _rate;
		e20 *= _rate;
		e21 *= _rate;
		e22 *= _rate;
	}

	void Matrix4x4::move_local( const Vector3& _rates ) {
		e30 += e00 * _rates.x + e01 * _rates.y + e02 * _rates.z;
		e31 += e10 * _rates.x + e11 * _rates.y + e12 * _rates.z;
		e32 += e20 * _rates.x + e21 * _rates.y + e22 * _rates.z;
	}

	void Matrix4x4::move_local_x( const float _rate ) {
		Vector3 x = get_right( );
		e30 += x.x * _rate;
		e31 += x.y * _rate;
		e32 += x.z * _rate;
	}

	void Matrix4x4::move_local_y( const float _rate ) {
		Vector3 y = get_up( );
		e30 += y.x * _rate;
		e31 += y.y * _rate;
		e32 += y.z * _rate;
	}

	void Matrix4x4::move_local_z( const float _rate ) {
		Vector3 z = get_facing( );
		e30 += z.x * _rate;
		e31 += z.y * _rate;
		e32 += z.z * _rate;
	}

	// rotate_pitch == rotate_x
	inline void Matrix4x4::rotate_pitch( const float _rate ) {
		rotate_x( _rate );
	}

	// rotate_yaw == rotate_y
	inline void Matrix4x4::rotate_yaw( const float _rate ) {
		rotate_y( _rate );
	}

	// rotate_roll == rotate_z
	inline void Matrix4x4::rotate_roll( const float _rate ) {
		rotate_z( _rate );
	}

	void Matrix4x4::rotate_x( const float _rate, bool flight_mode ) {
		float rotation = flight_mode ? _rate : -_rate;
		// compute sin/cos of input
		float sine = sinf( rotation );
		float cosine = cosf( rotation );
		// keep copy of orignal rotation tranform
		// of respective elements
		float tmp;
		//
		tmp = e10 * cosine + e20 * sine;
		e20 = e20 * cosine - e10 * sine;
		e10 = tmp;
		//
		tmp = e11 * cosine + e21 * sine;
		e21 = e21 * cosine - e11 * sine;
		e11 = tmp;
		//
		tmp = e12 * cosine + e22 * sine;
		e22 = e22 * cosine - e12 * sine;
		e12 = tmp;
	}

	void Matrix4x4::rotate_y( const float _rate ) {
		// compute sin/cos of input
		float sine = sinf( _rate );
		float cosine = cosf( _rate );
		// keep copy of orignal rotation tranform
		// of respective elements
		float tmp;
		//
		tmp = e20 * cosine + e00 * sine;
		e00 = e00 * cosine - e20 * sine;
		e20 = tmp;
		//
		tmp = e21 * cosine + e01 * sine;
		e01 = e01 * cosine - e21 * sine;
		e21 = tmp;
		//
		tmp = e22 * cosine + e02 * sine;
		e02 = e02 * cosine - e22 * sine;
		e22 = tmp;
	}

	void Matrix4x4::rotate_z( const float _rate ) {
		// compute sin/cos of input
		float sine = sinf( _rate );
		float cosine = cosf( _rate );
		// keep copy of orignal rotation tranform
		// of respective elements
		float tmp;
		//
		tmp = e00 * cosine + e10 * sine;
		e10 = e10 * cosine - e00 * sine;
		e00 = tmp;
		//
		tmp = e01 * cosine + e11 * sine;
		e11 = e11 * cosine - e01 * sine;
		e01 = tmp;
		//
		tmp = e02 * cosine + e12 * sine;
		e12 = e12 * cosine - e02 * sine;
		e02 = tmp;
	}

	void Matrix4x4::RotationMatrix( const Vector3 _rotations ) {
		// Compute sin/cos of the angles
		float s_x, c_x, s_y, c_y, s_z, c_z;
		s_x = sinf( _rotations.x );
		c_x = cosf( _rotations.x );
		s_y = sinf( _rotations.y );
		c_y = cosf( _rotations.y );
		s_z = sinf( _rotations.z );
		c_z = cosf( _rotations.z );
		// X
		e00 =  c_y * c_z - s_x * s_y * s_z;
		e10 = -c_x * s_z;
		e20 =  c_z * s_y + c_y * s_x * s_z;
		e30 = 0.0f;
		// Y
		e01 =  c_z * s_x * s_y + c_y * s_z;
		e11 =  c_x * c_z;
		e21 = -c_y * c_z * s_x + s_y * s_z;
		e31 = 0.0f;
		// Z
		e02 = -c_x * s_y;
		e12 =  s_x;
		e22 =  c_x * c_y;
	}

	void Matrix4x4::look_at( const Vector3& _point ) {
	}

	void Matrix4x4::set_position( const float &&_x, const float &&_y, const float &&_z ) {
		e30 = _x;
		e31 = _y;
		e32 = _z;
	}

	void Matrix4x4::set_position( const Vector3&& _vector ) {
		e30 = _vector.x;
		e31 = _vector.y;
		e32 = _vector.z;
	}

	Vector3 Matrix4x4::get_position( ) const {
		return Vector3( e30, e31, e32 );
	}

	/*	Row Major
		[00 01 02 03] -> right
		[10 11 12 13] -> up
		[20 21 22 23] -> facing
		[30 31 32 33] -> position

		Column Major
		|| || || ||
		-- -- -- --
		00 01 02 03
		10 11 12 13
		20 21 22 23
		30 31 32 33
		-- -- -- --
		|| Right 
		   || Up 
			  || facing
				 || position
	*/

	Vector3 Matrix4x4::get_facing( ) const {
		return Vector3( e20, e21, e22 );
	}

	Vector3 Matrix4x4::get_up( ) const {
		return Vector3( e10, e11, e12 );
	}

	Vector3 Matrix4x4::get_right( ) const {
		return Vector3( e00, e01, e02 );
	}
}

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