#pragma once

const float EPSILON = 0.00000001f;

inline constexpr float AbsoluteValue(float a)
{
    return a >= 0 ? a : -a;
}

inline constexpr bool IsNearlyEqual(float a, float b)
{
    return AbsoluteValue(a - b) < EPSILON;
}
