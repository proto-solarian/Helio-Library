#pragma once

#include <vector>

#include "HMath.h"

std::vector<N64> GetPrimeComposition(N64 integer)
{
    std::vector<N64> primeDivisors = std::vector<N64>();
    std::vector<N64> testedPrimes = std::vector<N64>();
    N64 ref = integer;
    N64 prime = 2;
    while (prime <= ref) {
        while (ref % prime == 0) {
            primeDivisors.push_back(prime);
            ref /= prime;
        }
        testedPrimes.push_back(prime++);

        // Find next prime
        // First iteration:
        //   3 % 2 = 1.
        //   No more tested primes to check. 3 is a new prime.
        // Second iteration:
        //   4 % 2 == 0. 4++.
        //   5 % 2 = 1. 5 % 3 == 2.
        //   No more tested primes to check. 5 is a new prime.
        // Third iteration:
        //   6 % 2 == 0. 6++.
        //   7 % 2 = 1. 7 % 3 = 1. 7 % 5 = 2.
        //   No more tested primes to check. 7 is a new prime.
        // Fourth iteration:
        //   8 % 2 == 0; 8++.
        //   9 % 2 = 1. 9 % 3 = 0. 9++
        //   10 % 2 = 0. 10++
        //   11 % 2 = 1. 11 % 3 = 2. 11 % 5 = 1. 11 % 7 = 4.
        //   No more tested primes to check. 11 is a new prime.
        bool test = true;
        while (test) {
            test = false;
            for (const auto& testedPrime : testedPrimes) {
                if (prime % testedPrime == 0) {
                    test = true;
                    prime++;
                    break;
                }
            }
        }
    }
    return primeDivisors;
}

void RunPrimeCompositionTest()
{
    std::cout << "Doing some prime decomp fun." << std::endl;
    for (N64 n = 0; n < 100; n++) {
        auto divisors = GetPrimeComposition(n);
        std::cout << "Divisors of " << n << std::endl;
        for (const auto& divisor : divisors) {
            std::cout << divisor << " ";
        }
        std::cout << std::endl;
    }
}
