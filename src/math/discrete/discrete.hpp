#ifndef __MATH_DISCRETE_HPP__
#define __MATH_DISCRETE_HPP__

#include <vector>
#include <memory>

namespace math {
	namespace discrete {
		int	factorial(int n);
		void	permutations(int** perm, int* trans, int i, int N);
		void	permutations(int**& perm, int*& trans, int N);
		
		/** @brief permutations */
		int	p(int,int);
		/** @brief combinations */
		int	c(int,int);
		
		namespace Graph {
			class Node {
			};
			class Edge {
				public:
					Node*	a_;
					Node*	b_;
			};
			class EdgeWeighted: public Edge {
				public:
					double	w_;
			};
			class Graph {
				public:
					std::vector<Node*>	nodes_;
					std::vector<Edge*>	edges_;
			};
		}
	}
}

#endif


