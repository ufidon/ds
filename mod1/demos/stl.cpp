#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

int main() {
    // 1. Containers
    std::vector<int> vec = {5, 2, 8, 1, 9};

    // 2. Algorithms
    std::sort(vec.begin(), vec.end());

    // 3. Iterators
    std::ostream_iterator<int> out_it(std::cout, " ");
    std::copy(vec.begin(), vec.end(), out_it);
    std::cout << std::endl;

    // 4. Function Objects (Functors)
    struct greater_than {
        int val;
        greater_than(int v) : val(v) {}
        bool operator()(int x) const { return x > val; }
    };
    int count_greater_than_5 = std::count_if(vec.begin(), vec.end(), greater_than(5));
    std::cout << "Count of elements greater than 5: " << count_greater_than_5 << std::endl;

    // 5. Utilities
    std::pair<int, std::string> my_pair = std::make_pair(42, "hello");
    std::cout << "Pair: " << my_pair.first << ", " << my_pair.second << std::endl;

    return 0;
}
