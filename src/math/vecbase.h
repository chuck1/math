#ifndef __MATH_VECBASE__
#define __MATH_VECBASE__

#include <cstdio>
#include <cstring>
#include <cmath>

namespace math {
	template <typename T, int N> class vecbase {
		public:
			typedef T Type;
		public:
			// constructor
			vecbase() {}
			vecbase(T const * const rhs) {
				memcpy(v, rhs, N * sizeof(T));
			}
			void	LoadZero() {
				for(int i = 0; i < N; ++i) {
					v[i] = 0;
				}
			}
			double		magnitude() const {
				double a;
				for(int i = 0; i < N; ++i) {
					a += v[i]*v[i];
				}
				return sqrt(a);
			}
			void	Normalize() {
				
				double length = magnitude();
				
				if(length==1.0f) return;
				
				if(length==0.0f) {
					printf("normalize zero vector\n");
					throw;
				}
				
				double scalefactor = 1.0f/length;
				
				(*this) *= scalefactor;
			}
			bool	IsFinite() const {
				if(isinf(v[0])) return false;
				if(isinf(v[1])) return false;
				if(isinf(v[2])) return false;
				return true;
			}
			bool	IsNan() const {
				if(isnan(v[0])) return true;
				if(isnan(v[1])) return true;
				if(isnan(v[2])) return true;
				return false;
			}
			void	write(FILE* file) const {
				fwrite(v, sizeof(T), N, file);
			}
			void	read(FILE* file) {
				fread(v, sizeof(T), N, file);
			}
			// binary operators
			vecbase<T,N>&	operator+=(const vecbase<T,N> & rhs) {
				for(int i = 0; i < N; ++i) {
					v[i] += rhs.v[i];
				}
				return *this;
			}
			vecbase<T,N>&	operator-=(const vecbase<T,N> & rhs) {
				for(int i = 0; i < N; ++i) {
					v[i] -= rhs.v[i];
				}
				return *this;
			}
			vecbase<T,N>	operator*=(const double rhs) {
				for(int i = 0; i < N; ++i) {
					v[i] *= rhs;
				}
				return *this;

			}
			vecbase<T,N>	operator/=(const double rhs) {
				for(int i = 0; i < N; ++i) {
					v[i] /= rhs;
				}
				return *this;
			}
			// unary
			vecbase<T,N>&	Abs() {
				for(int i = 0; i < N; ++i) {
					v[i] = fabs(v[i]);
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

