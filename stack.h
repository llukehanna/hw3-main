#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack : private std::vector<T> {
public:
    Stack() : std::vector<T>() {}
    ~Stack() {}

    bool empty() const { 
        return std::vector<T>::empty(); 
    }
    size_t size() const { 
        return std::vector<T>::size(); 
    }
    void push(const T& item) { 
        std::vector<T>::push_back(item); 
    }
    void pop() {
        if (empty()) 
            throw std::underflow_error("Stack is empty");
        std::vector<T>::pop_back();
    }
    const T& top() const {
        if (empty()) 
            throw std::underflow_error("Stack is empty");
        return std::vector<T>::back();
    }
};

#endif
