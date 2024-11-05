// * Session 14 : Set

// * A set is a container that stores unique elements in a specific order.
// * It only stores unique values. If you try to insert a duplicate element, it will be ignored

#include <iostream>
#include <set>
using namespace std;

class Foo
{
    int i ;
public :
    Foo (int x) : i (x) {}
    int get() const { return i; }
    bool operator<(const Foo& other) const
    {
        return i < other.i;
    }

    bool operator==(const Foo& other) const
    {
        return i == other.i;
    }
};

int main ()
{
    set <Foo> s { Foo(1) , Foo(2) , Foo(3) };
    for ( auto a : s)
    {
        cout << a.get() <<endl;
    }

    set <Foo> :: iterator it = s.find(Foo(3));
    if ( it != s.end())
    {
        cout << it -> get() << endl;
    }
    else 
    {
        cout << "Not found" << endl;
    }

    
    cin.get(); // paise the program 

}


/* 
int main()
{
    set <int> nums = { 2 , 6 , 2 , 9 , 0 , 4 , 4 , 4}; // * 0 2 4 6 9
    set <int> empty_set; // * default constructor
    set <int> nums2{ 8 , 8 , 2 , 1 , 1 , 0 , 0 , 5 }; // * 0 1 2 5 8

    // * Copy constructor
    set <int> copy_of_nums ( nums );

    // * To print our set :
    /*
    for (auto i : nums2)
    {
        cout << i << " " ;
    }    * /

    // * Iterators
    set <int> :: iterator it_f = nums.begin();
    it_f++;

    set <int> :: iterator it_b = nums.end();
    it_b--;

    set <int> new_set ( it_f , it_b); 

    // * To choose from where to start and when to stop we have defined 
    // * it_front increment by 1 that means the first list will begin by the second element
    // * and for the second list we have decremented it_back by one so we will not stop at n element
    // * but at the n-1 element 

    for (auto i : new_set)
        cout << i << " " ;
    cout <<endl;

    // * To traverse the set using while loop
    // * We have first to initialize iterator to begin

    it_f = new_set.begin();

    while( it_f != new_set.end())
    {
        cout << *it_f << " " ;
        it_f++;
    }
    cout << endl;

    // * To find an element in a set we can use find() function but we have to make sure to drop a message 
    // * if the iterator doesn't find the value otherwise the program will crash

    set <int> :: iterator it = nums.find(4);
    if ( it != nums.end() )
    {
        cout << "the value is " << *it << endl;
    }
    else
    {
        cout<<"the value does not exist in the set " << endl;
    }

    return 0;
}

*/