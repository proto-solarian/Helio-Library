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
    
    constexpr SphereCoords();
    constexpr SphereCoords(float radius, float theta, float phi);
};

inline constexpr SphereCoords::SphereCoords()
    : radius(1.0f), theta(0.0f), phi(0.0f)
{}

inline constexpr SphereCoords::SphereCoords(float radius, float theta, float phi)
    : radius(radius), theta(theta), phi(phi)
{}
