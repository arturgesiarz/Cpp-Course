#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric>   // std::gcd

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be 0!");
    }
    this->numerator_ = numerator;
    this->denominator_ = denominator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be 0!");
    }
    this->denominator_ = denominator;
}

Fraction Fraction::operator+(Fraction fraction) const {
    int newNumerator;
    int newDenominator;
    int nwdCould;
    if (this->denominator_ == fraction.denominator_) {
        newNumerator = this->numerator_ + fraction.numerator_;
        newDenominator = this->denominator_;

    } else {
        newNumerator = this->numerator_ * fraction.denominator_ + fraction.numerator_ * this->denominator_;
        newDenominator = this->denominator_ * fraction.denominator_;
    }
    nwdCould = std::gcd(newNumerator,newDenominator);
    newNumerator /= nwdCould;
    newDenominator /= nwdCould;

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(Fraction fraction) const {
    int newNumerator = this->numerator_ * fraction.numerator_;
    int newDenominator = this->denominator_ * fraction.denominator_;
    int nwdCould = std::gcd(newNumerator, newDenominator);

    newNumerator /= nwdCould;
    newDenominator /= nwdCould;

    return Fraction(newNumerator, newDenominator);
}
