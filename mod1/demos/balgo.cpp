#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    // Source vector
    std::vector<int> source = {1, 2, 3, 4, 5};

    // Destination vector
    std::vector<int> destination(source.size());

    // Copy elements from source to destination
    std::copy(source.begin(), source.end(), destination.begin());

    // Print the destination vector
    std::cout << "Copied vector:";
    for (int num : destination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Replace elements in destination vector
    std::replace(destination.begin(), destination.end(), 3, 10);

    // Print the destination vector after replacing
    std::cout << "After replacing 3 with 10:";
    for (int num : destination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Merge two sorted vectors
    std::vector<int> sorted1 = {1, 3, 5};
    std::vector<int> sorted2 = {2, 4, 6};
    std::vector<int> merged(6);
    std::merge(sorted1.begin(), sorted1.end(), sorted2.begin(), sorted2.end(), merged.begin());

    // Print the merged vector
    std::cout << "Merged vector:";
    for (int num : merged) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Count the number of occurrences of a value
    int count = std::count(source.begin(), source.end(), 3);
    std::cout << "Number of occurrences of 3 in source vector: " << count << std::endl;

    // Transform each element in source vector
    std::vector<int> transformed(source.size());
    std::transform(source.begin(), source.end(), transformed.begin(), [](int x) { return x * 2; });

    // Print the transformed vector
    std::cout << "Transformed vector:";
    for (int num : transformed) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Perform numeric computation
    int sum = std::accumulate(source.begin(), source.end(), 0);
    std::cout << "Sum of elements in source vector: " << sum << std::endl;

    return 0;
}
