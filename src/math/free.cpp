#include <stdio.h>

#include <cmath>

#include <math/free.hpp>

float	math::recipsqrt(float const & f) {
	return ( sqrt(f)/f );
}
void	math::hexdump(void* v, size_t s) {

	unsigned char* c = (unsigned char*)v;
	unsigned char* end = c + s;

	for(; c < end; ++c)
	{
		printf("%02X ", *c);
	}
	printf("\n");
}


