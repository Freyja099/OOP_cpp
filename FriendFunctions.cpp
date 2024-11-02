// * Session 10 : Friend Functions/Classes


// * A friend function has access to private and protected members of a class 

// * To declare a friend function we should use the keyword "friend" infront of the prototype of the function and put it inside the class

#include <iostream>
#include <cmath>
using namespace std;

class EquilateralTriangle
{
private:
    float a;
    float circumference;
    float area;

public : 
    void setA(float length)
    {
        a = length;
        circumference = a*3;
        area = ((a*a)*sqrt(3))/4;
    }

    // friend void PrintResults(EquilateralTriangle );
    friend class Homework ;

};

// * Friend Function 
/*
void PrintResults(EquilateralTriangle et)
{
    cout << "circumference = " << et.circumference << endl;
    cout << "area = " << et.area << endl;
}
*/

// * Friend Class
class Homework
{
public :
    void PrintResults(EquilateralTriangle et)
    {
        cout << "circumference = " << et.circumference << endl;
        cout << "area = " << et.area << endl;
    }
};
int main()
{
   EquilateralTriangle et;
   et.setA(3);

   // PrintResults(et);
   
   Homework h ;
   h.PrintResults(et);

   system("pause>nul"); 
}

// * A class can have mutltiple friend functions 

// ! Friend is not mutual in programming ; Homework is friend of EquilateralTriangle
// ! and have the access to its instance while EquilateralTriangle does not have access to Homework's instance
// ! to make it mutual we should declare in  class Homework that EquilateralTriangle is a friend of it


// ! Friendship is not inherited

// * Friend functions are used very often when we are using overloading operators
