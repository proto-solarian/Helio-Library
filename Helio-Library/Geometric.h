#pragma once

#include "HMath.h"
#include "Float2.h"
#include "Float3.h"
#include "SphereCoords.h"
#include "Triangle.h"

#include "StdUtil.h"

inline constexpr Float2 LookDirToSpheremapCoords(const Float3& lookDir)
{
    float theta = Call(
        atan2f,
        lookDir.z,
        lookDir.x);
    float x = (theta + PI) / (2.0f * PI);
    float phi = Call(
        atan2f,
        Float2(lookDir.x, lookDir.z).Magnitude(),
        lookDir.y);
    float y = -phi / PI;
    return Float2(x, y);
}

// TODO: implement lookdir to cubemap coords. 

inline constexpr Float3 ToCartesianCoords(const SphereCoords& sphereCoords)
{
    float y = Call(cosf, sphereCoords.phi) * sphereCoords.radius;
    float xzLength = Call(sinf, sphereCoords.phi);
    float x = Call(cosf, sphereCoords.theta) * xzLength;
    float z = Call(sinf, sphereCoords.theta) * xzLength;
    return Float3(x, y, z);
}

inline constexpr SphereCoords FromCartesianCoords(const Float3& cartesian)
{
    float theta = Call(atan2f, cartesian.z, cartesian.x);
    float xzLength = Call(sqrtf, cartesian.x * cartesian.x + cartesian.z * cartesian.z);
    float phi = Call(atan2f, xzLength, cartesian.y);
    float radius = cartesian.Magnitude();
    return SphereCoords(radius, theta, phi);
}

/// <summary>
/// Calculates the barycentric weights for a point in a triangle using the subtriangle method.
/// </summary>
/// <param name="tri"></param>
/// <param name="point"></param>
/// <returns></returns>
inline constexpr Float3 BarycentricWeights(const Triangle& triangle, const Float3& point)
{
    float area = triangle.Area();
    float w0 = Triangle::Area(triangle.p1, triangle.p2, point) / area;
    float w1 = Triangle::Area(triangle.p0, triangle.p2, point) / area;
    float w2 = Triangle::Area(triangle.p1, triangle.p0, point) / area;
    return Float3(w0, w1, w2);
}

/// <summary>
/// Calculates the barycentric weights for a point in a triangle using the matrix method.
/// </summary>
/// <param name="tri"></param>
/// <param name="point"></param>
/// <returns></returns>
//Float3 BarycentricWeights(Triangle tri, Float3 point)
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
