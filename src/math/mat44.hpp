#ifndef __MATH_MAT44_H__
#define __MATH_MAT44_H__

#include <math/config.hpp>
#include <math/vecbase.hpp>

namespace math {
	template <typename T> class mat44: public math::matsqu<T,4> {
		public:
			mat44() { LoadIdentity(); }
			mat44(
				T, T, T, T, T, T, T, T,
				T, T, T, T, T, T, T, T);
			mat44(const T * rhs);
			mat44(const mat44 & rhs);
			mat44(quat<T> const & q);
			mat44(transform<T> const &);
			~mat44() {}	//empty

			void SetEntry(int position, T value);
			T GetEntry(int position) const;
			vec4<T> GetRow(int position) const;
			vec4<T> GetColumn(int position) const;

			void LoadIdentity(void);
			void LoadZero(void);

			//binary operators
			mat44 operator+(const mat44 & rhs) const;
			mat44 operator-(const mat44 & rhs) const;
			mat44 operator*(const mat44 & rhs) const;
			mat44 operator*(const T rhs) const;
			mat44 operator/(const T rhs) const;

			bool operator==(const mat44 & rhs) const;
			bool operator!=(const mat44 & rhs) const;

			//self-add etc
			void operator+=(const mat44 & rhs);
			void operator-=(const mat44 & rhs);
			void operator*=(const mat44 & rhs);
			void operator*=(const T rhs);
			void operator/=(const T rhs);

			//unary operators
			mat44	operator-(void) const;
			mat44	operator+(void) const {return (*this);}

			//multiply a vector by this matrix
			vec4<T>	operator*(const vec4<T> rhs) const;

			//rotate a 3d vector by rotation part
			void	RotateVector3D(vec3<double> & rhs) const;
			void	InverseRotateVector3D(vec3<double> & rhs) const;

			vec3<double>	GetRotatedVector3D(const vec3<double> & rhs) const;
			vec3<double>	GetInverseRotatedVector3D(const vec3<double> & rhs) const;

			//translate a 3d vector by translation part
			void	TranslateVector3D(vec3<double> &) const;
			void	InverseTranslateVector3D(vec3<double> &) const;

			vec3<double>	GetTranslatedVector3D(const vec3<double> & rhs) const;
			vec3<double>	GetInverseTranslatedVector3D(const vec3<double> & rhs) const;

			//Other methods
			void	Invert(void);
			mat44	GetInverse(void) const;
			void	Transpose(void);
			mat44	GetTranspose(void) const;
			void	InvertTranspose(void);
			mat44	GetInverseTranspose(void) const;
			void	SetCoordinateTransform(math::vec3<double> const,math::vec3<double> const);
			
			//Inverse of a rotation/translation only matrix
			void	AffineInvert(void);
			mat44	GetAffineInverse(void) const;
			void	AffineInvertTranspose(void);
			mat44	GetAffineInverseTranspose(void) const;
			
			//set to perform an operation on space - removes other entries
			void	SetTranslation(vec3<double> const &);
			void	SetScale(vec3<double> const &);
			void	SetUniformScale(const T scaleFactor);
			void	set_rotation(quat<T> const &);
			void	SetRotationAxis(const double angle, const vec3<double> & axis);
			void	SetRotationX(const T angle);
			void	SetRotationY(const T angle);
			void	SetRotationZ(const T angle);
			void	SetRotationEuler(const double angleX, const double, const double angleZ);
			void	SetPerspective(T, T, T, T, T, T);
			void	SetPerspective(T fovy, T aspect, T n, T f);
			void	SetOrtho(T left, T right, T bottom, T top, T n, T f);
			void	setLookAt(math::vec3<double> eye, math::vec3<double> center, math::vec3<double> up);

			void	SetReflection(plane<T> const &);
			void	print();
			
			//set parts of the matrix
			void	SetTranslationPart(vec3<double> const &);
			void	SetRotationPartEuler(double const, double const, double const);
			void	SetRotationPartEuler(vec3<double> const & rotations);
			
			//cast to pointer to a (T *) for glGetFloatv etc
			operator T* () const {return (T*) this;}
			operator const T* () const {return (const T*) this;}

			//member variables
			//T entries[16];
	};

	//mat44	perspective(T fovy, T aspect, T zn, T zf);
	//mat44	lookat(math::vec3<double> eye, math::vec3<double> center, math::vec3<double> up);

}

#endif	//mat44_H
