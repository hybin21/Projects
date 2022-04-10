/*******************************************************************************
 * AUTHOR            : Jesse Tzo, Jessica Hahm
 * LAB #16           : Specifications
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 03/25/22
*******************************************************************************/
#include <iostream>
#include "personData.h"
#include "preferredCustomer.h"
#include "customerData.h"
using namespace std;

int main()
{
  PreferredCustomer customer;                   //CALC - Object to be testing
                                                //functions on
  //PERSONDATA TEST:
  cout << "Testing personData--> \n";
  //Test Phone
  customer.set_phone("6242455132");
  cout << "Phone Number: " << customer.get_phone()<<endl;

  //Test Zip
  customer.set_code(91007);
  cout<< "Zip: " << customer.get_zip()<<endl;

  //Test First Name
  customer.set_firstName("Jessica");
  cout<< "First Name: " << customer.get_firstName()<<endl;

  //Test Last Name
  customer.set_lastName("Hahm");
  cout<< "Last Name: " << customer.get_lastName()<<endl;

  //Test City
  customer.set_cityName("Arcadia");
  cout<< "City: " << customer.get_city() << " ";

  //Test State
  customer.set_stateName("California");
  cout << endl << "State: " << customer.get_stateName();

  //Test Address
  customer.set_address("Pasadena City College");
  cout<< endl << "Address: "<<customer.get_address()<<endl;
  cout << endl;

  //CUSTOMERDATA TEST
  cout << "Testing customerData--> \n";
  //Test customer number
  customer.set_customerNumber(290142);
  cout << "Customer Number: "<< customer.get_customerNumber() << endl;

  //Test mailing list
  cout << "Testing mailing list: ";
  customer.set_mailingList(true);
  if (customer.get_mailingList())
  {
    cout << "Customer is on mailing list \n";
  }
  else
  {
    cout << "Customer is not on mailing list \n";
  }

  //PREFERRED CUSTOMER TEST
  cout << "Testing preferredCustomer--> \n";
  //Test purchase amount
  customer.set_purchaseAmount(500);
  cout << "Purchase amount: " <<   customer.get_purchaseAmount() << endl;

  //Test discount
  customer.set_discountLevel();
  cout << "Discount Level: "; 
  if (customer.get_discountLevel() == 0.05)
  {
    cout << "5% \n";
  }
  else if (customer.get_discountLevel() == 0.06)
  {
    cout << "6% \n";
  }
  else if (customer.get_discountLevel() == 0.07)
  {
    cout << "7% \n";
  }
  else 
  {
    cout << "10% \n";
  }
}