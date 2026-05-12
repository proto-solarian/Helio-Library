#pragma once

#include <math.h>

struct Float3
{
public:
    float x;
    float y;
    float z;

    constexpr Float3();
    constexpr Float3(float x, float y, float z);
    constexpr Float3(const Float3& o);
    constexpr ~Float3();

    constexpr Float3& operator=(const Float3& other);
    constexpr Float3& operator+=(const Float3& other);
    constexpr Float3& operator-=(const Float3& other);
    constexpr Float3& operator*=(const float other);
    constexpr Float3& operator/=(const float other);

    constexpr Float3 operator+(const Float3& rhs) const;
    constexpr Float3 operator-(const Float3& rhs) const;
    constexpr Float3 operator*(const float rhs) const;
    constexpr Float3 operator/(const float rhs) const;

    constexpr float Dot(const Float3& other) const;
    constexpr Float3 Cross(const Float3& other) const;
    constexpr float SqrMagnitude() const;
    constexpr float Magnitude() const;
    constexpr Float3 Normalized() const;
    constexpr void Normalize();
    constexpr Float3 ProjectOnTarget(const Float3& target) const;
    constexpr Float3 ProjectOnNormal(const Float3& normal) const;
    constexpr Float3 ReflectOnNormal(const Float3& normal) const;
};

#include "Float3.inl"
