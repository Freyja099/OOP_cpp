// * Session 2 : Classes and Objects

// * To create a class it's outside main ; class name_of_class { body of class };
// * the body of the class contains the attributs and their behaviors

// * To use the class in main it's like type of variable and we put the name of variable we want 
// * to use one of the attributs in main we use the variable dot(.) the attribut we want
// * in cpp everything inside class is private by default 

// TODO Create an employee class : 

#include <iostream>
using namespace std;

class employee
{
    public:
    string name;
    string company;
    int age;

    void introduce_yourself()
    {
        cout<<" Name : " << name 
            << " , Company " <<  company 
            << " and age "<< age << endl;
    }
};
int main()
{
    int number;
    employee employee1;
    employee1.age = 34;
    employee1.name = "John";
    employee1.company = "Google";
    employee1.introduce_yourself();
    return 0;
}

// * Access modifiers in cpp are : private, public, protected .
// * private : only accessible inside the class 
// * public : accessible from outside the class
// * protected : accessible from outside the class and from its derived classes

// * describing behavior will be by a class method which is using a function inside class
// * an example for a behavior let's say that the employee can introduce himself 