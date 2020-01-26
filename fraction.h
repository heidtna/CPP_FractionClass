// File:        fraction.h
// Author:      Nathan Heidt
// This file contains the specifications for the fraction class
#ifndef FRACTION_CLASS
#define FRACTION_CLASS

#include <iostream>

using namespace std;

class fraction
{
    public:
        fraction();             // no argument constructor
        fraction(int, int);     // two int constructor
        fraction(double);       // decimal constructor
        int calculateGCD(int, int); // calculate the greatest common divisor
        double decimalValue();  // calculate and return decimal value
        void reduce();          // simplify fraction to lowest terms
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
        bool fraction::operator > (const fraction&) const;    // overload greater than relational operator
        bool fraction::operator < (const fraction&) const;    // overload less than relational operator
        bool fraction::operator >= (const fraction&) const;   // overload greater than or equal to relational operator
        bool fraction::operator <= (const fraction&) const;   // overload less than or equal to relational operator
        bool fraction::operator == (const fraction&) const;   // overlaod equal to relational operator

        static fraction outputFormat();

        friend istream& operator >> (istream&, const fraction&);    // overload input operator
    
    private:
        int numerator;
        int denominator;

};

ostream& operator << (ostream&, const fraction&);   // overload output operator

#endif
