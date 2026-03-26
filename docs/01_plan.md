# Project Plan (Jira + Git Workflow)

## 1. Milestones
| Milestone | Deliverable | Due | Owner |
|---|---|---:|---|
| M1 | SRS + SDS draft + CI skeleton | 2026/3/28 | @yourself |
| M2 | Core engine complete + unit tests | 2026/3/30 | @yourself |
| M3 | CLI end-to-end + golden tests | 2026/4/2 | @yourself |
| M4 | v1.0 release + deploy notes | 2026/4/5 | @yourself |

## 2. Jira Structure
- **Epic**: PX11402-Project0 (Two Sum implementations + CI/CD)
- **Stories**: 
  - PX11402-1: SRS documentation
  - PX11402-2: SDS design spec
  - PX11402-3: TwoSumArray implementation
  - PX11402-4: TwoSumHashTable implementation
  - PX11402-5: Unit tests (xUnit/Catch2)
  - PX11402-6: GitHub Actions CI/CD
  - PX11402-7: Docker packaging
  - PX14302-8: Deployment docs
  - PX11402-9: Release preparation

- **Definition of Done (DoD)**:
  - PR merged (no direct push to main)
  - CI green (all tests pass)
  - Tests added (80%+ coverage)
  - Docs updated (00_intended_use.md through 08_known_issues.md)

## 3. Git Collaboration Rules
- **Branch naming**: `feature/PX11402-<story-number>-short-title`
  - Ex: `feature/PX11402-3-twosumarray`, `feature/PX11402-6-github-actions`
- **PR required** for merge to main
- **Collaborator must**:
  - Review every PR (self-review + AI review via Copilot Chat)
  - Run `dotnet test` or `ctest` locally before PR
  - Approve before merge (include complexity analysis)

## 4. Meeting / Checkpoint Notes
- **Sprint demo checklist**:
  - Show CLI run: `./twosum [2,7,11,15] 9` → `[0,1]`
  - Show tests: `dotnet test --logger trx` (100% pass)
  - Show CI run: GitHub Actions badge green
  - Docker demo: `docker build -t twosum . && docker run twosum`