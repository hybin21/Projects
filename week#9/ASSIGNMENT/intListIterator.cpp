#include <iostream>
#include "IntListIterator.h"

/*******************************************************************************
 *
 * IntIterator
 *_________________________________________________________________
 * <description>
 * This program performs basic int list iterator member functions
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  returns the int list iterator
 *
*******************************************************************************/

/****************
** CONSTRUCTOR **
*****************/

/*****************************************************************************
* IntListIterator()
*   Constructor; initialzie an intlist iterator
*   Parameters: none
*   Return: none
*****************************************************************************/
IntListIterator::IntListIterator()
{
    current = NULL;
}

/*****************************************************************************
* IntListIterator(IntNode *ptr)
*   Constructor; initializes an int list iterator with iterator with ptr
*   Parameters: 
*       IntNode * ptr: pointer of the iterator
*   Return: none
*****************************************************************************/
IntListIterator::IntListIterator(IntNode *ptr) // IN - pointer of the iterator
{
    current = ptr;
}

/****************
**   MUTATOR   **
*****************/

/*****************************************************************************
 * int operator*():  Class IntListIterator
 *
 * ---------------------------------------------------------------------------
 * This function overloads operator *
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      none
 *
 * POST-CONDITIONç
 *   operator * is overaloded
 *
 *****************************************************************************/
int IntListIterator::operator*()
{
    return current->data;
}

/*****************************************************************************
 * IntListIterator operator++:  Class IntListIterator
 *
 * ---------------------------------------------------------------------------
 * This function overloads operator ++
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      none
 *
 * POST-CONDITIONç
 *   operator ++ is overloaded
 *
 *****************************************************************************/
IntListIterator IntListIterator::operator++()
{
    if(current)
        current = current->next;
    return *this;
    
}

/***************
** ACCESSORS **
***************/

/*****************************************************************************
 * bool operator==(const IntListIterator& right) const:  Class IntListIterator
 *
 * ---------------------------------------------------------------------------
 * This function overloads operator ==
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const IntListIterator& right: iterator to be computed
 *
 * POST-CONDITIONç
 *   operator == is overloaded
 *
 *****************************************************************************/
bool IntListIterator::operator==
    (const IntListIterator& right) const       // IN - iterator to be computed
{
    return (current == right.current);
}

/*****************************************************************************
 * bool operator!=(const IntListIterator& right) const:  Class IntListIterator
 *
 * ---------------------------------------------------------------------------
 * This function overloads operator != 
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const IntListIterator& right: iterator to be computed
 *
 * POST-CONDITIONç
 *   operator != is overloaded
 *
 *****************************************************************************/
bool IntListIterator::operator!=(
        const IntListIterator& right) const    // IN - iterator to be computed
{
    return (current != right.current);
}