#include "rational.h"   // include rational class header file

/******************************
** CONSTRUCTOR & DESTRUCTOR ** 
******************************/


/*****************************************************************************
* Rational();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/

Rational::Rational()                                                            
{ 
  numer = 0;
  denom = 1;
}

/*****************************************************************************
* Rational(int a);
*   Constructor; Initialize class attributes
*   Parameters: 
      int a: numerator
*   Return: none 
*****************************************************************************/

Rational::Rational(int a)   // IN - New rational's numerator
{
  numer = a;
  denom = 1;
}

/*****************************************************************************
* Rational(int a, int b);
*   Constructor; Initialize class attributes
*   Parameters: 
      int a: numerator
      int b: denominator
*   Return: none 
*****************************************************************************/

Rational::Rational(int a,   // IN - New rational's numerator
                   int b)   // IN - New rational's denominator
{
  numer = a;
  denom = b;
}


/***************
** ACCESSORS ** 
***************/


/*****************************************************************************
 * Method add: Class Rational
 * 
 * ---------------------------------------------------------------------------
 * This methods receives a rational b with denominator and numerator
 *   and add existing rational number a and input b together and 
 *   return the new rational c
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    Rational &b: a rational that will be added to rational in the class(a)
 *    
 * POST-CONDITION
 *   This function return the calculated rational 
 * 
 *****************************************************************************/

const Rational Rational::add(const Rational &b)const // IN - rat. to be calc
{
  Rational temp;    // CALC&OUT - calculated rational

  // PROCESSING: (a/b) + (c/d) = (a*d + b*c) / (b*d)
  temp.denom = b.denom * this->denom;
  temp.numer = b.numer * this->denom + b.denom * this->numer;
  return temp;
}


/*****************************************************************************
 * Method subtract: Class Rational
 * 
 * ---------------------------------------------------------------------------
 * This methods receives a rational b with denominator and numerator
 *   and subtract input rational(b) from the class rational(a) and 
 *   return the calculated new rational(temp/c)
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    Rational &b: a rational that will subtracted from rational in the class(a)
 *    
 * POST-CONDITION
 *   This function return the calculated rational 
 * 
 *****************************************************************************/

const Rational Rational::subtract(const Rational & b)const // IN - # to be calc
{
  Rational temp;    // CALC&OUT - calculated rational

  // PROCESSING: (a/b) - (c/d) = (a*d - b*c) / (b*d)
  temp.numer = this->numer * b.denom - this->denom * b.numer;
  temp.denom = this->denom * b.denom;

  return temp;
}

/*****************************************************************************
 * Method multiply: Class Rational
 * 
 * ---------------------------------------------------------------------------
 * This methods receives a rational b with denominator and numerator
 *   and mutliply it with class rational(a) 
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    Rational &b: a rational that will be multiplied with rational(a)
 *    
 * POST-CONDITION
 *   This function return the calculated rational 
 * 
 *****************************************************************************/

const Rational Rational::multiply(const Rational & b)const // IN - # to be calc
{   
  Rational temp;    // CALC&OUT - calculated rational
  
  // PROCESSING: multiply: (a/b) * (c/d) = (a*c) / (b*d)
  temp.numer = this->numer * b.numer;
  temp.denom = this->denom * b.denom;

  return temp;
}

/*****************************************************************************
 * Method divide: Class Rational
 * 
 * ---------------------------------------------------------------------------
 * This methods receives a rational b with denominator and numerator
 *   and divide class rational(a) by received rational(b)
 * 
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    Rational &b: a rational that will be used for the division
 *    
 * POST-CONDITIONç
 *   This function return the calculated rational 
 * 
 *****************************************************************************/

const Rational Rational::divide(const Rational & b) const // IN - # to be calc
{         
  Rational temp;   // CALC&OUT - calculated rational

  // PROCESSING: (a/b) / (c/d) = (a*d) / (c*b)                                                          
  temp.denom = b.numer * this->denom;
  temp.numer = this->numer * b.denom;

  return temp;
}

/*****************************************************************************
 * Method display: Class Rational
 * 
 * ---------------------------------------------------------------------------
 * This methods display in-class rational
 * 
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    Rational &b: a rational that will be used for the division
 *    
 * POST-CONDITIONç
 *   This function return the calculated rational 
 * 
 *****************************************************************************/

void Rational::display() const                              
{
  cout << numer << "/" << denom;
}