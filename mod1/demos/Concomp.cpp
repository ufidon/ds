#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3 = {1, 2, 3, 4};

    // Equality check
    if (vec1 == vec2) {
        std::cout << "vec1 and vec2 are equal" << std::endl;
    } else {
        std::cout << "vec1 and vec2 are not equal" << std::endl;
    }

    // Inequality check
    if (vec1 != vec3) {
        std::cout << "vec1 and vec3 are not equal" << std::endl;
    } else {
        std::cout << "vec1 and vec3 are equal" << std::endl;
    }

    // Less than check
    if (vec1 < vec3) {
        std::cout << "vec1 is less than vec3" << std::endl;
    } else {
        std::cout << "vec1 is not less than vec3" << std::endl;
    }

    return 0;
}
