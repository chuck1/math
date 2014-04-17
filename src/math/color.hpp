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

#include <stdlib.h>

namespace math
{
	class color {
		public:
			struct type {
				enum e: char {
					CONST,
					SINE,
					SAW,
					SQUARE,
				};
			};

			//constructors
			color();
			color(float newR, float newG, float newB, float newA=0.0f,
					char = type::e::CONST,
					char = type::e::CONST,
					char = type::e::CONST);
			//color(const float * rhs);
			color(const color & rhs);
			~color();
			void		Set(float newR, float newG, float newB, float newA=0.0f);
			static color	rand();
			void		SetR(float newR);
			void		SetG(float newG);
			void		SetB(float newB);
			void		SetA(float newA);
			float		GetR() const;
			float		GetG() const;
			float		GetB() const;
			float		GetA() const;
			void		ClampTo01(void);
			void		SetBlack(void);
			void		SetWhite(void);
			void		SetGrey(float shade);

			color		lerp(const color & c2, float factor);
			color		operator+(const color & rhs) const;
			color		operator-(const color & rhs) const;
			color		operator*(const color & rhs) const;
			color		operator/(const color & rhs) const;
			color		operator*(const float rhs) const;
			color		operator/(const float rhs) const;
			friend color	operator*(float scaleFactor, const color & rhs);
			bool		operator==(const color & rhs) const;
			bool		operator!=(const color & rhs) const;
			color		operator+=(const color & rhs);
			color		operator-=(const color & rhs);
			color		operator*=(const color & rhs);
			color		operator/=(const color & rhs);
			color		operator*=(const float rhs);
			color		operator/=(const float rhs);
			color		operator-(void) const;
			color		operator+(void) const;
			operator float* () const;
			operator const float* () const;
			void		step(double);
			void		print();
		public:
			float	r;
			float	g;
			float	b;
			float	a;
			float	fr;
			float	fg;
			float	fb;
			char	tr;
			char	tg;
			char	tb;	
	};

	const color white(	1.0f, 1.0f, 1.0f, 1.0f);
	const color black(	0.0f, 0.0f, 0.0f, 1.0f);

	const color red(	1.0f, 0.0f, 0.0f, 1.0f);
	const color green(	0.0f, 1.0f, 0.0f, 1.0f);
	const color blue(	0.0f, 0.0f, 1.0f, 1.0f);

	const color cyan(	0.0f, 1.0f, 1.0f, 1.0f);
	const color magenta(	1.0f, 0.0f, 1.0f, 1.0f);
	const color yellow(	1.0f, 1.0f, 0.0f, 1.0f);
}

#endif	//color_H
