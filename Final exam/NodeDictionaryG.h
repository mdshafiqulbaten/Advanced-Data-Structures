#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include <iostream>
#include "DNodeG.h"
#include "IteratorG.h"
#include "Range.h"

template <typename K, typename V>
class NodeDictionaryG {
private:
    int uKeys;
    int n;
    DNodeG<K, V>* header;
    DNodeG<K, V>* trailer;

    bool hasOtherKey(const K& k) const {
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            if (it.entry().getK() == k)
                return true;
        }
        return false;
    }

    void add(DNodeG<K, V>* before, const Entry<K, V>& e);

public:
    NodeDictionaryG() {
        n = 0;
        uKeys = 0;
        header = new DNodeG<K, V>();
        trailer = new DNodeG<K, V>();
        header->next = trailer;
        trailer->prev = header;
    }

    ~NodeDictionaryG() {
        while (!empty()) erase(begin());
        delete header;
        delete trailer;
    }

    int size() const { return n; }
    int uniqueKeys() const { return uKeys; }
    bool empty() const { return n == 0; }

    IteratorG<K, V> begin() const { return IteratorG<K, V>(header->next); }
    IteratorG<K, V> end() const { return IteratorG<K, V>(trailer); }

    IteratorG<K, V> find(const K& k) const {
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            if (it.entry().getK() == k)
                return it;
        }
        return end();
    }

    Range<K, V> findAll(const K& k) {
        IteratorG<K, V> b = end(), e = end();
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            if (it.entry().getK() == k) {
                if (b == end())
                    b = it;
                e = it;
            }
        }
        if (e != end()) ++e;
        return Range<K, V>(b, e);
    }

    IteratorG<K, V> put(const K& k, const V& v) {
        IteratorG<K, V> current = end();
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            if (it.entry().getK() == k)
                current = it;
        }

        Entry<K, V> newEntry(k, v);
        if (current == end()) {
            add(trailer->prev, newEntry);
            ++uKeys;
            return IteratorG<K, V>(trailer->prev);
        } else {
            add(current.getNode(), newEntry);
            return IteratorG<K, V>(current.getNode()->next);
        }
    }

    
    void erase(const K& k)
    {
    
     IteratorG<K, V> it = find(k);
     if (it != end())
         erase(it);
    
    }

    void erase(const IteratorG<K, V>& p) {
        DNodeG<K, V>* node = p.getNode();
        K key = node->elm.getK();

        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --n;
        bool keyStillExists = false;
        for (IteratorG<K, V> it = begin(); it != end(); ++it) 
        {
            if (it.entry().getK() == key) return;
            
        }

        if (!keyStillExists)
            --uKeys;
    }

    void erase(Range<K, V>& r) {
        IteratorG<K, V> it = r.getB();
        while (it != r.getE()) {
            IteratorG<K, V> next = it;
            ++next;
            erase(it);
            it = next;
        }
    }

    void print() {
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            std::cout << "[" << it.entry().getK() << ": " << it.entry().getV() << "]\n";
        }
    }

    void print(Range<K, V>& r) {
        for (IteratorG<K, V> it = r.getB(); it != r.getE(); ++it) {
            std::cout << "[" << it.entry().getK() << ": " << it.entry().getV() << "]\n";
        }
    }
};


template <typename K, typename V>
void NodeDictionaryG<K, V>::add(DNodeG<K, V>* before, const Entry<K, V>& e) {
    DNodeG<K, V>* newNode = new DNodeG<K, V>(e, before, before->next);
    before->next->prev = newNode;
    before->next = newNode;
    ++n;
}

#endif