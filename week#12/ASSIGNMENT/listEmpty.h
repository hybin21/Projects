#ifndef LISTEMPTY_H
#define LISTEMTPY_H
#include "linkedList.h"

template<typename T>
class ListEmpty
{   
    LinkedList<T> check;
    
public:
    ListEmpty();
    ListEmpty(const LinkedList & empty):check(empty);
    ~ListEmpty();
    bool checkEmptyList();
};
#endif

template<typename T>
ListEmpty<T>::ListEmpty()
{
    check = new Node();
}

template<typename T>
ListEmpty<T>::~ListEmpty()
{
    Node * current = check.head;
    while(!current)
    {
        Node * next = check.current->next;
        delete check.current;
        check.current = next;
    }


}
template<typename T>
bool ListEmpty<T>::checkEmptyList()
{
    try 
        if(check.head == NULL && check.tail = NULL);
    catch(false)
        return false;
    catch(true)
    {
        cout << "Exception: The linked List is emtpy\n";
        return  true;
    }
        
}



