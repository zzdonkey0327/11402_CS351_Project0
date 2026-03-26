# SRS — Software Requirements Specification

## 1. Scope
**Summary:**  
CS351 Project0 implements Two Sum algorithm with brute-force (TwoSumArray) and hash table (TwoSumHashTable) solutions, including CLI interface, comprehensive unit tests, GitHub Actions CI/CD, and Docker packaging for algorithm education and deployment practice.

**Out of scope:**  
Production-scale data processing (n > 10^5), multiple solution support, GUI interface, distributed computing, external API integration.

## 2. Definitions
**Key terms:**  
- **Two Sum**: Find indices i,j where nums[i] + nums[j] == target (i ≠ j, exactly one solution)  
- **TwoSumArray**: O(n²) brute-force nested loops  
- **TwoSumHashTable**: O(n) single-pass hash table (complement lookup)  
- **Golden tests**: Reference input/output validation  
- **CI/CD**: Continuous Integration/Deployment via GitHub Actions

## 3. User Stories (2–5)
**US-1: Algorithm Student**  
As a CS student, I want dual Two Sum implementations so I can compare time/space trade-offs through tests and complexity analysis.

**US-2: Course TA**  
As a teaching assistant, I want automated CI/CD + Docker tests so I can verify student submissions pass all test cases without manual grading.

**US-3: Developer**  
As a practitioner, I want CLI + containerized deployment so I can integrate Two Sum into larger C++ projects.

## 4. Functional Requirements (FR)
**FR-1: TwoSumArray**  
Implement `std::vector<size_t> TwoSumArray(const std::vector<int>& nums, int target)` using nested loops (i < j).

**FR-2: TwoSumHashTable**  
Implement `std::vector<size_t> TwoSumHashTable(const std::vector<int>& nums, int target)` using `std::unordered_map<int, size_t>` for O(n) lookup.

**FR-3: CLI Interface**  
Implement `twosum <nums> <target>` parsing comma-separated integers, outputting `[i,j]` or error.

## 5. Non-Functional Requirements (NFR)
**NFR-1 Determinism**: Identical inputs produce identical outputs across runs (no rand()).  
**NFR-2 Performance**: TwoSumHashTable completes n=10^4 in <50ms on GitHub Actions Ubuntu-latest.  
**NFR-3 Robustness**: Invalid inputs (empty array, n<2, non-integers) return exit code 1 with stderr message.  
**NFR-4 Portability**: Compiles and passes tests on Ubuntu-latest via GitHub Actions (C++23, STL only).

## 6. Interface Requirements (CLI)
**Command name:** `twosum`  
**Arguments:**  
```
twosum [2,7,11,15] 9
```
**Exit codes:**  
0: Success, 1: Invalid input, 2: No solution  
**Examples:**  
```
$ twosum [2,7,11,15] 9
[0,1]
$ twosum [] 5
Error: Input array empty or too small
$ twosum [1,2,3] 10
Error: No solution found
```

## 7. Data Requirements
**Accepted input format rules:**  
- Comma-separated integers in `[]`: `[2,-1,5,0,3]`  
- Valid range: -2^31 ≤ nums[i] ≤ 2^31-1  
- 2 ≤ nums.size() ≤ 10^4  

**Output format rules:**  
```
[i,j]  // sorted i < j, space after comma
```

## 8. Error Handling Requirements
**ER-1: Input Validation**  
Empty array, n<2, malformed numbers → stderr error + exit 1.  
**ER-2: No Solution**  
No valid i,j pair → stderr "No solution found" + exit 2.

## 9. Acceptance Criteria (black-box)
**AC-1: Normal Case**  
`twosum [2,7,11,15] 9` → `[0,1]` (verifies both implementations).  
**AC-2: Edge Case**  
`twosum [-1,-2,-3,-4] -3` → `[1,2]` (negative numbers, duplicates OK).  
**AC-3: CI/CD Pipeline**  
GitHub Actions passes 20+ test cases + Docker build on every PR/push.