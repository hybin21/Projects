#ifndef INTLISTITERATOR_H
#define INTLISTITERATOR_H
/*******************************************************************************
 *
 * IntNode
 *_________________________________________________________________
 * <description>
 * This program performs basic IntIterator member function
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  return the iterator to be used when it's needed
 *
*******************************************************************************/
#include "IntNode.h"

class IntListIterator
{
    private: 
        IntNode * current;  // IN - current position of the linked list
    public:

    /****************
    ** CONSTRUCTOR **
    ****************/  
        IntListIterator();
        IntListIterator(IntNode *ptr);  // IN - pointer of the iterator

    /****************
     *** MUTATORS ***
    ****************/
        int operator*();
        IntListIterator operator++();

    /***************
    **  ACCESSOR  **
    ****************/    
        bool operator==
        (const IntListIterator& right) const; // IN - iterator to be computed
        bool operator!=(
        const IntListIterator& right) const;  // IN - iterator to be computed
};
#endif

/******************************************************************************
 * IntIterator Class
 *  <description>: This Class allows IntList to access ot individual elements
 *
 *****************************************************************************/

/****************
** CONSTRUCTOR **
****************/

/******************************************************************************
 * IntListIterator();
 *  Constructor: initialzie an intlist iterator
 *-----------------------------------------------------------------------------
 *  Parameters: none
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/******************************************************************************
 * IntListIterator(IntNode *ptr);
 *  Constructor: initializes an int list iterator with iterator with ptr
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      IntNoe * ptr: pointer of the iterator
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/****************
 *** ACCESSORS ***
 ****************/

/******************************************************************************
 * bool operator==(const IntListIterator& right) const;
 *  Accessor: overload operator ==
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      const IntListIterator& right: iteartor to be computed
 *-----------------------------------------------------------------------------
 *  Return: return true if right and this are equal, false if they are not
 *****************************************************************************/

/******************************************************************************
 * bool operator!=(const IntListIterator& right) const;
 *  Accessor: overload operator !=
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      const IntListIterator& right: iterator to be computed
 *-----------------------------------------------------------------------------
 *  Return: return true if right and this are not equal, false if they are 
 *****************************************************************************/

/****************
 *** MUTATORS ***
 ****************/

/******************************************************************************
 * int operator*()
 *  Mutator: overloads operator *
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * IntListIterator operator++()
 *  Mutator: overloads operator ++
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/