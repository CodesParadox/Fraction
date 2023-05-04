#include "Fraction.hpp"
#include "doctest.h"
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <cmath>
#include <sstream>


using namespace std;

namespace ariel {
    // Constructors
    Fraction::Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Error: denominator cannot be zero.");
        }
        this->reduce();
    }

    // Getters
    int Fraction::getNumerator() const {
        return this->m_numerator;
    }

    int Fraction::getDenominator() const {
        return this->m_denominator;
    }

    // Simplify the fraction
    void Fraction::reduce() {
        int gcd = std::gcd(this->m_numerator, this->m_denominator);
        this->m_numerator /= gcd;
        this->m_denominator /= gcd;

        if (this->m_denominator < 0) {
            this->m_numerator *= -1;
            this->m_denominator *= -1;
        }
    }

    // Arithmetic operators
    Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
        int numerator = lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator();
        int denominator = lhs.getDenominator() * rhs.getDenominator();
        return Fraction(numerator, denominator);
    }

    Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
        int numerator = lhs.getNumerator() * rhs.getDenominator() - rhs.getNumerator() * lhs.getDenominator();
        int denominator = lhs.getDenominator() * rhs.getDenominator();
        return Fraction(numerator, denominator);
    }

    Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
        int numerator = lhs.getNumerator() * rhs.getNumerator();
        int denominator = lhs.getDenominator() * rhs.getDenominator();
        return Fraction(numerator, denominator);
    }

    Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
        if (rhs.getNumerator() == 0) {
            throw std::invalid_argument("Error: division by zero.");
        }

        int numerator = lhs.getNumerator() * rhs.getDenominator();
        int denominator = lhs.getDenominator() * rhs.getNumerator();
        return Fraction(numerator, denominator);
    }

    // Comparison operators
    bool operator==(const Fraction &lhs, const Fraction &rhs) {
        return lhs.getNumerator() == rhs.getNumerator() && lhs.getDenominator() == rhs.getDenominator();
    }

    bool operator!=(const Fraction &lhs, const Fraction &rhs) {
        return !(lhs == rhs);
    }

    bool operator<(const Fraction &lhs, const Fraction &rhs) {
        return lhs.getNumerator() * rhs.getDenominator() < rhs.getNumerator() * lhs.getDenominator();
    }

    bool operator>(const Fraction &lhs, const Fraction &rhs) {
        return rhs < lhs;
    }

    bool operator<=(const Fraction &lhs, const Fraction &rhs) {
        return !(rhs < lhs);
    }

    bool operator>=(const Fraction &lhs, const Fraction &rhs) {
        return !(lhs < rhs);
    }

    // Increment and decrement operators
    Fraction &Fraction::operator++() {
        // Pre-increment
        this->m_numerator += this->m_denominator;
        this->reduce();
        return *this;
    }

    // Comparison operators
    bool Fraction::operator==(const Fraction& other) const {
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }

    bool Fraction::operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool Fraction::operator>(const Fraction& other) const {
        double this_decimal = (double)this->numerator / this->denominator;
        double other_decimal = (double)other.numerator / other.denominator;
        return this_decimal > other_decimal;
    }

    bool Fraction::operator>=(const Fraction& other) const {
        return *this == other || *this > other;
    }

    bool Fraction::operator<(const Fraction& other) const {
        return !(*this >= other);
    }

    bool Fraction::operator<=(const Fraction& other) const {
        return !(*this > other);
    }

// Increment and decrement operators
    Fraction& Fraction::operator++() { // pre-increment
        this->numerator += this->denominator;
        reduce();
        return *this;
    }

    Fraction& Fraction::operator--() { // pre-decrement
        this->numerator -= this->denominator;
        reduce();
        return *this;
    }

    Fraction Fraction::operator++(int) { // post-increment
        Fraction temp(*this);
        ++(*this);
        return temp;
    }

    Fraction Fraction::operator--(int) { // post-decrement
        Fraction temp(*this);
        --(*this);
        return temp;
    }

// Input and output operators
    std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << '/' << f.denominator;
        return os;
    }

    std::istream& operator>>(std::istream& is, Fraction& f) {
        int n, d;
        is >> n >> d;
        f = Fraction(n, d);
        return is;
    }


}


//#include "Fraction.hpp"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <cmath>
//#include <algorithm>
//#include <cstdlib>
//#include <numeric>
//using namespace std;
//
//
//
//namespace ariel {
//
////Operators Fraction
//    Fraction::Fraction(int numerator, int denominator) {
//        if (denominator == 0) {
//            throw std::invalid_argument("denominator can't be 0");
//        }
//        this->numerator = numerator;
//        this->denominator = denominator;
//        this->reduce();
//    }
//
//    Fraction::Fraction(const Fraction &fraction) {
//        this->numerator = fraction.numerator;
//        this->denominator = fraction.denominator;
//    }
//
//    Fraction::Fraction(Fraction &&fraction) {
//    this->numerator = fraction.numerator;
//    this->denominator = fraction.denominator; }
//
//    Fraction::~Fraction() {}
//
//
//Fraction &Fraction::operator=(const Fraction &fraction) {
//    this->numerator = fraction.numerator;
//    this->denominator = fraction.denominator;
//    return *this;
//}
//
//Fraction &Fraction::operator=(Fraction &&fraction){
//this->numerator = fraction.numerator;
//this->denominator = fraction.denominator;
//return *this;
//}
//
//Fraction Fraction::operator+(const Fraction &fraction) const {
//    int newNumerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
//    int newDenominator = this->denominator * fraction.denominator;
//    return Fraction(newNumerator, newDenominator);
//}
//
//Fraction Fraction::operator-(const Fraction &fraction) const {
//    int newNumerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
//    int newDenominator = this->denominator * fraction.denominator;
//    return Fraction(newNumerator, newDenominator);
//}
//
//Fraction Fraction::operator*(const Fraction &fraction) const {
//    int newNumerator = this->numerator * fraction.numerator;
//    int newDenominator = this->denominator * fraction.denominator;
//    return Fraction(newNumerator, newDenominator);
//}
//
//Fraction Fraction::operator/(const Fraction &fraction) const {
//    int newNumerator = this->numerator * fraction.denominator;
//    int newDenominator = this->denominator * fraction.numerator;
//    return Fraction(newNumerator, newDenominator);
//}
//
//Fraction &Fraction::operator+=(const Fraction &fraction) {
//    int newNumerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
//    int newDenominator = this->denominator * fraction.denominator;
//    this->numerator = newNumerator;
//    this->denominator = newDenominator;
//    return *this;
//}
//
//Fraction &Fraction::operator-=(const Fraction &fraction) {
//    int newNumerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
//    int newDenominator = this->denominator * fraction.denominator;
//    this->numerator = newNumerator;
//    this->denominator = newDenominator;
//    return *this;
//}
//
//Fraction &Fraction::operator*=(const Fraction &fraction) {
//    int newNumerator = this->numerator * fraction.numerator;
//    int newDenominator = this->denominator * fraction.denominator;
//    this->numerator = newNumerator;
//    this->denominator = newDenominator;
//    return *this;
//}
//
//Fraction &Fraction::operator/=(const Fraction &fraction) {
//    int newNumerator = this->numerator * fraction.denominator;
//    int newDenominator = this->denominator * fraction.numerator;
//    this->numerator = newNumerator;
//    this->denominator = newDenominator;
//    return *this;
//}
//
//Fraction Fraction::operator-() const {
//    return Fraction(-this->numerator, this->denominator);
//}
//
//Fraction Fraction::operator+() const {
//    return Fraction(this->numerator, this->denominator);
//}
//
//bool Fraction::operator==(const Fraction &fraction) const {
//    return this->numerator == fraction.numerator && this->denominator == fraction.denominator;
//}
//
//bool Fraction::operator!=(const Fraction &fraction) const {
//    return !(*this == fraction);
//}
//
//bool Fraction::operator<(const Fraction &fraction) const {
//    return this->numerator * fraction.denominator < fraction.numerator * this->denominator;
//}
//
//bool Fraction::operator>(const Fraction &fraction) const {
//    return this->numerator * fraction.denominator > fraction.numerator * this->denominator;
//}
//
//bool Fraction::operator<=(const Fraction &fraction) const {
//    return !(*this > fraction);
//}
//
//bool Fraction::operator>=(const Fraction &fraction) const {
//    return !(*this < fraction);
//}
//
//Fraction &Fraction::operator++() {
//    this->numerator += this->denominator;
//    return *this;
//}
//
//Fraction &Fraction::operator--() {
//    this->numerator -= this->denominator;
//    return *this;
//}
//
//Fraction Fraction::operator++(int) {
//    Fraction temp = *this;
//    this->numerator += this->denominator;
//    return temp;
//}
//
//Fraction Fraction::operator--(int) {
//    Fraction temp = *this;
//    this->numerator -= this->denominator;
//    return temp;
//}
//
//Fraction::operator double() const {
//    return (double) this->numerator / (double) this->denominator;
//}
//
//Fraction::operator int() const {
//    return this->numerator / this->denominator;
//}
//
//Fraction::operator float() const {
//    return (float) this->numerator / (float) this->denominator;
//}
//
//Fraction::operator long() const {
//    return (long) this->numerator / (long) this->denominator;
//}
//
//Fraction::operator long long() const {
//    return (long long) this->numerator / (long long) this->denominator;
//}
//
//Fraction::operator short() const {
//    return (short) this->numerator / (short) this->denominator;
//}
//
//Fraction::operator unsigned int() const {
//    return (unsigned int) this->numerator / (unsigned int) this->denominator;
//}
//
//Fraction::operator unsigned long() const {
//    return (unsigned long) this->numerator / (unsigned long) this->denominator;
//}
//
//Fraction::operator unsigned long long() const {
//    return (unsigned long long) this->numerator / (unsigned long long) this->denominator;
//}
//
//Fraction::operator unsigned short() const {
//    return (unsigned short) this->numerator / (unsigned short) this->denominator;
//}
//
//ostream operator<<(ostream &os, const Fraction &fraction) {
//    os << fraction.numerator << "/" << fraction.denominator;
//    return os;
//}
//
//istream operator>>(istream &is, Fraction &fraction) {
//    int numerator, denominator;
//    char c;
//    is >> numerator >> c >> denominator;
//    if (denominator == 0) {
//        throw std::invalid_argument("Denominator can't be 0");
//    }
//    fraction.numerator = numerator;
//    fraction.denominator = denominator;
//    fraction.reduce();
//    return is;
//}
//
//void Fraction::reduce() {
//    int gcd = this->gcd(this->numerator, this->denominator);
//    this->numerator /= gcd;
//    this->denominator /= gcd;
//}
//
//int Fraction::gcd(int a, int b) {
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//int Fraction::lcm(int a, int b) {
//    return (a * b) / gcd(a, b);
//}
//
//Fraction operator+(int a, const Fraction &fraction) {
//    return Fraction(a) + fraction;
//
//}
//
//Fraction operator-(int a, const Fraction &fraction) {
//    return Fraction(a) - fraction;
//}



}