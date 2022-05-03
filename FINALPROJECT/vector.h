#ifndef VECTOR_H
#define VECTOR_H
#include "linkedlist.h"
#include<iostream>

using namespace std;

template <typename T>
class Vector
{
public:
    Vector();
    Vector(unsigned size);  // IN - size
    Vector(unsigned size,   // IN - size
           const T & value);    // IN - input object
    ~Vector();

    unsigned size() const;
    unsigned capcity() const;
    bool isEmpty() const;
    const T & front() const;
    const T & back() const;
    const T & at(unsigned index) const; // IN - index #

    void insert(unsigned index, // IN - index #
                const T & value);   // IN - value
    void erase(unsigned index); // IN - index #
    void assign(unsigned n, // IN - index #
                const T & value);   // IN - vlaue
    void push_back(T & value);  // IN - value
    void pop_back();
    void clear();
    void resize(unsigned size); // IN - size
    void resize(unsigned size,  // IN - size
                const T & value);   // IN -value
    void reserve(unsigned n);   // IN - new size
    void expand();
    void expand(unsigned amount);   // IN - new size
    T & operator[](int i);  // IN - index #

private:
    unsigned sz;    // IN - size of the vector
    unsigned cap;   // IN - capacity of the vector
    T * data;       // IN - data of the vector
};


/****************
** CONSTRUCTOR **
*****************/


/*****************************************************************************
* Vector();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
template <typename T>
Vector<T>::Vector()
{
    sz = 0;
    cap = 0;
    data = NULL;
}

/*****************************************************************************
* Vector(unsigned size);
*   Constructor; Initialize class attributes
*   Parameters:
        unsigned size: size and capacity of the vector
*   Return: none
*****************************************************************************/
template<typename T>
Vector<T>::Vector(unsigned size) // IN - size/capacity of the vector
{
    sz = size;
    cap = size;

    data = new T[size];
    for(int i = 0; i < size; i++)
        data[i] = 0;
}

/*****************************************************************************
* Vector(unsigned size, int value);
*   Constructor; Initialize class attributes
*   Parameters:
        unsigned size: size and capacity of the vector
        int value: value to be stored in the vector
*   Return: none
*****************************************************************************/
template <typename T>
Vector<T>::Vector(unsigned size,    // IN - size/capcity of the vector
                const T & value)    // IN - value to be stored in the vector
{
    sz = size;
    cap = size;
    data = new T [size];

    for(int i = 0; i < size; i++)
        data[i] = value;
}

/*****************
**  DESTRUCTOR  **
******************/

/*****************************************************************************
* ~Vector();
*   desctructor; deallocate the memory of the vector
*   Parameters: none
*   Return: none
*****************************************************************************/
template <typename T>
Vector<T>::~Vector()
{
    delete [] data;
}

/*****************
**   ACCESSOR   **
******************/

/*****************************************************************************
 * Method size():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods return the size of the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the vector should be initialized
 *
 * POST-CONDITIONç
 *   This function returns the size
 *
 *****************************************************************************/
template <typename T>
unsigned Vector<T>::size() const
{
    return sz;
}

/*****************************************************************************
 * Method capcacity():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods returns the capacity
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the vector should be initialized
 *
 * POST-CONDITIONç
 *   This function returns the capacity
 *
 *****************************************************************************/
template <typename T>
unsigned Vector<T>::capcity() const
{
    return cap;
}

/*****************************************************************************
 * Method empty():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods checks if the vector is empty
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the vector should be initialized
 *
 * POST-CONDITIONç
 *   This function returns true if the vector is empty
 *
 *****************************************************************************/
template <typename T>
bool Vector<T>::isEmpty() const
{
    if(sz == 0)
        return true;
    return false;
}

/*****************************************************************************
 * Method front():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods returns the value stored in the first element
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      Vector should contain any value
 *
 * POST-CONDITIONç
 *   This function returns the value stored in the first element
 *
 *****************************************************************************/
template <typename T>
const T & Vector<T>::front() const
{
    return data[0];
}

/*****************************************************************************
 * Method back():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods returns the value stored in the last element
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      vector should contain any value
 *
 * POST-CONDITIONç
 *   This function returns the value stored in the last element
 *
 *****************************************************************************/
template <typename T>
const T & Vector<T>::back() const
{
    return data[sz-1];
}

/*****************************************************************************
 * Method at:  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods returns the value stored in the index
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the value stored in the index should exist
 *
 * POST-CONDITIONç
 *   This function returns the value stored in the index
 *
 *****************************************************************************/
template <typename T>
const T & Vector<T>::at(unsigned index) const   // IN - index #
{
    if(index >= sz)
        exit(0);
    return data[index];
}

/****************
**   MUTATOR   **
*****************/


/*****************************************************************************
 * Method insert(unsigned index, int value):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods insert the value into index of the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned index: index number to be inserted
 *      T value: value to be inserted in the vector
 *
 * POST-CONDITIONç
 *   The vector will have new value for the index
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::insert(unsigned index,  // IN - index #
                       const T & value) // IN - input value
{
     T temp;    // CALC - temp variable
     T temp2;   // CALC - temp variable

     if(sz + 1> cap)
        expand();
     sz++;

     temp = data[index];
     for(int i = index + 1; i < sz; i++)
     {
         temp2 = data[i];
         data[i] = temp;
         temp = temp2;
     }
     data[index] = value;
}

/*****************************************************************************
 * Method erase():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This method erases the value that is stored in the index
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsinged index: index number to be erased
 *
 * POST-CONDITIONç
 *   The value of the index will be erased
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::erase(unsigned index)   // IN - input index
{
    T temp; // CALC - temp value to erase the value of the index
    for(int i = index; i < sz; i++)
    {
        temp = data[i+1];
        data[i] = temp;
    }
    sz--;
}

/*****************************************************************************
 * Method assign(unsinged n, T value):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods assign n number of value
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned n: the size of the vector to be assigned
 *      T value: the value to be stored
 *
 * POST-CONDITIONç
 *   This function assign new value to the vector
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::assign(unsigned n,  // IN - new size
                       const T & value) // IN - new value
{
    clear();
    reserve(n);
    sz = n;
    for(int i = 0; i < sz; i++)
        data[i] = value;
}

/*****************************************************************************
 * Method push_back(t value):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods inserts a vlaue at the end of the array
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      T value: value to be inserted
 *
 * POST-CONDITIONç
 *   The vector size is increased by 1 and have new value at the end
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::push_back(T & value)   // IN - value to be added
{
    if(sz +1 > cap)
        expand();
    sz++;
    data[sz-1] = value;
}

/*****************************************************************************
 * Method pop_back():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods removes a value at the end of the array
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the vector should have any values
 *
 * POST-CONDITIONç
 *   The vector size is decreased by 1 and the last value is deleted
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::pop_back()
{
    sz--;
}

/*****************************************************************************
 * Method clear():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods clear the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the vector should have any values
 *
 * POST-CONDITIONç
 *   The vector is empty
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::clear()
{
    for(int i = 0; i < sz; i++)
        data[i] = 0;
    sz = 0;
}

/*****************************************************************************
 * Method resize(unsigned size):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This method chages the size of the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned size: new size of the vector
 *
 * POST-CONDITIONç
 *   The vector will have new size
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::resize(unsigned size)   // IN - new size
{
    T temp;
    if(size < sz)
        sz = size;
    else
    {
        for(int i = sz; i < size; i++)
            push_back(temp);
    }
}

/*****************************************************************************
 * Method resize(unsigned size, int value):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods resize the vector and initialize the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsinged size: new size of the vector
 *      T value: value to be initialized
 *
 * POST-CONDITIONç
 *   The vector will have new size
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::resize(unsigned size,   // IN - new size
                       const T & value) // IN - new value to be stored
{
    if(size < sz)
        sz = size;
    else
    {
        for(int i = sz; i < size; i++)
            push_back(value);
    }
}

/*****************************************************************************
 * Method reserve(unsigned n):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods reserve the capacity of the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned n: new capacity of the vector
 *
 * POST-CONDITIONç
 *   The vector will have new capacity
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::reserve(unsigned n) // IN - new capacity of the vector
{
    if(n > cap)
    {
        if(n > cap * 2)
            expand(n-cap);
        else
            expand();
    }
}

/*****************************************************************************
 * Method expand():  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This method expands the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      the vector should be initialized
 *
 * POST-CONDITIONç
 *   The vector has new capacity
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::expand()
{
    T * temp;   // CALC - new data memory with new capacity and old value
    if(sz == 0)
        cap = 1;
    else
        cap *= 2;

    temp = new T[cap];
    for(int i = 0; i < sz; i++)
        temp[i] = data[i];
    delete [] data;

    data = temp;
}

/*****************************************************************************
 * Method expand(unsinged):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods expands the vector
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigend amount: amount to be added to capacity
 *
 * POST-CONDITIONç
 *   The vector has new capacity
 *
 *****************************************************************************/
template <typename T>
void Vector<T>::expand(unsigned amount) // IN - amount to be added to capacity
{
    T * temp;   // CALC - new data memory with new capacity and old value

    temp = new T[sz + amount];
    cap += amount;
    for(int i = 0; i < sz; i++)
        temp[i] = data[i];
    delete [] data;
    data = temp;
}

/*****************************************************************************
 * T operator[](int i):  Class Vector
 *
 * ---------------------------------------------------------------------------
 * This methods overload operator[]
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int i: index number of the vector
 *
 * POST-CONDITIONç
 *   The function returns the data at i index
 *
 *****************************************************************************/
template <typename T>
T & Vector<T>::operator[](int i)    // IN - index number
{
    if(i > size())
    {
        cout << "Index out of bounds" << endl;
        return data[0];
    }
    else
        return data[i];
}
#endif
