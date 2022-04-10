/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jason Boenjamin
 * Lab #7         : Distance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/01/22
*******************************************************************************/
#include <iostream>
#include "distance.h"
using namespace std;

/*******************************************************************************
 *
 * Disatnce Class
 *_________________________________________________________________
 *  This program generates the Distance Class and performs several
 *  mathematics operations using the Distance class
 *    - returns the calculated rationals 
 *_________________________________________________________________
 * INPUTS:
 *  Distance d1: default distance
 *  Distance d2: 2' 5.9"
 *  Distance d3: 0' 75"
 *  Distance d4: 5' 19.34"
 *  Distance d5: 100"
 *  Distacne dd: 3' -96"
 *
 * OUTPUTS:
 *  the calculated distances
 *
*******************************************************************************/

// Main Function
int main()
{
  // Test case 1
  Distance d1;    // IN - default distance
  cout << "d1: ";
  d1.display(); cout << endl;

  // Test case 2
  Distance d2 = Distance(2, 5.9);   // IN - 2' 5.9"
  cout << "d2: "; d2.display(); cout << endl;

  // Test case 3
  Distance d3 = Distance(3.75);     // IN - 0' 75"
  cout << "d3: "; d3.display(); cout << endl;

  // Test case 4
  Distance d4 = Distance(5, 19.34); // IN - 5' 19.34"
  cout << "d4: "; d4.display(); cout << endl;

  // Test case 5
  Distance d5 = Distance(100);      // IN - 100"
  cout << "d5: "; d5.display(); cout << endl;
  

  //Test case 6
  cout << "d4 + d5: "; (d4 + d5).display(); cout << endl;

  // Test case 7
  cout << "d2 + d4: "; (d2 + d4).display(); cout << endl;

  // Test case 8
  cout << "d3 - d1: "; (d3 - d1).display(); cout << endl;

  // Test case 9
  cout << "d1 - d3: "; (d1 - d3).display(); cout << endl;

  // Test case 10
  cout << "d4 - d2: "; (d4 - d2).display(); cout << endl;

  // Test case 11
  cout << "d2 - d4: "; (d2 - d4).display(); cout << endl;

  // Test case 12
  cout << "d4 - d5: "; (d4 - d5).display(); cout << endl;

  // Test case 13
  cout << "d5 - d2: "; (d5 - d2).display(); cout << endl;

  // Test case 14
  Distance dd(3,-96);     // IN - 3' -96"
  dd.display();


  return 0;
}