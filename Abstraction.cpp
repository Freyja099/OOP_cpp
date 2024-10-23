// * Session 5 : Abstraction :

// * Abstraction means hiding complex things behind a procedure that makes 
// * those things look simple  ; 
// * we should provide that complex logic for those functionalities that are complex
// * then we should provide a simple interface for anyone who wants to use the class

// * to make the method function obligatory we have to make it a pure virtual function
// * by adding at first virtual and at last = 0

// * To make the class sign the contract we have to add to class name : - name of the contract - {...}
// * and add the pure virtual function to our public class 
// * inside the function we have to add the complex logic we have talked about



// TODO same e.g:

#include <iostream>
using namespace std;

class abstract_employee  // * this contract has only one rule is to whichever class decides 
// * to sign this contract that class will need to provide implementation for a method called ask for promotion 
{
    virtual void ask_for_promotion() = 0; // * the method
    // * pure virtual function
};

class employee : abstract_employee                  // ! the abstract class = the contract 
{
private:             // * the properties are private now
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
    employee employee2 = employee ("Jane" , "Google" , 26);
    
    employee1.ask_for_promotion();
    employee2.ask_for_promotion();
    return 0;
}