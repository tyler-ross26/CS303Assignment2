// Tyler Ross
// CS303 Assignment 2
// 10/10/2024

#include "SingleLinkedList.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
    SingleLinkedList list;

    cout << "Testing Linked List Functions\n";

    // Test push_front
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);

    cout << "List after pushing 20, 10 to front and 30 to back:\n";
    cout << "Front: " << list.front() << "\n"; // Should be 20
    cout << "Back: " << list.back() << "\n";   // Should be 30
    cout << "Size: " << list.size() << "\n";   // Should be 3

    // Test pop_front
    list.pop_front();
    cout << "List after popping front:\n";
    cout << "Front: " << list.front() << "\n"; // Should be 10
    cout << "Size: " << list.size() << "\n";   // Should be 2

    // Test pop_back
    list.pop_back();
    cout << "List after popping back:\n";
    cout << "Back: " << list.back() << "\n";   // Should be 10
    cout << "Size: " << list.size() << "\n";   // Should be 1

    // Test insert
    list.insert(0, 40);
    cout << "List after inserting 40 at index 0:\n";
    cout << "Front: " << list.front() << "\n"; // Should be 40
    cout << "Size: " << list.size() << "\n";   // Should be 2

    // Test remove
    list.remove(0);
    cout << "List after removing at index 0:\n";
    cout << "Front: " << list.front() << "\n"; // Should be 10
    cout << "Size: " << list.size() << "\n";   // Should be 1

    // Test find
    cout << "Finding 10 in the list (should be index 0): " << list.find(10) << "\n";
    cout << "Finding 100 in the list (should be size 1): " << list.find(100) << "\n";

    Stack stack;

    cout << "\nTesting Stack Functions\n";

    // Test if stack is empty
    cout << "Stack is empty: " << (stack.empty() ? "True" : "False") << "\n";

    // Test push
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Pushed 10, 20, 30 onto the stack.\n";

    // Test top
    cout << "Top of stack: " << stack.top() << "\n"; // Should be 30

    // Test average
    cout << "Average of stack: " << stack.average() << "\n"; // Should be 20

    // Test pop
    stack.pop();
    cout << "Popped top element from stack.\n";

    // Test top again
    cout << "New top of stack: " << stack.top() << "\n"; // Should be 20

    return 0;
}