#ifndef COMPLEX_H // chekcs if headerfile has been created before
#define COMPLEX_H // defines the distanc_h constant

#include<iostream>

using namespace std;

class Complex
{
  private:
    double a; // IN/OUT - represents real number
    double b; // IN/OUT - represetns imaginary number
  public:

    /*****************
    ** CONSTRUCTORS **
    *****************/
    Complex();          // Default constructor
    Complex(            // Constructor with two parameter
            double a    // IN - takes in real number
          , double b);  // IN - takes in imaginary number
    Complex(            // Construtor with one parameter
            double a);  // IN - takes in real number

    /***************
    **  Accessor  **
    ***************/
    const int operator==     // override == operator
          (const Complex &input) const; // IN - input to be compared
    const Complex operator+   // override + operator
          (const Complex &input) const; // IN - input to be added
    const Complex operator-   // override - operator
          (const Complex &input) const; // IN - input to be subtracted
    const Complex operator*   // override * operator
          (const Complex &input) const; // IN - input to be multiplied
    friend ostream &operator <<  // override << operator
          (ostream &outStream           // IN - output stream
          , const Complex &input);          // IN - complex number for output
    double returnReal() const;
    double returnImagin() const;
    bool operator>=(const Complex & input) const;   // IN - input
    bool operator>(const Complex & input) const;    // IN - input
    bool operator<(const Complex & input) const;    // IN - input


    /*********************
    **      MUTATORS   **
    *********************/
    friend istream &operator >>   // override >> operator
          (istream &inStream,     // IN - input stream
            Complex &input);      // IN - complex number for input
    void setValue(const double real,    // IN - real number
                const double imagin);   // IN - imagin number
    void setReal(const double real);    // IN - real number
    void setImain(const double imagin); // IN - imagin number

};
#endif

/****************************************************************
* Complex class
*   This class represents a complex number and allows you to
      perform basic mathematics with complex number.
      It manages real number and imaginary number parts
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* Complex();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* Complex(double a, double b);
*   Constructor; Initialize class attributes
*   Parameters:
*     first parameter: takes in real number part
*     second parameter: takes in imaginary number part
*   Return: none
***************************************************************/

/****************************************************************
* Complex(double a);
*   Constructor; Initialize class attributes
*   Parameters:
*     first parameter: takes in real number part
*   Return: none
***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* const int operator== (const Complex &input) const;
*
*   Accessor; This method will override == operator

* --------------------------------------------------------------
*   Parameters: const Complex &input: input Class(Complex) to
      be compared

* --------------------------------------------------------------
*   Return: return 1/2 if two complex numebs are equal

***************************************************************/

/****************************************************************
* const Complex operator+ (const Complex &input) const;
*
*   Accessor; This method will override + operator

* --------------------------------------------------------------
*   Parameters: const Complex &input: input Class(Complex) to
                be added

* --------------------------------------------------------------
*   Return: Complex class with calculated complex number

***************************************************************/

/****************************************************************
* const Complex operator- (const Complex &input) const;
*
*   Accessor; This method will override - operator

* --------------------------------------------------------------
*   Parameters: const Complex &input: input Class(Complex) to
                be subtracted

* --------------------------------------------------------------
*   Return: Complex with calcuated complex number

***************************************************************/

/****************************************************************
* const Constructor operator* (const Complex &input) const;
*
*   Accessor; This method will override * operator

* --------------------------------------------------------------
*   Parameters: const Complex &input: input Class(Complex) to
                be multiplied

* --------------------------------------------------------------
*   Return: Complex with calculated complex number

***************************************************************/

/****************************************************************
* friend ostream &operator << (ostream &outStream,
                              const Complex &input);
*
*   Accessor; This method will override << operator

* --------------------------------------------------------------
*   Parameters:
*     ostream &outStream: output stream
      const Complex &input: complex number for output

* --------------------------------------------------------------
*   Return: display complex number

***************************************************************/

/*********************
**      MUTATORS   **
*********************/

/****************************************************************
* friend istream &operator >> (istream &inStream, complex &input)
*
*   Mutators; This method will override >> operator

* --------------------------------------------------------------
*   Parameters:
        istream &inStream: input stream
        complex &input:complex number for input

* --------------------------------------------------------------
*   Return: nothing

***************************************************************/

/****************************************************************
*   void setValue(const double real,const double imagin)
*
*   Mutators; This method will set Value

* --------------------------------------------------------------
*   Parameters:
        const double real: real numner
        const double imagin: imagin number

* --------------------------------------------------------------
*   Return: nothing

***************************************************************/

/****************************************************************
*  void setReal(const double real);
*
*   Mutators; This method will set real number

* --------------------------------------------------------------
*   Parameters:
        const double real: real number

* --------------------------------------------------------------
*   Return: nothing

***************************************************************/

/****************************************************************
* void setImain(const double imagin)
*
*   Mutators; This method will set imainary number

* --------------------------------------------------------------
*   Parameters:
        const double imagin: imaginary number

* --------------------------------------------------------------
*   Return: nothing

***************************************************************/

