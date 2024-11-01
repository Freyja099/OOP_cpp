// * Session 8 : All Types of Constructors 

#include <iostream>
#include <string>
#include <array>

using namespace std;

class User
{
    string FirstName;
    string LastName;
    int Age;
    string Email;
    
    public:

void setFirstName(string FName_setter)
{
    FirstName = FName_setter;
}
string getFirstName()
{
    return FirstName;
}
void setLastName(string Lname_setter)
{
    LastName = Lname_setter;
}
string getLastName()
{
    return LastName;
}
    //*   User(){}    Default Constructor */

  /*  User()  // * We created our defautle constructor
    {
        FirstName = "nn";
        LastName = "nn";
        Age = 0;
        Email = "nn";
    } */

    string *array;
    string T[2];

    /* Other methods : 
    use include array and string first
    array <string, 2 > T;
    T[0]= firstname; T[1]= lastname;
    string *array = T.data();

    or by using vector 
    vector<string> T = {firstname, lastname};
    */

// * Parameterized Constructor
    User (string firstname , string lastname , int age )
    {
        FirstName = firstname;
        LastName = lastname;
        Age = age;
        Email = firstname + "." + lastname + "@gmail.com";

        array = new string [2];
        T[0] = firstname;
        T[1] = lastname;

        array[0]=T[0];
        array[1]=T[1];
    }

    // * Copy Constructor
    User ( const User& other)
    {
        array = new string [2];
        for (int i = 0; i < 2; i++)
        {
            array[i] = other.array[i];
        }

        Age = other.Age;
        Email = other.Email;
    }

    // * Destructor
    ~User()
    {
        cout << " now the user is deleted " <<endl;
        delete[] array; // * if we used delete array we will only delete the first element of the array
        array = nullptr; // * it is recommended to set array to nullptr after deleting it
    }
};

int main()
{
    User user1("John", "Doe", 25);
    cout << " "<< user1.getFirstName() << " and " << user1.getLastName() << endl ;
    return 0;
}



// * 1st type default constructor: If we don't initialize our attributes and want to execute the program on main they will be 
// * initialized by the default constructor with default values for integers and for strings it will be an empty string; 

// * 2nd type Parameterized Constructor : It receives certain values as arguments and then uses those values in order to instantiate 
// * the properties of that object 

// * Destructor : it always start with the tilda sign "~" and its name should match the class name too, and no return type 
// * not even void, no parameters, it has to be a member function of the class and should be public, and finally it can be only one 
// * destructor per class and we should never invoke a destructor manually it will be invoked automatically at the end of the scope 
// * of each object
// * destructor is going to be invoked in the reverse order ( if we declare a user1 and user2, the destructor will destroy user2 first 
// * then user1 )
// * We don't really need a destructor for a program that has no pointers, the compiler can generate one at the end 
// * in that case we should tell the destructor to delete the pointer 

// * 3rd type Copy constructor : it's used while working with pointers; receives one parameters and it should be the same class 
// * as it belongs to
// ! if we use just the name of the class (passing an object by value) this will create a logical error 
// ! because in this case the compiler will take the object we want make a copy of it and pass it to the function but in order 
// ! to copy the object the compiler need to have a copy constructor that's why we get an error 
// * To fix this problem we have to pass it by reference == adding a & at the end, also we have to add at first const to prevent 
// * any changes from outside 
// * when working with pointers we should set a new array / integer ... to avoid confusing the destructor of which array should it 
// * delete for the copy constructor since the original one will be already destroyed

// ** A copy constructor is invoked :
// * - Whenever we are creating a new object based on an already existing one example : in main : User user3(user1);
// * there's no difference between those two lines : User user3 = user1; and User user3(user1);
// * - When the compiler is creating a temporary object ; example : when passing an object to a function by value 
// * void fun(User book){....} , in main to use this function we have to call it like this : fun(user1);
// * - When we are returning an object from a function but only if we are returning it by value 