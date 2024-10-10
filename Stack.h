#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

class Stack {
public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    double average() const;

private:
    std::vector<int> data;
};
