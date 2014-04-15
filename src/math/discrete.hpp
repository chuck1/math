#ifndef __MATH_DISCRETE_HPP__
#define __MATH_DISCRETE_HPP__

namespace math {
	namespace discrete {
		int	factorial(int n);
		void	permutations(int** perm, int* trans, int i, int N);
		void	permutations(int**& perm, int*& trans, int N);

		/** @brief permutations */
		int	p(int,int);
		/** @brief combinations */
		int	c(int,int);
	}
}

#endif
