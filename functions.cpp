// File:        functions.cpp
// This file contains useful functions usded in the fraction class

using namespace std;

int GCD(int firstNumber, int secondNumber)
{
    int larger, smaller;

    if (firstNumber > secondNumber)
    {
        larger = firstNumber;
        smaller = secondNumber;
    }
    else
    {
        larger = secondNumber;
        smaller = firstNumber;
    }

    while (larger != smaller)
    {
        int tmp = larger - smaller;

        if (tmp < smaller)
        {
            larger = smaller;
            smaller = tmp;
        }
        else if (tmp > smaller)
        {
            larger = tmp;
        }
        else
        {
            return smaller;
        }
    }

    return smaller;  
}