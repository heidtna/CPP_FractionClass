// File:        fraction.cpp
// This file contains the specifications for the fraction Class

#include <iostream>
#include <cassert>
#include <cmath>
#include "fraction.h"

fraction::fraction()
{
    numerator = 0;
    denominator = 1;
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

double fraction::decimalValue() const
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
    double diffValue = (double) newDenominator / denominator;
    double checkValue = numerator * diffValue;
    
    if (checkValue == numerator*diffValue)
    {
        numerator = numerator * diffValue;
        denominator = newDenominator;
    }
    else
    {
        cout << "Error--Numerator would not be a whole number" << endl;
    }
    
};

int fraction::getNumerator() const
{
    return numerator;
};

int fraction::getDenominator() const
{
    return denominator;
};

fraction fraction::operator + (const fraction& frac) const
{

    int resultNumerator, resultDenominator;

    int firstFracNumerator = numerator;
    int fristFracDenominator = denominator;

    int secondFracNumerator = frac.numerator;
    int secondFracDenominator = frac.denominator;

    firstFracNumerator = numerator * frac.denominator;
    fristFracDenominator = denominator * frac.denominator;

    secondFracNumerator = frac.numerator * denominator;
    secondFracDenominator = frac.denominator * denominator;

    resultNumerator = firstFracNumerator + secondFracNumerator;
    resultDenominator = fristFracDenominator;

    fraction tmp(resultNumerator, resultDenominator);
    tmp.reduce();
    
    return tmp;
};

fraction fraction::operator - (const fraction& frac) const
{
    int resultNumerator, resultDenominator;

    int firstFracNumerator = numerator;
    int fristFracDenominator = denominator;

    int secondFracNumerator = frac.numerator;
    int secondFracDenominator = frac.denominator;

    firstFracNumerator = numerator * frac.denominator;
    fristFracDenominator = denominator * frac.denominator;

    secondFracNumerator = frac.numerator * denominator;
    secondFracDenominator = frac.denominator * denominator;

    resultNumerator = firstFracNumerator - secondFracNumerator;
    resultDenominator = fristFracDenominator;

    fraction tmp(resultNumerator, resultDenominator);
    tmp.reduce();

    return tmp;
};

fraction fraction::operator * (const fraction& frac) const
{
    int resultNumerator = numerator * frac.numerator;
    int resultDenominator = denominator * frac.denominator;

    fraction tmp(resultNumerator, resultDenominator);
    tmp.reduce();

    return tmp;
};

fraction fraction::operator / (const fraction& frac) const
{
    int resultNumerator = numerator * frac.denominator;
    int resultDenominator = denominator * frac.numerator;

    fraction tmp(resultNumerator, resultDenominator);
    tmp.reduce();

    return tmp;
};

bool fraction::operator > (const fraction& frac) const
{
    return (decimalValue() > frac.decimalValue());
};

bool fraction::operator < (const fraction& frac) const
{
    return (decimalValue() < frac.decimalValue());
};

bool fraction::operator >= (const fraction& frac) const
{
    return (decimalValue() >= frac.decimalValue());
};

bool fraction::operator <= (const fraction& frac) const
{
    return (decimalValue() <= frac.decimalValue());
};

bool fraction::operator == (const fraction& frac) const
{
    return (decimalValue() == frac.decimalValue());
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