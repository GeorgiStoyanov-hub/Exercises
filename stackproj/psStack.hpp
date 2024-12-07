
#ifndef PSSTACK_HPP
#define PSSTACK_HPP

#include <stdexcept> 
#include <cstddef>    
#include <iostream>   

template<typename T>
class psStack
{
private:
    struct node
    {
        T data;
        node* next;

        node(T data, node* next) noexcept : data(data), next(next) {}
    };

    node *head = nullptr;
    std::size_t current_size;
    std::size_t capacity;

    void deepCopy(const psStack& other) noexcept;

public:
    explicit psStack(std::size_t size) noexcept;
    ~psStack();

    psStack(const psStack& other);
    psStack& operator=(const psStack& other);

    void push(T data);
    void pop();
    T top() const;
    bool isEmpty() const noexcept;
    bool isFull() const noexcept;
    std::size_t stackSize() const noexcept;
};

#include "psStack.tpp"  // Ensure this file is included to handle template code

#endif