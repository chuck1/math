#include <stdio.h>
#include <cmath>


#include <math/color.h>
#include <math/config.h>

math::color::color() {
	r = g = b = a = 0.0f;
	fr = fg = fb = 0.0;
	tr = tg = tb = type::e::CONST;
}
/*
math::color::color(float newR, float newG, float newB, float newA) {
	r = newR;
	g = newG;
	b = newB;
	a = newA;
	
	
	
	tr = type::e::CONST;
	tg = type::e::CONST;
	tb = type::e::CONST;
}*/
math::color::color(float newr, float newg, float newb, float newA, char newtr, char newtg, char newtb) {

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
/*math::color::color(const float * rhs) {
	r = *rhs;
	g = *(rhs+1);
	b = *(rhs+2);
	a = *(rhs+3);
}*/
math::color::color(const color & rhs) {
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
math::color::~color()
{
}
void math::color::Set(float newR, float newG, float newB, float newA) {
	r=newR;
	g=newG;
	b=newB;
	a=newA;
}
math::color math::color::rand() {
	color ret;
	ret.r = (float)(::rand() % 1000) / 1000.0f;
	ret.g = (float)(::rand() % 1000) / 1000.0f;
	ret.b = (float)(::rand() % 1000) / 1000.0f;
	ret.a = 1.0;
	return ret;
}
void math::color::SetR(float newR) {
	r = newR;
}
void math::color::SetG(float newG) {
	g = newG;
}
void math::color::SetB(float newB) {
	b = newB;
}
void math::color::SetA(float newA) {
	a = newA;
}
float math::color::GetR() const {
	return r;
}
float math::color::GetG() const {
	return g;
}
float math::color::GetB() const {
	return b;
}
float math::color::GetA() const {
	return a;
}
void math::color::SetBlack(void) {
	r = g = b = a = 1.0f;
}
void math::color::SetWhite(void) {
	r = g = b = 0.0f;
	a = 1.0f;
}
void math::color::SetGrey(float shade) {
	r = g = b = shade;
	a = 1.0f;
}
math::color math::color::lerp(const color & c2, float factor)
{
	return (*this) * (1.0f - factor) + c2 * factor;
}
math::color math::color::operator+(const color & rhs) const
{
	return color(r+rhs.r, g+rhs.g, b+rhs.b, a+rhs.a);
}
math::color math::color::operator-(const color & rhs) const
{
	return color(r-rhs.r, g-rhs.g, b-rhs.b, a-rhs.a);
}
math::color math::color::operator*(const color & rhs) const
{
	return color(r*rhs.r, g*rhs.g, b*rhs.b, a*rhs.a);
}
math::color math::color::operator/(const color & rhs) const
{
	return color(r/rhs.r, g/rhs.g, b/rhs.b, a/rhs.a);
}
math::color math::color::operator*(const float rhs) const
{
	return color(r*rhs, g*rhs, b*rhs, a*rhs);
}
math::color math::color::operator/(const float rhs) const
{
	return color(r/rhs, g/rhs, b/rhs, a/rhs);
}
bool math::color::operator ==(const math::color & rhs) const
{
	if(r != rhs.r) return false;
	if(g != rhs.g) return false;
	if(b != rhs.b) return false;
	if(a != rhs.a) return false;

	return true;
}
bool math::color::operator!=(const color & rhs) const
{
	return !((*this)==rhs);
}
math::color math::color::operator+=(const color & rhs)
{
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	a += rhs.a;

	return (*this);
}
math::color math::color::operator-=(const color & rhs)
{
	(*this)=(*this)-rhs;
	return (*this);
}
math::color math::color::operator*=(const color & rhs)
{
	(*this)=(*this)*rhs;	return (*this);
}
math::color math::color::operator/=(const color & rhs)
{
	(*this)=(*this)/rhs;	return (*this);
}
math::color math::color::operator*=(const float rhs)
{
	(*this)=(*this)*rhs;	return (*this);
}
math::color math::color::operator/=(const float rhs)
{
	(*this)=(*this)/rhs;
	return (*this);
}
math::color math::color::operator-(void) const
{
	return color(-r,-g, -b, -a);
}
math::color math::color::operator+(void) const
{
	return (*this);
}

void math::color::ClampTo01()
{
	if(r>1.0f) r=1.0f;
	if(r<0.0f) r=0.0f;

	if(g>1.0f) g=1.0f;
	if(g<0.0f) g=0.0f;

	if(b>1.0f) b=1.0f;
	if(b<0.0f) b=0.0f;

	if(a>1.0f) a=1.0f;
	if(a<0.0f) a=0.0f;
}
void	math::color::print() {
	printf("%f %f %f %f %f %f %f %i %i %i\n",r,g,b,a,fr,fg,fb,tr,tg,tb);
}

float saw(float t, float f) {
	float a = t*f;
	float y = a - floor(a);
	printf("saw: a = %f y = %f\n", a, y);
	return y;
}
void	math::color::step(double time) {
	MATH_DEBUG_1_FUNCTION;

	switch(tr)
	{
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
	switch(tg)
	{
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
	switch(tb)
	{
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
math::color operator*(float scaleFactor, const math::color & rhs)
{
	return rhs*scaleFactor;
}
math::color::operator float* () const {
	return (float*)this;
}
math::color::operator float const * () const {
	return (float*)this;
}

