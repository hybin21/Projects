#ifndef DATE_H  // checks if headerfile has been created begfore
#define DATE_H  // defines the rational_h constant

#include<iostream>
#include<cctype>
#include<string>

using namespace std;

class Date
{
    private:
        unsigned day;   // IN&OUT - the date's day
        unsigned month; // IN&OUT - the date's month
        string monthName;   // IN&OUT - the date's monthname
        unsigned year;  // IN&OUT - the date's year
    public:

        /******************************
        ** CONSTRUCTOR & DESTRUCTOR **
        ******************************/
        Date();     // Default constructor
        Date(unsigned m,
                unsigned d, unsigned y);   // constructor with month(int)
        Date(const string &mn,
                unsigned d, unsigned y);     // constructor with monthname

        /***************
        ** ACCESSORS **
        ***************/
        Date addDays(int numOfDays) const;  // add days to current date
        void printNumeric() const;  // print numerical date
        void printAlpha() const;    // print alphabetical date
        unsigned returnDay()const;
        unsigned returnMonth() const;
        unsigned returnYear() const;
        bool operator>=(const Date& input); // IN - input object
        bool operator<(const Date & input); // IN - input object
        bool operator==(const Date & input);// IN - input object
        bool operator>(const Date & input); // IN - input object

        /*************
        ** MUTATOR **
        **************/
        void setValue(const int month,  // IN - month
                      const int day,    // IN - day
                      const int year);  // IN - yaer


    private:

        /***************
        ** ACCESSORS **
        ***************/
        bool isLeap(unsigned y) const;     // check is the year is leap year
        unsigned daysPerMonth(unsigned m,  // return the days per month
                                unsigned y) const;
        string name(unsigned m) const;  // convert to month name
        unsigned number(const string &mn) const; // convert to month(int)
        ;


};
#endif

/****************************************************************
* Distance Class
*   This class represents a date and allows you to perform
        basic conversion with dates. It maanges the day, month,
        monthName, and year of a date
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* Date();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* Distance(unsinged m, unsigned d, unsigned y)
*   Constructor; Initialize class attributes
*   Parameters: first parameter: takes in month
                second parameter: takes in day
                third parameter: takes in year
*   Return: none
***************************************************************/

/****************************************************************
* Distance(const string &mn, unsigned d, unsigned y)
*   Constructor; Initialize class attributes
*   Parameters: first parameter: takes in month name
                second parameter: takes in day
                third parameter: takes in year
*   Return: none
***************************************************************/



/***************
** ACCESSORS **
***************/

/****************************************************************
* bool isLeap(unsigned y) const
*
*   Accessor; This method will check if the year is
                leap year

* --------------------------------------------------------------
*   Parameters:
        unsigned y: the current year to be checked

* --------------------------------------------------------------
*   Return: true if the year is leap year, false if it's not

***************************************************************/

/****************************************************************
* unsigned daysPerMonth(unsinged m, unsinged y) const
*
*   Accessor; This method will return the days per month

* --------------------------------------------------------------
*   Parameters:
        unsinged m: the current month
        unsigned y: the current year

* --------------------------------------------------------------
*   Return: the days of the month

***************************************************************/

/****************************************************************
* string name(unsigned m) const
*
*   Accessor; this method will convert month into name

* --------------------------------------------------------------
*   Parameters:
        unsigned m: the month to find it's month name

* --------------------------------------------------------------
*   Return: return input's month name

***************************************************************/

/****************************************************************
* unsigned number(const string &mn) const;

*   Accessor; This method will return the month

* --------------------------------------------------------------
*   Parameters:
        const string &mn: the month name to find it's month

* --------------------------------------------------------------
*   Return: return input's month

***************************************************************/

/****************************************************************
* Date addDays(int numOfDays) const;
*
*   Accessor; This method will add numOfDays to the current
                date

* --------------------------------------------------------------
*   Parameters:
        int numOfDays: the number of days
                to be added to current days

* --------------------------------------------------------------
*   Return: Date class with new date

***************************************************************/

/****************************************************************
* void printNumeric() const;
*
*   Accessor; This method will print the numeric date

* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the numeric date

***************************************************************/

/****************************************************************
* void  const;

*   Accessor; This method will pring the alphabeticl date

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: the alphabetical date
***************************************************************/

/****************************************************************
*  unsigned returnDay()const

*   Accessor; This function returns day value
* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: day value
***************************************************************/

/****************************************************************
* void returnMonth() const;

*   Accessor; This method returns month value

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: month value
***************************************************************/

/****************************************************************
* void returnYear const;

*   Accessor; This method returns year value

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: year value
***************************************************************/

/****************************************************************
* bool operator>=(const Date& input);

*   Accessor; This method will override >= operator

* --------------------------------------------------------------
*   Parameters:
*       const Date& input: input object to be compared

* --------------------------------------------------------------
*   Return: true/fasle
***************************************************************/

/****************************************************************
* bool operator>(const Date& input);

*   Accessor; This method will override > operator

* --------------------------------------------------------------
*   Parameters:
*       const Date& input: input object to be compared

* --------------------------------------------------------------
*   Return: true/fasle
***************************************************************/

/****************************************************************
* bool operator<(const Date& input);

*   Accessor; This method will override < operator

* --------------------------------------------------------------
*   Parameters:
*       const Date& input: input object to be compared

* --------------------------------------------------------------
*   Return: true/fasle
***************************************************************/

/****************************************************************
* bool operator==(const Date& input);

*   Accessor; This method will override == operator

* --------------------------------------------------------------
*   Parameters:
*       const Date& input: input object to be compared

* --------------------------------------------------------------
*   Return: true/fasle
***************************************************************/

/*************
** MUTATOR **
**************/

/****************************************************************
* void setValue(const int month, const int day, const int year;

*   Mutator; This method set value of the object

* --------------------------------------------------------------
*   Parameters:
*       const int month: month input
*       const int day: day input
*       cost int year: year input

* --------------------------------------------------------------
*   Return: N/A
***************************************************************/
