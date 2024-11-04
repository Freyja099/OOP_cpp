// * Session 13 : Map

#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

// * Map data collection stores elements in key value pairs
// * map < type of key , type of the value > MapName ;

// * To insert new elements :
// * MapName . insert(pair <type of key , type of value>(values) );

/*
int main ()
{
    map < string , string > myMap;
    myMap.insert(pair <string , string > ("map1.1" , "map1.2"));
    // * If we want to associate two values for the same key we use 

    // * MapName . insert(pair <type of key , type of value>( key , value1,value2 ) );
    myMap.insert(pair <string , string > ("map2.1" , "map1.2.1 , map1.2.2"));

    for (auto pair : myMap)
    {
        cout << "Key: " << pair.first
        << ", Value: " << pair.second << endl;
    }

    cout << myMap.size() << endl;
    myMap["map1.1"] = "map1.1_with_changes";
    myMap.erase("map1.1");
    for (auto pair : myMap)
    {
        cout << "Key: " << pair.first
        << ", Value: " << pair.second << endl;
    }
    return 0;
}
*/

// * Creating pokedex
int main()
{
    map < string , list < string > > pokedex ;

    list < string > pikachuAttacks { " Thunder Shock" , " Tail Whip " , " Quick Attack "};
    list < string > charmanderAttacks { "Flame thrower" , "scary face" };
    list < string > chikoritaAttacks { "Razor Leaf" , " Poison Powder "};

    pokedex.insert(pair <string, list<string>>("Pikatchu",pikachuAttacks));
    pokedex.insert(pair <string, list<string>>("Charmander",charmanderAttacks));
    pokedex.insert(pair <string, list<string>>("Chikorita",chikoritaAttacks));

// * the first for is iterating the first pair of the collection which is the key
    for ( auto pair : pokedex)
    {
        cout << pair.first << " - " ;
// * the second for is iterating the second pair of the collection which is the list of attacks 
        for ( auto attack : pair.second )
        cout << attack << " , ";

        cout <<endl;
    }
    return 0;
}


// * Map order elements by key in  ascending order alphabetically for strings
// * If we don't want that the element be ordered alphabetically then we need to use unordered_map in include

