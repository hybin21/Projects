  #include "personData.h"

/***********************************************************
* PersonData(): Class PersonData 
*_________________________________________________________ 
* This constructor is the default constructor
* that creates an object with  lastName(""),
* firstName(""),address(""),city(""),zip(0),phone("")
* set to their default values.
* 
* Constructor, returns nothing. 
*_________________________________________________________ 
* PRE-CONDITIONS
* The following need previously defined values:
* There are no pre-conditions.
*
* POST-CONDITIONS
* This function will create an object with lastName(""),
* firstName(""),address(""),city(""),zip(0),phone("")
* set to their default values.
***********************************************************/

PersonData::PersonData():
            lastName(""),firstName(""),address(""),
            city(""),zip(0),phone(""){}

/***********************************************************
* PersonData(const string last, const string first,
            const string addy, const strin ciy_name,
            const string state_name, const int code,
            const string phoneNum): Class PersonData 
*_________________________________________________________ 
* This constructor is the constructor
* that creates an object with  lastName(last),
* firstName(first),address(addy),city(city_name),zip(code)
* ,phone(phoneNum)set to their own values.
* 
* Constructor, returns nothing. 
*_________________________________________________________ 
* PRE-CONDITIONS
* The following need previously defined values:
*   const string last: last name
    const string first: first name
    const string addy: address
    const string city_name: city name
    const string state_name: tate name
    const int code: zipcode
    const string phoneNum): phone numbe
*
* POST-CONDITIONS
* This function will create an object with lastName(last),
* firstName(first),address(addy),city(city_name),zip(code)
* ,phone(phoneNum)set to their own values.
***********************************************************/
PersonData::PersonData(const string last, //IN - last name
                 const string first,      //IN - first name
                 const string addy,       //IN - address
                 const string city_name,  //IN - city name
                 const string state_name, //IN - state name
                 const int code,          //IN - zipcode
                 const string phoneNum)   //IN - phone 
                                          //number
                 : lastName(last), firstName(first),
                 address(addy),
                 city(city_name),state(state_name),
                 zip(code), phone(phoneNum){}

/***********************************************************
* set_lastName(const string last): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer's lastname to last
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    string last: last name to be set to
*
* POST-CONDITIONS
*   This function will have set the last name to
*   last
***********************************************************/
void PersonData::set_lastName(
            const string last)   //IN - last name to be set
{
  lastName = last;
}

/***********************************************************
* set_firstName(const string first): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer's first name to last
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    string first: first name to be set to
*
* POST-CONDITIONS
*   This function will have set the first name to
*   first
***********************************************************/
void PersonData::set_firstName(
            const string first)  //IN = first name to be set
{
  firstName = first;
}

/***********************************************************
*set_address(const string addy): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer's address to address
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    string addy: address to be set to
*
* POST-CONDITIONS
*   This function will have set the address to
*   addy
***********************************************************/
void PersonData::set_address(
            const string addy)  //IN - address to be set
{
  address = addy;
}

/***********************************************************
* set_cityName(const string cityName): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer's city name to cityName
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    string cityName: city name to be set to
*
* POST-CONDITIONS
*   This function will have set the customerNumber to
*   number
***********************************************************/
void PersonData::set_cityName(
          const string cityName)  //IN - city name to be set
{
    city = cityName;
}

/***********************************************************
* set_stateName(const string stateName): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer's state name to sateName
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    string stateName: state name to be set to
*
* POST-CONDITIONS
*   This function will have set the state name to
*   stateName
***********************************************************/
void PersonData::set_stateName(
        const string stateName) //IN - state name to be set
{
  state = stateName;
}

/***********************************************************
* set_code(const int code): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the customer's zip code to code
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    int code: zip code to be set to
*
* POST-CONDITIONS
*   This function will have set zip to code
***********************************************************/
void PersonData::set_code(
            const int code)  // IN - zip code to be set
{
  zip = code;
}

/***********************************************************
* set_phone(const string phoneNum): 
* Class CustomerData 
*_________________________________________________________ 
* This function sets the phone number to phoneNum given
* in the parameter.
*   - Returns nothing
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*    const string phoneNum: the phone number to be set to
*
* POST-CONDITIONS
*   This function will have set the customer's phone to
*   phoneNum
***********************************************************/
void PersonData::set_phone(const string phoneNum)
{
  phone = phoneNum;
}

/***********************************************************
* get_lastName() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the last name
*   - Returns lastName
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the last name
***********************************************************/
string PersonData::get_lastName() const
{
  return lastName;
}

/***********************************************************
* get_firstName() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the first name
*   - Returns firstName
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the first name
***********************************************************/
string PersonData::get_firstName() const
{
  return firstName;
}

/***********************************************************
* get_address() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the address
*   - Returns address
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the address
***********************************************************/
string PersonData::get_address() const
{
  return address;
}

/***********************************************************
* get_city() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the city name
*   - Returns city
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the city name
***********************************************************/
string PersonData::get_city() const
{
  return city;
}

/***********************************************************
* get_stateName() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the state 
*   - Returns state
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the phone number
***********************************************************/
string PersonData::get_stateName() const
{
  return state;
}

/***********************************************************
* get_zip() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the zip number
*   - Returns zip
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the zip number
***********************************************************/
int PersonData::get_zip() const
{
  return zip;
}

/***********************************************************
* get_phone() const: 
* Class personData 
*_________________________________________________________ 
* This function returns the phone number
*   - Returns phone
*_________________________________________________________ 
* PRE-CONDITIONS
*   The following need previously defined values:
*     -none
*
* POST-CONDITIONS
*   This function will return the phone number
***********************************************************/
string PersonData::get_phone() const
{
  return phone;
}