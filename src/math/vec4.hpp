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
#include <math/vecbase.hpp>

namespace math {
	template<typename T> class vec4: public vecbase<T,4> {
		public:
			T&		w() { return vecbase<T,4>::v[0]; }
			T&		x() { return vecbase<T,4>::v[1]; }
			T&		y() { return vecbase<T,4>::v[2]; }
			T&		z() { return vecbase<T,4>::v[3]; }
			
			/** @name Constructors
			 * @{
			 */
			vec4(const vec3<T> & rhs) {
				x() = rhs.v[0];
				y() = rhs.v[1];
				z() = rhs.v[2];
				w() = 1.0f;
			}
			vec4(vec3<T> const & rhs,T const & newW) {
				x() = rhs.v[0];
				y() = rhs.v[1];
				z() = rhs.v[2];
				w() = newW;
			}
			vec4() { vecbase<T,4>::loadZero(); }
			vec4(T newX, T newY, T newZ, T newW) {
				x() = (newX);
				y() = (newY);
				z() = (newZ);
				w() = (newW);
			}
			vec4(T const * rhs): vecbase<T,4>(rhs) {}
			vec4(const vec4 & rhs):	vecbase<T,4>(rhs) {}
			/** @} */


			/** @name Rotations
			 * @{
			 */
			void		rotateX(T angle) {
				(*this)=GetRotatedX(angle);

			}
			vec4<T>		getRotatedX(T angle) const {
				math::vec3<T> v3d(x, y, z);
				
				v3d.rotateX(angle);

				return math::vec4<T>(v3d, w);
			}
			void		rotateY(T angle) {
				(*this)=GetRotatedY(angle);
			}
			vec4<T>		getRotatedY(T angle) const {
				math::vec3<T> v3d(x, y, z);

				v3d.rotateY(angle);

				return math::vec4<T>(v3d, w);
			}
			void		rotateZ(T angle) {
				(*this)=GetRotatedZ(angle);
			}

			vec4<T>		getRotatedZ(T angle) const {
				math::vec3<T> v3d(x, y, z);

				v3d.RotateZ(angle);

				return math::vec4<T>(v3d, w);
			}
			void		rotateAxis(T angle, const math::vec3<T> & axis) {
				(*this)=GetRotatedAxis(angle, axis);
			}

			math::vec4<T>	getRotatedAxis(T angle, const math::vec3<T> & axis) const
			{
				math::vec3<T> v3d(x, y, z);

				v3d.RotateAxis(angle, axis);

				return math::vec4<T>(v3d, w);
			}
			/** @} */

			/** @name Comparison
			 * @{
			 */
			bool		operator==(const math::vec4<T> & rhs) const {
				return vecbase<T,4>::operator==(rhs);
			}
			bool		operator!=(const vec4 & rhs) const {
				return vecbase<T,4>::operator==(rhs);
			}	
			/** @} */

			operator math::vec3<T>() {
				if(w==0.0f || w==1.0f)
					return math::vec3<T>(x, y, z);
				else
					return math::vec3<T>(x/w, y/w, z/w);
			}
			math::mat44<T>	operator*(math::vec4<T> const & rhs) {
				math::mat44<T> ret(
						x*rhs.x, y*rhs.x, z*rhs.x, w*rhs.x,
						x*rhs.y, y*rhs.y, z*rhs.y, w*rhs.y,
						x*rhs.z, y*rhs.z, z*rhs.z, w*rhs.z,
						x*rhs.w, y*rhs.w, z*rhs.w, w*rhs.w);

				return ret;
			}
			void	print()
			{
				printf("%f %f %f %f\n",x,y,z,w);
			}

			//constructors
			//convert v3d to v4d


			~vec4() {}	//empty

			void Set(T newX, T newY, T newZ, T newW)
			{	x=newX;	y=newY;	z=newZ; w=newW;	}

			//accessors kept for compatability
			void SetX(T newX) {x = newX;}
			void SetY(T newY) {y = newY;}
			void SetZ(T newZ) {z = newZ;}
			void SetW(T newW) {w = newW;}

			T GetX() const {return x;}	//public accessor functions
			T GetY() const {return y;}	//inline, const
			T GetZ() const {return z;}
			T GetW() const {return w;}

			void LoadZero(void)
			{	x=0.0f; y=0.0f; z=0.0f; w=0.0f;	}

			void LoadOne(void)
			{	x=1.0f; y=1.0f; z=1.0f; w=1.0f;	}


			//vector algebra
			T dot(const vec4 & rhs) {
				return vecbase<T,4>::dot(rhs);
			}
			
			vec4 lerp(const vec4 & v2, T factor) const
			{	return (*this)*(1.0f-factor)+v2*factor;	}

			vec4 QuadraticInterpolate(const vec4 & v2, const vec4 & v3, T factor) const
			{	return (*this)*(1.0f-factor)*(1.0f-factor) + v2*2*factor*(1.0f-factor) + v3*factor*factor;}

			//binary operators
			vec4 operator+(const vec4 & rhs) const
			{	return vec4(x+rhs.x, y+rhs.y, z+rhs.z, w+rhs.w);	}
			vec4 operator+(const T & rhs) const
			{	return vec4(x+rhs, y+rhs, z+rhs, w+rhs);	}

			vec4 operator-(const vec4 & rhs) const
			{	return vec4(x-rhs.x, y-rhs.y, z-rhs.z, w-rhs.w);	}

			vec4 operator*(const T rhs) const
			{	return vec4(x*rhs, y*rhs, z*rhs, w*rhs);	}

			vec4 operator/(const T rhs) const
			{	return rhs==0.0f	?	vec4(0.0f, 0.0f, 0.0f, 0.0f): vec4(x/rhs, y/rhs, z/rhs, w/rhs);	}

			//multiply by a T, eg 3*v
			//friend vec4 operator*(T scaleFactor, const vec4 & rhs);

		
			//self-add etc
			void operator+=(const vec4 & rhs)
			{	x+=rhs.x; y+=rhs.y; z+=rhs.z; w+=rhs.w;	}

			void operator-=(const vec4 & rhs)
			{	x-=rhs.x; y-=rhs.y; z-=rhs.z; w-=rhs.w;	}

			void operator*=(const T rhs)
			{	x*=rhs; y*=rhs; z*=rhs; w*=rhs;	}

			void operator/=(const T rhs)
			{	if(rhs==0.0f)
				return;
				else
				{	x/=rhs; y/=rhs; z/=rhs; w/=rhs;	}
			}

			//cast to pointer to T for glVertex4fv etc
			operator T* () const {return (T*) this;}
			operator const T* () const {return (const T*) this;}

	};
}

#endif	//vec3<T>_H
