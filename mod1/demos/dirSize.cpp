#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

// Function to calculate the size of a directory recursively
uintmax_t directorySize(const fs::path& path) {
    uintmax_t size = 0;

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (fs::is_regular_file(entry)) {
            size += fs::file_size(entry);
        }
    }

    return size;
}

int main() {
    fs::path directoryPath = "/path/to/your/directory";

    if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
        uintmax_t size = directorySize(directoryPath);
        std::cout << "Size of directory: " << size << " bytes" << std::endl;
    } else {
        std::cerr << "Invalid directory path" << std::endl;
    }

    return 0;
}
