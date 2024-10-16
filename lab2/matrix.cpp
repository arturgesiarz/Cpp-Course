#include <iostream>
#include <cstring>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix() {  // konstruktor bezparametrowy
    for(size_t i = 0; i < size_; i++){
        for(size_t j = 0; j < size_; j++){
            matrix_[i][j] = 0;
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& other) {  // konstruktor kopiujacy
    for(size_t i = 0; i < size_; i++) {
        for(size_t j = 0; j < size_; j++){
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix[size_][size_]) {  // konstruktor dodatkowy
    for(size_t i = 0; i < size_; i++) {
        for(size_t j = 0; j < size_; j++) {
            matrix_[i][j] = matrix[i][j];
        }
    }
}

MatrixElement TwoDimensionMatrix::get(size_t i, size_t j) const {
    return matrix_[i][j];
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix& other) {  // operator przypisania kopiujacy
    if (this != &other) {
        memcpy(matrix_, other.matrix_, size_ * size_ * sizeof(MatrixElement));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const TwoDimensionMatrix& matrix) {  // operator wypisywania do strumienia
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            os << matrix.get(i,j) << ' ';
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, TwoDimensionMatrix& matrix){  // operator wczytywania z strumienia
    MatrixElement solutionMatrix[TwoDimensionMatrix::size()][TwoDimensionMatrix::size()];

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            is >> std::setw(1) >> solutionMatrix[i][j];
        }
    }

    if (!is.fail()) {
        matrix = TwoDimensionMatrix(solutionMatrix);
    }

    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
    MatrixElement solutionMatrix[TwoDimensionMatrix::size()][TwoDimensionMatrix::size()];

    for (size_t i = 0; i < matrix1.size(); i++) {
        for (size_t j = 0; j < matrix1.size(); j++) {
            solutionMatrix[i][j] = matrix1.get(i, j) + matrix2.get(i, j);
        }
    }

    return TwoDimensionMatrix(solutionMatrix);
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (size_t i = 0; i < size_; i++ ) {
        for (size_t j = 0; j < size_; j++) {
            this->matrix_[i][j] *= number;
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const {
    MatrixElement solutionMatrix[TwoDimensionMatrix::size()][TwoDimensionMatrix::size()];

    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++) {
            solutionMatrix[i][j] = abs(matrix_[i][j]) && abs(matrix.matrix_[i][j]);
        }
    }

    return TwoDimensionMatrix(solutionMatrix);
}

MatrixElement* TwoDimensionMatrix::operator[](size_t i) {
    return matrix_[i];
}

const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
    return matrix_[i];
}

TwoDimensionMatrix::operator size_t() const {
    return size();
}

TwoDimensionMatrix::~TwoDimensionMatrix(){
}

