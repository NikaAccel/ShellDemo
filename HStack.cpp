#include "HStack.hpp"
#include <iostream>
using namespace std;

Node::Node(int val): value(val), next(nullptr){}

Stack::Stack() : head(nullptr) {}
Stack::Stack(int value) : head(new Node(value)) {}
Stack::Stack(int value, int count) : head(nullptr) {
    for (int i = 0; i < count; i++)
        head = new Node(value);
}
Stack::~Stack() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
Stack Stack:: operator+(Stack& otherSt){
    Stack result;
    Node* upper = head;
    while(upper->next !=nullptr)upper = upper->next;
    upper->next = otherSt.head;
    result.head = head;
    head = otherSt.head = nullptr;
    return result;
}
void Stack::print() const {
    for (Node* current = head; current; current = current->next)
        cout << current->value << " ";
    cout << endl;
}
