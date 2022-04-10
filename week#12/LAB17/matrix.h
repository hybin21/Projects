 /*******************************************************************************
 * AUTHOR            : Jefferson He, Jessica Hahm
 * LAB #17           : Template
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 04/06/22
*******************************************************************************/
#ifndef MATRIX_H
#define MATRIX_H

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

#include <iostream>

using namespace std;

const int MAXROWS=2;    
const int MAXCOLS=3;

template<typename T>
class Matrix
{
    private:
        T array[MAXROWS][MAXCOLS];  // CALC/OUT - matrix array
        int rows;   // CALC - rows of the arrray
        int cols;   // CALC - columns of the array
        
    public:
    /****************
    ** CONSTRUCTOR **
    ****************/
        Matrix();
    /****************
    *** MUTATORS ***
    ****************/
        void setElement(int row,    // IN - row of the array to be set
                        int col,    // IN - column of the array to be set
                        T value);   // IN - value to be set
        void setMatrix(const T m[]);    // IN - 1D array to be set
        void setMatrix(const T  m[][MAXCOLS]);  // IN - 2D array to be set
        const Matrix operator+(
                        const Matrix<T> &m) const;  // IN =-matrix to be added
    /****************
    *** ACCESSORS ***
    ****************/
        template <typename U>friend ostream& operator<<(
                        ostream& outStream,     // IN - output stream
                        const Matrix<U> & m);   // IN - matrix to be output
        void printMatrix() const;
        
        
};

/******************************************************************************
 * Matrix class
 *  <description>: This class performs several member functions using 
 *  the Rational class
 *
 *****************************************************************************/

/****************
** CONSTRUCTOR **
****************/

/******************************************************************************
 * Matrix();
 *  Constructor: initializes an empty matrix
 *-----------------------------------------------------------------------------
 *  Parameters: none
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/
template<typename T>
Matrix<T>::Matrix()
{
    rows = MAXROWS;
    cols = MAXCOLS;
}

/****************
 *** MUTATORS ***
 ****************/

/******************************************************************************
 * void setElement(int row, int col, T value)
 *  Mutator: This function sets the appropriate element in the Matrix to
 *           the value passed in.
 *
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *  int row: row of the array to be set
 *  int col: column of the array to be set
 *  T value: value to be set
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/
template<typename T>
void Matrix<T> ::setElement(int row,    // IN - row of the array to be set
                        int col,    // IN - column of the array to be set
                        T value)   // IN - value to be set
{
   array[row][col]= value;
}

/******************************************************************************
 * void setMatrix(const T m[])
 *  Mutator: This function copies the elements in a 1d array and stores it 
 *          into the 2d matrix.  Should have the same number of elements.
 *
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *  T m[]: 1D array to be set
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/
template<typename T>
void Matrix<T>::setMatrix(const T m[])  // IN - 1D array to be set
{
    for(int i = 0; i < MAXROWS * MAXCOLS; i++)
        this->array[i/3][i%3]=m[i];
}

/******************************************************************************
 * void setMatrix(const T  m[][MAXCOLS])
 *  Mutator: This function copies the elements in the 2d array passed into 
 *          the matrix that called the function.
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      T m[][MAXCOLS]: 2D array to be set
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/
template<typename T>
void Matrix<T> :: setMatrix(
            const T  m[][MAXCOLS])  // IN - 2D array to be set
{
    for(int i = 0; i < rows; i++ )
    {
        for(int j = 0; j < cols; j++)
        {
            this->array[i][j] = m[i][j];
        }
    }
}

/******************************************************************************
 * const Matrix<T> operator+(const Matrix<T> &m) const
 *  MUTATOR: This function adds the passed in matrix to the called matrix.
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      Matrix<T> &m: matrix to be added
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/
template<typename T>
const Matrix<T> Matrix<T>::operator+(
            const Matrix<T> &m) const   // IN - matrix to be added
{  
   Matrix<T> temp;  // CALC/OUT - temporary matrix 
    
   for(int i = 0; i< rows; i++)
   {
       for(int j=0; j< cols; j++)
        {
            temp.array[i][j]= array[i][j]+ m.array[i][j];
        }
   }
   return temp;
}

/****************
 *** ACCESSORS ***
 ****************/

/******************************************************************************
 * void printMatrix() const
 *  ACCESSOR: This function displays all of the elements of 
 *            the array row by row.
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/
template<typename T>
void  Matrix<T> :: printMatrix() const
{
    for(int i = 0; i < rows; i++ )
    {
        for(int j = 0; j < cols; j++)
        {
            cout << array[i][j]<< " ";
        }
        cout << endl;
    }
}



/******************************************************************************
 * ostream& operator<<(ostream& outStream, const Matrix<U> & m)
 *  ACCESSOR: This function displays all of the elements of the array row by 
 *            row, by overloading the ostream operator.
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      ostream& outStream: output stream
 *      const Matrix<U> & m: matrix to be output
 *-----------------------------------------------------------------------------
 *  Return: output stream
 *****************************************************************************/
template<typename U>
ostream& operator<<(ostream& outStream, // OUT - otuput stream 
                 const Matrix<U> & m)   // IN - matrix to be output
{
    for(int i = 0; i < m.rows; i++ )
    {
        for(int j = 0; j < m.cols; j++)
        {
            outStream << m.array[i][j]<< " ";
        }
        outStream << endl;
    }
    return outStream;
}
#endif