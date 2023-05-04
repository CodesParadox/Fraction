#ifndef TASK3_FRACTION_HPP
#define TASK3_FRACTION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

namespace ariel {

    //Operators Fraction
    class Fraction {
    private:
        int numerator;
        int denominator;

        void simplify();

    public:
        Fraction();

        Fraction(int numerator, int denominator);

        Fraction(const Fraction &fraction);

        Fraction(Fraction &&fraction);

        ~Fraction();

        Fraction &operator=(const Fraction &fraction);

        Fraction &operator=(Fraction &&fraction);

        Fraction operator+(const Fraction &fraction) const;

        Fraction operator-(const Fraction &fraction) const;

        Fraction operator*(const Fraction &fraction) const;

        Fraction operator/(const Fraction &fraction) const;

        Fraction &operator+=(const Fraction &fraction);

        Fraction &operator-=(const Fraction &fraction);

        Fraction &operator*=(const Fraction &fraction);

        Fraction &operator/=(const Fraction &fraction);

        Fraction operator-() const;

        Fraction operator+() const;

        bool operator==(const Fraction &fraction) const;

        bool operator!=(const Fraction &fraction) const;

        bool operator<(const Fraction &fraction) const;

        bool operator>(const Fraction &fraction) const;

        bool operator<=(const Fraction &fraction) const;

        bool operator>=(const Fraction &fraction) const;

        Fraction &operator++();

        Fraction &operator--();

        Fraction operator++(int);

        Fraction operator--(int);

        explicit operator double() const;

        explicit operator string() const;

        friend ostream &operator<<(ostream &out, const Fraction &fraction);

        friend istream &operator>>(istream &in, Fraction &fraction);
    };

    //Constructors
    Fraction::Fraction() {
        //Default constructor
        this->numerator = 0;
        this->denominator = 1;
        //cout << "Default constructor" << endl;
    }

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("denominator can't be 0");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->simplify();
    }

}
#endif //TASK3_FRACTION_HPP
