#include <iostream>
using namespace std;

#include "fraction.h"

#ifdef _MSC_FULL_VER // if Visual Studio Compiler
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#else

int Fraction::removedFractions_ = 0;

Fraction::Fraction(int numerator_, int denominator_, std::string fractionName_){
    this->numerator_ = numerator_;
    this->denominator_ = denominator_;
    this->fractionName_ = fractionName_;
}

int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    return denominator_;
}

std::string Fraction::getFractionName() const {
    return fractionName_;
}

const int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}

int Fraction::getDefaultDenominatorValue() {
    return defaultDenominatorValue;
}

int Fraction::removedFractions() {
    return removedFractions_;
}

void Fraction::setNumerator(int numerator) {
    numerator_ = numerator;
}

void Fraction::setDenominator(int denominator) {
    denominator_ = denominator;
}

void Fraction::print() const{
    std::cout << numerator_ << "/" << denominator_ << std::endl;
}

void Fraction::save(std::ostream& os) const {
    os << numerator_ << "/" << denominator_;
}

void Fraction::load(std::istream& is) {
    char slash = '/';
    is >> numerator_ >> slash >> denominator_;
}

Fraction::~Fraction(){
    removedFractions_++;
}


#endif // #ifdef _MSC_FULL_VER