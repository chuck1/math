#ifndef __MAT33_H__
#define __MAT33_H__

#include <math/config.hpp>
#include <math/vecbase.hpp>

namespace math {
	template<typename T> class mat33: public math::matsqu<T,3> {
		public:
			//friend mat33 operator*(T scaleFactor, const mat33 & rhs);

			mat33(T e0, T e1, T e2, T e3, T e4, T e5, T e6, T e7, T e8) {
				matsqu<T,3>::v(0,0)=e0;
				matsqu<T,3>::v(0,1)=e1;
				matsqu<T,3>::v(0,2)=e2;
				matsqu<T,3>::v(1,0)=e3;
				matsqu<T,3>::v(1,1)=e4;
				matsqu<T,3>::v(1,2)=e5;
				matsqu<T,3>::v(2,0)=e6;
				matsqu<T,3>::v(2,1)=e7;
				matsqu<T,3>::v(2,2)=e8;
			}
			mat33(math::mat33<T> const & rhs): math::matsqu<T,3>(rhs) {}
			mat33(const T * rhs): math::matsqu<T,3>(rhs) {}
			mat33(vec3<T> const & rhs) {
				loadIdentity();
				matsqu<T,3>::v(0,0) = rhs.v_[0];
				matsqu<T,3>::v(1,1) = rhs.v_[1];
				matsqu<T,3>::v(2,2) = rhs.v_[2];
			}
			void		setDiagonal(T x, T y, T z) {
				matsqu<T,3>::loadZero();
				matsqu<T,3>::v(0,0) = x;
				matsqu<T,3>::v(1,1) = y;
				matsqu<T,3>::v(2,2) = z;
			}
			void		setRotation(math::quat<T> const & q) {
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

				matsqu<T,3>::v(0,0) = 1.0f - yy - zz;
				matsqu<T,3>::v(0,1) = xy + zw;
				matsqu<T,3>::v(0,2) = xz - yw;

				matsqu<T,3>::v(1,0) = xy - zw;
				matsqu<T,3>::v(1,1) = 1.0f - xx - zz;
				matsqu<T,3>::v(1,2) = yz + xw;

				matsqu<T,3>::v(2,0) = xz + yw;
				matsqu<T,3>::v(2,1) = yz - xw;
				matsqu<T,3>::v(2,2) = 1.0f - xx - yy;
			}
			math::vec3<T>		getRow(int position) const {
				math::vec3<T> ret(matsqu<T,3>::getRow());
				return ret;
			}
			math::vec3<T>		getColumn(int position) const {
				math::vec3<T> ret(matsqu<T,3>::getColumn());
				return ret;
			}
			void		loadIdentity() {
				matsqu<T,3>::loadZero();
				matsqu<T,3>::v(0,0) = 1.0;
				matsqu<T,3>::v(1,1) = 1.0;
				matsqu<T,3>::v(2,2) = 1.0;
			}
			/** @name Binary Operators @{ */
			math::mat33<T>		operator+(math::mat33<T> const & rhs) const {
				return matbase<T,3,3>::operator+(rhs);
			}
			math::mat33<T>		operator-(math::mat33<T> const & rhs) const {
				return matbase<T,3,3>::operator-(rhs);
			}
			math::mat33<T>		operator*(math::mat33<T> const & rhs) const {
				return math::matbase<T,3,3>::operator*(rhs);
			}
			math::vec3<T>		operator*(math::vec3<T> const & rhs) const {
				return math::matbase<T,3,3>::operator*(rhs);
			}
			math::mat33<T>		operator*(T const & rhs) const {
				return vecbase<T,9>::operator*(rhs);
			}
			math::mat33<T>		operator/(T const & rhs) const {
				if (rhs==0.0f || rhs==1.0f)
					return (*this);

				T temp=1/rhs;

				return (*this)*temp;
			}
			/** @} */
			bool			operator==(math::mat33<T> const & rhs) const {
				return math::vecbase<T,9>::operator==(rhs);
			}
			bool			operator!=(const math::mat33<T> & rhs) const {
				return math::vecbase<T,9>::operator!=(rhs);
			}
			void			operator+=(const math::mat33<T> & rhs) {
				math::matsqu<T,3>::operator+=(rhs);
			}
			void			operator-=(const math::mat33<T> & rhs) {
				math::matsqu<T,3>::operator-=(rhs);
			}
			void		operator*=(const math::mat33<T> & rhs) {
				(*this) = (*this) * rhs;
			}
			/** @name Unary Operators @{ */
			math::mat33<T>&		operator-() {
				matsqu<T,3>::operator-();
				return *this;
			}
			/** @} */

			math::vec3<T>		getRotatedVector3D(const vec3<T> & rhs) const
			{
				return operator*(rhs);
//						v(0]*rhs.v[0] + v[4]*rhs.v[1] + v[8]*rhs.v[2],
//						v(1]*rhs.v[0] + v[5]*rhs.v[1] + v[9]*rhs.v[2],
//						v(2]*rhs.v[0] + v[6]*rhs.v[1] + v[10]*rhs.v[2]);
			}
			math::vec3<T>		getInverseRotatedVector3D(const vec3<T> & rhs) const
			{
				//rotate .v[1] transpose:
				return getTranspose() * rhs;
			}
			void			invert() {
				*this = getInverse();
			}
			math::mat33<T>		getInverse() const {
				math::mat33<T> result = getInverseTranspose();

				result.Transpose();

				return result;
			}
			void			transpose() {
				*this = getTranspose();
			}
			math::mat33<T>		getTranspose(void) const {
				return math::mat33<T>(
						vecbase<T,9>::v[0], vecbase<T,9>::v[3], vecbase<T,9>::v[6],
						vecbase<T,9>::v[1], vecbase<T,9>::v[4], vecbase<T,9>::v[7],
						vecbase<T,9>::v[2], vecbase<T,9>::v[5], vecbase<T,9>::v[8]);
			}
			void			invertTranspose(void) {
				*this = getInverseTranspose();
			}
			math::mat33<T>		getInverseTranspose(void) const {
				math::mat33<T> result;
				/*
				T tmp[12];												//temporary pair storage
				T det;													//determinant

				//calculate pairs for first 8 elements (cofactors)
				tmp[0] = v[10] * v[15];
				tmp[1] = v[11] * v[14];
				tmp[2] = v[9] * v[15];
				tmp[3] = v[11] * v[13];
				tmp[4] = v[9] * v[14];
				tmp[5] = v[10] * v[13];
				tmp[6] = v[8] * v[15];
				tmp[7] = v[11] * v[12];
				tmp[8] = v[8] * v[14];
				tmp[9] = v[10] * v[12];
				tmp[10] = v[8] * v[13];
				tmp[11] = v[9] * v[12];

				//calculate first 8 elements (cofactors)
				result.SetEntry(0,		tmp[0]*v[5] + tmp[3]*v[6] + tmp[4]*v[7]
						-	tmp[1]*v[5] - tmp[2]*v[6] - tmp[5]*v[7]);

				result.SetEntry(1,		tmp[1]*v[4] + tmp[6]*v[6] + tmp[9]*v[7]
						-	tmp[0]*v[4] - tmp[7]*v[6] - tmp[8]*v[7]);

				result.SetEntry(2,		tmp[2]*v[4] + tmp[7]*v[5] + tmp[10]*v[7]
						-	tmp[3]*v[4] - tmp[6]*v[5] - tmp[11]*v[7]);

				result.SetEntry(3,		tmp[5]*v[4] + tmp[8]*v[5] + tmp[11]*v[6]
						-	tmp[4]*v[4] - tmp[9]*v[5] - tmp[10]*v[6]);

				result.SetEntry(4,		tmp[1]*v[1] + tmp[2]*v[2] + tmp[5]*v[3]
						-	tmp[0]*v[1] - tmp[3]*v[2] - tmp[4]*v[3]);

				result.SetEntry(5,		tmp[0]*v[0] + tmp[7]*v[2] + tmp[8]*v[3]
						-	tmp[1]*v[0] - tmp[6]*v[2] - tmp[9]*v[3]);

				result.SetEntry(6,		tmp[3]*v[0] + tmp[6]*v[1] + tmp[11]*v[3]
						-	tmp[2]*v[0] - tmp[7]*v[1] - tmp[10]*v[3]);

				result.SetEntry(7,		tmp[4]*v[0] + tmp[9]*v[1] + tmp[10]*v[2]
						-	tmp[5]*v[0] - tmp[8]*v[1] - tmp[11]*v[2]);

				//calculate pairs for second 8 elements (cofactors)
				tmp[0] = v[2]*v[7];
				tmp[1] = v[3]*v[6];
				tmp[2] = v[1]*v[7];
				tmp[3] = v[3]*v[5];
				tmp[4] = v[1]*v[6];
				tmp[5] = v[2]*v[5];
				tmp[6] = v[0]*v[7];
				tmp[7] = v[3]*v[4];
				tmp[8] = v[0]*v[6];
				tmp[9] = v[2]*v[4];
				tmp[10] = v[0]*v[5];
				tmp[11] = v[1]*v[4];

				//calculate second 8 elements (cofactors)
				result.SetEntry(8,		tmp[0]*v[13] + tmp[3]*v[14] + tmp[4]*v[15]
						-	tmp[1]*v[13] - tmp[2]*v[14] - tmp[5]*v[15]);

				result.SetEntry(9,		tmp[1]*v[12] + tmp[6]*v[14] + tmp[9]*v[15]
						-	tmp[0]*v[12] - tmp[7]*v[14] - tmp[8]*v[15]);

				result.SetEntry(10,		tmp[2]*v[12] + tmp[7]*v[13] + tmp[10]*v[15]
						-	tmp[3]*v[12] - tmp[6]*v[13] - tmp[11]*v[15]);

				result.SetEntry(11,		tmp[5]*v[12] + tmp[8]*v[13] + tmp[11]*v[14]
						-	tmp[4]*v[12] - tmp[9]*v[13] - tmp[10]*v[14]);

				result.SetEntry(12,		tmp[2]*v[10] + tmp[5]*v[11] + tmp[1]*v[9]
						-	tmp[4]*v[11] - tmp[0]*v[9] - tmp[3]*v[10]);

				result.SetEntry(13,		tmp[8]*v[11] + tmp[0]*v[8] + tmp[7]*v[10]
						-	tmp[6]*v[10] - tmp[9]*v[11] - tmp[1]*v[8]);

				result.SetEntry(14,		tmp[6]*v[9] + tmp[11]*v[11] + tmp[3]*v[8]
						-	tmp[10]*v[11] - tmp[2]*v[8] - tmp[7]*v[9]);

				result.SetEntry(15,		tmp[10]*v[10] + tmp[4]*v[8] + tmp[9]*v[9]
						-	tmp[8]*v[9] - tmp[11]*v[10] - tmp[5]*v[8]);

				// calculate determinant
				det	=	 v[0]*result.GetEntry(0)
					+v[1]*result.GetEntry(1)
					+v[2]*result.GetEntry(2)
					+v[3]*result.GetEntry(3);

				if(det==0.0f)
				{
					math::mat33 id;
					return id;
				}

				result=result/det;
				*/
				return result;
			}
			void		setRotationAxis(const T angle, const vec3<T> & axis) {
				vec3<T> u=axis.GetNormalized();

				T sinAngle=(T)sin(M_PI*angle/180);
				T cosAngle=(T)cos(M_PI*angle/180);
				T oneMinusCosAngle=1.0f-cosAngle;

				loadIdentity();

				vecbase<T,9>::v[0]  = (u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
				vecbase<T,9>::v[4]  = (u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
				vecbase<T,9>::v[8]  = (u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

				vecbase<T,9>::v[1]  = (u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
				vecbase<T,9>::v[5]  = (u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
				vecbase<T,9>::v[9]  = (u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

				vecbase<T,9>::v[2]  = (u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
				vecbase<T,9>::v[6]  = (u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
				vecbase<T,9>::v[10] = (u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));
			}
			void		setRotationX(const T angle) {
				loadIdentity();

				vecbase<T,9>::v[4] = (T)cos(M_PI*angle/180);
				vecbase<T,9>::v[5] = (T)sin(M_PI*angle/180);

				vecbase<T,9>::v[6] = -vecbase<T,9>::v[6];
				vecbase<T,9>::v[7]= vecbase<T,9>::v[5];
			}
			void		setRotationY(const T angle) {
				loadIdentity();

				vecbase<T,9>::v[0]=(T)cos(M_PI*angle/180);
				vecbase<T,9>::v[2]=-(T)sin(M_PI*angle/180);

				vecbase<T,9>::v[6]=-vecbase<T,9>::v[2];
				vecbase<T,9>::v[8]=vecbase<T,9>::v[0];
			}
			void		setRotationZ(const T angle) {
				loadIdentity();

				vecbase<T,9>::v[0]=(T)cos(M_PI*angle/180);
				vecbase<T,9>::v[1]=(T)sin(M_PI*angle/180);

				vecbase<T,9>::v[3]=-vecbase<T,9>::v[1];
				vecbase<T,9>::v[4]=vecbase<T,9>::v[0];
			}
			void		setRotationEuler(const T angleX, const T angleY, const T angleZ) {
				T cr = cos( M_PI*angleX/180 );
				T sr = sin( M_PI*angleX/180 );
				T cp = cos( M_PI*angleY/180 );
				T sp = sin( M_PI*angleY/180 );
				T cy = cos( M_PI*angleZ/180 );
				T sy = sin( M_PI*angleZ/180 );

				vecbase<T,9>::v[0] = ( T )( cp*cy );
				vecbase<T,9>::v[1] = ( T )( cp*sy );
				vecbase<T,9>::v[2] = ( T )( -sp );

				T srsp = sr*sp;
				T crsp = cr*sp;

				vecbase<T,9>::v[3] = ( T )( srsp*cy-cr*sy );
				vecbase<T,9>::v[4] = ( T )( srsp*sy+cr*cy );
				vecbase<T,9>::v[5] = ( T )( sr*cp );

				vecbase<T,9>::v[6] = ( T )( crsp*cy+sr*sy );
				vecbase<T,9>::v[7] = ( T )( crsp*sy-sr*cy );
				vecbase<T,9>::v[8] = ( T )( cr*cp );
			}
			void		rotateVector3D(math::vec3<T> & rhs) const {
				rhs = GetRotatedVector3D(rhs);
			}
			void		inverseRotateVector3D(math::vec3<T> & rhs) const
			{
				rhs=GetInverseRotatedVector3D(rhs);
			}


			~mat33() {}

			//cast to pointer to a (T *) for glGetFloatv etc
			operator T* () const {return (T*) this;}
			operator const T* () const {return (const T*) this;}

			//member variables

	};
}

#endif	//mat44_H
