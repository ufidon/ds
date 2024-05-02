#include <iostream>

class MyClass {
public:
    void originalFunction(int x) {
        std::cout << "Original function: " << x << std::endl;
    }

    using FunctionAlias = void (MyClass::*)(int); // 定义成员函数别名

    FunctionAlias aliasFunction = &MyClass::originalFunction; // 使用成员函数别名

    void callAliasFunction(int x) {
        (this->*aliasFunction)(x); // 通过别名调用成员函数
    }
};

int main() {
    MyClass obj;
    obj.originalFunction(5); // 调用原始成员函数
    obj.callAliasFunction(10); // 通过别名调用成员函数
    return 0;
}
