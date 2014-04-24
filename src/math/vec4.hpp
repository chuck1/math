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
	template <typename T> class vec4: public vecbase<T,4> {
		public:
			/** @name Constructors
			 * @{
			 */
			vec4(const vec3<double> & rhs): x(rhs.v[0]), y(rhs.v[1]), z(rhs.v[2]), w(1.0f) {}
			vec4(const vec3<double> & rhs,double const & newW): x(rhs.v[0]), y(rhs.v[1]), z(rhs.v[2]), w(newW) {}
			vec4(): x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
			vec4(double newX, double newY, double newZ, double newW): x(newX), y(newY), z(newZ), w(newW) {}
			vec4(const double * rhs): x(*rhs), y(*(rhs+1)), z(*(rhs+2)), w(*(rhs+3)) {}
			vec4(const vec4 & rhs):	x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}
			/** @} */


			bool	isNan() const {
				if(isnan(x)) return true;
				if(isnan(y)) return true;
				if(isnan(z)) return true;
				if(isnan(w)) return true;
				return false;
			}
			bool	isFinite() const {
				if(isinf(w)) return false;
				if(isinf(x)) return false;
				if(isinf(y)) return false;
				if(isinf(z)) return false;
				return true;
			}

			/** @name Rotations
			 * @{
			 */
			void math::vec4::RotateX(double angle)
			{
				(*this)=GetRotatedX(angle);
			}

			math::vec4 math::vec4::GetRotatedX(double angle) const
			{
				math::vec3<double> v3d(x, y, z);

				v3d.RotateX(angle);

				return math::vec4(v3d, w);
			}

			void math::vec4::RotateY(double angle)
			{
				(*this)=GetRotatedY(angle);
			}

			math::vec4 math::vec4::GetRotatedY(double angle) const
			{
				math::vec3<double> v3d(x, y, z);

				v3d.RotateY(angle);

				return math::vec4(v3d, w);
			}

			void math::vec4::RotateZ(double angle)
			{
				(*this)=GetRotatedZ(angle);
			}

			math::vec4 math::vec4::GetRotatedZ(double angle) const
			{
				math::vec3<double> v3d(x, y, z);

				v3d.RotateZ(angle);

				return math::vec4(v3d, w);
			}

			void math::vec4::RotateAxis(double angle, const math::vec3<double> & axis)
			{
				(*this)=GetRotatedAxis(angle, axis);
			}

			math::vec4 math::vec4::GetRotatedAxis(double angle, const math::vec3<double> & axis) const
			{
				math::vec3<double> v3d(x, y, z);

				v3d.RotateAxis(angle, axis);

				return math::vec4(v3d, w);
			}
			/** @} */

			/** @name Logical operators
			 * @{
			 */
			bool math::vec4::operator==(const math::vec4 & rhs) const
			{
				if(x==rhs.x && y==rhs.y && z==rhs.z && w==rhs.w)
					return true;

				return false;
			}
			/** @} */

			math::vec4::operator math::vec3<double>()
			{
				if(w==0.0f || w==1.0f)
					return math::vec3<double>(x, y, z);
				else
					return math::vec3<double>(x/w, y/w, z/w);
			}
			math::mat44 math::vec4::operator*(math::vec4 const & rhs)
			{
				math::mat44 ret(
						x*rhs.x, y*rhs.x, z*rhs.x, w*rhs.x,
						x*rhs.y, y*rhs.y, z*rhs.y, w*rhs.y,
						x*rhs.z, y*rhs.z, z*rhs.z, w*rhs.z,
						x*rhs.w, y*rhs.w, z*rhs.w, w*rhs.w);

				return ret;
			}
			void	math::vec4::print()
			{
				printf("%f %f %f %f\n",x,y,z,w);
			}

			//constructors
			//convert v3d to v4d


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

			mat44<T> operator*(vec4 const & rhs);

			//unary operators
			vec4 operator-(void) const {return vec4(-x, -y, -z, -w);}
			vec4 operator+(void) const {return (*this);}

			//cast to pointer to double for glVertex4fv etc
			operator double* () const {return (double*) this;}
			operator const double* () const {return (const double*) this;}

			operator vec3<double>();							//convert v4d to v3d
	};
}

#endif	//vec3<double>_H
