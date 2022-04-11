#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include "listEmpty.h"

using namespace std;

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

template <typename T>
class LinkedList
{
    class Iterator
    {
        private: 
            Node * current;  // IN - current position of the linked list
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
    void pop_front();
    void clear();
    void select_sort();
    void insert_sorted(const T & value);
    void remove_dupliccates();


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
#endif

template<typename T>
LinkedList<T>::Iterator::Iterator()
{
    current = NULL;
}

template<typename T>
LinkedList<T>::Iterator::Iterator(Node<T> * ptr)
{
    current = ptr;
}

template<typename T>
T LinkedList<T>::Iterator::operator*()
{
    return current->data;
}   

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++()
{
    if(current)
        current = current->next;
    return *this;
}

template<typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& right) const
{
    /*
    if(current->data == right.current->data)
    {
        if(current->next == right.current->next)
        {
            return true;
        }
        return false;
    }
    */
    return(current == right.current)
}

template<typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& right) const
{
    return (current != right.current);
}

template<typename T>
LinkedList<T>::LinkedList()
{
    Node = Node(0);
    head = NULL;
    tail = NULL;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & list)
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
        Node * current = list.head;
        while(current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node * current = head;
    while(!current)
    {
        Node * next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & source)
{
    Node * current;
    Node * temp = source.head;

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

template<typename T>
const T& LinkedList<T>::front() const throw(ListEmpty<T>)
{
    ListEmpty check(this);
    throw(check);
    if(!check.checkEmptyList())
        return head->data;
    return 0;
}

template<typename T>
const T & LinkedList<T>::back() const throw(ListEmpty<T>)
{   
    ListEmpty check(this);
    throw(check);
    if(!check.checkEmptyList())
        return tail->data;
    return 0;
}

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::begin()
{
    LinkedList<T>::Iterator  currentIterator(head);
    return currentIterator;
}

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::end()
{
    LinkedList<T>::Iterator  currentIterator(tail->next);
    return currentIterator;
}

template<typename T>
int LinkedList<T>::getLength(Node<T>* ptr) const
{
    if(!ptr)
        return 0;
    else
        return 1 + getLength(ptr->next);
}

template<typename T>
int LinkedList<T>::length() const
{
    return getLength(head);
}

template<typename T>
T LinkedList<T>::getSum(Node<T>* ptr) const
{   if(!ptr)
        return 0;
    else
        return ptr->data + getSum(ptr->next);

}

template<typename T>
T LinkedList<T>::sum() const
{
    return getSum(head);
}

template<typename T>
void LinkedList<T>::display() const
{
    Node * current = head;
    while(current)
    {
        if(current->next != NULL)
            cout << current->data << " ";
        else
            cout << current->data;
        current = current->next;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    if(head == NULL && tail == NULL)
        return true;
    return false;
}


template<typename T>
void LinkedList<T>::push_front(const T & value)
{
    Node * temp = new Node(value);
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

template<typename T>
void LinkedList<T>::push_back(const T & value)
{
    Node * temp = new Node(value);

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

template<typename T>
void LinkedList<T>::pop_front()
{
    throw(this);
    if(ListEmpty.checkEmptyList())
    {
        if(head)
        {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }
}

template<typename T>
void LinkedList<T>::clear()
{
    Node * current = head;
    while(!current)
    {
        Node * next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}


template<typename T>
void LinkedList<T>::select_sort()
{
    Node * current = head;
    Node * after;
    Node * min;
    T val;

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
        crurent->data = min->data;
        min->data = val;

        current = current->next;
    }
}

template<typename T>
void LinkedList<T>::insert_sorted(const T & value)
{
    Node * current = head;
    Node* newNode = new Node(value);

    i(!head || haed->data >= value)
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

template<typename T>
void LinkedList<T>::remove_dupliccates()
{
    Node * current = head;
    Node * p;
    Node * n;
    Node * temp;

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
                current = current->next;
            }
        }
    }
}