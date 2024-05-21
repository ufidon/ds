# Stack

<table>
  <thead>
    <tr>
      <th>Aspect</th>
      <th>Stacks</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Definition</td>
      <td>A linear data structure that follows the <span style="color:blue">Last In, First Out (LIFO)</span> principle.</td>
    </tr>
    <tr>
      <td>Implementation</td>
      <td>Can be implemented using arrays or linked lists.</td>
    </tr>
    <tr>
      <td>Operations</td>
      <td> ▶️Push: insert an element onto the stack<br>▶️Pop: remove the top element from the stack<br>▶️Peek: get the top element without removing it<br>▶️isEmpty: check if the stack is empty.</td>
    </tr>
    <tr>
      <td>Complexity</td>
      <td>Constant-time complexity 𝐎(1) for push, pop, and peek operations, Space efficiency.</td>
    </tr>
    <tr>
      <td>Applications</td>
      <td>Expression evaluation, Function call management (call stack), Undo mechanisms in text editors, Backtracking algorithms.</td>
    </tr>
  </tbody>
</table>


💡 Intuition
---
![stack](https://upload.wikimedia.org/wikipedia/commons/e/e4/Lifo_stack.svg)

- Animation
  - [Top is top](https://liveexample.pearsoncmg.com/liang/animation/web/Stack.html)
  - [Top is right - array implementation](https://www.cs.usfca.edu/~galles/visualization/StackArray.html)
  - [Top is left - linked list implementation](https://www.cs.usfca.edu/~galles/visualization/StackLL.html)
    - [Detailed view](https://web.eecs.utk.edu/~czheng4/viz/animations/linked_data_structures/stack/stack.html)


## Implementation
🍎 Example: by fixed-size array
---
- 💡 [Intuition by animation](https://csvistool.com/StackArray)
```c++
#include <iostream>

template <class T>
class Stack
{
private:
  static const int MAX_SIZE = 1000;
  T data[MAX_SIZE];
  int top;

public:
  Stack() : top(-1) {}

  bool push(const T &element)
  {
    if (top >= MAX_SIZE - 1)
    {
      std::cout << "Stack Overflow\n";
      return false;
    }
    data[++top] = element;
    return true;
  }

  T pop()
  {
    if (top < 0)
    {
      std::cout << "Stack Underflow\n";
      return T(); // Return a default value for the type T
    }
    return data[top--];
  }

  T topElement() const
  {
    if (top < 0)
    {
      std::cout << "Stack is Empty\n";
      return T(); // Return a default value for the type T
    }
    return data[top];
  }

  bool isEmpty() const
  {
    return (top < 0);
  }
};

int main()
{
  Stack<int> integerStack;
  Stack<std::string> stringStack;

  integerStack.push(10);
  integerStack.push(20);
  integerStack.push(30);

  stringStack.push("Hello");
  stringStack.push("World");

  std::cout << integerStack.pop() << " removed from stack\n";
  std::cout << stringStack.pop() << " removed from stack\n";

  std::cout << "Top element in integer stack: " << integerStack.topElement() << std::endl;
  std::cout << "Top element in string stack: " << stringStack.topElement() << std::endl;

  return 0;
}
```

---

🍎 Example: by dynamic array
---
```c++
#include <iostream>
#include <stdexcept> // For std::runtime_error

template <typename T>
class Stack
{
private:
  T *array;     // Pointer to the array used for storage
  int capacity; // Total capacity of the stack
  int topIndex; // Index of the top element in the stack

  // Function to resize the array when needed
  void resize(int newCapacity)
  {
    T *newArray = new T[newCapacity];
    for (int i = 0; i <= topIndex; ++i)
    {
      newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
  }

public:
  Stack(int initialCapacity = 2) : capacity(initialCapacity), topIndex(-1)
  {
    array = new T[capacity];
  }

  ~Stack()
  {
    delete[] array;
  }

  void push(const T &value)
  {
    if (topIndex >= capacity - 1)
    {
      resize(capacity * 2); // Double the capacity
    }
    array[++topIndex] = value;
  }

  T pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack Underflow");
    }
    return array[topIndex--];
  }

  T top() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack is Empty");
    }
    return array[topIndex];
  }

  bool isEmpty() const
  {
    return topIndex == -1;
  }

  int size() const
  {
    return topIndex + 1;
  }
};

int main()
{
  Stack<int> myStack;

  // Push elements onto the stack
  myStack.push(10);
  myStack.push(20);
  myStack.push(30);

  // Pop elements from the stack
  while (!myStack.isEmpty())
  {
    std::cout << "Top: " << myStack.top() << std::endl;
    myStack.pop();
  }

  return 0;
}
```

🍎 Example: by std::vector
---
```c++
#include <iostream>
#include <vector> // Include the vector header

int main()
{
  std::vector<int> myDynamicArray; // Declare an empty vector

  // Add elements to the vector
  myDynamicArray.push_back(10);
  myDynamicArray.push_back(20);
  myDynamicArray.push_back(30);

  // Access elements
  std::cout << "First element: " << myDynamicArray[0] << std::endl;
  std::cout << "Second element: " << myDynamicArray[1] << std::endl;

  // Change the size dynamically
  myDynamicArray.push_back(40); // Add another element
  myDynamicArray.pop_back();    // Remove the last element

  // Display the updated vector
  std::cout << "Updated vector: ";
  for (const auto &element : myDynamicArray)
  {
    std::cout << element << " ";
  }
  std::cout << std::endl;

  return 0;
}
```

---

🍎 Example: by linked list
---
- 💡 [Intuition by animation](https://csvistool.com/StackLL)

```c++
#include <iostream>

// Node structure for the linked list
template <typename T>
struct Node
{
  T data;
  Node *next;

  Node(T val) : data(val), next(nullptr) {}
};

// Stack class using a linked list
template <typename T>
class Stack
{
private:
  Node<T> *top;

public:
  Stack() : top(nullptr) {}

  // Push a new element onto the stack
  void push(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
  }

  // Pop the top element from the stack
  T pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack Underflow");
    }
    Node<T> *temp = top;
    T poppedValue = top->data;
    top = top->next;
    delete temp;
    return poppedValue;
  }

  // Check if the stack is empty
  bool isEmpty() const
  {
    return top == nullptr;
  }

  // Get the top element of the stack
  T peek() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack is Empty");
    }
    return top->data;
  }

  // Destructor to clean up the stack
  ~Stack()
  {
    while (!isEmpty())
    {
      pop();
    }
  }
};

int main()
{
  Stack<int> intStack;
  Stack<std::string> stringStack;

  intStack.push(1);
  intStack.push(2);
  intStack.push(3);

  stringStack.push("Hello");
  stringStack.push("World");

  std::cout << "Top of intStack: " << intStack.peek() << std::endl;
  std::cout << "Top of stringStack: " << stringStack.peek() << std::endl;

  // Pop all elements from the intStack
  while (!intStack.isEmpty())
  {
    std::cout << "Popped from intStack: " << intStack.pop() << std::endl;
  }

  // Pop all elements from the stringStack
  while (!stringStack.isEmpty())
  {
    std::cout << "Popped from stringStack: " << stringStack.pop() << std::endl;
  }

  return 0;
}
```

C++ STL std::stack
---
```c++
#include <iostream>
#include <stack>

int main()
{
  // Declare a stack of integers
  std::stack<int> myStack;

  // Push elements onto the stack
  myStack.push(10);
  myStack.push(20);
  myStack.push(30);

  // Access the top element
  std::cout << "Top element: " << myStack.top() << std::endl;

  // Remove the top element
  myStack.pop();

  // Check if the stack is empty
  if (!myStack.empty())
  {
    std::cout << "Stack is not empty" << std::endl;
  }

  // Display the remaining elements
  std::cout << "Elements left in the stack:" << std::endl;
  while (!myStack.empty())
  {
    std::cout << myStack.top() << std::endl;
    myStack.pop();
  }

  return 0;
}
```


## Applications

Function call stacks
---
- keep track of active function calls
- essential for managing the order in which functions execute and return control to each other

- `Main Function`: The main function serves as the base of the call stack.
  - it’s where the program starts executing.
- `Stack Frames`: Each function call creates a new frame on the stack 
  - which contains the `function’s parameters, local variables, and return address`.
- `LIFO Order`: The stack operates on a Last-In-First-Out basis 
  - the most recently called function will finish and be removed from the stack first.
- `Function Execution`: 
  - When a function is called, its frame is pushed onto the stack. 
  - When the function completes, its frame is popped off the stack, and control returns to the calling function.
- `Debugging Tools`: Debuggers utilize the `call stack` to step through code
  - allowing developers to inspect the state of the program at various points in execution.
- `Memory Management`: The call stack is also crucial for memory management
  - as it allocates space for function calls dynamically during program execution

Function call frame
---
- also known as `stack frame`
  - a section of the stack that contains data related to `a single execution` of a function

- **Return Address**: After a function completes its execution, the program control needs to return to the calling function. The return address specifies where this return should occur.
- **Parameters**: The function’s input parameters are pushed onto the stack so that the function can access and use them.
- **Local Variables**: Variables declared within the function are stored in the stack frame. They exist only during the function’s execution.
- **Saved Registers**: Some registers may need to be preserved across function calls. These registers’ values are saved on the stack before a function call and restored afterward.
- **Frame Pointer**: Typically points to the start of the stack frame for tracking purposes when there are multiple nested frames.
- **Stack Pointer**: Points to the current top of the stack, adjusting as local variables are added or removed.



🍎 Example
```c++
#include <iostream>

void FunctionB(int arg)
{
  int localVarB = arg;
  // The stack frame for FunctionB will contain:
  // - Return address for where FunctionB should return control after executing.
  // - The parameter 'arg'.
  // - The local variable 'localVarB'.
  std::cout << "In FunctionB: localVarB = " << localVarB << std::endl;
  // After this line, FunctionB will return to FunctionA, and its stack frame will be popped off.
}

void FunctionA()
{
  int localVarA = 5;
  // The stack frame for FunctionA will contain:
  // - Return address for where FunctionA should return control after executing.
  // - The local variable 'localVarA'.
  std::cout << "In FunctionA: localVarA = " << localVarA << std::endl;
  FunctionB(localVarA); // Call to FunctionB
                        // After FunctionB returns, the execution continues here.
}

int main()
{
  FunctionA(); // Call to FunctionA
  // After FunctionA returns, the execution continues here until the program ends.
  return 0;
}
```


Parentheses Matching Algorithm
---
- checks the `well-formedness` of expressions containing various types of brackets such as `{}`, `()`, and `[]`. 
- ensures that `each opening bracket has a corresponding closing bracket` in the `correct order`.
- Steps:
  1. **Initialize** a stack to keep track of opening brackets.
  2. **Traverse** the expression string character by character.
  3. **For each character**:
     - If it's an opening bracket, **push** it onto the stack.
     - If it's a closing bracket, **check** the stack:
       - If the stack is empty or the top doesn't match the corresponding opening bracket, the expression is **not balanced**.
       - If it matches, **pop** the top of the stack.
  4. After traversing the entire string, if the stack is **empty**, the expression is **balanced**; otherwise, it is **not balanced**.

- Implementation

```c++
#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(const std::string &expr)
{
  std::stack<char> s;
  char x;

  // Traversing the expression
  for (int i = 0; i < expr.length(); i++)
  {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
    {
      // Push the element in the stack
      s.push(expr[i]);
      continue;
    }

    // If current character is not opening bracket, then it must be closing. So stack cannot be empty at this point.
    if (s.empty())
      return false;

    switch (expr[i])
    {
    case ')':
      x = s.top();
      s.pop();
      if (x == '{' || x == '[')
        return false;
      break;

    case '}':
      x = s.top();
      s.pop();
      if (x == '(' || x == '[')
        return false;
      break;

    case ']':
      x = s.top();
      s.pop();
      if (x == '(' || x == '{')
        return false;
      break;
    }
  }

  // Check empty stack
  return (s.empty());
}

int main()
{
  std::string expr = "{()}[]";

  if (areBracketsBalanced(expr))
    std::cout << "Balanced\n";
  else
    std::cout << "Not Balanced\n";

  return 0;
}
```


Arithmetic expression notations and evaluation
---

<table border="1">
  <tr>
    <th>Infix Notation</th>
    <th>Postfix Notation</th>
    <th>Prefix Notation</th>
  </tr>
  <tr>
    <td>Operator is placed between operands (e.g., A + B).</td>
    <td>Operator is placed after operands (e.g., AB+).</td>
    <td>Operator is placed before operands (e.g., +AB).</td>
  </tr>
  <tr>
    <td>Easy for humans to read and write.</td>
    <td>Efficient for machines to parse without needing to consider operator precedence.</td>
    <td>Efficient for machines to parse and suitable for certain recursive algorithms.</td>
  </tr>
  <tr>
    <td>Requires consideration of operator precedence and parentheses for non-trivial expressions.</td>
    <td>Does not require parentheses. Operands are implicitly associated with their operators in order.</td>
    <td>Does not require parentheses. Operands are implicitly associated with their operators in reverse order.</td>
  </tr>
  <tr>
    <td>Commonly used in everyday mathematics and most programming languages.</td>
    <td>Used in some programming languages and calculators (Reverse Polish Notation).</td>
    <td>Less common in practice but used in some expression-evaluating algorithms.</td>
  </tr>
</table>

Infix to postfix
---
1. **Initialize a Stack**: Start with an empty stack to hold operators and parentheses.

2. **Scan the Infix Expression**: Read the infix expression from left to right.

3. **Process Operands**: When an operand is encountered, add it directly to the postfix expression.

4. **Process Operators**:
   - If the stack is empty or contains a '(', push the operator onto the stack.
   - If the incoming operator has higher precedence than the top of the stack, push it onto the stack.
   - If the incoming operator has lower or equal precedence, pop the stack until this is not true and then push the incoming operator.

5. **Process Parentheses**:
   - If a '(' is encountered, push it onto the stack.
   - If a ')' is encountered, pop the stack and add to the postfix expression until a '(' is encountered. Discard both parentheses.

6. **Pop Remaining Operators**: After the entire infix expression has been scanned, pop any remaining operators from the stack and add them to the postfix expression.

7. **Output the Postfix Expression**: The postfix expression is now complete and ready for evaluation.

🍎 Example
---
- convert the infix expression `A + B * C + D` to postfix

1. **Initialize an Empty Stack**: Start with an empty stack to hold operators and parentheses.
2. **Scan the Infix Expression from Left to Right**:
   - `A`: It’s an operand, so add it directly to the postfix expression.
   - `+`: It’s an operator. Since the stack is empty, push it onto the stack.
   - `B`: Operand, add to postfix.
   - `*`: Operator. Since `*` has higher precedence than `+`, push it onto the stack.
   - `C`: Operand, add to postfix.
   - `+`: Operator. Pop `*` from the stack (higher precedence), then push `+` onto the stack.
   - `D`: Operand, add to postfix.
3. **Pop Remaining Operators**: After scanning the entire infix expression, pop any remaining operators from the stack and add them to the postfix expression. In this case, pop `+` from the stack.
4. **Final Postfix Expression**: The postfix expression is `ABC*+D+`.

- the postfix expression corresponding to `A + B * C + D` is `ABC*+D+`.

Evaluate postfixes
---
1. **Create a Stack**: Initialize an empty stack that will be used to store operands.
2. **Scan the Postfix Expression**: Read the expression from left to right.
3. **Process Operands**:
   - If the token is an operand (number), push it onto the stack.
4. **Process Operators**:
   - If the token is an operator (`+`, `-`, `*`, `/`), pop the required number of operands from the stack.
   - Apply the operator to the operands in the correct order.
   - Push the result back onto the stack.
5. **Repeat**: Continue the process until the end of the expression.
6. **Result**: The final value remaining on the stack is the result of the postfix expression.

🍎 Example
---
- evaluate postfix `4 7 5 * + 2 +`


🏃 Implementation
---
- read user input of an infix expression `without spaces`
- convert the infix expression to postfix notation
- evaluate the postfix expression

```c++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Function to return precedence of operators
int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

// Function to convert infix expression to postfix
std::string infixToPostfix(const std::string &infix)
{
  std::stack<char> operators;
  std::string postfix;

  for (char c : infix)
  {
    if (std::isalnum(c))
    {
      postfix += c;
    }
    else if (c == '(')
    {
      operators.push(c);
    }
    else if (c == ')')
    {
      while (!operators.empty() && operators.top() != '(')
      {
        postfix += operators.top();
        operators.pop();
      }
      operators.pop(); // Remove '(' from stack
    }
    else
    {
      while (!operators.empty() && precedence(c) <= precedence(operators.top()))
      {
        postfix += operators.top();
        operators.pop();
      }
      operators.push(c);
    }
  }

  while (!operators.empty())
  {
    postfix += operators.top();
    operators.pop();
  }

  return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const std::string &postfix)
{
  std::stack<int> operands;

  for (char c : postfix)
  {
    if (std::isdigit(c))
    {
      operands.push(c - '0'); // Convert char to int value
    }
    else
    {
      int op2 = operands.top();
      operands.pop();
      int op1 = operands.top();
      operands.pop();

      switch (c)
      {
      case '+':
        operands.push(op1 + op2);
        break;
      case '-':
        operands.push(op1 - op2);
        break;
      case '*':
        operands.push(op1 * op2);
        break;
      case '/':
        operands.push(op1 / op2);
        break;
      }
    }
  }

  return operands.top();
}

int main()
{
  std::string infix;
  std::cout << "Enter an infix expression: ";
  std::cin >> infix;

  std::string postfix = infixToPostfix(infix);
  std::cout << "Postfix expression: " << postfix << std::endl;

  int result = evaluatePostfix(postfix);
  std::cout << "Result of evaluation: " << result << std::endl;

  return 0;
}
```


# References
- [ROPgadget Tool](https://github.com/JonathanSalwan/ROPgadget)