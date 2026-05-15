#pragma once

/// <summary>
/// Quaternions are useful for encoding rotations.
/// TODO: In larger projects, it might be wise to remove +, -, and / to avoid confusion.
/// </summary>
struct Quaternion
{
public:
    float a;
    float b;
    float c;
    float d;

    constexpr Quaternion();
    constexpr Quaternion(float a, float b, float c, float d);

    constexpr Quaternion& operator=(const Quaternion& other);
    constexpr Quaternion& operator+=(const Quaternion& other);
    constexpr Quaternion& operator-=(const Quaternion& other);
    constexpr Quaternion& operator*=(const Quaternion& other);
    constexpr Quaternion& operator/=(const Quaternion& other);

    constexpr Quaternion operator+(const Quaternion& rhs) const;
    constexpr Quaternion operator-(const Quaternion& rhs) const;
    constexpr Quaternion operator*(const Quaternion& rhs) const;
    constexpr Quaternion operator/(const Quaternion& rhs) const;
    
    constexpr bool operator==(const Quaternion& rhs) const;
    constexpr bool operator!=(const Quaternion& rhs) const;
    // TODO: Quaternion AngleAxis constructor
};

#include "Quaternion.inl"
