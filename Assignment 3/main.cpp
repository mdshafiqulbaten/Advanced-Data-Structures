//main.cpp

#include <iostream>
#include "DLinkedList.h"

int DNode::activeNodes = 0;

int main() {
    DLinkedList list;

    list.addFront(10);
    list.addFront(20);
    list.addFront(30);

    list.addBack(40);
    list.addBack(50);

    std::cout << "Print from front: ";
    list.print(true);

    std::cout << "Print from back: ";
    list.print(false);

    list.removeFront();
    list.removeBack();

    std::cout << "After removing front and back: ";
    list.print(true);

    list.addFront(5);
    list.addBack(60);

    std::cout << "Final list: ";
    list.print(true);

    std::cout << "Total active nodes: " << list.activeNodeCount() << std::endl;

    return 0;
}