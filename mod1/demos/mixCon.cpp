#include <iostream>
#include <set>
#include <map>
#include <queue>

int main() {
    // Using auto to declare variables
    auto num = 10;
    auto name = "John";

    // Using set to store unique elements
    std::set<int> mySet = {4, 1, 2, 3, 2, 1};
    std::cout << "Set elements:";
    for (auto elem : mySet) {
        std::cout << " " << elem;
    }
    std::cout << std::endl;

    // Using multiset to store duplicate elements
    std::multiset<int> myMultiSet = {4, 1, 2, 3, 2, 1};
    std::cout << "Multiset elements:";
    for (auto elem : myMultiSet) {
        std::cout << " " << elem;
    }
    std::cout << std::endl;

    // Using map to store key-value pairs with unique keys
    std::map<std::string, int> myMap = {{"apple", 5}, {"banana", 3}, {"orange", 2}};
    std::cout << "Map elements:";
    for (auto pair : myMap) {
        std::cout << " (" << pair.first << "," << pair.second << ")";
    }
    std::cout << std::endl;

    // Using multimap to store key-value pairs with duplicate keys
    std::multimap<std::string, int> myMultiMap = {{"apple", 5}, {"banana", 3}, {"apple", 2}};
    std::cout << "Multimap elements:";
    for (auto pair : myMultiMap) {
        std::cout << " (" << pair.first << "," << pair.second << ")";
    }
    std::cout << std::endl;

    // Using priority_queue to store elements with priority
    std::priority_queue<int> myPriorityQueue;
    myPriorityQueue.push(3);
    myPriorityQueue.push(5);
    myPriorityQueue.push(1);
    std::cout << "Priority Queue elements:";
    while (!myPriorityQueue.empty()) {
        std::cout << " " << myPriorityQueue.top();
        myPriorityQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
