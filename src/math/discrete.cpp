
int	factorial(int n) {
	if(n < 0) {
		throw;
	}

	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
void	permutation(int** perm, int* trans, int i, int N) {

	int n = factorial(N-i-1);

	//printf("i=%i n=%i N=%i perm=%p\n", i, n, N, perm);
	
	int** temp = perm;
	
	if(i == N) {
	
	} else {
		//for(int p = 0; p < n; ++p) {
		int j = 0;
		bool cont = false;
		for(int j = 0; j < N; j++) {
			//printf("j = %i\n",j);
			
			cont = false;
			for(int k = 0; k < i; k++) {
				if(j == (*temp)[k]) {
					cont = true;
					//printf("j=%i taken\n",j);
					break;
				}
			}
			
			if(cont) continue;
			
			//printf("j = %i\n",j);
			
			temp = perm;

			if(i+1 < N) {
				//printf("perm = %p\n",perm);
				//permutation(perm, trans, i+1, N);
			}
			
			for(int p = 0; p < n; p++) {
				//printf("p = %i\n",p);
				
				//printf("perm = %p i = %i j = %i\n",perm,i,j);

				(*perm)[i] = j;
