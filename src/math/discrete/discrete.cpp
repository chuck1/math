#include <cstdio>
#include <iostream>
#include <math/print.hpp>
#include <math/discrete/discrete.hpp>

int	math::discrete::factorial(int n) {
	if(n < 0) {
		throw;
	}

	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
void	math::discrete::permutations(int** perm, int* trans, int i, int N) {
	
	int n = factorial(N-i-1);
	
	//printf("i=%i n=%i N=%i perm=%p\n", i, n, N, perm);
	
	int** temp_perm = perm;
	int* temp_trans = trans;

	int transpose = 0;
	
	if(i == N) {

	} else {
		//for(int p = 0; p < n; ++p) {
		bool cont = false;
		for(int j = 0; j < N; j++) {
			//printf("j = %i\n",j);

			cont = false;
			//printf("temp=%p\n",temp);
			for(int k = 0; k < i; k++) {
				if(j == (*temp_perm)[k]) {
					cont = true;
					//printf("j=%i taken\n",j);
					break;
				}
			}

			if(cont) continue;

			//printf("j = %i\n",j);

			temp_perm = perm;
			temp_trans = trans;

			if(i+1 < N) {
				//printf("perm = %p\n",perm);
				//permutation(perm, trans, i+1, N);
			}

			for(int p = 0; p < n; p++) {
				//printf("p = %i\n",p);

				//printf("perm = %p i = %i j = %i\n",perm,i,j);

				(*perm)[i] = j;
				(*trans) += transpose;
				
				//std::cout << "trans = " << ((long)trans)/4 << " " << p << std::endl;
				
				//temp = *perm;

				perm++;
				trans++;
			}

			if(i+1 < N) {
				//printf("perm = %p\n",perm);
				math::discrete::permutations(temp_perm, temp_trans, i+1, N);
			}
			
			transpose++;
		}
		//}
	}
}
void	math::discrete::permutations(int**& perm, int*& trans, int N) {
	int n = math::discrete::p(N,N);
	perm = new int*[n];
	trans = new int[n];
	for(int i = 0; i < n; i++) {
		perm[i] = new int[N];
		for(int j = 0; j < N; j++) {
			perm[i][j] = -1;
		}

		trans[i] = 0;
	}

	//printf("perm %i %i\n",n,N);
	//math::print(perm,6,3);
	//math::print(trans,6);
	//printf("start\n");
	permutations(perm, trans, 0, N);
	//printf("finish\n");
}
int	math::discrete::p(int n, int k) {
	return (factorial(n) / factorial(n-k));
}






