#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include "IntNode.h"
#include "IntListIterator.h"

using namespace std;


/*******************************************************************************
 *
 * IntList
 *_________________________________________________________________
 * <description>
 * This program performs basic int linked list member functions
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays the computed int linked  list
 *
*******************************************************************************/

class IntList
{
public:
    /****************
    ** CONSTRUCTOR **
    ****************/
    IntList();
    IntList(const IntList &list);   // IN - list to be copied

    /***************
    ** DESTRUCTOR **
    ****************/
    ~IntList();

    /***************
    **  ACCESSOR  **
    ****************/
    void display() const;
    int front() const;
    int back() const;
    int length() const;
    int sum() const;
    void reverseDisplay() const;
    IntListIterator begin();
    IntListIterator end();

    /****************
    *** MUTATORS ***
    ****************/
    void push_front(int value); // IN - value of the new node
    void push_back(int value);  // IN - value of the new node
    void pop_front();
    void select_sort();         
    void insert_sorted(int value);  // IN - value of the new node 
    void remove_duplicates();  
    IntList & operator=(const IntList & list);  // IN - list to be copied


private:
    IntNode *head;  // CALC - head of the IntList
    IntNode *tail;  // CALC - tail of the IntList

    /***************
    **  ACCESSOR  **
    ****************/
    int getLength(IntNode * ptr) const; // IN - position to be calculated
    int getSum(IntNode * ptr) const;    // IN - position to be calculated
    void Display_Reverse
                (IntNode * ptr) const;  // IN - position to be calculated
};
#endif


/******************************************************************************
 * IntList Class
 *  <description>: This Class is a smaller, simpler version of the STL 
 *          vector class that is capable of only storing integers
 *
 *****************************************************************************/

/****************
** CONSTRUCTOR **
****************/

/******************************************************************************
 * IntList();
 *  Constructor: initializes an empty list
 *-----------------------------------------------------------------------------
 *  Parameters: none
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/******************************************************************************
 * IntList(const IntList &list);
 *  Constructor: initializes an empty list
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      const IntList &list: list to be copied
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/*****************
 **  DESTRUCTOR **
 ****************/

/******************************************************************************
 * ~IntList()
 *  Destructor: dealocates the remaining dynamically allocated memory
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/****************
 *** ACCESSORS ***
 ****************/

/******************************************************************************
 * void display() const
 *  Accessor: displays to a single line all the int values stored in the list,
 *           each separated by a space
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * IntListIterator begin()
 *  Accessor: This function returns an iterator at the beginning 
 *              of the linked list
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * IntListIterator end()
 *  Accessor: This function returs an iterator one element past the last 
 *              element of thel inked list
 *-----------------------------------------------------------------------------
 *  Parameter: none 
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * int front() const
 *  Accessor: This function returns the data in the head of the linked list
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * int back() const
 *  Accessor: This function returns the data in the tail of the linked list
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * int length() const
 *  Accessor: This function recursively determines the length of the list
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * int sum() const
 *  Accessor: This function recursively determines the sum of all elements 
 *              in the list
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void reverseDisplay() const
 *  Accessor: This function recursively displays the contents of the list
 *              in reverse order
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * int getLength(IntNode * ptr) const
 *  Accessor: This function determines the length of the list
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      IntNode * ptr: position to be calculated
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * int getSum(IntNode * ptr) const
 *  Accessor: This function determines the sum of all elements in the list
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      IntNode * ptr: position to be calculauted
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void Display_Reverse(IntNode * ptr) const  
 *  Accessor: This function displays the contents of the list in reverse order
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      IntNode * ptr: position to be calculated
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/



/****************
 *** MUTATORS ***
 ****************/

/******************************************************************************
 * void push_front(int value)
 *  Mutator: Inserts a data value at the front of the list
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      int value: value of the new node
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void push_back(int value)
 *  Mutator: Inserts a data value at the end of the list
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      int value: value of the new node
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 *  void pop_front()
 *  Mutator: remove the front node of the list
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void select_sort()
 *  Mutator: sorts the IntList by using selection-sort method
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void insert_sorted(int value)
 *  Mutator: Inserts a data into appropriate positionin the list
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      int value: value of the new node
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void remove_duplicates()
 *  Mutator: removes duplicates
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/



/******************************************************************************
 * IntList & operator=(const IntList & list)
 *  Mutator: 
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      const IntList & list: list to be copied
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/



 