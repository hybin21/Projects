#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "personData.h"

/****************************************************************
 * CustomerData Class
 *   This class is a subclass of personData and conatins the 
 *  customer number as well as the mailing list
 ***************************************************************/
class CustomerData : public PersonData
{
    private:
        int customerNumber;                 //IN&OUT - Contains
                                            //the customer's #
        bool mailingList;                   //IN&OUT - Contains
                                            //the customer's 
                                            //mailing list
    public:
        /******************************
        ** CONSTRUCTOR & DESTRUCTOR ** 
        ******************************/
        CustomerData();
        CustomerData(const string last,     //IN&OUT - Contains
                                            //the customer's 
                                            //first name
                 const string first,        //IN&OUT - Contains
                                            //the customer's 
                                            //last name                                   
                 const string addy,         //IN&OUT - Contains
                                            //the customer's 
                                            //address
                 const string city_name,    //IN&OUT - Contains
                                            //the customer's 
                                            //city name
                 const string state_name,   //IN&OUT - Contains 
                                            //the customer's
                                            //state name
                 const int code,            //IN&OUT - Contains
                                            //the customer's 
                                            //zip code
                 const string phoneNum,     //IN&OUT - Contains
                                            //the customer's 
                                            //phone number
                 const int number,          //IN&OUT - Contains
                                            //the customer's 
                                            //number 
                  const bool list);         //CALC - Determines
                                            //if the customer 
                                            //in on the list


        /*************** 
        ** ACCESSORS ** 
        ***************/
        int get_customerNumber() const;     
        bool get_mailingList() const;

        /*************** 
        ** MUTATORS  ** 
        ***************/
        void set_customerNumber
        (const int number);                 //IN&OUT - Contains
                                            //the customer's 
                                            //number
        void set_mailingList
        (const bool list);                  //CALC - Determines
                                            //if the customer 
                                            //in on the list
};
#endif

/******************************
** CONSTRUCTOR & DESTRUCTOR ** 
******************************/

/****************************************************************
* CustomerData();
*   Constructor; Initializes default class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* CustomerData(const string last, const string first, 
               const string addy, const string city_name, 
               const int code, const string phoneNum,   
               const int number, const bool list);
*   Constructor; Initializes class attributes
*   Parameters: 
      string last: Contains the last name
      string first: Contains the first name
      string addy: Contains the address
      string city_name: Contains the city name
      int code: Contains the zip code
      string phoneNum: Contains the phone number
      int number: Contains the customer's number
      bool list: Determines whether customer is on the list
*   Return: none
***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* int get_customerNumber() const;
*
*   Accessor; This method returns the customer's number
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's number
***************************************************************/

/****************************************************************
* bool get_mailingList() const;
*
*   Accessor; This method returns whether or not the customer
*             is on the list
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: true or false boolean value
***************************************************************/

/***************
** MUTATORS  **
***************/

/****************************************************************
* void set_customerNumber(const int number);
*
*   Accessor; This method sets the customer's number to the
*             number given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        int number: The number to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_mailingList(const bool list);
*
*   Accessor; This method sets the mailing list 
*             depending on if the parameter
* --------------------------------------------------------------
*   Parameters: 
*        bool list: Determines whether the customer is on
*                   the list or not
* --------------------------------------------------------------
*   Return: none
***************************************************************/
