# Traceability Matrix

| Intended Use Item | SRS Req ID | SDS Section | Test IDs | CI Step |
|---|---|---|---|---|
| **IU-1** Student algorithm comparison | FR-1, FR-2 | 3. Algorithms | T-1, T-3, T-5, V-1 | `build-test` |
| **IU-2** Automated TA verification | FR-3, NFR-4 | 1. Architecture, 6. Extensibility | T-4, T-6, V-2, V-6 | `docker-test` |
| **IU-3** CLI integration ready | FR-3 | 1. Architecture (cli/) | T-4, V-1, V-3, V-4 | `cli-smoke` |
| **IU-4** Performance education | NFR-2 | 3. Algorithms (Complexity) | T-7 (perf), V-5 | `perf-bench` |
| **IU-5** Deterministic output | NFR-1 | 4. Design Decisions | T-8, V-1 | `format-check` |
| **IU-6** Docker deployment | NFR-4 | 6. Extensibility | V-6 | `docker-build` |
| **IU-7** Edge case robustness | ER-1, ER-2 | 5. Error Model | T-2, T-6, V-3, V-4 | `edge-coverage` |

**Coverage Summary**: 100% traceability - all Intended Use items link to SRS → SDS → Tests → CI automation. No orphan requirements. Ready for M2 milestone review.