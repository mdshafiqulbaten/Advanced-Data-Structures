#ifndef DNODEG_H
#define DNODEG_H

#include "Entry.h"

template <typename K, typename V>
class DNodeG {
public:
    Entry<K, V> elm;
    DNodeG<K, V>* prev;
    DNodeG<K, V>* next;
    
    static int activeNodes;

    DNodeG(const Entry<K, V>& e = Entry<K, V>(), DNodeG<K, V>* p = nullptr, DNodeG<K, V>* n = nullptr)
        : elm(e), prev(p), next(n) {
        ++activeNodes;
    }

    ~DNodeG() {
        --activeNodes;
    }
};

template <typename K, typename V>
int DNodeG<K, V>::activeNodes = 0;

#endif