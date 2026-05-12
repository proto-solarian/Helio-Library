#pragma once

#include <math.h> // for sqrt.

constexpr static float Call(float (*stdFunc)(float), float in);

/// <summary>
/// Required to call standard functions from header lib
/// </summary>
inline constexpr static float Call(float (*stdFunc)(float), float in)
{
    return stdFunc(in);
}