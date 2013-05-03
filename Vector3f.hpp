#ifndef _VECTOR3F_HPP
#define _VECTOR3F_HPP

#include <math.h>
#include <iostream>
#include <string>
#include <sstream>


class Vector3f
{
	//Fields
	public:
		float x;
		float y;
		float z;
	
	private:
		std::string Vector3fString;

	//Functions
	public:	
	
		Vector3f(void);
		Vector3f(float all);
		Vector3f(float x, float y, float z);
		Vector3f(Vector3f* that);
        Vector3f(Vector3f& that);
        Vector3f(const Vector3f& that);

		void normalize(void);
		void crossProduct(Vector3f* that);

		inline void copy(Vector3f* that)
		{
            this->x = that->x;
            this->y = that->y;
            this->z = that->z;
		}
		
		inline void zeroOut(void)
		{
            this->x = 0.0f;
            this->y = 0.0f;
            this->z = 0.0f;
		}
		
		inline float magnitude(void)
		{
			return sqrt((x * x) + (y * y) + (z * z));
		}
		
		inline float magnitudeSquared(void)
		{
			return (x * x) + (y * y) + (z * z);
		}
		
		inline float dotProduct(Vector3f* that)
		{
            return (this->x * that->x) + (this->y * that->y) + (this->z * that->z);
		}
		
		inline float dotProductSquared(Vector3f* that)
		{
            float num = (this->x * that->x) + (this->y * that->y) + (this->z * that->z);
			return num * num;
		}
	
		inline void add(Vector3f* that)
		{
            this->x += that->x;
            this->y += that->y;
            this->z += that->z;
		}

        inline void add(Vector3f& that)
        {
            this->x += that.x;
            this->y += that.y;
            this->z += that.z;
        }
		
        inline void divideByScalar(float scalar)
        {
            this->x /= scalar;
            this->y /= scalar;
            this->z /= scalar;
        }

		inline void subtract(Vector3f* that)
		{        
            this->x -= that->x;
            this->y -= that->y;
            this->z -= that->z;
		}
		
		inline void scale(float scalar)
		{
			x *= scalar;
       		y *= scalar;
       		z *= scalar;		
		}	  
		
		inline void set(float x, float y, float z)
		{
            this->x = x;
            this->y = y;
            this->z = z;
		}

		inline void set(Vector3f* that)
		{
			this->x = that->x;
            this->y = that->y;
            this->z = that->z;
		}

		inline bool equals(Vector3f* that)
		{
            return ((this->x == that->x) && (this->y == that->y) && (this->z == that->z));
		}
		
		inline bool operator == (Vector3f* that)
		{
            return ((this->x == that->x) && (this->y == that->y) && (this->z == that->z));
		} 
	
	protected:
	private:
};


namespace Vector3fUtil
{
	//Namespace Functions
	Vector3f* add(Vector3f* one, Vector3f* two);
	Vector3f* subtract(Vector3f* one, Vector3f* two);

	Vector3f* scale(Vector3f* vector, float scalar);

	Vector3f* normalize(Vector3f* vector);

	Vector3f* crossProduct(Vector3f* one, Vector3f* two);

	void rotateVectorByAngle(Vector3f* vector, float angle);

	Vector3f midPoint(Vector3f* one, Vector3f* two);

	float distance(Vector3f* one, Vector3f* two);
	float distanceSquared(Vector3f* one, Vector3f* two);

	//float angleBetween(Vector3f& one, Vector3f& two, Vector3f& ref);
}
#endif

