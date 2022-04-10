/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT #03 : DATE
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/02/22
*******************************************************************************/
#include "date.h"   // include date.h 

const string MONTH_LIST[] = {"January", "February", "March" // month list
                            , "April", "May", "June",
                            "July", "August", "September",
                             "October","November", "December"};
const int MONTH_NUM = 12;   // total number of months
const int REG_DAYS = 365;   // days of non-leap year
const int LEAP_DAYS = 366;  // days of leap year

/*******************************************************************************
 * Date() 
 *_________________________________________________________________
 *  description: constructor that sets month, day, year, 
 *              and month name of the date class 
 *              with date of 1(January)/1/2000;
 *               
 *  - returns the default Date object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   month, day, year, and month name should be predefined
 *   
 *
 * POSTCONDITIONS:
 *  initializes month to 1, day to 1, year to 2000, 
 *      and month name to january
 *
*******************************************************************************/
Date::Date()
{   
    // PROCESSING: initialization 
    this->month = 1;
    this->day = 1;
    this->year = 2000;
    this->monthName = "January";
}

/*******************************************************************************
 * Date::Date(unsigned m, unsigned d, unsigned y)
 *_________________________________________________________________
 *  description: constructor that sets month, day, and year 
 *               to ther respective parameters
 *               
 *  - returns the the new Date object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   month, day, and year should be predefined
 *   
 *
 * POSTCONDITIONS:
 *  initializes month, day, and year to the parameters
 *
*******************************************************************************/

Date::Date(unsigned m,      // IN/OUT - number of the month
           unsigned d,      // IN/OUT - number of the day
           unsigned y)      // IN/OUT - number of the year
{
    int count;              // CALC - used to check if the inputs are valid
    count = 0;
    
    // when month is bigger than 12
    if(m > 12)
    {
        count++;
        m = 12;
    }

    // when month is smaller than 0
    if(m <= 0)
    {
        count++;
        m = 1;
    }
    
    // when day is bigger than the maximum days of the month
    if(d > daysPerMonth(m,y))
    {
        count++;
        d = daysPerMonth(m,y);
    }

    // when day is smaller than 0
    else if(d <= 0)
    {
        count++;
        d = 1;
    }

    // initilization
    this->month = m;
    this->day = d;
    this->year = y;
    this->monthName += name(m);
    
    if(count != 0)
        cout << "Invalid date values: Date corrected to " 
            << this->month << "/" << d << "/" << y <<".\n";; 
    
}

/*******************************************************************************
 * Date::Date(const string &mn, unsigned d, unsigned y)
 *_________________________________________________________________
 *  description: constructor that sets month name, day, and year 
 *               to ther respective parameters
 *               
 *  - returns the the new Date object
 *_________________________________________________________________
 * PRECONDITIONS:
 *   month name, day, and year should be predefined
 *   
 *
 * POSTCONDITIONS:
 *  initializes month name, day, and year to the parameters
 *
*******************************************************************************/

Date::Date(const string &mn,    // IN/OUT - name of the month
           unsigned d,          // IN/OUT - numebr of the day
           unsigned y)          // IN/OUT - number of the year
{
    int m;                // CALC&OUT - number of the month
    int count;            // CALC - used to check if the inputs are valid
    bool valid;          // CALC - used to check if the month name is valid
    string monthName;     // CALC - temporary month name to check the input

    count = 0;
    valid = true;
    monthName += mn;

    // set mn with first leter capital and rest of the letters lower
    for(int i = 0; i < mn.length(); i++)
    {
        if(i == 0)
            monthName[i] = toupper(monthName[i]);   
        else
            monthName[i] = tolower(mn[i]);
    }
    
    // check if the mn is valid
    for(int i = 0; i < MONTH_NUM; i++)
    {
        if(MONTH_LIST[i] == monthName)
        {
            m = number(monthName);
            this->monthName += MONTH_LIST[i];
            count++;
            break;
        }
    }   
    // if mn is invalid
    if(count == 0)
    {
        // initializtion
        this->month = 1;
        this->year = 2000;
        this->day = 1; 
        this->monthName += name(1);
        cout << "Invalid month name: the Date was set to " 
            << this->month << "/" << this->day 
            << "/" << this->year << ".\n"; 
        valid = false;
    }

    count = 0;

    // if the month name is valid, check the rest of the variable 
    if(valid)
    {
        //  if the day is bigger than the maximum days of the month
        if(d > daysPerMonth(m,y))
        {
             count++;
            // set d valud to the maximum day of the month
            d = daysPerMonth(m,y);
        }

        // if the day is negative
        else if(d <= 0)
        {
            count++;

            // set d value to 1
            d = 1;
        }

        // initialization
        this->month = m;
        this->day = d;
        this->year = y;

        if(count != 0)
            cout << "Invalid date values: Date corrected to " 
            << this->month << "/" << this->day << "/" << this->year <<".\n";
    }
}

/*******************************************************************************
 * Date addDays(int numOfDays) const
 *_________________________________________________________________
 *  description: function add numOfDays to the current date
 *               
 *  - returns the new date
 *_________________________________________________________________
 * PRECONDITIONS:
 *   int numOfDays: the days to be added to the current date
 *   
 *
 * POSTCONDITIONS:
 *  added date
 *
*******************************************************************************/
Date Date::addDays(int numOfDays) const // IN - number of days to be added
{
    Date newDate;       // CALC/OUT - the date class to store a new date
    int currentMonth;   // CALC - current month
    int currentYear;    // CALC - current year
    int currentDay;     // CALC - current day
    bool check;         // CALC - check until the numOfDays  is all added

    check = true;
    currentMonth = this->month;
    currentYear = this->year;
    currentDay = this->day;

    // when adding the days
    if(numOfDays > 0)
    {
        while(check)
        {   
            // if currentYear is a leap year
            if(isLeap(currentYear))
            {   
                if(numOfDays >= LEAP_DAYS)
                {
                    currentYear++;
                    numOfDays -= LEAP_DAYS;
                }
            }

            // if currentYear is a non-leap year
            else
            {
                if(numOfDays >= REG_DAYS)
                {
                    numOfDays -= REG_DAYS;
                    currentYear++;
                }
            }    
            
            // if the numOfdays is smaller than 365 and bigger than days for month
            if(numOfDays > daysPerMonth(currentMonth, currentYear) 
                && numOfDays < REG_DAYS)
            {
                numOfDays -= daysPerMonth(currentMonth,currentYear);
                currentMonth++;

                // set month to 1 and add one more year to the current year 
                if(currentMonth > MONTH_NUM)
                {
                    currentYear++;
                    currentMonth = 1;
                }
            }
            
            // when the numOfDays is smaller than days for month
            else if(numOfDays < daysPerMonth(currentMonth, currentYear))
            {   
                currentDay += numOfDays;
                if(currentDay > daysPerMonth(currentMonth, currentYear))
                {
                    currentMonth++;
                    currentDay -= daysPerMonth(currentMonth,currentYear);
                }
                
                // stop adding the days
                check = false;
            }
            
        }
    }

    // when subtracting the days 
    else
    {
        while(check)
        {   
            // if the current year is leap year
            if(isLeap(currentYear))
            {
                if(abs(numOfDays) >= LEAP_DAYS)
                {
                    currentYear--;
                    numOfDays += LEAP_DAYS;
                }
            }
            
            // if the current year is non-leap year
            else
            {
                if(abs(numOfDays) >= REG_DAYS)
                {
                    currentYear--;
                    numOfDays += REG_DAYS;
                }
            }    

            // subtract months
            if(abs(numOfDays) > daysPerMonth(currentMonth, currentYear))
            {
                if((isLeap(currentYear) && abs(numOfDays) <= LEAP_DAYS) 
                ||(isLeap(currentYear) == false 
                && abs(numOfDays) <= REG_DAYS))
                {
                    numOfDays += daysPerMonth(currentMonth,currentYear);
                    currentMonth--;
                    
                    //set month to 12 and subtract one year 
                    if(currentMonth <= 0)
                    {
                        currentYear--;
                        currentMonth = 12;
                        
                    }
                }
            }
            // subtract days
            else if(abs(numOfDays) < daysPerMonth(currentMonth, currentYear))
            {   
                currentDay += numOfDays;

                // when current day is negative
                if(currentDay <= 0)
                {
                    currentMonth--;
                    currentDay += (daysPerMonth(currentMonth,currentYear)+1);

                    // when current month is negtaive
                    if(currentMonth <= 0)
                    {
                        currentYear--;
                        currentMonth= 12;
                    }
                }

                // stop subtracting days 
                check = false;
            }
            
        }
    }

    // initialization
    newDate.year = currentYear;
    newDate.month = currentMonth;
    newDate.day = currentDay;
    newDate.monthName = name(newDate.month);
   

    return newDate;
}

/*******************************************************************************
 * void printNumeric() const
 *_________________________________________________________________
 *  description: this method will print he nemeric date
 *               
 *  - returns the numeric date
 *_________________________________________________________________
 * PRECONDITIONS:
 *   the month, day, and year should be initialized
 *
 * POSTCONDITIONS:
 *  the user can see the current date
 *
*******************************************************************************/

void Date::printNumeric() const
{
    // display the numeric date
    cout << this->month << "/" << this->day << "/" << this->year;
}

/*******************************************************************************
 * void printAlpha() const
 *_________________________________________________________________
 *  description: this method will print he alphatical date
 *               
 *  - returns the alphabetical date
 *_________________________________________________________________
 * PRECONDITIONS:
 *   the month name, day, and year should be initialized
 *
 * POSTCONDITIONS:
 *  the user can see the current date
 *
*******************************************************************************/

void Date::printAlpha() const
{
    // display the alphabetical date
    cout << this->monthName << " " << this->day << ", " << this->year;
}

/*******************************************************************************
 * bool Date::isLeap(unsigned y) const
 *_________________________________________________________________
 *  description: this method will check if the year is leap year
 *               
 *  - returns true if the year is leap year, false if it's not
 *_________________________________________________________________
 * PRECONDITIONS:
 *   unsigned y: the year to be checked
 *
 * POSTCONDITIONS:
 *  the program knows if the year is leap year or not
 *
*******************************************************************************/

bool Date::isLeap(unsigned y) const // year to be checkd if its leap year
{
    if(y % 4 == 0)
    {
        if(y % 100 == 0)
        {
            if(y % 400 == 0)
                return true;
            else    
                return false;
        }
        else
            return true;
    }
    return false;
}

/*******************************************************************************
 * unsigned daysPerMonth(unsigned m, unsigned y) const
 *_________________________________________________________________
 *  description: this method will return the days per month
 *               
 *  - returns the days of the month
 *_________________________________________________________________
 * PRECONDITIONS:
 *   unsinged m: find its days
 *   unsigned y: the year to see if it's leap year
 *
 * POSTCONDITIONS:
 *  the program knows how many days does the month have
 *
*******************************************************************************/

unsigned Date::daysPerMonth(unsigned m,    // IN - number of month
                             unsigned y) const  // IN - numebr of year
{
    // when month is 2 and year is leap year
    if(m == 2 && isLeap(y))
        return 29;
    
    // when month is 2
    else if(m == 2 && isLeap(y) == false)
        return 28;
    
    // when month is among months with 30 days
    else if(m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    
    // when month is among months with 31 days
    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 ||
            m == 10 || m == 12)
        return 31;
    return 0;
}

/*******************************************************************************
 * string name(unsigned m) const
 *_________________________________________________________________
 *  description: this method will convert month into name
 *               
 *  - returns month name corresponding to the month(input)
 *_________________________________________________________________
 * PRECONDITIONS:
 *   unsinged m: month to be converted to namme
 *
 * POSTCONDITIONS:
 *  program knows the name of the month
 *
*******************************************************************************/

string Date::name(unsigned m) const     // IN - month to be converted to name
{
    
    return MONTH_LIST[m-1];
}

/*******************************************************************************
 * unsigned number(const string &mn) const
 *_________________________________________________________________
 *  description: this method will convert month name to month
 *               
 *  - returns month corresponding to the month name(input)
 *_________________________________________________________________
 * PRECONDITIONS:
 *   const string &mn: month name to be converted to month
 *
 * POSTCONDITIONS:
 *  program knows the number of the month
 *
*******************************************************************************/

unsigned Date::number(const string &mn) const
{
    // find the month in MONTH_NUM array
    for(int i = 0; i < MONTH_NUM; i++)
    {
        // when the mn is found in the array, return the month
        if(mn == MONTH_LIST[i])
          return i+1;    
    }
    return 0;
}