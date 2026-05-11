#include "HStack.hpp"
#include <iostream>
using namespace std;

Node::Node(int val) : value(val), next(nullptr) {}

Stack::Stack() :head(nullptr) {}
Stack::Stack(int value) : head(nullptr) {
    head = new Node(value);
}
Stack::Stack(int value, int count) : head(nullptr) {
    for (int i = 0; i < count; i++) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
}
Stack::~Stack() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
Stack Stack:: operator+(Stack& otherSt) {
    Stack result;
    Node* upper = head;
    while (upper->next != nullptr)
    {
        upper = upper->next;
    }
    upper->next = otherSt.head;
    result.head = head;
    head = nullptr;
    otherSt.head = nullptr;
    return result;
}
void Stack::print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}