#pragma once

#include "TestUtils.h"

class Float2Tests : UnitTests
{
public:
    bool Run();
private:
    bool OperatorEqualTest();
    bool OperatorPlusEqualTest();
    bool OperatorMinusEqualTest();
    bool OperatorTimesEqualTest();
    bool OperatorDivideEqualTest();
    bool OperatorPlusTest();
    bool OperatorMinusTest();
    bool OperatorTimesTest();
    bool OperatorDivideTest();
    bool OperatorEqualsTest();
    bool OperatorNotEqualsTest();

    bool DotTest();
    bool SqrMagnitudeTest();
    bool MagnitudeTest();
    bool NormalizedTest();
    bool NormalizeTest();
    bool ProjectOnTargetTest();
    bool ProjectOnNormalTest();
    bool ReflectOnNormalTest();
};
