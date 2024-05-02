#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>

int main() {
    // Vector
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // List
    std::list<int> lst = {6, 7, 8, 9, 10};

    // Deque
    std::deque<int> deq = {11, 12, 13, 14, 15};

    // Stack
    std::stack<int> stk;
    for (int i = 16; i <= 20; ++i)
        stk.push(i);

    // Queue
    std::queue<int> que;
    for (int i = 21; i <= 25; ++i)
        que.push(i);

    // Priority Queue
    std::priority_queue<int> pq;
    for (int i = 26; i <= 30; ++i)
        pq.push(i);

    // Set
    std::set<int> st;
    for (int i = 31; i <= 35; ++i)
        st.insert(i);

    // MultiSet
    std::multiset<int> mst;
    for (int i = 31; i <= 35; ++i)
        mst.insert(i);

    // Map
    std::map<int, std::string> mp;
    mp[36] = "thirty-six";
    mp[37] = "thirty-seven";
    mp[38] = "thirty-eight";
    mp[39] = "thirty-nine";
    mp[40] = "forty";

    // MultiMap
    std::multimap<int, std::string> mmp;
    mmp.insert({41, "forty-one"});
    mmp.insert({42, "forty-two"});
    mmp.insert({42, "another forty-two"});
    mmp.insert({43, "forty-three"});
    mmp.insert({44, "forty-four"});

    // Output elements
    std::cout << "Vector: ";
    for (const auto& v : vec) std::cout << v << " ";
    std::cout << "\nList: ";
    for (const auto& l : lst) std::cout << l << " ";
    std::cout << "\nDeque: ";
    for (const auto& d : deq) std::cout << d << " ";
    std::cout << "\nStack: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "\nQueue: ";
    while (!que.empty()) {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << "\nPriority Queue: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\nSet: ";
    for (const auto& s : st) std::cout << s << " ";
    std::cout << "\nMultiSet: ";
    for (const auto& ms : mst) std::cout << ms << " ";
    std::cout << "\nMap: ";
    for (const auto& m : mp) std::cout << m.first << ":" << m.second << " ";
    std::cout << "\nMultiMap: ";
    for (const auto& mm : mmp) std::cout << mm.first << ":" << mm.second << " ";
    std::cout << std::endl;

    return 0;
}