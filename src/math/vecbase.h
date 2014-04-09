#ifndef __MATH_VECBASE__
#define __MATH_VECBASE__

#include <cstdio>

namespace math {
	template <class A, int n> class vecio: virtual public A {
		public:
			void	write(FILE* file) const {
				fwrite(A::v, sizeof(double), n, file);
			}
			void	read(FILE* file) {
				fread(A::v, sizeof(double), n, file);
			}
	};
}


#endif

