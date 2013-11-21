//////////////////////////////////////////////////////////////////////////////////////////
//	mat44.h
//	Class declaration for a 4x4 matrix
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Updated:	19th August 2002	-	Corrected 2nd SetPerspective for n!=1.0f
//				26th September 2002	-	Added nudge to prevent artifacts with infinite far plane
//									-	Improved speed
//				7th November 2002	-	Added Affine Inverse functions
//									-	Changed constructors
//									-	Added special cases for row3 = (0, 0, 0, 1)
//				17th December 2002	-	Converted from radians to degrees for consistency
//										with OpenGL. Should have been done a long time ago...
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#ifndef mat44_H
#define mat44_H

namespace math
{
	class vec3;
	class vec4;
	
	class mat44
	{
		public:
			mat44()
			{	LoadIdentity();	}
			mat44(	float e0, float e1, float e2, float e3,
					float e4, float e5, float e6, float e7,
					float e8, float e9, float e10, float e11,
					float e12, float e13, float e14, float e15);
			mat44(const float * rhs);
			mat44(const mat44 & rhs);
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
			mat44 operator-(void) const;
			mat44 operator+(void) const {return (*this);}

			//multiply a vector by this matrix
			vec4 operator*(const vec4 rhs) const;

			//rotate a 3d vector by rotation part
			void RotateVector3D(vec3 & rhs) const;
			void InverseRotateVector3D(vec3 & rhs) const;

			vec3 GetRotatedVector3D(const vec3 & rhs) const;
			vec3 GetInverseRotatedVector3D(const vec3 & rhs) const;

			//translate a 3d vector by translation part
			void TranslateVector3D(vec3 &) const;
			void InverseTranslateVector3D(vec3 &) const;

			vec3 GetTranslatedVector3D(const vec3 & rhs) const;
			vec3 GetInverseTranslatedVector3D(const vec3 & rhs) const;

			//Other methods
			void Invert(void);
			mat44 GetInverse(void) const;
			void Transpose(void);
			mat44 GetTranspose(void) const;
			void InvertTranspose(void);
			mat44 GetInverseTranspose(void) const;
			
			//Inverse of a rotation/translation only matrix
			void AffineInvert(void);
			mat44 GetAffineInverse(void) const;
			void AffineInvertTranspose(void);
			mat44 GetAffineInverseTranspose(void) const;
			
			//set to perform an operation on space - removes other entries
			void SetTranslation(const vec3 & translation);
			void SetScale(const vec3 & scaleFactor);
			void SetUniformScale(const float scaleFactor);
			void SetRotationAxis(const double angle, const vec3 & axis);
			void SetRotationX(const double angle);
			void SetRotationY(const double angle);
			void SetRotationZ(const double angle);
			void SetRotationEuler(const double angleX, const double angleY, const double angleZ);
			void SetPerspective(float left, float right, float bottom, float top, float n, float f);
			void SetPerspective(float fovy, float aspect, float n, float f);
			void SetOrtho(float left, float right, float bottom, float top, float n, float f);
			
			//set parts of the matrix
			void SetTranslationPart(const vec3 & translation);
			void SetRotationPartEuler(const double angleX, const double angleY, const double angleZ);
			void SetRotationPartEuler(const vec3 & rotations);
			
			//cast to pointer to a (float *) for glGetFloatv etc
			operator float* () const {return (float*) this;}
			operator const float* () const {return (const float*) this;}

			//member variables
			float entries[16];
	};
}

#endif	//mat44_H
