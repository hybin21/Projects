/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT 08  : Inheritance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 04/06/22
*******************************************************************************/

#ifndef DATE_H  // checks if headerfile has been created begfore
#define DATE_H  // defines the rational_h constant

#include<iostream>
#include<cctype>
#include<string>

using namespace std;

/*******************************************************************************
 *
 * Date class
 *_________________________________________________________________
 * <description>
 * This class performs basic computation for Date object 
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays Date object's data
 *
*******************************************************************************/

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
        Date();     
        Date(const Date & newDate);     // IN - newDate to be copied
        Date(unsigned m,        // IN - month of the date
                unsigned d,     // IN - day of the date
                unsigned y);    // IN - year of the date
        Date(const string &mn,  // IN - month name of the date
                unsigned d,     // IN - day of the date
                unsigned y);    // IN - year of the date   
       
        /***************
        ** ACCESSORS **
        ***************/    
        Date addDays(int numOfDays) const;  // IN - number of days to be added
        void printNumeric() const;  // print numerical date
        void printAlpha() const;    // print alphabetical date

        /************
        ** MUTATOR **
        *************/
        Date & operator=(const Date & newDate); // IN - newDate to be copied
        
    private:

        /***************
        ** ACCESSORS **
        ***************/
        bool isLeap(
                unsigned y) const; // IN - year to be checed for the leapYear
        unsigned daysPerMonth(unsigned m,  // IN - month of the date
                        unsigned y) const; // IN - year of the date
        string name(unsigned m) const;  // IN - month for the month name
        unsigned number(
                const string &mn) const; // IN - month name for the month

        
        


};
#endif

/****************************************************************
* Date Class
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
* Date(const Date & newDate)
*   Constructor; Initialize class attributes
*   Parameters: 
*       Date newDate: Date object should be defined
*   Return: none
***************************************************************/

/****************************************************************
* Date(unsinged m, unsigned d, unsigned y)
*   Constructor; Initialize class attributes
*   Parameters: first parameter: takes in month
                second parameter: takes in day 
                third parameter: takes in year
*   Return: none
***************************************************************/

/****************************************************************
* Date(const string &mn, unsigned d, unsigned y)
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
* void printAlpha() const;

*   Accessor; This method will pring the alphabeticl date

* --------------------------------------------------------------
*   Parameters: none

* --------------------------------------------------------------
*   Return: the alphabetical date
***************************************************************/

/************
** MUTATOR **
*************/

/****************************************************************
*  Date & operator=(const Date & newDate);

*   Mutator; This method will overload operator =
* --------------------------------------------------------------
*   Parameters: 
        Date newDate: Date object should be defined

* --------------------------------------------------------------
*   Return: copied Date object 
***************************************************************/