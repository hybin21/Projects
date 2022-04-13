/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT 07  : Recursion
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 03/23/22
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

/*****************************************************************************
* IntList(const IntList &list)
*   Constructor; Initialize class attributes
*   Parameters: 
        const IntList &list: list ot be copied
*   Return: none
*****************************************************************************/
IntList::IntList(const IntList &list)   // IN - list to be copied
{
    head = NULL;
    tail = NULL;
    if(list.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        IntNode * current = list.head;  // CALC - node to be added to the list
        while(current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
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
    IntNode * temp = new IntNode(value);    // CALC - temp pointer
    temp->next = head;
    head = temp;
    if(!tail)
        tail = temp;
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
        tail->next = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
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
    IntNode * p = current;      // CALC - points node before current node
    IntNode * n;                // CALC - points node after current node
    IntNode * temp;             // CALC - points temporary node to be deleted
    
    if(head)
    {
        while(current)
        {
            n = current->next;
            while(n)
            {
                if(n->data == current->data)
                {
                    temp = n;
                    p->next = n;
                    delete temp;
                }
                n = n->next;
            }
            p = current;
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

/*****************************************************************************
 * begin():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function returns an iterator at the begining of the linked list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   an iteartor at the beginning of the linked list is returned
 *
 *****************************************************************************/
IntListIterator IntList::begin()
{
    IntListIterator  Iterator(head);    // OUT - iterator to be returned
    return Iterator;
}

/*****************************************************************************
 * end():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function returns an iterator one element past the last element 
 *      of the linked list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   an iterator one element  past the last element of the linked list 
 *      is returned
 *
 *****************************************************************************/
IntListIterator IntList::end()
{
    IntListIterator Iterator(tail->next);   // OUT - iterator to be returned
    return Iterator;
}

/*****************************************************************************
 * front():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function returns the data in the head of the linked list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   data of the head of the linked list is returned
 *
 *****************************************************************************/
int IntList::front() const
{
    return head->data;
}

/*****************************************************************************
 * back():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function returns the data in the tail of the linked list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   data of the tail of linked list is returned
 *
 *****************************************************************************/
int IntList::back()const
{
    return tail->data;
}

/*****************************************************************************
 * length():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function recursively determines the length of the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   the length of the list is determined
 *
 *****************************************************************************/
int IntList::length() const
{
    return getLength(head);
}

/*****************************************************************************
 * sum():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function recursively determines the sum of all 
 *      of the elements in the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   the sum of all elements in the list is determined
 *
 *****************************************************************************/
int IntList::sum() const
{
    return getSum(head);
}

/*****************************************************************************
 * reverseDisplay():  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function recursively displays the contents of the list in 
 *      reverse order 
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   the contents of the list is displayed reversively
 *
 *****************************************************************************/
void IntList::reverseDisplay() const
{
    Display_Reverse(head);
}

/*****************************************************************************
 * operator=(const IntList & list):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function overload opeartor =
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const IntList & lsit: list to be copied
 *
 * POST-CONDITIONç
 *   list is copied to in-class list
 *
 *****************************************************************************/
IntList & IntList::operator=(const IntList & list)  // IN - list to be copied
{
    IntNode * current;  // CALC - current position
    IntNode * temp = list.head;     // CALC - pointer which points the list

    if(head != NULL)
    {
        current = head;
        while(current)
        {
            temp = current->next;
            delete current;
            current = temp;
        }
        head = NULL;
        tail = NULL;
    }
    if(list.head != NULL)
    {
        current = list.head;
        while(current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
    
    return *this;
}

/*****************************************************************************
 * getSum(IntNode * ptr):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function determines the sum of the conetent in the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      IntNode * ptr: position to be calculated
 *
 * POST-CONDITIONç
 *   sum of the content in the list is determined
 *
 *****************************************************************************/
int IntList::getSum(IntNode * ptr) const    // IN - position to be calculated
{   
    if(!ptr)
        return 0;
    else
        return ptr->data + getSum(ptr->next);
}

/*****************************************************************************
 * getLength(IntNode * ptr):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function determines length of the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      IntNode* ptr: position to be calcualted
 *
 * POST-CONDITIONç
 *   length of the list is determined
 *
 *****************************************************************************/
int IntList::getLength(IntNode * ptr) const // IN = position to be calculated
{
    if(!ptr)
        return 0;
    else 
        return 1 + getLength(ptr->next);
}

/*****************************************************************************
 * Display_Reverse(IntNode * ptr):  Class IntList
 *
 * ---------------------------------------------------------------------------
 * This function display the contents of the list in reverse order
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *     IntNode * ptr: position to be displayed
 *
 * POST-CONDITIONç
 *   the contents of the list is displayed reversively 
 *
 *****************************************************************************/
void IntList::Display_Reverse
                (IntNode * ptr) const  // IN - position to  be displayed
{
    if(ptr)
    {
        Display_Reverse(ptr->next);
        cout << ptr->data << " ";
    }
}