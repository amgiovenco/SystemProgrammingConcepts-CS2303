#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Rational.h" // Including the Rational class header file

/*****************************************************
* Rational (const int n, const int d)
* Constructor using two integers: numerator and denominator                          
*******************************************************/
Rational::Rational (const int n, const int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator can't be zero"); // Throwing an exception if denominator is zero
    }
    this->num = n; // Assigning value to the numerator
    this->denom = d; // Assigning value to the denominator
    simplify(num, denom); // Simplify the rational number
}

/*****************************************************
* Rational (const int wholeNumber) : num(wholeNumber), denom(1)
*Constructor using one integer (for whole numbers)
*******************************************************/
Rational::Rational (const int wholeNumber) : num(wholeNumber), denom(1) {
    // Creates a rational number equivalent to the whole number provided
    simplify(num, denom); // Simplify the rational number
}

/*****************************************************
* Rational (const Rational &a) : num(a.num), denom(a.denom)
*Copy Constructor (creates a new object as a copy)
*******************************************************/
Rational::Rational (const Rational &a) : num(a.num), denom(a.denom) {
    // Creates new Rational object with the same numerator and denominator as 'a'
    simplify(num, denom); // Simplify the rational number
}

/*****************************************************
* Rational() : num(0), denom(1) 
* Default constructor (no parameters)
*******************************************************/
Rational::Rational() : num(0), denom(1) {
    // This sets default values for the rational number: 0/1
    simplify(num, denom); // Simplify the rational number
}

/*****************************************************
* void Rational::simplify(int& num, int& denom) {
* Function to simplify the rational number
*******************************************************/
void Rational::simplify(int& num, int& denom) {
    int gcdValue = gcd(num, denom); // Find GCD of numerator and denominator
    num /= gcdValue; // Divide the numerator by GCD
    denom /= gcdValue; // Divide the denominator by GCD

    // If the denominator is negative, adjust both numerator and denominator to keep the denominator positive
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
}

/*****************************************************
* int Rational::gcd(int a, int b)
* Function to calculate the Greatest Common Divisor (GCD) using recursion
*******************************************************/
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}

/*****************************************************
* std::ostream& operator<<(std::ostream& out, const Rational &a) {
* Overloaded operator<< to print the Rational object using an ostream object
*******************************************************/
std::ostream& operator<<(std::ostream& out, const Rational &a) {
    out << a.num;  // Format: numerator/denominator
    if (a.denom != 1) {
        out << '/' << a.denom;
    }
    return out;
}

// Overloaded operator>> to read the Rational object from an istream object
/*****************************************************
* Rational() : num(0), denom(1) 
* Default constructor (no parameters)
*******************************************************/
std::istream& operator>>(istream& in1, Rational &a) {
    int num1, denom2;
    string frac1;
    string delimiter = "/";
    in1 >> frac1;
    int end = frac1.find(delimiter, 0);
    if (end > 0){
        num1 = std::stoi((frac1.substr(0, end)));
        denom2 = std::stoi(frac1.substr(end + 1, frac1.size()));
        a.simplify(num1, denom2);
        a.num = num1;
        a.denom = denom2;
        }
        else{
            if (frac1.size()){
                a.num = std::stoi((frac1));
                a.denom = 1;
            }
        }
        return in1;
    }

/*****************************************************
* Rational Rational::operator+(const Rational &a) {
* Overloaded operator+ to add two Rational objects
*******************************************************/
Rational Rational::operator+(const Rational &a) const {
    // Creating a new Rational object with the sum of the current object and the one passed as a parameter
    int commonDenominator = denom * a.denom; // Calculate common denominator
    int numeratorSum = num * a.denom + a.num * denom; // Calculate the sum of numerators
    Rational result(numeratorSum, commonDenominator); // Create a new Rational object with the sum
    return result; // The 'simplify' method is called in the constructor, so the result is simplified
}

/*****************************************************
* Rational Rational::operator-(const Rational &a) {
* Overloaded operator- to subtract two Rational objects
*******************************************************/
Rational Rational::operator-(const Rational &a) {
    // Similar to operator+, but performs subtraction instead
    int commonDenominator = denom * a.denom;
    int numeratorDifference = num * a.denom - a.num * denom;
    Rational result(numeratorDifference, commonDenominator);
    return result;
}

/*****************************************************
* Rational Rational::operator*(const Rational &a) {
* Overloaded operator* to multiply two Rational objects
*******************************************************/
Rational Rational::operator*(const Rational &a) {
    // Performs multiplication of two rational numbers
    int newNumerator = num * a.num;
    int newDenominator = denom * a.denom;
    Rational result(newNumerator, newDenominator); // Create a new Rational object with the product
    return result;
}

/*****************************************************
* Rational Rational::operator/(const Rational &a) {
* Overloaded operator/ to divide two Rational objects
*******************************************************/
Rational Rational::operator/(const Rational &a) {
    if (a.num == 0) {
        throw std::invalid_argument("Division by zero !"); // Can't divide by zero
    }
    // Performs division of two rational numbers
    int newNumerator = num * a.denom;
    int newDenominator = denom * a.num;
    Rational result(newNumerator, newDenominator); // Create a new Rational object with the quotient
    return result;
}

/*****************************************************
* bool Rational::operator==(const Rational &a) {
* Overloaded operator== to check equality of two Rational objects
*******************************************************/
bool Rational::operator==(const Rational &a) {
    return num == a.num && denom == a.denom; // True if both numerator and denominator are equal
}

/*****************************************************
* bool Rational::operator!=(const Rational &a) {
* Overloaded operator!= to check inequality of two Rational objects
*******************************************************/
bool Rational::operator!=(const Rational &a) {
    return !(*this == a); // The opposite of operator==
}

/*****************************************************
* bool Rational::operator<(const Rational &a) 
* Overloaded comparison operators to compare two Rational objects
*******************************************************/
bool Rational::operator<(const Rational &a) {
    return num * a.denom < a.num * denom; // True if the first is less than the second
}

/*****************************************************
* bool Rational::operator>(const Rational &a)
* > Overload
*******************************************************/
bool Rational::operator>(const Rational &a) {
    return num * a.denom > a.num * denom; // True if the first is greater than the second
}

/*****************************************************
* bool Rational::operator<=(const Rational &a) 
* <= Overload
*******************************************************/
bool Rational::operator<=(const Rational &a) {
    return num * a.denom <= a.num * denom; // True if the first is less than or equal to the second
}

/*****************************************************
* bool Rational::operator>=(const Rational &a) 
* >= Overload
*******************************************************/
bool Rational::operator>=(const Rational &a) {
    return num * a.denom >= a.num * denom; // True if the first is greater than or equal to the second
}