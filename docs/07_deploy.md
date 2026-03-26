# Deployment / Packaging

## 1. What "deployment" means for this project
- **Option B: Docker image** (primary) - Containerized CLI for consistent CI/CD testing and TA grading
- **Option A: Release binary** (secondary) - Static Linux binary for local execution

## 2. Build Instructions
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=23
cmake --build build --config Release --parallel 4
```
**Output**: `build/twosum` (CLI binary + tests)

## 3. Run Instructions
```
# Local binary
./build/twosum "[2,7,11,15]" 9
# Expected: [0,1]

# Run tests
ctest --test-dir build --output-on-failure
```

## 4. Docker (primary deployment)
```
# Build (includes tests during build)
docker build -t twosum:cs351-project0 .

# Run CLI
docker run --rm twosum:cs351-project0 "[2,7,11,15]" 9
# Expected: [0,1]

# Interactive shell
docker run --rm -it twosum:cs351-project0 bash
```

**Dockerfile** (multi-stage):
```dockerfile
FROM ubuntu:24.04 AS builder
RUN apt update && apt install -y cmake g++-13
WORKDIR /src
COPY . .
RUN cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build && \
    ctest --test-dir build  # Fail build if tests fail

FROM ubuntu:24.04 AS runtime
RUN apt update && apt install -y libstdc++6
COPY --from=builder /src/build/twosum /usr/local/bin/
ENTRYPOINT ["twosum"]
```

## 5. Versioning
**Tag format**: `v1.0.0`  
**Release process**:
```
git tag v1.0.0
git push origin v1.0.0
# GitHub Actions auto-builds/pushes Docker image
docker push ghcr.io/yourusername/twosum:1.0.0
```

**CHANGELOG.md**:
```
## v1.0.0 (2026/03/26)
- Initial release: TwoSumArray + TwoSumHashTable
- CLI + full test suite + GitHub Actions CI/CD
- Docker containerized deployment
```