#pragma once

#include "Float2.h"
#include "Float3.h"
#include "SphereCoords.h"

/// <summary>
/// ©‘R”-•„†–³‚µ (0 to N_MAX)
/// </summary>
using N64 = unsigned long long int;
const N64 N64_MAX = 0xffffffffffffffffui64;

/// <summary>
/// ®” (-Z_MAX to Z_MAX)
/// </summary>
using Z64 = long long int;
const Z64 Z64_MAX = 9223372036854775807i64;
const Z64 Z64_MIN = -9223372036854775808i64;

const float PI = 3.1415926535f;


const float EPSILON = 0.00000001f;

inline constexpr float AbsoluteValue(float a)
{
    return a >= 0 ? a : -a;
}

inline constexpr bool IsApproximatelyZero(float a)
{
    return AbsoluteValue(a) < EPSILON;
}

inline constexpr bool IsApproximatelyEqual(float a, float b)
{
    return AbsoluteValue(a - b) < EPSILON;
}
