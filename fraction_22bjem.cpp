#include "fraction_22bjem.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Default constructor
Fraction::Fraction() : numerator(0), denominator(1) {}

// Constructor for whole number
Fraction::Fraction(int num) : numerator(num), denominator(1) {}

// Constructor with numerator and denominator
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw FractionException("Denominator cannot be zero");
    }
    normalize();
}

// Helper function to normalize the fraction
void Fraction::normalize() {
    int gcd = greatestCommonDivisor(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /= gcd;

    // Ensure denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// GCD function
int Fraction::greatestCommonDivisor(int a, int b) const {
    return (b == 0) ? a : greatestCommonDivisor(b, a % b);
}

// Unary negation operator
Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

// Post-increment operator
Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}

// Pre-increment operator
Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

// Addition assignment operator
Fraction& Fraction::operator+=(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    normalize();
    return *this;
}

// Comparison operators
bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator<=(const Fraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Fraction::operator>=(const Fraction& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator;
}

// Arithmetic operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int num = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
    int denom = lhs.denominator * rhs.denominator;
    return Fraction(num, denom);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int num = lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator;
    int denom = lhs.denominator * rhs.denominator;
    return Fraction(num, denom);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.numerator == 0) {
        throw FractionException("Cannot divide by zero");
    }
    return Fraction(lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator);
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}

// Stream operators
ostream& operator<<(ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& fraction) {
    int num = 0;
    int denom = 1;
    char slash;

    is >> num;
    if (is.peek() == '/') {
        is >> slash >> denom;
    }

    if (denom == 0) {
        throw FractionException("Denominator cannot be zero");
    }

    fraction = Fraction(num, denom);
    return is;
}
