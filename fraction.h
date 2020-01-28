// File:        fraction.h
// Author:      Nathan Heidt
// This file contains the specifications for the fraction class
#ifndef FRACTION_CLASS
#define FRACTION_CLASS

#include <iostream>
#include <cmath>

using namespace std;

enum OutputFormat {improper, decimal, mixed};

class fraction
{

    public:
        fraction();                 // no argument constructor
        fraction(int, int);         // two int constructor
        fraction(double);           // decimal constructor
        int calculateGCD(int, int); // calculate the greatest common divisor
        double decimalValue();      // calculate and return decimal value
        void reduce();              // simplify fraction to lowest terms
        void setFraction(double);   // modify attribute values
        void setFraction(int, int); // modify attribute values
        void setNumerator(int);     // set numerator attribute
        void setDenominator(int);   // set denominator attribute
        int getNumerator() const;   // return numerator value
        int getDenominator() const; // return denominator value
        fraction operator + (const fraction&) const;    // overload addition operator
        fraction operator - (const fraction&) const;    // overload subtraction operator
        fraction operator * (const fraction&) const;    // overload multiplication operator
        fraction operator / (const fraction&) const;    // overload division operator
        fraction operator > (const fraction&) const;    // overload greater than relational operator
        fraction operator < (const fraction&) const;    // overload less than relational operator
        fraction operator >= (const fraction&) const;   // overload greater than or equal to relational operator
        fraction operator <= (const fraction&) const;   // overload less than or equal to relational operator
        fraction operator == (const fraction&) const;   // overlaod equal to relational operator

        static void outputFormat(OutputFormat); // use enum -> see Example 'circle2'
        // set default in imp as one line

        friend istream& operator >> (istream&, fraction&);    // overload input operator
        friend ostream& operator << (ostream&, const fraction&);   // overload output operator
    
    private:
        int numerator;
        int denominator;
        static OutputFormat format;

};

#endif
