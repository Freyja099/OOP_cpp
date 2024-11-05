# Friend Function 

A friend function has access to private and protected members of a class

To declare a friend function we should use the keyword "friend" infront of the prototype of the function and put it inside the class

A class can have mutltiple friend functions

Friend is not mutual in programming ; Homework is friend of EquilateralTriangle

and have the access to its instance while EquilateralTriangle does not have access to Homework's instance
to make it mutual we should declare in  class Homework that EquilateralTriangle is a friend of it

Friendship is not inherited

Friend functions are used very often when we are using overloading operators

# Inheritance

In C++, it is possible to inherit attributes and methods from one class to another. We group the "inheritance concept" into two categories:

- **derived class** (child) - the class that inherits from another class
- **base class** (parent) - the class being inherited from

To inherit from a class, use the `:` symbol.

---
### **Overriding Functions:** 
    
-  The derived class can redefine (override) methods from the base class. If the base class function is declared `virtual`, it can be overridden to allow polymorphism. 

-  Adding `override` in the derived class signals that this function is meant to override a virtual function in the base class, enabling compile-time checking.
---

To show that a class is a subclass from another class :
DerivedClassName : access_modifier BaseClassName

The access modifier can be either public or private ; 
If it' public that means :
- All privates instance in the BaseClass remains private for the DerivedClass too
- The protected and public instance are public for the DerivedClass

If it's private :
- All privates instance in the BaseClass remains private for the DerivedClass too
- The protected and public instance from BaseClass are private for the DerivedClass

#### Ambiguity in Multiple Inheritance

If the class inherits from more than one base class and supposing that each of them has the same name of a function (method)

If we want to use the function in the new derived class it will make a confusion for the compiler and someone reading the code that's why we have to specify which one to use by adding the scope resolution operator :: to specify the exact function to call

e.g : 
class A
{
	public :
	void display()
	{
		cout << " class A ";
	}
};

class B
{
	public :
	void display()
	{
		cout << " class B ";
	}
};

class C : public A, public B 
{
	public : 
	void view()
	{
		A::display();
		B::display();
	}
};

#  Polymorphism (Using a virtual function)
- The virtual function has to be a member of the class
- It can't be  a static member
- We can access to it using objects pointers 
- It can be friend of another class
- It should be defined in the base class even if we don't use it
- We can't have virtual constructor but it's possible to have virtual destructor 

## Pure Virtual Function
- The pure virtual function is declared in the base function 
- If a class has a pure virtual function it can't be used to declare its objects , that types of classes are called Abstract Classes
- A pure virtual method is a method that it's not declared in the base function but in one of the derived classes
- An Abstract class is a class that at least contains one pure virtual method
- Abstract function are only called by references or pointers 
- A pure virtual function is followed by =0 after it's declaration to show that it's a pure virtual function

# Exceptions
use # include < exeception>
When executing C++ code, different errors can occur: coding errors made by the programmer, errors due to wrong input, or other unforeseeable things.
When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an **exception** (throw an error).

## Try / Catch
try {.....} :  statement allows you to define a block of code to be tested for errors while it is being executed.

throw expression ; : an exception when a problem is detected, which lets us create a custom error.

catch (...){....} : statement allows you to define a block of code to be executed, if an error occurs in the try block.

# Templates 

Templates in C++ allow you to write **generic and reusable code**. Instead of writing separate functions or classes for each data type (like `int`, `float`, etc.), you can write a single template that works with any data type.

### Function Templates : 
Function templates let you create functions that operate with different types without rewriting the function multiple times.

**The syntaxe is :**

<mark style="background: #FFB86CA6;">In case the type of return and the parameters are all the same</mark>
adding at first a declaration of the template (usually we use t)
that way :
*template < typename T>*
<mark style="background: #FF5582A6;">no ; at the end</mark>
then instead of declaring the function and the parameters with a certain data type we use T

<mark style="background: #FFB86CA6;">If we use different types we can add another template like this :
</mark>
*template <typename T , typename U>*
*auto function(T n1, U n2);*
<mark style="background: #FF5582A6;">using auto make the compiler deduce what the return type should be</mark>

### Class Templates :

Class templates allow you to create classes that work with any data type. This is especially useful for data structures like lists, stacks, queues, etc.

---
 

---

# STL : Standard Template Library in c++ :

## Introduction
 STL is a library of components that are commonly used in c++.
 It is like a big box of tools (toolbox) that we can use when building things in c++ .

### Containers :
- Containers are boxes in which we store data that requires processing 
- The most commonly used containers are vector , list , map , set , stack , queue
- Each container provides different capabilities and beneficts

### Algorithms 
- Algorithms are like recipes for computers, it's used to tell them what to do with the data
- There are multiple algorithms already included in STL such as algorithms for sorting , searching , grouping , comparing the data , ... 

### Function Objects ( Functors )
- We can always create and customize our own algorithm using functors
- They are a custom implementation of algorithm

### Iterators
- Are used for navigating through the data inside containers ( we can think of it as pointers )
- The easiest way to visualize an iterator at work is to think about the cusor moving while we are typing the text . The same way we use cursor for navigating through the text in the document, algorithms use iterators to navigate through the data inside a container

## Vectors
- Vector provides you with all the benefits of the dynamic array with less work and errors.
- It stores elements in contiguous memory .
- Has the ability to resize itself automatically when an element is inserted or deleted

First include vector : # include < vector >
and for declaring it it's that way : 
vector < type_of_variable > VectorName

### Insert element
To insert elements to vector we use : 
VectorName.push_back/front (the element we want to add);


Another way is to is :
vector.insert(the_placement , the element we want to add );
### Print the vector
There's two ways to print the vector 
- The easy one :
for (type variable : vector )
cout << variable << endl;

- Using iterators :
Iterators are special functions that point to the front and back of the vector 
begin and end

for (auto it = vector.begin() ; it != vector.end() : it ++)
{
	cout << * it << endl ;
}
We can't use just it without * ,
- to get the value of the element we use the <mark style="background: #ADCCFFA6;">* it </mark>
-  the address of the iterator <mark style="background: #ADCCFFA6;">&it </mark>
- the address of the element <mark style="background: #ADCCFFA6;">&(* it)</mark>

To get a certain element we can use the following code:
first start by initializing iterator to begin like this 
auto it = vector.begin();
cout << * (it + n); here we will get to the n+1 position since it start with the first one and we add the n places 

- using :   
for (auto define_a_variable : VectorName)
cout << the variable;
#### const iterator :
use cbegin() or cend to avoid any changes of the iterator

### other functionality of vectors

- size : <mark style="background: #ABF7F7A6;">vector.size ()</mark>
- max size :<mark style="background: #ABF7F7A6;"> vector.max_size()</mark>
- capacity(how many element we can add to the vector before resizing it): <mark style="background: #ABF7F7A6;">vector .capacity ()</mark>
Two other methods to access to elements 
- element [ 0 ] is(element at position 0 ) : <mark style="background: #ABF7F7A6;">vector[ 0 ]</mark>
- element at ( 0 ) is (same as the previous one): <mark style="background: #ABF7F7A6;">vector.at(0)</mark>

- front(to access to the first element) : <mark style="background: #ABF7F7A6;">vector.front()</mark>
- back :<mark style="background: #ABF7F7A6;"> vector.back()</mark>
- Delete all elements : <mark style="background: #ABF7F7A6;">vector.clear()</mark>


### Delete an element 
#### In a specific position
VectorName.erase( the placement of the element);

#### At the end of the vector
VectorName . pop_back();

#### At the front of the vector
VectorName . push_back();
## List

We use containers to organize different kinds of data. Lists are one of the most commonly used containers in programming.
We need first to include it in our program.
We don't have to specify a size when declaring a list since it's a dynamic type of container which means it will automatically expand when we add more elements and shrink when we remove existing elements.

### Insert elements :
There are two methods that are used for inserting elements into the list and those are push back and push front 
**Push back** is used to add an element at the end of the list 
**Push front** is used to add an element at the beginning of the list 

ListName.push_back/push_front (the element we want to add );

In order to print the list we nedd to iterate through our list using iterators
( each element of the list is called node )
Using a for loop we will firstly initialize our iterator (kind of a pointer) by :
list < type >ListName  :: iterator give_name_to iterator = ListName.begin();

then for when to stop we write :
IteratorName != ListName.end();

and increment by one to go to the next node

and of course we use cout to print it but we have to know that the iterator itself points to an address but what we need to print is the value , that's why we going to print it using * IteratorName

### Delete elements :
To delete an element from our list we have to use erase() :
ListName.erase( a pointer to the element we want to delete )
if we want to delete the first or last element just use : ListName.begin() or ListName.end() inside the ( )

### Advantage/disadvantage of using list
- Inserting and deleting elements from the list is very fast
- Traversing and searching through data in the list is very slow (try using vector it's the opposite thing for vectors )
## Sets
A set is a container that stores unique elements in a specific order.
- It only stores unique values. If you try to insert a duplicate element, it will be ignored.
- By default, set elements are stored in ascending order.You can also define a custom ordering by specifying a comparison function.
- does not support direct access via indexes. Instead, it uses iterators for traversal.

### Initialize 

Include set firstly.
To initialize a set inside main :
set < type_of_data > SetName = { Values }; or use empty_set or without using = we can start declaring the variable direclty after the SetName

### Print the set
we can use an auto iterator like this 
for ( auto i : SetName ){ cout << i ; }

or by using while loop:
first we define the iterator and make it = to set.begin :

set < type_of_data > :: iterator name_for_iterator = SetName.begin();

while ( iteratorName != SetName.end())
{
cout << * iteratorName ;
iteratorName++ ;
}

## Maps 
Map data collection stores elements in key value pairs , each element is called pair it consists of key and value 
we have to include map first 

map < type of key , type of the value > MapName ;

### Insert element 
MapName . insert(pair <type of key , type of value>(values) );

### To print the map 
We use for (auto pair : VectorName)
{
	cout << pair .first << " . " ;  // To show the first pair

cout << pair.second ;     // To show the second pair 
}

### Access a specific element
MapName [ the key  ]
If we want to change the value we add = the_new_value;

MapName [ the key  ] = newValue;

### Function
- It exist a function that returns the size 
MapName.size()
- To delete all elements in the collection we use the function clear
MapName.clear();
- To delete an element we use the function erase 
MapName.erase(key of the element we want to delete)
