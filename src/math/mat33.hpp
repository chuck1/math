#ifndef __MAT33_H__
#define __MAT33_H__

#include <math/config.h>
#include <math/vecbase.h>

namespace math {
	class mat33: public vecbase<double,9> {
		public:
			//friend mat33 operator*(double scaleFactor, const mat33 & rhs);

			mat33();
			mat33(
					double, double, double,
					double, double, double,
					double, double, double);
			mat33(const double * rhs);
			mat33(const mat33 & rhs);
			mat33(vec3<double> const &);
			~mat33() {}

			void	SetEntry(int position, double value);
			double	GetEntry(int position) const;
			vec4	GetRow(int position) const;
			vec4	GetColumn(int position) const;

			void	LoadIdentity(void);
			void	LoadZero(void);

			void	SetDiagonal(double, double, double);

			//binary operators
			mat33	operator+(const mat33 & rhs) const;
			mat33	operator-(const mat33 & rhs) const;
			mat33	operator*(const mat33 & rhs) const;
			mat33	operator*(const double rhs) const;
			mat33	operator/(const double rhs) const;


			bool	operator==(const mat33 & rhs) const;
			bool	operator!=(const mat33 & rhs) const;

			//self-add etc
			void	operator+=(const mat33 & rhs);
			void	operator-=(const mat33 & rhs);
			void	operator*=(const mat33 & rhs);
			void	operator*=(const double rhs);
			void	operator/=(const double rhs);

			//unary operators
			mat33	operator-(void) const;
			mat33	operator+(void) const {return (*this);}

			//multiply a vector by this matrix
			vec3<double>	operator*(const vec3<double> rhs) const;

			//rotate a 3d vector by rotation part
			void	RotateVector3D(vec3<double> & rhs) const;
			void	InverseRotateVector3D(vec3<double> & rhs) const;

			vec3<double>	GetRotatedVector3D(const vec3<double> & rhs) const;
			vec3<double>	GetInverseRotatedVector3D(const vec3<double> & rhs) const;

			//Other methods
			void	Invert(void);
			mat33	GetInverse(void) const;
			void	Transpose(void);
			mat33	GetTranspose(void) const;
			void	InvertTranspose(void);
			mat33	GetInverseTranspose(void) const;

			//set to perform an operation on space - removes other entries
			void	SetTranslation(vec3<double> const &);
			void	SetScale(vec3<double> const &);
			void	SetUniformScale(const double scaleFactor);
			void	setRotation(quat const &);
			void	SetRotationAxis(const double angle, const vec3<double> & axis);
			void	SetRotationX(const double angle);
			void	SetRotationY(const double angle);
			void	SetRotationZ(const double angle);
			void	SetRotationEuler(const double angleX, const double, const double angleZ);

			void	print();

			//set parts of the matrix
			void	SetRotationPartEuler(vec3<double> const & rotations);

			//cast to pointer to a (double *) for glGetFloatv etc
			operator double* () const {return (double*) this;}
			operator const double* () const {return (const double*) this;}

			//member variables

	};
}

#endif	//mat44_H
