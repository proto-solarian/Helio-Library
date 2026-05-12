#pragma once

#include "StdUtil.h"

inline constexpr Float3::Float3()
    : x(0.0f), y(0.0f), z(0.0f)
{}

inline constexpr Float3::Float3(float x, float y, float z)
    : x(x), y(y), z(z)
{}

inline constexpr Float3::Float3(const Float3& o)
    : x(o.x), y(o.y), z(o.z)
{}

inline constexpr Float3::~Float3()
{}

/*
    Arithmetic
*/
inline constexpr Float3& Float3::operator=(const Float3& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

inline constexpr Float3& Float3::operator+=(const Float3& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

inline constexpr Float3& Float3::operator-=(const Float3& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

inline constexpr Float3& Float3::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

inline constexpr Float3& Float3::operator/=(const float rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

inline constexpr Float3 Float3::operator+(const Float3& rhs) const
{
    return Float3(x + rhs.x, y + rhs.y, z + rhs.z);
}

inline constexpr Float3 Float3::operator-(const Float3& rhs) const
{
    return Float3(x - rhs.x, y - rhs.y, z - rhs.z);
}

inline constexpr Float3 Float3::operator*(const float scalar) const
{
    return Float3(x * scalar, y * scalar, z * scalar);
}

inline constexpr Float3 Float3::operator/(const float scalar) const
{
    return this->operator*(1.0f / scalar);
}

inline constexpr bool Float3::operator==(const Float3& rhs) const
{
    return x == rhs.x &&
        y == rhs.y &&
        z == rhs.z;
}

inline constexpr bool Float3::operator!=(const Float3& rhs) const
{
    return !(*this == rhs);
}

inline constexpr float Float3::Dot(const Float3& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

inline constexpr Float3 Float3::Cross(const Float3& other) const
{
    return Float3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x);
}

inline constexpr float Float3::SqrMagnitude() const
{
    return Dot(*this);
}

inline constexpr float Float3::Magnitude() const
{
    return Call(sqrtf, SqrMagnitude());
}

inline constexpr Float3 Float3::Normalized() const
{
    float magnitude = Magnitude();
    return Float3(x / magnitude, y / magnitude, z / magnitude);
}

void constexpr Float3::Normalize()
{
    float magnitude = Magnitude();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}

/// <summary>
/// Projects this vector onto another vector.
/// Assumes the target is not normalized. Use `ProjectOnNormal` if `target` is already normalized.
/// </summary>
/// <param name="target">A non-normalized target vector.</param>
/// <returns>The non-normalized projection onto target.</returns>
inline constexpr Float3 Float3::ProjectOnTarget(const Float3& target) const
{
    Float3 targetNormalized = target.Normalized();
    return targetNormalized * Dot(targetNormalized);
}

/// <summary>
/// Projects this vector onto a target normal.
/// </summary>
/// <param name="normal">A normalized target vector.</param>
/// <returns>The non-normalized projection onto target.</returns>
inline constexpr Float3 Float3::ProjectOnNormal(const Float3& normal) const
{
    return normal * Dot(normal);
}

inline constexpr Float3 Float3::ReflectOnNormal(const Float3& normal) const
{
    return normal * Dot(normal) * 2.0f - *this;
}
