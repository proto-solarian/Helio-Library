# Helio-Library
A zero-dependency† cross-project header library for practice, reference, and preference.

Contains data structures, math implementations, and preferred typename definitions.

## Why?
Most of the code here is for research. Float3.h, for instance, isn't intended to be better than GLM, even if I intend to implement SIMD optimizations.
Some of the code here is for readability. C++ is a beautiful language full of ugly cruft, so I like to clear it out when it does no harm in my personal projects.
Some of the code here is also for showcase and reference. What can I do, what did I do? Some of that is archived here.

## TODO
- Tests should be out of source, especially so that some library header doesn't accidentally call them in.
- Implement Float4 -> Make Float* declarations generic? Make Enable various levels of precision?
- Implement Matrices and Quaternions
- Add that quick square root from Quake
- Add Spheremap conversion functions (from-to look dir).
- Add Cubemap functions
- Add Data Structures
- Add Computational Geometry Utils: triangle logic, barycentric coords (rasterization, point-in-tri)
- Add Tests for Spherecoords implementation.

† There are/may-always-be some standard math library references, like sin, cos, etc.
