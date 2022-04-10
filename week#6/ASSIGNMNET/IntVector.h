/*******************************************************************************
 * AUTHOR            : Jessica Hahm
 * ASSIGNMENT #05    : IntVector
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 02/23/22
*******************************************************************************/
#ifndef INTVECTOR_H // check if headerfile has been created before
#define INTVECTOR_H // define header file

class IntVector
{
    private:
        unsigned sz;    // size of the int vector
        unsigned cap;   // capacity of the int vector 
        int* data;      // data pointer to store data 
    public:
        // constructor
        IntVector();        
        IntVector(unsigned size);   // IN - size of the vector
        IntVector(unsigned size,    // IN - size of the vector
                     int value);    // IN - value to be filled to the vector

        // descructor
        ~IntVector();

        // accessor
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & front() const;
        const int & back() const;
        const int & at
            (unsigned index) const; // IN - index number to be returned

        // mutator
        
        void insert(unsigned index,  // IN - index number to insert the valuer
                        int value); // IN - value to be inserted to the vector
        void erase(unsigned index);     // IN - index number to be erased
        void assign(unsigned n,         // IN - size of the vector 
                     int value);        // IN/CALC - value to be assigned
        void push_back(int value);      // IN - value to be added 
        void pop_back();
        void clear();
        void resize(unsigned size);     // IN - new size of the vector
        void resize(unsigned size,      // IN - new size of the vector
                     int value);        // IN - new value to be added 
        void reserve(unsigned n);       // IN - new capacity
        void expand();
        void expand
            (unsigned amount); // IN - amount of the capacity to be added

}; 
#endif

/****************************************************************
* IntVector Class
*   This class represents an int vector and allows you to use
        basic member function of vector
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* IntVector();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
***************************************************************/

/****************************************************************
* IntVector(unsigned size);
*   Constructor; Initialize class attributes
*   Parameters:
        unsigned size: size and capacity of the vector
*   Return: none 
***************************************************************/

/****************************************************************
* IntVector(unsigned size, int value);
*   Constructor; Initialize class attributes
*   Parameters: 
        unsigned size: size and capacity of the vector
        int value: value to be stored in the vector
*   Return: none 
***************************************************************/

/*****************
**  DESTRUCTOR  **
*****************/

/****************************************************************
* ~IntVector();
*   desctructor; deallocate the memory of the int vector
*   Parameters: none
*   Return: none 
***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* unsigned size() const
*
*   Accessor; This method returns the size of the vector

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: size of the vector

***************************************************************/

/****************************************************************
* unsigned capacity() const
*
*   Accessor; This method returns the capacity of the vector

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: capacity of the vector
***************************************************************/

/****************************************************************
* bool empty() const
*
*   Accessor; This method checks if the vector is empty

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: true if the vector is empty, false it it's not

***************************************************************/

/****************************************************************
* const int & front() const
*
*   Accessor; This method returns the value stored in the 
                first element


* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: the value stored in the first element

***************************************************************/

/****************************************************************
* const int & back() const
*
*   Accessor; This method returns the value stored in the 
                last element

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: the value stored in the last element

***************************************************************/

/****************************************************************
* const int & at(unsigned index) const;
*
*   Accessor; This method will return the value stored in the idnex
* --------------------------------------------------------------
*   Parameters: 
        unsinged index: index to be displayed

* --------------------------------------------------------------
*   Return: the value stored in the index

***************************************************************/

/*********************
**     MUTATORS     **
*********************/

/****************************************************************
*  void insert(unsigned index, int value)
*
*   Mutator; This method inserts the value into the index of the vector

* --------------------------------------------------------------
*   Parameters: 
        unsigned index: index number to be inserted
        int value: value to be inserted

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void erase(unsigned index)
*
*   Mutator; This method erases the value that is stored in the index

* --------------------------------------------------------------
*   Parameters: 
        unsigned index: index number to be erased

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/


/****************************************************************
*  void assign(unsinged n, int value)
*
*   Mutator; This method assigns n numebr of value 

* --------------------------------------------------------------
*   Parameters: 
        unsinged n: new size of the vector
        int value: new value to be added

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void push_back(int value)
*
*   Mutator; This method inserts a value at the end of the array

* --------------------------------------------------------------
*   Parameters: 
        int value: value to be added in the vector

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void pop_back()
*
*   Mutator; This method removes a value at the end of the array

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void clear();
*
*   Mutator; This method clears the vector

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A
***************************************************************/

/****************************************************************
*  void resize(unsinged size); ;
*
*   Mutator; This method changes the size of the vector
* --------------------------------------------------------------
*   Parameters: 
        unsinged size: new size of the vector

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void reserve(unsinged size, int value); ;
*
*   Mutator; This method resizes the vector and initializes the vector
* --------------------------------------------------------------
*   Parameters: 
        unsinged size: new size of the vector
        int value: value to be initialized

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void reserve(unsinged n);
*
*   Mutator; This method reserves the new capacity of the vector

* --------------------------------------------------------------
*   Parameters: 
        unsinged n: new capacity of the vector

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void expand();
*
*   Mutator; This method expands the vector

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/****************************************************************
*  void expand(unsinged amount);
*
*   Mutator; This method expands the vector

* --------------------------------------------------------------
*   Parameters: 
        unsinged amount: amount to be added to capacity

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/


