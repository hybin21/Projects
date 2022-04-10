/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jefferson He
 * Lab #5         : 2D Vector
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/10/22
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/*******************************************************************************
 *
 * 2D Vector
 *_________________________________________________________________
 * <description>
 * This program performs 2D vector member function 
 *_________________________________________________________________
 * INPUTS:
 *  vector<vector<int> > A: 2d vector to be calculated
 *  vector<vector<int> > B: 2d vector to be calculated
 *
 * OUTPUTS:
 *  vecotr<vector<int> > C: 2d vector to store the calculation
 *
*******************************************************************************/

// FUNCTION PROTOTYPES
/******************************************************************
 * matrixFill
 * description: fills the 2d vector with the user inputted numbers 
 * 
 * -returns nothing
 *      
******************************************************************/
void matrixFill
      (vector< vector<int> >& v);  // CALC/OUT - stores user's iput

/*****************************************************************************
 * displayMatrix
 * description: display the 2d vector
    - returns nothing

*****************************************************************************/
void displayMatrix
        (const vector< vector<int> >& v); // IN - 2D vector to be displayed

/******************************************************************
 * matrixAddition
 * description: adds the first two vectors into the third vector
 * 
 * -returns third 2d vector(c)
 *      
******************************************************************/
void matrixAddition(const vector< vector<int> >& a, //IN/CALC: input vector
                    const vector< vector<int> >& b, //IN/CALC: input vector
                         vector< vector<int> >& c); //OUT/CALC: output vector

/*****************************************************************************
 * matrixMultiplication
 * description: multiplies the the first two vectors 
 
    - returns thrid 2d vector(c)
*****************************************************************************/
void matrixMultiplication
            (const vector< vector<int> >& a,  //IN/CALC: input vector
            const vector< vector<int> >& b,   //IN/CALC: input vector
            vector< vector<int> >& c);        //OUT/CALC: output vector



int main() {
  vector<vector<int> > A; //IN/CALC: first input 2d vector
  vector<vector<int> > B; //IN/CALC: second input 2d vector
  vector<vector<int> > C; //CALC/OUT: result output 2d vector

  int rows;        //IN/CALC: number of rows for first 2d array
  int columns;     //IN/CALC: number of columns for the first 2d array
  int rows1;       //IN/CALC: number of rows for scond 2d array
  int columns1;    //IN/CALC: number of columns for second 2d array

  cout << "Enter the number of rows and columns of the matrices to add: ";
  cin >> rows >> columns;  //user enter rows and columns for addition vectors
 
  A.resize(rows);  //sets rows and columns for vector with user input
  for(int i = 0; i < rows; i++)
    A[i].resize(columns);
    
  B.resize(rows); //sets rows and columns for vector with user input
  for(int i = 0; i < rows; i++)
    B[i].resize(columns);

  C.resize(rows); //sets rows and columns for output/result vector
  for(int i = 0; i < rows; i++)
    C[i].resize(columns); 

  cout << "Enter matrix A: ";
  matrixFill(A);      //fill vector A
  cout << "For matrix A you entered: ";
  displayMatrix(A);

  cout << "Enter matrix B: ";
  matrixFill(B);     //fill vector B
  cout << "For matrix B you entered: ";
  displayMatrix(B);

  matrixAddition(A, B, C);  //add vectors
  cout << "sum of A and B is: ";
  displayMatrix(C);  

  

  cout << "\n\nNow for multiplication.\n";

  //clears vectors to reset size
  A.clear();    
  B.clear();
  C.clear();
  
  cout << "Enter the number of rows and columns of matrix A: ";
  cin >> rows >> columns; //user enter rows and columns for mult vectors

  cout << "Enter the number of rows and columns of matrix B: ";
  cin >> rows1 >> columns1; //user enter rows and columns for mult vectors

  while(columns != rows1) //check for valid entered rows and columns
  {
    cout << "The number of columns of matrix A must be "
     <<"the same as the number of rows of matrix B.\n";
    
    cout << "Enter the number of rows and columns of matrix A: ";
    cin >> rows >> columns;

    cout << "Enter the number of rows and columns of matrix B: ";
    cin >> rows1 >> columns1;
  }
  
   
  A.resize(rows); //sets rows and columns for vector with user input
  for(int i = 0; i < rows; i++)
  A[i].resize(columns); 
  

  B.resize(rows1); //sets rows and columns for vector with user input
  for(int i = 0; i < rows1; i++)
    B[i].resize(columns1); 
  
  C.resize(rows); //sets rows and columns for output vector
  for(int i = 0; i < rows; i++)
   C[i].resize(columns1);  
    

  cout << "Enter matrix A: ";
  matrixFill(A);  //fill vector A
  cout << "For matrix A you entered: ";
  displayMatrix(A);

  cout << "Enter matrix B: ";
  matrixFill(B);  //fill vector B
  cout << "For matrix B you entered: ";
  displayMatrix(B);
  
  matrixMultiplication(A,B,C);  //multiply two vectors
  cout << "product of A and B is: ";
  displayMatrix(C);
  
  return 0;
}

/*****************************************************************************
 * matrixFill
 * description: fills the 2d vector with the user inputted numbers 
 * 
 * -returns nothing
------------------------------------------------------------------------------
PRE-CONDITIONS
  vector<vector<int> > v: 2d vector to be filled 
POST-CONDITIONS
  This function fills user's input to v(2d vector)
*****************************************************************************/
void matrixFill(vector< vector<int> >& v) // CACL/OUT: stores user's input
{
  for(int i = 0; i < v.size(); i++)
  {
    for(int j = 0; j < v[i].size() ; j++)
    {
      cin >> v[i][j];
    }
  }
}

/*****************************************************************************
 *displayMatrix
 * description: display the 2d vector
    - returns nothing
------------------------------------------------------------------------------
PRE-CONDITIONS
 vector< vector<int> > v: 2d vector to be displayed
POST-CONDITIONS
  This function will display v(2d vector)
*****************************************************************************/
void displayMatrix
    (const vector< vector<int> >& v)  // 2D vector to be displayed
{
  for(int i = 0; i < v.size(); i++)
  {
    for(int j = 0; j < v[i].size() ; j++)
      cout << v[i][j] << " ";
    cout << endl;
  }
}

/*****************************************************************************
 * matrixAddition
 * description: adds the first two vectors into the third vector
 * 
 * -returns third 2d vector(c)
------------------------------------------------------------------------------
PRE-CONDITIONS
  N/A
POST-CONDITIONS
  This function will ouptut user's choice
*****************************************************************************/
void matrixAddition
        (const vector< vector<int> >& a,  // IN/CALC: input vector
        const vector< vector<int> >& b,   // IN/CALC: input vector
              vector< vector<int> >& c)   // OUT/CALC: output vector
{
  int temp;
   for(int i = 0; i < a.size(); i++)
  {
    for(int j = 0; j < a[i].size() ; j++)
    {
      temp = a[i][j]+b[i][j];
      c[i][j]= temp;
    }   
  }
}


/*****************************************************************************
 * matrixMultiplication
 * description: multiplies the the first two vectors 
 
    - returns thrid 2d vector(c)
------------------------------------------------------------------------------
PRE-CONDITIONS
  vector< vector<int> > a: 2d vector to be calculated
  vector< vector<int> > b: 2d vector to be calculated
POST-CONDITIONS
  vector< vector<int> > c: 2d vector with calculated values
*****************************************************************************/
void matrixMultiplication
                  (const vector< vector<int> >& a, //IN/CALC: input vector
                  const vector< vector<int> >& b, //IN/CALC: input vector
                       vector< vector<int> >& c) //OUT/CALC: output vector
{
  int temp;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < c[i].size(); j++)
        {
            temp = 0;
            for(int k = 0; k < a[i].size(); k++)
            {
                temp += a[i][k] * b[k][j];
            }
            c[i][j] = temp;
        }
    }

}                      