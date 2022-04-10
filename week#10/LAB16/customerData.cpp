#include "customerData.h"

/***********************************************************
* Constructor CustomerData(): Class CustomerData 
*_________________________________________________________ 
* This constructor is the default constructor
* that creates an object with PersonData(), 
* customerNumber(0), and mailingList() set to their
* default values.
* 
* Constructor, returns nothing. 
*_________________________________________________________ 
* PRE-CONDITIONS
* The following need previously defined values:
* There are no pre-conditions.
*
* POST-CONDITIONS
* This function will create an object with PersonData(), 
* customerNumber(0), and mailingList() set to their
* default values.
***********************************************************/
CustomerData::CustomerData(): PersonData(), 
            customerNumber(0),mailingList(false){}

/***********************************************************
* CustomerData(const string last, const string first, 
               const string addy, const string city_name, 
               const int code, const string phoneNum,   
               const int number, const bool list);
*_________________________________________________________ 
* This constructor creates an object that takes in 
* multiple parameters such as first name, last name, addy,
* etc and sets the object's member variables to such
* 
* Constructor, returns nothing. 
*_________________________________________________________ 
* PRE-CONDITIONS
* The following need previously defined values:
*   string last: Contains the last name
    string first: Contains the first name
    string addy: Contains the address
    string city_name: Contains the city name
    int code: Contains the zip code
    string phoneNum: Contains the phone number
    int number: Contains the customer's number
    bool list: Determines whether customer is on the list
*
* POST-CONDITIONS
* This function will create an object that takes in 
* multiple parameters such as first name, last name, addy,
* etc and sets the object's member variables to such
***********************************************************/
CustomerData::
CustomerData(const string last,        //IN&OUT - Contains
                                       //the customer's 
                                       //first name
             const string first,       //IN&OUT - Contains
                                       //the customer's 
                                       //last name                                   
             const string addy,        //IN&OUT - Contains
                                       //the customer's 
                                       //address
             const string city_name,   //IN&OUT - Contains
                                       //the customer's 
                                       //city name
            const string state_name,   // IN&OUR- Contains
                                       // the customer's 
                                       // state name
             const int code,           //IN&OUT - Contains
                                       //the customer's 
                                       //zip code
             const string phoneNum,    //IN&OUT - Contains
                                       //the customer's 
                                       //phone number
             const int number,         //IN&OUT - Contains
                                       //the customer's 
                                       //number 
             const bool list)          //CALC - Determines
                                       //if the customer 
                                       //in on the list)
 : PersonData(last,first,addy,city_name,state_name,code,phoneNum),
 customerNumber(number), mailingList(list){}


/***********************************************************
* set_customerNumber(const int number): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer number to number
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     int number: number to be set to
*
* POST-CONDITIONS
*   This function will have set the customerNumber to
*   number
***********************************************************/
void CustomerData::set_customerNumber
(const int number)                        //IN - Number to
                                          //be set to
{
    customerNumber = number;
}

/***********************************************************
* set_mailingList(const bool list): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the mailingList to true or false
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     bool list: boolean value to see if on list or not
*
* POST-CONDITIONS
*   This function will have set the mailingList to
*   true or false
***********************************************************/
void CustomerData::set_mailingList
(const bool list)                        //IN - Determines
                                         //whether customer 
                                         //is on the list
{
    mailingList = list;
}

/***********************************************************
* get_customerNumber(): 
* Class CustomerData 
*_________________________________________________________ 
* This function returns the customer's number
*   - Returns the customer number
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     - none
*
* POST-CONDITIONS
*   This function will return the customerNumber
***********************************************************/
int CustomerData::get_customerNumber() const
{
    return customerNumber;
}

/***********************************************************
* get_mailingList(): 
* Class CustomerData 
*_________________________________________________________ 
* This function returns the customer's number
*   - Returns the mailing list
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     - none
*
* POST-CONDITIONS
*   This function will return the mailingList
***********************************************************/
bool CustomerData::get_mailingList() const
{
    return mailingList;
}