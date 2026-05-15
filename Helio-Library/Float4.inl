#pragma once

#include "StdUtil.h"

inline constexpr Float4::Float4()
    : x(0.0f), y(0.0f), z(0.0f)
{}

inline constexpr Float4::Float4(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
{}

inline constexpr Float4::Float4(const Float4& o)
    : x(o.x), y(o.y), z(o.z), w(o.w)
{}

/*
    Arithmetic
*/
inline constexpr Float4& Float4::operator=(const Float4& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
    return *this;
}

inline constexpr Float4& Float4::operator+=(const Float4& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

inline constexpr Float4& Float4::operator-=(const Float4& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

inline constexpr Float4& Float4::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
    return *this;
}

inline constexpr Float4& Float4::operator/=(const float rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return *this;
}

inline constexpr Float4 Float4::operator+(const Float4& rhs) const
{
    return Float4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

inline constexpr Float4 Float4::operator-(const Float4& rhs) const
{
    return Float4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

inline constexpr Float4 Float4::operator*(const float scalar) const
{
    return Float4(x * scalar, y * scalar, z * scalar, w * scalar);
}

inline constexpr Float4 Float4::operator/(const float scalar) const
{
    return this->operator*(1.0f / scalar);
}

inline constexpr bool Float4::operator==(const Float4& rhs) const
{
    return x == rhs.x &&
        y == rhs.y &&
        z == rhs.z &&
        w == rhs.w;
}

inline constexpr bool Float4::operator!=(const Float4& rhs) const
{
    return !(*this == rhs);
}

inline constexpr float Float4::Dot(const Float4& other) const
{
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

inline constexpr float Float4::SqrMagnitude() const
{
    return Dot(*this);
}

inline constexpr float Float4::Magnitude() const
{
    return Call(sqrtf, SqrMagnitude());
}

inline constexpr Float4 Float4::Normalized() const
{
    float magnitude = Magnitude();
    return Float4(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}

void constexpr Float4::Normalize()
{
    float magnitude = Magnitude();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
}

/// <summary>
/// Projects this vector onto another vector.
/// Assumes the target is not normalized. Use `ProjectOnNormal` if `target` is already normalized.
/// </summary>
/// <param name="target">A non-normalized target vector.</param>
/// <returns>The non-normalized projection onto target.</returns>
inline constexpr Float4 Float4::ProjectOnTarget(const Float4& target) const
{
    Float4 targetNormalized = target.Normalized();
    return targetNormalized * Dot(targetNormalized);
}

/// <summary>
/// Projects this vector onto a target normal.
/// </summary>
/// <param name="normal">A normalized target vector.</param>
/// <returns>The non-normalized projection onto target.</returns>
inline constexpr Float4 Float4::ProjectOnNormal(const Float4& normal) const
{
    return normal * Dot(normal);
}

inline constexpr Float4 Float4::ReflectOnNormal(const Float4& normal) const
{
    return normal * Dot(normal) * 2.0f - *this;
}
