#pragma once

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
