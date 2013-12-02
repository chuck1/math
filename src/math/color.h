//////////////////////////////////////////////////////////////////////////////////////////
//	color.h
//	Class declaration for an RGBA color
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	7th November 2002	-	Some speed improvements
//									-	Removed clamping after adds etc. Do it yourself!
//										To enable use with floating point color buffers
//									-	Corrected lerp (reversed f and 1-f)
//				13th December 2002	-	Added default parameter to alpha of Set()
//									-	Added red, green, blue constant colors
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#ifndef color_H
#define color_H

namespace math
{
	class color
	{
		public:
			//constructors
			color()
			{	r=g=b=a=0.0f;	}

			color(float newR, float newG, float newB, float newA=0.0f)
			{	r=newR;	g=newG;	b=newB;	a=newA;	}

			color(const float * rhs)
			{	r=*rhs;	g=*(rhs+1);	b=*(rhs+2); a=*(rhs+3);	}

			color(const color & rhs)
			{	r=rhs.r;	g=rhs.g;	b=rhs.b;	a=rhs.a;}

			~color() {}	//empty

			void Set(float newR, float newG, float newB, float newA=0.0f)
			{	r=newR;	g=newG;	b=newB;	a=newA;	}

			//accessors kept for compatability
			void SetR(float newR) {r = newR;}
			void SetG(float newG) {g = newG;}
			void SetB(float newB) {b = newB;}
			void SetA(float newA) {a = newA;}

			float GetR() const {return r;}	//public accessor functions
			float GetG() const {return g;}	//inline, const
			float GetB() const {return b;}
			float GetA() const {return a;}

			void ClampTo01(void);			//clamp all components to [0,1]

			void SetBlack(void) {r=g=b=a=1.0f;}
			void SetWhite(void) {r=g=b=a=0.0f;}
			void SetGrey(float shade) {r=g=b=a=shade;}

			//linear interpolate
			color lerp(const color & c2, float factor)
			{	return (*this)*(1.0f-factor) + c2*factor;	}

			//binary operators
			color operator+(const color & rhs) const
			{	return color(r+rhs.r, g+rhs.g, b+rhs.b, a+rhs.a);	}

			color operator-(const color & rhs) const
			{	return color(r-rhs.r, g-rhs.g, b-rhs.b, a-rhs.a);	}

			color operator*(const color & rhs) const
			{	return color(r*rhs.r, g*rhs.g, b*rhs.b, a*rhs.a);	}

			color operator/(const color & rhs) const
			{	return color(r/rhs.r, g/rhs.g, b/rhs.b, a/rhs.a);	}

			color operator*(const float rhs) const
			{	return color(r*rhs, g*rhs, b*rhs, a*rhs);	}

			color operator/(const float rhs) const
			{	return color(r/rhs, g/rhs, b/rhs, a/rhs);	}

			//multiply by a float, eg 3*c
			friend color operator*(float scaleFactor, const color & rhs);

			bool operator==(const color & rhs) const;
			bool operator!=(const color & rhs) const
			{	return !((*this)==rhs);	}

			//self-add etc
			color operator+=(const color & rhs)
			{
				(*this)=(*this)+rhs;
				return (*this);
			}
			color operator-=(const color & rhs)
			{	(*this)=(*this)-rhs;	return (*this);	}
			color operator*=(const color & rhs)
			{	(*this)=(*this)*rhs;	return (*this);	}
			color operator/=(const color & rhs)
			{	(*this)=(*this)/rhs;	return (*this);	}
			color operator*=(const float rhs)
			{	(*this)=(*this)*rhs;	return (*this);	}
			color operator/=(const float rhs)
			{	(*this)=(*this)/rhs;	return (*this);	}
			//unary operators
			color operator-(void) const {return color(-r,-g, -b, -a);}
			color operator+(void) const {return (*this);}

			//cast to pointer to float for glColor4fv etc
			operator float* () const {return (float*) this;}
			operator const float* () const {return (const float*) this;}

			void	print();
			//member variables
			float r;
			float g;
			float b;
			float a;
	};

	const color white(1.0f, 1.0f, 1.0f, 1.0f);
	const color black(0.0f, 0.0f, 0.0f, 0.0f);

	const color red(1.0f, 0.0f, 0.0f, 1.0f);
	const color green(0.0f, 1.0f, 0.0f, 1.0f);
	const color blue(0.0f, 0.0f, 1.0f, 1.0f);

	const color cyan(0.0f, 1.0f, 1.0f, 1.0f);
	const color magenta(1.0f, 0.0f, 1.0f, 1.0f);
	const color yellow(1.0f, 1.0f, 0.0f, 1.0f);
}

#endif	//color_H
