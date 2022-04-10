/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jason Boenjamin
 * Lab #7         : Distance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/01/22
*******************************************************************************/
#ifndef DISTANCE_H  // checks if headerfile has been created before
#define DISTANCE_H  // defines the distance_h constant

#include<iostream>
using namespace std;


class Distance
{
  private:

    unsigned feet;      //IN/OUT - represents feet
    double inches;      //IN/OUT - represents inches

  public:

    /*****************
    ** CONSTRUCTORS **
    *****************/
    Distance();           //Default constructor
    Distance(             //Constructor with two parameters
              unsigned feet,    // takes in feet
              double inches);   //takes in inches
                                  

    Distance(double);     //Constructor that takes in only inches

    /***************
    **  Accessor  **
    ***************/
    double convertToInches() const;             //Converts the feet to inches
    const Distance operator+
                      (const Distance &) const; //Adds two distances
    const Distance operator-
                      (const Distance &) const; //Subtracts two distances

    /*************
    ** Accessor **
    *************/
    void display() const; //Displaces the feet and inches Ex(feet, inches)

  private:

    /*********************
    **      MUTATORS   **
    *********************/
    void init();              // change the value of distance

};
#endif

/****************************************************************
* Distance Class
*   This class represents a distance and allows you to perform  
      basic mathematics with distances. It manages the feet and 
      inches of a distance
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* Distance();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* Distance(unsigned feet, double inches);
*   Constructor; Initialize class attributes
*   Parameters: first parameter: takes in feet
                second parpameter: takes in inches
*   Return: none
***************************************************************/

/****************************************************************
* Distance(double inches);
*   Constructor; Initialize class attributes
*   Parameters: takes in inches
*   Return: none
***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* double convertToInches() const;
*
*   Accessor; This method will convert the distance to inches

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: distance converted inches

***************************************************************/

/****************************************************************
* const Distance operator+(const Distance &) const;
*
*   Accessor; This method will overload '+' operator

* --------------------------------------------------------------
*   Parameters: constdDistance &: IN - a distance to be added

* --------------------------------------------------------------
*   Return: a new distance that equals the addition

***************************************************************/


/****************************************************************
* const Distance operator-(const Distance &) const;
*
*   Accessor; This method will overload '-' operator

* --------------------------------------------------------------
*   Parameters: const Distance &: IN - rational to be subtracted

* --------------------------------------------------------------
*   Return: a new distance that equals the subtraction

***************************************************************/


/****************************************************************
* void display() const;
*
*   Accessor; This method will display the distance

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: display the distance 

***************************************************************/

/*********************
**      MUTATORS   **
*********************/

/****************************************************************
*  void init(); ;
*
*   Mutator; This method change distance's value

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: mutated distance 

***************************************************************/
