/*******************************************************************************
 * AUTHOR         : Jefferson He, Jessica Hahm
 * Lab #8         : Complex Class
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/08/22
*******************************************************************************/
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
 * operator==: Class Complex
 *_________________________________________________________________
 * Overloads the == operator so it checks if the complext numbers are equal
 * - returns true/false if the complex numbers are equal
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Complex &input: Complex variable to be compared
 *
 * POSTCONDITIONS:
 *  Overloads the == operator so that compares the complex variables
 *
*******************************************************************************/

const Complex Complex::operator+(const Complex &input) const
{
  Complex temp;
  temp.a = this->a + input.a;
  temp.b = this->b + input.b;
  return temp;
}
const Complex Complex::operator- (const Complex &input) const
{
  Complex temp;
  temp.a = this->a - input.a;
  temp.b = this->b - input.b;
  return temp;
}
const Complex Complex::operator* (const Complex &input) const
{
  Complex temp;
  temp.a = (this->a * input.a) - (this->b * input.b);
  temp.b = (this->a * input.b) + (this->b * input.a);
  return temp;
}
istream & operator >> (istream &inStream, Complex &input)
{
  int im;
  int re;
  string temp;
  string numTemp;
  string realT;
  string imaginT;

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

ostream & operator << (ostream &outStream, const Complex &input)
{
  if(input.a >= 0)
    outStream << noshowpos << input.a << showpos << input.b << "i";
  else
    outStream << input.a  << showpos <<  input.b << "i";
  return outStream;
}