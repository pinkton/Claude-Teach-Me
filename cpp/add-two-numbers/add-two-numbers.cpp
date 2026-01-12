#include <iostream>

int add(int a, int b) {
	return a+b;
}

int main() {
	std::cout << "The two numbers make: " << add(4,5) << std::endl;
	return 0;
}
