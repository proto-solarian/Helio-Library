#pragma once

struct Float2
{
public:
    float x;
    float y;

    constexpr Float2();
    constexpr Float2(float x, float y);
    constexpr Float2(const Float2& o);

    constexpr Float2& operator=(const Float2& other);
    constexpr Float2& operator+=(const Float2& other);
    constexpr Float2& operator-=(const Float2& other);
    constexpr Float2& operator*=(const float other);
    constexpr Float2& operator/=(const float other);

    constexpr Float2 operator+(const Float2& rhs) const;
    constexpr Float2 operator-(const Float2& rhs) const;
    constexpr Float2 operator*(const float rhs) const;
    constexpr Float2 operator/(const float rhs) const;

    constexpr bool operator==(const Float2& rhs) const;
    constexpr bool operator!=(const Float2& rhs) const;

    constexpr float Dot(const Float2& other) const;
    constexpr float SqrMagnitude() const;
    constexpr float Magnitude() const;
    constexpr Float2 Normalized() const;
    constexpr void Normalize();
    constexpr Float2 ProjectOnTarget(const Float2& target) const;
    constexpr Float2 ProjectOnNormal(const Float2& normal) const;
    constexpr Float2 ReflectOnNormal(const Float2& normal) const;
};

#include "Float2.inl"
