// * Session 7 : Polymorphism

// * Polymorphism (many forms) in programming it describes the ability of an object
// * or a method to have many forms
// * The common use of the polymorphism is when a parent class reference is used to 
// * refer to a child class object

// * Polymorphism allows us to define a method in a parent class that can be overridden by each child class.
// * Each child class can provide its own implementation of this method, allowing us to call the same method
// * on different child classes and have them behave according to their specific implementation.


// TODO same e.g:

#include <iostream>
using namespace std;

class abstract_employee  
{
    virtual void ask_for_promotion() = 0; // * the method
    // * pure virtual function
};

class employee : abstract_employee                  // ! the abstract class = the contract 
{
protected:
    string name;
    string company;
    int age;
public:
    // ! the pure virtual function
    void ask_for_promotion()
    {
        if(age > 30)
            cout<< name << " got promoted " << endl;
        else
            cout<< name << " sorry no promotion " << endl;
    }
    virtual void work()  // * we have to add virtual to make the polymorphism work 
    {
        cout << name << " working in a project  ";
    }

    // * Constructor : 
    employee(string name_c , string company_c , int age_c)
    {
        name = name_c;
        company = company_c;
        age = age_c;
    }
};


class Developer : public employee 
{
public :
    string fav_programming_language;
    Developer(string name_c , string company_c , int age_c, string fav_programming_language_c) 
            :employee(name_c,company_c,age_c)
    {
     fav_programming_language = fav_programming_language_c;
    }
    
    void work() 
    {
        cout<< name << " is working for " << company << " and do other stuff like coding with " << fav_programming_language << endl;
    }
};

class Teacher : public employee
{
public:
    string subject;
    Teacher(string name_c , string company_c , int age_c , string subject_c) 
            :employee(name_c,company_c,age_c)
    {
        subject = subject_c;
    }
    void work()
    {
        cout<< name << " job is to make kids learn " << subject << endl;
    }

    
};

/*
int main()
{ 
    Developer developer1 = Developer("Sam","Google", 34 ,"C#");
    Teacher teacher1 = Teacher ("Alice" , "NULL" , 0 , "math");
    
    developer1.works();
    teacher1.works();

    return 0;
}
*/

// * output : Sam is working for Google and do other stuff like coding with C#
// *          Alice job is to make kids learn math

// * By using polymorphism we create a pointer instead of the work we did before


int main()
{
    Developer developer1 = Developer("Sam","Google", 34 ,"C#");
    Teacher teacher1 = Teacher ("Alice" , "NULL" , 0 , "math");
    employee* e1 = &developer1;
    employee* e2 = &teacher1;

    e1->work();
    e2->work();

    return 0;
}

// * output : Sam is working for Google and do other stuff like coding with C#
// *          Alice job is to make kids learn math


// * When a virtual function is invoked, it checks if there is an implementation in the derived classes.
// * If a derived class has overridden the function, that implementation is executed instead.
// * The most derived version of the virtual function will be called at runtime, ensuring that
// * each object uses its specific implementation.
