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

			color() {
				r = g = b = a = 0.0f;
				fr = fg = fb = 0.0;
				tr = tg = tb = type::e::CONST;
			}
			color(double newR, double newG, double newB, double newA) {
				r = newR;
				g = newG;
				b = newB;
				a = newA;
			}
			color(double newr, double newg, double newb, double newA, char newtr, char newtg, char newtb) {

				tr = newtr;
				tg = newtg;
				tb = newtb;

				switch(tr)
				{
					case type::e::SINE:
						r = 0.0;
						fr = newr;
						break;
					case type::e::SAW:
						r = 0.0;
						fr = newr;
						break;
					case type::e::CONST:
					default:
						r = newr;
						fr = 0.0;
						break;

				}
				switch(tb)
				{
					case type::e::SINE:
						b = 0.0;
						fb = newb;
						break;
					case type::e::SAW:
						b = 0.0;
						fb = newb;
						break;
					case type::e::CONST:
					default:

						b = newb;
						fb = 0.0;
						break;

				}
				switch(tr)
				{
					case type::e::SINE:
						g = 0.0;
						fg = newg;
						break;
					case type::e::SAW:
						g = 0.0;
						fg = newg;
						break;
					case type::e::CONST:
					default:
						g = newg;
						fg = 0.0;
						break;

				}

				a = newA;
			}
			/*math::color::color(const double * rhs) {
			  r = *rhs;
			  g = *(rhs+1);
			  b = *(rhs+2);
			  a = *(rhs+3);
			  }*/
			color(const color & rhs) {
				r = rhs.r;
				g = rhs.g;
				b = rhs.b;
				a = rhs.a;
				fr = rhs.fr;
				fg = rhs.fg;
				fb = rhs.fb;
				tr = rhs.tr;
				tg = rhs.tg;
				tb = rhs.tb;
			}


			~color()
			{
			}
			void		set(double newR, double newG, double newB, double newA) {
				r=newR;
				g=newG;
				b=newB;
				a=newA;
			}
			math::color<T>	rand() {
				color ret;
				ret.r = (double)(::rand() % 1000) / 1000.0f;
				ret.g = (double)(::rand() % 1000) / 1000.0f;
				ret.b = (double)(::rand() % 1000) / 1000.0f;
				ret.a = 1.0;
				return ret;
			}
			void		setR(double newR) {
				r = newR;
			}
			void		setG(double newG) {
				g = newG;
			}
			void		setB(double newB) {
				b = newB;
			}
			void		setA(double newA) {
				a = newA;
			}
			double		getR() const {
				return r;
			}
			double		getG() const {
				return g;
			}
			double		getB() const {
				return b;
			}
			double		getA() const {
				return a;
			}
			void		setBlack() {
				r = g = b = a = 1.0f;
			}
			void		setWhite() {
				r = g = b = 0.0f;
				a = 1.0f;
			}
			void		setGrey(double shade) {
				r = g = b = shade;
				a = 1.0f;
			}
			math::color<T>		lerp(const color & c2, double factor) {
				return (*this) * (1.0f - factor) + c2 * factor;
			}
			math::color<T>		operator+(const color & rhs) const {
				return color(r+rhs.r, g+rhs.g, b+rhs.b, a+rhs.a);
			}
			math::color<T>		operator-(const color & rhs) const {
				return color(r-rhs.r, g-rhs.g, b-rhs.b, a-rhs.a);
			}
			math::color<T>		operator*(const color & rhs) const {
				return color(r*rhs.r, g*rhs.g, b*rhs.b, a*rhs.a);
			}
			math::color<T>		operator/(const color & rhs) const {
				return color(r/rhs.r, g/rhs.g, b/rhs.b, a/rhs.a);
			}
			math::color<T>		operator*(const double rhs) const {
				return color(r*rhs, g*rhs, b*rhs, a*rhs);
			}
			math::color<T>		operator/(const double rhs) const {
				return color(r/rhs, g/rhs, b/rhs, a/rhs);
			}
			bool			operator ==(math::color<T> const & rhs) const {
				if(r != rhs.r) return false;
				if(g != rhs.g) return false;
				if(b != rhs.b) return false;
				if(a != rhs.a) return false;

				return true;
			}
			bool			operator!=(color<T> const & rhs) const {
				return !((*this)==rhs);
			}
			math::color<T>		operator+=(color<T> const & rhs) {
				r += rhs.r;
				g += rhs.g;
				b += rhs.b;
				a += rhs.a;

				return (*this);
			}
			math::color<T>		operator-=(color<T> const & rhs) {
				(*this)=(*this)-rhs;
				return (*this);
			}
			math::color<T>		operator*=(const color & rhs) {
				(*this)=(*this)*rhs;	return (*this);
			}
			math::color<T>		operator/=(const color & rhs) {
				(*this)=(*this)/rhs;	return (*this);
			}
			math::color<T>		operator*=(const double rhs) {
				(*this)=(*this)*rhs;	return (*this);
			}
			math::color<T>		operator/=(const double rhs) {
				(*this)=(*this)/rhs;
				return (*this);
			}
			math::color<T>		operator-() const {
				return color(-r,-g, -b, -a);
			}
			math::color<T>		operator+() const{
				return (*this);
			}
			void			clampTo01() {
				if(r>1.0f) r=1.0f;
				if(r<0.0f) r=0.0f;

				if(g>1.0f) g=1.0f;
				if(g<0.0f) g=0.0f;

				if(b>1.0f) b=1.0f;
				if(b<0.0f) b=0.0f;

				if(a>1.0f) a=1.0f;
				if(a<0.0f) a=0.0f;
			}
			void			print() {
				printf("%f %f %f %f %f %f %f %i %i %i\n",r,g,b,a,fr,fg,fb,tr,tg,tb);
			}

			double			saw(double t, double f) {
				double a = t*f;
				double y = a - floor(a);
				printf("saw: a = %f y = %f\n", a, y);
				return y;
			}
			void			step(double time) {
				//MATH_DEBUG_1_FUNCTION;

				switch(tr) {
					case type::e::CONST:
						break;
					case type::e::SINE:
						r = 0.5 * sin(2.0 * M_PI * fr * time) + 0.5;
						printf("sine r = %f\n", r);
						break;
					case type::e::SAW:
						r = saw(time, fr);
						break;

				}
				switch(tg) {
					case type::e::CONST:
						break;
					case type::e::SINE:
						g = 0.5 * sin(2.0 * M_PI * fg * time) + 0.5;
						printf("g = %f\n", g);
						break;
					case type::e::SAW:
						g = saw(time, fg);
						break;
				}
				switch(tb) {
					case type::e::CONST:
						break;
					case type::e::SINE:
						b = 0.5 * sin(2.0 * M_PI * fb * time) + 0.5;
						break;
					case type::e::SAW:
						b = saw(time, fb);
						break;
				}

			}
			math::color<T>		operator*(double f) {
				math::color<T> ret(*this);
				ret *= f;
				return ret;
			}
			operator double* () const {
				return (double*)this;
			}
			operator double const * () const {
				return (double*)this;
			}

			//constructors
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
