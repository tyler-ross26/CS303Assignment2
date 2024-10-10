#include "Stack.h"

// Constructor
Stack::Stack() {}

// Destructor
Stack::~Stack() {}

// Push an integer onto the stack
void Stack::push(int value) {
    data.push_back(value);
}

// Remove the top integer from the stack
void Stack::pop() {
    if (empty()) {
        throw std::runtime_error("Stack underflow: Cannot pop from an empty stack.");
    }
    data.pop_back();
}

// Get the top integer of the stack
int Stack::top() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty: No top element.");
    }
    return data.back();
}

// Check if the stack is empty
bool Stack::empty() const {
    return data.empty();
}

// Find the average of the stack elements
double Stack::average() const {
    if (empty()) {
        throw std::runtime_error("Cannot compute average of an empty stack.");
    }
    double sum = 0;
    for (int value : data) {
        sum += value;
    }
    return sum / data.size();
}
