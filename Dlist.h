#ifndef DLIST_H
#define DLIST_H

#include "LinkedList.h"
#include <iostream>

using namespace std;

template < typename NODETYPE >
class Dlist
{
    public:
        Dlist( );
        ~Dlist( );
        void push_front( const NODETYPE & );
        void push_back( const NODETYPE & );
        bool pop_front( NODETYPE & );
        bool pop_back( NODETYPE & );
        bool isEmpty() const;
        void print() const;
        void sort();
        void reverse();
        LinkedList< NODETYPE> *begin() const;
        LinkedList< NODETYPE> *end() const;
        int size() const;

    private:
        int list_size;
        LinkedList< NODETYPE > *firstPtr;
        LinkedList< NODETYPE > *lastPtr;

        LinkedList< NODETYPE > *getNewNode( const NODETYPE & );
};

template <typename NODETYPE >
Dlist< NODETYPE >::Dlist()
    : firstPtr( 0 ), lastPtr( 0 ), list_size ( 0 )
{
    //empty
}

template < typename NODETYPE>
Dlist< NODETYPE >::~Dlist()
{
    if(isEmpty())
    {
        cout << "Destroying nodes...\n";
        LinkedList< NODETYPE> *currentPtr = firstPtr;
        LinkedList< NODETYPE > *tempPtr;

        while( currentPtr != 0 )
        {
            tempPtr = currentPtr;
            cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
        cout << "All nodes destroyed\n\n";
    }
}

template < typename NODETYPE >
void Dlist< NODETYPE >::push_front( const NODETYPE &value)
{
    LinkedList< NODETYPE > *newPtr = getNewNode( value );
    list_size++;

    if( isEmpty() )
    {
        firstPtr = lastPtr = newPtr;
    }else
    {
        newPtr->nextPtr = firstPtr;
        firstPtr->prevPtr = newPtr;
        newPtr->prevPtr = nullptr;

        firstPtr = newPtr;
    }
}

template < typename NODETYPE >
void Dlist< NODETYPE >::push_back( const NODETYPE &value)
{
    LinkedList< NODETYPE > *newPtr = getNewNode( value );
    list_size++;

    if( isEmpty() )
    {
        firstPtr = lastPtr = newPtr;
    }else
    {
        lastPtr->nextPtr = newPtr;
        newPtr->prevPtr = lastPtr;
        newPtr->nextPtr = nullptr;
        lastPtr = newPtr;
    }
}


template < typename NODETYPE >
bool Dlist< NODETYPE >::pop_front( NODETYPE &value )
{
    if( isEmpty() )
    {
        return false;
    }else
    {
        list_size--;
        LinkedList< NODETYPE > *tempPtr = firstPtr;
        if( firstPtr == lastPtr )
            firstPtr = lastPtr = 0;
        else
            firstPtr = firstPtr->nextPtr;
            firstPtr->prevPtr = nullptr;
        value = tempPtr->data;
        delete tempPtr;
        return true;
    }   
}

template < typename NODETYPE >
bool Dlist< NODETYPE >::pop_back( NODETYPE &value )
{
    if( isEmpty() )
    {
        return false;
    }else
    {
        LinkedList< NODETYPE > *tempPtr = lastPtr;
        list_size--;
        if( firstPtr == lastPtr )
        {
            firstPtr = lastPtr = 0;
        }else
        {
            LinkedList< NODETYPE > *currentPtr = lastPtr->prevPtr;
                lastPtr = currentPtr;
                currentPtr->nextPtr = 0;
        }
        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

template < typename NODETYPE >
bool Dlist< NODETYPE>::isEmpty() const 
{
    return firstPtr == 0;
}

template < typename NODETYPE >
LinkedList< NODETYPE > *Dlist< NODETYPE >::getNewNode( const NODETYPE &value )
{
    return new LinkedList< NODETYPE >( value );
}

template< typename NODETYPE>
void Dlist< NODETYPE >::sort()
{
    NODETYPE temp;
    LinkedList< NODETYPE > *currentPtr = firstPtr;
    LinkedList< NODETYPE > *loopPtr;


    while( currentPtr != nullptr )
    {
        loopPtr = currentPtr->nextPtr;
        while(loopPtr != nullptr )
        {
            if((loopPtr->data) < (currentPtr->data))
            {
                temp = currentPtr->data;
                currentPtr->data = loopPtr->data;
                loopPtr->data= temp;
            }
            loopPtr = loopPtr->nextPtr;
        }
        currentPtr = currentPtr->nextPtr;
    }
    delete loopPtr;
    delete currentPtr;
}
/*
template< typename NODETYPE >
void Dlist< NODETYPE >::reverse()
{
    LinkedList< NODETYPE > *tempf = firstPtr;
    LinkedList< NODETYPE > *tempr = lastPtr;

    int i = 0;
    int temp;
    int x = int( list_size/2 );

    while( i < x )
    {   
        temp = tempf->data;
        tempf->data = tempr->data;
        tempr->data = temp;

        tempf = tempf->nextPtr;
        tempr = tempr->prevPtr;
        i++;
    }

    delete tempf;
    delete tempr;

    cout << "Reverse operation successful..." << endl;
}
*/
template< typename NODETYPE >
LinkedList< NODETYPE> * Dlist< NODETYPE >::begin() const
{
    return firstPtr; 
}

template< typename NODETYPE >
LinkedList< NODETYPE> * Dlist< NODETYPE >::end() const
{
    return lastPtr;
}

template< typename NODETYPE >
int  Dlist< NODETYPE >::size() const
{
    return list_size;
}

template < typename NODETYPE >
void Dlist< NODETYPE >::print() const 
{
    if( isEmpty() )
    {
        cout << "The list is empty\n\n ";
        return;
    }

    LinkedList< NODETYPE > *currentPtr = firstPtr;

    cout << "The list is : ";
    while( currentPtr != lastPtr->nextPtr )
    {
        cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    }
    cout << "\n\n";
}
#endif