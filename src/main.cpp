#include <charconv>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::size_t> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<std::size_t> TwoSumHashTable(const std::vector<int>& nums, int target);

namespace {

std::string_view Trim(std::string_view value) {
	while (!value.empty() && std::isspace(static_cast<unsigned char>(value.front())) != 0) {
		value.remove_prefix(1);
	}
	while (!value.empty() && std::isspace(static_cast<unsigned char>(value.back())) != 0) {
		value.remove_suffix(1);
	}
	return value;
}

bool ParseInteger(std::string_view text, int& value) {
	text = Trim(text);
	if (text.empty()) {
		return false;
	}

	const char* begin = text.data();
	const char* end = text.data() + text.size();
	long long parsed = 0;
	const auto result = std::from_chars(begin, end, parsed);
	if (result.ec != std::errc{} || result.ptr != end) {
		return false;
	}
	if (parsed < static_cast<long long>(std::numeric_limits<int>::min()) ||
		parsed > static_cast<long long>(std::numeric_limits<int>::max())) {
		return false;
	}

	value = static_cast<int>(parsed);
	return true;
}

bool ParseNumbers(std::string_view text, std::vector<int>& nums) {
	text = Trim(text);
	if (text.empty()) {
		return true;
	}
	if (text.size() < 2 || text.front() != '[' || text.back() != ']') {
		return false;
	}

	std::string_view body = text.substr(1, text.size() - 2);
	body = Trim(body);
	if (body.empty()) {
		return true;
	}

	while (!body.empty()) {
		const std::size_t comma = body.find(',');
		std::string_view token = comma == std::string_view::npos ? body : body.substr(0, comma);
		token = Trim(token);
		if (token.empty()) {
			return false;
		}

		int parsed = 0;
		if (!ParseInteger(token, parsed)) {
			return false;
		}
		nums.push_back(parsed);

		if (comma == std::string_view::npos) {
			break;
		}
		body.remove_prefix(comma + 1);
		body = Trim(body);
		if (body.empty()) {
			return false;
		}
	}

	return true;
}

void PrintIndices(const std::vector<std::size_t>& indices) {
	std::cout << '[' << indices[0] << ',' << indices[1] << ']';
}

}  // namespace

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Error: INPUT_INVALID - Invalid argument count" << std::endl;
		return 1;
	}

	std::vector<int> nums;
	if (!ParseNumbers(argv[1], nums)) {
		std::cerr << "Error: INPUT_INVALID - Invalid number format" << std::endl;
		return 1;
	}
	if (nums.size() < 2) {
		std::cerr << "Error: INPUT_INVALID - Array empty or size < 2" << std::endl;
		return 1;
	}

	int target = 0;
	if (!ParseInteger(argv[2], target)) {
		std::cerr << "Error: INPUT_INVALID - Invalid target format" << std::endl;
		return 1;
	}

	const std::vector<std::size_t> indices = TwoSumHashTable(nums, target);
	if (indices.size() != 2) {
		std::cerr << "Error: NO_SOLUTION - No valid pair found" << std::endl;
		return 2;
	}

	PrintIndices(indices);
	return 0;
}