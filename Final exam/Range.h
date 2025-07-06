#ifndef RANGE_H
#define RANGE_H

#include "IteratorG.h"

template <typename K, typename V>
class Range {
private:
    IteratorG<K, V> b;
    IteratorG<K, V> e;

public:
    Range(const IteratorG<K, V>& b, const IteratorG<K, V>& e) : b(b), e(e) {}
    IteratorG<K, V>& getB() { return b; }
    IteratorG<K, V>& getE() { return e; }
};

#endif
