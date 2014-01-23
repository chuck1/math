#ifndef __MAT33_H__
#define __MAT33_H__

namespace math
{
	class vec3;
	class vec4;
	class quat;
	class plane;
	class transform;
	class mat33
	{
		public:
			//friend mat33 operator*(float scaleFactor, const mat33 & rhs);
			
			mat33();
			mat33(
				float, float, float,
				float, float, float,
				float, float, float);
			mat33(const float * rhs);
			mat33(const mat33 & rhs);
			mat33(vec3 const &);
			~mat33() {}
			
			void	SetEntry(int position, float value);
			float	GetEntry(int position) const;
			vec4	GetRow(int position) const;
			vec4	GetColumn(int position) const;

			void	LoadIdentity(void);
			void	LoadZero(void);
			
			//binary operators
			mat33	operator+(const mat33 & rhs) const;
			mat33	operator-(const mat33 & rhs) const;
			mat33	operator*(const mat33 & rhs) const;
			mat33	operator*(const float rhs) const;
			mat33	operator/(const float rhs) const;
			

			bool	operator==(const mat33 & rhs) const;
			bool	operator!=(const mat33 & rhs) const;

			//self-add etc
			void	operator+=(const mat33 & rhs);
			void	operator-=(const mat33 & rhs);
			void	operator*=(const mat33 & rhs);
			void	operator*=(const float rhs);
			void	operator/=(const float rhs);

			//unary operators
			mat33	operator-(void) const;
			mat33	operator+(void) const {return (*this);}

			//multiply a vector by this matrix
			vec3	operator*(const vec3 rhs) const;
			
			//rotate a 3d vector by rotation part
			void	RotateVector3D(vec3 & rhs) const;
			void	InverseRotateVector3D(vec3 & rhs) const;
			
			vec3	GetRotatedVector3D(const vec3 & rhs) const;
			vec3	GetInverseRotatedVector3D(const vec3 & rhs) const;
			
			//Other methods
			void	Invert(void);
			mat33	GetInverse(void) const;
			void	Transpose(void);
			mat33	GetTranspose(void) const;
			void	InvertTranspose(void);
			mat33	GetInverseTranspose(void) const;
			
			//set to perform an operation on space - removes other entries
			void	SetTranslation(vec3 const &);
			void	SetScale(vec3 const &);
			void	SetUniformScale(const float scaleFactor);
			void	set_rotation(quat const &);
			void	SetRotationAxis(const double angle, const vec3 & axis);
			void	SetRotationX(const double angle);
			void	SetRotationY(const double angle);
			void	SetRotationZ(const double angle);
			void	SetRotationEuler(const double angleX, const double, const double angleZ);
			void	SetPerspective(float, float, float, float, float, float);
			void	SetPerspective(float fovy, float aspect, float n, float f);
			void	SetOrtho(float left, float right, float bottom, float top, float n, float f);
			
			void	print();
			
			//set parts of the matrix
			void	SetTranslationPart(vec3 const &);
			void	SetRotationPartEuler(double const, double const, double const);
			void	SetRotationPartEuler(vec3 const & rotations);
			
			//cast to pointer to a (float *) for glGetFloatv etc
			operator float* () const {return (float*) this;}
			operator const float* () const {return (const float*) this;}

			//member variables
			float	v[9];
	};
}

#endif	//mat44_H
