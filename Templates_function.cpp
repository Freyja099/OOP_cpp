// * Session 11 : Function Templates

// * Function templates describes what a function looks like 
// * It can be used to generate as many overloaded functions as needed, each using different data types

// *

#include <iostream>
using namespace std;
template <typename T>

T max1(T x,T y)         // ! Avoid using just max here ; the compiler doesn't know whether you're referring to the 
                        // ! std::max function or your own max function template.
{
    return(x>y)? x :y;
}
int main()
{
    cout << "1 - Max of 1 and 3 is "<<max1 ( 1 , 3) <<endl;
    cout <<"2 - Max of 2.5 and 3.7 is" << max1 ( 2.5 , 3.7) << endl;
    cout <<"3 - Max of 'a' and 'b' is "<< max1 ( 'a', 'b') << endl;
    system("pause>nul");
}

// * To solve the problem of creating overloaded functions that each do the 
// * same thing the only difference is that they accept and return different data types;
// * Using a template function make us use one function that accept and return any data type
// * the syntaxe is :
// ! In case the type of return and the parameters are all the same 
// * adding at first a declaration of the template (usually we use t)
// * that way : template <typename T>
// ! no ; at the end 
// * then instead of declaring the function and the parameters with a certain data type we use T
// ! If we use different types we can add another template like this :
// * template <typename T , typename U>
// * auto function(T n1, U n2);
// ! using auto make the compiler deduce what the return type should be 