#include <iostream>
#include <string>
#include<cctype>
#include "complex.h"

using namespace std;

/*******************************************************************************
 * Complex()
 *_________________________________________________________________
 *  description: constructor that sets real num and imaginary num to 0
 *
 *
 *  - returns the Complex object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   no preconditions
 *
 *
 * POSTCONDITIONS:
 *  returns the Complex variable
 *
*******************************************************************************/

Complex :: Complex ()
{
  a = 0; //OUT: set real num to 0;
  b = 0; //OUT: set imaginary num to 0;
}

/*******************************************************************************
 * Complex (double real_part)
 *_________________________________________________________________
 *  description: constructor that sets real num to real_part and
 *               imaginary num to 0
 *
 *  - returns the Complex object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   The following needs previous defined values:
 *   double real_part: real num of the complex number
 *
 * POSTCONDITIONS:
 *  returns the Complex variable
 *
*******************************************************************************/

Complex :: Complex (double real_part) //CALC: real num of complex
{
  a = real_part; //CALC&OUT: set real num to real_part
  b = 0; //OUT: set imaginary num to 0
}

/*******************************************************************************
 * Complex (double num, double num1)
 *_________________________________________________________________
 *  description: constructor that sets real number to num and
 *               imaginary number to num1
 *
 *  - returns the Complex object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   The following needs previous defined values:
 *   double num: real num of the complex number
 *   double num1: imaginary num of the complex number
 *
 * POSTCONDITIONS:
 *  returns the Complex variable
 *
*******************************************************************************/

Complex :: Complex (double num, //CALC: real num of complex
                   double num1) //CALC: imaginary num of complex
{
  a = num;  //CALC&OUT: set real num to num
  b = num1; //CALC&OUT: set imaginary num to num1
}

/*******************************************************************************
 * operator==: Class Complex
 *_________________________________________________________________
 * Overloads the == operator so it checks if the complext numbers are equal
 * - returns 1/2 if the complex numbers are equal
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  Overloads the == operator so that compares the complex variables
 *
*******************************************************************************/

const int Complex::operator ==(const Complex &input) const
{
  if(this->a == input.a && this->b == input.b)
    return 1;
  return 0;
}

/*******************************************************************************
 * operator+: Class Complex
 *_________________________________________________________________
 * Overloads the + operator to do addition
 * - do addition of two objects
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: input Complex object
 *
 * POSTCONDITIONS:
 *  Overloads the + operator to do addition
 *
*******************************************************************************/

const Complex Complex::operator+(const Complex &input) const    // IN - input
{
  Complex temp; // CALC/OUT: temp complex class
  temp.a = this->a + input.a;
  temp.b = this->b + input.b;
  return temp;
}

/*******************************************************************************
 * operator-: Class Complex
 *_________________________________________________________________
 * Overloads the - operator to do subtraction
 * - returns the value of the calculation
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  Overloads the - operator for subtraction
 *
*******************************************************************************/

const Complex Complex::operator- (const Complex &input) const   // IN - input
{
  Complex temp; // CALC/OUT: temp complex class
  temp.a = this->a - input.a;
  temp.b = this->b - input.b;
  return temp;
}

/*******************************************************************************
 * operator*: Class Complex
 *_________________________________________________________________
 * Overloads the * operator to do multiplication
 * - returns the value of the calculation
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  Overloads the * operator for multiplication
 *
*******************************************************************************/

const Complex Complex::operator* (const Complex &input) const   // IN - input
{
  Complex temp; // CALC/OUT: temp complex class
  temp.a = (this->a * input.a) - (this->b * input.b);
  temp.b = (this->a * input.b) + (this->b * input.a);
  return temp;
}

/*******************************************************************************
 * operator>>: Class Complex
 *_________________________________________________________________
 * Overloads the >> operator to get input
 * - returns the input strewam
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  program gets input
 *
*******************************************************************************/
istream & operator >> (istream &inStream,   // IN - input stream
                        Complex &input)     // IN - input complex
{
  int im;   // CALC - imaginary number
  int re;   // CALC - real number
  string temp;  // CALC - temp variable
  string numTemp;   // CALC - temp stores int
  string realT; // CALC - stores real number
  string imaginT;   // CALC - stores imainary number

  im = 0;
  re = 0;
  realT = "";
  imaginT  = "";


  getline(inStream,temp);

  for(int i = 0; i < temp.size(); i++)
  {
    if(i == 0)
    {
      if(temp[i]== '-')
        numTemp += temp[i];
      else if(temp[i] == 'i')
      {
        numTemp += '1';
        im = 1;
      }
      else
        numTemp += temp[i];
    }
    else
    {
      if(temp[i] == 'i')
      {
        if(temp[i-1] == '-')
        {
          numTemp += '1';
          imaginT += numTemp;
        }
        else
        {
          imaginT += numTemp;
          numTemp.clear();
        }
        im = 1;
      }
      else if(temp[i]=='-')
      {

        realT += numTemp;
        numTemp .clear();
        imaginT += temp[i];
        re=1;
      }
      else if(temp[i]=='+')
      {
        realT += numTemp;
        numTemp.clear();
        re=1;
      }
      else if(isdigit(temp[i])||temp[i]=='.')
        numTemp += temp[i];
    }
  }
  if(re != 0 && im == 0 && numTemp != "")
  {
    realT = numTemp;
    imaginT.clear();
  }
  else if(re == 0 && im != 0 && numTemp != "")
  {
    realT.clear();
    imaginT = numTemp;
  }
  else if(re == 0 && im == 0 && numTemp == "")
  {
    realT = "";
    imaginT = "";
  }
  else if(re == 0 && im == 0 && numTemp != "")
  {
    realT = numTemp;
    imaginT.clear();
  }

  if(realT.empty())
    input.a = 0;
  else
    input.a = stod(realT);

  if(imaginT.empty())
    input.b = 0;
  else
    input.b = stod(imaginT);

  return inStream;
}


/*******************************************************************************
 * operator<<: Class Complex
 *_________________________________________________________________
 * Overloads the << operator to get input
 * - returns the ouptut strewam
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  program outputs the value of the input complex class
 *
*******************************************************************************/
ostream & operator << (ostream &outStream,  // IN/OUT - output stream
                       const Complex &input)    // OUT - object to be output
{
  if(input.a >= 0)
    outStream << noshowpos << input.a << showpos << input.b << "i";
  else
    outStream << input.a  << showpos <<  input.b << "i";
  return outStream;
}

/*******************************************************************************
 * returnReal(): Class Complex
 *_________________________________________________________________
 * return real number part of the object
 * - returns the real number
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   N/A
 *
 * POSTCONDITIONS:
 *  program returns the object's real number
 *
*******************************************************************************/
double Complex::returnReal() const
{
    return a;
}

/*******************************************************************************
 * returnImain(): Class Complex
 *_________________________________________________________________
 * return imaginary number part of the object
 * - returns the imaginary number
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   N/A
 *
 * POSTCONDITIONS:
 *  program returns the object's imgainary number
 *
*******************************************************************************/
double Complex::returnImagin() const
{
    return b;
}

/*******************************************************************************
 * setValue(const double real, const double imagin): Class Complex
 *_________________________________________________________________
 * set value of the class
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const double real: real number
 *   const double imagin: imaginary number
 *
 * POSTCONDITIONS:
 *  program returns the object's imgainary number
 *
*******************************************************************************/
void Complex::setValue(const double real,   // IN - real number
                       const double imagin) // IN - imaginary number
{
    a = real;
    b = imagin;
}

/*******************************************************************************
 * operator>=: Class Complex
 *_________________________________________________________________
 * Overloads the >= operator so it checks if the complext
 *      numbers are equal or bigger than the input
 * - returns true/false if the complex number is equal
 *          or biegger than the input
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  program return true if in-class object is bigger
 *              than or equal to the input
 *
*******************************************************************************/
bool Complex::operator>=(const Complex & input) const   // IN - input object
{

    if(this->a >= input.a)
    {
        return true;
    }
    else if(this->b >= input.b)
    {
        return true;
    }
    else
        return false;
}

/*******************************************************************************
 * operator>: Class Complex
 *_________________________________________________________________
 * Overloads the > operator so it checks if the complex
 *      number is bigger than then input object
 * - returns true/false if the complex number is bigger than
 *         the input
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  program return true if in-class object is equal to the input
 *
*******************************************************************************/
bool Complex::operator>(const Complex & input) const    // IN - input object
{
    if(this->a > input.a)
    {
        return true;
    }
    else if(this->b > input.b)
    {
        return true;
    }
    else
        return false;
}

/*******************************************************************************
 * operator<: Class Complex
 *_________________________________________________________________
 * Overloads the < operator so it checks if the complex
 *      number is smaller than input object
 * - returns true/false if the complex number is smaller than
 *       the input
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  program returns true/false if the complex number is smaller than
 *       the input
 *
*******************************************************************************/
bool Complex::operator<(const Complex & input) const    // IN - input object
{
    if(this->a < input.a)
    {
        return true;
    }
    else if(this->b < input.b)
    {
        return true;
    }
    else
        return false;
}

/*******************************************************************************
 * setReal(const double real): Class Complex
 *_________________________________________________________________
 * set value of the class
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const double real: real number
 *
 * POSTCONDITIONS:
 *  program has a new real number value
 *
*******************************************************************************/
void Complex::setReal(const double real)    // IN - real number
{
    this->a = real;
}

/*******************************************************************************
 * setImain(const double imagin): Class Complex
 *_________________________________________________________________
 * set value of the class
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const double imgain: imaginary number
 *
 * POSTCONDITIONS:
 *  program has a new imaginary number value
 *
*******************************************************************************/
void Complex::setImain(const double imagin) // IN - imaginary number
{
    this-> b = imagin;
}
