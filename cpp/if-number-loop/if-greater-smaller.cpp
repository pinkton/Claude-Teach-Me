#include <iostream>

int main () {
    int number;
    while (true) {
        std::cout << "Please enter a number from 0 - 20, or -1 to quit:" << std::endl;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flags
            std::cin.ignore(100, '\n');  // Discard up to 100 chars or until newline
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        else if (number > 10 && number <= 20) 
        {
            std::cout << "Number is greater than 10" << std::endl;
        } 
        else if (number < 10 && number >= 0)
        {
            std::cout << "Number is less than 10" << std::endl;
        }
        else if (number == 10)
        {
            std::cout << "Number is exactly 10" << std::endl;
        }
        else if (number == -1)
        {
            std::cout << "Quitting!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Number is not within parameters, or is not a number, try again\n" << std::endl;
        }
    }
    return 0;
}