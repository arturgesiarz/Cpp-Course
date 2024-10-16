//
// Created by Artur Gęsiarz on 26/05/2024.
//

#ifndef ZAD5MYLISTANDSORTING_MYSORTING_H
#define ZAD5MYLISTANDSORTING_MYSORTING_H

#include "myList.h"

template<typename T>
void mySort(T (&array)) {
    size_t len = std::size(array);

    for(size_t i = 0; i < len; i++) {
        for(size_t j = 0; j < len - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j+1]);
            }
        }
    }
}

template<typename T>
void mySort(MyList<T> &array) {

    for (auto value_i = array.begin(); value_i != array.end(); value_i++) {
        for (auto value_j = value_i; value_j != array.end(); value_j++) {
            if (*value_i > *value_j ) {
                std::swap(*value_i, *value_j);
            }
        }
    }
}

template<size_t N, size_t M>
void mySort(char (&array)[N][M]) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N - 1; j++) {
            char stringOne[M];
            char stringTwo[M];

            strncpy(stringOne, array[j], std::size(array[j]));
            strncpy(stringTwo, array[j + 1], std::size(array[j+1]));

            // Konwersja nowo utworzonych stringów na wielkie litery
            for (size_t k = 0; k < std::size(array[j]); k++) {
                stringOne[k] = std::toupper(stringOne[k]);
            }
            for (size_t k = 0; k < std::size(array[j + 1]); k++) {
                stringTwo[k] = std::toupper(stringTwo[k]);
            }

            // porownywanie stringow - przypadek jesli wczesniejszy string jest wiekszy od nastepnego.
            if (strcmp(stringOne, stringTwo) > 0) {
                std::swap(array[j], array[j + 1]);
            }

        }
    }
}


#endif //ZAD5MYLISTANDSORTING_MYSORTING_H
