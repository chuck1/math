#ifndef __MATH_FREE_H__
#define __MATH_FREE_H__

#include <tinyxml2.h>

namespace math {
	float					recipsqrt(float const &);
	void					hexdump(void*, size_t);
	template<typename T,typename F>	F	saw(T t, F f) {
		F a = t*f;
		return (a - floor(a));
	}
}

#endif


