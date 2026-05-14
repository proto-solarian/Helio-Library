#pragma once

#include <math.h> // for sqrt.

constexpr static float Call(float (*stdFunc)(float), float a);
constexpr static float Call(float (*stdFunc)(float, float), float a, float b);

/// <summary>
/// Required to call standard functions from header lib
/// </summary>
inline constexpr static float Call(float (*stdFunc)(float), float a)
{
    return stdFunc(a);
}

/// <summary>
/// Required to call standard functions from header lib
/// </summary>
inline constexpr static float Call(float (*stdFunc)(float, float), float a, float b)
{
    return stdFunc(a, b);
}