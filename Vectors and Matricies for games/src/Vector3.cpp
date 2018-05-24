#include "Vector3.h"

namespace math {
	Vector3::Vector3( float _x, float _y, float _z )
		: x( _x ), y( _y ), z( _z ) {
	};

	Vector3::Vector3( const Vector3& _input )
		: x( _input.x ), y( _input.y ), z( _input.z ) {
	}

	Vector3 Vector3::operator= ( const Vector3& _input ) {
		if( this != &_input ) {
			x = _input.x;
			y = _input.y;
			z = _input.z;
		}
		return (*this);
	}

	Vector3 Vector3::operator+ ( const Vector3& _input ) {
		x += _input.x;
		y += _input.y;
		z += _input.z;
		return (*this);
	}

	Vector3 Vector3::operator- ( const Vector3& _input ) {
		x -= _input.x;
		y -= _input.y;
		z -= _input.z;
		return (*this);
	}

	Vector3 Vector3::operator* ( const Vector3& _input ) {
		x *= _input.x;
		y *= _input.y;
		z *= _input.z;
		return (*this);
	}

	Vector3 Vector3::operator/ ( const Vector3& _input ) {
		x /= _input.x;
		y /= _input.y;
		z /= _input.z;
		return (*this);
	}

	inline float Vector3::LengthSquared( ) const {
		return (x * x + y * y + z * z);
	}

	inline float Vector3::Length( ) const {
		return sqrtf( x * x + y * y + z * z );
	}

	inline bool Vector3::IsZero( ) const {
		return fabs( x * x + y * y + z * z ) < _epsilon;
	}

	void Vector3::Normalise( ) {
		if( IsZero( ) ) {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			return;
		}
		/*	 1
			---
			|v|
		*/
		float length = 1.0f / sqrtf( LengthSquared( ) );
		x *= length;
		y *= length;
		z *= length;
	}

	float Vector3::Dot( const Vector3& _w ) const {
		return (x * _w.x + y * _w.y + z * _w.z);
	}

	Vector3 Vector3::Cross( const Vector3& _w ) const {
		return Vector3( y * _w.z - _w.y * z,
						z * _w.x - _w.z * x,
						x * _w.y - _w.x * y );
	}

	Vector3 Vector3::TripleProduct( const Vector3& _w ) const {
		return Vector3( Cross( _w, this->Cross( _w ) ) );
	}

	float Vector3::ScalarTripleProduct( const Vector3& _w, const Vector3& _u ) const {
		return Dot( _u, this->Cross( _w ) );
	}

	// finds the angle between two given vectors (v,w)
	float Vector3::Dot( const Vector3& _v, const Vector3& _w ) {
		return (_v.x * _w.x + _v.y * _w.y + _v.z * _w.z);
	}

	// compute a new orthogonal vector, ( perpendicular ) to two given vectors (v,w)
	Vector3 Vector3::Cross( const Vector3& _v, const Vector3& _w ) {
		return Vector3( _v.y * _w.z - _w.y * _v.z,
						_v.z * _w.x - _w.z * _v.x,
						_v.x * _w.y - _w.x * _v.y );
	}

	// puts vector between 0 -> 1 (unit vector)
	Vector3 Vector3::Normalise( const Vector3& _v ) {
		if( _v.IsZero( ) ) {
			return Vector3( 0.0f, 0.0f, 0.0f );
		}
		/*	 1
			---
			|v|
		*/
		float length = 1.0f / sqrtf( _v.LengthSquared( ) );
		return Vector3( _v.x * length, _v.y * length, _v.z * length );
	}

	Vector3 Vector3::TripleProduct( const Vector3& _v, const Vector3& _w ) {
		return Vector3( Cross( _w, Cross( _v, _w ) ) );
	}

	float Vector3::ScalarTripleProduct( const Vector3& _v, const Vector3& _w, const Vector3& _u ) {
		return Dot( _u, Cross( _v, _w ) );
	}

	float Vector3::LengthSquared( const Vector3& _v ) {
		return (_v.x * _v.x + _v.y * _v.y + _v.z * _v.z);
	}

	float Vector3::Length( const Vector3& _v ) {
		return sqrtf( _v.x * _v.x + _v.y * _v.y + _v.z * _v.z );
	}

	bool  Vector3::IsZero( const Vector3& _v ) {
		return fabs( _v.x * _v.x + _v.y * _v.y + _v.z * _v.z ) < _epsilon;
	}

	bool  Vector3::IsZero( const float& _input ) {
		return _input < _epsilon;
	}

	const Vector3 Vector3::Zero( 0.0f, 0.0f, 0.0f );
	const Vector3 Vector3::One( 1.0f, 1.0f, 1.0f );
	const Vector3 Vector3::Right( -1.0f, 0.0f, 0.0f );
	const Vector3 Vector3::Forward( 0.0f, 0.0f, 1.0f );
	const Vector3 Vector3::Up( 0.0f, 1.0f, 0.0f );
}