#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include <string>
#include "Entry.h"
#include "NodeDictionaryG.h"

class EnglishDictionary {
private:
    std::string name;
    NodeDictionaryG<std::string, std::string> dictionary;

    void printForward(IteratorG<std::string, std::string> it) {
        if (it == dictionary.end()) return;
        std::cout << "[" << it.entry().getK() << ": " << it.entry().getV() << "]\n";
        ++it;
        printForward(it);
    }

    void printBackward(IteratorG<std::string, std::string> it) {
        if (it == dictionary.begin()) return;
        --it;
        std::cout << "[" << it.entry().getK() << ": " << it.entry().getV() << "]\n";
        printBackward(it);
    }

public:
    EnglishDictionary(std::string dictName) : name(dictName) {}
    ~EnglishDictionary() {}

    int words() const { return dictionary.size(); }
    int uniqueWords() const { return dictionary.uniqueKeys(); }
    bool empty() const { return dictionary.empty(); }

    void add(Entry<std::string, std::string> e) {
        dictionary.put(e.getK(), e.getV());
    }

    void deleteFirst(std::string word) {
        dictionary.erase(word);
    }

    void deleteWord(std::string word) {
        Range<std::string, std::string> r = dictionary.findAll(word);
        dictionary.erase(r);
    }

    void printDictionary(bool forward) {
        if (forward) printForward(dictionary.begin());
        else printBackward(dictionary.end());
    }

    void printDictionary(std::string word) {
        Range<std::string, std::string> r = dictionary.findAll(word);
        dictionary.print(r);
    }

    Entry<std::string, std::string> find(std::string word) {
        IteratorG<std::string, std::string> it = dictionary.find(word);
        if (it != dictionary.end())
            return it.entry();
        return Entry<std::string, std::string>();
    }
};

#endif
