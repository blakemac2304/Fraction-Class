/*
 * Author: Blake MacPherson
 * Header file for Fraction Class
 */

/*
 * Fraction Class Header
 * fraction_netid.h
 * Created on: Oct 8, 2024
 * Author: [Your Name]
 *
 * This header file defines the Fraction class, which represents a mathematical fraction
 * in its simplest form, along with the FractionException class for handling errors.
 */

#ifndef FRACTION_NETID_H_
#define FRACTION_NETID_H_

#include <iostream>
#include <stdexcept>
#include <string>

// Exception class for Fraction-specific errors
class FractionException : public std::exception {
public:
    explicit FractionException(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string errorMessage;
};

// Fraction class to handle mathematical fractions in normalized form
class Fraction {
public:
    Fraction();
    Fraction(int);
    Fraction(int, int);

    int getNumerator() const;
    int getDenominator() const;

    Fraction operator-() const;
    Fraction& operator++();        // Pre-increment
    Fraction operator++(int);      // Post-increment
    Fraction& operator+=(const Fraction&);

    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);

    friend bool operator==(const Fraction&, const Fraction&);
    friend bool operator!=(const Fraction&, const Fraction&);
    friend bool operator<(const Fraction&, const Fraction&);
    friend bool operator<=(const Fraction&, const Fraction&);
    friend bool operator>(const Fraction&, const Fraction&);
    friend bool operator>=(const Fraction&, const Fraction&);

    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);

private:
    int numerator;
    int denominator;

    void normalize();
    int gcd(int, int) const;
};

#endif /* FRACTION_NETID_H_ */
