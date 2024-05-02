#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {5, 2, 8, 3, 1, 9, 4, 7, 6};

    // Print the original vector
    std::cout << "Original vector:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print the sorted vector
    std::cout << "Sorted vector:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Find the minimum and maximum elements in the vector
    auto min_element = std::min_element(numbers.begin(), numbers.end());
    auto max_element = std::max_element(numbers.begin(), numbers.end());
    std::cout << "Minimum element: " << *min_element << std::endl;
    std::cout << "Maximum element: " << *max_element << std::endl;

    // Reverse the vector
    std::reverse(numbers.begin(), numbers.end());

    // Print the reversed vector
    std::cout << "Reversed vector:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Remove duplicates from the vector
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    // Print the vector with duplicates removed
    std::cout << "Vector with duplicates removed:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
