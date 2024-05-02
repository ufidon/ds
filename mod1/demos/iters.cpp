#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

int main() {
    // Input Iterator
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto it_input = vec.begin();
    std::cout << "Input Iterator: " << *it_input << std::endl;

    // Output Iterator
    std::vector<int> vec_out(5);
    auto it_output = vec_out.begin();
    *it_output = 10;
    std::cout << "Output Iterator: " << *it_output << std::endl;

    // Forward Iterator
    std::forward_list<int> flist{1, 2, 3, 4, 5};
    auto it_forward = flist.begin();
    std::cout << "Forward Iterator: ";
    while (it_forward != flist.end()) {
        std::cout << *it_forward << " ";
        ++it_forward;
    }
    std::cout << std::endl;

    // Bidirectional Iterator
    std::list<int> llist{1, 2, 3, 4, 5};
    auto it_bidirectional = llist.begin();
    std::cout << "Bidirectional Iterator (reverse): ";
    while (it_bidirectional != llist.end()) {
        std::cout << *it_bidirectional << " ";
        --it_bidirectional;
    }
    std::cout << std::endl;

    // Random Access Iterator
    std::vector<int> vec_random{1, 2, 3, 4, 5};
    auto it_random = vec_random.begin();
    std::cout << "Random Access Iterator: ";
    std::cout << *(it_random + 2) << std::endl;

    return 0;
}
