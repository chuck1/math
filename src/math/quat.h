// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2008-2013 NVIDIA Corporation. All rights reserved.
// Copyright (c) 2004-2008 AGEIA Technologies, Inc. All rights reserved.
// Copyright (c) 2001-2004 NovodeX AG. All rights reserved.  



#ifndef __QUAT_H__
#define __QUAT_H__

namespace math
{
	class vec3;
	class mat33;

	class quat
	{
		public:
			quat();
			quat(float nx, float ny, float nz, float nw);
			quat(float angleRadians, vec3 const & axis);
			quat(quat const & v);
			quat(vec3 const &, vec3 const &);
			quat(mat33 const & m);

			bool	isFinite() const;
			/**
			  \brief returns true if finite and magnitude is close to unit
			  */
			bool	isUnit() const;
			/**
			  \brief returns true if finite and magnitude is reasonably close to unit to allow for some accumulation of error vs isValid
			  */

			bool	isSane() const;

			/**
			  \brief converts this quaternion to angle-axis representation
			  */

			void toRadiansAndUnitAxis(float& angle, vec3& axis) const;
			float getAngle() const;
			float getAngle(const quat& q) const;
			float magnitudeSquared() const;
			float dot(const quat& v) const;
			quat getNormalized() const;
			float magnitude() const;
			float normalize();
			quat getConjugate() const;
			vec3 getImaginaryPart() const;
			vec3 getBasisVector0()	const;
			vec3 getBasisVector1()	const;
			vec3 getBasisVector2() const;
			const vec3	rotate(const vec3& v) const;
			const vec3	rotateInv(const vec3& v) const;
			quat&		operator=(const quat& p);
			quat&		operator*= (const quat& q);
			quat&		operator+= (const quat& q);
			quat&		operator-= (const quat& q);
			quat&		operator*= (const float s);
			quat operator*(const quat& q) const;
			quat operator+(const quat& q) const;
			quat operator-() const;
			quat operator-(const quat& q) const;
			quat operator*(float r) const;
			static quat createIdentity();
			float x,y,z,w;
	};
}

/** @} */
#endif // PX_FOUNDATION_PX_QUAT_H
