#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template < typename NODETYPE > class Dlist;

template < typename NODETYPE >
class LinkedList
{
    friend class Dlist< NODETYPE >;

    public:
        LinkedList( const NODETYPE &);
        NODETYPE getdata() const;
    private:
        NODETYPE data;
        LinkedList< NODETYPE > *nextPtr;
        LinkedList< NODETYPE > *prevPtr;
};


template < typename NODETYPE > 
LinkedList< NODETYPE >::LinkedList( const NODETYPE &val)
    : data( val ), nextPtr( 0 ), prevPtr( 0 )
{
    //empty
}

template < typename NODETYPE > 
NODETYPE LinkedList< NODETYPE >::getdata() const
{
    return data;
}

#endif