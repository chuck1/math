//////////////////////////////////////////////////////////////////////////////////////////
//	vec3.h
//	Class declaration for a 3d vector
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	8th November 2002	-	Changed Constructor layout
//									-	Some speed Improvements
//									-	Corrected Lerp
//				7th January 2003	-	Added QuadraticInterpolate
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#ifndef vec3_H
#define vec3_H

#include <math/math.h>

namespace math
{
	class vec3
	{
		public:
			//constructors
			vec3(void)	:	x(0.0f), y(0.0f), z(0.0f)
		{}

			vec3(float newX, float newY, float newZ)	:	x(newX), y(newY), z(newZ)
		{}

			vec3(const float * rhs)	:	x(*rhs), y(*(rhs+1)), z(*(rhs+2))
		{}

			vec3(const vec3 & rhs)	:	x(rhs.x), y(rhs.y), z(rhs.z)
		{}

			~vec3() {}	//empty

			void Set(float newX, float newY, float newZ)
			{	x=newX;	y=newY;	z=newZ;	}

			//Accessors kept for compatibility
			void SetX(float newX) {x = newX;}
			void SetY(float newY) {y = newY;}
			void SetZ(float newZ) {z = newZ;}

			float GetX() const {return x;}	//public accessor functions
			float GetY() const {return y;}	//inline, const
			float GetZ() const {return z;}

			void LoadZero(void)
			{	x=y=z=0.0f;	}
			void LoadOne(void)
			{	x=y=z=1.0f;	}

			//vector algebra
			vec3 cross(const vec3 & rhs) const
			{	return vec3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);	}

			float dot(const vec3 & rhs) const
			{	return x*rhs.x + y*rhs.y + z*rhs.z;	}

			void normalize();
			vec3 GetNormalized() const;

			float magnitude() const
			{	return (float)sqrt((x*x)+(y*y)+(z*z));	}

			float magnitudeSquared() const
			{	return (x*x)+(y*y)+(z*z);	}

			//rotations
			void RotateX(double angle);
			vec3 GetRotatedX(double angle) const;
			void RotateY(double angle);
			vec3 GetRotatedY(double angle) const;
			void RotateZ(double angle);
			vec3 GetRotatedZ(double angle) const;
			void RotateAxis(double angle, const vec3 & axis);
			vec3 GetRotatedAxis(double angle, const vec3 & axis) const;

			//pack to [0,1] for color
			void PackTo01();
			vec3 GetPackedTo01() const;

			//linear interpolate
			vec3 lerp(const vec3 & v2, float factor) const
			{	return (*this)*(1.0f-factor) + v2*factor;	}

			vec3 QuadraticInterpolate(const vec3 & v2, const vec3 & v3, float factor) const
			{	return (*this)*(1.0f-factor)*(1.0f-factor) + 2*v2*factor*(1.0f-factor) + v3*factor*factor;}


			//overloaded operators
			//binary operators
			vec3 operator+(const vec3 & rhs) const
			{	return vec3(x + rhs.x, y + rhs.y, z + rhs.z);	}

			vec3 operator-(const vec3 & rhs) const
			{	return vec3(x - rhs.x, y - rhs.y, z - rhs.z);	}

			vec3 operator*(const float rhs) const
			{	return vec3(x*rhs, y*rhs, z*rhs);	}

			vec3 operator/(const float rhs) const
			{	return (rhs==0.0f) ? vec3(0.0f, 0.0f, 0.0f) : vec3(x / rhs, y / rhs, z / rhs);	}

			//multiply by a float, eg 3*v
			friend vec3 operator*(float scaleFactor, const vec3 & rhs);

			//Add, subtract etc, saving the construction of a temporary
			void Add(const vec3 & v2, vec3 & result)
			{
				result.x=x+v2.x;
				result.y=y+v2.y;
				result.z=z+v2.z;
			}

			void Subtract(const vec3 & v2, vec3 & result)
			{
				result.x=x-v2.x;
				result.y=y-v2.y;
				result.z=z-v2.z;
			}

			bool operator==(const vec3 & rhs) const;
			bool operator!=(const vec3 & rhs) const
			{	return !((*this)==rhs);	}

			//self-add etc
			void operator+=(const vec3 & rhs)
			{	x+=rhs.x;	y+=rhs.y;	z+=rhs.z;	}

			void operator-=(const vec3 & rhs)
			{	x-=rhs.x;	y-=rhs.y;	z-=rhs.z;	}

			void operator*=(const float rhs)
			{	x*=rhs;	y*=rhs;	z*=rhs;	}

			void operator/=(const float rhs)
			{	if(rhs==0.0f)
				return;
				else
				{	x/=rhs; y/=rhs; z/=rhs;	}
			}


			void	print();
			//unary operators
			vec3 operator-(void) const {return vec3(-x, -y, -z);}
			vec3 operator+(void) const {return *this;}

			//cast to pointer to a (float *) for glVertex3fv etc
			operator float* () const {return (float*) this;}
			operator const float* () const {return (const float*) this;}

			//member variables
			float x;
			float y;
			float z;
	};
}

#endif	//vec3_H
