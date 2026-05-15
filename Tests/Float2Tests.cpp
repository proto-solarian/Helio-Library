#include "Float2Tests.h"

#include "Float2.h"
#include "HMath.h"

const float TestParamA = 1.5f;
const float TestParamB = 2.25f;
const float TestParamC = 3.125f;
const float TestParamD = 4.0625f;
const float Sqrt2 = 1.41421356f;
const float Sqrt2On2 = 0.70710678f;
const float Sqrt3 = 1.73205081f;
const float Sqrt3On2 = 0.86602540f;

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
    pass &= DotTest();
    pass &= SqrMagnitudeTest();
    pass &= MagnitudeTest();
    pass &= NormalizedTest();
    pass &= NormalizeTest();
    pass &= ProjectOnTargetTest();
    pass &= ProjectOnNormalTest();
    pass &= ReflectOnNormalTest();

    return pass;
}

bool Float2Tests::OperatorEqualTest()
{
    Float2 a(0.0f, 0.0f);
    Float2 b(TestParamA, TestParamB);
    a = b;
    bool pass = true;
    pass &= Assert(a.x == TestParamA && a.y == TestParamB, "operator=: assign b to a failed.");

    return pass;
}

bool Float2Tests::OperatorPlusEqualTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b(TestParamC, TestParamD);
    a += b;
    bool pass = true;
    pass &= Assert(a.x == TestParamA + TestParamC &&
        a.y == TestParamB + TestParamD,
        "operator+=: add b to a failed.");

    Float2 c(TestParamA, TestParamB);
    c += c;
    pass &= Assert(c.x == TestParamA + TestParamA &&
        c.y == TestParamB + TestParamB,
        "operator+=: add c to c failed.");
    return pass;
}

bool Float2Tests::OperatorMinusEqualTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b(TestParamC, TestParamD);
    a -= b;
    bool pass = true;
    pass &= Assert(
        a.x == TestParamA - TestParamC &&
        a.y == TestParamB - TestParamD,
        "operator-=: sub b to a failed.");

    Float2 c(TestParamA, TestParamB);
    c -= c;
    pass &= Assert(
        IsApproximatelyZero(c.x) &&
        IsApproximatelyZero(c.y),
        "operator-=: sub c to c failed.");
    return pass;
}

bool Float2Tests::OperatorTimesEqualTest()
{
    Float2 a(TestParamA, TestParamB);
    a *= TestParamC;
    bool pass = true;
    pass &= Assert(
        a.x == TestParamA * TestParamC &&
        a.y == TestParamB * TestParamC,
        "operator*=: mul a by c failed.");
    return pass;
}

bool Float2Tests::OperatorDivideEqualTest()
{
    Float2 a(TestParamA, TestParamB);
    a /= TestParamC;
    bool pass = true;
    pass &= Assert(
        a.x == TestParamA / TestParamC &&
        a.y == TestParamB / TestParamC,
        "operator*=: mul a by c failed.");
    return pass;
}

bool Float2Tests::OperatorPlusTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b(TestParamC, TestParamD);
    Float2 c(TestParamA + TestParamC, TestParamB + TestParamD);
    Float2 d = a + b;
    return Assert(
        c.x == d.x && c.y == d.y,
        "operator+: result from adding a to b failed."
    );
}

bool Float2Tests::OperatorMinusTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b(TestParamC, TestParamD);
    Float2 c(TestParamA - TestParamC, TestParamB - TestParamD);
    Float2 d = a - b;
    return Assert(
        c.x == d.x && c.y == d.y,
        "operator-: result from subtracting b from a failed."
    );
}

bool Float2Tests::OperatorTimesTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b = a * TestParamC;
    return Assert(
        b.x == TestParamA * TestParamC &&
        b.y == TestParamB * TestParamC,
        "operator*: result from multiplaying a by b failed."
    );
}

bool Float2Tests::OperatorDivideTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b = a / TestParamC;
    float aOnC = TestParamA / TestParamC;
    float bOnC = TestParamB / TestParamC;
    return Assert(
        IsApproximatelyEqual(b.x, aOnC) &&
        IsApproximatelyEqual(b.y, bOnC),
        "operator/: result from dividing a by b failed."
    );
}

bool Float2Tests::OperatorEqualsTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b(TestParamA, TestParamB);
    return Assert(a == b,
        "operator==: equal Float2s return inequal."
    );
}

bool Float2Tests::OperatorNotEqualsTest()
{
    Float2 a(TestParamA, TestParamB);
    Float2 b(TestParamC, TestParamD);
    return Assert(a == b,
        "operator!=: inequal Float2s return equal."
    );
}

bool Float2Tests::DotTest()
{
    Float2 a(1.0f, 0.0f);
    Float2 b(1.0f, 1.0f);
    float dot = a.Dot(b);
    return Assert(dot == 1.0f, "Dot: unexpected dot value.");
}

bool Float2Tests::SqrMagnitudeTest()
{
    Float2 a(1.0, 1.0);
    return Assert(
        IsApproximatelyEqual(a.SqrMagnitude(), 2.0),
        "SqrMagnitude(): incorrect value.");
}

bool Float2Tests::MagnitudeTest()
{
    Float2 a(1.0, 1.0);
    return Assert(
        IsApproximatelyEqual(a.Magnitude(), Sqrt2),
        "Magnitude(): incorrect value.");
}

bool Float2Tests::NormalizedTest()
{
    Float2 a(1.0f, 1.0f);
    Float2 b(Sqrt2On2, Sqrt2On2);
    Float2 c = a.Normalized();
    return Assert(b == c, "Normalized(): Normalization failure.");
}

bool Float2Tests::NormalizeTest()
{
    Float2 a(1.0f, 1.0f);
    a.Normalize();
    return Assert(
        a.x == Sqrt2On2 && a.y == Sqrt2On2,
        "Normalize(): Normalization failure.");
}

bool Float2Tests::ProjectOnTargetTest()
{
    Float2 a(1.0f, 1.0f);
    Float2 b(1.0f, 0.0f);
    bool pass = true;
    Float2 projection1 = b.ProjectOnTarget(a);
    pass &= Assert(
        projection1 == Float2(0.5f, 0.5f),
        "ProjectOnTarget(): smaller vector onto longer failed.");

    Float2 c(2.0f, 2.0f);
    Float2 d(0.0f, 0.5f);
    Float2 projection2 = c.ProjectOnTarget(d);
    pass &= Assert(
        projection2 == Float2(0.0f, 2.0f),
        "ProjectionOnTarget(): larger vector onto shorter failed.");
    return pass;
}

bool Float2Tests::ProjectOnNormalTest()
{
    Float2 a(Sqrt2On2, Sqrt2On2);
    Float2 b(2.0f, 0.0f);
    bool pass = true;
    Float2 projection1 = b.ProjectOnNormal(a);
    pass &= Assert(
        projection1 == Float2(1.0f, 1.0f),
        "ProjectOnNormal(): long vector projected on 45deg normal failed.");

    Float2 c(1.0f, 0.0f);
    Float2 d(0.5f, 0.5f);
    Float2 projection2 = d.ProjectOnNormal(c);
    pass &= Assert(
        projection2 == Float2(0.5f, 0.0f),
        "ProjectOnNormal(): short vector projected on x-axis failed.");
    return pass;
}

bool Float2Tests::ReflectOnNormalTest()
{
    Float2 reflectionSurfaceNormalA(1.0f, 1.0f);
    reflectionSurfaceNormalA.Normalize();
    Float2 reflectionSurfaceNormalB(0.0f, 1.0f);
    Float2 reflectionVectorA(0.5f, 0.0f);
    Float2 reflectionVectorB(Sqrt3On2, 0.5f);

    Float2 r1 = reflectionVectorA.ReflectOnNormal(reflectionSurfaceNormalA);
    Float2 r2 = reflectionVectorB.ReflectOnNormal(reflectionSurfaceNormalA);
    Float2 r3 = reflectionVectorA.ReflectOnNormal(reflectionSurfaceNormalB);
    Float2 r4 = reflectionVectorB.ReflectOnNormal(reflectionSurfaceNormalB);
    bool pass = true;
    pass &= Assert(
        r1 == Float2(0.0f, 0.5f),
        "");
    pass &= Assert(
        r2 == Float2(0.5f, Sqrt3On2),
        "");
    pass &= Assert(
        r3 == Float2(-0.5f, 0.0f),
        "");
    pass &= Assert(
        r4 == Float2(-Sqrt3On2, 0.5f),
        "");
    return pass;
}
