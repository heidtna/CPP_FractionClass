# CPP_FractionClass
A Fraction Class and test file written in C++

File:       README
Author:     Nathan Heidt
Program:    Assignment 4
Date:       01-31-2020

BUILDING THE PROGRAM
    This program was written in C++ and can be built
    on a Linux system using g++ compiler. To BUILDING
    program type 'make' at the command line to create 
    the executable called 'prog4'

RUNNING THE PROGRAM
    Type 'prog4' at the command line after building

PROGRAM DESCRIPTION
    This program will read in two integer numbers and 
    initialize a 'fraction' object with the first number
    as the numerator and the second as the denominator.
    The program will then go through a series of tests on
    the 'fraction' class's member variables and functions
    with corresponding outputs. 

PROGRAM INPUT
    Input for this program can either be through the
    keyboard at the terminal or through redirected input.

PROGRAM OUTPUT
    Program will first output the 'fraction' object created
    by initial user input, and then will output other
    fraction objects defined and modified throughout the 
    'main' program.

PROGRAM DESIGN
    Program implements a 'fraction' class, of which objects
    can be created with either a default constructor, or 
    constructors that take either two integer numbers or a
    decimal number, and performs the necessary operations to 
    store the fraction as numerator and denominator integer 
    values. The 'fraction' class allows users to then perform
    operations with the 'fraction' object, including the
    overloading of arithmetic and relational operators.

FILE INDEX
    File            Functions               Description 
    -------------   ------------------      --------------------
    fraction.h                              fraction class header

    fraction.cpp    fraction                default constructor (3 overloads)
                    calculateGCD            calculates Greatest Common Denominator
                                            of two integer numbers
                    decimalValue            calculates decimal value of fraction
                    reduce                  convert fraction to lowest terms
                    setFraction             assign new values to fraction (2 overloads)
                    setNumerator            assign new numerator value
                    setDenominator          change denominator value and reassign
                                            numerator to maintain ratio (error otherwise)
                    getNumerator            return numerator value
                    getDenominator          return denominator value
                    <operator overloads>    allow arithmetic and relational operations 
                                            on fraction objects
                    outputFormat            change class-level format for output
                    

    main.cpp        main                    calls other functions

    makefile

    README

PROGRAM TESTING
    This program was tested using different input methods

    Input Type      Input Values    Result
    --------------------------------------
    keyboard        2 3             2/3
    file            2 4             2/4

    There are currently no known bugs. Errors should be reported to Author at:
    heidtna@mnstate.edu


