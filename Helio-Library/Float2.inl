#pragma once

#include "StdUtil.h"

inline constexpr Float2::Float2()
    : x(0.0f), y(0.0f)
{}

inline constexpr Float2::Float2(float x, float y)
    : x(x), y(y)
{}

inline constexpr Float2::Float2(const Float2& o)
    : x(o.x), y(o.y)
{}

inline constexpr Float2::~Float2()
{}

/*
    Arithmetic
*/
inline constexpr Float2& Float2::operator=(const Float2& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x = rhs.x;
    y = rhs.y;
    return *this;
}

inline constexpr Float2& Float2::operator+=(const Float2& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x += rhs.x;
    y += rhs.y;
    return *this;
}

inline constexpr Float2& Float2::operator-=(const Float2& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

inline constexpr Float2& Float2::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    return *this;
}

inline constexpr Float2& Float2::operator/=(const float rhs)
{
    x /= rhs;
    y /= rhs;
    return *this;
}

inline constexpr Float2 Float2::operator+(const Float2& rhs) const
{
    return Float2(x + rhs.x, y + rhs.y);
}

inline constexpr Float2 Float2::operator-(const Float2& rhs) const
{
    return Float2(x - rhs.x, y - rhs.y);
}

inline constexpr Float2 Float2::operator*(const float scalar) const
{
    return Float2(x * scalar, y * scalar);
}

inline constexpr Float2 Float2::operator/(const float scalar) const
{
    return this->operator*(1.0f / scalar);
}

inline constexpr float Float2::Dot(const Float2& other) const
{
    return x * other.x + y * other.y;
}

inline constexpr float Float2::SqrMagnitude() const
{
    return Dot(*this);
}

inline constexpr float Float2::Magnitude() const
{
    return Call(sqrtf, SqrMagnitude());
}

inline constexpr Float2 Float2::Normalized() const
{
    float magnitude = Magnitude();
    return Float2(x / magnitude, y / magnitude);
}

void constexpr Float2::Normalize()
{
    float magnitude = Magnitude();
    x /= magnitude;
    y /= magnitude;
}

/// <summary>
/// Projects this vector onto another vector.
/// Assumes the target is not normalized. Use `ProjectOnNormal` if `target` is already normalized.
/// </summary>
/// <param name="target">A non-normalized target vector.</param>
/// <returns>The non-normalized projection onto target.</returns>
inline constexpr Float2 Float2::ProjectOnTarget(const Float2& target) const
{
    Float2 targetNormalized = target.Normalized();
    return targetNormalized * Dot(targetNormalized);
}

/// <summary>
/// Projects this vector onto a target normal.
/// </summary>
/// <param name="normal">A normalized target vector.</param>
/// <returns>The non-normalized projection onto target.</returns>
inline constexpr Float2 Float2::ProjectOnNormal(const Float2& normal) const
{
    return normal * Dot(normal);
}

inline constexpr Float2 Float2::ReflectOnNormal(const Float2& normal) const
{
    return normal * Dot(normal) * 2.0f - *this;
}
