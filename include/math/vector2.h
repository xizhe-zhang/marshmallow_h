/*
 * Copyright 2011-2012 Marshmallow Engine. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MARSHMALLOW ENGINE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MARSHMALLOW ENGINE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Marshmallow Engine.
 */

#pragma once

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#ifndef MARSHMALLOW_MATH_VECTOR2_H
#define MARSHMALLOW_MATH_VECTOR2_H 1

#include <core/environment.h>
#include <core/namespace.h>

/* Box2D */
#if MARSHMALLOW_WITH_BOX2D
struct b2Vec2;
#endif

MARSHMALLOW_NAMESPACE_BEGIN

namespace Math
{
	/*! @brief 2D Vector */
	class MARSHMALLOW_MATH_EXPORT
	Vector2
	{
		float m_value[2];
	public:
		Vector2(float x = 0.f, float y = 0.f);
		Vector2(const Vector2 &copy);

		const float & x(void) const
		    { return(m_value[0]); }
		const float & y(void) const
		    { return(m_value[1]); }

		Vector2 normalized(const float *magnitude = 0) const;
		Vector2 & normalize(const float *magnitude = 0);

		float magnitude(void) const;
		float magnitude2(void) const;

		float cross(const Vector2 &b) const;
		float dot(const Vector2 &b) const;

	public: /* operators */

		Vector2 & operator=(const Vector2 &rhs);
		bool operator==(const Vector2 &rhs) const;

		float & operator[](int i)
		    { return(m_value[i % 2]); }

		const float & operator[](int i) const
		    { return(m_value[i % 2]); }

		operator bool(void) const
		    { return(m_value[0] || m_value[1]); }

		Vector2 & operator*=(float rhs);
		Vector2 & operator-=(float rhs);
		Vector2 & operator+=(float rhs);

		Vector2 & operator*=(const Vector2 &rhs);
		Vector2 & operator+=(const Vector2 &rhs);
		Vector2 & operator-=(const Vector2 &rhs);

		Vector2 operator*(float rhs) const;
		Vector2 operator+(float rhs) const;
		Vector2 operator-(float rhs) const;

		Vector2 operator*(const Vector2 &rhs) const;
		Vector2 operator+(const Vector2 &rhs) const;
		Vector2 operator-(const Vector2 &rhs) const;

#if MARSHMALLOW_WITH_BOX2D
		operator b2Vec2(void) const;
#endif

	public: /* static */

		static const Vector2 & Zero(void)
		    { static Vector2 s_zero(0.f, 0.f);
		      return(s_zero); }

		static const Vector2 & Identity(void)
		    { static Vector2 s_identity(1.f, 1.f);
		      return(s_identity); }
	};
}

MARSHMALLOW_NAMESPACE_END

#endif