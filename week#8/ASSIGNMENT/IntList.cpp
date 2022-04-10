/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT 06  : IntList
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 03/16/22
*******************************************************************************/

#include<iostream>
using namespace std;
#include "IntList.h"

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

/****************
** CONSTRUCTOR **
*****************/

/*****************************************************************************
* IntList()
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
IntList::IntList()
{
    IntNode node = IntNode(0);  // CALC - initialize an empty node
    head = 0;
    tail = 0;
}

/***************
** DESTRUCTOR **
****************/

/*****************************************************************************
* ~IntList()
*   Destructor; destroy class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
IntList::~IntList()
{
    IntNode *current = head;    // CALC - pointer to be used to destroy
    while (current != NULL)
    {
        IntNode *next = current->next;  // CALC - pointer points the next
        delete current;
        current = next;
    }
}

/****************
**   MUTATOR   **
*****************/


/*****************************************************************************
 * push_front(int value):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method locates a new node to the very frist order
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int value: value of the data to be stored in a new created node
 *
 * POST-CONDITIONç
 *   node will be the first node in linked list
 *
 *****************************************************************************/
void IntList::push_front(int value) // IN - value of the data to be stored
{
    IntNode * current;              // CALC - points current position
    IntNode * temp;                 // CALC - temp node to be added
    temp  = new IntNode(value);
    temp->next = head;
    head = temp;
    
    current = head;
    while(current)
        current = current->next;
    tail = current;
}

/*****************************************************************************
 * push_back(int value):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method locates a new node to the very last order
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int value: value of the data to be stored in a new created node
 *
 * POST-CONDITION
 *   the number of node will be increased by 1
 *
 *****************************************************************************/
void IntList::push_back(int value)      // IN - value of the new node
{
    IntNode * temp = new IntNode(value);    // CALC - temp node to be added
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        IntNode * current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = temp;
        tail = temp;
    }
}

/*****************************************************************************
 * pop_front():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method deletes the first node of linked list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   linked list will have one less node
 *
 *****************************************************************************/
void IntList::pop_front()
{
    if (head == 0);
    else
    {
        IntNode *temp;  // CALC - pointer to be used for the deletion
        temp = head;
        head = head->next;
        delete temp;
    }
}

/*****************************************************************************
 * select_sort():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method sort the int list with selection-sort method
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *  The following need previously defined values:
 *      the program should initialize intlist before calling this function
 *
 * POST-CONDITION
 *      the intlist will be sorted
 *
 *****************************************************************************/
void IntList::select_sort()
{
    IntNode * current = head;   // CALC - points current position
    IntNode * after;            // CALC - points the next of the current position
    IntNode * min;              // CALC - points the node with minimum value
    int val;                    // CALC - value to be swapped
    
    while(current)
    {
        min = current;
        after = current->next;
        while(after)
        {
            if(min->data > after->data)
                min = after;
            after = after->next;
        }
        val = current->data;
        current->data = min->data;
        min->data = val;
        
        current = current->next;
    }
    
}

/*****************************************************************************
 * insert_sorted(int value):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method insert the new node with value to sorted intlist
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int value: value of the new node to be inserted
 * POST-CONDITION
 *      the int list will have one additional node with value 
 *
 *****************************************************************************/
void IntList::insert_sorted(int value)  // IN - value of the new node
{
    IntNode * current = head;       // CALC - points current position
    IntNode * newNode = new IntNode(value); // CALC - new node to be added 
    
    if(!head)
        push_front(value);
    else if(head->data >= value)
        push_front(value);
    else
    {
        while(current->next)
        {
            if(current->next->data >= value)
            {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
        if(current == tail && tail->data < value)
            push_back(value);
    }
}

/*****************************************************************************
 * remove_duplicates():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method remove duplicates nodes in IntList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the program should initialize intlist before calling this function 
 * POST-CONDITION
 *      the intlist won't have any duplicates
 *
 *****************************************************************************/
void IntList::remove_duplicates()
{
    IntNode * current = head;   // CALC - points current position
    IntNode * p;                // CALC - points node before current node
    IntNode * n;                // CALC - points node after current node
    IntNode * temp;             // CALC - points temporary node to be deleted
    
    if(head)
    {
        while(current)
        {
            if(current == head)
                p = head;
            else
                p = current;
            
            n = p->next;
            while(n)
            {
                if(n->data == current->data)
                {
                    temp = n;
                    p->next = n->next;
                    delete temp;
                    n = p->next;
                }
                else
                {
                    n = n->next;
                    p = p->next;
                }
            }
            current = current->next;
        }
    }
    
  
}

/***************
** ACCESSORS **
***************/

/*****************************************************************************
 * Method display() const:  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This method displays linked list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   This function displays linked list
 *
 *****************************************************************************/

void IntList::display() const
{
    IntNode * current = head;    // CALC - pointer stores the head
    while (current)
    {
        if(current->next != NULL)
            cout << current->data << " ";
        else
            cout << current->data;
        current = current->next;
    }
}
