# Classes & Objects
Everything in C++ is associated with classes and objects, along with its attributes and methods.

<mark style="background: #ABF7F7A6;">syntaxe : <br>
class name_class<br>
{<br>
declaration_of_attributs<br>
declaration_of_constructors<br>
declaration_of_methods<br>
declaration_of_destructors<br>
};</mark>

- **Modifiers:** Classes can use the access modifiers `public`, `private`, and `protected`.
- **Attributes** can be used directly in methods.
- **Methods** are functions that belong to the class.
- **Attributes** should not be declared in the method's parameter list.
# Methods

It is often better to define a method outside the class. To link the class to the method in this case, we use the scope resolution operator `::`. The method prototype should be declared inside the class, and the definition outside the class should be written as follows:
type_of_return ClassName :: function_name() {...........}

we can also add the "const" after() of the function if it's predicats- We can also add `const` after `()` in the function definition if it is a predicate.

# Objects
To declare an object : 
ClassName name_object;
To access to an attribut or method, use the name of object followed by dot name of the attribut/method
objectName.attributeName;
objectName.methodName();

# Encapsulation
Encapsulation serves to hide the attributes within the class, ensuring that anything unnecessary to expose remains private. By default, all class elements are private. To access private attributes, we use **getters** and **setters**, which should be declared as public.
<mark style="background: #D2B3FFA6;">ReturnType getOrSetAttributeName(TypeOfElement) const { return elementName; }</mark>
# "This" pointer
The `this` pointer is used to distinguish between member variables and parameters with the same name. To clarify which variable we want, we use `this->` to refer to the member variable specifically.


# Constructor
A **constructor** is a special method used to initialize the elements of a class. It must have the same name as the class and does not have a return type, not even `void`. A class can have multiple constructors.
To create an instance using a constructor:
<mark style="background: #D2B3FFA6;">ClassName instanceName(arg1, ...);</mark>

**Initialization List:**

The initialization list allows for direct initialization of attributes and is written as follows:
<mark style="background: #D2B3FFA6;">ClassName(parameters) : attribute1(), ..., attributeN() {}</mark>

Using the initialization list (with the `:` operator) is optional but recommended for efficiency, especially for attributes that are objects. 
Attributes not initialized in this section will receive a default value if they are objects, and will remain uninitialized if they are of a basic data type.
Attributes initialized in this section can still be modified within the constructor's body.


If we don't create a constructor the compiler generate one 
If we want to keep the constructor by default we use
NameOfClass()= default;

## Initialization list in cpp constructor

An **initialization list** is a part of the constructor in C++ that allows you to initialize member variables directly, right before the constructor body runs. It’s particularly useful for initializing `const` members, references, and objects that do not have default constructors. The initialization list appears after a colon (`:`) following the constructor’s parameter list.

ClassName(parameters) : member1(value1), member2(value2) {
    // Constructor body
}
**member1(value1)**, **member2(value2)**, etc., are initialized before the constructor body executes.

#### Why Use an Initialization List?

- **Efficiency**: Avoids default construction and reassignment, especially useful for large or complex objects.
- **Required for const and references**: `const` and reference members can only be initialized here, not in the constructor body.
- **Object Members without Default Constructors**: If a member is an object that doesn’t have a default constructor, it must be initialized here.

### Initializing Object Attributes with Initialization Lists

When an attribute is an object of another class, initializing it in the constructor body leads to extra steps. Instead, we use the **initialization list** to initialize these object members directly.

#### Example: Initializing Object Attributes Correctly

Let's say we have two classes, `Rectangle` and `ColoredRectangle`, where `ColoredRectangle` contains a `Rectangle` object and a `Color` object.

class Rectangle {
private:
    double height;
    double width;

public:
    <mark style="background: #FFB8EBA6;">Rectangle(double h, double w) : height(h), width(w) { }</mark>
};

class Color {
private:
    int red, green, blue;

public:
    <mark style="background: #FFB8EBA6;">Color(int r, int g, int b) : red(r), green(g), blue(b) { }</mark>
};

class ColoredRectangle {
private:
    Rectangle rectangle;
    Color color;

public:
// Proper initialization of object attributes in the initialization list
    <mark style="background: #FFB8EBA6;">ColoredRectangle(double h, double w, int r, int g, int b) 
        : rectangle(h, w), color(r, g, b) { }</mark>
};
- The `ColoredRectangle` constructor uses an **initialization list** to initialize both `rectangle` and `color` directly with the parameters.
- This is efficient because `Rectangle` and `Color` objects are directly initialized, avoiding temporary default values or extra assignment steps.

### Default Constructor with Initialization List vs. Without Initialization List

A **default constructor** initializes an object without any arguments. It can either use an **initialization list** or assign values in the constructor body.

class Rectangle {
private:
    double height;
    double width;

public:
    // Default constructor with initialization list
    <mark style="background: #FFB8EBA6;">Rectangle() : height(2.0), width(3.0) { }</mark>

// Default constructor without initialization list
    <mark style="background: #FFB8EBA6;">Rectangle() {
        height = 2.0;
        width = 3.0;
    }</mark>
};
Both constructors set `height` to 2.0 and `width` to 3.0, but:

- The first version (with an initialization list) is often more efficient and preferred because it initializes `height` and `width` directly.
- The second version (without the initialization list) sets `height` and `width` after default initialization, which may involve extra steps.

###  Combining Constructors with Default Parameters

You can define multiple constructors by setting default parameter values. This approach allows a single constructor to work as a **default constructor** and as a **parameterized constructor**.
class Rectangle {
private:
    double height;
    double width;

public:
    // Constructor with default parameter values
    <mark style="background: #FFB8EBA6;">Rectangle(double h = 2.0, double w = 3.0) : height(h), width(w) { }</mark>
};

int main() {
    Rectangle rect1;        // Uses default values: height = 2.0, width = 3.0
    Rectangle rect2(4.0);   // Uses provided value for height, default for width
    Rectangle rect3(4.0, 5.0); // Uses provided values for both height and width
}
In this example:

- `rect1` uses the default values `2.0` and `3.0`.
- `rect2` specifies `4.0` for `height`, but uses the default for `width`.
- `rect3` provides values for both parameters.

This makes the constructor flexible and adaptable to different situations.


### Compiler-Generated Default Constructor

When no constructors are explicitly defined in a class, the compiler automatically creates a minimal **default constructor**. This constructor:

- Calls the **default constructors** of any object-type attributes.
- Leaves **basic types (like `int`, `double`) uninitialized**.

class Example {
private:
    int number;       // Uninitialized if compiler-generated constructor is used
    Rectangle rect;   // Calls Rectangle's default constructor

public:
    <mark style="background: #FFB8EBA6;">// No constructors defined here, so the compiler provides a default constructor</mark>
};

int main() {
    Example ex; // Compiler-generated default constructor is used
}
In this case:

- Since `Rectangle` has a default constructor, `rect` is initialized by calling `Rectangle()` (its default constructor).
- `number`, however, remains uninitialized because it’s of a basic type (`int`), and no specific value is provided.

> **Note:** If any constructor is defined, the compiler **will not provide a default constructor**. You must create a default constructor manually if needed.

### Explicitly Requesting the Default Constructor with `= default`

If you’ve defined other constructors but still need a default constructor, you can explicitly request one using = default

class Rectangle {
private:
    double height;
    double width;

public:
    <mark style="background: #FFB8EBA6;">Rectangle(double h, double w) : height(h), width(w) { } 
    <br>
    //Parameterized constructor <br>
    Rectangle() = default;  // Explicitly declares a default constructor</mark>
};

int main() {
    Rectangle rect1;       // Calls the explicitly defaulted constructor
    Rectangle rect2(3.0, 4.0); // Calls the parameterized constructor
}
In this example:

- The default constructor is declared explicitly using = default;, so rect1 can be created without arguments.
- rect2 is created with specific values, using the parameterized constructor.

### Copy Constructor
A **copy constructor** in C++ is used to create a new object by copying the data from an existing object of the same class. It is called automatically when:

1. Initializing a new object from an existing one.
2. Passing an object by value to a function.
3. Returning an object by value from a function.

<mark style="background: #FFB8EBA6;">ClassName(const ClassName& other) { ... }</mark>

class Rectangle {
private:
    double height;
    double width;

public:
    // Parameterized constructor
    Rectangle(double h, double w) : height(h), width(w) { }

// Copy constructor
    <mark style="background: #FFB8EBA6;">Rectangle(const Rectangle& other) 
        : height(other.height), width(other.width) { }</mark>
};

int main() {
    Rectangle r1(11.3, 12.5); // Creates r1
    Rectangle r2(r1);         // Uses copy constructor to create r2 with r1's data
    Rectangle r3 = r1;        // Also uses copy constructor to create r3
}

### When the Copy Constructor is Called

1. **Object Initialization**:  
    Creating a new object as a copy of another object (e.g., Rectangle r2(r1);).
    
2. **Passing by Value to a Function**:  
    When an object is passed by value to a function, the function parameter is a copy of the object.

void example(Rectangle r) { /*...*/ }
example(r1); // Calls the copy constructor

3. **Returning by Value**:
When a function returns an object by value, the return statement makes a copy of the local object.
Rectangle createRectangle() {
    Rectangle rect(10, 5);
    return rect; // Copy constructor is called
}
### Copy Constructor Default Behavior

If no copy constructor is explicitly defined, the compiler provides a **default copy constructor** that:

- Copies each attribute from the source object to the target object.
- For basic types (like int or double ), it performs a simple value copy.
- For class-type attributes, it calls their own copy constructors.

### Shallow Copy vs. Deep Copy

- **Shallow Copy**: The default copy constructor performs a shallow copy. This is often sufficient, but if an attribute is a pointer, only the pointer address is copied (not the actual data), leading to shared memory between objects. This can cause issues, especially with dynamically allocated memory.
    
- **Deep Copy**: For objects with pointers, a deep copy is often necessary. This involves allocating new memory and copying the actual data (not just the pointer).

#### Example of Shallow Copy vs. Deep Copy

Suppose RectangleWithColor has a color pointer that points to dynamically allocated memory. Here’s a deep copy solution for such a class:

class RectangleWithColor {
private:
    double height;
    double width;
    int* color; // Pointer attribute

public:
    <mark style="background: #FFB8EBA6;">RectangleWithColor(double h, double w, int col) 
        : height(h), width(w) {</mark>
        <mark style="background: #FFB8EBA6;">color = new int(col); // Allocate memory for color</mark>
    }

// Deep copy constructor
    <mark style="background: #FFB8EBA6;">RectangleWithColor(const RectangleWithColor& other)
        : height(other.height), width(other.width) {</mark>
        
<mark style="background: #FFB8EBA6;">color = new int(* (other.color) ); </mark>// Allocate new memory and copy value
    }

<mark style="background: #FFB8EBA6;">~RectangleWithColor()</mark> { // Destructor
        <mark style="background: #FFB8EBA6;">delete color; // Free allocated memory</mark>
    }
};


In this example:

- The deep copy constructor creates a new `int` for `color` and copies the value from `other.color`.
- The destructor (`~RectangleWithColor`) ensures memory is freed, preventing memory leaks.

### Avoiding the Copy Constructor

If you want to prevent an object from being copied, you can **delete the copy constructor** using = delete:

class NonCopyable {
public:
    NonCopyable() = default; // Default constructor
    <mark style="background: #FFB8EBA6;">NonCopyable(const NonCopyable&) = delete; // Deleted copy constructor</mark>
};
### Important Notes on Copy and Assignment

**Copying vs. Assignment**: The copy constructor creates a new object as a copy of another. Assignment (=) replaces the contents of an already existing object.

Rectangle rect1(3.0, 4.0);
Rectangle rect2; // Default constructor
rect2 = rect1;   // Assignment, not copy construction

# Operator Overloading 

Operator overloading is done by defining a function with the keyword operator followed by the operator symbol you wish to overload

##### General Structure
ReturnType operator<symbol>(ParameterList) {
    // Code for the operation
}

**1. Binary Operators (e.g : +, -, *, / )  :** 
Typically used for operations involving two operands.

// Example: Overloading the + operator for a class called "Complex"
class Complex {
    private:
        double real, imag;

    public:
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}

        // Overload + operator
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }
};

**2. Unary Operators (e.g., `++`, `--`, `-`): Used for operations involving a single operand.**

// Example: Overloading the - (unary minus) operator for a class called "Complex"
Complex operator-() const {
    return Complex(-real, -imag);
}

**3. Comparison Operators (e.g:  ==, !=, <, >  ): Used for comparisons.**

// Overloading == to compare two Complex objects

bool operator==(const Complex & other) 
const {
    return (real == other.real) && (imag == other.imag);
	  }

** 4. Assignment Operators** (e.g., `=`): Used to assign one object to another.
// Overloading the assignment operator =
Complex& operator=(const Complex& other) {
    if (this != &other) {   // Avoid self-assignment
        real = other.real;
        imag = other.imag;
    }
    return *this;   // Return the current object to allow chaining
}

** 5. tream Operators** (e.g., `<<` for output, `>>` for input): Often overloaded as friend functions.

// Overloading << for outputting a Complex object
friend ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

<mark style="background: #FF5582A6;">Example Complete Class with Operator Overloading : </mark>

#include < iostream >
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload == operator
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;          // Uses overloaded +
    Complex c4 = c1 - c2;          // Uses overloaded -
    bool areEqual = (c1 == c2);    // Uses overloaded ==

    cout << "c1 + c2 = " << c3 << endl; // Uses overloaded <<
    cout << "c1 - c2 = " << c4 << endl;
    cout << "c1 == c2: " << (areEqual ? "true" : "false") << endl;

    return 0;
}

---

# Static - Instance Variables 

- **Instance Variables** are unique to each object and represent the object's state.
- **Static Variables** are shared among all instances, with only one copy existing for the entire class.
- **Static Functions** can access only static members and are typically used for class-level operations.


---
# Inline Function 

An **inline function** in C++ is a function for which the compiler attempts to substitute the function code directly into the calling code instead of generating a regular function call. This approach is generally intended to improve performance by avoiding the overhead of a function call, especially for small, frequently called functions

### When to Use Inline Functions

Inline functions are usually small, quick-to-execute functions where the overhead of calling the function is greater than the time taken by the actual function code. They are often defined within the class definition itself.

### Pros and Cons of Inline Functions

#### Pros

1. **Reduces Function Call Overhead**: Inlining avoids the jump to another memory location to execute a function, which can speed up the execution of small functions.
2. **Enables Compiler Optimizations**: With inline code, the compiler can perform more optimizations, such as loop unrolling or constant folding.

#### Cons

1. **Code Size Increase (Code Bloat)**: Inline functions increase the binary size of the program, especially if they’re large or used in multiple places. This can lead to increased memory usage and may degrade performance in some cases.
2. **Compile-Time Overhead**: The compiler spends more time processing inline expansions, which could slow down compilation.

### When Not to Use Inline

- Avoid using inline functions for large functions or functions with complex control structures, as they might not be inlined anyway.
- Inline functions shouldn’t generally be used for recursive functions, as recursion creates additional calls that defeat the purpose of inlining.

