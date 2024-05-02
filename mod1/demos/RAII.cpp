#include <iostream>
#include <memory>

class File {
private:
    FILE* file;

public:
    // Constructor opens the file
    explicit File(const char* filename) : file(fopen(filename, "r")) {
        if (!file) {
            throw std::runtime_error("Failed to open file.");
        }
        std::cout << "File opened.\n";
    }

    // Destructor closes the file
    ~File() {
        if (file) {
            fclose(file);
            std::cout << "File closed.\n";
        }
    }

    // Read a line from the file
    std::string readLine() {
        char buffer[256];
        if (fgets(buffer, sizeof(buffer), file)) {
            return buffer;
        } else {
            return "";
        }
    }
};

int main() {
    try {
        File file("example.txt");
        std::string line = file.readLine();
        std::cout << "First line: " << line;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
