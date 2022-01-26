#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<char> li= { 'a', 'b', 'c', 'd', 'e' };


    list<char>::iterator x;
    cout<<"Przejście po elementach lsty"<<endl;
    for (x = li.begin(); x != li.end(); ++x) {

        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    }


    for (x = li.begin(); x != li.end(); x++) {
// użycie iteratora wyjścia do zmiany lub przypisania nowych wartości do wszystkich
// elementów listy
        *x -=32;
    }
    cout<<endl;
    cout<<"Traversing elements of the list after assigning a new value to the list.."<<endl;
    for (x = li.begin(); x != li.end(); ++x) {

        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    }

    return 0;
}