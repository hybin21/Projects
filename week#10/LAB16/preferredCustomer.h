#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H
#include "customerData.h"

/****************************************************************
 * CustomerData Class
 *   This class is a subclass of personData and conatins the 
 *  customer number as well as the mailing list
 ***************************************************************/

class PreferredCustomer : public CustomerData
{
    private:
        double purchaseAmount;
        double discountLevel;
    public:
       /******************
        ** CONSTRUCTOR ** 
        ******************/
        PreferredCustomer();
        PreferredCustomer(
                 const string last,       //IN - last name
                const string first,      //IN - first name
                const string addy,       //IN - address
                const string city_name,  //IN - city name
                const string state_name, //IN - state name
                const int code,          //IN - zipcode
                const string phoneNum,   //IN - phone #
                const int number,        //IN - customer number
                const bool list,         //IN - customer's wish 
                                         //to be on the 
                                         //mailing list
                const double amount);    //IN - purchase amount

        /************
        ** MUTATOR ** 
        *************/      
        void set_purchaseAmount(
                  const double amount);  // IN - purchase amount
        void set_discountLevel();  

        /**************
        ** ACCESSOR ** 
        **************/
        double get_purchaseAmount() const;
        double get_discountLevel() const;

};
#endif
/******************
** CONSTRUCTOR ** 
******************/

/****************************************************************
* PreferredCustomer();
*   Constructor; Initializes default class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* PreferredCustomer(const string last, const string first, 
               const string addy, const string city_name,
               const string state_name,const int code, 
               const string phoneNum, const int number, 
               const bool list,const doubel amount);
*   Constructor; Initializes class attributes
*   Parameters: 
      string last: Contains the last name
      string first: Contains the first name
      string addy: Contains the address
      string city_name: Contains the city name
      string state_name:: Contains the state name 
      int code: Contains the zip code
      string phoneNum: Contains the phone number
      int number: Contains the customer's number
      bool list: Determines whether customer is on the list
      double amount: Amount that customer purchased
*   Return: none
***************************************************************/

/***************
** MUTATORS  **
***************/

/****************************************************************
* void set_purchaseAmount(const double amount)
*
*   Mutator; This method sets the customer's purchase amount
            to the amount given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*       double amount: the amount to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_discountLevel()
*
*   Mutator; This method sets the customer's discount level 
              depends on the purchase amount
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* double get_purchaseAmount();
*
*   Accessor; This method returns the customer's purchase amount
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's purchase amount
***************************************************************/

/****************************************************************
* string get_lastName() const;
*
*   Accessor; This method returns the customer's lastname
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's lastname
***************************************************************/