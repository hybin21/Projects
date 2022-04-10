/*****************************************************************************
 * AUTHOR   : Jesse Tzo & Jessica Hahm
 * LAB #1   : Roman Numerals
 * CLASS    : CS 3A
 * SECTION  : 32276
 * DUE DATE : 1/12/22
*****************************************************************************/
#include <iostream>∑
using namespace std;

/*****************************************************************************
* CONVERTING ROMAN NUMERALS

* This program converts a positive integer into Roman numerals, or regular numbers into Roman numerals.

* INPUT:
    int choice: Receieves either type 1 or type 2 from the user to determine regular number to roman numeral or vise versa.
    
    int regNum: The regular number the user inputs into the program (when the choice is 1).

    int roman: The roman number the user inputs into the program (when the choice is 2).

* OUTPUT:
    int roman: The roman number that outputs after being translated by the program (when the choice is 1).

    string regNum: The regular number that outputs after being translated by the program (when the choice is 2).


******************************************************************************/

// FUNCTION PROTOTYPES
/*****************************************************************************
 * menu
 * This function receives nothing and let the user choose the conversion(roman->regular/ regular->roman)
  - returns user's choice(1(roman=->regular) or 2(regular->roman))
------------------------------------------------------------------------------
PRE-CONDITIONS
  N/A
POST-CONDITIONS
  This function will ouptut user's choice
*****************************************************************************/
int menu(void); 

/*****************************************************************************
 * getRegularNumber
 * This function get regular number from the user
  - returns regular number from the user
------------------------------------------------------------------------------
PRE-CONDITIONS
  N/A
POST-CONDITIONS
  This function will output the regular number from the user
*****************************************************************************/
int getRegularNumber(void);

/*****************************************************************************
 * findDigits
 * This function receives regular number from the user break the regular number from the user into 4 digits(thousands, hundreds, tens, and ones)
 * change the value of the thousands, hundreds, tens, and ones in main function by using call-by-reference variables
------------------------------------------------------------------------------
PRE-CONDITIONS
  the following need previously defined values:
    regNum: regular number from the user and the value is not changed
    thousands: regular number's thousands place
    hundreds: regular number's hundreds place
    tens: regular number's tens place
    ones: regular number's ones place
POST-CONDITIONS
  This function will output thousands, hundreds, tens, and ones place of the regular number
*****************************************************************************/
void findDigits(const int regNum, int& thousands, int& hundreds, int& tens, int& ones);

/*****************************************************************************
 * roman_digit
 * This function receives digit(thousands/hundreds/tens/ones) and three strings(one, five,and ten) to convert regular number to roman numeral 
  - returns converted roman numeral
------------------------------------------------------------------------------
PRE-CONDITIONS
  the following need previously defined values:
    n: digit type(thousands/hundreds/tens/ones)
    one: the smallest digit of digit type(I or X or C)
    five: the next smallest digit of digit type(V or L or D)
    ten: the biggest digit of digit type(X or C or M)
POST-CONDITIONS
  This function will ouptut converted roman numeral 
*****************************************************************************/
string roman_digit(int n, string one, string five, string ten);

/*****************************************************************************
 * getRomanNumber
 * This function gets roman number from the user
  - returns roman numeral form the user
------------------------------------------------------------------------------
PRE-CONDITIONS
  N/A
POST-CONDITIONS
  This function will ouptut the roman numeral from the user 
*****************************************************************************/
string getRomanNumeral(void);

/*****************************************************************************
 * checkRoman
 * This function receives roman numeral from the user, three characters(one, five, and ten) to check if the roman numeral is valid
  - returns 1 if the input is valid, and return 0 if it's not
------------------------------------------------------------------------------
PRE-CONDITIONS
 The following need previosly defined values:
  roman: roman numeral from the user
  one: the smallest digit of digit type(I or X or C)
  five: the next smallest digit of digit type(V or L or D)
  ten: the biggest digit of digit type(X or C or M)
POST-CONDITIONS
  This function will output the 1 if the input is valid, and 0 if it's not
*****************************************************************************/
int checkRoman(string roman, char one, char five, char ten);

/*****************************************************************************
 * roman_to_digit
 * This function receives roman numeral from the user and convert the roman numeral to regular number
  - returns converted regular number 
PRE-CONDITIONS
  The following need previosly defined values:
    romanNum: roman numeral from the user
POST-CONDITIONS
  The function will ouptut converted regular number
*****************************************************************************/
int roman_to_digit(string romanNum);

int main() {
  int choice; // INPUT - the choice entered by the user
  int regNum; // INPUT - the regular number enterd by the user(when the choice is 1) or OUTPUT - the converted regular number(when the choice is 2)
  int thousands;  // CALC&OUT - output of finding each digt(thousands)
  int hundreds; // CALC&OUT - output of finding each digit(hundreds)
  int tens; // CALC&OUT - output of finding each digit(tens)
  int ones; // CALC&OUT - output of finding each digit(ones)
  int check1; // CALC&OUT - ouput of checking ones(I,V,X)
  int check2; // CALC&OUT - output of checking tens(X,L,C)
  int check3; // CALC&OUT - output of checking hundreds(C,D,M)
  string roman_ones;  // CALC&OUT - output of conversion of ones(regular number) to roman numeral
  string roman_tens;  // CALC&OUT - output of conversion of tens(regular number) to roman numeral
  string roman_hundreds;  // CALC&OUT - output of conversion of hunddreds(regular number) to roman numeral
  string roman_thousands; // CALC&OUT - output of conversion of thousands(regular number) to roman numeral
  string roman; // INPUT - the roman numeral entered by the user(When the choice is 2) or OUTPUT - the converted roman numeral(when the choice is 1)
  
  choice = menu();  // user choose the conversion 
  
  if(choice == 1) // tells program to translate regular number to roman numeral
  {
    regNum = getRegularNumber();
    findDigits(regNum, thousands, hundreds, tens, ones); // break the regular number into 4 digits
    roman_ones = roman_digit(ones, "I","V","X");  // convert ones place to roman numeral 
    roman_tens = roman_digit(tens,"X","L","C"); // convert tens place to roman numeral
    roman_hundreds = roman_digit(hundreds,  "C", "D", "M"); // convert hundreds to roman numeral 
    for(int i = 0; i < thousands; i++)  // convert thousands place to roman numeral
    {
      roman_thousands += "M";
    }
    roman += roman_thousands + roman_hundreds + roman_tens + roman_ones;  // add converted digits to one final roman numeral 
    cout << roman << endl;
  }
  
  else if(choice == 2)  // tells program to translate roman numeral to regular number
  {
    roman = getRomanNumeral();
    check1 = checkRoman(roman,'I','V','X'); // check ones place 
    check2 = checkRoman(roman,'X','L','C'); // check tens place
    check3 = checkRoman(roman,'C','D','M'); // check hundreds place
    if(check1 == 1 && check2 == 1 && check3 == 1) // convert the roman numeral to regular when every digit is valid
    {
      regNum = roman_to_digit(roman); // convert roman to regular
      cout << regNum << endl;
    }
  }
  return 0;
} 

int menu(void)  // let the user choose the conversion
{
  int userInput; //INPUT - User inputs their choice of Type 1 or Type 2 conversion
  cout << "Type 1 for standard -> Roman numeral conversion.\n";
  cout << "Type 2 for Roman numeral -> Standard numeral conversion.\n";
  cin >> userInput; // read user's choice(either 1 or 2)
  return userInput; 
}

int getRegularNumber (void) // get regular number from the user
{
  int regNum; //INPUT - User inputs their regular number for conversion
  cout << "Please enter a number to convert to Roman Numerals: \n";
  cin >> regNum;
  if(regNum < 0 || regNum > 4000) // check regular number from the user(should be positive and less than 4000)
  {
    cout << "invalid\n";
    return 0;
  }
  return regNum;
}

string getRomanNumeral(void)  // get roman numeral from the user
{
  string roman; //INPUT - User inputs their roman numeral for conversion
  cout << "Enter roman numeral to convert: ";
  cin >> roman;
  return roman;
}

int checkRoman(string roman, char one, char five, char ten) // check the roman numeral before the conversion
{
  int length; //CALC&OUT - Output of finding the length of the roman numeral from the user
  length = (int)roman.length();
  for(int i = 0; i < length; i++)
  {
    if(roman[i] == one)
    {
      //Checks for invalid input IIII
      if(roman[i+3] == one)
      {
        cout << "invalid\n";
        return 0;
      }
    }
    
    //Checks for invalid input IIV
    if(roman[i] == five)
    {
      if(roman[i-2] == one)
      {
        cout << "invalid\n";
        return 0;
      }
      //Checks for invalid input VIIII
      else if (roman[i+4] == one)
      {
        cout << "invalid\n";
        return 0;
      }
      //If no invalid inputs, returns 1
      else
      {
        return 1;
      }
    }
    if(roman[i] == ten)
    {
      //Checks for invalid input VX
      if(roman[i-2] == five)
      {
        cout << "invalid\n";
        return 0;
      }
    }
  }
  return 1;
}

int roman_to_digit(string romanNum) // convert the roman numeral to regular number
{
  int length; //CALC&OUT - Output of finding the length of the roman numeral from the user
  length = (int)romanNum.length(); 
  int regNum; //CALC&OUT - output of converesion from roman numeral to regular number
  regNum = 0;
  for(int i = 0; i < length; i++)
  {
    //Calculates how many roman numeral letters there are and add each value to the final regular number
    switch(romanNum[i])
    {
      case 'I':
        regNum += 1; 
        break;
      case 'V': 
        regNum += 5; 
        break;
      case 'X': 
        regNum += 10; 
        break;
      case 'L': 
        regNum += 50;  
        break;
      case 'C': 
        regNum += 100; 
        break;
      case 'D': 
        regNum += 500; 
        break;
      case 'M': 
        regNum += 1000; 
        break;
      default: 
        regNum += 0;
    }
    if(romanNum[i] == 'I' && (romanNum [i+1] == 'V'|| romanNum [i+1] == 'X')) 
    {
      regNum -= 2;  // deduct 2 from the regular number when the roman numeral is IV(4) or IX(9)
    }
    else if(romanNum[i] == 'X' && (romanNum[i+1] == 'L' || romanNum[i+1] == 'C')) 
    {
      regNum -= 20; // deduct 20 from the regular number when the roman numeral is XL(40) or XC(90)  
    }
    else if(romanNum[i] == 'C' && (romanNum [i+1] == 'D' || romanNum[i+1] == 'M'))
    {
      regNum -= 200;  // deduct 200 from the regular number when the roman numeral is CD(400) or CM(900)
    }
  }
  return regNum;
}

void findDigits(const int regNum, int& thousands, int& hundreds, int& tens, int& ones)
{ 
  //Calculates the number for each digit place
  thousands = regNum / 1000;      
  hundreds = (regNum % 1000)/100; 
  tens = ((regNum%1000)%100)/10;  
  ones = ((regNum%1000)%100)%10; 
}

string roman_digit(int n, string one, string five, string ten)
{
  string roman; // CALC&OUT - output of conversion from regular number to roman numeral 

  //Calculates the number of I's from the standard user input
  if(n < 4)
  {
    for(int i = 0; i < n; i++)
      roman += one;
  }

  //Calculates the number IV depending on user input for the regular number
  else if(n == 4)
  {
    roman += one + five;
  }

  //Calculates the number V depending on user input for the regular number
  else if(n == 5)
  {
    roman += five;
  }

  //Calculates the numbers VI, VII, VIII depending on user input for the regular number
  else if(n < 9)
  {
    roman += five; 
    int remainder = n % 5;  
    for(int i = 0; i < remainder; i++)
    {
      roman += one; 
    } 
  }

  //Calculates the number IX depending on user input for the regular number
  else if(n == 9)
  {
    roman += one + ten;  
  }
  return roman;
}