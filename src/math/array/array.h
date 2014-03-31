#ifndef __MATH_ARRAY_ARRAY_H__
#define __MATH_ARRAY_ARRAY_H__

template<typename... Args> inline void pass(Args&&...) {}

template <typename T = double, int D = 1> class array {

	public:
		array() {
			for(int a = 0; a < D; ++a) shape[a] = 0;
			size = 0;
			v = NULL;
		}
		
		void alloc_sub(int& a, int s) {
			size *= s;
			shape[a--] = s;
		}
		
		template<typename... S> void zeros(S... s) {
			
		}

		void alloc(int const * s) {
			size = 1;
			for(int a = 0; a < D; ++a) {
				size *= s[a];
				shape[a] = s[a];
			}

			v = new T[size];
		}
		template<typename... S> void alloc(S... s) {
			if(sizeof...(S) != D) throw;
			
			int a = D-1;
			size = 1;
			pass((alloc_sub(a,s),1)...);
			
			v = new T[size];
		}
		
		void at_sub(int* i, int& a, int s) {
			i[a--] = s;
		}
		
		template<int... S> T& at() {
			if(sizeof...(S) != D) throw;
			
			int i[D];
			int a = D-1;
			
			pass((at_sub(i,a,S),1)...);
			
			return at(i);
		}

		T& at(int* i) {
			T* t = v;
			int r = size;
			for(int a = 0; a < D; ++a) {
				r /= shape[a];
				t += r * i[a];
			}
			return *t;
		}
		
		void print_sub(char const* fmt, int* i, int lvl) {
			if(lvl == (D-1)) {
				for(int a = 0; a < shape[lvl]; ++a) {
					i[lvl] = a;
					printf(fmt, at(i));
				}
			} else {
				for(int a = 0; a < shape[lvl]; ++a) {
					i[lvl] = a;
					print_sub(fmt, i, lvl+1);
					printf("\n");
				}
			}
		}
	
		
		array<T,D>& operator=(array<T,D> const & rhs) {
			alloc(rhs.shape);
			for(int a = 0; a < size; ++a) v[a] = rhs.v[a];
			return *this;
		}
		array<T,D>& operator+=(array<T,D> const & rhs) {
			if(size != rhs.size) {
				printf("operator+= size mismatch\n");
				throw;
			}
			
			for(int a = 0; a < size; ++a) v[a] += rhs.v[a];
			return *this;
		}
		array<T,D>& operator+=(T const & rhs) {
			for(int a = 0; a < size; ++a) v[a] += rhs;
			return *this;
		}

		array<T,D> operator+(array<T,D> const & rhs) {
			if(size != rhs.size) {
				printf("operator+ size mismatch\n");
				throw;
			}

			array<T,D> r;
			r = *this;
			r += rhs;
			return r;
		}
		array<T,D> operator+(T const & rhs) {
			array<T,D> r = *this;
			r += rhs;
			return r;

		}




		void print(char const* fmt) {
			int i[D];
			print_sub(fmt, i, 0);
		}
		
		
		
		int	shape[D];
		int	size;
		T*	v;
};

#endif

