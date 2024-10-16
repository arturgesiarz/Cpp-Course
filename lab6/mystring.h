//
// Created by Artur Gęsiarz on 27/05/2024.
//

#ifndef ZAD6MYSTRING_MYSTRING_H
#define ZAD6MYSTRING_MYSTRING_H

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

class MyString {
private:
    std::string text_;
    size_t capacity_;
    size_t size_;

public:
    static const int initialBufferSize_ = 20;

    MyString() : text_(std::string()), capacity_(MyString::initialBufferSize_+text_.capacity()), size_(0) {
        text_.reserve(initialBufferSize_);
    }

    MyString(const char text[]) : text_(text), capacity_(initialBufferSize_ + text_.capacity()), size_(text_.size()) {
        text_.reserve(initialBufferSize_);
    }

    MyString(const MyString &myString) : text_(myString.text_),
    capacity_(initialBufferSize_ + text_.capacity()), size_(text_.size()) {
        text_.reserve(initialBufferSize_);
    }

    MyString(const std::string &word) : text_(word), capacity_(initialBufferSize_ + text_.capacity()), size_(text_.size()){
        text_.reserve(initialBufferSize_);
    }

    std::string::iterator begin() {
        return text_.begin();
    };

    std::string::iterator end() {
        return text_.end();
    }

    std::string::const_iterator begin() const {
        return text_.begin();
    }

    std::string::const_iterator end() const {
        return text_.end();
    }

    std::string::const_iterator cbegin() const {
        return text_.cbegin();
    }

    std::string::const_iterator cend() const {
        return text_.cend();
    }

    auto capacity() const { return capacity_; }

    auto size() const { return size_;}

    bool empty() const { return size_ == 0; }

    void clear();

    void trim();

    std::set<MyString> getUniqueWords() const;

    std::map<MyString,size_t> countWordsUsageIgnoringCases() const;

    void toLower();

    const static std::string generateRandomWord(size_t size);

    bool startsWith(const char text[]) const;

    bool endsWith(const char text[]) const;

    const MyString join(const std::vector<MyString> x) const;

    bool all_of(int (*func)(int a)) const;

    // operator !=
    bool operator!=(const MyString& other) const;

    // operator ==
    bool operator==(const MyString& other) const;

    // operator +=
    MyString& operator+=(const char& text);

    // operator []
    char operator[](size_t size) const;

    // operator >
    bool operator>(const MyString& other) const;

    // operator <
    bool operator<(const MyString& other) const;

    // operator <<
    friend std::ostream& operator<<(std::ostream& os, const MyString& myString);

    // operator >>
    friend std::istream& operator>>(std::istream& is, MyString& myString);


};

#endif //ZAD6MYSTRING_MYSTRING_H
