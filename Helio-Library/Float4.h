#pragma once

struct Float4
{
public:
    float x;
    float y;
    float z;
    float w;

    constexpr Float4();
    constexpr Float4(float x, float y, float z, float w);
    constexpr Float4(const Float4& o);

    constexpr Float4& operator=(const Float4& rhs);
    constexpr Float4& operator+=(const Float4& rhs);
    constexpr Float4& operator-=(const Float4& rhs);
    constexpr Float4& operator*=(const float rhs);
    constexpr Float4& operator/=(const float rhs);

    constexpr Float4 operator+(const Float4& rhs) const;
    constexpr Float4 operator-(const Float4& rhs) const;
    constexpr Float4 operator*(const float scalar) const;
    constexpr Float4 operator/(const float scalar) const;

    constexpr bool operator==(const Float4& rhs) const;
    constexpr bool operator!=(const Float4& rhs) const;

    constexpr float Dot(const Float4& other) const;
    constexpr float SqrMagnitude() const;
    constexpr float Magnitude() const;
    constexpr Float4 Normalized() const;
    constexpr void Normalize();
    constexpr Float4 ProjectOnTarget(const Float4& target) const;
    constexpr Float4 ProjectOnNormal(const Float4& normal) const;
    constexpr Float4 ReflectOnNormal(const Float4& normal) const;
};

#include "Float4.inl"
