#include <iostream>

struct Player {
    int health;
    int x;
    int y;
};

int main() {
    Player myPlayer; //Create a structure called myPlayer
    Player* ptr = &myPlayer; //Create a pointer and reference to myPlayer (with &)

    ptr->health=100;
    ptr->x=50;
    ptr->y=75;

    std::cout << "-- Simple one liners ---" << std::endl;
    std::cout << "Player HP: " << ptr->health << std::endl;
    std::cout << "Player X Pos: " << ptr->x << std::endl;
    std::cout << "Player Y Pos: " << ptr->y << std::endl;

    std::cout << "-- Looping through addresses ---" << std::endl;
    // Create ptr addr integer
    int* addrPtr = (int*)ptr;
    for (int i = 0; i < 3; i++) {
        // Example: Offset 0x0: 100
        // How it's built
            // Offset 0x
            // Set Hex and eval i * 4 
            // Set to decimal, add ": "
            // Dereference array value - Health = 0, X = 1, Y = 2
            // Finish
        std::cout << "Offset 0x" << std::hex << (i * 4) << std::dec << ": " << *(addrPtr + i) << std::endl;
    };

    std::cout << "-- Looping through addresses with proof of pointer ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        // Example: Pointer:0x7ffc9acf5f2c
        //          Offset 0x0: 100
        // How it's built
            // Pointer:
            // Set Hex and print ptr + i
            // Offset 0x
            // Set Hex and eval i * 4 
            // Set to decimal, add ": "
            // Dereference array value - Health = 0, X = 1, Y = 2
            // Finish
        std::cout << "Pointer:" << std::hex << (addrPtr + i) << std::endl;
        std::cout << "Offset 0x" << std::hex << (i * 4) << std::dec << ": " << *(addrPtr + i) << std::endl;
    };     


};
