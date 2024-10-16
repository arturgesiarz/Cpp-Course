//
// Created by Artur Gęsiarz on 27/05/2024.
//

#include <vector>
#include <ctime>
#include "mystring.h"

// clear
void MyString::clear() {
    text_.clear();
    size_ = 0;
    capacity_ = 0;
}

// operator []
char MyString::operator[](size_t size) const {
    if (size > size_)
        throw std::out_of_range("Size is bigger than size_!");
    return text_[size];
}

// operator <<
std::ostream &operator<<(std::ostream &os, const MyString &myString) {
    return os << myString.text_;
}

// operator >>
std::istream &operator>>(std::istream &is, MyString &myString) {
    std::string buffer;

    // odczyt do buffera
    while (is >> buffer) {
        myString.text_.append(buffer);
        myString.text_.append(" ");
    }
    myString.capacity_ = myString.text_.capacity();
    myString.size_ = myString.text_.size();
    return is;
}

// operator !=
bool MyString::operator!=(const MyString &rhs) const {
    return text_ != rhs.text_;
}

// operator +=
MyString& MyString::operator+=(const char &word) {
    text_ += word;
    capacity_ = text_.capacity();
    size_ = text_.size();
    return *this;
}

// operator >
bool MyString::operator>(const MyString &other) const {
    return text_ > other.text_;
}

// operator <
bool MyString::operator<(const MyString &other) const {
    return text_ < other.text_;
}

// operator ==
bool MyString::operator==(const MyString &other) const {
    return text_ == other.text_;
}

// trim
void MyString::trim() {

    size_t idFirst = -1;
    size_t idLast = -1;

    // szukanie pierwszego znaku
    for (size_t i = 0; i < size_; i++) {
        if (text_[i] != ' ') {
            idFirst = i;
            break;
        }
    }

    // szukanie drugiego znaku
    for (size_t i = idFirst + 1; i < size_; i++) {
        if (text_[i] != ' ') {
            idLast = i;
        }
    }

    std::string newString = "";

    // pozyskiwanie finalowego stringa
    for (size_t i = idFirst; i <= idLast; i++) {
        newString += text_[i];
    }

    text_ = newString;
    capacity_ = text_.capacity();
    size_ = text_.size();
}

std::set<MyString> MyString::getUniqueWords() const {
    std::set<MyString> uniqueWords;
    std::string copyText = text_;

    // definiuje funkcje anonimowe
    auto to_lower = [](char c) { return std::tolower(c); };
    auto is_space = [](char c) { return std::isspace(c); };
    auto is_punct = [](char c) {return std::ispunct(c);};


    // transformacja tekstu na male litery
    std::transform(copyText.begin(), copyText.end(), copyText.begin(), to_lower);

    // usuwamy z tekstu znaki interpunkcje zwracajac je na sam koniec pod indeksem new_end
    auto new_end = std::remove_if(copyText.begin(), copyText.end(), is_punct);

    // usuwam znaki interpunkcje od new_end to konca copyText
    copyText.erase(new_end, copyText.end());

    // zmienne pomocniczne
    auto i = copyText.begin();
    auto j = copyText.begin();

    while (i != copyText.end()) {
        i = std::find_if_not(i, copyText.end(), is_space);
        j = std::find_if(i, copyText.end(), is_space);

        auto d1 = i - copyText.begin();
        auto d2 = j - copyText.begin();

        // pozyskiwanie slowa
        std::string word = copyText.substr(d1, d2 - d1);

        // tworzenie stringa
        MyString myStringNew = MyString(word);

        uniqueWords.insert(myStringNew);

        // przesuwamy nasze wskazniki
        i = j;
    }

    return uniqueWords;
}

std::map<MyString,size_t> MyString::countWordsUsageIgnoringCases() const {
    std::map<MyString, size_t> map;
    std::string copyText = text_;

    // definiuje funkcje anonimowa
    auto to_lower = [](char c) {return std::tolower(c);};
    auto is_space = [](char c){return std::isspace(c);};
    auto is_punct = [](char c) {return std::ispunct(c);};

    // caly tekst zamieniamy na male litery
    std::transform(copyText.begin(), copyText.end(), copyText.begin(), to_lower);

    // usuwamy z tekstu znaki interpunkcje zwracajac je na sam koniec pod indeksem new_end
    auto new_end = std::remove_if(copyText.begin(), copyText.end(), is_punct);

    // usuwam znaki interpunkcje od new_end to konca copyText
    copyText.erase(new_end, copyText.end());

    // zmienne pomocniczne
    auto i = copyText.begin();
    auto j = copyText.begin();

    while (i != copyText.end()) {
        // znajduje dane slowa
        i = std::find_if_not(i, copyText.end(), is_space);
        j = std::find_if(i, copyText.end(), is_space);

        auto d1 = i - copyText.begin();
        auto d2 = j - copyText.begin();

        // pozyskiwanie slowa
        std::string word = copyText.substr(d1, d2 - d1);

        // sprawdzam czy mapa zawiera dane slowo
        if (map.contains(word)) {
            map[word]++;
        }
        else {
            map[word] = 1;
        }
        i = j;
    }

    return map;
}

void MyString::toLower() {
    auto to_lower = [](char c) {return std::tolower(c);};
    std::transform(text_.begin(), text_.end(), text_.begin(), to_lower);
}

const std::string MyString::generateRandomWord(size_t size) {
    // ustawiamy seed na podstawie biezacego czasu
    std::srand(std::time(nullptr));

    std::string randomWord = "";
    long randomNumber;

    for (size_t i = 0; i < size; i++) {
        long smallOrBigLetter = random() % 2;

        if (smallOrBigLetter) {
            // wielka litera
            randomNumber = random() % 26 + 65;
        } else {
            // mala litera
            randomNumber = random() % 26 + 97;
        }

        char randomLetter = static_cast<char>(randomNumber);
        randomWord += randomLetter;
    }

    return randomWord;
}

bool MyString::startsWith(const char startText[]) const {
    // kopiuje wartosc tekstu do zmiennej
    std::string startTextCopy(startText);

    // poszukuje dwoch pierwszych indeksow na ktorych znajduje sie pierwsze slowo
    auto i = std::find_if_not(text_.begin(), text_.end(), [](char c) {return std::isspace(c); });
    auto j = std::find_if(text_.begin(), text_.end(), [](char c) {return std::isspace(c);});

    // znajduje dany wycinek tekstu
    std::string firstWord = text_.substr(i - text_.begin(), j - i);

    return firstWord.contains(startTextCopy);
}

bool MyString::endsWith(const char endText[]) const {
    // kopiuje wartosc tekstu do zmiennej
    std::string endTextCopy(endText);
    std::string lastWord;

    // definicja funkcji anonimowej
    auto is_space = [](char c){return std::isspace(c);};

    // poszukuje dwoch ostatnich indeksow na ktorych znajduje sie ostatnie slowo
    auto i = text_.begin();
    auto j = text_.begin();

    // znajowanie w petli ostatniego slowa
    while (i != text_.end()) {
        i = std::find_if_not(i, text_.end(), is_space);
        j = std::find_if(i, text_.end(), is_space);

        // pozyskiwanie ostateniego slowa
        lastWord = text_.substr(i - text_.begin(), j - i);
        i = j;
    }

    return lastWord.contains(endTextCopy);
}

const MyString MyString::join(const std::vector<MyString> words) const {
    // zapisuje serparator
    std::string separator(text_);
    std::string solution = "";

    // dodaje do mojego stringa kazdy wraz odpowiednio z spacja oraz przecinkiem
    for (size_t i = 0; i < words.size(); i++) {
        solution += words[i].text_;

        // do ostateiego slowa nie bede dodawal nic
        if (i != words.size() - 1) {
            solution += separator;
        }
    }

    return MyString(solution);
}

bool MyString::all_of(int (*func)(int)) const {
    return std::all_of(text_.begin(), text_.end(), func);
}




