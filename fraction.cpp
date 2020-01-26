// File:        fraction.cpp
// This file contains the specifications for the fraction Class

#include <iostream>
#include <cassert>
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

};

double fraction::decimalValue()
{
    assert(numerator != NULL && denominator != NULL);
    double tmpNumerator = static_cast<double>(numerator);
    double tmpDenominator = static_cast<double>(denominator);

    return numerator / denominator;
};

int fraction::calculateGCD(int firstNumber, int secondNumber)
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
};

void fraction::reduce()
{
    assert(numerator != NULL && denominator != NULL);
    int gcd = calculateGCD(numerator, denominator);

    numerator = numerator / gcd;
    denominator = denominator / gcd;
};

void fraction::setFraction(double decimalValue)
{
    
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

bool fraction::operator > (const fraction& fraction) const
{
    return true;
};

bool fraction::operator < (const fraction& fraction) const
{
    return true;
};

bool fraction::operator >= (const fraction& fraction) const
{
    return true;
};

bool fraction::operator >= (const fraction& fraction) const
{
    return true;
};

bool fraction::operator == (const fraction& fraction) const
{
    return true;
};

fraction fraction::outputFormat()
{

};

istream& operator >> (istream& i, const fraction& fraction)
{

};

ostream& operator << (ostream& o, const fraction& fraction)
{

};