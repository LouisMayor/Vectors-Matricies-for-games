#pragma once

#include "MathStuff.h"

namespace math {
	class Vector3 {
	public:
		/* Constructors/Destructor */
		Vector3( float _x, float _y, float _z );

		Vector3( const Vector3& _input );

		/* Operator overloaders */
		Vector3 operator= ( const Vector3& _input );

		Vector3 operator+ ( const Vector3& _input );

		Vector3 operator- ( const Vector3& _input );

		Vector3 operator* ( const Vector3& _input );

		Vector3 operator/ ( const Vector3& _input );

		/* Member Functions */

		/* Magnitude/Length squared function */
		inline float LengthSquared( )	const;

		/* Magnitude/Length function |v| */
		inline float Length( )			const;

		inline bool  IsZero( )			const;

		// puts vector between 0 -> 1 (unit vector)
		void Normalise( );

		// finds the angle between two given vectors (v,w)
		float Dot( const Vector3& _w ) const;

		// compute a new orthogonal vector, ( perpendicular ) to two given vectors (v,w)
		// Example usage: face normals, or camera's up vector
		Vector3 Cross( const Vector3& _w ) const;

		Vector3 TripleProduct( const Vector3& _w ) const;

		/*	Example usage: if ScalarTripleProduct(v,w,u) > 0
			'u' must be left of v cross w, and soo on. i.e.
			tells us if an object is left/right of a given position
			--------------------------------------------------------
			there is an alternative method (which is cheaper)
			compute vector from target to source and do
			dot (axis X, target difference vector)
		*/
		float ScalarTripleProduct( const Vector3& _w, const Vector3& _u ) const;

		float FindAngleBetween( Vector3& _w ) const;

		/* Non-member Functions */
		static float	LengthSquared			( const Vector3& _v );
		static float	Length					( const Vector3& _v );
		static bool		IsZero					( const Vector3& _v ) ;
		static bool		IsZero					( const float&	 _input );
		static Vector3	Cross					( const Vector3& _v, const Vector3& _w	);
		static float	Dot						( const Vector3& _v, const Vector3& _w	);
		static Vector3	Normalise				( const Vector3& _v						);
		static Vector3	TripleProduct			( const Vector3& _v, const Vector3& _w	);
		static float	ScalarTripleProduct		( const Vector3& _v, const Vector3& _w, const Vector3& _u );
		static float	FindAngleBetween		( Vector3& _v, Vector3& _w, Vector3& _u );
		static bool 	FindDirectionBetween	( Vector3& _v, Vector3& _w, Vector3& _u, float* out_value = nullptr, bool _convert_to_degress = false );

		/* Member variables */
		float x, y, z;

		/* Non-member variables */
		static const Vector3 Zero;
		static const Vector3 One;
		static const Vector3 Right;
		static const Vector3 Forward;
		static const Vector3 Up;
	};
}