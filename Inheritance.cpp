// * Session 6 : Inheritance

// * The base class also known as parent class or super class
// * Derived class also known as child class or subclass

// * The base class has certain attributes and behaviors it has members
// * and then if the subclass decides to inherit from the base class at that moment
// * the subclass become a child class and it's going to obtain all of the members of the base class
// * which means it will have all the same attributes and behaviors as its base class and can also
// * have its own members that are specific for that class only which the base class does not have

// * - For example a car besides its attributes like model brand 
// * it can has a method for example drive
// * - the kind of classes that we can derive from this base class that can be more specific
// * in that case it can be the car types ; we can have one derived class that it is called electric car
// * and another derived class that is called gas car
// * - the electric car will have the same properties that a car has (name, model, color,...) and method called drive
// * - this will be the same for the gas car, but they are going to be different between them 
// * - the electric car is going to have a method called charge and an attribute called battery_status
// * - for the gas car  is going to have a method called tank which means a method of putting fuel in that car and an attribute
// * tank_status which shows you how much gas do we have left in the tank 
// * - This shows that two derived classes have their specific attributes but they will also inherit all of those attributes that
// * their base class has 



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
private:             // * the properties are private now
    string name;
    string company;
protected:
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

    // * setter/getter for name 
    void setname(string name_setter) 
    {
        name = name_setter ;
    }
    string getname()
    {
        return name;
    }
    //* ***************************************************************
    // * setter/getter for company
    void setcompany(string company_setter)
    {
        company = company_setter;
    }
    string getcompany()
    {
        return company;
    }
    //* ***************************************************************
    // * setter/getter for age
    void setage(int age_setter)
    {
        age = age_setter;
    }
    int getage()
    {
        return age;
    }
    //* ***************************************************************
    void introduce_yourself()
    {
        cout<<" Name : " << name 
            << " , Company " <<  company 
            << " and age "<< age << endl;
    }

    // * Constructor : 
    employee(string name_c , string company_c , int age_c)
    {
        name = name_c;
        company = company_c;
        age = age_c;
    }
};

// * Now the class that can inherit from employee
// * Developper
class Developer : employee // * by adding : another class we say that this is a child class from the one after :
{
public :
    string fav_programming_language;
    Developer(string name_c , string company_c , int age_c, string fav_programming_language_c) 
            :employee(name_c,company_c,age_c)
    {
     fav_programming_language = fav_programming_language_c;
    }
    // * it  has the same parameters of the constructor of the parent class + the one that it's specific for developper ,
    // ! since the first three have already a constructor we don't have to initialize them but we should add
    // * : constructor_of_the_parent_class (the parameters)

    // * The method:
    void fix_bug()
    {
        cout << getname() << " is fixing bug using " << fav_programming_language <<endl;
    }

    void introduce()
    {
        cout << getname() << " is "<< age << " years old , and like working with "<< fav_programming_language << endl;
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

    void introduce()                       // * I did use the same name of a function in developer 
                                           // * class to see if it won't make any confusion since each one of the child classes
                                           // * do not share the same method
    {
        cout << getname() << " is a "<< subject << " teacher"<< endl;
    }
};

int main()
{ 
    Developer developer1 = Developer("Sam","Google", 34 ,"C#");
    developer1.fix_bug();                                       // * Output : Sam is fixing bug using C#

    developer1.introduce();                                     // * Output : Sam is 34 years old , and like working with C#

    Teacher teacher1 = Teacher ("Alice" , "NULL" , 0 , "math");
    teacher1.introduce();                                       // * Output : Alice is a math teacher
    return 0;
}

// ! Every class has its own default constructor but once we create our own we lose
// ! that default constructor now we have to create a constructor for Developper too
// ! because its a childclass ; we already created a constructor for employee, now we have to provide 
// ! a constructor for the derived classes of employee class

// ! in the child class method we used getname() because we can not access to private properties of the parent class
// ! But there's a way to access directly to those properties by using protected modifier instead of private

// * If we wanted to use the method ask for promotion in the main function using the child class like this : developer1.ask_for_promotion()
// * it won't work because the child class is private by default , to change that we should add public modifier like this :
// * class developer : public employee{...}