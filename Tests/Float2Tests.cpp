#include "Float2Tests.h"

#include "Float2.h"
#include "HMath.h"

bool Float2Tests::Run()
{
    bool pass = true;

    pass &= OperatorEqualTest();
    pass &= OperatorPlusEqualTest();
    pass &= OperatorMinusEqualTest();
    pass &= OperatorTimesEqualTest();
    pass &= OperatorDivideEqualTest();
    pass &= OperatorPlusTest();
    pass &= OperatorMinusTest();
    pass &= OperatorTimesTest();
    pass &= OperatorDivideTest();

    return pass;
}

bool Float2Tests::OperatorEqualTest()
{
    float testParamA = 2.0f;
    float testParamB = 0.66666666f;
    Float2 a(0.0f, 0.0f);
    Float2 b(testParamA, testParamB);
    a = b;
    bool pass = true;
    pass &= Assert(a.x == testParamA && a.y == testParamB, "operator=: assign b to a failed.");

    return pass;
}

bool Float2Tests::OperatorPlusEqualTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    const float testParamD = 4.0625f;
    Float2 a(testParamA, testParamB);
    Float2 b(testParamC, testParamD);
    a += b;
    bool pass = true;
    pass &= Assert(a.x == testParamA + testParamC &&
        a.y == testParamB + testParamD,
        "operator+=: add b to a failed.");

    Float2 c(testParamA, testParamB);
    c += c;
    pass &= Assert(c.x == testParamA + testParamA &&
        c.y == testParamB + testParamB,
        "operator+=: add c to c failed.");
    return pass;
}

bool Float2Tests::OperatorMinusEqualTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    const float testParamD = 4.0625f;
    Float2 a(testParamA, testParamB);
    Float2 b(testParamC, testParamD);
    a -= b;
    bool pass = true;
    pass &= Assert(
        a.x == testParamA - testParamC &&
        a.y == testParamB - testParamD,
        "operator-=: sub b to a failed.");

    Float2 c(testParamA, testParamB);
    c -= c;
    pass &= Assert(
        IsApproximatelyZero(c.x) &&
        IsApproximatelyZero(c.y),
        "operator-=: sub c to c failed.");
    return pass;
}

bool Float2Tests::OperatorTimesEqualTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    Float2 a(testParamA, testParamB);
    a *= testParamC;
    bool pass = true;
    pass &= Assert(
        a.x == testParamA * testParamC &&
        a.y == testParamB * testParamC,
        "operator*=: mul a by c failed.");
    return pass;
}

bool Float2Tests::OperatorDivideEqualTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    Float2 a(testParamA, testParamB);
    a /= testParamC;
    bool pass = true;
    pass &= Assert(
        a.x == testParamA / testParamC &&
        a.y == testParamB / testParamC,
        "operator*=: mul a by c failed.");
    return pass;
}

bool Float2Tests::OperatorPlusTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    const float testParamD = 4.0625f;
    Float2 a(testParamA, testParamB);
    Float2 b(testParamC, testParamD);
    Float2 c(testParamA + testParamC, testParamB + testParamD);
    Float2 d = a + b;
    return Assert(
        c.x == d.x && c.y == d.y,
        "operator+: result from adding a to b failed."
    );
}

bool Float2Tests::OperatorMinusTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    const float testParamD = 4.0625f;
    Float2 a(testParamA, testParamB);
    Float2 b(testParamC, testParamD);
    Float2 c(testParamA - testParamC, testParamB - testParamD);
    Float2 d = a - b;
    return Assert(
        c.x == d.x && c.y == d.y,
        "operator-: result from subtracting b from a failed."
    );
}

bool Float2Tests::OperatorTimesTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    Float2 a(testParamA, testParamB);
    Float2 b = a * testParamC;
    return Assert(
        b.x == testParamA * testParamC &&
        b.y == testParamB * testParamC,
        "operator*: result from multiplaying a by b failed."
    );
}

bool Float2Tests::OperatorDivideTest()
{
    const float testParamA = 1.5f;
    const float testParamB = 2.25f;
    const float testParamC = 3.125f;
    Float2 a(testParamA, testParamB);
    Float2 b = a / testParamC;
    float aOnC = testParamA / testParamC;
    float bOnC = testParamB / testParamC;
    return Assert(
        IsApproximatelyEqual(b.x, aOnC) &&
        IsApproximatelyEqual(b.y, bOnC),
        "operator/: result from dividing a by b failed."
    );
}
