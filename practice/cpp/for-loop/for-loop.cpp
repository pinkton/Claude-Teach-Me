#include <iostream>

int main () {
    std::cout << "Counting from 1 - 20" << std::endl;
    for (int i = 1; i <= 20; i++) {
        std::cout << "Number " << i << " of 20" << std::endl;
    }
    std::cout << "\nCounting from 10 - 0" << std::endl;
    for (int i = 10; i >= 0; i--) {
        std::cout << "Number " << i << " of 10" << std::endl;
    }
    std::cout << "\nCounting from 0 - 20 in 2s" << std::endl;
    for (int i = 0; i <= 20; i+=2) {
        std::cout << "Number " << i << " of 20" << std::endl;
    }
    return 0;
}

