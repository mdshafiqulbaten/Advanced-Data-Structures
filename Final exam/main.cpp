#include "EnglishDictionary.h"
#include <iostream>
#include <string>

int main() {
    EnglishDictionary myDictionary("My Awesome English Dictionary");
    myDictionary.add(Entry<std::string, std::string>("apple", "A common fruit."));
    myDictionary.add(Entry<std::string, std::string>("apple", "The tree that bears apples."));
    myDictionary.add(Entry<std::string, std::string>("apple", "A brand of computer and electronics."));
    myDictionary.add(Entry<std::string, std::string>("run", "To move at a speed faster than walking."));
    myDictionary.add(Entry<std::string, std::string>("run", "To operate or manage."));
    myDictionary.add(Entry<std::string, std::string>("run", "A continuous series or sequence."));
    myDictionary.add(Entry<std::string, std::string>("run", "To flow."));
    myDictionary.add(Entry<std::string, std::string>("book", "A written or printed work."));
    myDictionary.add(Entry<std::string, std::string>("bank", "A financial institution."));
    myDictionary.add(Entry<std::string, std::string>("bank", "The land alongside a river or lake."));
    myDictionary.add(Entry<std::string, std::string>("hello", "A greeting."));
    std::cout << "\n--- Initial Dictionary Contents (Forward) ---" << std::endl;
    myDictionary.printDictionary(true);
    std::cout << "\n--- Initial Dictionary Contents (Reverse) ---" << std::endl;
    myDictionary.printDictionary(false);
    std::cout << "\n--- Definitions for 'bank' ---" << std::endl;
    myDictionary.printDictionary("bank");
    std::cout << "\n--- Definitions for 'bank' (demonstrating Range functionality, still forward print) ---" << std::endl;
    myDictionary.printDictionary("bank"); 
    std::cout << "\n--- Deleting first definition of 'apple' ---" << std::endl;
    myDictionary.deleteFirst("apple");
    myDictionary.printDictionary("apple");
    std::cout << "\n--- Searching and printing all definitions for 'run' ---" << std::endl;
    myDictionary.printDictionary("run");
    std::cout << "\n--- Deleting first definition of 'run' ---" << std::endl;
    myDictionary.deleteFirst("run");
    myDictionary.printDictionary("run");
    std::cout << "\n--- Deleting all definitions for 'bank' ---" << std::endl;
    myDictionary.deleteWord("bank");
    myDictionary.printDictionary("bank"); 
    std::cout << "\n--- Final Dictionary Contents (Forward) ---" << std::endl;
    myDictionary.printDictionary(true);
    std::cout << "\n--- Final Dictionary Contents (Reverse) ---" << std::endl;
    myDictionary.printDictionary(false);
    std::cout << "\n--- Testing find for 'nonexistent' ---" << std::endl;
    Entry<std::string, std::string> foundEntry = myDictionary.find("nonexistent");
    if (foundEntry.getK() == "") { 
        std::cout << "Word 'nonexistent' not found." << std::endl;
    }

    return 0;
}