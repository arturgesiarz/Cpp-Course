//
// Created by Artur Gęsiarz on 09/05/2024.
//

#ifndef ZAD5MYLISTANDSORTING_MYLIST_H
#define ZAD5MYLISTANDSORTING_MYLIST_H

#include <iostream>
#include <iterator>

#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator

template <typename T>
class MyList {
protected:
    struct Node {
        T data;
        std::unique_ptr<Node> next_;

        Node(const T& data) : data(data), next_(nullptr) {}
    };

    // Potrzebne pola naszej listy
    size_t size_;
    std::unique_ptr<Node> head_;

public:

    MyList() : size_(0), head_(nullptr) {}

    size_t size() const { return size_; }
    void push_front(T item);
    T pop_front();
    T& front() { return head_->data; }

    void remove(T elementToDelete);


    class iterator {
    private:
        Node* ptr_;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        iterator(Node* ptr) : ptr_(ptr) {}

        iterator& operator=(Node *node) {
            ptr_ = node;
            return *this;
        }

        // pre-inkrementacja
        iterator& operator++() {
            if (ptr_ != nullptr)
                ptr_ = ptr_->next_.get();
            return *this;
        }

        // post-inkrementacja
        iterator operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }

    friend bool operator!=(iterator iterator1, iterator iterator2) {
        return iterator1.ptr_ != iterator2.ptr_;
    }

    friend bool operator==(iterator iterator1, iterator iterator2) {
        return iterator1.ptr_ == iterator2.ptr_;
    }

        T& operator*() {
            return ptr_->data;
        }

        T* operator->() {
            return &(ptr_->data);
        }


    };

    class const_iterator {
    private:
        const Node* ptr_;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        const_iterator(const Node* ptr) : ptr_(ptr) {}

        const_iterator& operator++() {
            ptr_ = ptr_->next_.get();
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        const T& operator*() const {
            return ptr_->data;
        }

        const T* operator->() const {
            return &(ptr_->data);
        }

        friend bool operator!=(const const_iterator iterator1, const const_iterator iterator2) {
            return iterator1.ptr_ != iterator2.ptr_;
        }

        friend bool operator==(const const_iterator iterator1, const const_iterator iterator2) {
            return iterator1.ptr_ == iterator2.ptr_;
        }
    };

    using value_type = T;

    iterator begin() { return iterator(head_.get());}
    iterator end() { return iterator(nullptr); }
    const_iterator begin() const { return const_iterator(head_.get());}
    const_iterator end() const { return const_iterator(nullptr); }

    MyList(const MyList&) = delete;
    MyList& operator=(const MyList&) = delete;

    friend std::ostream& operator<<(std::ostream& os, const MyList<T> &other) {
        for(const auto& item : other) {
            os << item << " ";
        }
        os << std::endl;
        return os;
    }
};

template<typename T>
void MyList<T>::remove(T elementToDelete) {
    if (!head_) {
        throw std::out_of_range("Head is null!");
    }

    Node* node_prev = nullptr;
    Node* node_first = head_.get();

    while (node_first) {
        if (elementToDelete == node_first->data) {
            if (node_prev) {
                node_prev->next_ = std::move(node_first->next_);
            } else {
                head_ = std::move(node_first->next_);
            }
            node_first = (node_prev ? node_prev->next_.get() : head_.get());
            size_--;
        } else {
            node_prev = node_first;
            node_first = node_first->next_.get();
        }
    }

}

template<typename T>
void MyList<T>::push_front(T item) {
    auto node = std::make_unique<Node>(item);
    node->next_ = std::move(head_);

    head_ = std::move(node);
    size_++;
}

template<typename T>
T MyList<T>::pop_front() {
    if (!head_) {
        throw std::out_of_range("Head is null!");
    }
    T value = head_->data;
    head_ = std::move(head_->next_);
    size_--;
    return value;
}

#endif //ZAD5MYLISTANDSORTING_MYLIST_H
