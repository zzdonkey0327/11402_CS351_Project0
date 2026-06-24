# 11402_CS351_Project0

# Two sum
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to target.You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Requirements
- Programming language: **C++20**
- Implement two solutions for the Two Sum problem:
    - `TwoSumArray`: brute-force approach using nested loops
    - `TwoSumHashTable`: optimized approach using a hash table
- Include test cases covering both implementations
- Add a GitHub Actions CI/CD workflow for build and test automation
- Provide Docker containerization for packaging and running the solution

## Project Goal

Project 0 is not only about solving the classic Two Sum problem.  
The main goal is to practice end-to-end software engineering: implementing algorithms in C++20, writing tests, configuring GitHub Actions for CI/CD, and packaging the solution with Docker.

## Algorithm Idea

This project includes two implementations:

- **TwoSumArray**: a brute-force solution that checks all pairs of indices using nested loops.  
  It is simple to understand but runs in \(O(n^2)\) time for an array of length \(n\).
- **TwoSumHashTable**: an optimized solution that uses a hash table (`std::unordered_map`) to store previously seen values.  
  It finds the required pair in a single pass with average \(O(n)\) time complexity while keeping the code readable.

## Development History

The development went through several steps:

- Implemented the brute-force array solution as a baseline.
- Added the hash-table-based solution to improve performance.
- Created test cases to cover typical inputs and edge cases (duplicates, negative values, and no-solution scenarios).
- Configured a GitHub Actions workflow to automatically build and run tests on each push.
- Added Docker support so the project can be built and executed in a consistent container environment.

## Testing Results

The test suite is designed to verify both implementations under multiple scenarios.  
All current test cases pass in the CI pipeline, which helps ensure that future changes do not accidentally break existing behavior.
