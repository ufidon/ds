#include <iostream>
#include <string>

// Helper function to check if a substring is a palindrome
bool isPalindrome(const std::string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

// Function to check if a string is a palindrome using recursion
bool isPalindrome(const std::string& str) {
    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    std::string message;

    // Get user input for the message
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);

    // Check if the entered message is a palindrome
    if (isPalindrome(message)) {
        std::cout << "The entered message is a palindrome." << std::endl;
    } else {
        std::cout << "The entered message is not a palindrome." << std::endl;
    }

    return 0;
}
