#ifndef RATIONAL_H // checks if headerfile has been created before
#define RATIONAL_H // defines the rational_h constant

#include <iostream>
#include <QString>

using namespace std;

class Rational
{
  private:
    int numer;         //IN/OUT - the rational's numerator
    int denom;         //IN/OUT - the rational's denominator
  public:

    /******************************
    ** CONSTRUCTOR & DESTRUCTOR **
    ******************************/

    Rational();         //default consructor
    Rational(int);      //constructor
    Rational(int, int); //constructor


    /***************
    ** ACCESSORS **
    ***************/
    bool operator>= (
            const Rational & input);// IN - input object
    bool operator< (
            const Rational & input);// IN - input object
    bool operator> (
            const Rational & input);// IN - input object
    bool operator== (
            const Rational & input);// IN - input object

    /*************
    ** MUTATOR **
    **************/
    Rational & operator=(
            const Rational & input);// IN - input object

    Rational & setValue(const int number,// IN - numerator
                        const int denom);// IN - denomianator
    const Rational add(
            const Rational &b) const;// IN - input object
    const Rational subtract(
            const Rational &b) const;// IN - input object
    const Rational multiply(
            const Rational &b) const;// IN - input object
    const Rational divide(
            const Rational &b) const;// IN - input object

    int getNumer() const;
    int getDenom() const;
    void display() const;
};

/****************************************************************
* Rational Class
*   This class represents a simple rational and allows you
*     to perform basic mathematics with fractions. It manages
*     the numerator and denominator of a rational.
***************************************************************/


/******************************
** CONSTRUCTOR & DESTRUCTOR **
******************************/

/****************************************************************
* Rational ();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* Rational (int);
*   Constructor; Initialize class attributes
*   Parameters: one initialized integer for the numerator
*   Return: none
***************************************************************/

/****************************************************************
* Rational (int, int);
*   Constructor; Initialize class attributes
*   Parameters: integers initialized for the numerator
*    and denominator
*   Return: none
***************************************************************/



/*************
** MUTATOR **
**************/

/****************************************************************
* Rational & opeartor=(const Rational & input)
*
*   Accessor; This method will override = operator

* --------------------------------------------------------------
*   Parameters:
*   const Rational & input: input Class to
      be compared

* --------------------------------------------------------------
*   Return: object with new value

***************************************************************/
/****************************************************************
* const Rational add(const Rational &b) const;
*
*   Accessor; This method will add two rationals together

* --------------------------------------------------------------
*   Parameters: Rational &b: IN - a rational to be added

* --------------------------------------------------------------
*   Return: a new rational that equals the addition

***************************************************************/

/****************************************************************
* const Rational subtract(const Rational &b) const;
*
*   Accessor; This method will subtract two rationals

* --------------------------------------------------------------
*   Parameters: Rational &b: IN - a rational to be subtracted

* --------------------------------------------------------------
*   Return: a new rational that equals the subtraction

***************************************************************/

/****************************************************************
* const Rational multiply(const Rational &b) const;
*
*   Accessor; This method will multiply two rationals

* --------------------------------------------------------------
*   Parameters: Rational &b: IN - a rational to be multiplied

* --------------------------------------------------------------
*   Return: a new rational that equals the multiplication

***************************************************************/

/****************************************************************
* const Rational divide(const Rational &b) const;
*
*   Accessor; This method will add divide rationals

* --------------------------------------------------------------
*   Parameters: Rational &b: IN - a rational to be divided

* --------------------------------------------------------------
*   Return: a new rational that equals the division

***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* int getNumer() const;
*
*   Accessor; This method will return numerator

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: none

***************************************************************/
/****************************************************************
* int getDenom() const;
*
*   Accessor; This method will return denominator

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: none

***************************************************************/

/****************************************************************
* void display() const;
*
*   Accessor; This method will display a given rational

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: none

***************************************************************/

/****************************************************************
* bool operator>= (const Rational & input);
*
*   Accessor; This method will compare the input object and
*           in-class object

* --------------------------------------------------------------
*   Parameters:
*       Rational & input: input object

* --------------------------------------------------------------
*   Return: true/false

***************************************************************/

/****************************************************************
* bool operator> (const Rational & input);
*
*   Accessor; This method will compare the input object and
*           in-class object

* --------------------------------------------------------------
*   Parameters:
*       Rational & input: input object

* --------------------------------------------------------------
*   Return: true/false

***************************************************************/

/****************************************************************
* bool operator< (const Rational & input);
*
*   Accessor; This method will compare the input object and
*           in-class object

* --------------------------------------------------------------
*   Parameters:
*       Rational & input: input object

* --------------------------------------------------------------
*   Return: true/false

***************************************************************/

/****************************************************************
* bool operator== (const Rational & input);
*
*   Accessor; This method will compare the input object and
*           in-class object

* --------------------------------------------------------------
*   Parameters:
*       Rational & input: input object

* --------------------------------------------------------------
*   Return: true/false

***************************************************************/




#endif //ending rational_h constant definition
