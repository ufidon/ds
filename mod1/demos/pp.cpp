#include <iostream>
#include <string>

// Function to print a message n times using recursion
void printMessage(int n, const std::string& message) {
    if (n > 0) {
        std::cout << message << std::endl;
        printMessage(n - 1, message);
    }
}

// Function to check if a string is a palindrome using recursion
bool isPalindrome(const std::string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    int n;
    std::string message;

    // Get user input for the message and number of times to print
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);
    std::cout << "Enter the number of times to print the message: ";
    std::cin >> n;

    // Print the message n times
    printMessage(n, message);

    // Check if the entered message is a palindrome
    if (isPalindrome(message, 0, message.length() - 1)) {
        std::cout << "The entered message is a palindrome." << std::endl;
    } else {
        std::cout << "The entered message is not a palindrome." << std::endl;
    }

    return 0;
}
