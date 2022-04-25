#include <iostream>
#include <cstdlib>
#include <chrono>
#include <memory>
#include "Searching.h"

using namespace std;

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTheTimer;

public:

    Timer()
    {
        startTheTimer = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto stopTheTimer = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTheTimer).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(stopTheTimer).time_since_epoch().count();
        auto duration = end - start;
        double milliseconds = duration * 0.001;
        std::cout << "Duration in microseconds is  " << duration  <<" us " << std::endl;
        std::cout << "Duration in milliseconds is  " << milliseconds  <<" ms " << std::endl;

    }
};

void PrintArray(int* inputArray, int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << "[" << i << "]" << " is " << inputArray[i] << endl;
    }
}

void DoTheSearch(std::unique_ptr<Searching> searching, int selectedAlgorithm, int valueToSearch)
{
    int response = -1;

    switch (selectedAlgorithm)
    {
        case 1:
            cout << "Selected the Linear search" << endl;
            {
                Timer timer;
                response = searching->LinearSearch(valueToSearch);
            }
            break;

        case 2:
            searching->BubbleSorting();
            cout << "Selected the Binary search" << endl;
            {
                Timer timer;
                response = searching->BinarySearch(0, searching->GetSize() - 1, valueToSearch);
            }
            break;

        case 3:
            searching->BubbleSorting();
            cout << "Selected the Ternary search" << endl;
            {
                Timer timer;
                response = searching->TernarySearch(0, searching->GetSize() -1, valueToSearch);
            }
            break;

        case 4:
            searching->BubbleSorting();
            cout << "Selected the interpolation search" << endl;
            {
                Timer timer;
                response = searching->InterpolationSearch(0, searching->GetSize() - 1, valueToSearch);
            }
            break;

        case 5:
            searching->BubbleSorting();
            cout << "Selected the jump search " << endl;
            {
                Timer timer;
                response = searching->JumpSearch(valueToSearch);
            }
            break;

        case 6:
            searching->BubbleSorting();
            cout << "Selected the exponential search " << endl;
            {
                Timer timer;
                response = searching->ExponentialSearch(valueToSearch);
            }
            break;
        case -1:
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    if(response != -1)
    {
        cout << "The number " << valueToSearch << " is in position " << response << endl;
    }
    else
    {
        cout << "The number " << valueToSearch << " is not in the array " << endl;
    }
}

int main() {
    int rnd;
    int ctn = 0;
    int numberToSearch;
    int selectedAlgorithm;

    cout << "Enter the number of random integer: " << endl;
    cin >> rnd;

    // check if random is a positive number
    if(rnd <= 0)
    {
        throw invalid_argument("The value of the random integer should be greater then 0");
    }

    try {
        //get the array with the size with need
        int inputArray[rnd];

        //fill the array
        while (rnd--) {
            inputArray[ctn] = rand() % INT16_MAX + 1;
            ctn++;
        }

        //get the size of the array
        int size = sizeof(inputArray) / sizeof(*inputArray);

        //print out the random array so we can select a number inside
        PrintArray(inputArray, size);

        //select a number to search
        cout << "\n";
        cout << "Select a number to search " << endl;
        cin >> numberToSearch;

        cout << "Select an algorithm" << endl;
        cout << endl;
        cout << "1 for linear search" << endl;
        cout << "2 for binary search" << endl;
        cout << "3 for ternary search" << endl;
        cout << "4 for interpolation search" << endl;
        cout << "5 for jump search" << endl;
        cout << "6 for exponential search" << endl;
        cout << endl;
        cout << "7 for benchmark" << endl;
        cout << endl;
        cout << "-1 to exit" << endl;

        cin >> selectedAlgorithm;

        if((selectedAlgorithm != 7) && selectedAlgorithm != -1)
        {
            //let s try the unique pointer
            unique_ptr<Searching> searching(new Searching(inputArray, size));

            //do the single job
            DoTheSearch(std::move(searching), selectedAlgorithm,numberToSearch);

            //free memory
            searching.reset();
        }

        if (selectedAlgorithm == 7)
        {
            for(int i = 1; i <= 6; i++)
            {
                //we have an unique pointer and we can not copy it so:
                unique_ptr<Searching> searching(new Searching(inputArray, size));

                //do the benchmark
                DoTheSearch(std::move(searching), i,numberToSearch);
                cout << "\t===\t===\t===" << endl;

                searching.reset();
            }
        }

        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Main throws exception " << e.what() << endl;
        return -1;
    }
}
