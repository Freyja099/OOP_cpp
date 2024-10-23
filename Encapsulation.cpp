// * Session 4 : Pillars in OOP / Encapsulation : 

// * In OOP the four main pillars that define its principles are :
// * Encapsulation , Abstraction , Inheritance and polymorphism

// *** Encapsulation
// * It's the idea of bundling or tying together data and methods that 
// * operate on that data so that they grouped together within a class
// * We do this with the purpose of preventing anyone or anything outside 
// * our class to be able to directly access our data and to interact with it
// * and to modify it ; 

// * To provide a way for other classes to interact with the properties of our class , we have to use 
// * a very specific public functions that other classes can invoke and that interact with our data 
// * To access encapsulated properties of a class the answer is through its methods ; 
// * these methods are very often implemented as "getters" and "setters"

// * first we want to make the properties private (encapsulate the properties) 

// TODO same e.g:

#include <iostream>
using namespace std;

class employee
{
private:             // * the properties are private now
    string name;
    string company;
    int age;
public:

    // * the first setter for name 
    void setname(string name_setter) 
    {
        name = name_setter ;
    }
    // * now the getter for name 
    string getname()
    {
        return name;
    }
    //* ***************************************************************
    // * setter for company
    void setcompany(string company_setter)
    {
        company = company_setter;
    }
    string getcompany()
    {
        return company;
    }
    //* ***************************************************************
    void setage(int age_setter)
    {
        age = age_setter;
    }
    /* void setage (int age_setter) 
    {
        if (age_setter >= 18)
        age = age_setter ;
    }
   */
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
int main()
{
    int number;
    employee employee1 = employee ("John" , "Google" , 34 );
     // * the first employee is the class, the last one is the constructor
    employee1.introduce_yourself();

    employee1.setcompany("Amazon");
    cout << employee1.getname() << " is working for " << employee1.getcompany() << endl;

    employee1.setage(14);
    cout << employee1.getname() << " age is " << employee1.getage();
    return 0;
}
// * output : Name : John , Company Google and age 34  
// *           John is working for Amazon


// * We can apply certain validation rules like inside setter like using if to commit the changes only if the condition is true 
// * for ex using : 
/* void setage (int age_setter) 
    {
        if (age_setter >= 18)
        age = age_setter ;
    }
*/
// * in this case if we set an age < 18 John's age will not be changed, but if we set an age >=18 it will get the new value 