/*******************************************************************************
 * AUTHOR            : Jessica Hahm
 * ASSIGNMENT #05    : IntVector
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 02/23/22
*******************************************************************************/

#include <iostream>
#include "IntVector.h"

using namespace std;

/****************
** CONSTRUCTOR ** 
*****************/


/*****************************************************************************
* IntVector();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/
IntVector::IntVector()
{
    this->sz = 0;
    this->cap = 0;
    data = NULL;
}

/*****************************************************************************
* IntVector(unsigned size);
*   Constructor; Initialize class attributes
*   Parameters:
        unsigned size: size and capacity of the vector
*   Return: none 
*****************************************************************************/
IntVector::IntVector(unsigned size) // IN - size and capacity of the vector
{
    this->sz = size;
    this->cap = size;
    
     // allocate memoery 
    this->data = new int [size];
    for(int i = 0; i < size; i++)
        this->data[i] = 0; 
}

/*****************************************************************************
* IntVector(unsigned size, int value);
*   Constructor; Initialize class attributes
*   Parameters: 
        unsigned size: size and capacity of the vector
        int value: value to be stored in the vector
*   Return: none 
*****************************************************************************/
IntVector::IntVector(unsigned size,  // IN - size and capacity of the vector      
                        int value)  // IN - value to be stored in the vector
{ 
    this->sz = size;
    this->cap = size;
    this->data = new int [size];

    //Processing
    for(int i = 0; i < size; i++)
        this->data[i] = value; 
}

/*****************
**  DESTRUCTOR  ** 
******************/

/*****************************************************************************
* ~IntVector();
*   desctructor; deallocate the memory of the int vector
*   Parameters: none
*   Return: none 
*****************************************************************************/
IntVector::~IntVector()
{
    delete [] data;
}

/*****************
**   ACCESSOR   ** 
******************/

/*****************************************************************************
 * Method size():  Class IntVector
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
unsigned IntVector::size() const
{
    return this->sz;
}

/*****************************************************************************
 * Method capcacity():  Class IntVector
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
unsigned IntVector::capacity() const
{
    return this->cap;
}

/*****************************************************************************
 * Method empty():  Class IntVector
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
bool IntVector::empty() const
{
    if(this->sz == 0)
        return true;
    
    return false;
}

/*****************************************************************************
 * Method front():  Class IntVector
 * 
 * ---------------------------------------------------------------------------
 * This methods returns the value stored in the first element
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int vector should contain any value
 *    
 * POST-CONDITIONç
 *   This function returns the value stored in the first element
 * 
 *****************************************************************************/
const int & IntVector::front() const
{
    return this->data[0];
}

/*****************************************************************************
 * Method back():  Class IntVector
 * 
 * ---------------------------------------------------------------------------
 * This methods returns the value stored in the last element
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int vector should contain any value
 *    
 * POST-CONDITIONç
 *   This function returns the value stored in the last element
 * 
 *****************************************************************************/
const int & IntVector::back() const
{
    return this->data[this->sz-1];
}

/*****************************************************************************
 * Method at:  Class IntVector
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
const int & IntVector::at(unsigned index) const // IN - index to be displayed                               
{
    if (index >= this->sz)
       exit(0);
    else
        return this->data[index];
}

/****************
**   MUTATOR   ** 
*****************/


/*****************************************************************************
 * Method insert(unsigned index, int value):  Class IntVector
 * 
 * ---------------------------------------------------------------------------
 * This methods insert the value into index of the vector
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned index: index number to be inserted
 *      int value: value to be inserted in the vector
 *    
 * POST-CONDITIONç
 *   The vector will have new value for the index
 * 
 *****************************************************************************/
void IntVector::insert(unsigned index,  // IN - index number to be inserted
                        int value)      // IN - value to be inserted
{
    int temp;       // CALC - temporary value for the insertion
    int temp2;      // CALC - temporary value for the insertion

    // when new size is bigger than its capacity
    if(this->sz +1 > this->cap)
        expand();

    this->sz++;

    
    temp = this->data[index];
    for(int i = index + 1 ; i < this->sz ; i++)
    {
        temp2 = this->data[i];
        this->data[i] = temp;
        temp = temp2;
    }
    this->data[index] = value;
}

/*****************************************************************************
 * Method erase():  Class IntVector
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
void IntVector::erase(unsigned index)   // IN - index number to be erased
{
    int temp;   // CALC - temporary value to erase the value of the index
    
    for(int i = index; i < this->sz; i++)
    {
        temp = this->data[i+1];
        this->data[i] = temp;
    }
    this->sz--;
}


/*****************************************************************************
 * Method assign(unsinged n, int value):  Class IntVector
 * 
 * ---------------------------------------------------------------------------
 * This methods assign n number of value
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned n: the size of the vector to be assigned
 *      int value: the value to be stored 
 *    
 * POST-CONDITIONç
 *   This function assign new value to the vector
 * 
 *****************************************************************************/
void IntVector::assign(unsigned n,  // IN - new size of the vector
                        int value)  // IN - new value to be added
{
    clear();
    reserve(n);
    this->sz = n;
    for(int i = 0; i < this->sz; i++)
        this->data[i] = value;
}

/*****************************************************************************
 * Method push_back(int value):  Class IntVector
 * 
 * ---------------------------------------------------------------------------
 * This methods inserts a vlaue at the end of the array
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      int value: value to be inserted
 *    
 * POST-CONDITIONç
 *   The vector size is increased by 1 and have new value at the end 
 * 
 *****************************************************************************/
void IntVector::push_back(int value)   // IN - value to be added in the vector
{
    if(this->sz+1 > this->cap)
        expand();
    this->sz++;
    this->data[this->sz-1] = value;
}

/*****************************************************************************
 * Method pop_back():  Class IntVector
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
void IntVector::pop_back()
{
    this->data[this->sz-1] = 0;
    sz--;

}

/*****************************************************************************
 * Method clear():  Class IntVector
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
void IntVector::clear()
{
    for(int i = 0; i < this->sz; i++)
        this->data[i] = 0;
    this->sz = 0;
}

/*****************************************************************************
 * Method resize(unsigned size):  Class IntVector
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
void IntVector::resize(unsigned size)   // IN - new size
{
    if(size < this->sz)
        this->sz = size;
    else    
    {
        for(int i = this->sz; i < size; i++)
            push_back(0);
    }
}

/*****************************************************************************
 * Method resize(unsigned size, int value):  Class IntValue
 * 
 * ---------------------------------------------------------------------------
 * This methods resize the vector and initialize the vector
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsinged size: new size of the vector
 *      int value: value to be initialized
 *    
 * POST-CONDITIONç
 *   The vector will have new size 
 * 
 *****************************************************************************/
void IntVector::resize(unsigned size,   // IN - new size
                        int value)      // IN - new value to be stored
{
    if(size < this->sz)
        this->sz = size;
    else    
    {
        for(int i = this->sz; i < size; i++)
            push_back(value);
    }
}

/*****************************************************************************
 * Method reserve(unsigned n):  Class IntVector
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
void IntVector::reserve(unsigned n) // IN - new capcity of the vector
{
    if(n > this->cap)
        // when increasing the capcity to n is bigger than doubling capacity
        if(n > this->cap * 2)
            expand(n-cap);
        
        // when doubling capacity is bigger than incresing the cap. to n
        else    
            expand();
}

/*****************************************************************************
 * Method expand():  Class IntVector
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
void IntVector::expand()
{
    int* temp;  // CALC - new data memory with new capacity and old value
    if(this->sz == 0)
        this->cap = 1;
    else
        this->cap *= 2;

    // allocate new memory
    temp = new int[cap];
    for(int i = 0; i < this->sz; i++)
        temp[i] = data[i];
    
    // delete old data
    delete [] data;

    // store data to new data
    this->data = temp;
   
}

/*****************************************************************************
 * Method expand(unsinged):  Class IntVector
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
void IntVector::expand(unsigned amount) // IN - amount to be added to capacity
{
    int* temp;  // CALC - new data memory with new capacity and old value

    // allocate new memory
    temp = new int[this->sz + amount];
    this->cap += amount;
    for(int i = 0; i < this->sz; i++)
        temp[i] = data[i];
    
    // delete old data
    delete [] data;

    // store data to new data
    this->data = temp;
}

 