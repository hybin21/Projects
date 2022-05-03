#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include "listEmpty.h"

using namespace std;

/*******************************************************************************
 *
 * LinkedList
 *_________________________________________________________________
 * <description>
 * This program performs basic templated linked list member functions
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays the computed template type linked  list
 *
*******************************************************************************/

/*******************************************************************************
 *
 * Iterator
 *_________________________________________________________________
 * <description>
 * This program performs basic template type linked list iterator 
 *  member functions
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  returns the template type linkedlist iterator
 *
*******************************************************************************/

template<typename T>
struct Node
{
    T data;   // IN - data of the node
    Node *next;  // IN - pointer to point the next node

    /****************
    ** CONSTRUCTOR **
    ****************/
    Node(T data) : data(data), next(0) {}  // data of the node 
};
/****************
** CONSTRUCTOR **
 ****************/   
/******************************************************************************
 * Node(T data)
 *  Constructor: initializes an empty list
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      T data: data of the node
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

template <typename T>
class LinkedList
{
    public:
    class Iterator
    {
        private: 
            Node<T> * current;  // IN - current position of the linked list
        public:

        /****************
        ** CONSTRUCTOR **
        ****************/  
            Iterator();
            Iterator(Node<T> *ptr);  // IN - pointer of the iterator

        /****************
         *** MUTATORS ***
        ****************/
            T operator*(); 
            Iterator operator++();

        /***************
        **  ACCESSOR  **
        ****************/    
            bool operator==
            (const Iterator& right) const; // IN - iterator to be computed
            bool operator!=(
            const Iterator& right) const;  // IN - iterator to be computed
    };

public:
    /****************
    ** CONSTRUCTOR **
    ****************/
    LinkedList();
    LinkedList(const LinkedList &list);   // IN - list to be copied

    /***************
    ** DESTRUCTOR **
    ****************/
    ~LinkedList();

    LinkedList & operator =(const LinkedList & source);
    /***************
    **  ACCESSOR  **
    ****************/
    const T & front() const throw(ListEmpty);
    const T & back() const throw(ListEmpty);
    Iterator begin();
    Iterator end();
    int length() const;
    T sum() const;
    void display() const;
    bool isEmpty() const;
    /****************
    *** MUTATORS ***
    ****************/
    void push_front(const T & value);
    void push_back(const T & value);
    void pop_front() throw(ListEmpty);
    void clear();
    void select_sort();
    void insert_sorted(const T & value);
    void remove_duplicates();


private:
    Node<T> *head;  // CALC - head of the IntList
    Node<T> *tail;  // CALC - tail of the IntList

    /***************
    **  ACCESSOR  **
    ****************/
    int getLength(Node<T> * ptr) const; // IN - position to be calculated
    T getSum(Node<T> * ptr) const;    // IN - position to be calculated
    void Display_Reverse
                (Node<T> * ptr) const;  // IN - position to be calculated
};

/****************
** CONSTRUCTOR **
*****************/

/*****************************************************************************
* Iterator()
*   Constructor; initialzie an linkedlist iterator
*   Parameters: none
*   Return: none
*****************************************************************************/
template<typename T>
LinkedList<T>::Iterator::Iterator()
{
    current = NULL;
}

/*****************************************************************************
* ListIterator(Node<T> *ptr)
*   Constructor; initializes an template type linkedlist iterator with 
        iterator with ptr
*   Parameters: 
*       Node<t> * ptr: pointer of the iterator
*   Return: none
*****************************************************************************/
template<typename T>
LinkedList<T>::Iterator::Iterator(Node<T> * ptr)//IN - pointer of the iterator
{
    current = ptr;
}

/****************
**   MUTATOR   **
*****************/

/*****************************************************************************
 * T operator*():  Class Iterator
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
template<typename T>
T LinkedList<T>::Iterator::operator*()
{
    return current->data;
}   

/*****************************************************************************
 * Iterator operator++:  Class Iterator
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
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++()
{
    if(current)
        current = current->next;
    return *this;
}

/***************
** ACCESSORS **
***************/

/*****************************************************************************
 * bool operator==(const Iterator& right) const:  Class Iterator
 *
 * ---------------------------------------------------------------------------
 * This function overloads operator ==
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const Iterator& right: iterator to be computed
 *
 * POST-CONDITIONç
 *   operator == is overloaded
 *
 *****************************************************************************/
template<typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& right) const
{
    return(current == right.current);
}

/*****************************************************************************
 * bool operator!=(const Iterator& right) const:  Class Iterator
 *
 * ---------------------------------------------------------------------------
 * This function overloads operator != 
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const Iterator& right: iterator to be computed
 *
 * POST-CONDITIONç
 *   operator != is overloaded
 *
 *****************************************************************************/
template<typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& right) const
{
    return (current != right.current);
}

/****************
** CONSTRUCTOR **
*****************/

/*****************************************************************************
* LinkedList()
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
template<typename T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

/*****************************************************************************
* LinkedList(const LinkedList<T> &list)
*   Constructor; Initialize class attributes
*   Parameters: 
        const LinkedLis<T> &list: list ot be copied
*   Return: none
*****************************************************************************/
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & list)// IN - list to be copied
{
    
    if(!list.head)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = NULL;
        tail = NULL;
        Node<T> * current = list.head;
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
* ~LinkedList()
*   Destructor; destroy class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> * current = head;// CALC - pointer to be to destry class atributes
    while(current)
    {   
        current = head->next; // CALC - points the next node
        delete current;
        head = current;
    }
    head = NULL;
    tail = NULL;
        cout << "destructor begin\n";
}


/***************
** ACCESSORS **
***************/

/*****************************************************************************
 * front():  Class LinkedList
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
template<typename T>
const T& LinkedList<T>::front() const throw(ListEmpty)
{
    if(head == NULL)
        throw(ListEmpty());
    else
        return head->data;
        
}

/*****************************************************************************
 * back():  Class LinkedList
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
template<typename T>
const T & LinkedList<T>::back() const throw(ListEmpty)
{   
    if(head == NULL)
        throw(ListEmpty());
    else
        return tail->data;
        
}

/*****************************************************************************
 * begin():  Class LinkedList
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
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    LinkedList<T>::Iterator  currentIterator(head);
    return currentIterator;
}

/*****************************************************************************
 * end():  Class LinkedList
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
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    LinkedList<T>::Iterator  currentIterator(tail->next);
    return currentIterator;
}

/*****************************************************************************
 * getLength(Node<T>* ptr):  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This function determines length of the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      Node<T>* ptr: position to be calcualted
 *
 * POST-CONDITIONç
 *   length of the list is determined
 *
 *****************************************************************************/
template<typename T>
int LinkedList<T>::getLength(
            Node<T>* ptr) const// IN - position to be calculated
{
    if(!ptr)
        return 0;
    else
        return 1 + getLength(ptr->next);
}

/*****************************************************************************
 * length():  Class LinkedList
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
template<typename T>
int LinkedList<T>::length() const
{
    return getLength(head);
}

/*****************************************************************************
 * getSum(Node<T>* ptr):  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This function determines the sum of the conetent in the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      Node<T>* ptr: position to be calculated
 *
 * POST-CONDITIONç
 *   sum of the content in the list is determined
 *
 *****************************************************************************/
template<typename T>
T LinkedList<T>::getSum(Node<T>* ptr) const // IN - position to be calculated
{   if(!ptr)
        return 0;
    else
        return ptr->data + getSum(ptr->next);

}

/*****************************************************************************
 * sum():  Class LinkedList
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
template<typename T>
T LinkedList<T>::sum() const
{
    return getSum(head);
}


/*****************************************************************************
 * display() const:  Class LinkedList
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
template<typename T>
void LinkedList<T>::display() const
{
    Node<T> * current = head;
    while(current)
    {
        if(current->next != NULL)
            cout << current->data << " ";
        else
            cout << current->data;
        current = current->next;
    }
}

/*****************************************************************************
 * isEmpty() const:  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method checks if the linked list empty
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   This function retures true if the linke is empty, and false if it's not
 *
 *****************************************************************************/
template<typename T>
bool LinkedList<T>::isEmpty() const
{
    if(head == NULL && tail == NULL)
        return true;
    return false;
}

/****************
**   MUTATOR   **
*****************/


/*****************************************************************************
 * operator=(const LinkedList<T> & list):  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This function overload opeartor =
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      onst LinkedList<T> & source: list to be copied
 *
 * POST-CONDITIONç
 *   list is copied to in-class list
 *
 *****************************************************************************/
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(
            const LinkedList<T> & source)   // IN - list to be copied
{
    Node<T> * current;  // CALC - current position
    Node<T> * temp = source.head;   // CALC - points the source

    if(!head)
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
    if(!source.head)
    {
        current = source.head;
        while(current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    else
    {
        head = NULL;
        tail =  NULL;
    }

    return * this;
}


/*****************************************************************************
 * push_front(const T & value):  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method locates a new node to the very frist order
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const T & value: value of the data to be stored in a new created node
 *
 * POST-CONDITIONç
 *   node will be the first node in linked list
 *
 *****************************************************************************/
template<typename T>
void LinkedList<T>::push_front(const T & value) // IN - data of the node
{
    Node<T> * temp = new Node<T>(value);    // CALC - new node to be added
    if(!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

/*****************************************************************************
 * push_back(const T & value):  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method locates a new node to the very last order
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      cosnt T & value: value of the data to be stored in a new created node
 *
 * POST-CONDITION
 *   the new node will be added to the linked list
 *
 *****************************************************************************/
template<typename T>
void LinkedList<T>::push_back(const T & value)  // IN - value of the new node
{
    Node<T> * temp = new Node<T>(value);    // CALC - new node

    if(!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
}

/*****************************************************************************
 * pop_front():  Class LinkedList
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
template<typename T>
void LinkedList<T>::pop_front() throw(ListEmpty)
{
    if(head == NULL)
        throw(ListEmpty());
    else
    {
        if(head)
        {
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
    }
}

/*****************************************************************************
 * clear():  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method clears the linkedlist
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   linked list will be cleared
 *
 *****************************************************************************/
template<typename T>
void LinkedList<T>::clear()
{
    Node<T> * current = head;
    while(!current)
    {
        Node<T> * next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}


/*****************************************************************************
 * select_sort():  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method sort the  linkedlist with selection-sort method
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *  The following need previously defined values:
 *      the program should initialize intlist before calling this function
 *
 * POST-CONDITION
 *      the linkedList will be sorted
 *
 *****************************************************************************/
template<typename T>
void LinkedList<T>::select_sort()
{
    Node<T> * current = head;   // CALC - points current position
    Node<T> * after;    // CALC - points the next node 
    Node<T> * min;  // CALC - points the node with minimum value
    T val;  // CALC - value to be swapped

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
 * insert_sorted(const T & value):  Class LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method insert the new node with value to sorted linkedList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const T & value: value of the new node to be inserted
 * POST-CONDITION
 *      the linkedlist will have one additional node with value 
 *
 *****************************************************************************/
template<typename T>
void LinkedList<T>::insert_sorted(
                    const T & value)  // IN - value of the new node
{
    Node<T> * current = head;   // CALC - points current position
    Node<T> * newNode = new Node<T>(value);  // CALC - new node to be added

    if(!head || head->data >= value)
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
 * remove_duplicates():  Class : LinkedList
 *
 * ---------------------------------------------------------------------------
 * This method remove duplicates nodes in linkedList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the program should initialize intlist before calling this function 
 * POST-CONDITION
 *      the LinkedList won't have any duplicates
 *
 *****************************************************************************/
template<typename T>
void LinkedList<T>::remove_duplicates()
{
    Node<T> * current = head;   // CALC - points current position
    Node<T> * p = current;   // CALC - points node before the current node
    Node<T> * n;    // CALC - points node after current node
    Node<T> * temp; // CALC - points temporary node to be deleted

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
                    current->next = n->next;
                    n = n->next;
                    delete temp;
                }
                else
                    n = n->next;
            }
            current = current->next;
        }
    }
}
#endif

