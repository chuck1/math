#ifndef __MATH_VECBASE__
#define __MATH_VECBASE__


#include <cstdio>
#include <cstring>
#include <cmath>

#include <iostream>

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
			vecbase() { loadZero(); }
			vecbase(vecbase<T,N> const & rhs) {
				for(int i = 0; i < N; ++i) {
					v_[i] = rhs.v_[i];
				}
				//rhs.print();
				//print();
			}
			vecbase(T const * const rhs) {
				for(int i = 0; i < N; ++i) {
					v_[i] = rhs[i];
				}
				//memcpy(v_, rhs, N * sizeof(T));
			}
			/** @} */
			void	loadZero() {
				for(int i = 0; i < N; ++i) {
					v_[i] = 0;
				}
			}
			T	magnitude() const {
				T a = 0;
				for(int i = 0; i < N; ++i) {
					a += v_[i] * v_[i];
				}
	
				std::cout << "length squared = " << a << std::endl;

				return sqrt(a);
			}
			void	Normalize() {
				
				T length = magnitude();
				
				if(length==1.0f) return;
				
				if(length==0.0f) {
					printf("normalize zero vector\n");
					throw;
				}
				
				std::cout << "normalizing length = " << length << std::endl;

				(*this) /= length;
			}
			bool		isFinite() const {
				for(int i = 0; i < N; ++i) {
					if(isinf(v_[i])) return false;
				}
				return true;
			}
			bool		isNan() const {
				for(int i = 0; i < N; i++) {
					if(isnan(v_[i])) return true;
				}
				return false;
			}
			bool		isSane() {
				return (isFinite() && (!isNan()));
			}
			void		write(FILE* file) const {
				fwrite(v_, sizeof(T), N, file);
			}
			void		read(FILE* file) {
				fread(v_, sizeof(T), N, file);
			}
			/** @name Accessors @{ */
			T&		v(int i) {
				return v_[i];
			}
			T const &	v(int i) const {
				return v_[i];
			}
			/** @{ */
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
					res += v_[i] * rhs.v_[i];
				}
				return res;
			}
			/** @} */

			/** @name Self-Assignment operators @{ */
			vecbase<T,N>&	operator+=(const vecbase<T,N> & rhs) {
				for(int i = 0; i < N; ++i) {
					v_[i] += rhs.v_[i];
				}
				return *this;
			}
			vecbase<T,N>&	operator-=(const vecbase<T,N> & rhs) {
				for(int i = 0; i < N; ++i) {
					v_[i] -= rhs.v_[i];
				}
				return *this;
			}
			vecbase<T,N>&	operator*=(const T rhs) {
				for(int i = 0; i < N; ++i) {
					v_[i] *= rhs;
				}
				return *this;
			}
			vecbase<T,N>&	operator/=(const T rhs) {
				for(int i = 0; i < N; ++i) {
					v_[i] /= rhs;
				}
				return *this;
			}
			/** @} */
			/** @name Binary Operators @{ */
			vecbase<T,N>	operator+(const vecbase<T,N> & rhs) const {
				vecbase<T,N> ret(*this);
				ret += rhs;
				return ret;
			}
			vecbase<T,N>	operator-(const vecbase<T,N> & rhs) const {
				vecbase<T,N> ret(*this);
				ret -= rhs;
				return ret;
			}
			vecbase<T,N>	operator*(const T rhs) const {
				vecbase<T,N> ret(*this);
				ret *= rhs;
				return ret;
			}
			vecbase<T,N>	operator/(const T rhs) const {
				vecbase<T,N> ret(*this);
				ret /= rhs;
				return ret;
			}
			void		Add(const vecbase<T,N> & v2, vecbase<T,N> & result) const {
				for(int i = 0; i < N; ++i) {
					result.v[i]=v[i]+v2.v[i];
				}
			}
			void		Subtract(const vecbase<T,N> & v2, vecbase<T,N> & result) const {
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
					v_[i] = -v_[i];
				}
				return *this;
			}
			vecbase<T,N>&	abs() {
				for(int i = 0; i < N; ++i) {
					v_[i] = fabs(v_[i]);
				}
				return *this;
			}
			vecbase<T,N>	operator-() const {
				vecbase<T,N> ret(*this);
				ret.minus();
				return ret;
			}
			/** @} */

			void	print() const {
				for(int i = 0; i < N; i++) {
					::math::print(v_[i]);
					printf(" ");
				}
				printf("\n");
			}
		protected:
			bool	operator<(vecbase<T,N> const & rhs) {
				for(int i = 0; i < N; i++) {
					if(v_[i] >= rhs.v_[i]) return false;
				}
				return true;
			}
		public:
			T	v_[N];
	};
	/** @brief Two-Dimensional Matrix */
	template <typename T, int R, int C> class matbase: public vecbase<T,R*C> {
		public:
			/** @name Constructor @{ */
			matbase() {}
			matbase(math::vecbase<T,R*C> const & rhs): math::vecbase<T,R*C>(rhs) {}
			matbase(math::matbase<T,R,C> const & rhs): math::vecbase<T,R*C>(rhs) {}
			matbase(const T * rhs): vecbase<T,R*C>(rhs) {
				//memcpy(v, rhs, R*C*sizeof(T));
			}
			/** @} */
			/** @name Accessors @{ */
			T&		v(int i, int j) {
				return math::vecbase<T,R*C>::v_[i*C + j];
			}
			T const &	v(int i, int j) const {
				return math::vecbase<T,R*C>::v_[i*C + j];
			}
			/** @} */
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
			/** @name Binary Operators @{ */
			math::matbase<T,R,C>		operator+(math::matbase<T,R,C> const & rhs) const {
				math::matbase<T,R,C> m;
				for(int i = 0; i < 9; ++i) m.v_[i] = v(i) + rhs.v_[i];
				return m;
			}
			math::matbase<T,R,C>		operator-(math::matbase<T,R,C> const & rhs) const {
				math::matbase<T,R,C> m;
				for(int i = 0; i < 9; ++i) m.v_[i] = v(i) - rhs.v_[i];
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
			math::vecbase<T,R>		operator*(const vecbase<T,C> rhs) const {
				math::vecbase<T,R> ret;

				for(int r = 0; r < R; r++) {
					ret.v_[r] = 0;
					for(int c = 0; c < C; c++) {
						ret.v_[r] += v(r,c) * rhs.v_[c];
					}
				}
				return ret;
			}
			math::matbase<T,R,C>		operator*(T const & rhs) const {
				return vecbase<T,R*C>::operator*(rhs);
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
				for(int i = 0; i < 9; ++i) v(i) *= rhs.v_[i];
			}
			void		operator*=(const math::matbase<T,R,C> & rhs) {
				(*this) = (*this) * rhs;
			}
			void		operator*=(const T rhs) {
				for(int i = 0; i < 9; ++i) v(i) *= rhs;
			}

			void		operator/=(const T rhs)
			{
				(*this)=(*this)/rhs;
			}
			math::matbase<T,R,C>	operator-() const {
				math::matbase<T,R,C> result(*this);

				for(int i=0; i<16; i++)
					result.v_[i]=-result.v_[i];

				return result;
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
			matsqu(math::matbase<T,N,N> const & rhs): math::matbase<T,N,N>(rhs) {}
			matsqu(math::matsqu<T,N> const & rhs): math::matbase<T,N,N>(rhs) {
				//memcpy(v, rhs.v, 9*sizeof(T));
			}

			void		loadIdentity() {
				vecbase<T,N*N>::loadZero();
				for(int i = 0; i < N; i++) {
					matbase<T,N,N>::v(i,i) = 1.0;
				}
			}
			/** @name Binary Operators @{ */
			matsqu<T,N>	operator*(T const & rhs) const {
				return matbase<T,N,N>::operator*(rhs);
			}
			/** @} */
			/** @brief determinant */
			T	det() const {
				int** perm;
				int* trans;
				math::discrete::permutations(perm, trans, N);
				int p = math::discrete::p(N,N);
				
				T res = 0;
				for(int i = 0; i < p; ++i) {
					T prod = 1;
					for (int j = 0; j < N; ++j) {
						prod *= matbase<T,N,N>::v(j,perm[i][j]);
					}
					res += pow(-1.0, trans[i]) * prod;
				}
				return res;
			}
			/** @brief determinant of subset */
			T	det(int* a, int* b, int n) const {
				int** perm;
				int* trans;
				math::discrete::permutations(perm, trans, N);
				int p = math::discrete::p(N,N);
				
				T res = 0;
				for(int i = 0; i < p; ++i) {
					T prod = 1;
					for (int j = 0; j < N; ++j) {
						prod *= matbase<T,N,N>::v(a[j],b[perm[i][j]]);
					}
					res += pow(-1.0, trans[i]) * prod;
				}

			}
		private:

	};

	}


#endif

