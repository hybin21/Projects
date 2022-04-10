/******************************************************************************
 * AUTHOR       : Jesse Tzo & Jessica Hahm
 * LAB #15      : Doubly Linked List
 * CLASS        : 32276 CS3A
 * SECTION      : 10
 * DUE DATE     : 03/23/2022
 ******************************************************************************/
#include<iostream>
#include "doublyLinkedList.h"
#include "intListIterator.h"
using namespace std;

/**********************************************************
 *
 * Constructor DoublyLinkedList: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  Default constructor, head and tail to NULL 
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *     returns none
 ***********************************************************/
DoublyLinkedList::DoublyLinkedList()
{   
    IntNode node = IntNode(0);  // CALC - create node
    head = NULL;
    tail = NULL;
}

/**********************************************************
 *
 * Constructor DoublyLinkedList: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  Constructor that sets the list to the provided list
 *  provided by the parameter
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *     returns none
 ***********************************************************/
DoublyLinkedList::DoublyLinkedList
(const DoublyLinkedList & D)            //IN - Node to copy
{
    head = NULL;
    tail = NULL;

    //Special case empty linked list
    if(D.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        IntNode *current;               //CALC - node to be
                                        //added to the list
        current = D.head;  
        while(current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
}   

/**********************************************************
 *
 * Destructor ~DoublyLinkedList: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function is a destructor that destroys the object
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
DoublyLinkedList::~DoublyLinkedList()
{
    IntNode *current = head;            //CALC - pointer to 
                                        //be used to destroy
    while (current)
    {
        IntNode *next;                  //CALC - pointer 
                                        //points the next
        next = current->next;  
        delete current;
        current = next;
    }
}

/**********************************************************
 *
 * Mutator operator = : Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function overloads the = operator to copy all 
 *    nodes of an existing list to another list
 *_________________________________________________________
 * PRE-CONDITIONS
 *  const DoublyLinkedList &D : The node to be copied from.
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
DoublyLinkedList& DoublyLinkedList::operator=
(const DoublyLinkedList &D)                 //CALC - Node
                                            //to be set to
{
    IntNode * current;                      //CALC - current
                                            //position
    IntNode * temp;                         // CALC - pointer 
                                            //which points the list
    temp = D.head;                          

    //Checks for empty list
    if(head)
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
    //Checks for empty list
    if(D.head)
    {
        current = D.head;
        while(current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    //If empty list
    else
    {
        head = NULL;
        tail = NULL;
    }
    return *this;
}

/**********************************************************
 *
 * Mutator push_front: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function adds a node with the specified value
 *  to the front of the linked list
 *_________________________________________________________
 * PRE-CONDITIONS
 *   int value : Value to be added to the front of the list
 *
 * POST-CONDITIONS
 *   none
 ***********************************************************/
void DoublyLinkedList::push_front
(int value)                                //IN&CALC - Value 
                                           //to be added
{
    IntNode * temp;                        //CALC - temp 
                                           //pointer
    temp = new IntNode(value);    

    //If list is empty
    if(!head)
    {
        head = temp;
        tail = temp;
        temp->prev = NULL;
    }
    //Other cases
    else
    {
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
}

/**********************************************************
*
* Mutator pop_front: Class DoublyLinkedList
*_________________________________________________________
* Description
*  This function deletes the value at the front of the
*  list
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   return none
***********************************************************/
void DoublyLinkedList::pop_front()
{
    IntNode * temp;            //CALC - pointer to be used
    temp = head;  

    //Empty list special case
    if(head == NULL)
    {
      return;
    }
    //Other cases
    else
    {  
        //One node special case
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
}

/**********************************************************
 *
 * Mutator push_back: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function adds a new node at the end of the linked
 *  list
 *_________________________________________________________
 * PRE-CONDITIONS
 *   int value : Value to be inserted at the end of the 
 *               list
 *
 * POST-CONDITIONS
 *   none
 ***********************************************************/
void DoublyLinkedList::push_back
(int value)                                //IN&CALC - Value 
                                           //to be added
{
    IntNode * temp;                        //CALC - temp node 
                                           //to be added
    temp = new IntNode(value);    

    //Special case empty list
    if(head == NULL)
    {
        head = temp;
        tail = head;
    }
    //Other cases
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        temp->next = NULL;
    }
    
}

/**********************************************************
*
* Mutator pop_back: Class DoublyLinkedList
*_________________________________________________________
* Description
*  This function deletes the value at the back of the
*  list
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   return none
***********************************************************/
void DoublyLinkedList::pop_back()
{
    IntNode * temp;                //CALC - Temp pointer
    temp = tail;

    //If empty list
    if(!head)
    {
      return;
    }
    else
    {
      //Special case 1 node
      if(head == tail)
      {
          head = NULL;
          tail = NULL;
      }
      //Other cases
      else
      {
          tail = tail->prev;
          tail->next = NULL;
      }
      delete temp;
    }
}

/**********************************************************
 *
 * Mutator select_sort: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function sorts the list into ascending order
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
void DoublyLinkedList::select_sort()
{
    IntNode * current = head;   //CALC - points current 
                                //position
    IntNode * after;            //CALC - points the next 
                                //of the current position
    IntNode * min;              //CALC - points the node with 
                                //minimum value
    int val;                    //CALC - value to be swapped

    //Selection sort
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

/**********************************************************
 *
 * Mutator insert_sorted: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function assumes the values in the list are 
 *  in ascending order and inserts the new data into the
 *  correct position in the list.

 *_________________________________________________________
 * PRE-CONDITIONS
 *   int value : Value to be added onto the list
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
void DoublyLinkedList::insert_sorted
(int value)                              //IN&CALC - Value 
                                         //to be added
{
  IntNode * current;                     //CALC - current 
                                         //node
  IntNode * newNode;                     //CALC - new node
  current = head;
  newNode = new IntNode(value);

  //If no data or value of first node is bigger than value
  if(!head || head->data >= value)
  {
    push_front(value);
  }
  else
  {
    while(current->next)
    {
      //If data after current is bigger than value
      if(current->next->data > value)
      {
          newNode->next = current->next;
          newNode->prev = current;
          current->next = newNode;
          break;
      }
      current = current->next;
    }

    //Other cases
    if(current == tail && tail->data < value)
    {
      push_back(value);
    }
  }
}

/**********************************************************
 *
 * Mutator remove: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function removes the node given by the parameter
 *_________________________________________________________
 * PRE-CONDITIONS
 *   int value: The node to be removed
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
bool DoublyLinkedList::remove(int value)   //IN&CALC - Value 
                                           //to be added
{
  IntNode * current;
  IntNode * temp;
  current = head;
  while(current)
  {
    //Checks for value
    if(current->data == value)
    {
      //If its in the front of the linked list
      if(current == head)
      {
        pop_front();
      }
      //If its in the end of the linked list
      else if(current == tail)
      {
        pop_back();
      }
      //All other cases
      else
      {
        temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete temp;
      }
      return true;
    }
  current = current->next;
  }
  return false;
}

/**********************************************************
 *
 * Accessor begin: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function returns the iterator at the 
 *             beginning of the linked list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return an iterator pointing to the head.
 ***********************************************************/
IntListIterator DoublyLinkedList::begin()
{
    IntListIterator Iterator(head);    //OUT - iterator to 
                                       //be returned
    return Iterator;
}

/**********************************************************
 *
 * Accessor end: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function returns the iterator at the 
 *             end of the linked list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return an iterator pointing to the tail.
 ***********************************************************/
IntListIterator DoublyLinkedList::end()
{
    IntListIterator Iterator(tail);    //OUT - iterator to 
                                       //be returned
    return Iterator;
}

/**********************************************************
 *
 * Accessor display: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function displays all nodes in the linked list
 *_________________________________________________________
 * PRE-CONDITIONS
 *   bool foward: determines the way the list is displayed
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
void DoublyLinkedList::display
(bool forward)                      //CALC - Determines how
                                    //linked list is 
                                    //displayed
const
{
  if(forward)
  {
    IntNode * current;             //CALC -pointer stores 
                                   //the head
    current = head;   
    
    //Displays node
    while (current)
    {
      if(current->next != NULL)
      {
        cout << current->data << " ";
      }
      else
      {
        cout << current->data;
      }
      current = current->next;
    }
  }
  else
  {
    Display_Reverse(head);
  }
}

/**********************************************************
 *
 * Accessor Display_Reverse: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function displays all nodes in the linked list
 *  in reverse
 *_________________________________________________________
 * PRE-CONDITIONS
 *   IntNode *ptr: determines the node to be displayed
 *
 * POST-CONDITIONS
 *   return none
 ***********************************************************/
void DoublyLinkedList::Display_Reverse
(IntNode * ptr) const                     //IN - Determines 
                                          //list to display
{
  if(ptr)
  {
      Display_Reverse(ptr->next);
      cout << ptr->data << " ";
  }
}

/**********************************************************
 *
 * Accessor front: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function returns the node at the 
 *             beginning of the linked list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return the node at the beginning of the linked list
 ***********************************************************/
int DoublyLinkedList::front() const
{
    if(head)
        return head->data;
    else
        return 0;
}

/**********************************************************
 *
 * Accessor back: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function returns the node at the 
 *             end of the linked list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   return the node at the end of the linked list
 ***********************************************************/
int DoublyLinkedList::back() const
{   
    if(tail)
        return tail->data;
    else
        return 0;
}

/**********************************************************
 *
 * Accessor length: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function uses recursion to determine the
 *             length of the linked list 
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   Returns the length of the recursion
 ***********************************************************/
int DoublyLinkedList::length() const
{
    return getLength(head);
}

/**********************************************************
 *
 * Accessor getLength: Class DoublyLinkedList
 *_________________________________________________________
 * Description
 *  This function finds the total amount of nodes 
 *             through the use of recursion
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   Returns the length of the list
 ***********************************************************/
int DoublyLinkedList::getLength
(IntNode * ptr) const                 //IN - Determines the 
                                      //list to display
{
  //Base case
  if(!ptr)
      return 0;
  //Recursion
  else 
  {
    return 1 + getLength(ptr->next);
  }
}