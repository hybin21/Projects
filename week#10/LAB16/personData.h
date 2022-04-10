#ifndef PERSONDATA_H
#define PERSONDATA_H

/****************************************************************
 * CustomerData Class
 *   This class is a subclass of personData and conatins the 
 *  customer number as well as the mailing list
 ***************************************************************/

#include<iostream>
using namespace std;

class PersonData
{
    private: 
        string lastName;   //IN - last name
        string firstName;  //IN - first name
        string address;    //IN - address
        string city;       //IN - city name
        string state;      //IN - stat name
        int zip;           //IN - zip code
        string phone;      //IN - phone number
    public:
        /******************
        ** CONSTRUCTOR ** 
        ******************/
        PersonData();
        PersonData(const string last,       //IN - last name
                   const string first,      //IN - first name
                   const string addy,       //IN - address
                   const string city_name,  //IN - city name
                   const string state_name, //IN - state name
                   const int code,          //IN - zipcode
                   const string phoneNum);  //IN - phone #
        /************
        ** MUTATOR ** 
        *************/      
        void set_lastName
        (const string last);                //IN - last name
        void set_firstName
        (const string first);               //IN - first name
        void set_address
        (const string addy);                //IN - address
        void set_cityName
        (const string cityName);            //IN - city name
        void set_stateName
        (const string stateName);           //IN - state name
        void set_code
        (const int code);                   //IN - zip code
        void set_phone
        (const string phoneNum);            //IN - phone #

       /**************
        ** ACCESSOR ** 
        **************/
        string get_lastName() const;
        string get_firstName() const;
        string get_address() const;
        string get_city() const;
        string get_stateName() const;
        int get_zip() const;
        string get_phone() const;

};
#endif

/******************
** CONSTRUCTOR ** 
******************/

/****************************************************************
* PersonData();
*   Constructor; Initializes default class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* CustomerData(const string last, const string first, 
               const string addy, const string city_name,
               const string state_name,const int code, 
               const string phoneNum, const int number, 
               const bool list);
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
*   Return: none
***************************************************************/

/***************
** MUTATORS  **
***************/

/****************************************************************
* void set_lastName(const string last)
*
*   Mutator; This method sets the customer's last name to the
             last name given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        const string last: The last name to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_firstName(const string first)
*
*   Mutator; This method sets the customer's first name to the
             last name given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        const string first: The first name to be set to 
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_address(const string addy);
*
*   Accessor; This method sets the customer's address to the
              address given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        const string addy: The address to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_cityName(const string city);
*
*   Accessor; This method sets the customer's city name to the
*             number given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*       const string city: The city name to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_stateName(const string stateName);
*
*   Accessor; This method sets the customer's state name to the
*             number given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        const string stateName: The state name to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_code(const int code);
*
*   Accessor; This method sets the customer's zip code to the
*             number given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        const int code: The zip code to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* void set_phone(const string phoneNum);
*
*   Accessor; This method sets the customer's phone number to the
*             number given in the parameter
* --------------------------------------------------------------
*   Parameters: 
*        const string phoneNum: The phone number to be set to
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* string get_lastName() const;
*
*   Accessor; This method returns the customer's lastname
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's lastname
***************************************************************/

/****************************************************************
* string get_firstName() const;
*
*   Accessor; This method returns the customer's firstname
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's firstname
***************************************************************/

/****************************************************************
* string get_address() const;
*
*   Accessor; This method returns the customer's address
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's address
***************************************************************/

/****************************************************************
* string get_cityName() const;
*
*   Accessor; This method returns the customer's city name
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's ciy name
***************************************************************/

/****************************************************************
* string get_stateName() const;
*
*   Accessor; This method returns the customer's state
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's state
***************************************************************/

/****************************************************************
* int get_zip() const;
*
*   Accessor; This method returns the customer's zipcode
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's zipcode
***************************************************************/

/****************************************************************
* string get_phone() const;
*
*   Accessor; This method returns the customer's phone number
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: the customer's phone number
***************************************************************/

