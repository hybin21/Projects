 /*******************************************************************************
 * AUTHOR            : Sharif Diallo, Jessica Hahm
 * LAB #04           : Rational Class
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 01/25/22
*******************************************************************************/
#include <iostream>
#include "rational.h"   // include rational class

/*******************************************************************************
 *
 * Rational Class
 *_________________________________________________________________
 *  This program generates the Rational Class and performs several
 *  mathematics operations using the Rational class
 *    - returns the calculated rationals 
 *_________________________________________________________________
 * INPUTS:
 *  Rational rd: default rational
 *  Rational r1(5): rational with numerator of 5
 *  Rational r2(2,3): rational of 2/3
 *
 * OUTPUTS:
 *  Rational r3: calculated rational 
 *
*******************************************************************************/

using namespace std;

int main(void) 
{
  //PROCESSING - test for each case
  Rational rd;       // CALC&OUT: default rational
  Rational r1(5);     // CALC&OUT: rational with numerator of 5 
  Rational r2(2,3);  // CALC&OUT: rational of 2/3
  Rational r3;      // CALC&OUT: store the calculution value
  
  cout << "Testing default constructor.\n";
  rd.display();   

  cout << "\n\nTesting one argument constructor with 5 as the argument.\n";
  r1.display();

  cout << "\n\nTesting two argument constructor with (2,3) as the argument.\n";
  r2.display();

  cout << "\n\nTesting add function by adding 5 and 2/3.\n";
  r3 = r1.add(r2);
  r3.display();

  cout << "\n\nTesting subtract function by subtracting 5 and 2/3.\n";
  r3 = r1.subtract(r2);
  r3.display();
  
  cout << "\n\nTesting multiply function by multiplying 5 and 2/3.\n";
  r3 = r1.multiply(r2);
  r3.display();

  cout << "\n\nTesting divide function by dividing 5 and 2/3.\n";
  r3 = r1.divide(r2);
  r3.display();
  cout << endl;

  return 0;
}