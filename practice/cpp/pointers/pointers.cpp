#include <iostream>

int main() {
    int num = 42;
    // int* ptr - declares a pointer (part of the type)
    // *ptr - dereferences a pointer (accesses the value)
    int* ptr = &num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value stored in ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    // Another way to understand references, arrays and derefencing.
    // scores[0] + 1 is equivalent to scores[1]
    // &scores[0] gets the memory address
    int scores[5] = {10, 20, 30, 40, 50};
    std::cout << "\n--- Watch the Addresses ---" << std::endl;
    std::cout << "Address of scores[0]: " << &scores[0] << std::endl;
    std::cout << "Address of scores[1]: " << &scores[1] << std::endl;
    std::cout << "Address of scores[2]: " << &scores[2] << std::endl;
    
    std::cout << "\n--- Iterate with Pointer Arithmetic ---" << std::endl;
    int* p = scores;  // p now points to first element
    for (int i = 0; i < 5; i++) {
        std::cout << "*(p + " << i << ") = " << *(p + i) << std::endl;
    }
    
    std::cout << "\n--- Iterate by Incrementing Pointer ---" << std::endl;
    int* end = scores + 5;
    while (p < end) {
        std::cout << *p << std::endl;
        p++;
    } 
    
    
    
    
    
    return 0;
}