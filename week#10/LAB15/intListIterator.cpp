/******************************************************************************
 * AUTHOR       : Jesse Tzo & Jessica Hahm
 * LAB #15      : Doubly Linked List
 * CLASS        : 32276 CS3A
 * SECTION      : 10
 * DUE DATE     : 03/23/2022
 ******************************************************************************/
#include<iostream>
#include "intListIterator.h"

using namespace std;

/**********************************************************
 *
 * Constructor IntListIterator: Class IntListIterator
 *_________________________________________________________
 * Description
 *  The default constructor for the IntListIterator
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   returns none
 ***********************************************************/
IntListIterator::IntListIterator()
{
    current = NULL;
}

/**********************************************************
 *
 * Constructor IntListIterator: Class IntListIterator
 *_________________________________________________________
 * Description
 *  Constructor that takes a pointer as a parameter, and
 *  sets the private member variable current to the pointer
 *_________________________________________________________
 * PRE-CONDITIONS
 *   IntNode *ptr : The node for the constructor to set
 *                  current to.
 *
 * POST-CONDITIONS
 *   returns none
 ***********************************************************/
IntListIterator::IntListIterator
                (IntNode *ptr)          //CALC - Pointer to 
                                        //be set to
{
    current = ptr;
}

/************************************************************
 *
 * Method operator* : Class IntListIterator
 *____________________________________________________________
 * Mutator: This function overloads the dereferencing operator
 *          (*) and returns the data in the node * is used on.
 *____________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   returns the data in node * is used on.
 *
 ************************************************************/
int IntListIterator::operator*()
{
    return current->data;
}

/************************************************************
 *
 * Method operator++ : Class IntListIterator
 *____________________________________________________________
 * Mutator: This function overloads the pre-increment operator
 *          (++). It returns the iterator that points to the 
 *          following node.
 *____________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   returns iterator pointing to the following node.
 *
 ************************************************************/
IntListIterator & IntListIterator::operator++()
{   
    if(current)
        current = current->next;
    return *this;
}

/************************************************************
 *
 * Method operator++ : Class IntListIterator
 *____________________________________________________________
 * Mutator: This function overloads the pre-decrement operator
 *          (--). It returns the iterator that points to the 
 *          following node.
 *____________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   returns iterator pointing to the previous node.
 *
 ************************************************************/
IntListIterator & IntListIterator::operator--()
{
    if(current)
    {
      current = current->prev;      
    }
    return *this;
}

/************************************************************
 *
 * Method operator == : Class IntListIterator
 *____________________________________________________________
 * Mutator: This function overloads the equality operator (==)
 *          and returns either true or false depending on if
 *          the nodes are equal or not.
 *____________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return a boolean result of either true or false
 *
 ************************************************************/
bool IntListIterator::operator==
(const IntListIterator &right) const    //CALC - Object to be 
                                        //checked
{
    if(current->data == right.current->data)
    {
      if(current->next == right.current->next)
      {
        return true;
      }
    return false;
    }
}

/************************************************************
 *
 * Method operator != : Class IntListIterator
 *____________________________________________________________
 * Mutator: This function overloads the inequality operator
 *          (!=) and returns true or false depending on if
 *           the node is the same as the one being compared.
 *____________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   returns boolean result of either true or false depending
 *   on the nodes. 
 *
 ************************************************************/
bool IntListIterator::operator!=
(const IntListIterator &right) const    //CALC - Object to be 
                                        //checked
{
  return ((right.current != NULL) && (current != NULL));
}