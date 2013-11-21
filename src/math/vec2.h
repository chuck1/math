//////////////////////////////////////////////////////////////////////////////////////////
//	vec2.h
//	Class declaration for a 2d vector
//	Downloaded from: www.paulsprojects.net
//	Created:	6th November 2002
//	Modified:	7th January 2003	-	Added QuadraticInterpolate
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#ifndef __VEC2_H__
#define __VEC2_H__

namespace math
{
	class vec2
	{
		public:
			//constructors
			vec2(void):
				x(0.0f), y(0.0f)
		{}

			vec2(float newX, float newY):
				x(newX), y(newY)
		{}

			vec2(const float * rhs):
				x(*rhs), y((*rhs)+1)
		{}

			vec2(const vec2 & rhs):
				x(rhs.x), y(rhs.y)
		{}

			~vec2() {}	//empty

			void Set(float newX, float newY)
			{	x=newX;	y=newY;	}

			//Accessors kept for compatibility
			void SetX(float newX) {x = newX;}
			void SetY(float newY) {y = newY;}

			float GetX() const {return x;}	//public accessor functions
			float GetY() const {return y;}	//inline, const

			void LoadZero(void);
			void LoadOne(void);					//fill with (1, 1)

			void Normalize();
			vec2 GetNormalized() const;

			float GetLength() const
			{	return (float)sqrt((x*x)+(y*y));	}

			float GetSquaredLength() const
			{	return (x*x)+(y*y);	}

			//linear interpolate
			vec2 lerp(const vec2 & v2, float factor) const
			{	return (*this)*(1.0f-factor) + v2*factor;	}

			vec2 QuadraticInterpolate(const vec2 & v2, const vec2 & v3, float factor) const
			{	return (*this)*(1.0f-factor)*(1.0f-factor) + 2*v2*factor*(1.0f-factor) + v3*factor*factor;}

			//overloaded operators
			//binary operators
			vec2 operator+(const vec2 & rhs) const
			{	return vec2(x + rhs.x, y + rhs.y);	}

			vec2 operator-(const vec2 & rhs) const
			{	return vec2(x - rhs.x, y - rhs.y);	}

			vec2 operator*(const float rhs) const
			{	return vec2(x*rhs, y*rhs);	}

			vec2 operator/(const float rhs) const
			{	return (rhs==0) ? vec2(0.0f, 0.0f) : vec2(x / rhs, y / rhs);	}

			//multiply by a float, eg 3*v
			friend vec2 operator*(float scaleFactor, const vec2 & rhs);

			bool operator==(const vec2 & rhs) const;
			bool operator!=(const vec2 & rhs) const
			{	return !((*this)==rhs);	}

			//self-add etc
			void operator+=(const vec2 & rhs)
			{	x+=rhs.x;	y+=rhs.y;}

			void operator-=(const vec2 & rhs)
			{	x-=rhs.x;	y-=rhs.y;}

			void operator*=(const float rhs)
			{	x*=rhs;	y*=rhs;	}

			void operator/=(const float rhs)
			{	if(rhs==0.0f)
				return;
				else
				{	x/=rhs; y/=rhs;	}
			}


			//unary operators
			vec2 operator-(void) const {return vec2(-x, -y);}
			vec2 operator+(void) const {return *this;}

			//cast to pointer to a (float *) for glVertex3fv etc
			operator float* () const {return (float*) this;}
			operator const float* () const {return (const float*) this;}

			//member variables
			float x;
			float y;
	};
}

#endif //__VEC2_H__
