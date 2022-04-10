 /*******************************************************************************
 * AUTHOR            : Jefferson He, Jessica Hahm
 * LAB #17           : Template
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 04/06/22
*******************************************************************************/
#include <iostream>
#include <fstream>
#include "matrix.h"

/*******************************************************************************
 *
 * Matrix class
 *_________________________________________________________________
 *  This program generates the Matrix Class and performs several
 *  member functions using the Rational class
 *    - returns the matrix  
 *_________________________________________________________________
 * INPUTS:
 *  Matrix<string> m1: string type matrix
 *  Matrix<string> m2: string type matrix
 *  Matrix<int> m4: int type matrix
 *  Matrix<int> m5: int type matrix
 *  Matrix<float> m7: float type matrix
 *  Matrix<float> m8: float type matrix
 * OUTPUTS:
 *  Every matrix that created in the program 
 *
*******************************************************************************/

using namespace std;

int main(void)
{
    ofstream outStream; // OUT - ouptut file stream 
    outStream.open("output.txt");
    if(outStream.fail())
    {
        cout <<"Error! Unable to read the file\n";
        outStream.close();
    }

    Matrix<string> m1;  // IN - string type matrix
    Matrix<string> m2;  // IN - string type matrix
    Matrix<string> m3;  // IN - string type matrix
   
    
    string temp[2][3] = {   // CALC - 2D array to be added
            {"a","b","c"},{"d","e","f"}};  
    string oneD [6] = {     // CALC - 1D array to be added
            "a","b","c","d","e","f"};      
    
    cout << "Demonstrating with string matrix:\n";
    outStream << "Demonstrating with string matrix:\n";
    m1.setElement(0,0,"Congra");
    m1.setElement(0,1,"y");
    m1.setElement(0,2,"ar");
    m1.setElement(1,0,"alm");
    m1.setElement(1,1,"don");
    m1.setElement(1,2,"La");
    m1.printMatrix();
    outStream << m1;
    cout << endl;
    outStream << endl;

    cout << "Matrix incremented by second array\n";
    outStream << "Matrix incremented by second array\n";
  
    m2.setElement(0,0,"A");
    m2.setElement(0,1,"B");
    m2.setElement(0,2,"C");
    m2.setElement(1,0,"D");
    m2.setElement(1,1,"E");
    m2.setElement(1,2,"F");
    m2.printMatrix();
    m3 = m1+m2;
    m3.printMatrix();
    outStream << m3;
    cout << endl;
    outStream << endl;

    cout << "testing setMatrix with 1D array\n";
    outStream << "testing setMatrix with 1D array\n";

    m1.setMatrix(oneD);
    m1.printMatrix();
    outStream << m1;
    cout << endl;
    outStream << endl;

    cout << "testing setMatrix with 2D array\n";
    outStream << "testing setMatrix with 2D array\n";
    m2.setMatrix(temp);
    m2.printMatrix();
    outStream << m2;
    cout << endl;
    outStream << endl;
    
    Matrix<int> m4; // IN - int type matrix
    Matrix<int> m5; // IN - int type matrix
    Matrix<int> m6; // IN - int type matrix
    int arr1[6] = { // CALC - 1D array to be added
            100,200,300,400};
    int arr2[2][3] = {  // CALC - 2D array to be added
            {100,200,300},{400,500,600}};

    cout << "Demonstrating with int matrix:\n";
    outStream << "Demonstrating with int matrix:\n";
    cout << "Matrix set to first array\n";
    outStream << "Matrix set to first array\n";
  
    m4.setElement(0,0,1);
    m4.setElement(0,1,2);
    m4.setElement(0,2,3);
    m4.setElement(1,0,4);
    m4.setElement(1,1,5);
    m4.setElement(1,2,6);
    m4.printMatrix();
    outStream << m4;
    cout << endl;
    outStream << endl;
  
    cout << "Matrix incremented by second array\n";
    outStream << "Matrix incremented by second array\n";
    m5.setElement(0,0,6);
    m5.setElement(0,1,5);
    m5.setElement(0,2,4);
    m5.setElement(1,0,3);
    m5.setElement(1,1,2);
    m5.setElement(1,2,1);
    m5.printMatrix();
    outStream << m5;
    cout << endl;
    outStream << endl;

    cout << "Matrix incremented by second array\n";
    outStream << "Matrix incremented by second array\n";
    m6 = m4+ m5;
    m6.printMatrix();
    outStream << m6;
    cout << endl;
    outStream << endl;

    cout << "testing setMatrix with 1D array\n";
    outStream << "testing setMatrix with 1D array\n";
    m4.setMatrix(arr1);
    m4.printMatrix();
    outStream << m4;
    cout << endl;
    outStream << endl;

    cout << "testing setMatrix with 2D array\n";
    outStream << "testing setMatrix with 2D array\n";
    m5.setMatrix(arr2);
    m5.printMatrix();
    outStream << m5;
    cout << endl;
    outStream << endl;

    
    Matrix<float> m7;   // IN - float type matrix
    Matrix<float> m8;   // IN - float type matrix
    Matrix<float> m9;   // IN - float type matrix
    float arr3[6] = {   // CALC - 1D array to be added
            100.1,200.2,300.3,400.4};
    float arr4[2][3] = {    // CALC - 2D array to be added
            {100.1,200.2,300.3},{400.4,500.5,600.6}};

    cout << "Demonstrating with float matrix:\n";
    cout << "Matrix set to first array\n";
    outStream << " Demonstrating with float matrix:\n";
    outStream << "Matrix set to first array\n";
    m7.setElement(0,0,1.6);
    m7.setElement(0,1,2.5);
    m7.setElement(0,2,3.4);
    m7.setElement(1,0,4.3);
    m7.setElement(1,1,5.2);
    m7.setElement(1,2,6.1);
    m7.printMatrix();
    outStream << m7;
    cout << endl;
    outStream << endl;

    cout << "Matrix incremented by second array\n";
    outStream << "Matrix incremented by second array\n";
    m8.setElement(0,0,6.1);
    m8.setElement(0,1,5.2);
    m8.setElement(0,2,4.3);
    m8.setElement(1,0,3.4);
    m8.setElement(1,1,2.5);
    m8.setElement(1,2,1.6);
    m8.printMatrix();
    outStream << m8;
    cout << endl;
    outStream << endl;

    cout << "Matrix incremented by second array\n";
    outStream << "Matrix incremented by second array\n";
    m9 = m7+ m8;
    m9.printMatrix();
    outStream << m9;
    cout << endl;
    outStream << endl;
    
    cout << "testing setMatrix with 1D array\n";
    outStream << "testing setMatrix with 1D array\n";
    m7.setMatrix(arr3);
    m7.printMatrix();
    outStream << m7;
    cout << endl;
    outStream << endl;

    cout << "testing setMatrix with 2D array\n";
    outStream << "testing setMatrix with 2D array\n";
    m8.setMatrix(arr4);
    m8.printMatrix();
    outStream << m8;
    cout << endl;
    outStream << endl;

    outStream.close();
    return 0;
}