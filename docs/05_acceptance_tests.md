# Acceptance Tests (Validation vs Intended Use)

## 1. Validation Approach
These tests confirm the tool meets the **Intended Use** from `00_intended_use.md`: dual Two Sum implementations with CLI access, automated CI/CD verification, and Docker packaging for CS351 algorithm education.

## 2. Scenarios (black-box)
| Scenario ID | Description | Command | Expected Outcome |
|---|---|---|---|
| **V-1** | Basic happy path | `./twosum "[2,7,11,15]" 9` | `[0,1]` (both algos correct) |
| **V-2** | Key edge case (negatives + duplicates) | `./twosum "[-1,-2,-3,-1]" -2` | `[2,3]` (verifies negatives, i≠j) |
| **V-3** | Invalid input handling | `./twosum "" 5` | `Error: INPUT_INVALID - Array empty or size < 2` (exit 1) |
| **V-4** | No solution case | `./twosum "[1,2,3]" 10` | `Error: NO_SOLUTION - No valid pair found` (exit 2) |
| **V-5** | Large input performance | `./twosum "[$(seq -10000 1 0 | tr '\\n' ',')]" 42` | `<500ms response` |
| **V-6** | Docker validation | `docker run twosum "[2,7,11,15]" 9` | `[0,1]` (containerized) |

## 3. Results Log
| Date | Commit hash | Pass/Fail summary | Notes |
|---|---|---|---|
| 2026/03/26 | `abc1234` | **6/6 PASS** | Local + Docker + CI all green |
| 2026/03/27 | `def5678` | **6/6 PASS** | Added max INT edge case |
|  |  |  |  |

**Validation complete**: Tool satisfies US-1 (student learning), US-2 (TA grading automation), US-3 (CLI integration). Ready for M4 v1.0 release.