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

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

#include <math/math.h>

namespace math
{
	class vec3
	{
		public:
			//constructors
			vec3(void):	x(0.0f), y(0.0f), z(0.0f){}
			vec3(float newX, float newY, float newZ):x(newX), y(newY), z(newZ){}
			vec3(const float * rhs):x(*rhs), y(*(rhs+1)), z(*(rhs+2)){}
			vec3(const vec3 & rhs):x(rhs.x), y(rhs.y), z(rhs.z){}
#ifdef PHYSX
			vec3(physx::PxVec3 const & rhs) {
				x=rhs.x;
				y=rhs.y;
				z=rhs.z;
			}
#endif
			~vec3() {}	//empty

			void		Set(float newX, float newY, float newZ){
				x=newX;	y=newY;	z=newZ;
			}
			//Accessors kept for compatibility
			void		SetX(float newX) {x = newX;}
			void		SetY(float newY) {y = newY;}
			void		SetZ(float newZ) {z = newZ;}
			float		GetX() const {return x;}	//public accessor functions
			float		GetY() const {return y;}	//inline, const
			float		GetZ() const {return z;}
			void		LoadZero(void){	x=y=z=0.0f;	}
			void		LoadOne(void){	x=y=z=1.0f;	}
			bool		is_finite() const;
			//vector algebra
			vec3		cross(const vec3 & rhs) const
			{
				return vec3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
			}
			float		dot(const vec3 & rhs) const
			{
				return x*rhs.x + y*rhs.y + z*rhs.z;
			}
			void		normalize();
			vec3		GetNormalized() const;
			float		magnitude() const{	return (float)sqrt((x*x)+(y*y)+(z*z));	}
			float		magnitudeSquared() const{	return (x*x)+(y*y)+(z*z);	}
			float		angle(vec3 const & rhs) const;
			//rotations
			void		RotateX(double angle);
			void		RotateY(double angle);
			void		RotateZ(double angle);
			void		RotateAxis(double angle, const vec3 & axis);
			vec3		GetRotatedX(double angle) const;
			vec3		GetRotatedY(double angle) const;
			vec3		GetRotatedZ(double angle) const;
			vec3		GetRotatedAxis(double angle, const vec3 & axis) const;
			//pack to [0,1] for color
			void		PackTo01();
			vec3		GetPackedTo01() const;
			//linear interpolate
			vec3		lerp(const vec3 & v2, float factor) const
			{
				return (*this)*(1.0f-factor) + v2*factor;
			}
			vec3		QuadraticInterpolate(
					const vec3 & v2,
					const vec3 & v3,
					float factor) const
			{
				return (*this)*(1.0f-factor)*(1.0f-factor)+
					2*v2*factor*(1.0f-factor)+
					v3*factor*factor;
			}

			//overloaded operators
			//binary operators
			vec3		operator+(const vec3 & rhs) const
			{
				return vec3(x + rhs.x, y + rhs.y, z + rhs.z);
			}
			vec3		operator-(const vec3 & rhs) const
			{
				return vec3(x - rhs.x, y - rhs.y, z - rhs.z);	}
				vec3		operator*(const float rhs) const
				{
					return vec3(x*rhs, y*rhs, z*rhs);	}
					vec3		operator/(const float rhs) const
					{
						return (rhs==0.0f) ? vec3(0.0f, 0.0f, 0.0f) : vec3(x / rhs, y / rhs, z / rhs);	
					}

					//multiply by a float, eg 3*v
					friend vec3 operator*(float scaleFactor, const vec3 & rhs);

					//Add, subtract etc, saving the construction of a temporary
					void		Add(const vec3 & v2, vec3 & result);
					void		Subtract(const vec3 & v2, vec3 & result);

					bool		operator==(const vec3 & rhs) const;
					bool		operator!=(const vec3 & rhs) const;
					//self-add etc
					void		operator+=(const vec3 & rhs);
					void		operator-=(const vec3 & rhs);
					void		operator*=(const float rhs);
					void		operator/=(const float rhs);

					void		print();
					//unary operators
					vec3		operator-(void) const {return vec3(-x, -y, -z);}
					vec3		operator+(void) const {return *this;}

					//cast to pointer to a (float *) for glVertex3fv etc
					operator float* () const {return (float*) this;}
					operator const float* () const {return (const float*) this;}

#ifdef PHYSX
					operator physx::PxVec3() const { return physx::PxVec3(x,y,z); }
					vec3&		operator=(physx::PxVec3 const & rhs) {
						x=rhs.x;
						y=rhs.y;
						z=rhs.z;
						return *this;
					}
#endif
					//member variables
					float		x;
					float		y;
					float		z;
	};
}

#endif	//vec3_H
