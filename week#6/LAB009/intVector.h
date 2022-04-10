/******************************************************************************
 * AUTHOR    : Angel Rojas, Jessica Hahm
 * LAB #9    : IntVector
 * CLASS     : 32276 CS3A 
 * SECTION   : Unit 7
 * DUE DATE  : 2/15/2022
******************************************************************************/
#ifndef INTVECTOR_H 
#define INTVECTOR_H

class IntVector
{
    private:
				     //Data Table
        unsigned sz; //In&Calc - the size of the vector
        unsigned cap;//In&Calc - the capacity of the vector
        int* data;	 //Calc - pointer dynamic memory
      
    public:

        /*********************
        **   CONSTRUCTORS   **
        *********************/
        IntVector(); 
        IntVector(unsigned size);   // IN&CALC - the size of the vector
        IntVector(unsigned size,    // IN&CALC - the size of the vector
                     int value);    // IN&CALC - the value of the vector

        /*********************
        **   ACCESSORS      **
        *********************/
        unsigned size() const;
        unsigned capacity() const;
        bool empty()const;
        const int& at(unsigned index) const; // IN - index # to be returned



};
#endif

/******************************************************************************
* IntVector Class-
*   - This class computes basic int vector member functions
******************************************************************************/

/******************************
**        CONSTRUCTORS       **
******************************/

/****************************************************************
* IntVector ();
*   Constructor: Sets values to 0 and pointer to null
*   Parameters : None
*   Return     : None
***************************************************************/

/****************************************************************
* IntVector (unsigned size);
*   Constructor: sets value to 0 and pointer to data 
*   Parameters :  
        unsigned size: size of the vector
*   Return     : None
***************************************************************/

/****************************************************************
* IntVector (unsigned size, int value);
*   Constructor: sets vector value to value 
*   Parameters : 
        unsigned size of the vector
        int value: value of the vector
*   Return     : None
***************************************************************/


/******************************
**         ACCESSORS         **
******************************/
/****************************************************************
* size();
*   Accessor   : Gets the size of the vector
*   Parameters : None
*   Return     : The size
***************************************************************/

/****************************************************************
* capacity ();
*   Accessor   : Gets the capacity of the vector
*   Parameters : None
*   Return     : The capacity
***************************************************************/

/****************************************************************
* empty ();
*   Accessor   : Checks to see if the vector is empty
*   Parameters : None
*   Return     : True or False
***************************************************************/

/****************************************************************
* at(unsigned index) const;
*   Accessor   : Gets the value at index in the vector
*   Parameters : the index to find value at
*   Return     : the value at the index if valid
***************************************************************/


