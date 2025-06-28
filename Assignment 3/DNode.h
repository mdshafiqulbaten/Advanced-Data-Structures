//DNode.h
#ifndef DNODE_H
#define DNODE_H

class DNode {
private:
    int elem;            
    DNode* prev;         
    DNode* next;         

public:
    static int activeNodes;

   
    DNode(int e = 0, DNode* p = nullptr, DNode* n = nullptr)
        : elem(e), prev(p), next(n) {
        activeNodes++;
    }

    
    ~DNode() {
        activeNodes--;
    }

    
    friend class DLinkedList;
};

#endif