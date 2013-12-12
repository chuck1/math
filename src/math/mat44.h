#ifndef __MAT44_H__
#define __MAT44_H__

namespace math
{
	class vec3;
	class vec4;
	class quat;
	class plane;
	class transform;
	class mat44
	{
		public:
			mat44()
			{	LoadIdentity();	}
			mat44(
				float, float, float, float, float, float, float, float,
				float, float, float, float, float, float, float, float);
			mat44(const float * rhs);
			mat44(const mat44 & rhs);
			mat44(const quat & q);
			mat44(transform const &);
			~mat44() {}	//empty

			void SetEntry(int position, float value);
			float GetEntry(int position) const;
			vec4 GetRow(int position) const;
			vec4 GetColumn(int position) const;

			void LoadIdentity(void);
			void LoadZero(void);

			//binary operators
			mat44 operator+(const mat44 & rhs) const;
			mat44 operator-(const mat44 & rhs) const;
			mat44 operator*(const mat44 & rhs) const;
			mat44 operator*(const float rhs) const;
			mat44 operator/(const float rhs) const;
			friend mat44 operator*(float scaleFactor, const mat44 & rhs);

			bool operator==(const mat44 & rhs) const;
			bool operator!=(const mat44 & rhs) const;

			//self-add etc
			void operator+=(const mat44 & rhs);
			void operator-=(const mat44 & rhs);
			void operator*=(const mat44 & rhs);
			void operator*=(const float rhs);
			void operator/=(const float rhs);

			//unary operators
			mat44	operator-(void) const;
			mat44	operator+(void) const {return (*this);}

			//multiply a vector by this matrix
			vec4	operator*(const vec4 rhs) const;

			//rotate a 3d vector by rotation part
			void	RotateVector3D(vec3 & rhs) const;
			void	InverseRotateVector3D(vec3 & rhs) const;

			vec3	GetRotatedVector3D(const vec3 & rhs) const;
			vec3	GetInverseRotatedVector3D(const vec3 & rhs) const;

			//translate a 3d vector by translation part
			void	TranslateVector3D(vec3 &) const;
			void	InverseTranslateVector3D(vec3 &) const;

			vec3	GetTranslatedVector3D(const vec3 & rhs) const;
			vec3	GetInverseTranslatedVector3D(const vec3 & rhs) const;

			//Other methods
			void	Invert(void);
			mat44	GetInverse(void) const;
			void	Transpose(void);
			mat44	GetTranspose(void) const;
			void	InvertTranspose(void);
			mat44	GetInverseTranspose(void) const;
			void	SetCoordinateTransform(math::vec3 const,math::vec3 const);
			
			//Inverse of a rotation/translation only matrix
			void	AffineInvert(void);
			mat44	GetAffineInverse(void) const;
			void	AffineInvertTranspose(void);
			mat44	GetAffineInverseTranspose(void) const;
			
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
			
			void	SetReflection(plane const &);
			void	print();
			
			//set parts of the matrix
			void	SetTranslationPart(vec3 const &);
			void	SetRotationPartEuler(double const, double const, double const);
			void	SetRotationPartEuler(vec3 const & rotations);
			
			//cast to pointer to a (float *) for glGetFloatv etc
			operator float* () const {return (float*) this;}
			operator const float* () const {return (const float*) this;}

			//member variables
			float entries[16];
	};

	mat44	perspective(float fovy, float aspect, float zn, float zf);
	mat44	lookat(math::vec3 eye, math::vec3 center, math::vec3 up);

}

#endif	//mat44_H
