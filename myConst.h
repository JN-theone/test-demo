// case 1 :修饰变量，指针
   cosnt int max = 100;  //只读，不可修改内容
   const int* a = new int;   //等价于  int const *a;   const在指针前，代表指针指向内容不可变
   a = &max; //合法
   *a = 80; //不合法

   int* const a = new int;  //const在指针后，代表指针本身不可变
    a = &max; //不合法
   *a = 80; //合法

// case 2:const 修饰成员函数
// 在C++中，const关键字可以用来修饰类中的成员函数，以表示这些函数不会修改类的成员变量。被const修饰的成员函数叫做常量成员函数，它们有以下特点：
// 常量成员函数不能修改类的任何成员变量，包括普通成员变量和静态成员变量。这通过编译器生成的隐式的const指针来实现。
// 常量成员函数可以被类的const对象和非const对象调用。
// 常量成员函数一般用于查询操作，以确保这些函数不会产生意外的数据修改。这也使得编译器能够进行更多的优化。

class MyClass {
public:
    void foo() const {
        // 不能修改成员变量
        // this->member_variable = 5; // 错误
        // 当然，如果成员变量被mutable修饰，可以修改
        mutableVariable = 10;//正确
    }

    void bar() {
        // 可以修改成员变量
        member_variable = 10;
    }

private:
    int member_variable;
    mutable int mutableVariable;
};

int main() {
    const MyClass obj1;
    obj1.foo(); // 可以调用常量成员函数

    MyClass obj2;
    obj2.foo(); // 可以调用常量成员函数
    obj2.bar(); // 可以调用非常量成员函数

    return 0;
}

// case 3: const修饰参数
class MyClass {
public:
    void nonConstFunction() {
        // 修改对象状态
    }

    void constFunction() const {
        // 只读访问对象状态
    }
};

// 传递非const引用，可以调用非const函数
int print(MyClass &obj) {
    obj.nonConstFunction(); // 可以调用非const修饰的函数
}

// 传递const引用，只能调用const函数
int printConst(const MyClass &obj) {
    obj.constFunction(); // 可以调用const修饰的函数
}
