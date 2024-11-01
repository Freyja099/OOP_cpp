// * Session 9 : Instance and Static variables :

// * Instance variables are variables that are declared inside a class and have a scope that is limited to the object of that class.
// * Using Static variables will make all the instances of the class will share the same memory location
// * to do so we have to add before the instance variables the word static, it's like a pointer pointing to a global variable 
// * we have to add a definition outside the class and main 
// * type Class :: variable_name = value ;

#include <iostream>
using namespace std;

class Integer
{
private:
    int num;
    static int shared;

public:
    Integer(){ num = 0; }
    void set(int i){ num = i; }
    int get(){return num;}
    int getShared() const { return shared;}
    void bump(){ shared++; }

// * The point of these functions is that it can be executed without an instance of class Integer being instantiated 
    static void updatedShared(int i) { shared = i ; }
    static int retrieveShared() { return shared ; }
};

int Integer :: shared = 0; //* Static member variable

int main()
{
    // * in the next line no instance of Integer has been defined yet and we will get 0
    cout << Integer::retrieveShared() << endl;
    Integer:: updatedShared(98); 
    /* If we add this line our output will be : 0
                                                98 - 98
                                                99 - 99
    */

    Integer i1,i2;

    cout<< i1.getShared() << " - " << i2.getShared() << endl;
    i1.bump();
    cout<< i1.getShared() << " - " << i2.getShared() << endl; // * i2 is incremented too   
    return 0;

}

// * we can't use a static function to a function that returns an instance 