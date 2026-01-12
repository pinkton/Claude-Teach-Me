#include <iostream>

int main() {
    int numbers[6] = {1, 2, 4, 8, 16, 32};
    std::cout << "This is hardcoded.." << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Number: " << numbers[i] << std::endl;
    }
    // Dynamic looping set to size of variable, 
    std::cout << "\nThis is dynamic.." << std::endl;

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        std::cout << "Number: " << numbers[i] << std::endl;
    }

    // Helps understand what's going on
    std::cout << "\nInt Debug values:\nsizeof(numbers): " << sizeof(numbers) << std::endl;
    std::cout << "sizeof(numbers[0]): " << sizeof(numbers[0]) << std::endl;
    std::cout << "Array length: " << sizeof(numbers) / sizeof(numbers[0]) << std::endl;
    std::cout << std::endl;

    // Changed from -int- to -char- (4byte ea to 1byte ea)
    // Note the change of variable due to being unable to reuse/reassign
    char number[6] = {1, 2, 4, 8, 16, 32};
    std::cout << "Char Debug values:\nsizeof(number): " << sizeof(number) << std::endl;
    std::cout << "sizeof(number[0]): " << sizeof(number[0]) << std::endl;
    std::cout << "Array length: " << sizeof(number) / sizeof(number[0]) << std::endl;
    std::cout << std::endl;

    // Another method, requires C++11 upwards (2011 or later essentially)
    std::cout << "Using modern loops: " << std::endl;
    for (int num : numbers) 
    {
      std::cout << num << std::endl;
    }

    return 0;
}