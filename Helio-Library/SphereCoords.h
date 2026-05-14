#pragma once

#include "Float3.h"
#include "StdUtil.h"

/// <summary>
/// Constructs a point in space via a radius, an azimuthal angle theta, and a polar angle phi.
/// Angles are in radians.
/// </summary>
struct SphereCoords
{
public:
    float radius;
    float theta;
    float phi;
    
    constexpr Float3 ToCartesianCoords();

    inline constexpr Float3 ToCartesianCoords()
    {
        Float3 coords;
        coords.y = Call(cosf, phi) * radius;
        float xzLength = Call(sinf, phi);
        coords.x = Call(cosf, theta) * xzLength;
        coords.z = Call(sinf, theta) * xzLength;
        return coords;
    }
};