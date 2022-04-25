//
// Created by luca on 22.4.2022.
//

#ifndef SEARCHING_SEARCHING_H
#define SEARCHING_SEARCHING_H
#include <iostream>

class Searching {
private:
    int* InputArray;
    int SizeOfArray;

public:
    Searching(int* inputArray, int sizeArray);
    int GetSize();
    void BubbleSorting();

    int LinearSearch(int valueToSearch);
    //overload the Linear Search methods
    int LinearSearch(int start, int end, int valueToSearch);

    int BinarySearch(int start, int end, int valueToSearch);
    int TernarySearch(int start, int end, int valueToSearch);
    int InterpolationSearch(int start, int end, int valueToSearch);
    int JumpSearch(int valueToSearch);
    int ExponentialSearch(int valueToSearch);

};


#endif //SEARCHING_SEARCHING_H
