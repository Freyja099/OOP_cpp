// * Session 3 : Constructors

// * There's a better approach of constucting our objects insted of 
// * using for each attribut the variable.attribut = ; 
// * To resume a constructor is a special type of method that is invoked
// * each time that an object of a class is created 
// * in case we don't create a constructor on our own the compiler will 
// * generate a default constructor
// * There are 3 rules for creating constructor :
// * - following ; unlike other method a constructor does not have a return type
// * - it has the same name as the class that it belongs to
// * - it must be public(not always)

// TODO same e.g:

#include <iostream>
using namespace std;

class employee
{
private:
    string name;
    string company;
    int age;
public:
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
    return 0;
}

// * using this our code become much smaller and doesn't repeat lines for each "employee" in that case 
// * + we can now set the attribut to private