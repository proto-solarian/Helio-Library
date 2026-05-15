#pragma once

#include "Float.h"
#include "Float3.h"

struct Triangle
{
public:
    static constexpr float Area(const Float3& p0, const Float3& p1, const Float3& p2);
    static constexpr Float3 BarycentricWeights(const Triangle& triangle, const Float3& point);
    static constexpr bool PointInTriangle(const Triangle& triangle, const Float3& point);

    Float3 p0;
    Float3 p1;
    Float3 p2;

    constexpr Triangle(const Float3& p0, const Float3& p1, const Float3& p2)
        : p0(p0), p1(p1), p2(p2)
    {}

    constexpr float Area() const;
    constexpr Float3 BarycentricWeights(const Float3& point) const;
    constexpr bool PointInTriangle(const Float3& point) const;
};

/*
* Static definitions.
*/
inline constexpr float Triangle::Area(const Float3& p0, const Float3& p1, const Float3& p2)
{
    Float3 e0 = p1 - p0; // ctor call
    Float3 e1 = p2 - p0; // ctor call
    return e0.Cross(e1).Magnitude() * 0.5f;
}

inline constexpr Float3 Triangle::BarycentricWeights(const Triangle& triangle, const Float3& point)
{
    float area = triangle.Area();
    float w0 = Triangle::Area(triangle.p1, triangle.p2, point) / area;
    float w1 = Triangle::Area(triangle.p2, triangle.p0, point) / area;
    float w2 = Triangle::Area(triangle.p0, triangle.p1, point) / area;
    return Float3(w0, w1, w2);
}

inline constexpr bool Triangle::PointInTriangle(const Triangle& triangle, const Float3& point)
{
    Float3 weights = BarycentricWeights(triangle, point);
    return IsApproximatelyEqual(weights.x + weights.y + weights.z, 1.0f);
}

/*
* Member definitions.
*/
inline constexpr float Triangle::Area() const
{
    Float3 e0 = p1 - p0; // ctor call
    Float3 e1 = p2 - p0; // ctor call
    return e0.Cross(e1).Magnitude() * 0.5f;
}

inline constexpr Float3 Triangle::BarycentricWeights(const Float3& point) const
{
    float area = Area();
    float w0 = Triangle::Area(p1, p2, point) / area;
    float w1 = Triangle::Area(p2, p0, point) / area;
    float w2 = Triangle::Area(p0, p1, point) / area;
    return Float3(w0, w1, w2);
}

/// Barycentric weights calculated with the matrix method
//inline constexpr Float3 Triangle::BarycentricWeights(Triangle tri, Float3 point)
//{
//    Matrix4x4 t = new Matrix4x4(
//        new Float3(tri.p0.x - tri.p2.x, tri.p0.y - tri.p2.y, tri.p0.z - tri.p2.z, 0.0f),
//        new Float3(tri.p1.x - tri.p2.x, tri.p1.y - tri.p2.y, tri.p1.z - tri.p2.z, 0.0f),
//        new Float3(0.0f, 0.0f, 1.0f, 0.0f),
//        new Float3(0.0f, 0.0f, 0.0f, 1.0f));
//    Float3 weights = t.inverse * (point - tri.p2);
//    weights.z = 1.0f - weights.x - weights.y;
//    return weights;
//}

inline constexpr bool Triangle::PointInTriangle(const Float3& point) const
{
    Float3 weights = BarycentricWeights(point);
    return IsApproximatelyEqual(weights.x + weights.y + weights.z, 1.0f);
}
