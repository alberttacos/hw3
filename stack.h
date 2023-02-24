#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    private:
    std::vector<T> stack;
};

template <typename T>
Stack<T>::Stack(){

}
template <typename T>
Stack<T>::~Stack(){

}

template <typename T>
bool Stack<T>::empty()const {
    return stack.empty();
}

template <typename T>
size_t Stack<T>::size() const{
    return stack.size();
}

template <typename T>
void Stack<T>::push(const T& item){
    stack.push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(stack.empty()){
        throw std::underflow_error("Tried to pop on an empty stack");
    } else{
        stack.pop_back();
    }
}
template <typename T>
const T& Stack<T>::top() const{
    if(stack.empty()){
        throw std::underflow_error("Tried to pop on an empty stack");
    }
    else{
        return stack.back();
    }
}


#endif