// Two Sum algorithm implementations.
#include <cstddef>
#include <limits>
#include <unordered_map>
#include <vector>

std::vector<std::size_t> TwoSumArray(const std::vector<int>& nums, int target) {
	const std::size_t count = nums.size();
	for (std::size_t left = 0; left < count; ++left) {
		for (std::size_t right = left + 1; right < count; ++right) {
			const long long sum = static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);
			if (sum == static_cast<long long>(target)) {
				return {left, right};
			}
		}
	}
	return {};
}

std::vector<std::size_t> TwoSumHashTable(const std::vector<int>& nums, int target) {
	std::unordered_map<int, std::size_t> seen;
	seen.reserve(nums.size());

	for (std::size_t index = 0; index < nums.size(); ++index) {
		const long long complement_value = static_cast<long long>(target) - static_cast<long long>(nums[index]);
		if (complement_value >= static_cast<long long>(std::numeric_limits<int>::min()) &&
			complement_value <= static_cast<long long>(std::numeric_limits<int>::max())) {
			const int complement = static_cast<int>(complement_value);
			const auto found = seen.find(complement);
			if (found != seen.end()) {
				return {found->second, index};
			}
		}

		if (seen.find(nums[index]) == seen.end()) {
			seen.emplace(nums[index], index);
		}
	}

	return {};
}
