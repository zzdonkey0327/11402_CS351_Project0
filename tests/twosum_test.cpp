#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::size_t> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<std::size_t> TwoSumHashTable(const std::vector<int>& nums, int target);

bool TestCase(const std::string& name,
	const std::vector<int>& nums,
	int target,
	const std::vector<std::size_t>& expected) {
	const std::vector<std::size_t> actual = TwoSumHashTable(nums, target);
	if (actual != expected) {
		std::cerr << "FAILED: " << name << "\n";
		std::cerr << "  expected: [";
		for (std::size_t i = 0; i < expected.size(); ++i) {
			if (i != 0) std::cerr << ',';
			std::cerr << expected[i];
		}
		std::cerr << "]\n  actual: [";
		for (std::size_t i = 0; i < actual.size(); ++i) {
			if (i != 0) std::cerr << ',';
			std::cerr << actual[i];
		}
		std::cerr << "]\n";
		return false;
	}
	std::cout << "PASSED: " << name << "\n";
	return true;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: twosum_test <case_name>\n";
		std::cerr << "  case_name: basic, negative, duplicate, no_solution\n";
		return 1;
	}

	std::string case_name = argv[1];

	if (case_name == "basic") {
		return TestCase("basic", {2, 7, 11, 15}, 9, {0, 1}) ? 0 : 1;
	}
	else if (case_name == "negative") {
		return TestCase("negative", {-1, -2, -3, -4}, -3, {0, 1}) ? 0 : 1;
	}
	else if (case_name == "duplicate") {
		return TestCase("duplicate", {3, 3}, 6, {0, 1}) ? 0 : 1;
	}
	else if (case_name == "no_solution") {
		return TestCase("no_solution", {1, 2, 5, 9}, 50, {}) ? 0 : 1;
	}
	else {
		std::cerr << "Unknown case: " << case_name << "\n";
		return 1;
	}
}
