/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jason Boenjamin
 * Lab #7         : Distance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/01/22
*******************************************************************************/
#include "distance.h"
#include<cmath>

const int FEET_TO_INCHES = 12;

/*******************************************************************************
 * Distance()
 *_________________________________________________________________
 *  description: Default constructor that sets
 *    feet and inches to 0
 *               
 *  - returns the default Distance object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   feet and inches must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  initializes feet and inches to 0
 *
*******************************************************************************/
Distance::Distance(): feet(0),inches(0){}  //IN/OUT - Initializes feet 
                                                  // and inches to 0

/*******************************************************************************
 * Distance() - Two parameters
 *_________________________________________________________________
 *  description: constructor that sets feet
 *   and inches to their respective parameters
 *               
 *  - returns the new Distance object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   feet and inches must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  initializes feet and inches to the parameters
 *
*******************************************************************************/
Distance::Distance(unsigned feet,       //IN/OUT - number of feet
                    double inches)      //IN/OUT - number of inches
{          

  //initialization
  this->feet = feet;
  this->inches = inches;

  //if statements for the diff conditions
  if(inches < 12 && inches > 0)
    this->inches = inches;
  else
  {
    this->inches = convertToInches();
    init();
  }
}

/*******************************************************************************
 * Distance() - One parameters
 *_________________________________________________________________
 *  description: constructor that gets newInches
 *    and converts it to feet and inches
 *               
 *  - returns the new Distance object
 *_________________________________________________________________
 * PRECONDITIONS:
 *  inches must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  changes the inches to feet and inches
 *
*******************************************************************************/
Distance::Distance(double newInches)    //IN/OUT - number of inches
                                        //Usually total inches
{ 
  //initialization
  this->inches = newInches;
  //Call init to convert to feet and inches
  init();

}

/*******************************************************************************
 * convertToInches()
 *_________________________________________________________________
 *  description: function converts all the 
 *  feet and inches to just inches
 *               
 *  - returns the new amount of inches
 *_________________________________________________________________
 * PRECONDITIONS:
 *   feet and inches must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  converted feet and inches to just inches
 *
*******************************************************************************/
double Distance::convertToInches() const
{
  double newInches;   //CALC&OUT - gets the total amount of inches

  //Calculates how many total inches from feet and inches
  newInches = abs(this->inches) + this->feet * FEET_TO_INCHES;
  
  return newInches;
}

/*******************************************************************************
 * operator+()
 *_________________________________________________________________
 *  description: function adds two distances together
 *                overloads the "+" operator               
 *
 *  - returns the new added amount of feet and inches 
 *_________________________________________________________________
 * PRECONDITIONS:
 *   feet and inches must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  The two total distances shall be added
 *
*******************************************************************************/
const Distance Distance::operator+
          (const Distance &newDistance) const   //IN/CALC - the second object
                                                // the user is adding
{
  //Adds the two total distances and returns it
  return Distance(convertToInches() + newDistance.convertToInches());
}

/*******************************************************************************
 * operator-()
 *_________________________________________________________________
 *  description: function subtracts two distances together
 *               also overloads the "-" operator
 *  - returns the new subtracted amount of feet and inches 
 *_________________________________________________________________
 * PRECONDITIONS:
 *   feet and inches must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  The two total distances shall be subtracted
 *
*******************************************************************************/
const Distance Distance::operator-
         (const Distance & newDistance) const    //IN/CALC - the second object
                                                 //the user is subtracting
{
  //Subtracts the two total distances and returns it
  return Distance(convertToInches() - newDistance.convertToInches());
}
/*******************************************************************************
 * init()
 *_________________________________________________________________
 *  description: function change distance's value
 *               
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  inches and feet must be predefined
 *   
 *
 * POSTCONDITIONS:
 *  the class should have mutated distance value
 *
*******************************************************************************/
void Distance::init()
{
  double temp;  //CALC&OUT - temporary inches

  temp = this->inches;
  
  /*
  If- statements to test the different conditions of inches
  Tests if its greater than 12, less than zero
  or neither
  */
  if(temp > 12)
  {
    this->feet = temp / FEET_TO_INCHES;
    this->inches -= (FEET_TO_INCHES * this->feet);
  }
  else if(temp < 0)
  {
    this->inches = abs(this->inches);
    init();
  }
  // PROCESSING - when user inputs inches less than 12
  else
  {
    this->feet = 0;
    this->inches = temp;
  }
}

/*******************************************************************************
 * display()
 *_________________________________________________________________
 *  description: function display distance
 *               
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  inches should be mutated by the init() to be less than 12
      and positive
 *   
 *
 * POSTCONDITIONS:
 *  the distance is displayed to the user
 *
*******************************************************************************/
void Distance::display() const
{
  //Displays the feet and inches by calling it
  cout << this->feet << "' " << this->inches << "\"";
}