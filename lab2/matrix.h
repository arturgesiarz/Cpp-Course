#ifndef MATRIX_H
#define MATRIX_H

/** @file matrix.h
@brief Przeciążanie operatorów na przykładzie Macierzy (bardziej szczegolowa tresc w README.md):
1. Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
    X tablice typu MatrixElement (tzn. int), oraz `size_` (=2)
    X konstruktory:
        X bezargumentowy - zerujący wszystkie elementy
        X kopiujący
        X przyjmujący jako argument tablicę (const MatrixElement matrix[size_][size_]) i kopiujący z niej wartości
    X funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
    X funkcja zwracająca `size_` o nazwie `size()`, proponuję aby była `static constexpr`
    X po zaimplementowaniu usun makro `UNIMPLEMENTED_CONSTRUCTORS`
2. Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
    X operator przypisania kopiujący (głęboko): `operator=()`
       X po zaimplementowaniu usun makro `UNIMPLEMENTED_ASIGNMENT_OPERATOR`
    !! operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
       - po zaimplementowaniu usun makro `UNIMPLEMENTED_OSTREAM_OPERATOR`
    !! operatory wczytywania z strumienia (funkcja zewn.) - format dla macierzy:
      { a, b }
      { c, d }
      powinno się odbyć:
      ```
        a b
        c d
      ```
       - po zaimplementowaniu usun makro `UNIMPLEMENTED_ISTREAM_OPERATOR`
    - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
        X `TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna`
        X `TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy`
        X Zadany operator logiczny (metoda klasy):
          `TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;`
           - po zaimplementowaniu usun makro `UNIMPLEMENTED_ARITHMETIC_OPERATORS`
    X operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), **proszę pamiętać o wersji const**
          `MatrixElement* operator[](size_t i);`
       - po zaimplementowaniu usun makro `UNIMPLEMENTED_SUBSCRIPT_OPERATOR`
    X operator konwersji do size_t, zwracający to co `size()` (metoda klasy)
       - po zaimplementowaniu usun makro `UNIMPLEMENTED_CONVERSION_OPERATOR`
Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"
____________________________________________________________________________________
## Uwaga (bardziej wiazaca tresc jest w pliku `README.md`):
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

Mozna tworzyc dowolna ilosc metod pomocniczych, jednakze aby byly one prywatne.
____________________________________________________________________________________
## Punktacja:
Na maksa przejście wszystkich testów i niepoprawnych operacji na pamieci (m.in. wyciekow pamieci)
____________________________________________________________________________________
## Najczestrze pytania:
1. Jak ma działać && dla macierzy?
    Wykonująca na każdym z elementów &&, czyli:
    ```
    { 0, 0 }      { 0, 6 }      { 0, 0 }
    {-3, 9 }  &&  { 0, -9 }  =  { 0, 1 }
    ```
2. Jak ma działać operator tablicowy []?
    Operator ten przyjmuje tylko jeden argument (poza this), a chcemy odnieść się w następujący sposób:
    `matrix[row][column]`, dlatego ten operator musi zwrócić matrix[row] typu `MatrixElement*`.
3. Mam operator indeksowania [], a kompilator jakby go nie widzi.
    To najczęstrzy błąd w tym zadaniu - muszą być dwie wersje - jedna zwykła, a druga stała (przydomek `const`)
____________________________________________________________________________________
# Pytania po implementacji ćwiczenia:
@note A. Jaka jest różnica między przeciążaniem operatorów jako metoda klasy vs jako funkcja?
 -> Roznia jest taka ze jesli operator przeciazamy w klasie to zawsze ( w przypadku kiedy jest dwuargumentowy ), element glowny musi stac po lewej stronie a po prawiej cos innego,
 -> kiedy zaimplementujemy to w funkjci poza klasa juz nie muismy sie martwic o kolejnosc,
 -> kolejna roznica bedzie to ze zaimplementowa w klasie ma dostep do atrybutow oraz funkcji
@note B. Których operatorów nie da się przeciążać?
 -> . -> ::
@note C. Wymień operatory mające różną ilość argumentów?
 -> + - ! ~ ++ -- * & sizeof() : majace jeden argument
 -> + - * / % == != itd. : majace dwa argumenty
@note D. Jakie konsekwencje będzie miało przeciążanie operatorów logicznych? (chodzi o lazy-evaluation)
**/

#include <iosfwd>

#include "matrixElement.h"

class TwoDimensionMatrix {
    constexpr static size_t size_ = 2;

public:
    TwoDimensionMatrix();
    TwoDimensionMatrix(const TwoDimensionMatrix& other);
    TwoDimensionMatrix(const MatrixElement matrix[size_][size_]);

    MatrixElement get(size_t i, size_t j) const;

    static constexpr size_t size() {
        return size_;
    }

    TwoDimensionMatrix& operator=(const TwoDimensionMatrix& other);
    TwoDimensionMatrix& operator*=(MatrixElement number);
    TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
    MatrixElement* operator[](size_t i);
    const MatrixElement* operator[](size_t i) const;
    operator size_t() const;

    ~TwoDimensionMatrix();

private: // methods:

private: // fields:
    MatrixElement matrix_[size_][size_];
};

std::istream& operator>>(std::istream& is, TwoDimensionMatrix& matrix);
std::ostream& operator<<(std::ostream& os, const TwoDimensionMatrix& matrix);
TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2);

#endif // MATRIX_H
