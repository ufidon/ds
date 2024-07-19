#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <unordered_map>

bool isBalanced(const std::string& expression) {
    std::stack<char> stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) return false;
            char top = stack.top();
            if ((ch == ')' && top != '(') || 
                (ch == ']' && top != '[') || 
                (ch == '}' && top != '{')) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        case '%': return std::fmod(a, b);
        case '^': return std::pow(a, b);
        default: throw std::runtime_error("Invalid operator");
    }
}

void processOperator(std::stack<double>& values, std::stack<char>& ops) {
    double b = values.top(); values.pop();
    double a = values.top(); values.pop();
    char op = ops.top(); ops.pop();
    values.push(applyOperation(a, b, op));
}

double evaluate(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> ops;
    std::unordered_map<char, char> closingBracket = {{')', '('}, {']', '['}, {'}', '{'}};

    std::istringstream tokens(expression);
    char ch;
    while (tokens >> ch) {
        if (std::isdigit(ch) || ch == '.') {
            tokens.putback(ch);
            double value;
            tokens >> value;
            values.push(value);
        } else if (ch == '(' || ch == '[' || ch == '{') {
            ops.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            while (!ops.empty() && ops.top() != closingBracket[ch]) {
                processOperator(values, ops);
            }
            if (!ops.empty()) ops.pop();
        } else if (isOperator(ch)) {
            while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(ch)) {
                processOperator(values, ops);
            }
            ops.push(ch);
        } else {
            throw std::runtime_error(std::string("Illegal character: ") + ch);
        }
    }

    while (!ops.empty()) {
        processOperator(values, ops);
    }

    return values.top();
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    try {
        // Check for illegal characters
        for (char ch : expression) {
            if (!std::isdigit(ch) && !isOperator(ch) && ch != '.' && ch != ' ' && ch != '(' && ch != ')' && ch != '[' && ch != ']' && ch != '{' && ch != '}') {
                throw std::runtime_error(std::string("Illegal character: ") + ch);
            }
        }

        // Check if brackets are balanced
        if (!isBalanced(expression)) {
            throw std::runtime_error("Brackets are not balanced");
        }

        double result = evaluate(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
