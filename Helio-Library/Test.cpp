#include "Helio.h"

#include <iostream>

int main()
{
    Float3 n(0.0f, 1.0f, 0.0f);
    Float3 v(1.0f, 1.0f, 0.0f);
    float initMagnitude = v.Magnitude();
    v.Normalize();
    float postNormalizeMagnitude = v.Magnitude();
    float dot = n.Dot(v);
    Float3 proj = n * dot;
    Float3 projOnTgt = v.ProjectOnTarget(n);
    // assert proj == projOnTgt
    Float3 perp = v - proj;
    Float3 perpNormalized = perp.Normalized();
    Float3 reflected = proj * 2.0f - v;
    Float3 reflectOnNormal = v.ReflectOnNormal(n);
    // assert reflected == reflectOnNormal

    return 0;
}