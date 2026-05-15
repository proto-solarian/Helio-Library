#pragma once

#include "Float3.h"

struct Triangle
{
public:
    static constexpr float Area(const Float3& p0, const Float3& p1, const Float3& p2);

    Float3 p0;
    Float3 p1;
    Float3 p2;

    constexpr Triangle(const Float3& p0, const Float3& p1, const Float3& p2)
        : p0(p0), p1(p1), p2(p2)
    {}

    constexpr float Area() const;
};

inline constexpr float Triangle::Area(const Float3& p0, const Float3& p1, const Float3& p2)
{
    Float3 e0 = p1 - p0; // ctor call
    Float3 e1 = p2 - p0; // ctor call
    return e0.Cross(e1).Magnitude() * 0.5f;
}

inline constexpr float Triangle::Area() const
{
    Float3 e0 = p1 - p0; // ctor call
    Float3 e1 = p2 - p0; // ctor call
    return e0.Cross(e1).Magnitude() * 0.5f;
}
