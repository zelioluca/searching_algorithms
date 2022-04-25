//
// Created by luca on 22.4.2022.
//

#include "Searching.h"
#include <math.h>

Searching::Searching(int *inputArray, int sizeArray) : InputArray{inputArray}, SizeOfArray(sizeArray)
{

}
int Searching::GetSize() { return SizeOfArray; }

void Searching::BubbleSorting() {
    //flag is the element of the array is swapped or not
    bool flagIsSwapped = false;

    int elementToSort = SizeOfArray;

    do
    {
        flagIsSwapped = false;
        // fix all the elements of the array
        for(int i = 0; i < elementToSort - 1; ++i)
        {
            // if they are in the wrong position swap it
            if(InputArray[i] > InputArray[i + 1])
            {
                std::swap(InputArray[i], InputArray[i + 1]);
                flagIsSwapped = true;
            }
        }
        //remove one from the element to sort
        --elementToSort;

    } while (flagIsSwapped);
}

int Searching::LinearSearch(int valueToSearch)
{
    for(int i = 0; i < SizeOfArray; i++)
    {
        if(InputArray[i] == valueToSearch)
        {
            return i;
        }
    }

    return -1; 
}

//overload the Linear Search method
int Searching::LinearSearch(int start, int end, int valueToSearch)
{
    for(int i = start; i < end; i++)
    {
        if(InputArray[i] == valueToSearch)
        {
            return i;
        }
    }
    return -1;
}

int Searching::BinarySearch(int start, int end, int valueToSearch)
{

    if(start <= end)
    {
        int middle = start + (end - start) / 2;

        if(InputArray[middle] == valueToSearch)
        {
            return middle;
        }
        else if(InputArray[middle] > valueToSearch)
        {
            return BinarySearch(start, middle -1, valueToSearch);
        }
        else
        {
            return BinarySearch(middle + 1, SizeOfArray, valueToSearch);
        }
    }

    return -1;

}

int Searching::TernarySearch(int start, int end, int valueToSearch)
{
    if(start <= end)
    {
        int middleLeft = start + (end -start) / 3;
        int middleRight = middleLeft + (end - start) / 3;

        if(InputArray[middleLeft] == valueToSearch)
        {
            return middleLeft;
        }
        else if(InputArray[middleRight] == valueToSearch)
        {
            return middleRight;
        }
        else if(InputArray[middleLeft] > valueToSearch)
        {
            return TernarySearch(start, middleLeft - 1, valueToSearch);
        }
        else if(InputArray[middleRight] < valueToSearch)
        {
            return TernarySearch(middleRight + 1, end, valueToSearch);
        }
        else
        {
            return TernarySearch(middleLeft + 1, middleRight -1, valueToSearch);
        }
    }

    return -1;
}

int Searching::InterpolationSearch(int start, int end, int valueToSearch)
{
    if(start <= end)
    {
        int middle = start + ((valueToSearch - InputArray[start]) * (start - end) / (InputArray[start] - InputArray[end]));

        if(InputArray[middle] == valueToSearch)
        {
            return middle;
        }
        else if(InputArray[middle] > valueToSearch)
        {
            return InterpolationSearch(start, middle - 1, valueToSearch);
        }
        else
        {
            return InterpolationSearch(middle + 1, end, valueToSearch);
        }
    }
    return -1;
}

int Searching::JumpSearch(int valueToSearch)
{
    if(SizeOfArray <= 0)
    {
        return  -1;
    }

    int step = std::sqrt(SizeOfArray);
    int comparingIndexes = 0;

    while(comparingIndexes < SizeOfArray && InputArray[comparingIndexes] < valueToSearch)
    {
        comparingIndexes += step;
    }

    return LinearSearch(comparingIndexes - step, std::min(comparingIndexes, SizeOfArray), valueToSearch);
}

int Searching::ExponentialSearch(int valueToSearch)
{
    if(SizeOfArray <= 0)
    {
        return -1;
    }

    int compareBlock = 1;

    while(compareBlock < SizeOfArray && InputArray[compareBlock] < valueToSearch)
    {
        compareBlock *= 2;
    }

    return BinarySearch(compareBlock / 2, std::min(compareBlock, SizeOfArray), valueToSearch);
}
