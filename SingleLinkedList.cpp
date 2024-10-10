#include "SingleLinkedList.h"
#include <stdexcept>

// Constructor
SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
SingleLinkedList::~SingleLinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add a new element to the front of the list
void SingleLinkedList::push_front(int item) {
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {
        tail = head;
    }
    num_items++;
}

// Add a new element to the end of the list
void SingleLinkedList::push_back(int item) {
    Node* new_node = new Node(item);
    if (tail == nullptr) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Remove the first element
void SingleLinkedList::pop_front() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    num_items--;
}

// Remove the last element
void SingleLinkedList::pop_back() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// Get the element at the front of the list
int& SingleLinkedList::front() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

// Get the element at the back of the list
int& SingleLinkedList::back() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

// Insert an element in the list
void SingleLinkedList::insert(int index, int item) {
    if (index < 0 || index > num_items) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        push_front(item);
    }
    else if (index == num_items) {
        push_back(item);
    }
    else {
        Node* new_node = new Node(item);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        num_items++;
    }
}

// Remove an element from the list
bool SingleLinkedList::remove(int index) {
    if (index < 0 || index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) {
            tail = current;
        }
        delete temp;
        num_items--;
    }
    return true;
}

// Remove the element at a specified index
int SingleLinkedList::find(int item) const {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // item not found
}

// Get the element at a specified index
int SingleLinkedList::get(int index) const {
    if (index < 0 || index >= num_items) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Check if the list is empty
bool SingleLinkedList::empty() const {
    return num_items == 0;
}

// Check the size of the list
int SingleLinkedList::size() const {
    return num_items;
}