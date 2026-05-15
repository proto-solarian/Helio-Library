#pragma once

#include "HMath.h"
#include "Float2.h"
#include "Float3.h"
#include "SphereCoords.h"

#include "StdUtil.h"

inline constexpr Float2 LookDirToSpheremapCoords(Float3 lookDir)
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
