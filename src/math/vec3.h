#ifndef vec3_H
#define vec3_H

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif


#include <math/math.h>
#include <math/vecbase.h>

namespace math {
	class vec3: public vecbase<double,3> {
		public:
			//constructors
			vec3();
			vec3(vec3 const &);
			vec3(double const &, double const &, double const &);
			vec3(double const * const);
			
#ifdef PHYSX
			vec3(physx::PxVec3 const & rhs);
#endif
			~vec3() {}	//empty

			//Accessors kept for compatibility
			double&		x() { return v[0]; }
			double&		y() { return v[1]; }
			double&		z() { return v[2]; }

			//vector algebra
			double		dot(vec3 const & rhs) const;
			vec3		cross(const vec3 & rhs) const;
			double		angle(vec3 const & rhs) const;
			math::vec3	GetNormalized() const;
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
			vec3		lerp(const vec3 & v2, double factor) const
			{
				return (*this)*(1.0f-factor) + v2*factor;
			}
			vec3		QuadraticInterpolate(
					const vec3 & v2,
					const vec3 & v3,
					double factor) const
			{
				return (*this)*(1.0f-factor)*(1.0f-factor)+
					v2 * 2 * factor*(1.0f-factor)+
					v3 * factor * factor;
			}

			//overloaded operators
			//binary operators
			vec3		operator+(const vec3 & rhs) const;
			vec3		operator-(const vec3 & rhs) const;
			vec3		operator*(const double rhs) const;
			vec3		operator/(const double rhs) const;

			//multiply by a double, eg 3*v
			//friend vec3 operator*(double scaleFactor, const vec3 & rhs);

			//Add, subtract etc, saving the construction of a temporary
			void		Add(const vec3 & v2, vec3 & result);
			void		Subtract(const vec3 & v2, vec3 & result);

			bool		operator==(const vec3 & rhs) const;
			bool		operator!=(const vec3 & rhs) const;
			//self-add etc
			vec3&		operator+=(const vec3 & rhs);
			vec3&		operator-=(const vec3 & rhs);
			vec3&		operator*=(const double rhs);
			vec3&		operator/=(const double rhs);

			void		print() const;
			//unary operators
			vec3		operator-() const {return vec3(-v[0], -v[1], -v[2]);}
			vec3		operator+() const {return *this;}
			vec3		Abs() { vec3 a(*this); a.vecbase<double,3>::Abs(); return a; }
			// logical
			bool		operator<(vec3 const & rhs) { return vecbase<double,3>::operator<(rhs); }
			//cast to pointer to a (double *) for glVertex3fv etc
			operator double* () const {return (double*) this;}
			operator const double* () const {return (const double*) this;}

#ifdef PHYSX
			operator physx::PxVec3() const { return physx::PxVec3(x,y,z); }
			vec3&		operator=(physx::PxVec3 const & rhs) {
				v[0]=rhs.x;
				v[1]=rhs.y;
				v[2]=rhs.z;
				return *this;
			}
#endif


	};

}

#endif	//vec3_H






