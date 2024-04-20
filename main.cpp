#include <measure_duration.hpp>
#include <iostream>

uint64_t f(int n) {
	if (n < 0) return 1;
	return f(n - 1) + f(n - 2);
}

int main() {
	auto duration = water::measure_duration_average<1>(f, 40);
	std::cout << duration << std::endl;
	return 0;
}