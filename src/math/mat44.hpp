#ifndef __MATH_MAT44_H__
#define __MATH_MAT44_H__

#include <cstdlib>

#include <math/config.hpp>
#include <math/vecbase.hpp>

namespace math {
	template <typename T> class mat44: public math::matsqu<T,4> {
		public:
			/** @name Constructors @{ */
			mat44() {
				matsqu<T,4>::loadIdentity();
			}
			mat44(matsqu<T,4> const & rhs): matsqu<T,4>(rhs) {}
			mat44(T e0, T e1, T e2, T e3, T e4, T e5, T e6, T e7, T e8, T e9, T e10, T e11, T e12, T e13, T e14, T e15) {
				matbase<T,4,4>::v(0,0) = e0;
				matbase<T,4,4>::v(0,1) = e1;
				matbase<T,4,4>::v(0,2) = e2;
				matbase<T,4,4>::v(0,3) = e3;
				matbase<T,4,4>::v(1,0) = e4;
				matbase<T,4,4>::v(1,1) = e5;
				matbase<T,4,4>::v(1,2) = e6;
				matbase<T,4,4>::v(1,3) = e7;
				matbase<T,4,4>::v(2,0) = e8;
				matbase<T,4,4>::v(2,1) = e9;
				matbase<T,4,4>::v(2,2) = e10;
				matbase<T,4,4>::v(2,3) = e11;
				matbase<T,4,4>::v(3,0) = e12;
				matbase<T,4,4>::v(3,1) = e13;
				matbase<T,4,4>::v(3,2) = e14;
				matbase<T,4,4>::v(3,3) = e15;
			}
			mat44(const mat44<T> & rhs): matsqu<T,4>(rhs) {}
			mat44(const T * rhs): matsqu<T,4>(rhs) {}
			mat44(const math::quat<T> & q) {
				const T x = q.x;
				const T y = q.y;
				const T z = q.z;
				const T w = q.w;

				const T x2 = x + x;
				const T y2 = y + y;
				const T z2 = z + z;

				const T xx = x2*x;
				const T yy = y2*y;
				const T zz = z2*z;

				const T xy = x2*y;
				const T xz = x2*z;
				const T xw = x2*w;

				const T yz = y2*z;
				const T yw = y2*w;
				const T zw = z2*w;

				matbase<T,4,4>::v(0,0) = 1.0f - yy - zz;
				matbase<T,4,4>::v(0,1) = xy + zw;
				matbase<T,4,4>::v(0,2) = xz - yw;
				matbase<T,4,4>::v(0,3) = 0.0f;
				matbase<T,4,4>::v(1,0) = xy - zw;
				matbase<T,4,4>::v(1,1) = 1.0f - xx - zz;
				matbase<T,4,4>::v(1,2) = yz + xw;
				matbase<T,4,4>::v(1,3) = 0.0f;
				matbase<T,4,4>::v(2,0) = xz + yw;
				matbase<T,4,4>::v(2,1) = yz - xw;
				matbase<T,4,4>::v(2,2) = 1.0f - xx - yy;
				matbase<T,4,4>::v(2,3) = 0.0f;
				matbase<T,4,4>::v(3,0) = 0.0f;
				matbase<T,4,4>::v(3,1) = 0.0f;
				matbase<T,4,4>::v(3,2) = 0.0f;
				matbase<T,4,4>::v(3,3) = 1.0f;
			}
			mat44(math::transform<T> const & t) {
				matsqu<T,4>::loadIdentity();

				set_rotation(t.q);
				SetTranslationPart(t.p);
			}
			/** @} */
			/** @name Accessors @{ */
			T&		v(int r, int c) {
				return matbase<T,4,4>::v(r,c);
			}
			T const &	v(int r, int c) const {
				return matbase<T,4,4>::v(r,c);
			}
			/** @} */
			void		set_rotation(math::quat<T> const & q)
			{
				const T x = q.x;
				const T y = q.y;
				const T z = q.z;
				const T w = q.w;

				const T x2 = x + x;
				const T y2 = y + y;
				const T z2 = z + z;

				const T xx = x2*x;
				const T yy = y2*y;
				const T zz = z2*z;

				const T xy = x2*y;
				const T xz = x2*z;
				const T xw = x2*w;

				const T yz = y2*z;
				const T yw = y2*w;
				const T zw = z2*w;

				matbase<T,4,4>::v(0,0) = 1.0f - yy - zz;
				matbase<T,4,4>::v(0,1) = xy + zw;
				matbase<T,4,4>::v(0,2) = xz - yw;

				matbase<T,4,4>::v(1,0) = xy - zw;
				matbase<T,4,4>::v(1,1) = 1.0f - xx - zz;
				matbase<T,4,4>::v(1,2) = yz + xw;

				matbase<T,4,4>::v(2,0) = xz + yw;
				matbase<T,4,4>::v(2,1) = yz - xw;
				matbase<T,4,4>::v(2,2) = 1.0f - xx - yy;
			}
			math::vec4<T>	getRow(int r) const {
				return math::vec4<T>(matbase<T,4,4>::getRow(r));
			}
			math::vec4<T>	getColumn(int c) const {
				return math::vec4<T>(matbase<T,4,4>::getColumn(c));
			}
			mat44<T> operator+(const mat44<T> & rhs) const {
				return matbase<T,4,4>::operator+(rhs);
			}
			mat44<T> operator-(const mat44<T> & rhs) const {
				return matbase<T,4,4>::operator-(rhs);
			}
			mat44<T> operator*(const mat44<T> & rhs) const {
				//return matbase<T,4,4>::operator*(rhs);
				//Optimise for matrices in which bottom row is (0, 0, 0, 1) in both matrices
				if(matbase<T,4,4>::v(0,3)==0.0f && matbase<T,4,4>::v(1,3)==0.0f && matbase<T,4,4>::v(2,3)==0.0f && matbase<T,4,4>::v(3,3)==1.0f	&&
						rhs.matbase<T,4,4>::v(0,3)==0.0f && rhs.matbase<T,4,4>::v(1,3)==0.0f &&
						rhs.matbase<T,4,4>::v(2,3)==0.0f && rhs.matbase<T,4,4>::v(3,3)==1.0f)
				{
					return math::mat44<T>(
							v(0,0)*rhs.v(0,0)+v(1,0)*rhs.v(0,1)+v(2,0)*rhs.v(0,2),
							v(0,1)*rhs.v(0,0)+v(1,1)*rhs.v(0,1)+v(2,1)*rhs.v(0,2),
							v(0,2)*rhs.v(0,0)+v(1,2)*rhs.v(0,1)+v(2,2)*rhs.v(0,2),
							0.0f,
							v(0,0)*rhs.v(1,0)+v(1,0)*rhs.v(1,1)+v(2,0)*rhs.v(1,2),
							v(0,1)*rhs.v(1,0)+v(1,1)*rhs.v(1,1)+v(2,1)*rhs.v(1,2),
							v(0,2)*rhs.v(1,0)+v(1,2)*rhs.v(1,1)+v(2,2)*rhs.v(1,2),
							0.0f,
							v(0,0)*rhs.v(2,0)+v(1,0)*rhs.v(2,1)+v(2,0)*rhs.v(2,2),
							v(0,1)*rhs.v(2,0)+v(1,1)*rhs.v(2,1)+v(2,1)*rhs.v(2,2),
							v(0,2)*rhs.v(2,0)+v(1,2)*rhs.v(2,1)+v(2,2)*rhs.v(2,2),
							0.0f,
							v(0,0)*rhs.v(3,0)+v(1,0)*rhs.v(3,1)+v(2,0)*rhs.v(3,2)+v(3,0),
							v(0,1)*rhs.v(3,0)+v(1,1)*rhs.v(3,1)+v(2,1)*rhs.v(3,2)+v(3,1),
							v(0,2)*rhs.v(3,0)+v(1,2)*rhs.v(3,1)+v(2,2)*rhs.v(3,2)+v(3,2),
							1.0f);
				}

				//Optimise for when bottom row of 1st matrix is (0, 0, 0, 1)
				if(	matbase<T,4,4>::v(0,3)==0.0f && matbase<T,4,4>::v(1,3)==0.0f && matbase<T,4,4>::v(2,3)==0.0f && matbase<T,4,4>::v(3,3)==1.0f)
				{
					return math::mat44<T>(
							v(0,0)*rhs.v(0,0)+v(1,0)*rhs.v(0,1)+v(2,0)*rhs.v(0,2)+v(3,0)*rhs.v(0,3),
							v(0,1)*rhs.v(0,0)+v(1,1)*rhs.v(0,1)+v(2,1)*rhs.v(0,2)+v(3,1)*rhs.v(0,3),
							v(0,2)*rhs.v(0,0)+v(1,2)*rhs.v(0,1)+v(2,2)*rhs.v(0,2)+v(3,2)*rhs.v(0,3),
							rhs.v(0,3),
							v(0,0)*rhs.v(1,0)+v(1,0)*rhs.v(1,1)+v(2,0)*rhs.v(1,2)+v(3,0)*rhs.v(1,3),
							v(0,1)*rhs.v(1,0)+v(1,1)*rhs.v(1,1)+v(2,1)*rhs.v(1,2)+v(3,1)*rhs.v(1,3),
							v(0,2)*rhs.v(1,0)+v(1,2)*rhs.v(1,1)+v(2,2)*rhs.v(1,2)+v(3,2)*rhs.v(1,3),
							rhs.v(1,3),
							v(0,0)*rhs.v(2,0)+v(1,0)*rhs.v(2,1)+v(2,0)*rhs.v(2,2)+v(3,0)*rhs.v(2,3),
							v(0,1)*rhs.v(2,0)+v(1,1)*rhs.v(2,1)+v(2,1)*rhs.v(2,2)+v(3,1)*rhs.v(2,3),
							v(0,2)*rhs.v(2,0)+v(1,2)*rhs.v(2,1)+v(2,2)*rhs.v(2,2)+v(3,2)*rhs.v(2,3),
							rhs.v(2,3),
							v(0,0)*rhs.v(3,0)+v(1,0)*rhs.v(3,1)+v(2,0)*rhs.v(3,2)+v(3,0)*rhs.v(3,3),
							v(0,1)*rhs.v(3,0)+v(1,1)*rhs.v(3,1)+v(2,1)*rhs.v(3,2)+v(3,1)*rhs.v(3,3),
							v(0,2)*rhs.v(3,0)+v(1,2)*rhs.v(3,1)+v(2,2)*rhs.v(3,2)+v(3,2)*rhs.v(3,3),
							rhs.v(3,3));
				}

				//Optimise for when bottom row of 2nd matrix is (0, 0, 0, 1)
				if(rhs.v(0,3)==0.0f && rhs.v(1,3)==0.0f && rhs.v(2,3)==0.0f && rhs.v(3,3)==1.0f) {
					return math::mat44<T>(
							v(0,0)*rhs.v(0,0)+v(1,0)*rhs.v(0,1)+v(2,0)*rhs.v(0,2),
							v(0,1)*rhs.v(0,0)+v(1,1)*rhs.v(0,1)+v(2,1)*rhs.v(0,2),
							v(0,2)*rhs.v(0,0)+v(1,2)*rhs.v(0,1)+v(2,2)*rhs.v(0,2),
							v(0,3)*rhs.v(0,0)+v(1,3)*rhs.v(0,1)+v(2,3)*rhs.v(0,2),
							v(0,0)*rhs.v(1,0)+v(1,0)*rhs.v(1,1)+v(2,0)*rhs.v(1,2),
							v(0,1)*rhs.v(1,0)+v(1,1)*rhs.v(1,1)+v(2,1)*rhs.v(1,2),
							v(0,2)*rhs.v(1,0)+v(1,2)*rhs.v(1,1)+v(2,2)*rhs.v(1,2),
							v(0,3)*rhs.v(1,0)+v(1,3)*rhs.v(1,1)+v(2,3)*rhs.v(1,2),
							v(0,0)*rhs.v(2,0)+v(1,0)*rhs.v(2,1)+v(2,0)*rhs.v(2,2),
							v(0,1)*rhs.v(2,0)+v(1,1)*rhs.v(2,1)+v(2,1)*rhs.v(2,2),
							v(0,2)*rhs.v(2,0)+v(1,2)*rhs.v(2,1)+v(2,2)*rhs.v(2,2),
							v(0,3)*rhs.v(2,0)+v(1,3)*rhs.v(2,1)+v(2,3)*rhs.v(2,2),
							v(0,0)*rhs.v(3,0)+v(1,0)*rhs.v(3,1)+v(2,0)*rhs.v(3,2)+v(3,0),
							v(0,1)*rhs.v(3,0)+v(1,1)*rhs.v(3,1)+v(2,1)*rhs.v(3,2)+v(3,1),
							v(0,2)*rhs.v(3,0)+v(1,2)*rhs.v(3,1)+v(2,2)*rhs.v(3,2)+v(3,2),
							v(0,3)*rhs.v(3,0)+v(1,3)*rhs.v(3,1)+v(2,3)*rhs.v(3,2)+v(3,3));
				}	

				return math::mat44<T>(
						v(0,0)*rhs.v(0,0)+v(1,0)*rhs.v(0,1)+v(2,0)*rhs.v(0,2)+v(3,0)*rhs.v(0,3),
						v(0,1)*rhs.v(0,0)+v(1,1)*rhs.v(0,1)+v(2,1)*rhs.v(0,2)+v(3,1)*rhs.v(0,3),
						v(0,2)*rhs.v(0,0)+v(1,2)*rhs.v(0,1)+v(2,2)*rhs.v(0,2)+v(3,2)*rhs.v(0,3),
						v(0,3)*rhs.v(0,0)+v(1,3)*rhs.v(0,1)+v(2,3)*rhs.v(0,2)+v(3,3)*rhs.v(0,3),
						v(0,0)*rhs.v(1,0)+v(1,0)*rhs.v(1,1)+v(2,0)*rhs.v(1,2)+v(3,0)*rhs.v(1,3),
						v(0,1)*rhs.v(1,0)+v(1,1)*rhs.v(1,1)+v(2,1)*rhs.v(1,2)+v(3,1)*rhs.v(1,3),
						v(0,2)*rhs.v(1,0)+v(1,2)*rhs.v(1,1)+v(2,2)*rhs.v(1,2)+v(3,2)*rhs.v(1,3),
						v(0,3)*rhs.v(1,0)+v(1,3)*rhs.v(1,1)+v(2,3)*rhs.v(1,2)+v(3,3)*rhs.v(1,3),
						v(0,0)*rhs.v(2,0)+v(1,0)*rhs.v(2,1)+v(2,0)*rhs.v(2,2)+v(3,0)*rhs.v(2,3),
						v(0,1)*rhs.v(2,0)+v(1,1)*rhs.v(2,1)+v(2,1)*rhs.v(2,2)+v(3,1)*rhs.v(2,3),
						v(0,2)*rhs.v(2,0)+v(1,2)*rhs.v(2,1)+v(2,2)*rhs.v(2,2)+v(3,2)*rhs.v(2,3),
						v(0,3)*rhs.v(2,0)+v(1,3)*rhs.v(2,1)+v(2,3)*rhs.v(2,2)+v(3,3)*rhs.v(2,3),
						v(0,0)*rhs.v(3,0)+v(1,0)*rhs.v(3,1)+v(2,0)*rhs.v(3,2)+v(3,0)*rhs.v(3,3),
						v(0,1)*rhs.v(3,0)+v(1,1)*rhs.v(3,1)+v(2,1)*rhs.v(3,2)+v(3,1)*rhs.v(3,3),
						v(0,2)*rhs.v(3,0)+v(1,2)*rhs.v(3,1)+v(2,2)*rhs.v(3,2)+v(3,2)*rhs.v(3,3),
						v(0,3)*rhs.v(3,0)+v(1,3)*rhs.v(3,1)+v(2,3)*rhs.v(3,2)+v(3,3)*rhs.v(3,3));
			}
			mat44<T> operator*(T const & rhs) const {
				return matsqu<T,4>::operator*(rhs);
			}
			mat44<T> operator/(const T rhs) const
			{
				if (rhs==0.0f || rhs==1.0f)
					return (*this);

				T temp=1/rhs;

				return (*this) * temp;
			}
			bool operator==(const mat44<T> & rhs) const {
				return vecbase<T,16>::operator==(rhs);
			}
			bool operator!=(const mat44<T> & rhs) const {
				return vecbase<T,16>::operator==(rhs);
			}
			void operator+=(const mat44<T> & rhs) {
				(*this)=(*this)+rhs;
			}
			void operator-=(const mat44<T> & rhs) {
				(*this)=(*this)-rhs;
			}
			void operator*=(const mat44<T> & rhs) {
				(*this)=(*this)*rhs;
			}
			void operator*=(const T rhs) {
				(*this)=(*this)*rhs;
			}
			void operator/=(const T rhs) {
				(*this)=(*this)/rhs;
			}
			mat44<T> operator-() const {
				return vecbase<T,16>::operator-();
			}
			math::vec4<T> operator*(const vec4<T> rhs) const
			{
				//Optimise for matrices in which bottom row is (0, 0, 0, 1)
				if(v(0,3)==0.0f && v(1,3)==0.0f && v(2,3)==0.0f && v(3,3)==1.0f)
				{
					return vec4<T>(
							v(0,0)*rhs.x + v(1,0)*rhs.y + v(2,0)*rhs.z + v(3,0)*rhs.w,
							v(0,1)*rhs.x + v(1,1)*rhs.y + v(2,1)*rhs.z + v(3,1)*rhs.w,
							v(0,2)*rhs.x + v(1,2)*rhs.y + v(2,2)*rhs.z + v(3,2)*rhs.w,
							rhs.w);
				}
				return matbase<T,4,4>::operator*(rhs);
				return vec4<T>(
						v(0,0) * rhs.x + v(1,0) * rhs.y + v(2,0) * rhs.z + v(3,0) * rhs.w,
						v(0,1) * rhs.x + v(1,1) * rhs.y + v(2,1) * rhs.z + v(3,1) * rhs.w,
						v(0,2) * rhs.x + v(1,2) * rhs.y + v(2,2) * rhs.z + v(3,2) * rhs.w,
						v(0,3) * rhs.x + v(1,3) * rhs.y + v(2,3) * rhs.z + v(3,3) * rhs.w);

			}
			math::vec3<T>	GetRotatedVector3D(const vec3<T> & rhs) const {
				return vec3<T>(
						matbase<T,4,4>::v(0,0)*rhs.v_[0] + matbase<T,4,4>::v(1,0)*rhs.v_[1] + matbase<T,4,4>::v(2,0) * rhs.v_[2],
						matbase<T,4,4>::v(0,1)*rhs.v_[0] + matbase<T,4,4>::v(1,1)*rhs.v_[1] + matbase<T,4,4>::v(2,1) * rhs.v_[2],
						matbase<T,4,4>::v(0,2)*rhs.v_[0] + matbase<T,4,4>::v(1,2)*rhs.v_[1] + matbase<T,4,4>::v(2,2) * rhs.v_[2]);
			}
			math::vec3<T>	GetInverseRotatedVector3D(const vec3<T> & rhs) const
			{
				//rotate by transpose:
				return vec3<T>(
						matbase<T,4,4>::v(0,0) * rhs.v_[0] + matbase<T,4,4>::v(0,1) * rhs.v_[1] + matbase<T,4,4>::v(0,2) * rhs.v_[2],
						matbase<T,4,4>::v(1,0) * rhs.v_[0] + matbase<T,4,4>::v(1,1) * rhs.v_[1] + matbase<T,4,4>::v(1,2) * rhs.v_[2],
						matbase<T,4,4>::v(2,0) * rhs.v_[0] + matbase<T,4,4>::v(2,1) * rhs.v_[1] + matbase<T,4,4>::v(2,2) * rhs.v_[2]);
			}
			math::vec3<T>	GetTranslatedVector3D(const vec3<T> & rhs) const {

				return vec3<T>(rhs.v_[0] + matbase<T,4,4>::v(3,0), rhs.v_[1]+matbase<T,4,4>::v(3,1), rhs.v_[2] + matbase<T,4,4>::v(3,2));
			}
			math::vec3<T>	GetInverseTranslatedVector3D(const vec3<T> & rhs) const
			{
				return vec3<T>(rhs.v_[0] - matbase<T,4,4>::v(3,0), rhs.v_[1] - matbase<T,4,4>::v(3,1), rhs.v_[2] - matbase<T,4,4>::v(3,2));
			}
			void		Invert(void) {
				*this = getInverse();
			}
			mat44<T>	getInverse(void) const {
				mat44<T> result = getInverseTranspose();

				result.Transpose();

				return result;
			}
			void		Transpose(void)
			{
				*this = getTranspose();
			}
			mat44<T>	getTranspose() const {
				return math::mat44<T>(
						matbase<T,4,4>::v(0,0), matbase<T,4,4>::v(1,0), matbase<T,4,4>::v(2,0), matbase<T,4,4>::v(3,0),
						matbase<T,4,4>::v(0,1), matbase<T,4,4>::v(1,1), matbase<T,4,4>::v(2,1), matbase<T,4,4>::v(3,1),
						matbase<T,4,4>::v(0,2), matbase<T,4,4>::v(1,2), matbase<T,4,4>::v(2,2), matbase<T,4,4>::v(3,2),
						matbase<T,4,4>::v(0,3), matbase<T,4,4>::v(1,3), matbase<T,4,4>::v(2,3), matbase<T,4,4>::v(3,3));
			}
			void		invertTranspose() {
				*this = getInverseTranspose();
			}
			mat44<T>	getInverseTranspose() const {
				mat44<T> result;

				T tmp[12];												//temporary pair storage
				T det;													//determinant

				//calculate pairs for first 8 elements (cofactors)
				tmp[0] = matbase<T,4,4>::v(2,2) * matbase<T,4,4>::v(3,3);
				tmp[1] = matbase<T,4,4>::v(2,3) * matbase<T,4,4>::v(3,2);
				tmp[2] = matbase<T,4,4>::v(2,1) * matbase<T,4,4>::v(3,3);
				tmp[3] = matbase<T,4,4>::v(2,3) * matbase<T,4,4>::v(3,1);
				tmp[4] = matbase<T,4,4>::v(2,1) * matbase<T,4,4>::v(3,2);
				tmp[5] = matbase<T,4,4>::v(2,2) * matbase<T,4,4>::v(3,1);
				tmp[6] = matbase<T,4,4>::v(2,0) * matbase<T,4,4>::v(3,3);
				tmp[7] = matbase<T,4,4>::v(2,3) * matbase<T,4,4>::v(3,0);
				tmp[8] = matbase<T,4,4>::v(2,0) * matbase<T,4,4>::v(3,2);
				tmp[9] = matbase<T,4,4>::v(2,2) * matbase<T,4,4>::v(3,0);
				tmp[10] = matbase<T,4,4>::v(2,0) * matbase<T,4,4>::v(3,1);
				tmp[11] = matbase<T,4,4>::v(2,1) * matbase<T,4,4>::v(3,0);
				
				//calculate first 8 elements (cofactors)
				result.v(0,0) = tmp[0] * v(1,1) + tmp[3] * v(1,2) + tmp[4]*v(1,3) - tmp[1]*v(1,1) - tmp[2]*v(1,2) - tmp[5]*v(1,3);
				result.v(0,1) = tmp[1] * v(1,0) + tmp[6] * v(1,2) + tmp[9]*v(1,3) - tmp[0]*v(1,0) - tmp[7]*v(1,2) - tmp[8]*v(1,3);
				result.v(0,2) = tmp[2] * v(1,0) + tmp[7] * v(1,1) + tmp[10]*v(1,3) - tmp[3]*v(1,0) - tmp[6]*v(1,1) - tmp[11]*v(1,3);
				result.v(0,3) = tmp[5] * v(1,0) + tmp[8] * v(1,1) + tmp[11]*v(1,2) - tmp[4]*v(1,0) - tmp[9]*v(1,1) - tmp[10]*v(1,2);
				result.v(1,0) = tmp[1] * v(0,1) + tmp[2] * v(0,2) + tmp[5]*v(0,3) - tmp[0]*v(0,1) - tmp[3]*v(0,2) - tmp[4]*v(0,3);
				result.v(1,1) = tmp[0] * v(0,0) + tmp[7] * v(0,2) + tmp[8]*v(0,3) - tmp[1]*v(0,0) - tmp[6]*v(0,2) - tmp[9]*v(0,3);
				result.v(1,2) = tmp[3] * v(0,0) + tmp[6] * v(0,1) + tmp[11]*v(0,3) - tmp[2]*v(0,0) - tmp[7]*v(0,1) - tmp[10]*v(0,3);
				result.v(1,3) = tmp[4] * v(0,0) + tmp[9] * v(0,1) + tmp[10]*v(0,2) - tmp[5]*v(0,0) - tmp[8]*v(0,1) - tmp[11]*v(0,2);
				//calculate pairs for second 8 elements (cofactors)
				tmp[0] = matbase<T,4,4>::v(0,2)*matbase<T,4,4>::v(1,3);
				tmp[1] = matbase<T,4,4>::v(0,3)*matbase<T,4,4>::v(1,2);
				tmp[2] = matbase<T,4,4>::v(0,1)*matbase<T,4,4>::v(1,3);
				tmp[3] = matbase<T,4,4>::v(0,3)*matbase<T,4,4>::v(1,1);
				tmp[4] = matbase<T,4,4>::v(0,1)*matbase<T,4,4>::v(1,2);
				tmp[5] = matbase<T,4,4>::v(0,2)*matbase<T,4,4>::v(1,1);
				tmp[6] = matbase<T,4,4>::v(0,0)*matbase<T,4,4>::v(1,3);
				tmp[7] = matbase<T,4,4>::v(0,3)*matbase<T,4,4>::v(1,0);
				tmp[8] = matbase<T,4,4>::v(0,0)*matbase<T,4,4>::v(1,2);
				tmp[9] = matbase<T,4,4>::v(0,2)*matbase<T,4,4>::v(1,0);
				tmp[10] = matbase<T,4,4>::v(0,0)*matbase<T,4,4>::v(1,1);
				tmp[11] = matbase<T,4,4>::v(0,1)*matbase<T,4,4>::v(1,0);

				//calculate second 8 elements (cofactors)
				result.v(2,0) = tmp[0]*v(3,1) + tmp[3]*v(3,2) + tmp[4]*v(3,3)-tmp[1]*v(3,1) - tmp[2]*v(3,2) - tmp[5]*v(3,3);
				result.v(2,1) = tmp[1]*v(3,0) + tmp[6]*v(3,2) + tmp[9]*v(3,3)-tmp[0]*v(3,0) - tmp[7]*v(3,2) - tmp[8]*v(3,3);
				result.v(2,2) = tmp[2]*v(3,0) + tmp[7]*v(3,1) + tmp[10]*v(3,3)-tmp[3]*v(3,0) - tmp[6]*v(3,1) - tmp[11]*v(3,3);
				result.v(2,3) = tmp[5]*v(3,0) + tmp[8]*v(3,1) + tmp[11]*v(3,2)-tmp[4]*v(3,0) - tmp[9]*v(3,1) - tmp[10]*v(3,2);
				result.v(3,0) = tmp[2]*v(2,2) + tmp[5]*v(2,3) + tmp[1]*v(2,1)-tmp[4]*v(2,3) - tmp[0]*v(2,1) - tmp[3]*v(2,2);
				result.v(3,1) = tmp[8]*v(2,3) + tmp[0]*v(2,0) + tmp[7]*v(2,2)-tmp[6]*v(2,2) - tmp[9]*v(2,3) - tmp[1]*v(2,0);
				result.v(3,2) = tmp[6]*v(2,1) + tmp[11]*v(2,3) + tmp[3]*v(2,0)-tmp[10]*v(2,3) - tmp[2]*v(2,0) - tmp[7]*v(2,1);
				result.v(3,3) = tmp[10]*v(2,2) + tmp[4]*v(2,0) + tmp[9]*v(2,1)-tmp[8]*v(2,1) - tmp[11]*v(2,2) - tmp[5]*v(2,0);

				// calculate determinant
				det = matsqu<T,4>::det();
/*
				det =	matbase<T,4,4>::v(0,0)*result.GetEntry(0)
					+matbase<T,4,4>::v(0,1)*result.GetEntry(1)
					+matbase<T,4,4>::v(0,2)*result.GetEntry(2)
					+matbase<T,4,4>::v(0,3)*result.GetEntry(3);
*/
				if(det==0.0f)
				{
					mat44<T> id;
					return id;
				}

				result=result/det;

				return result;
			}
			void		AffineInvert() {
				(*this) = getAffineInverse();
			}
			mat44<T>	getAffineInverse() const {
				//return the transpose of the rotation part
				//and the negative of the inverse rotated translation part
				return math::mat44<T>(
						matbase<T,4,4>::v(0,0),matbase<T,4,4>::v(1,0),matbase<T,4,4>::v(2,0),0.0f,
						matbase<T,4,4>::v(0,1),matbase<T,4,4>::v(1,1),matbase<T,4,4>::v(2,1),0.0f,
						matbase<T,4,4>::v(0,2),matbase<T,4,4>::v(1,2),matbase<T,4,4>::v(2,2),0.0f,
						-(matbase<T,4,4>::v(0,0)*matbase<T,4,4>::v(3,0)+matbase<T,4,4>::v(0,1)*matbase<T,4,4>::v(3,1)+matbase<T,4,4>::v(0,2)*matbase<T,4,4>::v(3,2)),
						-(matbase<T,4,4>::v(1,0)*matbase<T,4,4>::v(3,0)+matbase<T,4,4>::v(1,1)*matbase<T,4,4>::v(3,1)+matbase<T,4,4>::v(1,2)*matbase<T,4,4>::v(3,2)),
						-(matbase<T,4,4>::v(2,0)*matbase<T,4,4>::v(3,0)+matbase<T,4,4>::v(2,1)*matbase<T,4,4>::v(3,1)+matbase<T,4,4>::v(2,2)*matbase<T,4,4>::v(3,2)),
						1.0f);
			}
			void		affineInvertTranspose(void) {
				(*this)=getAffineInverseTranspose();
			}
			mat44<T>	getAffineInverseTranspose(void) const
			{
				//return the transpose of the rotation part
				//and the negative of the inverse rotated translation part
				//transposed
				return math::mat44<T>(
						matbase<T,4,4>::v(0,0),
						matbase<T,4,4>::v(0,1),
						matbase<T,4,4>::v(0,2),
						-(matbase<T,4,4>::v(0,0)*matbase<T,4,4>::v(3,0)+matbase<T,4,4>::v(0,1)*matbase<T,4,4>::v(3,1)+matbase<T,4,4>::v(0,2)*matbase<T,4,4>::v(3,2)),
						matbase<T,4,4>::v(1,0),
						matbase<T,4,4>::v(1,1),
						matbase<T,4,4>::v(1,2),
						-(matbase<T,4,4>::v(1,0)*matbase<T,4,4>::v(3,0)+matbase<T,4,4>::v(1,1)*matbase<T,4,4>::v(3,1)+matbase<T,4,4>::v(1,2)*matbase<T,4,4>::v(3,2)),
						matbase<T,4,4>::v(2,0),
						matbase<T,4,4>::v(2,1),
						matbase<T,4,4>::v(2,2),
						-(matbase<T,4,4>::v(2,0)*matbase<T,4,4>::v(3,0)+matbase<T,4,4>::v(2,1)*matbase<T,4,4>::v(3,1)+matbase<T,4,4>::v(2,2)*matbase<T,4,4>::v(3,2)),
						0.0f, 0.0f, 0.0f, 1.0f);
			}
			void		SetTranslation(const vec3<T> & translation) {
				matsqu<T,4>::loadIdentity();

				SetTranslationPart(translation);
			}
			void		SetScale(const vec3<T> & scaleFactor) {
				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(0,0) = scaleFactor.v_[0];
				matbase<T,4,4>::v(1,1) = scaleFactor.v_[1];
				matbase<T,4,4>::v(2,2) = scaleFactor.v_[2];
			}
			void		SetUniformScale(const T scaleFactor)
			{
				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(0,0)=matbase<T,4,4>::v(1,1)=matbase<T,4,4>::v(2,2)=scaleFactor;
			}
			void		SetRotationAxis(const T angle, const vec3<T> & axis)
			{
				vec3<T> u=axis.GetNormalized();

				T sinAngle=(T)sin(M_PI*angle/180);
				T cosAngle=(T)cos(M_PI*angle/180);
				T oneMinusCosAngle=1.0f-cosAngle;

				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(0,0)=(u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
				matbase<T,4,4>::v(1,0)=(u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
				matbase<T,4,4>::v(2,0)=(u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

				matbase<T,4,4>::v(0,1)=(u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
				matbase<T,4,4>::v(1,1)=(u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
				matbase<T,4,4>::v(2,1)=(u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

				matbase<T,4,4>::v(0,2)=(u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
				matbase<T,4,4>::v(1,2)=(u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
				matbase<T,4,4>::v(2,2)=(u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));
			}
			void		SetRotationX(const T angle)
			{
				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(1,1)=(T)cos(M_PI*angle/180);
				matbase<T,4,4>::v(1,2)=(T)sin(M_PI*angle/180);

				matbase<T,4,4>::v(2,1)=-matbase<T,4,4>::v(1,2);
				matbase<T,4,4>::v(2,2)=matbase<T,4,4>::v(1,1);
			}
			void		SetRotationY(const T angle)
			{
				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(0,0)=(T)cos(M_PI*angle/180);
				matbase<T,4,4>::v(0,2)=-(T)sin(M_PI*angle/180);

				matbase<T,4,4>::v(2,0)=-matbase<T,4,4>::v(0,2);
				matbase<T,4,4>::v(2,2)=matbase<T,4,4>::v(0,0);
			}
			void		SetRotationZ(const T angle)
			{
				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(0,0)=(T)cos(M_PI*angle/180);
				matbase<T,4,4>::v(0,1)=(T)sin(M_PI*angle/180);

				matbase<T,4,4>::v(1,0)=-matbase<T,4,4>::v(0,1);
				matbase<T,4,4>::v(1,1)=matbase<T,4,4>::v(0,0);
			}
			void		SetRotationEuler(const T angleX, const T angleY, const T angleZ)
			{
				matsqu<T,4>::loadIdentity();

				SetRotationPartEuler(angleX, angleY, angleZ);
			}
			void		SetPerspective(T left, T right, T bottom, T top, T n, T f)
			{
				T nudge=0.999f;		//prevent artifacts with infinite far plane

				matbase<T,4,4>::loadZero();

				//check for division by 0
				if(left==right || top==bottom || n==f)
				{
					printf("invalid perspective");
					exit(0);
				}
				matbase<T,4,4>::v(0,0)=(2*n)/(right-left);

				matbase<T,4,4>::v(1,1)=(2*n)/(top-bottom);

				matbase<T,4,4>::v(2,0)=(right+left)/(right-left);
				matbase<T,4,4>::v(2,1)=(top+bottom)/(top-bottom);

				if(f!=-1)
				{
					matbase<T,4,4>::v(2,2)=-(f+n)/(f-n);
				}
				else		//if f==-1, use an infinite far plane
				{
					matbase<T,4,4>::v(2,2)=-nudge;
				}

				matbase<T,4,4>::v(2,3)=-1;

				if(f!=-1)
				{
					matbase<T,4,4>::v(3,2)=-(2*f*n)/(f-n);
				}
				else		//if f==-1, use an infinite far plane
				{
					matbase<T,4,4>::v(3,2)=-2*n*nudge;
				}
			}
			void		SetPerspective(T fovy, T aspect, T n, T f)
			{
				T left, right, top, bottom;

				//convert fov from degrees to radians
				fovy *= (T)M_PI / 180.0f;

				top = n*tanf(fovy/2.0f);
				bottom=-top;

				left=aspect*bottom;
				right=aspect*top;

				SetPerspective(left, right, bottom, top, n, f);
			}
			void		SetOrtho(	T left, T right, T bottom, T top, T n, T f)
			{
				matsqu<T,4>::loadIdentity();

				matbase<T,4,4>::v(0,0)=2.0f/(right-left);

				matbase<T,4,4>::v(1,1)=2.0f/(top-bottom);

				matbase<T,4,4>::v(2,2)=-2.0f/(f-n);

				matbase<T,4,4>::v(3,0)=-(right+left)/(right-left);
				matbase<T,4,4>::v(3,1)=-(top+bottom)/(top-bottom);
				matbase<T,4,4>::v(3,2)=-(f+n)/(f-n);
			}
			void		SetTranslationPart(const vec3<T> & translation) {
				matbase<T,4,4>::v(3,0) = translation.v_[0];
				matbase<T,4,4>::v(3,1) = translation.v_[1];
				matbase<T,4,4>::v(3,2) = translation.v_[2];
			}
			void		SetRotationPartEuler(const T angleX, const T angleY, const T angleZ) {
				T cr = cos( M_PI*angleX/180 );
				T sr = sin( M_PI*angleX/180 );
				T cp = cos( M_PI*angleY/180 );
				T sp = sin( M_PI*angleY/180 );
				T cy = cos( M_PI*angleZ/180 );
				T sy = sin( M_PI*angleZ/180 );

				matbase<T,4,4>::v(0,0) = ( T )( cp*cy );
				matbase<T,4,4>::v(0,1) = ( T )( cp*sy );
				matbase<T,4,4>::v(0,2) = ( T )( -sp );

				T srsp = sr*sp;
				T crsp = cr*sp;

				matbase<T,4,4>::v(1,0) = ( T )( srsp*cy-cr*sy );
				matbase<T,4,4>::v(1,1) = ( T )( srsp*sy+cr*cy );
				matbase<T,4,4>::v(1,2) = ( T )( sr*cp );

				matbase<T,4,4>::v(2,0) = ( T )( crsp*cy+sr*sy );
				matbase<T,4,4>::v(2,1) = ( T )( crsp*sy-sr*cy );
				matbase<T,4,4>::v(2,2) = ( T )( cr*cp );
			}
			void		RotateVector3D(math::vec3<T> & rhs) const {
				rhs=GetRotatedVector3D(rhs);
			}
			void		InverseRotateVector3D(math::vec3<T> & rhs) const
			{
				rhs=GetInverseRotatedVector3D(rhs);
			}
			void		TranslateVector3D(vec3<T> & rhs) const
			{
				rhs=GetTranslatedVector3D(rhs);
			}
			void		InverseTranslateVector3D(vec3<T> & rhs) const
			{
				rhs=GetInverseTranslatedVector3D(rhs);
			}
			void		SetRotationPartEuler(const math::vec3<T> & rotations)
			{
				SetRotationPartEuler((T)rotations.v[0], (T)rotations.v[1], (T)rotations.v[2]);
			}
			mat44<T>	lookat(math::vec3<T> eye, math::vec3<T> center, math::vec3<T> up) {
				vec3<T> F = center - eye;
				vec3<T> f = F.GetNormalized();

				vec3<T> UP = up.GetNormalized();

				vec3<T> s = f.cross(UP);
				s.Normalize();

				vec3<T> u = s.cross(f);

				//printf("u\n");
				//u.print();

				mat44<T> M(
						s.v_[0],  u.v_[0],  -f.v_[0] , 0.0f,
						s.v_[1],  u.v_[1],  -f.v_[1] , 0.0f,
						s.v_[2],  u.v_[2],  -f.v_[2] , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

				//	M.print();

				mat44<T> t;
				t.SetTranslation(-eye);

				//printf("M\n");
				//M.print();
				//printf("T\n");
				//T.print();

				//return T*M;
				return M*t;
			}
			void	SetReflection(math::plane<T> const & p)
			{
				math::vec3<T> n = p.n.GetNormalized();

				mat44<T> A;
				A.SetTranslation(n * -p.d);

				mat44<T> I;

				mat44<T> RA = I - math::vec4<T>(n,0) * math::vec4<T>(n,0) * 2.0;

				//*this = A * RA * A.GetInverse();
				*this = A.GetInverse() * RA * A;
			}
			void	SetCoordinateTransform(math::vec3<T> const x, math::vec3<T> const y) {


				math::vec3<T> Z = x.cross(y);

				math::vec3<T> X = y.cross(Z);

				X.Normalize();
				math::vec3<T> Y = y.GetNormalized();
				Z.Normalize();

				mat44<T> m(
						X.v[0],  Y.v[0],  Z.v[0] , 0.0f,
						X.v[1],  Y.v[1],  Z.v[1] , 0.0f,
						X.v[2],  Y.v[2],  Z.v[2] , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

				*this = m;
			}







						~mat44() {}	//empty


			//unary operators
			mat44	operator+(void) const {return (*this);}


			//cast to pointer to a (T *) for glGetFloatv etc
			operator T* () const {return (T*) this;}
			operator const T* () const {return (const T*) this;}

			//member variables
			//T matbase<T,4,4>::v(16];
	};

	//mat44	perspective(T fovy, T aspect, T zn, T zf);
	//mat44	lookat(math::vec3<T> eye, math::vec3<T> center, math::vec3<T> up);

}

#endif	//mat44_H
