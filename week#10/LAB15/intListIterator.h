#ifndef INTLISTITERATOR_H
#define INTLISTITERATOR_H
#include "intNode.h"

/****************************************************************
 * IntListIterator Class
 *   This class contains iterators that are 
 *   utilized in IntNode.
 ***************************************************************/
class IntListIterator
{
    private:

        IntNode * current;
    public:
        /****************
        ** CONSTRUCTOR **
        ****************/
        IntListIterator();
        IntListIterator(IntNode *ptr);

        /****************
        *** ACCESSORS ***
        ****************/
        int operator*();
        IntListIterator & operator++();
        IntListIterator & operator--();
        bool operator==(const IntListIterator& right) const;
        bool operator!=(const IntListIterator& right) const;

};
#endif

/****************************************************************
 * IntListIterator Class
 *   This class contains iterators that are 
 *   utilized in IntNode.
 ***************************************************************/

/****************
** CONSTRUCTOR **
****************/

/****************************************************************
 * IntList();
 *
 *   Constructor; Initializes the class to its default 
 *                constructor parameters
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * IntList(IntNode *ptr);
 *
 *   Constructor; Initialize the constructor to its pointer
 *                parameters
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************
*** ACCESSORS ***
****************/

/****************************************************************
 * int operator* ();
 *
 *   Accessor; This function overloads the dereferencing
 *             operator (*)
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: It returns information contained within the node
 ***************************************************************/

/****************************************************************
 * IntListIterator operator++ ();
 *
 *   Accessor; This function overloads the pre-increment operator
 *             (++).
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: It returns the iterator that is pointing to
 *           next node.
 ***************************************************************/

/****************************************************************
 *   bool operator== (const IntListIterator &right) const;
 *
 *   Accessor; This function overloads the equality operator (==)
 * --------------------------------------------------------------
 *   Parameters: right: Contains the right side of the == 
                        operator
 * --------------------------------------------------------------
 *   Return: Returns a boolean value of either true or false
 ***************************************************************/

/****************************************************************
 *   bool operator!= (const IntListIterator &right) const;
 *
 *   Accessor; This function overloads the != operator    
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Returns either true or false depending on 
 *           comparison.
 ***************************************************************/


