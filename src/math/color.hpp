#ifndef color_H
#define color_H

#include <stdlib.h>

namespace math {
	template <typename T> class color {
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
			color(double newR, double newG, double newB, double newA=0.0f,
					char = type::e::CONST,
					char = type::e::CONST,
					char = type::e::CONST);
			//color(const double * rhs);
			color(const color & rhs);
			~color();
			void		Set(double newR, double newG, double newB, double newA=0.0f);
			static color	rand();
			void		SetR(double newR);
			void		SetG(double newG);
			void		SetB(double newB);
			void		SetA(double newA);
			double		GetR() const;
			double		GetG() const;
			double		GetB() const;
			double		GetA() const;
			void		ClampTo01(void);
			void		SetBlack(void);
			void		SetWhite(void);
			void		SetGrey(double shade);

			color		lerp(const color & c2, double factor);
			color		operator+(const color & rhs) const;
			color		operator-(const color & rhs) const;
			color		operator*(const color & rhs) const;
			color		operator/(const color & rhs) const;
			color		operator*(const double rhs) const;
			color		operator/(const double rhs) const;
			//friend color	operator*(double scaleFactor, const color & rhs);
			bool		operator==(const color & rhs) const;
			bool		operator!=(const color & rhs) const;
			color		operator+=(const color & rhs);
			color		operator-=(const color & rhs);
			color		operator*=(const color & rhs);
			color		operator/=(const color & rhs);
			color		operator*=(const double rhs);
			color		operator/=(const double rhs);
			color		operator-(void) const;
			color		operator+(void) const;
			operator double* () const;
			operator const double* () const;
			void		step(double);
			void		print();
		public:
			double	r;
			double	g;
			double	b;
			double	a;
			double	fr;
			double	fg;
			double	fb;
			char	tr;
			char	tg;
			char	tb;	
	};

	const color<float> white(	1.0f, 1.0f, 1.0f, 1.0f);
	const color<float> black(	0.0f, 0.0f, 0.0f, 1.0f);

	const color<float> red(		1.0f, 0.0f, 0.0f, 1.0f);
	const color<float> green(	0.0f, 1.0f, 0.0f, 1.0f);
	const color<float> blue(	0.0f, 0.0f, 1.0f, 1.0f);

	const color<float> cyan(	0.0f, 1.0f, 1.0f, 1.0f);
	const color<float> magenta(	1.0f, 0.0f, 1.0f, 1.0f);
	const color<float> yellow(	1.0f, 1.0f, 0.0f, 1.0f);
}

#endif	//color_H
