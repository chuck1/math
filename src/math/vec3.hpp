#ifndef vec3_H
#define vec3_H

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif


#include <math/math.h>
#include <math/vecbase.h>

namespace math {
	template <typename T> class vec3: public math::vecbase<T,3> {
		public:
			/** @name constructors
			 * @{
			 */
			vec3() { vecbase<T,3>::LoadZero(); }
			vec3(math::vec3<T> const & rhs): math::vecbase<double,3>(rhs) {}
			vec3(double const & nx, double const & ny, double const & nz) {
				vecbase<T,3>::v[0] = nx;
				vecbase<T,3>::v[1] = ny;
				vecbase<T,3>::v[2] = nz;
			}
			vec3(double const * const v): math::vecbase<double,3>(v) {}

#ifdef PHYSX
			vec3(physx::PxVec3 const & rhs);
#endif
			/** @} */

			~vec3() {}	//empty

			/** @name accessors
			 * @{
			 */
			/***/
			T&		x() { return math::vecbase<T,3>::v[0]; }
			/***/
			T&		y() { return math::vecbase<T,3>::v[1]; }
			/***/
			T&		z() { return math::vecbase<T,3>::v[2]; }
			/***/
			T const &	x() const { return math::vecbase<T,3>::v[0]; }
			/***/
			T const &	y() const { return math::vecbase<T,3>::v[1]; }
			/***/
			T const &	z() const { return math::vecbase<T,3>::v[2]; }

			/**@}*/

			//vector algebra
			T	dot(math::vec3<T> const & rhs) const {
				return vecbase<T,3>::dot(rhs);
			}
			math::vec3<T>	cross(const vec3<T> & rhs) const {
				return vec3<T>(y()*rhs.z() - z()*rhs.y(), z()*rhs.x() - x()*rhs.z(), x()*rhs.y() - y()*rhs.x());
			}
			T		angle(vec3<T> const & rhs) const {
				
				math::vec3<T> v = cross(rhs);
				
				return acos( v.magnitude() / vecbase<T,3>::magnitude() / rhs.magnitude() );
			}
			math::vec3<T> GetNormalized() const {

				vec3<T> result(*this);

				result.Normalize();

				return result;
			}
			//rotations
			/*
			   void		RotateX(T angle);
			   void		RotateY(T angle);
			   void		RotateZ(T angle);
			   void		RotateAxis(T angle, const vec3<T> & axis);
			   vec3<T>		GetRotatedX(T angle) const;
			   vec3<T>		GetRotatedY(T angle) const;
			   vec3<T>		GetRotatedZ(T angle) const;
			   vec3<T>		GetRotatedAxis(T angle, const vec3<T> & axis) const;
			   */
			math::vec3<T> GetRotatedX(T angle) const {

				if(angle==0.0) return (*this);

				float sinAngle=(float)sin(M_PI*angle/180);
				float cosAngle=(float)cos(M_PI*angle/180);

				return vec3<T>(	x(),
						y()*cosAngle - z()*sinAngle,
						y()*sinAngle + z()*cosAngle);
			}
			void RotateX(T angle) {
				(*this)=GetRotatedX(angle);
			}
			math::vec3<T> GetRotatedY(double angle) const {

				if(angle==0.0) return (*this);

				float sinAngle=(float)sin(M_PI*angle/180);
				float cosAngle=(float)cos(M_PI*angle/180);

				return math::vec3<T>(
						x()*cosAngle + z()*sinAngle,
						y(),
						-x()*sinAngle + z()*cosAngle);
			}
			void RotateY(double angle) {

				(*this)=GetRotatedY(angle);
			}
			math::vec3<T> GetRotatedZ(double angle) const {

				if(angle==0.0) return (*this);

				float sinAngle=(float)sin(M_PI*angle/180);
				float cosAngle=(float)cos(M_PI*angle/180);

				return math::vec3<T>(
						x()*cosAngle - y()*sinAngle,
						x()*sinAngle + y()*cosAngle,
						z());
			}
			void RotateZ(double angle) {

				(*this)=GetRotatedZ(angle);
			}
			math::vec3<T> GetRotatedAxis(double angle, const math::vec3<T> & axis) const {

				if(angle==0.0) return (*this);

				math::vec3<T> u = axis.GetNormalized();

				math::vec3<T> rotMatrixRow0, rotMatrixRow1, rotMatrixRow2;

				float sinAngle=(float)sin(M_PI*angle/180);
				float cosAngle=(float)cos(M_PI*angle/180);
				float oneMinusCosAngle=1.0f-cosAngle;

				rotMatrixRow0.v[0]=(u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
				rotMatrixRow0.v[1]=(u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
				rotMatrixRow0.v[2]=(u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

				rotMatrixRow1.v[0]=(u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
				rotMatrixRow1.v[1]=(u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
				rotMatrixRow1.v[2]=(u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

				rotMatrixRow2.v[0]=(u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
				rotMatrixRow2.v[1]=(u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
				rotMatrixRow2.v[2]=(u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));

				return math::vec3<T>( dot(rotMatrixRow0), dot(rotMatrixRow1), dot(rotMatrixRow2));
			}
			//pack to [0,1] for color
			void		PackTo01() {
				vecbase<T,3>::Normalize();
				
				operator*=(0.5f);
				operator+=(math::vec3<T>(0.5f, 0.5f, 0.5f));
				
			}
			math::vec3<T>	GetPackedTo01() const {
				
				math::vec3<T> temp(*this);

				temp.packTo01();


				return temp;
			}
			//linear interpolate
			vec3<T>		lerp(const vec3<T> & v2, T factor) const
			{
				return (*this)*(1.0f-factor) + v2*factor;
			}
			vec3<T>		QuadraticInterpolate(
					const vec3<T> & v2,
					const vec3<T> & v3,
					T factor) const
			{
				return (*this)*(1.0f-factor)*(1.0f-factor)+
					v2 * 2 * factor*(1.0f-factor)+
					v3 * factor * factor;
			}

			/** @name binary operators
			 * @{
			 */
			vec3<T>		operator+(const vec3<T> & rhs) const
			{
				vec3<T> a(*this);
				a += rhs;
				return a;
			}
			vec3<T>		operator-(const vec3<T> & rhs) const {
				vec3<T> a(*this);
				a -= rhs;
				return a;
			}
			vec3<T>		operator*(const double rhs) const {
				vec3<T> a(*this);
				a *= rhs;
				return a;
			}
			vec3<T>		operator/(const double rhs) const {
				vec3<T> a(*this);
				a /= rhs;
				return a;
			}
			/** @} */

			// friend vec3<T> operator*(T scaleFactor, const vec3<T> & rhs);


			
			/** @name self operators
			 * @{
			 */
			math::vec3<T>&		operator+=(math::vec3<T> const & rhs) {
				math::vecbase<double,3>::operator+=(rhs);
				return *this;
			}
			math::vec3<T>&		operator-=(const vec3<T> & rhs) {
				math::vecbase<double,3>::operator-=(rhs);
				return *this;
			}
			math::vec3<T>&		operator*=(const double rhs) {
				math::vecbase<double,3>::operator*=(rhs);
				return *this;
			}
			math::vec3<T>&		operator/=(const double rhs) {
				math::vecbase<double,3>::operator/=(rhs);
				return *this;
			}			/** @} */

			//unary operators
			vec3<T>		operator-() const { vec3<T> a(*this); a.minus(); return a; }
			vec3<T>		operator+() const {return *this;}
			vec3<T>		Abs() { vec3<T> a(*this); a.vecbase<T,3>::Abs(); return a; }
			// logical
			bool		operator<(vec3<T> const & rhs) { return vecbase<T,3>::operator<(rhs); }
			//cast to pointer to a (T *) for glVertex3fv etc
			operator T* () const {return (T*) this;}
			operator const T* () const {return (const T*) this;}

#ifdef PHYSX
			operator physx::PxVec3() const { return physx::PxVec3(x,y,z); }
			vec3<T>&		operator=(physx::PxVec3 const & rhs) {
				v[0]=rhs.x;
				v[1]=rhs.y;
				v[2]=rhs.z;
				return *this;
			}
#endif







			void		RotateAxis(double angle, const math::vec3<T> & axis) {

				(*this) = GetRotatedAxis(angle, axis);
			}


	};

}

#endif	//vec3<T>_H






