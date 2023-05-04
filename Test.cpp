#include "doctest.h"
#include <string>
#include "sources/Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("GOOD INPUT"){
    CHECK(Fraction(1,2).getNumerator() == 1);
    CHECK(Fraction(1,2).getDenominator() == 2);
    CHECK(Fraction(1,2).toString() == "1/2");
    CHECK(Fraction(1,2).toDouble() == 0.5);
    CHECK(Fraction(1,2).toRational() == "1/2");
    CHECK(Fraction(1,2).operator==(Fraction(1,2)));
    CHECK(Fraction(1,2).operator!=(Fraction(1,3)));
    CHECK(Fraction(1,2).operator<(Fraction(1,1)));
    CHECK(Fraction(1,2).operator>(Fraction(1,3)));
    CHECK(Fraction(1,2).operator<=(Fraction(1,2)));
    CHECK(Fraction(1,2).operator>=(Fraction(1,2)));
    CHECK(Fraction(1,2).operator+(Fraction(1,2)) == Fraction(1,1));
    CHECK(Fraction(1,2).operator-(Fraction(1,2)) == Fraction(0,1));
    CHECK(Fraction(1,2).operator*(Fraction(1,2)) == Fraction(1,4));
    CHECK(Fraction(1,2).operator/(Fraction(1,2)) == Fraction(1,1));
    CHECK(Fraction(1,2).operator-() == Fraction(-1,2));
    CHECK(Fraction(1,2).operator+() == Fraction(1,2));
    CHECK(Fraction(1,2).operator+=(Fraction(1,2)) == Fraction(1,1));
    CHECK(Fraction(1,2).operator-=(Fraction(1,2)) == Fraction(0,1));
    CHECK(Fraction(1,2).operator*=(Fraction(1,2)) == Fraction(1,4));
    CHECK(Fraction(1,2).operator/=(Fraction(1,2)) == Fraction(1,1));
    CHECK(Fraction(1,2).operator++() == Fraction(3,2));
    CHECK(Fraction(1,2).operator--() == Fraction(-1,2));
    CHECK(Fraction(1,2).operator++(1) == Fraction(3,2));
    CHECK(Fraction(1,2).operator--(1) == Fraction(-1,2));
    CHECK(Fraction(1,2).operator==(1.0/2));

}

TEST_CASE("edge cases"){
    CHECK_EQ(Fraction(1,2).getNumerator(),1);
    CHECK_EQ(Fraction(1,2).getDenominator(),2);
    CHECK_EQ(Fraction(1,2).toString(),"1/2");
    CHECK_EQ(Fraction(1,2).toDouble(),0.5);
    CHECK_EQ(Fraction(1,2).toRational(),"1/2");
    CHECK_GT(Fraction(1,2),Fraction(1,3));
    CHECK_LT(Fraction(1,2),Fraction(1,1));
    CHECK_GE(Fraction(1,2),Fraction(1,2));
    CHECK_LE(Fraction(1,2),Fraction(1,2));
    CHECK_EQ(Fraction(1,2)+Fraction(1,2),Fraction(1,1));
    CHECK_EQ(Fraction(1,2)-Fraction(1,2),Fraction(0,1));
    CHECK_EQ(Fraction(1,2)*Fraction(1,2),Fraction(1,4));
    CHECK_EQ(Fraction(1,2)/Fraction(1,2),Fraction(1,1));
    CHECK_EQ(Fraction(1,2)-(),Fraction(-1,2));
    CHECK(Fraction(1,2)+() == Fraction(1,2));
    CHECK_THROWS(Fraction(1,2)+Fraction(1,0));
    CHECK_THROWS(Fraction(1,2)-Fraction(1,0));

}
//Tests for the class Fraction - GOOD INPUT
TEST_CASE("Good"){
    Fraction f1(1,2);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
    CHECK(f1.toString() == "1/2");
    CHECK(f1.toDouble() == 0.5);
    CHECK(f1.toRational() == "1/2");
    CHECK(f1.operator==(Fraction(1,2)));
    CHECK(f1.operator!=(Fraction(1,3)));
    CHECK(f1.operator<(Fraction(1,1)));
    CHECK(f1.operator>(Fraction(1,3)));
    CHECK(f1.operator<=(Fraction(1,2)));
    CHECK(f1.operator>=(Fraction(1,2)));
    CHECK(f1.operator+(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator-(Fraction(1,2)) == Fraction(0,1));
    CHECK(f1.operator*(Fraction(1,2)) == Fraction(1,4));
    CHECK(f1.operator/(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator-() == Fraction(-1,2));
    CHECK(f1.operator+() == Fraction(1,2));
    CHECK(f1.operator+=(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator-=(Fraction(1,2)) == Fraction(0,1));
    CHECK(f1.operator*=(Fraction(1,2)) == Fraction(1,4));
    CHECK(f1.operator/=(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator++() == Fraction(3,2));
    CHECK(f1.operator--() == Fraction(-1,2));
    CHECK(f1.operator++(1) == Fraction(3,2));
    CHECK(f1.operator--(1) == Fraction(-1,2));
    CHECK(f1.operator==(1.0/2));


}
//Tests Edge Cases
TEST_CASE("edge cases"){
    CHECK_EQ(Fraction(1,2).getNumerator(),1);
    CHECK_EQ(Fraction(1,2).getDenominator(),2);
    CHECK_EQ(Fraction(1,2).toString(),"1/2");
    CHECK_EQ(Fraction(1,2).toDouble(),0.5);
    CHECK_EQ(Fraction(1,2).toRational(),"1/2");
    CHECK_GT(Fraction(1,2),Fraction(1,3));
    CHECK_LT(Fraction(1,2),Fraction(1,1));
    CHECK_GE(Fraction(1,2),Fraction(1,2));
    CHECK_LE(Fraction(1,2),Fraction(1,2));
    CHECK_EQ(Fraction(1,2)+Fraction(1,2),Fraction(1,1));
    CHECK_EQ(Fraction(1,2)-Fraction(1,2),Fraction(0,1));
    CHECK_EQ(Fraction(1,2)*Fraction(1,2),Fraction(1,4));
    CHECK_EQ(Fraction(1,2)/Fraction(1,2),Fraction(1,1));
    CHECK_EQ(Fraction(1,2)-(),Fraction(-1,2));
    CHECK(Fraction(1,2)+() == Fraction(1,2));
    CHECK_THROWS(Fraction(1,2)+Fraction(1,0));
    CHECK_THROWS(Fraction(1,2)-Fraction(1,0));

}

// Tests base on the Fraction class
TEST_CASE("Test Fraction") {
    Fraction f1(1, 2);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
    CHECK(f1.toString() == "1/2");
    CHECK(f1.toDouble() == 0.5);
    CHECK(f1.toRational() == "1/2");
    CHECK(f1.operator==(Fraction(1,2)));
    CHECK(f1.operator!=(Fraction(1,3)));
    CHECK(f1.operator<(Fraction(1,1)));
    CHECK(f1.operator>(Fraction(1,3)));
    CHECK(f1.operator<=(Fraction(1,2)));
    CHECK(f1.operator>=(Fraction(1,2)));
    CHECK(f1.operator+(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator-(Fraction(1,2)) == Fraction(0,1));
    CHECK(f1.operator*(Fraction(1,2)) == Fraction(1,4));
    CHECK(f1.operator/(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator-() == Fraction(-1,2));
    CHECK(f1.operator+() == Fraction(1,2));
    CHECK(f1.operator+=(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator-=(Fraction(1,2)) == Fraction(0,1));
    CHECK(f1.operator*=(Fraction(1,2)) == Fraction(1,4));
    CHECK(f1.operator/=(Fraction(1,2)) == Fraction(1,1));
    CHECK(f1.operator++() == Fraction(3,2));
    CHECK(f1.operator--() == Fraction(-1,2));
    CHECK(f1.operator++(1) == Fraction(3,2));
    CHECK(f1.operator--(1) == Fraction(-1,2));
    CHECK(f1.operator==(1.0/2));
}

/*
 * TEST_CASE("BAD INPUT"){
 *    CHECK_THROWS(Fraction(1,0));
 *    CHECK_THROWS(Fraction(1,0));
 *
 *
 *
TEST_CASE("Test Addition") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 + f2;
    REQUIRE(f3 == Fraction(5, 4));

    Fraction f4(-1, 2);
    Fraction f5(-3, 4);
    Fraction f6 = f4 + f5;
    REQUIRE(f6 == Fraction(-5, 4));
}

TEST_CASE("Test Subtraction") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction f3 = f1 - f2;
    REQUIRE(f3 == Fraction(1, 4));

    Fraction f4(-3, 4);
    Fraction f5(-1, 2);
    Fraction f6 = f4 - f5;
    REQUIRE(f6 == Fraction(-1, 4));
}

TEST_CASE("Test Multiplication") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction f3 = f1 * f2;
    REQUIRE(f3 == Fraction(3, 8));

    Fraction f4(-3, 4);
    Fraction f5(-1, 2);
    Fraction f6 = f4 * f5;
    REQUIRE(f6 == Fraction(3, 8));
}

TEST_CASE("Test Division") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction f3 = f1 / f2;
    REQUIRE(f3 == Fraction(3, 2));

    Fraction f4(-3, 4);
    Fraction f5(-1, 2);
    Fraction f6 = f4 / f5;
    REQUIRE(f6 == Fraction(3, 2));
}

TEST_CASE("Test Equality") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(6, 8);
    REQUIRE(f1 == f2);
    REQUIRE(f1 == f3);
    REQUIRE(f2 == f3);

    Fraction f4(-1, 2);
    Fraction f5(-3, 4);
    Fraction f6(-6, 8);
    REQUIRE(f4 == f5);
    REQUIRE(f4 == f6);
    REQUIRE(f5 == f6);
}

TEST_CASE("Test Inequality") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 3);
    REQUIRE(f1 != f2);
    REQUIRE(f1 != f3);
    REQUIRE(f2 != f3);

    Fraction f4(-1, 2);
    Fraction f5(-3, 4);
    Fraction f6(-2, 3);
    REQUIRE(f4 != f5);
    REQUIRE(f4 != f6);
    REQUIRE(f5 != f6);
}

TEST_CASE("Test Less Than") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 3);
    REQUIRE(f1 < f2);
    REQUIRE(f1 < f3);
    REQUIRE(f2 < f3);

    Fraction f4(-1, 2);
    Fraction f5(-3, 4);
    Fraction f6(-2, 3);
    REQUIRE(f5 < f4);
    REQUIRE(f5 < f6);
    REQUIRE(f4 < f6);
 */