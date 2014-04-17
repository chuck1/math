#ifndef __MATH_VECBASE__
#define __MATH_VECBASE__

#include <cstdio>
#include <cstring>
#include <cmath>

#include <math/print.hpp>
#include <math/discrete/discrete.hpp>

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
			double	magnitude() const {
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
				for(int i = 0; i < N; ++i) {
					if(isinf(v[i])) return false;
				}
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
			T&	operator[](int i) { return v[i]; }

			/** @name comparison
			 * @{
			 */
			bool		operator==(const vecbase<T,N> & rhs) const {
				for(int i = 0; i < N; ++i) {
					if(v[i]!=rhs.v[i]) return false;
				}
				return true;
			}
			bool		operator!=(const vecbase<T,N> & rhs) const {
				return !((*this)==rhs);
			}/** @} */


			/** @name vector algebra
			 * @{
			 */

			T	dot(vecbase<T,N> const & rhs) const {
				T res = 0;
				for(int i = 0; i < N; ++i) {
					res += v[i] * rhs.v[i];
				}
				return res;
			}
			/** @} */

			/** @name binary operators
			 * @{
			 */
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
			void		Add(const vecbase<T,N> & v2, vecbase<T,N> & result) {
				for(int i = 0; i < N; ++i) {
					result.v[i]=v[i]+v2.v[i];
				}
			}
			void		Subtract(const vecbase<T,N> & v2, vecbase<T,N> & result) {
				for(int i = 0; i < N; ++i) {
					result.v[i]=v[i]-v2.v[i];
				}
			}
			/** @} */

			/** @name unary operators
			 * @{
			 */
			vecbase<T,N>&	minus() {
				for(int i = 0; i < N; ++i) {
					v[i] = -v[i];
				}
				return *this;
			}
			vecbase<T,N>&	abs() {
				for(int i = 0; i < N; ++i) {
					v[i] = fabs(v[i]);
				}
				return *this;
			}
			/** @} */

			void	print() const {
				for(int i = 0; i < N; i++) {
					::math::print(v[i]);
				}
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

	template <typename T, int R, int C> class matbase: public vecbase<T,R*C> {
		T&	v(int i, int j) {
			return v[i*C + j];
		}
	};
	template <typename T, int N> class matsqu: public matbase<T,N,N> {
		public:
			/** @brief determinant */
			T	det() {
				int** perm;
				int* sig;
				math::discrete::permutations(perm, sig, N);
				int p = math::discrete::p(N,N);

				T res = 0;
				for(int i = 0; i < p; ++i) {
					T prod = 1;
					for (int j = 0; j < N; ++j) {
						prod *= matbase<T,N,N>::v(j,perm[i][j]);
					}
					res += sig[i] * prod;
				}
			}
			/** @brief determinant of subset */
			T	det(int* a, int* b, int n) {
				int** perm;
				int* sig;
				math::discrete::permutations(perm, sig, N);
				int p = math::discrete::p(N,N);

				T res = 0;
				for(int i = 0; i < p; ++i) {
					T prod = 1;
					for (int j = 0; j < N; ++j) {
						prod *= matbase<T,N,N>::v(a[j],b[perm[i][j]]);
					}
					res += sig[i] * prod;
				}

			}
		private:

	};

}


#endif

