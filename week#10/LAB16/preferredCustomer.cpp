#include "preferredCustomer.h"

/***********************************************************
* PreferredCustomer(): Class PreferredCustomer 
*_________________________________________________________ 
* This constructor is the default constructor
* that creates an object with purchaseAmount
* set to its default values.
* 
* Constructor, returns nothing. 
*_________________________________________________________ 
* PRE-CONDITIONS
* The following need previously defined values:
* There are no pre-conditions.
*
* POST-CONDITIONS
* This function will create an object with purchaseAmount
* set to 0.
***********************************************************/
PreferredCustomer::PreferredCustomer()
{
    purchaseAmount = 0;
}

/***********************************************************
* PreferredCustomer(const string last, const string first, 
               const string addy, const string city_name, 
               const int code, const string phoneNum,   
               const int number, const bool list, 
               const double amount);
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
*   string first: Contains the first name
*   string addy: Contains the address
*   string city_name: Contains the city name
*   int code: Contains the zip code
*   string phoneNum: Contains the phone number
*   int number: Contains the customer's number
*   bool list: Determines whether customer is on the list
*   double amount: Contains the amount the customer
*                  has spent
*
* POST-CONDITIONS
* This function will create an object that takes in 
* multiple parameters such as first name, last name, addy,
* etc and sets the object's member variables to such
***********************************************************/
PreferredCustomer::PreferredCustomer(
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
                const double amount)     //IN - purchase amount
                : CustomerData(last,first,addy,city_name,
                state_name,code,phoneNum,number,list),
                purchaseAmount(amount){}

/***********************************************************
* set_purchaseAmount(const double amount): 
* Class PreferredCustomer 
*_________________________________________________________ 
* This function sets the customer's purchase amount
  to amount
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    double amount: amount to be set to
*
* POST-CONDITIONS
*   This function will have set the purcahse amount to
*   amount
***********************************************************/
void PreferredCustomer::set_purchaseAmount(
              const double amount) //IN - purchase amount
{
  //Function does not return purchase amounts less than 0
  if(amount < 0)
  {
    return;
  }
  else
  {
    purchaseAmount = amount; 
  }
}

/***********************************************************
* sset_discountLevel(): 
* Class PreferredCustomer 
*_________________________________________________________ 
* This function sets the customer's discount level 
  depends on custoer's discount level
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    none
*
* POST-CONDITIONS
*   This function will have set cutomer's discount level
***********************************************************/
void PreferredCustomer::set_discountLevel()
{
  //If amount purchased is more or equal to 2000
  if(purchaseAmount>= 2000)
  {
    discountLevel = 0.1;     
  }
    //If amount purchased is more or equal to 1500
  else if(purchaseAmount >= 1500)
  {
   discountLevel = 0.07;     
  }
    //If amount purchased is more or equal to 1000
  else if(purchaseAmount >= 1000)
  {
    discountLevel = 0.06;     
  }
  //If amount purchased is more or equal to 500
  else if(purchaseAmount >= 500)
  {
    discountLevel = 0.05;     
  }
  //If amount purchased doesn't exceed 500
  else
  {
    discountLevel = 0;
  }
}

/***********************************************************
* get_purchaseAmount() const: 
* Class PreferredCustomer 
*_________________________________________________________ 
* This function returns the amount purchased
*   - Returns purchaseAmount
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the purchase amount
***********************************************************/
double PreferredCustomer::get_purchaseAmount() const
{
    return purchaseAmount;
}

/***********************************************************
* get_discountLevel() const: 
* Class PreferredCustomer 
*_________________________________________________________ 
* This function returns the amount of discount for the 
* customer.
*   - Returns discountLevel
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the discountLevel
***********************************************************/
double PreferredCustomer::get_discountLevel() const
{
    return discountLevel;
}