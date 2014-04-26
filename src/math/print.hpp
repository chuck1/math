#ifndef __MATH_PRINT_HPP__
#define __MATH_PRINT_HPP__

namespace math {
	void	print(int const &);
	template<typename T> void	print(T const * const t, int n) {
		for(int i = 0; i < n; i++) {
			math::print(t[i]);
			printf(" ");
		}
	}
	template<typename T> void	print(T const * const * const t, int n, int m) {
		for(int i = 0; i < n; i++) {
			math::print(t[i], m);
			printf("\n");
		}
	}
}

#endif
