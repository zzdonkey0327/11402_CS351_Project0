#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::size_t> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<std::size_t> TwoSumHashTable(const std::vector<int>& nums, int target);

struct TestCase {
	std::string name;
	std::vector<int> nums;
	int target;
	std::vector<std::size_t> expected_array;
	std::vector<std::size_t> expected_hash;
};

bool RunCase(const TestCase& test_case,
	std::vector<std::size_t> (*solver)(const std::vector<int>&, int),
	const std::string& solver_name,
	const std::vector<std::size_t>& expected) {
	const std::vector<std::size_t> actual = solver(test_case.nums, test_case.target);
	if (actual != expected) {
		std::cerr << solver_name << " failed: " << test_case.name << "\n";
		std::cerr << "  expected: [";
		for (std::size_t index = 0; index < expected.size(); ++index) {
			if (index != 0) {
				std::cerr << ',';
			}
			std::cerr << expected[index];
		}
		std::cerr << "]\n  actual:   [";
		for (std::size_t index = 0; index < actual.size(); ++index) {
			if (index != 0) {
				std::cerr << ',';
			}
			std::cerr << actual[index];
		}
		std::cerr << "]\n";
		return false;
	}
	return true;
}

int main() {
	const std::vector<TestCase> cases = {
		{"basic", {2, 7, 11, 15}, 9, {0, 1}, {0, 1}},
		{"negative_numbers", {-1, -2, -3, -4}, -3, {0, 1}, {0, 1}},
		{"duplicates", {3, 3}, 6, {0, 1}, {0, 1}},
		{"zero_target", {0, 1, 2, 3}, 1, {0, 1}, {0, 1}},
		{"mixed_sign", {-10, 4, 7, 3, 8}, 11, {1, 2}, {1, 2}},
		{"later_pair", {1, 5, 9, 13, 17}, 22, {1, 4}, {2, 3}},
		{"max_int_edge", {2147483647, -2147483648, 1, 0}, -1, {0, 1}, {0, 1}},
		{"repeated_values", {1, 2, 1, 2}, 4, {1, 3}, {1, 3}},
		{"ordered_pair", {8, 1, 6, 3}, 9, {0, 1}, {0, 1}},
		{"another_basic", {5, 75, 25}, 100, {1, 2}, {1, 2}},
		{"no_solution", {1, 2, 5, 9}, 50, {}, {}}
	};

	bool passed = true;
	for (const TestCase& test_case : cases) {
		passed = RunCase(test_case, TwoSumArray, "TwoSumArray", test_case.expected_array) && passed;
		passed = RunCase(test_case, TwoSumHashTable, "TwoSumHashTable", test_case.expected_hash) && passed;
	}

	if (!passed) {
		return 1;
	}

	std::cout << "All Two Sum tests passed\n";
	return 0;
}
