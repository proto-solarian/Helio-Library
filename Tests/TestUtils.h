#pragma once

#include "Helio.h"

#include <iostream>

inline constexpr bool Assert(bool assertion, String failureMsg)
{
    if (!assertion) {
        std::cout << "Assertion failed: " << failureMsg << std::endl;
    }
    return assertion;
}

class UnitTests
{
public:
    virtual bool Run() = 0;
};
