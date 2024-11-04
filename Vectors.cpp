// * Session 12 : Vectors

// * A vector is a dynamic array that can grow and shrink in size
// * the elements are stored continuously
// * the elements are accessed by their index
// * the index starts at 0

// * First thing include vector , then declare it that way : vector < type_of_variable > VectorName
// * To insert an element to vector we use push_back or push_front 
// * VectorName.push_back(the element we want to add);

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vector1;
    vector1.push_back(0);

// * Let's try insert 10 elements
    for (int i= 0 ; i<10;i++)
    {
        vector1.push_back(i);
    }

// * First method to print a vector
    for ( int number : vector1 )
    cout << number <<endl;

// * Print vector using iterators
    // * the auto is to not worry about the type of vector and let the compiler will assign the right type to it 
    for (auto it = vector1.cbegin() ; it != vector1.cend() ; it++ )
    {
        // * the next has no effect since we used cbegin() and cend() to make it const instead of begin() and end()
       //  *it = 20;

        cout << *it <<endl; // * the value of the element of the iterator
        cout << &it <<endl; // * the address of the iterator
        cout << &(*it) <<endl; // * the address of the element 
    }

auto it = vector1.begin();
cout << * ( it + 5 );           // * output 5 since we started with 0

// * To insert the element at a specific position we use :
// * VectorName.insert( the position , the element we want to add)
    vector1.insert ( vector1.begin() + 5 , 10); // * the element with index 5

    // * To print it :
    for (auto n : vector1)
    cout << n <<endl;
 
 // * To delete a certain element 
 // * VectorName.erase( the position of the element we want to delete)
    vector1.erase(vector1.begin() + 5); // * the element with index 5

    // * To print it :
    for (auto n : vector1)
    cout << n <<endl;

    return 0;
}