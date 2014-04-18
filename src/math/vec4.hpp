//////////////////////////////////////////////////////////////////////////////////////////
//	vec4.h
//	Class declaration for a 4d vector
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

#ifndef vec4_H
#define vec4_H

#include <math/config.hpp>

namespace math {
	class vec4 {
		public:
			//constructors
			vec4(void)	:	x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{}

			vec4(double newX, double newY, double newZ, double newW)	
				:	x(newX), y(newY), z(newZ), w(newW)
			{}

			vec4(const double * rhs)	:	x(*rhs), y(*(rhs+1)), z(*(rhs+2)), w(*(rhs+3))
		{}

			vec4(const vec4 & rhs):	x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w)
		{}
			//convert v3d to v4d
			vec4(const vec3<double> & rhs);
			vec4(const vec3<double> & rhs,double const & newW);


			~vec4() {}	//empty

			void Set(double newX, double newY, double newZ, double newW)
			{	x=newX;	y=newY;	z=newZ; w=newW;	}

			//accessors kept for compatability
			void SetX(double newX) {x = newX;}
			void SetY(double newY) {y = newY;}
			void SetZ(double newZ) {z = newZ;}
			void SetW(double newW) {w = newW;}

			double GetX() const {return x;}	//public accessor functions
			double GetY() const {return y;}	//inline, const
			double GetZ() const {return z;}
			double GetW() const {return w;}

			void LoadZero(void)
			{	x=0.0f; y=0.0f; z=0.0f; w=0.0f;	}

			void LoadOne(void)
			{	x=1.0f; y=1.0f; z=1.0f; w=1.0f;	}


			//vector algebra
			double DotProduct(const vec4 & rhs)
			{	return x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w;	}

			//rotations
			void RotateX(double angle);
			vec4 GetRotatedX(double angle) const;
			void RotateY(double angle);
			vec4 GetRotatedY(double angle) const;
			void RotateZ(double angle);
			vec4 GetRotatedZ(double angle) const;
			void RotateAxis(double angle, const vec3<double> & axis);
			vec4 GetRotatedAxis(double angle, const vec3<double> & axis) const;
			void	print();
		
			bool	isFinite() const;	
			bool	isSane() const {return (!isNan() && isFinite());}
			bool	isNan() const;
			
			vec4 lerp(const vec4 & v2, double factor) const
			{	return (*this)*(1.0f-factor)+v2*factor;	}

			vec4 QuadraticInterpolate(const vec4 & v2, const vec4 & v3, double factor) const
			{	return (*this)*(1.0f-factor)*(1.0f-factor) + v2*2*factor*(1.0f-factor) + v3*factor*factor;}

			//binary operators
			vec4 operator+(const vec4 & rhs) const
			{	return vec4(x+rhs.x, y+rhs.y, z+rhs.z, w+rhs.w);	}
			vec4 operator+(const double & rhs) const
			{	return vec4(x+rhs, y+rhs, z+rhs, w+rhs);	}

			vec4 operator-(const vec4 & rhs) const
			{	return vec4(x-rhs.x, y-rhs.y, z-rhs.z, w-rhs.w);	}

			vec4 operator*(const double rhs) const
			{	return vec4(x*rhs, y*rhs, z*rhs, w*rhs);	}

			vec4 operator/(const double rhs) const
			{	return rhs==0.0f	?	vec4(0.0f, 0.0f, 0.0f, 0.0f): vec4(x/rhs, y/rhs, z/rhs, w/rhs);	}

			//multiply by a double, eg 3*v
			//friend vec4 operator*(double scaleFactor, const vec4 & rhs);

			bool operator==(const vec4 & rhs) const;
			bool operator!=(const vec4 & rhs) const
			{	return !((*this)==rhs);	}

			//self-add etc
			void operator+=(const vec4 & rhs)
			{	x+=rhs.x; y+=rhs.y; z+=rhs.z; w+=rhs.w;	}

			void operator-=(const vec4 & rhs)
			{	x-=rhs.x; y-=rhs.y; z-=rhs.z; w-=rhs.w;	}

			void operator*=(const double rhs)
			{	x*=rhs; y*=rhs; z*=rhs; w*=rhs;	}

			void operator/=(const double rhs)
			{	if(rhs==0.0f)
				return;
				else
				{	x/=rhs; y/=rhs; z/=rhs; w/=rhs;	}
			}

			mat44 operator*(vec4 const & rhs);

			//unary operators
			vec4 operator-(void) const {return vec4(-x, -y, -z, -w);}
			vec4 operator+(void) const {return (*this);}

			//cast to pointer to double for glVertex4fv etc
			operator double* () const {return (double*) this;}
			operator const double* () const {return (const double*) this;}

			operator vec3<double>();							//convert v4d to v3d

			//member variables
			double x;
			double y;
			double z;
			double w;
	};
}

#endif	//vec3<double>_H