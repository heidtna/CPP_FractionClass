// File:        fraction.cpp
// This file contains the specifications for the fraction Class

#include <iostream>
#include <cassert>
#include <cmath>
#include "fraction.h"

fraction::fraction()
{

};

fraction::fraction(int newNumerator, int newDenominator)
{
    numerator = newNumerator;
    denominator = newDenominator;
};

fraction::fraction(double decimalValue)
{
    setFraction(decimalValue);
};

double fraction::decimalValue()
{
    return (double)numerator / (double)denominator;
};

int fraction::calculateGCD(int firstNumber, int secondNumber)
{
    int larger, smaller;

    if ( abs(firstNumber) > abs(secondNumber) )
    {   
        larger = abs(firstNumber);
        smaller = abs(secondNumber);
    }
    else
    {
        larger = abs(secondNumber);
        smaller = abs(firstNumber);
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
};

void fraction::reduce()
{
    // assert(numerator != NULL && denominator != NULL);
    int gcd = calculateGCD(numerator, denominator);

    numerator = numerator / gcd;
    denominator = denominator / gcd;
};

void fraction::setFraction(double decimalValue)
{
    int tempValue;
    int multiplyValue = 1;

    tempValue = decimalValue * multiplyValue;
    while ( (tempValue != decimalValue * multiplyValue) && 
            (multiplyValue <= 100000) )
    {
        multiplyValue = multiplyValue * 10;
        tempValue = decimalValue * multiplyValue;
    }

    numerator = decimalValue * multiplyValue;
    denominator = multiplyValue;
    reduce();
    
};

void fraction::setFraction(int newNumerator, int newDenominator)
{
    numerator = newNumerator;
    denominator = newDenominator;
};

void fraction::setNumerator(int newNumerator)
{
    numerator = newNumerator;
};

void fraction::setDenominator(int newDenominator)
{
    denominator = newDenominator;
};

int fraction::getNumerator() const
{
    return numerator;
};

int fraction::getDenominator() const
{
    return denominator;
};

fraction fraction::operator + (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator - (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator * (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator / (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator > (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator < (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator >= (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator <= (const fraction& fraction) const
{
    return fraction;
};

fraction fraction::operator == (const fraction& fraction) const
{
    return fraction;
};

void fraction::outputFormat(OutputFormat f)
{
    format = f; 
};

OutputFormat fraction::format = mixed;

istream& operator >> (istream& i, fraction& fraction)
{
    i >> fraction.numerator >> fraction.denominator;
    return i;
};

ostream& operator << (ostream& o, const fraction& fraction)
{
    switch(fraction.format)
    {
        case (mixed):
            if (fraction.getNumerator() / fraction.getDenominator() == 0)
            {
                cout << fraction.getNumerator() << "/"
                    << fraction.getDenominator();
            }

            else if (fraction.getNumerator() % fraction.getDenominator() == 0)
            {
                cout << fraction.getNumerator() / fraction.getDenominator();
            }
            
            else
            {
                cout << fraction.getNumerator() / fraction.getDenominator()
                    << ' '
                    << abs(fraction.getNumerator() % fraction.getDenominator())
                    << '/' << fraction.getDenominator();
            }
            break;
        
        case improper:
            cout << fraction.getNumerator() << '/'
                    << fraction.getDenominator();
            break;

        case decimal:
            cout << (double)fraction.getNumerator() / \
                    (double)fraction.getDenominator();
            break;
    }

    return o;
};