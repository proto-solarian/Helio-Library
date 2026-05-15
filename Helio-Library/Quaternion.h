#pragma once

/// <summary>
/// Quaternions are useful for encoding rotations.
/// </summary>
struct Quaternion
{
public:
    float a;
    float b;
    float c;
    float d;

    constexpr Quaternion();
    constexpr Quaternion(float a, float b, float c, float d);

    constexpr Quaternion& operator=(const Quaternion& other);
    constexpr Quaternion& operator+=(const Quaternion& other);
    constexpr Quaternion& operator-=(const Quaternion& other);
    constexpr Quaternion& operator*=(const Quaternion& other);
    constexpr Quaternion& operator/=(const Quaternion& other);

    constexpr Quaternion operator+(const Quaternion& rhs) const;
    constexpr Quaternion operator-(const Quaternion& rhs) const;
    constexpr Quaternion operator*(const Quaternion& rhs) const;
    constexpr Quaternion operator/(const Quaternion& rhs) const;
};

inline constexpr Quaternion::Quaternion()
    : a(0.0f), b(0.0f), c(0.0f), d(0.0f)
{}

inline constexpr Quaternion::Quaternion(float a, float b, float c, float d)
    : a(a), b(b), c(c), d(d)
{}

inline constexpr Quaternion& Quaternion::operator=(const Quaternion& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    a = rhs.a;
    b = rhs.b;
    c = rhs.c;
    d = rhs.d;
    return *this;
}

inline constexpr Quaternion& Quaternion::operator+=(const Quaternion& rhs)
{
    a += rhs.a;
    b += rhs.b;
    c += rhs.c;
    d += rhs.d;
    return *this;
}

inline constexpr Quaternion& Quaternion::operator-=(const Quaternion& rhs)
{
    a -= rhs.a;
    b -= rhs.b;
    c -= rhs.c;
    d -= rhs.d;
    return *this;
}

inline constexpr Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
    float oa = a*rhs.a - b*rhs.b - c*rhs.c - d*rhs.d;
    float ob = a*rhs.b + b*rhs.a + c*rhs.d - d*rhs.c;
    float oc = a*rhs.c - b*rhs.d + c*rhs.a + d*rhs.b;
    float od = a*rhs.d + b*rhs.c - c*rhs.b + d*rhs.a;
    a = oa;
    b = ob;
    c = oc;
    d = od;
    return *this;
}

inline constexpr Quaternion& Quaternion::operator/=(const Quaternion& rhs)
{
    float den = rhs.a + rhs.b + rhs.c + rhs.d;
    float oa = (a*rhs.a + b*rhs.b + c*rhs.c + d*rhs.d) / den;
    float ob = (a*rhs.b - b*rhs.a - c*rhs.d + d*rhs.c) / den;
    float oc = (a*rhs.c + b*rhs.d - c*rhs.a - d*rhs.b) / den;
    float od = (a*rhs.d - b*rhs.c + c*rhs.b - d*rhs.a) / den;
    a = oa;
    b = ob;
    c = oc;
    d = od;
    return *this;
}

inline constexpr Quaternion Quaternion::operator+(const Quaternion& rhs) const
{
    return Quaternion(a + rhs.a, b + rhs.b, c + rhs.c, d + rhs.d);
}

inline constexpr Quaternion Quaternion::operator-(const Quaternion& rhs) const
{
    return Quaternion(a - rhs.a, b - rhs.b, c - rhs.c, d - rhs.d);
}

inline constexpr Quaternion Quaternion::operator*(const Quaternion& rhs) const
{
    float oa = a * rhs.a - b * rhs.b - c * rhs.c - d * rhs.d;
    float ob = a * rhs.b + b * rhs.a + c * rhs.d - d * rhs.c;
    float oc = a * rhs.c - b * rhs.d + c * rhs.a + d * rhs.b;
    float od = a * rhs.d + b * rhs.c - c * rhs.b + d * rhs.a;
    return Quaternion(oa, ob, oc, od);
}

inline constexpr Quaternion Quaternion::operator/(const Quaternion& rhs) const
{
    float den = rhs.a + rhs.b + rhs.c + rhs.d;
    float oa = (a * rhs.a + b * rhs.b + c * rhs.c + d * rhs.d) / den;
    float ob = (a * rhs.b - b * rhs.a - c * rhs.d + d * rhs.c) / den;
    float oc = (a * rhs.c + b * rhs.d - c * rhs.a - d * rhs.b) / den;
    float od = (a * rhs.d - b * rhs.c + c * rhs.b - d * rhs.a) / den;
    return Quaternion(oa, ob, oc, od);
}
