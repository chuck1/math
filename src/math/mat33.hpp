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
				matsqu<T,3>::v(0,0) = rhs.v[0];
				matsqu<T,3>::v(1,1) = rhs.v[1];
				matsqu<T,3>::v(2,2) = rhs.v[2];
			}
			void		setDiagonal(T x, T y, T z) {
				loadZero();
				v(0,0) = x;
				v(1,1) = y;
				v(2,2) = z;
			}
			void		setRotation(math::quat<T> const & q)
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

				v[0] = 1.0f - yy - zz;
				v[1] = xy + zw;
				v[2] = xz - yw;

				v[3] = xy - zw;
				v[4] = 1.0f - xx - zz;
				v[5] = yz + xw;

				v[6] = xz + yw;
				v[7] = yz - xw;
				v[8] = 1.0f - xx - yy;
			}
			void		setEntry(int position, T value) {
				if(position>=0 && position<=15)
					v[position]=value;
			}
			T		getEntry(int position) const {
				if(position>=0 && position<=15)
					return v[position];

				return 0.0f;
			}
			math::vec4<T>	getRow(int position) const
			{
				if(position==0)
					return vec4(v[0], v[4], v[8], v[12]);

				if(position==1)
					return vec4(v[1], v[5], v[9], v[13]);

				if(position==2)
					return vec4(v[2], v[6], v[10], v[14]);

				if(position==3)
					return vec4(v[3], v[7], v[11], v[15]);

				return vec4(0.0f, 0.0f, 0.0f, 0.0f);
			}
			math::vec4<T>	getColumn(int position) const {
				if(position==0)
					return vec4(v[0], v[1], v[2], v[3]);

				if(position==1)
					return vec4(v[4], v[5], v[6], v[7]);

				if(position==2)
					return vec4(v[8], v[9], v[10], v[11]);

				if(position==3)
					return vec4(v[12], v[13], v[14], v[15]);

				return vec4(0.0f, 0.0f, 0.0f, 0.0f);
			}
			void		loadIdentity(void)
			{
				memset(v, 0, 9*sizeof(T));
				v[0]=1.0f;
				v[4]=1.0f;
				v[8]=1.0f;
			}
			void		loadZero(void)
			{
				memset(v, 0, 9*sizeof(T));
			}

			math::mat33<T>		operator+(math::mat33<T> const & rhs) const {
				math::mat33 m;
				for(int i = 0; i < 9; ++i) m.v[i] = v[i] + rhs.v[i];
				return m;
			}
			math::mat33<T>		operator-(math::mat33<T> const & rhs) const {
				math::mat33 m;
				for(int i = 0; i < 9; ++i) m.v[i] = v[i] - rhs.v[i];
				return m;
			}
			math::mat33<T>		operator*(math::mat33<T> const & rhs) const {
				return math::mat33(
						v[0]*rhs.v[0] + v[3] * rhs.v[1] + v[6] * rhs.v[2],
						v[1]*rhs.v[0] + v[4] * rhs.v[1] + v[7] * rhs.v[2],
						v[2]*rhs.v[0] + v[5] * rhs.v[1] + v[8] * rhs.v[2],
						v[0]*rhs.v[3] + v[3] * rhs.v[4] + v[6] * rhs.v[5],
						v[1]*rhs.v[3] + v[4] * rhs.v[4] + v[7] * rhs.v[5],
						v[2]*rhs.v[3] + v[5] * rhs.v[4] + v[8] * rhs.v[5],
						v[0]*rhs.v[6] + v[3] * rhs.v[7] + v[6] * rhs.v[8],
						v[1]*rhs.v[6] + v[4] * rhs.v[7] + v[7] * rhs.v[8],
						v[2]*rhs.v[6] + v[5] * rhs.v[7] + v[8] * rhs.v[8]);
			}
			math::mat33<T>		operator*(const T rhs) const {
				math::mat33 m;
				for(int i = 0; i < 9; ++i) m.v[i] = v[i]*rhs;

				return math::mat33(
						v[0]*rhs,
						v[1]*rhs,
						v[2]*rhs,
						v[3]*rhs,
						v[4]*rhs,
						v[5]*rhs,
						v[6]*rhs,
						v[7]*rhs,
						v[8]*rhs);
			}
			math::mat33<T>		operator/(const T rhs) const {
				if (rhs==0.0f || rhs==1.0f)
					return (*this);

				T temp=1/rhs;

				return (*this)*temp;
			}
			bool			operator==(math::mat33<T> const & rhs) const {
				for(int i=0; i<16; i++)
				{
					if(v[i]!=rhs.v[i])
						return false;
				}
				return true;
			}
			bool		operator!=(const math::mat33<T> & rhs) const {
				return math::matsqu<T,3>operator!=(rhs);
			}
			void		operator+=(const math::mat33<T> & rhs) {
				math::matsqu<T,3>operator+=(rhs);
			}
			void		operator-=(const math::mat33<T> & rhs)
			{
				math::matsqu<T,3>operator-=(rhs);
			}
			void		operator*=(const math::mat33<T> & rhs) {
				(*this) = (*this) * rhs;
			}
			math::vec3<T>		operator*(const vec3<T> rhs) const {
				return math::matsqu<T,3>::operator*(rhs);
			}


			math::vec3<T>		getRotatedVector3D(const vec3<T> & rhs) const
			{
				return vec3<T>(
						v[0]*rhs.v[0] + v[4]*rhs.v[1] + v[8]*rhs.v[2],
						v[1]*rhs.v[0] + v[5]*rhs.v[1] + v[9]*rhs.v[2],
						v[2]*rhs.v[0] + v[6]*rhs.v[1] + v[10]*rhs.v[2]);
			}
			math::vec3<T>		getInverseRotatedVector3D(const vec3<T> & rhs) const
			{
				//rotate .v[1] transpose:
				return vec3<T>(v[0]*rhs.v[0] + v[1]*rhs.v[1] + v[2]*rhs.v[2],
						v[4]*rhs.v[0] + v[5]*rhs.v[1] + v[6]*rhs.v[2],
						v[8]*rhs.v[0] + v[9]*rhs.v[1] + v[10]*rhs.v[2]);
			}
			void			invert() {
				*this = getInverse();
			}
			math::mat33<T>		getInverse() const {
				math::mat33 result=GetInverseTranspose();

				result.Transpose();

				return result;
			}
			void			transpose() {
				*this = getTranspose();
			}
			math::mat33<T>		getTranspose(void) const {
				return math::mat33(
						v[ 0], v[ 3], v[6],
						v[ 1], v[ 4], v[7],
						v[ 2], v[ 5], v[8]);
			}
			void			invertTranspose(void) {
				*this=GetInverseTranspose();
			}
			math::mat33<T>		getInverseTranspose(void) const {
				math::mat33 result;

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

				return result;
			}
			void		setScale(const vec3<T> & scaleFactor) {
				LoadIdentity();

				v[0]  = scaleFactor.v[0];
				v[5]  = scaleFactor.v[1];
				v[10] = scaleFactor.v[2];
			}
			void		setUniformScale(const T scaleFactor) {
				LoadIdentity();

				v[0]=v[5]=v[10]=scaleFactor;
			}
			void		setRotationAxis(const T angle, const vec3<T> & axis) {
				vec3<T> u=axis.GetNormalized();

				T sinAngle=(T)sin(M_PI*angle/180);
				T cosAngle=(T)cos(M_PI*angle/180);
				T oneMinusCosAngle=1.0f-cosAngle;

				LoadIdentity();

				v[0]  = (u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
				v[4]  = (u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
				v[8]  = (u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

				v[1]  = (u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
				v[5]  = (u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
				v[9]  = (u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

				v[2]  = (u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
				v[6]  = (u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
				v[10] = (u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));
			}
			void		setRotationX(const T angle) {
				LoadIdentity();

				v[5]=(T)cos(M_PI*angle/180);
				v[6]=(T)sin(M_PI*angle/180);

				v[9]=-v[6];
				v[10]=v[5];
			}
			void		setRotationY(const T angle) {
				LoadIdentity();

				v[0]=(T)cos(M_PI*angle/180);
				v[2]=-(T)sin(M_PI*angle/180);

				v[8]=-v[2];
				v[10]=v[0];
			}
			void		setRotationZ(const T angle) {
				LoadIdentity();

				v[0]=(T)cos(M_PI*angle/180);
				v[1]=(T)sin(M_PI*angle/180);

				v[4]=-v[1];
				v[5]=v[0];
			}
			void		setRotationEuler(const T angleX, const T angleY, const T angleZ) {
				T cr = cos( M_PI*angleX/180 );
				T sr = sin( M_PI*angleX/180 );
				T cp = cos( M_PI*angleY/180 );
				T sp = sin( M_PI*angleY/180 );
				T cy = cos( M_PI*angleZ/180 );
				T sy = sin( M_PI*angleZ/180 );

				v[0] = ( T )( cp*cy );
				v[1] = ( T )( cp*sy );
				v[2] = ( T )( -sp );

				T srsp = sr*sp;
				T crsp = cr*sp;

				v[4] = ( T )( srsp*cy-cr*sy );
				v[5] = ( T )( srsp*sy+cr*cy );
				v[6] = ( T )( sr*cp );

				v[8] = ( T )( crsp*cy+sr*sy );
				v[9] = ( T )( crsp*sy-sr*cy );
				v[10] = ( T )( cr*cp );
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
