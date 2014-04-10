#ifndef __MATH_VECBASE__
#define __MATH_VECBASE__

#include <cstdio>

namespace math {
	template <int N> class vecbase {
		public:
			void	write(FILE* file) const {
				fwrite(v, sizeof(double), N, file);
			}
			void	read(FILE* file) {
				fread(v, sizeof(double), N, file);
			}
		public:
			double	v[N];
	};
}


#endif

