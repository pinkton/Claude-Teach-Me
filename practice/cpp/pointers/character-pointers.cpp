#include <iostream>

int main() {
    std::cout << "\n--- Pointer Arithmetic with Different Types ---" << std::endl;
    
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};
    char* cp = letters;
    
    std::cout << "Address of letters[0]: " << (void*)cp << std::endl;
    std::cout << "Address of letters[1]: " << (void*)(cp + 1) << std::endl;
    std::cout << "Address of letters[2]: " << (void*)(cp + 2) << std::endl;








    
    return 0;
}