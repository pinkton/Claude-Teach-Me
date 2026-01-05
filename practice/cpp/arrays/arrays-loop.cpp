#include <iostream>

int main() {
    int numbers[5] = {1, 2, 4, 8, 16};

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Number: " << numbers[i] << std::endl;
    }

    return 0;
}