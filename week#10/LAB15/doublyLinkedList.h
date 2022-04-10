/******************************************************************************
 * AUTHOR       : Jesse Tzo & Jessica Hahm
 * LAB #15      : Doubly Linked List
 * CLASS        : 32276 CS3A
 * SECTION      : 10
 * DUE DATE     : 03/23/2022
 ******************************************************************************/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "intNode.h"
#include "intListIterator.h"
#include<iostream>


/****************************************************************
 * DoublyLinkedList Class
 *   This class represents a linked list of nodes.
 ***************************************************************/
class DoublyLinkedList
{
    private:
        IntNode *head;                        //CALC - Head 
                                              //pointer node
        IntNode *tail;                        //CALC - Tail 
                                              //pointer node
    public: 
        /******************************
        ** CONSTRUCTORS & DESTRUCTOR **
        ******************************/
        DoublyLinkedList();
        DoublyLinkedList
        (const DoublyLinkedList & D);         //IN - Node for 
                                              //constructor to 
                                              //be set to
        ~DoublyLinkedList();
        /***************
        ** ACCESSORS **
        ***************/
        void display
        (bool forward = true) const;          //CALC - Determines
                                              //how to display
                                              //linked list     
        IntListIterator begin();
        IntListIterator end();
        int front() const;
        int back() const;
        int length() const;

        /****************
        ***  MUTATORS ***
        ****************/
        void push_front(int value);           //CALC - Value to
                                              //be added     
        void push_back(int value);            //CALC - Value to
                                              //be added  
        void pop_front();
        void pop_back();
        void select_sort( );
        void insert_sorted(int value);        //CALC - Value to
                                              //be added  
        bool remove(int value);               //CALC - Value to
                                              //be removed  
        DoublyLinkedList & operator=
        (const DoublyLinkedList &D);          //CALC - Linked 
                                              //list to be 
                                              //set to

    private:
        /***************
        ** ACCESSORS **
        ***************/
        void Display_Reverse
                (IntNode * ptr) const;        //CALC - pointer
                                              //to be displayed           
        int getLength(IntNode * ptr) const;   //CALC - pointer
                                              //to get length of
};
#endif


/****************************************************************
 * DoublyLinkedList Class
 *   This class respresents a list of integer nodes. 
 ***************************************************************/

/******************************
** CONSTRUCTOR & DESTRUCTOR **
******************************/

/****************************************************************
 * DoublyLinkedList();
 *   Default Constructor; Initializes default constructor 
 *                        attributes.
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * DoublyLinkedList(const DoublyLinkedList& D);
 *   Constructor; Initialize constructor attributes
 *   Parameters: Contains new node that is going to be assigned
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~DoublyLinkedList();
 *   Destructor; Destroys the constructor by deallocating the
 *               class attributes
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
 * void display (bool forward = true) const;
 *
 *   Accessor; This method will display the contents of each node
 * --------------------------------------------------------------
 *   Parameters: 
 *    bool forward: decide to display forward or not
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * IntListIterator begin () const;
 *
 *   Accessor; This function returns the iterator at the 
 *             beginning of the linked list.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Returns the iterator pointing to NULL
 ***************************************************************/

/****************************************************************
 * IntlistIterator end () const;
 *
 *   Accessor; This function returns the iterator at the 
 *             end of the linked list.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Returns the iterator pointing to NULL
 ***************************************************************/

/****************************************************************
 * int front () const;
 *
 *   Accessor; This function returns the first node
 *     of the linked list.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Returns the first node of the linked list 
 ***************************************************************/

/****************************************************************
 * int back () const;
 *
 *   Accessor; This function returns the last node
 *     of the linked list.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Returns the last node of the linked list 
 ***************************************************************/

/****************************************************************
 * int length () const;
 *
 *   Accessor; This function uses recursion to determine the
 *             length of the linked list 
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: The length of the recursion
 ***************************************************************/

/****************************************************************
 * void Display_Reverse (IntNode *ptr) const;
 *
 *   Accessor; This function uses recursion to display the
 *    contents of the list in reverse
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Void function, returns nothing
 ***************************************************************/

/****************************************************************
 * int getLength(IntNode* ptr) const;
 *
 *   Accessor; This function finds the total amount of nodes 
 *             through the use of recursion
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: Returns the length of the list
 ***************************************************************/

/***************
*** MUTATORS ***
***************/

/****************************************************************
 * void push_front (int value);
 *
 *   Mutator; This method adds a new node to the front of
 *            the linked list
 * --------------------------------------------------------------
 *   Parameters: 
 *      int value: The value to be added to the front of the list
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void push_back (int value);
 *
 *   Mutator; This method adds a value to the back of the linked
 *     list
 * --------------------------------------------------------------
 *   Parameters: 
 *       int value:
 *          the data to be added to the node
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void pop_back ();
 *
 *   Mutator; Deletes the value at the end of the list
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void pop_front ();
 *
 *   Mutator; Deletes the value at the front of the list
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void select_sort ();
 *
 *   Mutator; This function sorts the list into ascending order
 *   utilizing the selection sort algorithm.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void insert_sorted (int value);
 *
 *   Mutator; This function assumes the values in the list are 
 *   in ascending order and inserts the new data into the
 *   correct position in the list.
 * --------------------------------------------------------------
 *   Parameters: 
 *        int value: data to be added onto the list
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 *   bool remove(int value);
 *
 *    Mutator; This function removes the node determined 
 *            by the paramter "value"
 * --------------------------------------------------------------
 *   Parameters: 
 *    int value: value to be removed
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/


/****************************************************************
 * DoublyLinkedList& operator=(const DoublyLinkedList& D);
 *
 *   Mutator; This function overloads the = operator to copy all 
 *    nodes of an existing list to another list
 * --------------------------------------------------------------
 *   Parameters: 
 *        DoublyLinkedList& D: The node to be copied from.
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/