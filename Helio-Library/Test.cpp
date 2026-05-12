#include "Helio.h"

#include <iostream>

bool badflag = false;

void Assert(bool assertion, String failureMsg)
{
    if (!assertion) {
        std::cout << "Assertion failed: " << failureMsg << std::endl;
        badflag = true;
    }
}

int main()
{
    const float sqrt2 = 1.41421356f;
    const float sqrt2on2 = sqrt2 * 0.5f;

    Float3 n(0.0f, 1.0f, 0.0f);
    Float3 v(1.0f, 1.0f, 0.0f);
    float initMagnitude = v.Magnitude();
    Assert(IsNearlyEqual(initMagnitude, sqrt2), "Magnitude calculation is incorrect.");
    v.Normalize();
    float postNormalizeMagnitude = v.Magnitude();
    // TODO: This assertion fails, because sqrtf(2.00000000f) from math.h gives back
    // 1.41421354 instead of 1.41421356, which compounds down a bit.
    //          ^                     ^
    // Review whether this is actually a problem.
    // At least `Epsilon` and `IsNearlyEqual` seem to be doing their job.
    Assert(IsNearlyEqual(postNormalizeMagnitude, 1.0f), "Normalize() produced incorrect magnitude.");
    Assert(IsNearlyEqual(v.x, v.y), "Normalize produced mismatched axes.");
    Assert(IsNearlyEqual(v.x, sqrt2on2), "Normalize() produced incorrect axis length.");
    float nDotV = n.Dot(v);
    Assert(IsNearlyEqual(nDotV, sqrt2on2), "Dot product incorrect.");
    Float3 proj = n * nDotV;
    Assert(proj == Float3(0.0f, sqrt2on2, 0.0f), "Incorrect manually projected vector.");
    Float3 projOnTgt = v.ProjectOnTarget(n);
    Assert(proj == projOnTgt, "Manually projected and type projected vectors don't match.");
    Float3 perp = v - proj;
    Assert(perp == Float3(sqrt2on2, 0.0f, 0.0f), "Incorrect manually calculated perpendicular.");
    Float3 perpNormalized = perp.Normalized();
    Assert(perpNormalized == Float3(1.0f, 0.0f, 0.0f), "Incorrect normalized perpendicular generated.");
    Float3 reflected = proj * 2.0f - v;
    Assert(reflected == Float3(-sqrt2on2, sqrt2on2, 0.0f), "Incorrect manually reflected vector.");
    Float3 reflectOnNormal = v.ReflectOnNormal(n);
    Assert(reflected == reflectOnNormal, "Manually and automatically calculated reflection vector mismatch.");

    return 0;
}