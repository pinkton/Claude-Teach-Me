#include <iostream>

int main() {
    int numbers[5] = {1, 2, 4, 8, 16};

    // Intentionally access out of bounds
    std::cout << "Accessing out of bounds:" << std::endl;
    std::cout << "numbers[5] = " << numbers[5] << std::endl;  // Valid indices: 0-4
    std::cout << "numbers[10] = " << numbers[10] << std::endl;
    std::cout << "numbers[100] = " << numbers[100] << std::endl;

    return 0;
}