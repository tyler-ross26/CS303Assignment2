#pragma once

class SingleLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int num_items;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    void push_front(int item);
    void push_back(int item);
    void pop_front();
    void pop_back();
    int& front();
    int& back();
    bool empty() const;
    void insert(int index, int item);
    bool remove(int index);
    int find(int item) const;
    int size() const;
    int get(int index) const;
};
