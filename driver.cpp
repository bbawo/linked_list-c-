#include <iostream>
#include <string>
#include "Dlist.h"

using namespace std;

void instructions()
{
    cout << "Enter one of the following: \n"
        << "    1 to insert at beginning of list\n"
        << "    2 to insert at end of list\n"
        << "    3 to delete from beginning of list\n"
        << "    4 to delete from end of list\n"
        << "    5 to sort list \n"
        << "    6 to end list processing \n";
}

template< typename T >
void testList( Dlist< T > &listObject, const string &typeName )
{
    cout << "Test a List of " << typeName << " values\n";
    instructions();


    int choice; //store user choice
    T value;    //store input value

    do{
        cout << "? ";
        cin >> choice;
        switch ( choice )
        {
            case 1:
                cout << "Enter " << typeName << ": ";
                cin >> value;
                listObject.push_front( value );
                listObject.print();
                break;
            case 2:
                cout << "Enter " << typeName << ": ";
                cin >> value;
                listObject.push_back( value );
                listObject.print();
                break;
            case 3:
                if( listObject.pop_front( value ) )
                    cout << value << " removed from list\n";
                listObject.print();
                break;
            case 4:
                if( listObject.pop_back( value ))
                    cout << value << " removed from list\n";
                listObject.print();
                break;
            case 5:
                listObject.sort();
                cout << "sorted list: \n";
                listObject.print();
                break;
            /*case 6:
                listObject.reverse();
                cout << "reversed list: \n";
                listObject.print();
                break;*/
        }
    }while( choice <= 6 );

    cout << "End of testList\n";
}

int main()
{
    //testList of int values
    Dlist< int > integerList;
    testList( integerList, "integer");

}