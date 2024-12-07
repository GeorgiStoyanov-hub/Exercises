#ifndef PSSTACK_TPP
#define PSSTACK_TPP

#include "psStack.hpp"
#include <stdexcept>  // for exceptions
#include <cstddef>    // for size_t

template<typename T>
psStack<T>::psStack(std::size_t size) noexcept : head(nullptr), capacity(size), current_size(0) {}

template<typename T>
psStack<T>::~psStack() noexcept
{
    while (head)
    {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
psStack<T>::psStack(const psStack& other) : head(nullptr), current_size(0), capacity(other.capacity)
{
    deepCopy(other);
}

template<typename T>
psStack<T>& psStack<T>::operator=(const psStack& other)
{
    if (this != &other)
    {
        while (!isEmpty())
        {
            pop();
        }
        deepCopy(other);
    }
    return *this;
}

template<typename T>
void psStack<T>::push(T data)
{
    if (current_size >= capacity)
    {
        throw std::overflow_error("Stack overflow. Stack capacity is full.");
    }
    node* newNode = new node(data, head);
    head = newNode;
    ++current_size;
}

template<typename T>
void psStack<T>::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack underflow. Stack is empty.");
    }

    node* temp = head;
    head = head->next;
    delete temp;
    --current_size;
}

template<typename T>
T psStack<T>::top() const 
{
    if (!head)
    {
        throw std::underflow_error("Stack underflow. Stack is empty.");
    }
    return head->data;
}

template<typename T>
bool psStack<T>::isEmpty() const noexcept
{
    return head == nullptr;
}

template<typename T>
bool psStack<T>::isFull() const noexcept
{
    return current_size == capacity;
}

template<typename T>
size_t psStack<T>::stackSize() const noexcept
{
    return current_size;
}

template<typename T>
void psStack<T>::deepCopy(const psStack& other) noexcept
{
    capacity = other.capacity;
    current_size = 0;
    head = nullptr;

    node* tempNode = other.head;
    while (tempNode)
    {
        push(tempNode->data);
        tempNode = tempNode->next;
    }
}

#endif