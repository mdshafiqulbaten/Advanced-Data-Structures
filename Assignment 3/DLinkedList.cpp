//DLinkedList.cpp

#include "DLinkedList.h"
#include <iostream>

DLinkedList::DLinkedList() : head(nullptr), trailer(nullptr), count(0) {}

DLinkedList::~DLinkedList() {
    while (!empty())
        removeFront();
}

bool DLinkedList::empty() const {
    return head == nullptr;
}

const int& DLinkedList::front() const {
    return head->elem;
}

const int& DLinkedList::back() const {
    return trailer->elem;
}

void DLinkedList::addFront(const int& e) {
    DNode* newNode = new DNode(e, nullptr, head);
    if (empty()) trailer = newNode;
    else head->prev = newNode;
    head = newNode;
    count++;
}

void DLinkedList::addBack(const int& e) {
    DNode* newNode = new DNode(e, trailer, nullptr);
    if (empty()) head = newNode;
    else trailer->next = newNode;
    trailer = newNode;
    count++;
}

void DLinkedList::removeFront() {
    if (empty()) return;
    DNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else trailer = nullptr;
    delete temp;
    count--;
}

void DLinkedList::removeBack() {
    if (empty()) return;
    DNode* temp = trailer;
    trailer = trailer->prev;
    if (trailer) trailer->next = nullptr;
    else head = nullptr;
    delete temp;
    count--;
}

void DLinkedList::print(bool front) const {
    if (front) {
        DNode* cur = head;
        while (cur) {
            std::cout << cur->elem << " ";
            cur = cur->next;
        }
    } else {
        DNode* cur = trailer;
        while (cur) {
            std::cout << cur->elem << " ";
            cur = cur->prev;
        }
    }
    std::cout << std::endl;
}

int DLinkedList::size() const {
    return count;
}

int DLinkedList::activeNodeCount() const {
    return DNode::activeNodes;
}