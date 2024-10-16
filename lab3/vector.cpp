#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include "vector.h"

std::size_t Vector::size() const noexcept {
    return this->size_;
}

std::size_t Vector::capacity() const noexcept {
    return this->capacity_;
}

std::unique_ptr<Fraction[]>& Vector::data() noexcept {
    return this->data_;
}

Vector::Vector(std::size_t sizeToAllocation) : data_(nullptr), size_(0), capacity_(sizeToAllocation) {
    if (sizeToAllocation > 0) {
        data_ = std::make_unique<Fraction[]>(sizeToAllocation);
    }
}

Vector::Vector(const Vector& vector) : size_(vector.size_), capacity_(vector.capacity_){
    data_ = std::make_unique<Fraction[]>(vector.capacity_);
    for (std::size_t i = 0; i < vector.size_; i++) {
        data_[i] = vector.data_[i];
    }
}

Vector::Vector(Vector&& vector) : size_(vector.size_), capacity_(vector.capacity_) {
    data_ = std::make_unique<Fraction[]>(vector.capacity_);
    for (std::size_t i = 0; i < vector.size_; i++) {
        data_[i] = vector.data_[i];
    }
    vector.data_ = std::move(nullptr);
    vector.size_ = 0;
    vector.capacity_ = 0;
}

Vector& Vector::operator=(const Vector &vector) {
    if (this != &vector) {
        size_ = vector.size_;
        capacity_ = vector.capacity_;
        data_ = std::make_unique<Fraction[]>(capacity_);

        for (std::size_t i = 0; i < size_; i++) {
            data_[i] = vector.data_[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& vector) {
    if (this != &vector) {
        size_ = vector.size_;
        capacity_ = vector.capacity_;
        data_ = std::make_unique<Fraction[]>(capacity_);

        for (std::size_t i = 0; i < size_; i++) {
            data_[i] = vector.data_[i];
        }
        vector.data_ = nullptr;
        vector.capacity_ = 0;
        vector.size_ = 0;
    }
    return *this;
}

void Vector::push_back(const Fraction &value) {

    // case when we have to allocate new memory
    if (size_ >= capacity_) {
        capacity_ = capacity_ == 0 ? 1 : ++capacity_;
        std::unique_ptr<Fraction[]> newData = std::make_unique<Fraction[]>(capacity_);

        // adding old values to new memory
        for (std::size_t i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }

        // moving
        data_ = std::move(newData);

    }
    data_[size_++] = value;
}

const Fraction& Vector::operator[](std::size_t index) const {
    if (size_ > index) {
        return data_[index];
    } else
        throw std::out_of_range("You are going beyond the scope Captain!");
}

Fraction& Vector::operator[](std::size_t index) {
    if (size_ > index) {
        return data_[index];
    } else
        throw std::out_of_range("You are going beyond the scope Captain!");
}
