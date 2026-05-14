#pragma once

#include "HMath.h"
#include "Float2.h"
#include "Float3.h"
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
