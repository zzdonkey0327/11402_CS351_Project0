# Test Plan (Verification)

## 1. Test Strategy
- **Unit tests**: Per module (`TwoSumArray`, `TwoSumHashTable`, `parser`)
- **Integration tests**: Engine + parser → CLI result validation
- **Golden tests**: CLI end-to-end output compare (exact string match)

## 2. Test Environment
**Compiler:** GCC 13+ (C++23), CMake 3.20+  
**OS:** Ubuntu-latest (GitHub Actions), WSL2 locally  
**How to run tests:**
```
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build --output-on-failure
```

## 3. Test Cases (table)
| Test ID | Level | Requirement ID | Description | Input Fixture | Expected |
|---|---|---|---|---|---|
| T-1 | Unit | FR-1 | TwoSumArray normal case | `nums=[2,7,11,15], target=9` | `[0,1]` |
| T-2 | Unit | ER-1 | Empty array validation | `nums=[], target=5` | `error="Array empty or size < 2"` |
| T-3 | Integration | FR-2 | HashTable edge case (negatives) | `nums=[-1,-2,-3,-4], target=-3` | `[1,2]` |
| T-4 | Golden | AC-1 | CLI normal case | `./twosum "[2,7,11,15]" 9` | `[0,1]` |
| T-5 | Unit | FR-2 | HashTable duplicates | `nums=[3,3], target=6` | `[0,1]` |
| T-6 | Golden | AC-2 | CLI malformed input | `./twosum "[a,b]" 5` | `Error: INPUT_INVALID - Invalid number format` |

## 4. Edge Cases Checklist
- [ ] **Empty input**: `[] 5` → validation error
- [ ] **Single element**: `[1] 2` → size error  
- [ ] **Missing fields/nulls**: N/A (primitive int array)
- [ ] **Invalid formats**: `"[a,b]"`, `""`, `[,,]` → parse error
- [ ] **Large input sanity**: n=10^4 random → <500ms both algos
- [ ] **Negative numbers**: `[-1,-2,2,-1] -2` → `[2,3]`
- [ ] **Zero target**: `[0,1] 1` → `[0,1]`
- [ ] **Max INT**: `[2147483647,-2147483648] 0` → `[0,1]`