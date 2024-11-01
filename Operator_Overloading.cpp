// * Session 10: Operator Overloading 

// * Operator functions are used to define how a certain operator will behave with different types of objects  
// * 

#include <iostream>
using namespace std;

class Number
{
public:
    int n;

    Number(int set_n){n=set_n;}

    Number operator+(const Number &other)
    {
        cout << " this -> " << this -> n << endl;
        cout << "other.n : "<< other.n <<endl;
        return Number(this-> n +other.n);
    }

    // * the n in that case is a and the other is going to be b

    bool operator == (const Number &other2)
    {
        if (this -> n == other2.n )
        return true;
        else return false;
    }

};

int main()
{
    Number a(5);
    Number b(5);

    Number c = a + b; // * If we didn't define the + operator previously we would get en error here
    cout << " c.n : "<<c.n<<endl;

    if (a == c) cout << " a is equal to c " << endl;
    else cout << " a is not equal to c " << endl;
    return 0;
}