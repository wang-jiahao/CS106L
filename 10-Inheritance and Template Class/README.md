

## 继承

### C++中的继承概述

继承是面向对象编程（OOP）中的一种机制，它允许创建一个新的类（派生类），该类可以继承并扩展或修改已有类（基类）的属性和方法。在C++中，继承提供了一种组织代码的方式，使得可以在不重复代码的情况下重用和扩展已有的类。

继承的基本概念如下：
- **基类（Base Class）**：也称为父类，它包含一些通用的属性和方法。
- **派生类（Derived Class）**：也称为子类，它继承了基类的成员，并可以在此基础上进行扩展或修改。

C++支持单继承（一个派生类只能继承一个基类）和多继承（一个派生类可以继承多个基类）。C++的继承是通过使用`:`符号来实现的。

### 继承的基本语法

在C++中，继承的基本语法结构如下：

```cpp
class DerivedClass : accessSpecifier BaseClass {
    // DerivedClass的成员
};
```

- `DerivedClass` 是派生类的名称。
- `BaseClass` 是基类的名称。
- `accessSpecifier` 是继承方式，可以是`public`、`protected`或`private`，它决定了基类成员在派生类中的可访问性。

### 继承的访问控制

C++允许通过三种访问控制修饰符来指定基类成员在派生类中的可访问性：

1. **`public`继承**：基类的`public`成员在派生类中依然是`public`，`protected`成员在派生类中是`protected`，`private`成员不可访问。

   ```cpp
   class Base {
   public:
       int publicVar;
   protected:
       int protectedVar;
   private:
       int privateVar;
   };

   class Derived : public Base {
   public:
       void show() {
           std::cout << publicVar << std::endl;    // 可以访问
           std::cout << protectedVar << std::endl;  // 可以访问
           // std::cout << privateVar << std::endl;  // 错误，不能访问private成员
       }
   };
   ```

2. **`protected`继承**：基类的`public`和`protected`成员会变为派生类中的`protected`，`private`成员不可访问。

3. **`private`继承**：基类的所有成员（无论是`public`、`protected`还是`private`）都会变为派生类中的`private`，这意味着它们不能被派生类外部访问。

### 继承的类型

1. **单继承（Single Inheritance）**：一个派生类只继承自一个基类。
   ```cpp
   class Base {
   public:
       void show() { std::cout << "Base class" << std::endl; }
   };
   
   class Derived : public Base {
   public:
       void display() { std::cout << "Derived class" << std::endl; }
   };
   ```

2. **多继承（Multiple Inheritance）**：一个派生类可以继承自多个基类。
   ```cpp
   class Base1 {
   public:
       void show1() { std::cout << "Base1" << std::endl; }
   };
   
   class Base2 {
   public:
       void show2() { std::cout << "Base2" << std::endl; }
   };
   
   class Derived : public Base1, public Base2 {
   public:
       void display() { std::cout << "Derived class" << std::endl; }
   };
   ```

3. **虚继承（Virtual Inheritance）**：解决多继承中的“钻石问题”。虚继承确保派生类只继承基类的一份数据。通过`virtual`关键字来声明虚继承。
   ```cpp
   class Base {
   public:
       int baseVar;
   };
   
   class A : virtual public Base {
   public:
       void showA() { std::cout << "Class A" << std::endl; }
   };
   
   class B : virtual public Base {
   public:
       void showB() { std::cout << "Class B" << std::endl; }
   };
   
   class Derived : public A, public B {
   public:
       void showDerived() { std::cout << "Derived Class" << std::endl; }
   };
   ```

### 构造函数与析构函数的继承

1. **基类构造函数**：派生类通常不直接调用基类构造函数，而是通过派生类的构造函数隐式调用基类的构造函数。如果基类没有默认构造函数，派生类必须显式调用基类的构造函数。

   ```cpp
   class Base {
   public:
       Base(int x) { std::cout << "Base class constructor, x = " << x << std::endl; }
   };

   class Derived : public Base {
   public:
       Derived(int x) : Base(x) { std::cout << "Derived class constructor" << std::endl; }
   };

   int main() {
       Derived d(10);  // 会调用Base(int)构造函数
   }
   ```

2. **基类析构函数**：如果派生类的对象被销毁，析构函数会从派生类开始，逐步调用基类的析构函数。如果基类的析构函数是虚拟的，C++将确保在删除通过基类指针指向派生类的对象时，能够正确地调用派生类和基类的析构函数。

   ```cpp
   class Base {
   public:
       virtual ~Base() { std::cout << "Base class destructor" << std::endl; }
   };
   
   class Derived : public Base {
   public:
       ~Derived() { std::cout << "Derived class destructor" << std::endl; }
   };
   
   int main() {
       Base* b = new Derived();
       delete b;  // 会先调用Derived类的析构函数，再调用Base类的析构函数
   }
   ```

### 方法重写与多态

继承使得派生类可以重写基类的方法。这种现象称为**方法重写（Override）**。如果基类中的方法被标记为`virtual`，则C++会启用**运行时多态（Runtime Polymorphism）**，即通过基类指针或引用调用派生类的重写方法。

```cpp
class Base {
public:
    virtual void display() { std::cout << "Base class" << std::endl; }
};

class Derived : public Base {
public:
    void display() override { std::cout << "Derived class" << std::endl; }
};

int main() {
    Base* b = new Derived();
    b->display();  // 输出 "Derived class"
    delete b;
}
```

### 总结

C++中的继承机制支持代码复用和扩展，可以帮助实现类的层次化结构。通过继承，派生类可以继承基类的属性和方法，进而对其进行修改或扩展，支持单继承和多继承（通过虚继承解决多继承中的问题）。此外，C++支持方法的重写与多态，使得面向对象编程更具灵活性和表达力。在实际编程中，理解并合理运用继承能大大提高代码的可复用性和维护性。

## Concepts

在 C++ 中，**Concepts** 和 **requires** 是 C++20 引入的新特性，它们是用于约束模板类型的工具，旨在提高模板编程的可读性和可维护性。这些特性帮助程序员指定模板参数的要求，从而确保模板类型满足一定的条件。通过 Concepts，程序员可以在编译时进行类型检查，确保模板的类型参数符合预期的行为。

### 1. Concepts：概念

Concept（概念）是对类型要求的命名约定，用来描述一种类型的“能力”或“特性”。概念可以定义模板参数应该具备哪些操作、成员或属性，而 C++ 编译器可以根据这些要求进行类型检查。

Concept的定义使用 `concept` 关键字。其作用类似于类型约束，目的是使得模板代码更加类型安全，并且可以提高代码的可读性和可维护性。Concept 允许编译器在模板实例化时检查类型是否符合特定的要求，从而避免在编译时出现不可预测的错误。

#### Concept的定义语法：

```cpp
template <typename T>
concept ConceptName = <condition>;
```

其中，`ConceptName` 是概念的名称，`<condition>` 是对类型 `T` 的约束条件，通常是一些类型特征或者操作。

#### 示例：自定义 Concept

```cpp
#include <iostream>
#include <type_traits>

// 定义一个Concept，要求T类型必须是可加的（支持+操作符）
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>; // 表示a和b可以相加，并且返回值类型是T
};

// 使用Concept约束模板参数
template <Addable T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << std::endl;         // 可行，int是可加的
    // std::cout << add("Hello", "World") << std::endl;  // 错误，char*不支持+操作符
}
```

在这个例子中，我们定义了一个名为 `Addable` 的概念，它要求类型 `T` 必须支持加法运算并且返回值类型是 `T`。在 `add` 函数模板中，只有满足 `Addable` 概念的类型 `T` 才能被使用。

### 2. `requires`：要求表达式

`requires` 是 C++20 中用于在模板参数中指定约束条件的关键字。它可以用于声明和表达某些条件，限制模板的使用。`requires` 可以单独使用，也可以与 Concepts 一起使用。

`requires` 表达式的作用是检查模板参数是否满足某些特定的操作或条件，若条件不满足，编译器会报错。

#### `requires`语法

```cpp
requires <condition>
```

在 C++20 中，`requires` 关键字通常与概念（Concepts）结合使用，用来指定模板的约束条件。例如：

```cpp
template <typename T>
requires std::is_integral_v<T>  // T必须是整型
T add(T a, T b) {
    return a + b;
}
```

#### `requires` 用于模板参数

`requires` 关键字可以直接用来约束模板参数，表示该模板只适用于满足某些要求的类型。以下是一个带有 `requires` 关键字的模板示例：

```cpp
template <typename T>
requires requires(T a, T b) { a + b; }  // T支持加法操作
T add(T a, T b) {
    return a + b;
}
```

上面的代码中，`requires` 表达式检查 `T` 类型是否可以进行加法操作。如果类型不满足这个要求，编译器将无法实例化 `add` 函数。

#### `requires` 表达式与 `concept` 的结合

Concept 是一种可重用的约束条件，可以通过 `requires` 关键字在模板中更直观地使用。例如：

```cpp
template <typename T>
concept Addable = requires(T a, T b) { a + b; };

template <Addable T>
T add(T a, T b) {
    return a + b;
}
```

### 3. `requires` 子句与 SFINAE

`requires` 还可以用于指定 SFINAE（Substitution Failure Is Not An Error，替代失败不是错误）条件。通常在模板特化或函数重载时，使用 `requires` 可以根据模板参数类型的特性进行选择。

#### 示例：SFINAE 与 `requires`

```cpp
#include <iostream>
#include <type_traits>

template <typename T>
requires std::is_integral_v<T>  // T必须是整型
T multiply(T a, T b) {
    return a * b;
}

template <typename T>
requires std::is_floating_point_v<T>  // T必须是浮点型
T multiply(T a, T b) {
    return a * b;
}

int main() {
    std::cout << multiply(3, 4) << std::endl;        // 整型
    std::cout << multiply(3.5, 2.1) << std::endl;    // 浮点型
}
```

这里的 `requires` 用于函数模板的重载，使得 `multiply` 函数能够根据传入的类型选择正确的重载版本。

### 4. 总结

- **Concepts** 提供了一种声明类型要求的方式，允许对模板参数进行约束，使得模板编程更加安全和可读。
- **`requires`** 是用于定义约束条件的关键字，可以与 Concept 一起使用，或单独在模板函数中进行条件检查。
- `requires` 关键字和 Concepts 的结合能在编译时有效地过滤掉不符合要求的类型，提高了代码的可维护性和类型安全性。

通过 Concept 和 `requires`，C++ 模板编程可以更加灵活、清晰和精确地表达类型要求，减少了由于模板不合规类型导致的编译时错误。