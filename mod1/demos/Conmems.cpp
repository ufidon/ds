#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

int main() {
    // Vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    std::cout << "Vector size: " << vec.size() << std::endl;

    // List
    std::list<int> li;
    li.push_front(3);
    li.push_front(4);
    std::cout << "List size: " << li.size() << std::endl;

    // Deque
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_front(6);
    std::cout << "Deque size: " << deq.size() << std::endl;

    // Map
    std::map<int, std::string> mp;
    mp.insert({1, "one"});
    mp.insert({2, "two"});
    std::cout << "Map size: " << mp.size() << std::endl;

    // Set
    std::set<int> st;
    st.insert(1);
    st.insert(2);
    std::cout << "Set size: " << st.size() << std::endl;

    return 0;
}