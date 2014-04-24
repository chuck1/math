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
			/** @name Constructors
			 * @{
			 */
			vecbase() {}
			vecbase(vecbase<T,N> const & rhs) {
				for(int i = 0; i < N; ++i) {
					v[i] = rhs.v[i];
				}
			}
			vecbase(T const * const rhs) {
				memcpy(v, rhs, N * sizeof(T));
			}
			/** @} */
			void	loadZero() {
				for(int i = 0; i < N; ++i) {
					v[i] = 0;
				}
			}
			T	magnitude() const {
				T a;
				for(int i = 0; i < N; ++i) {
					a += v[i]*v[i];
				}
				return sqrt(a);
			}
			void	Normalize() {
				
				T length = magnitude();
				
				if(length==1.0f) return;
				
				if(length==0.0f) {
					printf("normalize zero vector\n");
					throw;
				}
				
				T scalefactor = 1.0f/length;
				
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
			vecbase<T,N>	operator*=(const T rhs) {
				for(int i = 0; i < N; ++i) {
					v[i] *= rhs;
				}
				return *this;

			}
			vecbase<T,N>	operator/=(const T rhs) {
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
		public:
			matbase(math::matbase<T,R,C> const & rhs): math::matbase<T,R,C>(rhs) {
				memcpy(v, rhs.v, R*C*sizeof(T));
			}
			matbase(const T * rhs) {
				memcpy(v, rhs, R*C*sizeof(T));
			}

			T&	v(int i, int j) {
				return v[i*C + j];
			}



			math::vecbase<T,C>	getRow(int r) const {
				math::vecbase<T,C> ret;
				for(int c = 0; c < C; c++) {
					ret[c] = v(r,c);
				}
				return ret;
			}
			math::vecbase<T,R>	getColumn(int c) const {
				math::vecbase<T,R> ret;
				for(int r = 0; r < R; r++) {
					ret[r] = v(r,c);
				}
				return ret;
			}

			

			math::matbase<T,R,C>		operator+(math::matbase<T,R,C> const & rhs) const {
				math::matbase<T,R,C> m;
				for(int i = 0; i < 9; ++i) m.v[i] = v[i] + rhs.v[i];
				return m;
			}
			math::matbase<T,R,C>		operator-(math::matbase<T,R,C> const & rhs) const {
				math::matbase<T,R,C> m;
				for(int i = 0; i < 9; ++i) m.v[i] = v[i] - rhs.v[i];
				return m;
			}

			math::matbase<T,R,R>		operator*(math::matbase<T,C,R> const & rhs) const {
				math::matbase<T,R,C> m;

				for(int r = 0; r < R; r++) {
					for(int c = 0; c < C; c++) {
						for(int c1 = 0; c1 < C; c1++) {
							m.v(r,c) = v(r,c1) * rhs.v(c1,r);
						}

					}
				}

			}
			bool				operator==(math::matbase<T,R,C> const & rhs) const {
				for(int i=0; i<16; i++)
				{
					if(v[i]!=rhs.v[i])
						return false;
				}
				return true;
			}
			bool		operator!=(const math::matbase<T,R,C> & rhs) const {
				return !((*this)==rhs);
			}
			void		operator+=(const math::matbase<T,R,C> & rhs) {
				(*this)=(*this)+rhs;
			}
			void		operator-=(const math::matbase<T,R,C> & rhs)
			{
				for(int i = 0; i < 9; ++i) v[i] *= rhs.v[i];
			}
			void		operator*=(const math::matbase<T,R,C> & rhs) {
				(*this) = (*this) * rhs;
			}
			void		operator*=(const T rhs) {
				for(int i = 0; i < 9; ++i) v[i] *= rhs;
			}
			void		operator/=(const T rhs)
			{
				(*this)=(*this)/rhs;
			}
			math::matbase<T,R,C>	operator-() const {
				math::matbase<T,R,C> result(*this);

				for(int i=0; i<16; i++)
					result.v[i]=-result.v[i];

				return result;
			}
			math::vecbase<T,R>		operator*(const vecbase<T,C> rhs) const {
				math::vecbase<T,R> ret;

				for(int r = 0; r < R; r++) {
					ret[r] = 0;
					for(int c = 0; c < C; c++) {
						ret[r] += v(r,c) * rhs[c];
					}
				}
				return ret;
			}
			void		print() {
				for(int r = 0; r < R; ++r)
				{
					for(int c = 0; c < C; ++c)
					{
						printf("%f ",v(r,c));
					}
					printf("\n");
				}
			}

	};
	template <typename T, int N> class matsqu: public matbase<T,N,N> {
		public:
			matsqu() {
				loadIdentity();
			}
			matsqu(math::matsqu<T,N> const & rhs): math::matbase<T,N,N>(rhs) {
				//memcpy(v, rhs.v, 9*sizeof(T));
			}

			void		loadIdentity() {
				vecbase<T,N*N>::loadZero();
				for(int i = 0; i < N; i++) {
					matbase<T,N,N>::v(i,i) = 1.0;
				}
			}

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

