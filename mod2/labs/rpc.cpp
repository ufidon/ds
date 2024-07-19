#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Function to check if brackets are balanced
bool isBalanced(const std::string &expression)
{
  std::stack<char> stack;
  for (char ch : expression)
  {
    if (ch == '(' || ch == '[' || ch == '{')
    {
      stack.push(ch);
    }
    else if (ch == ')' || ch == ']' || ch == '}')
    {
      if (stack.empty())
        return false;
      char top = stack.top();
      if ((ch == ')' && top != '(') ||
          (ch == ']' && top != '[') ||
          (ch == '}' && top != '{'))
      {
        return false;
      }
      stack.pop();
    }
  }
  return stack.empty();
}

// Function to check if a character is an operator
bool isOperator(char ch)
{
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/' || op == '%')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}

// Function to apply an operation to two operands
double applyOperation(double a, double b, char op)
{
  switch (op)
  {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0)
      throw std::runtime_error("Division by zero");
    return a / b;
  case '%':
    return std::fmod(a, b);
  case '^':
    return std::pow(a, b);
  default:
    throw std::runtime_error("Invalid operator");
  }
}

// Function to process an operator
void processOperator(std::stack<double> &values, std::stack<char> &ops)
{
  double b = values.top();
  values.pop();
  double a = values.top();
  values.pop();
  char op = ops.top();
  ops.pop();
  values.push(applyOperation(a, b, op));
}

// Function to convert infix expression to postfix
std::string infixToPostfix(const std::string &expression)
{
  std::stack<char> ops;
  std::vector<std::string> postfix;
  std::unordered_map<char, char> closingBracket = {{')', '('}, {']', '['}, {'}', '{'}};

  std::istringstream tokens(expression);
  char ch;
  while (tokens >> ch)
  {
    if (std::isdigit(ch) || ch == '.')
    {
      tokens.putback(ch);
      double value;
      tokens >> value;
      postfix.push_back(std::to_string(value));
    }
    else if (ch == '(' || ch == '[' || ch == '{')
    {
      ops.push(ch);
    }
    else if (ch == ')' || ch == ']' || ch == '}')
    {
      while (!ops.empty() && ops.top() != closingBracket[ch])
      {
        postfix.push_back(std::string(1, ops.top()));
        ops.pop();
      }
      if (!ops.empty())
        ops.pop();
    }
    else if (isOperator(ch))
    {
      while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(ch))
      {
        postfix.push_back(std::string(1, ops.top()));
        ops.pop();
      }
      ops.push(ch);
    }
    else
    {
      throw std::runtime_error(std::string("Illegal character: ") + ch);
    }
  }

  while (!ops.empty())
  {
    postfix.push_back(std::string(1, ops.top()));
    ops.pop();
  }

  std::string postfixExpression;
  for (const auto &token : postfix)
  {
    postfixExpression += token + ' ';
  }

  return postfixExpression;
}

// Function to evaluate postfix expression
double evaluatePostfix(const std::string &postfix)
{
  std::stack<double> values;
  std::istringstream tokens(postfix);
  std::string token;
  while (tokens >> token)
  {
    if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
    {
      values.push(std::stod(token));
    }
    else if (isOperator(token[0]))
    {
      double b = values.top();
      values.pop();
      double a = values.top();
      values.pop();
      values.push(applyOperation(a, b, token[0]));
    }
    else
    {
      throw std::runtime_error("Invalid token in postfix expression");
    }
  }
  return values.top();
}

int main()
{
  std::string expression;

  std::cout << "Enter an expression: ";
  std::getline(std::cin, expression);

  try
  {
    // Check for illegal characters
    for (char ch : expression)
    {
      if (!std::isdigit(ch) && !isOperator(ch) && ch != '.' && ch != ' ' && ch != '(' && ch != ')' && ch != '[' && ch != ']' && ch != '{' && ch != '}')
      {
        throw std::runtime_error(std::string("Illegal character: ") + ch);
      }
    }

    // Check if brackets are balanced
    if (!isBalanced(expression))
    {
      throw std::runtime_error("Brackets are not balanced");
    }

    // Convert infix to postfix and evaluate
    std::string postfix = infixToPostfix(expression);
    double result = evaluatePostfix(postfix);

    std::cout << "Infix: " << expression << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;
    std::cout << "Result: " << result << std::endl;
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
