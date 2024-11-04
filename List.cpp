// * Session 12 : List 

// * push back : to add new element to the end of the list
// * push front : to add new element to the front of the list
// * pop back : to remove the last element of the list
// * pop front : to remove the first element of the list

// * each element of the list is called node

#include <iostream>
#include <list> // * include the list library

using namespace std;

// * to display the list 
void displayRating( const list<int>& playersRating) // * adding & to pass the parameter by reference
{
    for ( list <int> :: const_iterator it = playersRating.begin(); it != playersRating.end(); it++)
    {
        cout <<" Player Rating :"<< *it << endl;
    }
} 
// * Sort players
void SortPlayers( int newplayer ,list<int>& the_list)
{
    for (list <int> :: iterator it = the_list.begin() ; it != the_list.end() ; it++)
    {
        if (*it > newplayer)
        {
            the_list.insert(it , newplayer);
            return;
        }   
    }
    the_list.push_back(newplayer);
}

// ! Some helpful modification :

// ! If we pass parameters by value the function will make it's own copy and work with it , in the other hand 
// ! if we pass parameters by reference we will work directly with the original function 
// ! the difference here is with the excecution time 

// ! If we want to make sure that the function doesn't change the original parameters we have to add const infront of the parameter
// ! if we made that change we have to use const_iterator too 

int main()
{
    list <int> players = { 1 ,3 , 5 , 6, 2 , 9 , 4 , 7 , 8};
    list <int> beginners; // * To regroup players that has rating 1-5
    list <int> advanced; // * To regroup players that has rating 6-10

    for ( list <int> :: iterator it = players.begin(); it != players.end(); it++)
    {
        int temp = *it;
        if (temp >= 1 && temp <= 5)
        {
            SortPlayers(temp , beginners);
        }
        else if (temp >=6 && temp <=10)
        SortPlayers(temp , advanced);
    }

    
    cout << "Beginners Rating :"<< endl;
    displayRating(beginners);
    cout << "Advanced Rating :"<< endl;
    displayRating(advanced);

return 0;
}

