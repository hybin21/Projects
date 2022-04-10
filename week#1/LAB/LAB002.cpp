/******************************************************************
 * AUTHOR    : Jesse and Jessica
 * LAB #00   : Lab 2 - CS 002 Review - Arrays - Histogram
 * CLASS     : CS003A
 * SECTION   : 32276
 * DUE DATE  : 01/13/2021
******************************************************************/
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

/******************************************************************
 *
 * Lab 2 - CS 002 Review - Arrays - Histogram
 *_________________________________________________________________
 * <description>
 * This program create a histogram based on the sum of 4 random dice rolls
 *_________________________________________________________________
 * INPUTS:
 *  int nRolls: the number of times program rolls dice.
 * OUTPUTS:
 *  void printHistogram(): Histogram of the bell curve
******************************************************************/

const int COUNTS_SIZE = 21;                 // constant variable for the size of counts array

//FUNCTION PROTOTYPES

/******************************************************************
 * Name: getInput
 * Description: Gets number of rolls and seed value from the user
 * Returns: Returns two call-by-reference variables(nRolls and seed) 
******************************************************************/
void getInput(int& nRolls,                  // OUT - number of rolls
               int& seed);                  // OUT - seed value  

/******************************************************************
 * Name: roll
 * Description: Generate a random number from 1 to 6
 * Returns: Returns generated random number 
******************************************************************/
int roll(void);                         


/******************************************************************
 * Name: fourSum
 * Description: Generates a sum from four random numbers ranged from integers 1-6.
 * Returns: Returns the sum generated (num) from the four random numbers.
******************************************************************/
int fourSum(void);

/******************************************************************
 * Name: findNum
 * Description: find a number(sum of 4 dices) from array(counts) 
 * Returns: Returns 1 if the numbe is found or 2 if it's not
******************************************************************/
void findNum(int fourNum,                     // IN - the sum of 4 dices
             int counts[COUNTS_SIZE]);        // IN - array which stores

/******************************************************************
 * Name: printHistogram
 * Description: prints out the histogram
 * Returns: N/A, will output the Histogram.
******************************************************************/
void printHistogram(int counts[COUNTS_SIZE]); // IN -  array which stores the number of sum 

//FUNCTION DEFINITIONS

int main() {
  int nRolls;                                 // INPUT: User inputs the number of times program rolls dice
  int seed;                                   // INPUT: User inputs the seed valud
  int sum;                                    // CALC&OUT : Output of the sum of dices
  int counts[COUNTS_SIZE] = {0};              // CALC&OUT : Output of array which contains the number of total from dices

  // INPUT -- A menu for the user to enter rolling times and seed value                           
  getInput(nRolls,seed);                    

  // PROCESSING -- run the program when input(nRolls) is valid 
  if(nRolls != 0)                              
  {
    srand(seed);

    // PROCESSING -- find the sum from 4 fices from the array(counts)
    for (int i = 0; i < nRolls; i++)         
    {
      sum = fourSum();
      findNum(sum,counts);
    }

    // OUPUT -- print out the histogram of the bell curve
    printHistogram(counts);                 
  }
  
} 

/******************************************************************
 * getInput
 *_________________________________________________________________
 * This function gets the number of rolls and seed value from the user
 *   - returns the number of rolls and seed value 
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   int& nRolls: call-by-reference variable, the number of rolls
 *   int& seed: call-by-reference variable, the seed value
 *
 * POSTCONDITIONS:
 *  int& nRolls: the number of rolls from the user
 *  int& seed: the seed value from the user
******************************************************************/
void getInput(int& nRolls, int& seed)           
{
  // INPUT -- prompt to get input of seed value and number of rolls
  cout << "Enter the seed value: \n";
  // PROCESSING -- read the seed value from the user
  cin >> seed;  
  
  cout << "Enter the number of Rolls: \n";
    // PROCESSING -- read rolling time from the user 
  cin >> nRolls;
}

/******************************************************************
 * findNum
 *_________________________________________________________________
 * Places the sum calculated  into the appropriate index and adds 1.
 * - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   fourNum : Sum of four dices
 *   counts[] : Array which stores the # of sums
 *
 * POSTCONDITIONS:
 *   Add one to corresponding index for sum
******************************************************************/
void findNum(int fourNum, int counts[])
{
  // PROCESSING -- add one to the index of the sum
  counts[fourNum - 4]++;                    
}

/******************************************************************
 * printHistogram
 *_________________________________________________________________
 * Print the bell curve histogram 
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   counts[]: Array which stores the number of sums
 *
 * POSTCONDITIONS:
 *  print "X" correspoinding to the value from the array(counts)
 *
******************************************************************/
void printHistogram(int counts[])
{
  
  cout << endl;
  for(int i = 0; i < COUNTS_SIZE; i++)
  {
    // PROCESSING -- format by using setw()
    cout << left << setw(2) << i+4 << ": " ;

    for(int x = 0; x < counts[i]; x++)
    {
      //OUTPUT -- Prints out "X" for each sum on histogram
      cout << "X";
      
    }
    cout << endl;
  }
}

/******************************************************************
 * Roll()
 *_________________________________________________________________
 * Rolls a integer number between 1-6
 * - returns the generated integer
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   randInt: Has no value
 *
 * POSTCONDITIONS:
 *   randInt: Random int value between 1-6
 *
******************************************************************/
int roll()
{ 
  int randInt;                                // CALC&OUT: generated random number
  
  //PROCESSING -- Sets randInt to random int between 1-6
  randInt = rand()%6+1;
  return randInt;
}

/******************************************************************
 * fourSum
 *_________________________________________________________________
 * calculate the total of 4 dices
 * - returns the total
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   N/A
 *
 * POSTCONDITIONS:
 *  returns the total of 4 dices
 *
******************************************************************/ 
int fourSum()
{
  int total;                                      // CALC&OUT: total of rolls
  int randInt;                                    // CALC: generated random number
  total = 0;

  // PROCESSING -- rolls 4 dices and add the number to total
  for (int i = 0; i < 4; i++)
  {
    randInt = roll();
    total += randInt; 
  }
  return total;
}