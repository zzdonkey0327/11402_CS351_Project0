# Known Issues / Limitations

## Current Limitations
- **L-1: Hash collision degradation**  
  `TwoSumHashTable` worst-case reverts to O(n²) with pathological hash collisions (rare with `std::unordered_map` default hasher).
- **L-2: Input size limit**  
  CLI parser optimized for n ≤ 10^4; larger inputs (>50k) may hit command-line length limits or memory pressure.

## Deferred Features (nice-to-have)
- **D-1: Multiple solutions**  
  Support returning all valid [i,j] pairs instead of just first found.
- **D-2: Alternative algorithms**  
  Binary search on sorted array (O(n log n)) as third comparison implementation.
- **D-3: JSON/CSV input formats**  
  File-based input for larger datasets beyond CLI argument limits.
- **D-4: Benchmark mode**  
  Performance comparison timing both algorithms on same input.

## Bug Reporting
**Create a GitHub Issue** with:
- **Title**: `[BUG] <brief description>`
- **Repro steps**: Exact command + input that fails
- **Expected vs actual**: `[0,1]` vs `Error: NO_SOLUTION`
- **Input fixture**: `nums=[2,7,11,15], target=9`
- **Environment**: OS/compiler/Docker tag
- **Screenshots**: CLI output + `ctest` failure if applicable

**Labels**: `bug`, `testing`, `help wanted` (student contributions welcome)