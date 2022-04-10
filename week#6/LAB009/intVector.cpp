/******************************************************************************
 * AUTHOR    : Angel Rojas, Jessica Hahm
 * LAB #9    : IntVector
 * CLASS     : 32276 CS3A 
 * SECTION   : Unit 7
 * DUE DATE  : 2/15/2022
******************************************************************************/
#include "intVector.h"
#include <iostream>

/**********************************************************
*
* Method IntVector(): Class IntVector
*_________________________________________________________
* Description
    This functions initialize class size, capacity to 0
*_________________________________________________________
* PRE-CONDITIONS
*   N/A
*
* POST-CONDITIONS
    vector class's size and capacity is set to 0
*     
***********************************************************/
IntVector::IntVector()
{
    this->sz = 0;
    this->cap = 0;
    data = NULL;
}
/**********************************************************
*
* Method IntVector(unsigned size): Class IntVector
*_________________________________________________________
* Description
    This functions initialize class size, capacity,and 
        allocate memory for the data of the vector
*_________________________________________________________
* PRE-CONDITIONS
*   unsinged size: size and capacity of the vector
*
* POST-CONDITIONS
    the size and capaity are set to the value of the size
        and the data has the size number of 0
*     
***********************************************************/
IntVector::IntVector(unsigned size)// IN - size and cap of vector<int>
{
    this->sz = size;
    this->cap = size;
    
     // allocate memoery 
    this->data = new int [size];
    for(int i = 0; i < size; i++)
        this->data[i] = 0; 

}
/**********************************************************
*
* Method IntVector(unsigned size, int value): Class IntVector
*_________________________________________________________
* Description
    This function intialize the size and capacity of the vector
        and intialize the data 
*_________________________________________________________
* PRE-CONDITIONS
*   unsigned size: size and capacity of the vector
    int value:  value to be initialized to the vector data
*
* POST-CONDITIONS
*   the size and capacity will be size and the vector will 
        store value
***********************************************************/
IntVector::IntVector(unsigned size, // In&Calc-the size of vector
                         int value) // In-the value to fill vector
{

    this->sz = size;
    this->cap = size;
    this->data = new int [size];

    //Processing
    for(int i = 0; i < size; i++)
        this->data[i] = value; 

}
/**********************************************************
*
* Method size(): Class IntVector
*_________________________________________________________
* Description
*   gets the size of the vectors
*_________________________________________________________
* PRE-CONDITIONS
*   none
*       
* POST-CONDITIONS
*     the size of the vector is returned
***********************************************************/

unsigned IntVector::size()const
{
    return this->sz;
}

/**********************************************************
*
* Method capacity(): Class IntVector
*_________________________________________________________
* Description
*   returns the capacity of the vector
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     the capacity of the vector
***********************************************************/
unsigned IntVector::capacity() const
{
     return this->cap;
}

/**********************************************************
*
* Method empty(): Class IntVector
*_________________________________________________________
* Description
*   checks to see if the vector is empty
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*     true or false
***********************************************************/

bool IntVector::empty() const
{
    if(this->sz == 0)
        return true;
    
    return false;
}

/**********************************************************
*
* Method at(unsigned index): Class IntVector
*_________________________________________________________
* Description
*   returns the value at the given index, if index is invalid
*   the program exits
*_________________________________________________________
* PRE-CONDITIONS
*   unsigned index: a defined index to return the value of
*
* POST-CONDITIONS
*     returns value at index or exits program
***********************************************************/

const int& IntVector::at(unsigned index) const//In&Calc-the index to return
{   
    //Processing
    if (index >= this->sz)
       exit(0);
    else
        return this->data[index];
     
}

