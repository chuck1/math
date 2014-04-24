#ifndef __MATH_MAT44_H__
#define __MATH_MAT44_H__

#include <math/config.hpp>
#include <math/vecbase.hpp>

namespace math {
	template <typename T> class mat44: public math::matsqu<T,4> {
		public:
			mat44() { LoadIdentity(); }




			mat44(float e0, float e1, float e2, float e3,
					float e4, float e5, float e6, float e7,
					float e8, float e9, float e10, float e11,
					float e12, float e13, float e14, float e15)
			{
				matbase<T,4,4>::v(0,0) = e0;
				matbase<T,4,4>::v(0,1) = e1;
				matbase<T,4,4>::v(0,2) = e2;
				matbase<T,4,4>::v(0,3) = e3;
				matbase<T,4,4>::v(1,0) = e4;
				matbase<T,4,4>::v(1,1) = e5;
				matbase<T,4,4>::v(1,2) = e6;
				matbase<T,4,4>::v(1,3) = e7;
				matbase<T,4,4>::v(2,0) = e8;
				matbase<T,4,4>::v(2,1) = e9;
				matbase<T,4,4>::v(2,2) = e10;
				matbase<T,4,4>::v(2,3) = e11;
				matbase<T,4,4>::v(3,0) = e12;
				matbase<T,4,4>::v(3,1) = e13;
				matbase<T,4,4>::v(3,2) = e14;
				matbase<T,4,4>::v(3,3) = e15;
			}
			mat44(const mat44<T> & rhs): matbase<T,4,4>(rhs) {}
			mat44(const float * rhs): matbase<T,4,4>(rhs) {}
			mat44(const math::quat<T> & q)
			{
				const float x = q.x;
				const float y = q.y;
				const float z = q.z;
				const float w = q.w;

				const float x2 = x + x;
				const float y2 = y + y;
				const float z2 = z + z;

				const float xx = x2*x;
				const float yy = y2*y;
				const float zz = z2*z;

				const float xy = x2*y;
				const float xz = x2*z;
				const float xw = x2*w;

				const float yz = y2*z;
				const float yw = y2*w;
				const float zw = z2*w;

				matbase<T,4,4>::v(0] = 1.0f - yy - zz;
				matbase<T,4,4>::v(1] = xy + zw;
				matbase<T,4,4>::v(2] = xz - yw;
				matbase<T,4,4>::v(3] = 0.0f;
				matbase<T,4,4>::v(4] = xy - zw;
				matbase<T,4,4>::v(5] = 1.0f - xx - zz;
				matbase<T,4,4>::v(6] = yz + xw;
				matbase<T,4,4>::v(7] = 0.0f;
				matbase<T,4,4>::v(8] = xz + yw;
				matbase<T,4,4>::v(9] = yz - xw;
				matbase<T,4,4>::v(10] = 1.0f - xx - yy;
				matbase<T,4,4>::v(11] = 0.0f;
				matbase<T,4,4>::v(12] = 0.0f;
				matbase<T,4,4>::v(13] = 0.0f;
				matbase<T,4,4>::v(14] = 0.0f;
				matbase<T,4,4>::v(15] = 1.0f;
			}
			mat44(math::transform<T> const & t)
			{
				LoadIdentity();

				set_rotation(t.q);
				SetTranslationPart(t.p);
			}
			void		set_rotation(math::quat<T> const & q)
			{
				const float x = q.x;
				const float y = q.y;
				const float z = q.z;
				const float w = q.w;

				const float x2 = x + x;
				const float y2 = y + y;
				const float z2 = z + z;

				const float xx = x2*x;
				const float yy = y2*y;
				const float zz = z2*z;

				const float xy = x2*y;
				const float xz = x2*z;
				const float xw = x2*w;

				const float yz = y2*z;
				const float yw = y2*w;
				const float zw = z2*w;

				matbase<T,4,4>::v(0] = 1.0f - yy - zz;
				matbase<T,4,4>::v(1] = xy + zw;
				matbase<T,4,4>::v(2] = xz - yw;

				matbase<T,4,4>::v(4] = xy - zw;
				matbase<T,4,4>::v(5] = 1.0f - xx - zz;
				matbase<T,4,4>::v(6] = yz + xw;

				matbase<T,4,4>::v(8] = xz + yw;
				matbase<T,4,4>::v(9] = yz - xw;
				matbase<T,4,4>::v(10] = 1.0f - xx - yy;
			}
			void SetEntry(int position, float value)
			{
				if(position>=0 && position<=15)
					matbase<T,4,4>::v(position]=value;
			}
			float		GetEntry(int position) const
			{
				if(position>=0 && position<=15)
					return matbase<T,4,4>::v(position];

				return 0.0f;
			}
			math::vec4<T>	GetRow(int position) const
			{
				if(position==0)
					return vec4(matbase<T,4,4>::v(0], matbase<T,4,4>::v(4], matbase<T,4,4>::v(8], matbase<T,4,4>::v(12]);

				if(position==1)
					return vec4(matbase<T,4,4>::v(1], matbase<T,4,4>::v(5], matbase<T,4,4>::v(9], matbase<T,4,4>::v(13]);

				if(position==2)
					return vec4(matbase<T,4,4>::v(2], matbase<T,4,4>::v(6], matbase<T,4,4>::v(10], matbase<T,4,4>::v(14]);

				if(position==3)
					return vec4(matbase<T,4,4>::v(3], matbase<T,4,4>::v(7], matbase<T,4,4>::v(11], matbase<T,4,4>::v(15]);

				return vec4(0.0f, 0.0f, 0.0f, 0.0f);
			}
			math::vec4<T> GetColumn(int position) const
			{
				if(position==0)
					return vec4(matbase<T,4,4>::v(0], matbase<T,4,4>::v(1], matbase<T,4,4>::v(2], matbase<T,4,4>::v(3]);

				if(position==1)
					return vec4(matbase<T,4,4>::v(4], matbase<T,4,4>::v(5], matbase<T,4,4>::v(6], matbase<T,4,4>::v(7]);

				if(position==2)
					return vec4(matbase<T,4,4>::v(8], matbase<T,4,4>::v(9], matbase<T,4,4>::v(10], matbase<T,4,4>::v(11]);

				if(position==3)
					return vec4(matbase<T,4,4>::v(12], matbase<T,4,4>::v(13], matbase<T,4,4>::v(14], matbase<T,4,4>::v(15]);

				return vec4(0.0f, 0.0f, 0.0f, 0.0f);
			}
			void LoadIdentity(void)
			{
				memset(entries, 0, 16*sizeof(float));
				matbase<T,4,4>::v(0]=1.0f;
				matbase<T,4,4>::v(5]=1.0f;
				matbase<T,4,4>::v(10]=1.0f;
				matbase<T,4,4>::v(15]=1.0f;
			}
			void LoadZero(void)
			{
				memset(entries, 0, 16*sizeof(float));
			}
			mat44<T> operator+(const mat44<T> & rhs) const		//overloaded operators
			{
				return math::mat44(	matbase<T,4,4>::v(0]+rhs.matbase<T,4,4>::v(0],
						matbase<T,4,4>::v(1]+rhs.matbase<T,4,4>::v(1],
						matbase<T,4,4>::v(2]+rhs.matbase<T,4,4>::v(2],
						matbase<T,4,4>::v(3]+rhs.matbase<T,4,4>::v(3],
						matbase<T,4,4>::v(4]+rhs.matbase<T,4,4>::v(4],
						matbase<T,4,4>::v(5]+rhs.matbase<T,4,4>::v(5],
						matbase<T,4,4>::v(6]+rhs.matbase<T,4,4>::v(6],
						matbase<T,4,4>::v(7]+rhs.matbase<T,4,4>::v(7],
						matbase<T,4,4>::v(8]+rhs.matbase<T,4,4>::v(8],
						matbase<T,4,4>::v(9]+rhs.matbase<T,4,4>::v(9],
						matbase<T,4,4>::v(10]+rhs.matbase<T,4,4>::v(10],
						matbase<T,4,4>::v(11]+rhs.matbase<T,4,4>::v(11],
						matbase<T,4,4>::v(12]+rhs.matbase<T,4,4>::v(12],
						matbase<T,4,4>::v(13]+rhs.matbase<T,4,4>::v(13],
						matbase<T,4,4>::v(14]+rhs.matbase<T,4,4>::v(14],
						matbase<T,4,4>::v(15]+rhs.matbase<T,4,4>::v(15]);
			}
			mat44<T> operator-(const mat44<T> & rhs) const		//overloaded operators
			{
				return math::mat44(	matbase<T,4,4>::v(0]-rhs.matbase<T,4,4>::v(0],
						matbase<T,4,4>::v(1]-rhs.matbase<T,4,4>::v(1],
						matbase<T,4,4>::v(2]-rhs.matbase<T,4,4>::v(2],
						matbase<T,4,4>::v(3]-rhs.matbase<T,4,4>::v(3],
						matbase<T,4,4>::v(4]-rhs.matbase<T,4,4>::v(4],
						matbase<T,4,4>::v(5]-rhs.matbase<T,4,4>::v(5],
						matbase<T,4,4>::v(6]-rhs.matbase<T,4,4>::v(6],
						matbase<T,4,4>::v(7]-rhs.matbase<T,4,4>::v(7],
						matbase<T,4,4>::v(8]-rhs.matbase<T,4,4>::v(8],
						matbase<T,4,4>::v(9]-rhs.matbase<T,4,4>::v(9],
						matbase<T,4,4>::v(10]-rhs.matbase<T,4,4>::v(10],
						matbase<T,4,4>::v(11]-rhs.matbase<T,4,4>::v(11],
						matbase<T,4,4>::v(12]-rhs.matbase<T,4,4>::v(12],
						matbase<T,4,4>::v(13]-rhs.matbase<T,4,4>::v(13],
						matbase<T,4,4>::v(14]-rhs.matbase<T,4,4>::v(14],
						matbase<T,4,4>::v(15]-rhs.matbase<T,4,4>::v(15]);
			}
			mat44<T> operator*(const mat44<T> & rhs) const
			{
				//Optimise for matrices in which bottom row is (0, 0, 0, 1) in both matrices
				if(	matbase<T,4,4>::v(3]==0.0f && matbase<T,4,4>::v(7]==0.0f && matbase<T,4,4>::v(11]==0.0f && matbase<T,4,4>::v(15]==1.0f	&&
						rhs.matbase<T,4,4>::v(3]==0.0f && rhs.matbase<T,4,4>::v(7]==0.0f &&
						rhs.matbase<T,4,4>::v(11]==0.0f && rhs.matbase<T,4,4>::v(15]==1.0f)
				{
					return math::mat44(	matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(2],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(2],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(2],
							0.0f,
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(6],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(6],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(6],
							0.0f,
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(10],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(10],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(10],
							0.0f,
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(12],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(13],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(14],
							1.0f);
				}

				//Optimise for when bottom row of 1st matrix is (0, 0, 0, 1)
				if(	matbase<T,4,4>::v(3]==0.0f && matbase<T,4,4>::v(7]==0.0f && matbase<T,4,4>::v(11]==0.0f && matbase<T,4,4>::v(15]==1.0f)
				{
					return math::mat44(	matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(3],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(3],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(3],
							rhs.matbase<T,4,4>::v(3],
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(7],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(7],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(7],
							rhs.matbase<T,4,4>::v(7],
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(11],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(11],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(11],
							rhs.matbase<T,4,4>::v(11],
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(15],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(15],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(15],
							rhs.matbase<T,4,4>::v(15]);
				}

				//Optimise for when bottom row of 2nd matrix is (0, 0, 0, 1)
				if(	rhs.matbase<T,4,4>::v(3]==0.0f && rhs.matbase<T,4,4>::v(7]==0.0f &&
						rhs.matbase<T,4,4>::v(11]==0.0f && rhs.matbase<T,4,4>::v(15]==1.0f)
				{
					return math::mat44(	matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(2],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(2],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(2],
							matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(2],
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(6],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(6],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(6],
							matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(6],
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(10],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(10],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(10],
							matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(10],
							matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(12],
							matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(13],
							matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(14],
							matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(15]);
				}	

				return math::mat44(	matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(3],
						matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(3],
						matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(3],
						matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(0]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(1]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(2]+matbase<T,4,4>::v(15]*rhs.matbase<T,4,4>::v(3],
						matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(7],
						matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(7],
						matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(7],
						matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(4]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(5]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(6]+matbase<T,4,4>::v(15]*rhs.matbase<T,4,4>::v(7],
						matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(11],
						matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(11],
						matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(11],
						matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(8]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(9]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(10]+matbase<T,4,4>::v(15]*rhs.matbase<T,4,4>::v(11],
						matbase<T,4,4>::v(0]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(4]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(8]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(12]*rhs.matbase<T,4,4>::v(15],
						matbase<T,4,4>::v(1]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(5]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(9]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(13]*rhs.matbase<T,4,4>::v(15],
						matbase<T,4,4>::v(2]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(6]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(10]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(14]*rhs.matbase<T,4,4>::v(15],
						matbase<T,4,4>::v(3]*rhs.matbase<T,4,4>::v(12]+matbase<T,4,4>::v(7]*rhs.matbase<T,4,4>::v(13]+matbase<T,4,4>::v(11]*rhs.matbase<T,4,4>::v(14]+matbase<T,4,4>::v(15]*rhs.matbase<T,4,4>::v(15]);
			}
			mat44<T> operator*(const float rhs) const
			{
				return math::mat44(	matbase<T,4,4>::v(0]*rhs,
						matbase<T,4,4>::v(1]*rhs,
						matbase<T,4,4>::v(2]*rhs,
						matbase<T,4,4>::v(3]*rhs,
						matbase<T,4,4>::v(4]*rhs,
						matbase<T,4,4>::v(5]*rhs,
						matbase<T,4,4>::v(6]*rhs,
						matbase<T,4,4>::v(7]*rhs,
						matbase<T,4,4>::v(8]*rhs,
						matbase<T,4,4>::v(9]*rhs,
						matbase<T,4,4>::v(10]*rhs,
						matbase<T,4,4>::v(11]*rhs,
						matbase<T,4,4>::v(12]*rhs,
						matbase<T,4,4>::v(13]*rhs,
						matbase<T,4,4>::v(14]*rhs,
						matbase<T,4,4>::v(15]*rhs);
			}
			mat44<T> operator/(const float rhs) const
			{
				if (rhs==0.0f || rhs==1.0f)
					return (*this);

				float temp=1/rhs;

				return (*this)*temp;
			}
			bool operator==(const mat44<T> & rhs) const
			{
				for(int i=0; i<16; i++)
				{
					if(matbase<T,4,4>::v(i]!=rhs.matbase<T,4,4>::v(i])
						return false;
				}
				return true;
			}
			bool operator!=(const mat44<T> & rhs) const
			{
				return !((*this)==rhs);
			}
			void operator+=(const mat44<T> & rhs)
			{
				(*this)=(*this)+rhs;
			}
			void operator-=(const mat44<T> & rhs)
			{
				(*this)=(*this)-rhs;
			}
			void operator*=(const mat44<T> & rhs)
			{
				(*this)=(*this)*rhs;
			}
			void operator*=(const float rhs)
			{
				(*this)=(*this)*rhs;
			}
			void operator/=(const float rhs)
			{
				(*this)=(*this)/rhs;
			}
			mat44<T> operator-(void) const
			{
				mat44<T> result(*this);

				for(int i=0; i<16; i++)
					result.matbase<T,4,4>::v(i]=-result.matbase<T,4,4>::v(i];

				return result;
			}
			math::vec4<T> operator*(const vec4<T> rhs) const
			{
				//Optimise for matrices in which bottom row is (0, 0, 0, 1)
				if(matbase<T,4,4>::v(3]==0.0f && matbase<T,4,4>::v(7]==0.0f && matbase<T,4,4>::v(11]==0.0f && matbase<T,4,4>::v(15]==1.0f)
				{
					return vec4(
							matbase<T,4,4>::v(0]*rhs.x
							+	matbase<T,4,4>::v(4]*rhs.y
							+	matbase<T,4,4>::v(8]*rhs.z
							+	matbase<T,4,4>::v(12]*rhs.w,
							matbase<T,4,4>::v(1]*rhs.x
							+	matbase<T,4,4>::v(5]*rhs.y
							+	matbase<T,4,4>::v(9]*rhs.z
							+	matbase<T,4,4>::v(13]*rhs.w,
							matbase<T,4,4>::v(2]*rhs.x
							+	matbase<T,4,4>::v(6]*rhs.y
							+	matbase<T,4,4>::v(10]*rhs.z
							+	matbase<T,4,4>::v(14]*rhs.w,
							rhs.w);
				}

				return vec4(
						matbase<T,4,4>::v(0] * rhs.x
						+ matbase<T,4,4>::v(4] * rhs.y
						+ matbase<T,4,4>::v(8] * rhs.z
						+ matbase<T,4,4>::v(12] * rhs.w,
						matbase<T,4,4>::v(1] * rhs.x
						+ matbase<T,4,4>::v(5] * rhs.y
						+ matbase<T,4,4>::v(9] * rhs.z
						+ matbase<T,4,4>::v(13] * rhs.w,
						matbase<T,4,4>::v(2] * rhs.x
						+ matbase<T,4,4>::v(6] * rhs.y
						+ matbase<T,4,4>::v(10] * rhs.z
						+ matbase<T,4,4>::v(14] * rhs.w,
						matbase<T,4,4>::v(3] * rhs.x
						+ matbase<T,4,4>::v(7] * rhs.y
						+ matbase<T,4,4>::v(11] * rhs.z
						+ matbase<T,4,4>::v(15] * rhs.w);

			}
			math::vec3<double>	GetRotatedVector3D(const vec3<double> & rhs) const
			{
				return vec3<double>(
						matbase<T,4,4>::v(0]*rhs.v[0] + matbase<T,4,4>::v(4]*rhs.v[1] + matbase<T,4,4>::v(8] *rhs.v[2],
						matbase<T,4,4>::v(1]*rhs.v[0] + matbase<T,4,4>::v(5]*rhs.v[1] + matbase<T,4,4>::v(9] *rhs.v[2],
						matbase<T,4,4>::v(2]*rhs.v[0] + matbase<T,4,4>::v(6]*rhs.v[1] + matbase<T,4,4>::v(10]*rhs.v[2]);
			}
			math::vec3<double>	GetInverseRotatedVector3D(const vec3<double> & rhs) const
			{
				//rotate by transpose:
				return vec3<double>(
						matbase<T,4,4>::v(0]*rhs.v[0] + matbase<T,4,4>::v(1]*rhs.v[1] + matbase<T,4,4>::v(2] *rhs.v[2],
						matbase<T,4,4>::v(4]*rhs.v[0] + matbase<T,4,4>::v(5]*rhs.v[1] + matbase<T,4,4>::v(6] *rhs.v[2],
						matbase<T,4,4>::v(8]*rhs.v[0] + matbase<T,4,4>::v(9]*rhs.v[1] + matbase<T,4,4>::v(10]*rhs.v[2]);
			}
			math::vec3<double>	GetTranslatedVector3D(const vec3<double> & rhs) const {

				return vec3<double>(rhs.v[0]+matbase<T,4,4>::v(12], rhs.v[1]+matbase<T,4,4>::v(13], rhs.v[2]+matbase<T,4,4>::v(14]);
			}
			math::vec3<double>	GetInverseTranslatedVector3D(const vec3<double> & rhs) const
			{
				return vec3<double>(rhs.v[0]-matbase<T,4,4>::v(12], rhs.v[1]-matbase<T,4,4>::v(13], rhs.v[2]-matbase<T,4,4>::v(14]);
			}
			void		Invert(void)
			{
				*this=GetInverse();
			}
			mat44<T>sGetInverse(void) const
			{
				mat44<T> result=GetInverseTranspose();

				result.Transpose();

				return result;
			}
			void		Transpose(void)
			{
				*this=GetTranspose();
			}
			mat44<T>sGetTranspose(void) const
			{
				return math::mat44(
						matbase<T,4,4>::v( 0], matbase<T,4,4>::v( 4], matbase<T,4,4>::v( 8], matbase<T,4,4>::v(12],
						matbase<T,4,4>::v( 1], matbase<T,4,4>::v( 5], matbase<T,4,4>::v( 9], matbase<T,4,4>::v(13],
						matbase<T,4,4>::v( 2], matbase<T,4,4>::v( 6], matbase<T,4,4>::v(10], matbase<T,4,4>::v(14],
						matbase<T,4,4>::v( 3], matbase<T,4,4>::v( 7], matbase<T,4,4>::v(11], matbase<T,4,4>::v(15]);
			}
			void		InvertTranspose(void)
			{
				*this=GetInverseTranspose();
			}
			mat44<T>sGetInverseTranspose(void) const
			{
				mat44<T> result;

				float tmp[12];												//temporary pair storage
				float det;													//determinant

				//calculate pairs for first 8 elements (cofactors)
				tmp[0] = matbase<T,4,4>::v(10] * matbase<T,4,4>::v(15];
				tmp[1] = matbase<T,4,4>::v(11] * matbase<T,4,4>::v(14];
				tmp[2] = matbase<T,4,4>::v(9] * matbase<T,4,4>::v(15];
				tmp[3] = matbase<T,4,4>::v(11] * matbase<T,4,4>::v(13];
				tmp[4] = matbase<T,4,4>::v(9] * matbase<T,4,4>::v(14];
				tmp[5] = matbase<T,4,4>::v(10] * matbase<T,4,4>::v(13];
				tmp[6] = matbase<T,4,4>::v(8] * matbase<T,4,4>::v(15];
				tmp[7] = matbase<T,4,4>::v(11] * matbase<T,4,4>::v(12];
				tmp[8] = matbase<T,4,4>::v(8] * matbase<T,4,4>::v(14];
				tmp[9] = matbase<T,4,4>::v(10] * matbase<T,4,4>::v(12];
				tmp[10] = matbase<T,4,4>::v(8] * matbase<T,4,4>::v(13];
				tmp[11] = matbase<T,4,4>::v(9] * matbase<T,4,4>::v(12];

				//calculate first 8 elements (cofactors)
				result.SetEntry(0,		tmp[0]*matbase<T,4,4>::v(5] + tmp[3]*matbase<T,4,4>::v(6] + tmp[4]*matbase<T,4,4>::v(7]
						-	tmp[1]*matbase<T,4,4>::v(5] - tmp[2]*matbase<T,4,4>::v(6] - tmp[5]*matbase<T,4,4>::v(7]);

				result.SetEntry(1,		tmp[1]*matbase<T,4,4>::v(4] + tmp[6]*matbase<T,4,4>::v(6] + tmp[9]*matbase<T,4,4>::v(7]
						-	tmp[0]*matbase<T,4,4>::v(4] - tmp[7]*matbase<T,4,4>::v(6] - tmp[8]*matbase<T,4,4>::v(7]);

				result.SetEntry(2,		tmp[2]*matbase<T,4,4>::v(4] + tmp[7]*matbase<T,4,4>::v(5] + tmp[10]*matbase<T,4,4>::v(7]
						-	tmp[3]*matbase<T,4,4>::v(4] - tmp[6]*matbase<T,4,4>::v(5] - tmp[11]*matbase<T,4,4>::v(7]);

				result.SetEntry(3,		tmp[5]*matbase<T,4,4>::v(4] + tmp[8]*matbase<T,4,4>::v(5] + tmp[11]*matbase<T,4,4>::v(6]
						-	tmp[4]*matbase<T,4,4>::v(4] - tmp[9]*matbase<T,4,4>::v(5] - tmp[10]*matbase<T,4,4>::v(6]);

				result.SetEntry(4,		tmp[1]*matbase<T,4,4>::v(1] + tmp[2]*matbase<T,4,4>::v(2] + tmp[5]*matbase<T,4,4>::v(3]
						-	tmp[0]*matbase<T,4,4>::v(1] - tmp[3]*matbase<T,4,4>::v(2] - tmp[4]*matbase<T,4,4>::v(3]);

				result.SetEntry(5,		tmp[0]*matbase<T,4,4>::v(0] + tmp[7]*matbase<T,4,4>::v(2] + tmp[8]*matbase<T,4,4>::v(3]
						-	tmp[1]*matbase<T,4,4>::v(0] - tmp[6]*matbase<T,4,4>::v(2] - tmp[9]*matbase<T,4,4>::v(3]);

				result.SetEntry(6,		tmp[3]*matbase<T,4,4>::v(0] + tmp[6]*matbase<T,4,4>::v(1] + tmp[11]*matbase<T,4,4>::v(3]
						-	tmp[2]*matbase<T,4,4>::v(0] - tmp[7]*matbase<T,4,4>::v(1] - tmp[10]*matbase<T,4,4>::v(3]);

				result.SetEntry(7,		tmp[4]*matbase<T,4,4>::v(0] + tmp[9]*matbase<T,4,4>::v(1] + tmp[10]*matbase<T,4,4>::v(2]
						-	tmp[5]*matbase<T,4,4>::v(0] - tmp[8]*matbase<T,4,4>::v(1] - tmp[11]*matbase<T,4,4>::v(2]);

				//calculate pairs for second 8 elements (cofactors)
				tmp[0] = matbase<T,4,4>::v(2]*matbase<T,4,4>::v(7];
				tmp[1] = matbase<T,4,4>::v(3]*matbase<T,4,4>::v(6];
				tmp[2] = matbase<T,4,4>::v(1]*matbase<T,4,4>::v(7];
				tmp[3] = matbase<T,4,4>::v(3]*matbase<T,4,4>::v(5];
				tmp[4] = matbase<T,4,4>::v(1]*matbase<T,4,4>::v(6];
				tmp[5] = matbase<T,4,4>::v(2]*matbase<T,4,4>::v(5];
				tmp[6] = matbase<T,4,4>::v(0]*matbase<T,4,4>::v(7];
				tmp[7] = matbase<T,4,4>::v(3]*matbase<T,4,4>::v(4];
				tmp[8] = matbase<T,4,4>::v(0]*matbase<T,4,4>::v(6];
				tmp[9] = matbase<T,4,4>::v(2]*matbase<T,4,4>::v(4];
				tmp[10] = matbase<T,4,4>::v(0]*matbase<T,4,4>::v(5];
				tmp[11] = matbase<T,4,4>::v(1]*matbase<T,4,4>::v(4];

				//calculate second 8 elements (cofactors)
				result.SetEntry(8,		tmp[0]*matbase<T,4,4>::v(13] + tmp[3]*matbase<T,4,4>::v(14] + tmp[4]*matbase<T,4,4>::v(15]
						-	tmp[1]*matbase<T,4,4>::v(13] - tmp[2]*matbase<T,4,4>::v(14] - tmp[5]*matbase<T,4,4>::v(15]);

				result.SetEntry(9,		tmp[1]*matbase<T,4,4>::v(12] + tmp[6]*matbase<T,4,4>::v(14] + tmp[9]*matbase<T,4,4>::v(15]
						-	tmp[0]*matbase<T,4,4>::v(12] - tmp[7]*matbase<T,4,4>::v(14] - tmp[8]*matbase<T,4,4>::v(15]);

				result.SetEntry(10,		tmp[2]*matbase<T,4,4>::v(12] + tmp[7]*matbase<T,4,4>::v(13] + tmp[10]*matbase<T,4,4>::v(15]
						-	tmp[3]*matbase<T,4,4>::v(12] - tmp[6]*matbase<T,4,4>::v(13] - tmp[11]*matbase<T,4,4>::v(15]);

				result.SetEntry(11,		tmp[5]*matbase<T,4,4>::v(12] + tmp[8]*matbase<T,4,4>::v(13] + tmp[11]*matbase<T,4,4>::v(14]
						-	tmp[4]*matbase<T,4,4>::v(12] - tmp[9]*matbase<T,4,4>::v(13] - tmp[10]*matbase<T,4,4>::v(14]);

				result.SetEntry(12,		tmp[2]*matbase<T,4,4>::v(10] + tmp[5]*matbase<T,4,4>::v(11] + tmp[1]*matbase<T,4,4>::v(9]
						-	tmp[4]*matbase<T,4,4>::v(11] - tmp[0]*matbase<T,4,4>::v(9] - tmp[3]*matbase<T,4,4>::v(10]);

				result.SetEntry(13,		tmp[8]*matbase<T,4,4>::v(11] + tmp[0]*matbase<T,4,4>::v(8] + tmp[7]*matbase<T,4,4>::v(10]
						-	tmp[6]*matbase<T,4,4>::v(10] - tmp[9]*matbase<T,4,4>::v(11] - tmp[1]*matbase<T,4,4>::v(8]);

				result.SetEntry(14,		tmp[6]*matbase<T,4,4>::v(9] + tmp[11]*matbase<T,4,4>::v(11] + tmp[3]*matbase<T,4,4>::v(8]
						-	tmp[10]*matbase<T,4,4>::v(11] - tmp[2]*matbase<T,4,4>::v(8] - tmp[7]*matbase<T,4,4>::v(9]);

				result.SetEntry(15,		tmp[10]*matbase<T,4,4>::v(10] + tmp[4]*matbase<T,4,4>::v(8] + tmp[9]*matbase<T,4,4>::v(9]
						-	tmp[8]*matbase<T,4,4>::v(9] - tmp[11]*matbase<T,4,4>::v(10] - tmp[5]*matbase<T,4,4>::v(8]);

				// calculate determinant
				det	=	 matbase<T,4,4>::v(0]*result.GetEntry(0)
					+matbase<T,4,4>::v(1]*result.GetEntry(1)
					+matbase<T,4,4>::v(2]*result.GetEntry(2)
					+matbase<T,4,4>::v(3]*result.GetEntry(3);

				if(det==0.0f)
				{
					mat44<T> id;
					return id;
				}

				result=result/det;

				return result;
			}
			void		AffineInvert(void)
			{
				(*this)=GetAffineInverse();
			}
			mat44<T>sGetAffineInverse(void) const
			{
				//return the transpose of the rotation part
				//and the negative of the inverse rotated translation part
				return math::mat44(
						matbase<T,4,4>::v(0],matbase<T,4,4>::v(4],matbase<T,4,4>::v(8],0.0f,
						matbase<T,4,4>::v(1],matbase<T,4,4>::v(5],matbase<T,4,4>::v(9],0.0f,
						matbase<T,4,4>::v(2],matbase<T,4,4>::v(6],matbase<T,4,4>::v(10],0.0f,
						-(matbase<T,4,4>::v(0]*matbase<T,4,4>::v(12]+matbase<T,4,4>::v(1]*matbase<T,4,4>::v(13]+matbase<T,4,4>::v(2]*matbase<T,4,4>::v(14]),
						-(matbase<T,4,4>::v(4]*matbase<T,4,4>::v(12]+matbase<T,4,4>::v(5]*matbase<T,4,4>::v(13]+matbase<T,4,4>::v(6]*matbase<T,4,4>::v(14]),
						-(matbase<T,4,4>::v(8]*matbase<T,4,4>::v(12]+matbase<T,4,4>::v(9]*matbase<T,4,4>::v(13]+matbase<T,4,4>::v(10]*matbase<T,4,4>::v(14]),
						1.0f);
			}
			void		AffineInvertTranspose(void)
			{
				(*this)=GetAffineInverseTranspose();
			}
			mat44<T>sGetAffineInverseTranspose(void) const
			{
				//return the transpose of the rotation part
				//and the negative of the inverse rotated translation part
				//transposed
				return math::mat44(	matbase<T,4,4>::v(0],
						matbase<T,4,4>::v(1],
						matbase<T,4,4>::v(2],
						-(matbase<T,4,4>::v(0]*matbase<T,4,4>::v(12]+matbase<T,4,4>::v(1]*matbase<T,4,4>::v(13]+matbase<T,4,4>::v(2]*matbase<T,4,4>::v(14]),
						matbase<T,4,4>::v(4],
						matbase<T,4,4>::v(5],
						matbase<T,4,4>::v(6],
						-(matbase<T,4,4>::v(4]*matbase<T,4,4>::v(12]+matbase<T,4,4>::v(5]*matbase<T,4,4>::v(13]+matbase<T,4,4>::v(6]*matbase<T,4,4>::v(14]),
						matbase<T,4,4>::v(8],
						matbase<T,4,4>::v(9],
						matbase<T,4,4>::v(10],
						-(matbase<T,4,4>::v(8]*matbase<T,4,4>::v(12]+matbase<T,4,4>::v(9]*matbase<T,4,4>::v(13]+matbase<T,4,4>::v(10]*matbase<T,4,4>::v(14]),
						0.0f, 0.0f, 0.0f, 1.0f);
			}
			void		SetTranslation(const vec3<double> & translation)
			{
				LoadIdentity();

				SetTranslationPart(translation);
			}
			void		SetScale(const vec3<double> & scaleFactor)
			{
				LoadIdentity();

				matbase<T,4,4>::v(0]=scaleFactor.v[0];
				matbase<T,4,4>::v(5]=scaleFactor.v[1];
				matbase<T,4,4>::v(10]=scaleFactor.v[2];
			}
			void		SetUniformScale(const float scaleFactor)
			{
				LoadIdentity();

				matbase<T,4,4>::v(0]=matbase<T,4,4>::v(5]=matbase<T,4,4>::v(10]=scaleFactor;
			}
			void		SetRotationAxis(const double angle, const vec3<double> & axis)
			{
				vec3<double> u=axis.GetNormalized();

				float sinAngle=(float)sin(M_PI*angle/180);
				float cosAngle=(float)cos(M_PI*angle/180);
				float oneMinusCosAngle=1.0f-cosAngle;

				LoadIdentity();

				matbase<T,4,4>::v(0]=(u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
				matbase<T,4,4>::v(4]=(u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
				matbase<T,4,4>::v(8]=(u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

				matbase<T,4,4>::v(1]=(u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
				matbase<T,4,4>::v(5]=(u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
				matbase<T,4,4>::v(9]=(u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

				matbase<T,4,4>::v(2]=(u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
				matbase<T,4,4>::v(6]=(u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
				matbase<T,4,4>::v(10]=(u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));
			}
			void		SetRotationX(const double angle)
			{
				LoadIdentity();

				matbase<T,4,4>::v(5]=(float)cos(M_PI*angle/180);
				matbase<T,4,4>::v(6]=(float)sin(M_PI*angle/180);

				matbase<T,4,4>::v(9]=-matbase<T,4,4>::v(6];
				matbase<T,4,4>::v(10]=matbase<T,4,4>::v(5];
			}
			void		SetRotationY(const double angle)
			{
				LoadIdentity();

				matbase<T,4,4>::v(0]=(float)cos(M_PI*angle/180);
				matbase<T,4,4>::v(2]=-(float)sin(M_PI*angle/180);

				matbase<T,4,4>::v(8]=-matbase<T,4,4>::v(2];
				matbase<T,4,4>::v(10]=matbase<T,4,4>::v(0];
			}
			void		SetRotationZ(const double angle)
			{
				LoadIdentity();

				matbase<T,4,4>::v(0]=(float)cos(M_PI*angle/180);
				matbase<T,4,4>::v(1]=(float)sin(M_PI*angle/180);

				matbase<T,4,4>::v(4]=-matbase<T,4,4>::v(1];
				matbase<T,4,4>::v(5]=matbase<T,4,4>::v(0];
			}
			void		SetRotationEuler(const double angleX, const double angleY, const double angleZ)
			{
				LoadIdentity();

				SetRotationPartEuler(angleX, angleY, angleZ);
			}
			void		SetPerspective(float left, float right, float bottom, float top, float n, float f)
			{
				float nudge=0.999f;		//prevent artifacts with infinite far plane

				LoadZero();

				//check for division by 0
				if(left==right || top==bottom || n==f)
				{
					printf("invalid perspective");
					exit(0);
				}
				matbase<T,4,4>::v(0]=(2*n)/(right-left);

				matbase<T,4,4>::v(5]=(2*n)/(top-bottom);

				matbase<T,4,4>::v(8]=(right+left)/(right-left);
				matbase<T,4,4>::v(9]=(top+bottom)/(top-bottom);

				if(f!=-1)
				{
					matbase<T,4,4>::v(10]=-(f+n)/(f-n);
				}
				else		//if f==-1, use an infinite far plane
				{
					matbase<T,4,4>::v(10]=-nudge;
				}

				matbase<T,4,4>::v(11]=-1;

				if(f!=-1)
				{
					matbase<T,4,4>::v(14]=-(2*f*n)/(f-n);
				}
				else		//if f==-1, use an infinite far plane
				{
					matbase<T,4,4>::v(14]=-2*n*nudge;
				}
			}
			void		SetPerspective(float fovy, float aspect, float n, float f)
			{
				float left, right, top, bottom;

				//convert fov from degrees to radians
				fovy *= (float)M_PI / 180.0f;

				top = n*tanf(fovy/2.0f);
				bottom=-top;

				left=aspect*bottom;
				right=aspect*top;

				SetPerspective(left, right, bottom, top, n, f);
			}
			void		SetOrtho(	float left, float right, float bottom, float top, float n, float f)
			{
				LoadIdentity();

				matbase<T,4,4>::v(0]=2.0f/(right-left);

				matbase<T,4,4>::v(5]=2.0f/(top-bottom);

				matbase<T,4,4>::v(10]=-2.0f/(f-n);

				matbase<T,4,4>::v(12]=-(right+left)/(right-left);
				matbase<T,4,4>::v(13]=-(top+bottom)/(top-bottom);
				matbase<T,4,4>::v(14]=-(f+n)/(f-n);
			}
			void		SetTranslationPart(const vec3<double> & translation)
			{
				matbase<T,4,4>::v(12]=translation.v[0];
				matbase<T,4,4>::v(13]=translation.v[1];
				matbase<T,4,4>::v(14]=translation.v[2];
			}
			void		SetRotationPartEuler(const double angleX, const double angleY, const double angleZ)
			{
				double cr = cos( M_PI*angleX/180 );
				double sr = sin( M_PI*angleX/180 );
				double cp = cos( M_PI*angleY/180 );
				double sp = sin( M_PI*angleY/180 );
				double cy = cos( M_PI*angleZ/180 );
				double sy = sin( M_PI*angleZ/180 );

				matbase<T,4,4>::v(0] = ( float )( cp*cy );
				matbase<T,4,4>::v(1] = ( float )( cp*sy );
				matbase<T,4,4>::v(2] = ( float )( -sp );

				double srsp = sr*sp;
				double crsp = cr*sp;

				matbase<T,4,4>::v(4] = ( float )( srsp*cy-cr*sy );
				matbase<T,4,4>::v(5] = ( float )( srsp*sy+cr*cy );
				matbase<T,4,4>::v(6] = ( float )( sr*cp );

				matbase<T,4,4>::v(8] = ( float )( crsp*cy+sr*sy );
				matbase<T,4,4>::v(9] = ( float )( crsp*sy-sr*cy );
				matbase<T,4,4>::v(10] = ( float )( cr*cp );
			}
			void		RotateVector3D(math::vec3<double> & rhs) const {
				rhs=GetRotatedVector3D(rhs);
			}
			void		InverseRotateVector3D(math::vec3<double> & rhs) const
			{
				rhs=GetInverseRotatedVector3D(rhs);
			}
			void		TranslateVector3D(vec3<double> & rhs) const
			{
				rhs=GetTranslatedVector3D(rhs);
			}
			void		InverseTranslateVector3D(vec3<double> & rhs) const
			{
				rhs=GetInverseTranslatedVector3D(rhs);
			}
			void		SetRotationPartEuler(const math::vec3<double> & rotations)
			{
				SetRotationPartEuler((double)rotations.v[0], (double)rotations.v[1], (double)rotations.v[2]);
			}
			mat44<T>	lookat(math::vec3<double> eye, math::vec3<double> center, math::vec3<double> up) {
				vec3<double> F = center - eye;
				vec3<double> f = F.GetNormalized();

				vec3<double> UP = up.GetNormalized();

				vec3<double> s = f.cross(UP);
				s.Normalize();

				vec3<double> u = s.cross(f);

				//printf("u\n");
				//u.print();

				mat44 M(
						s.v[0],  u.v[0],  -f.v[0] , 0.0f,
						s.v[1],  u.v[1],  -f.v[1] , 0.0f,
						s.v[2],  u.v[2],  -f.v[2] , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

				//	M.print();

				mat44 T;
				T.SetTranslation(-eye);

				//printf("M\n");
				//M.print();
				//printf("T\n");
				//T.print();

				//return T*M;
				return M*T;
			}
			void	SetReflection(math::plane<T> const & p)
			{
				math::vec3<double> n = p.n.GetNormalized();

				mat44<T> A;
				A.SetTranslation(n * -p.d);

				mat44<T> I;

				mat44<T> RA = I - math::vec4<T>(n,0) * math::vec4<T>(n,0) * 2.0;

				//*this = A * RA * A.GetInverse();
				*this = A.GetInverse() * RA * A;
			}
			void	print()
			{
				for(int i = 0; i < 4; ++i )
				{
					for(int j = 0; j < 4; ++j )
					{
						printf("%f ",matbase<T,4,4>::v(4*i+j]);
					}
					printf("\n");
				}
			}
			void	SetCoordinateTransform(math::vec3<double> const x, math::vec3<double> const y)
			{


				math::vec3<double> Z = x.cross(y);

				math::vec3<double> X = y.cross(Z);

				X.Normalize();
				math::vec3<double> Y = y.GetNormalized();
				Z.Normalize();

				mat44<T> m(
						X.v[0],  Y.v[0],  Z.v[0] , 0.0f,
						X.v[1],  Y.v[1],  Z.v[1] , 0.0f,
						X.v[2],  Y.v[2],  Z.v[2] , 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

				*this = m;
			}







			mat44(
					T, T, T, T, T, T, T, T,
					T, T, T, T, T, T, T, T);
			mat44(const T * rhs);
						~mat44() {}	//empty

			void SetEntry(int position, T value);

			//unary operators
			mat44	operator+(void) const {return (*this);}


			//cast to pointer to a (T *) for glGetFloatv etc
			operator T* () const {return (T*) this;}
			operator const T* () const {return (const T*) this;}

			//member variables
			//T matbase<T,4,4>::v(16];
	};

	//mat44	perspective(T fovy, T aspect, T zn, T zf);
	//mat44	lookat(math::vec3<double> eye, math::vec3<double> center, math::vec3<double> up);

}

#endif	//mat44_H
