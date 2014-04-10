#ifndef __MATH_VECBASE__
#define __MATH_VECBASE__

#include <cstdio>

namespace math {
	template <typename T, int N> class vecbase {
		public:
			void	write(FILE* file) const {
				fwrite(v, sizeof(T), N, file);
			}
			void	read(FILE* file) {
				fread(v, sizeof(T), N, file);
			}
			// binary operators
			vecbase<T,N>&	operator+=(const vecbase<T,N> & rhs) const {
				for(int i = 0; i < N; ++i) {
					v[i] += rhs.v[i];
				}
				return *this;
			}
			vecbase<T,N>&	operator-=(const vecbase<T,N> & rhs) const {
				for(int i = 0; i < N; ++i) {
					v[i] -= rhs.v[i];
				}
				return *this;
			}
			vecbase<T,N>	operator*=(const double rhs) const {
			for(int i = 0; i < N; ++i) {
					v[i] *= rhs;
				}
				return *this;

			}
			vecbase<T,N>	operator/=(const double rhs) const {
				for(int i = 0; i < N; ++i) {
					v[i] /= rhs;
				}
				return *this;
			}

		protected:
			bool	operator<(vecbase<T,N> const & rhs) {
				for(int i = 0; i < N; i++) {
					if(v[i] >= rhs.v[i]) return false;
				}
				return true;
			}
		public:
			T	v[N];
	};
}


#endif

