/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Zybran Khan
 * Lab #11        : IntList 
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 03/03/22
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
    IntNode * temp;                 // CALC - temp node to be added 
    temp  = new IntNode(value);    
    temp->next = head;  
    head = temp;
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
    IntNode *current = head;    // CALC - pointer stores the head
    if (current == NULL);
    else
    {
        while (current != NULL)
        {
            if(current->next == NULL)
                cout << current->data;
            else
                cout << current->data << " ";

            current = current->next;
            
        }
    }
}