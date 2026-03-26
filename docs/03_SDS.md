# SDS — Software Design Specification

## 1. Architecture Overview
**Modules:**
- **parser/**: CLI argument parsing (`[2,7,11,15]` → `std::vector<int>`)
- **model/**: `Result` struct holding indices pair, error state
- **engine/**: `TwoSumArray` (O(n²)) + `TwoSumHashTable` (O(n)) implementations
- **cli/**: Entry point, argument validation, output formatting
- **io/**: Stdout/stderr formatting, test harness integration

## 2. Key Data Structures
**Structs/classes and responsibilities:**
```cpp
struct TwoSumResult {
    std::optional<std::pair<size_t, size_t>> indices;  // {i,j} or nullopt
    std::string error;  // Empty if success
};

std::unordered_map<int, size_t> seen_map;  // HashTable: value → first index
std::vector<int> nums;  // Input array (model)
```

**Ownership/lifetime model (RAII):**
- `nums` owned by caller, passed by const ref to engine
- `seen_map` local to `TwoSumHashTable`, auto-cleared on scope exit
- `TwoSumResult` returned by value, `std::optional` RAII-managed

## 3. Algorithms
**Parsing strategy:**  
`split("[2,7,11,15]", ',')` → `stoi` each token → validate range/size.

**Core transform/query/filter logic:**  
- **TwoSumArray**: `for i=0..n-1, for j=i+1..n-1, if(nums[i]+nums[j]==target) return {i,j}`
- **TwoSumHashTable**: `for i=0..n-1, complement=target-nums[i], if(seen_map.count(complement)) return {seen_map[complement],i}, else seen_map[nums[i]]=i`

**Complexity notes:**  
| Algorithm | Time | Space | Best Case | Worst Case |
|---|---|---|---|---|
| TwoSumArray | O(n²) | O(1) | O(n²) | O(n²) |
| TwoSumHashTable | O(n) avg | O(n) | O(n) | O(n²) hash collision |

## 4. Design Decisions
**Dependency decisions:**  
STL only (`vector`, `unordered_map`, `optional`, `string`) - no external libs for CI portability.

**Deterministic ordering strategy:**  
Always return `i < j`, smaller index first (stable across implementations).

**Null/missing handling policy:**  
`std::optional<std::pair<size_t,size_t>>` - explicit no-result state vs magic values.

## 5. Error Model
**Error codes or exceptions policy:**  
No exceptions (NFR-4 portability). Return `TwoSumResult` with `error` field or `indices=nullopt`.

**Error messages format:**  
```
Error: <code> - <description>
```
Ex: `Error: INPUT_INVALID - Array empty or size < 2`

## 6. Extensibility (1 paragraph)
Design supports extension via new engine modules (`TwoSumSortedBinarySearch`) pluggable into CLI via registry pattern. Parser extensible for JSON/YAML inputs. Test harness supports golden files for new edge cases. Docker multi-stage build enables additional runtimes (Windows, ARM). Hash table replaceable with custom allocator for memory-constrained environments.