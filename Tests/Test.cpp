#include "Helio.h"

#include "Float2Tests.h"
#include "Float3Tests.h"
#include "MathToys.h"

int main()
{
    Float2Tests float2Tests;
    float2Tests.Run();

    RunFloat3Test();

    RunPrimeCompositionTest();

    return 0;
}
