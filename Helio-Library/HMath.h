#pragma once

#include "Float.h"
#include "Float2.h"
#include "Float3.h"
#include "SphereCoords.h"

/// <summary>
/// é©ëRêî-ïÑçÜñ≥Çµ (0 to N_MAX)
/// </summary>
using N64 = unsigned long long int;
const N64 N64_MAX = 0xffffffffffffffffui64;

/// <summary>
/// êÆêî (-Z_MAX to Z_MAX)
/// </summary>
using Z64 = long long int;
const Z64 Z64_MAX = 9223372036854775807i64;
const Z64 Z64_MIN = -9223372036854775808i64;

struct Quaternion {};
