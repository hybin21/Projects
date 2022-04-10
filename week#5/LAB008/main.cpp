/*******************************************************************************
 * AUTHOR    : Jessica Hahm, Jefferson He
 * LAB #08   : Complex class
 * CLASS     : CS003A
 * SECTION   : 32276
 * DUE DATE  : 2/08/21
*******************************************************************************/
#include <iostream>
#include "complex.h" 

using namespace std; 

/*******************************************************************************
 *
 * Complex Class
 *_________________________________________________________________
 *  This program generates the Complex class and performs several
 *    mathematics operations using the Complex class
 *    - returns the calculated complex number
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  the calculated complex number
 *
*******************************************************************************/

const Complex i(0,1);   // defined constant i (0+1i)

// main function
int main() 
{
  Complex num;      //  CALC/OUT - complex number to be calculated
  Complex temp;     // CALC/OUT - complex number to be calculated

  // case 1
  cout << "\nTesting default constructor\n";
  num = Complex();      // num = 0+0i
  cout << num << endl;

  // case 2
  cout << "\nTesting one parameter constructor with input 5\n";
  num = Complex(5);     // num = 5+0i
  cout << num << endl;

  // case 3
  cout << "\nTesting two parameter constructor with input 0, 0\n";
  num = Complex(0,0);   // num = 0+0i
  cout << num << endl;

  // case 4
  cout << "\nTesting two parameter constructor with input 1, 2\n";
  num = Complex(1,2);   // num = 1+2i
  cout << num << endl;
  
  // case 5
  cout << "\nTesting two parameter constructor with input -13, 21\n";
  num = Complex(-13,21);  // num = -13+21i
  cout << num <<endl;
  
  // case 6
  cout << "\nTesting two parameter constructor with input -3, -4\n";
  num = Complex(-3,-4);   // num = -3-4i
  cout << num << endl;

  // case 7
  cout << "\nTesting addition subtraction and multiplication "
          << "for complex numbers: 10+4i and 5+3i\n";
  num = Complex(10,4);    // num = 10+4i
  temp = Complex(5,3);    // temp = 5+3i
  cout << "10+4i + 5+3i = " << num + temp << endl;
  cout << "10+4i - 5+3i = " << num - temp << endl;
  cout << "10+4i * 5+3i = " << num * temp << endl;
  
  // case 8
  cout<<"\nTesting addition subtraction and multiplication "
        << "for complex numbers: -10-4i and -5-3i\n";
  num = Complex(-10,-4);  // num = -10-4i
  temp = Complex(-5,-3);  // temp = -5-3i
  cout << "-10-4i + -5-3i = " << num + temp << endl;
  cout << "-10-4i - -5-3i = " << num - temp << endl;
  cout << "-10-4i * -5-3i = " <<num * temp << endl;
  
  // case 9
  cout << "\nTesting == operator with -10-4i and -5-3i\n";
  cout << "Should be false: " << noshowpos << (num == temp) << endl;

  // case 10
  cout << "\nTesting == operator with 10+4i and 10+4i\n";
  num = Complex(10,4);  // num = 10+4i
  temp = Complex(10,4); // temp = 10 +4i
  cout << "Should be true: " << noshowpos <<(num == temp) << endl;
  
  // case 11
  cout << "\nTesting << and >> operators\n";
  cout << "enter imaginary number of form a+bi or a-bi\n";
  cin >> num;
  cout << num << endl;
  
  
 
}