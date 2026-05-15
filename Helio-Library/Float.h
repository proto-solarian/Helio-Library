#pragma once

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
