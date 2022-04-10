/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jibran Khan
 * Lab #14        : Reccursion - Maze
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 03/20/22
 *******************************************************************************/
#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

const int ROWS = 11;    // row of the maze
const int COLUMNS = 13; // column of the maze

/*******************************************************************************
 *
 * Recursion- Maze
 *_________________________________________________________________
 * <description>
 * This program creates a maze by using recursion
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  N/A
 *
 *******************************************************************************/

/*******************************************************************************
 * void createArr(bool arr[][COLUMNS]);
 *  This functoin creates an array with boolean
 *  - returns nothing
 *
 *******************************************************************************/
void createArr(bool arr[][COLUMNS]);    // IN - boolan array for the maze

/*******************************************************************************
 * void directionOrder(vector<int> & order);
 *  This function randomizes the order of the direction
 *  - returns nothing
 *
 *******************************************************************************/
void directionOrder(vector<int> & order);   // CALC - vector for the direction

/*******************************************************************************
 * void generateMaze
 *     (bool arr [][COLUMNS], const int row, const int column, const int end );
 *  This function generates a maze by using recursion
 *  - returns nothing
 *
 *******************************************************************************/
void generateMaze(bool arr [][COLUMNS], // IN/CALC - array with boolean
                  const int row,        // IN - row of current position
                  const int column,     // IN - column of current position
                  const int end );      // IN - columns of the end point

/*******************************************************************************
 * void displayMaze(const bool arr[][COLUMNS]);
 *  This function displays generated maze
 *  - returns nothing
 *
 *******************************************************************************/
void displayMaze(const bool arr[][COLUMNS]);    // IN - array with boolean
int returnPoint();

int main(void)
{
    int start;      // CALC - starting point of the maze
    int end;        // CALC - end point of the maze
    vector<int> order;  // CALC - vector for order of the direction
    bool arr[ROWS][COLUMNS];    // CALC - array for the maze

    srand(time(NULL));

    order.reserve(4);
    start = 1 + 2 * returnPoint();
    end = 1 + 2 * returnPoint();

    createArr(arr);
    generateMaze(arr,0,start,end);
    displayMaze(arr);

    return 0;
}

int returnPoint()
{
    return 1 + 2 * (rand()%6);
}
/*******************************************************************************
 * void createArr(bool arr[][COLUMNS])
 *_________________________________________________________________
 * <description>
 * - This function creates an array with boolean
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   bool arr[][COLUMNS]: array with boolean
 *
 * POSTCONDITIONS:
 *  The array elements have new values
 *
 *******************************************************************************/
void createArr(bool arr[][COLUMNS]) // CALC - array with boolean
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
            arr[i][j] = true;
    }
}
/*******************************************************************************
 * void directionOrder(vector<int> & order)
 *_________________________________________________________________
 * <description>
 * - This function randomizes the order of the direction
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   vector<int> & order: vector for the direction
 *
 * POSTCONDITIONS:
 *  The vector will have all different direction as a value
 *
 *******************************************************************************/
void directionOrder(vector<int> & order)    // CALC - vector for the direction
{
    int num;        // CALC - number for random number
    int count(0);   // CALC - variable for checking if the direction exists
    bool check;     // CALC - boolean for checking if the random numebr is valid
    
    for(int i = 0; i < order.capacity(); i++)
    {
        num = rand()%4+1;
        check = true;
        while(check)
        {
            for(int j = 0; j <= order.size(); j++)
            {
                if(order[j] == num)
                {
                    num = rand()%4+1;
                    count++;
                }
            }
            if(!count)
                check = false;
            count = 0;
        }
        order.push_back(num);
    }
}

/*******************************************************************************
 * void generateMaze
 *     (bool arr [][COLUMNS], const int row, const int column, const int end )
 *_________________________________________________________________
 * <description>
 * - This function generates a maze by using recursion
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   bool arr[][COLUMNS]: array with boolean
 *   const int row: row of current position
 *   const int columns: column of current position
 *   const int end: columnd of the end point
 *
 * POSTCONDITIONS:
 *  Maze is generated
 *
 *******************************************************************************/
void generateMaze(bool arr[][COLUMNS],  // CALC - array with boolean
                 const int row, // IN - row of current position
                 const int column,  //  IN - columns of current position
                 const int end) // IN - column of the end point
{
    vector<int> order;  // IN/CALC - vector with directions

    order.reserve(4);
    directionOrder(order);

    if(row == 0)
    {
        arr[row][column] = false;
        arr[row+1][column] = false;
        generateMaze(arr, row+1,column,end);
    }
    else if(order.size() > 0)
    {
        for(int i = order.capacity()-1; i >= 0; i--)
        {
            switch(order[i])
            {
                // PROCESSING - Check East
                case 1:
                    if(row !=0 && row != ROWS-1)
                    {
                        if(arr[row][column +1] && arr[row][column+2] && column + 2 < COLUMNS-1)
                        {
                            arr[row][column + 1] = false;
                            arr[row][column + 2] = false;
                            order.pop_back();
                            generateMaze(arr,row,column+2,end);
                        }
                    }
                    else
                        order.pop_back();
                    break;
                // PROCESSING - Check West
                case 2:
                    if(row != 0 && row != ROWS-1)
                    {
                        if(arr[row][column -1] && arr[row][column-2] && column - 2 > 0)
                        {
                            arr[row][column - 1] = false;
                            arr[row][column - 2] = false;
                            order.pop_back();
                            generateMaze(arr,row,column-2,end);
                        }
                    }
                    else
                        order.pop_back();
                    break;
                // PROCESSING - Check North
                case 3:
                    if(row != 0)
                    {
                        if(arr[row-1][column] && arr[row-2][column] && row - 2 > 0 )
                        {
                            arr[row - 1][column] = false;
                            arr[row - 2][column] = false;
                            order.pop_back();
                            generateMaze(arr,row-2,column,end);
                        }
                    }
                    break;
                // PROCESSING - Check South
                case 4:
                    if(row + 2 == ROWS-1 )
                    {
                        if(column == end)
                        {
                            arr[row+1][column] = false;
                            arr[row+2][column] = false;
                        }
                        order.pop_back();
                    }
                    else if(row+1 == ROWS - 1)
                    {
                        if(column == end)
                            arr[row+1][column] = false;
                        order.pop_back();
                    }
                    else if(arr[row+1][column] && arr[row+2][column] && row+1 < ROWS)
                    {
                        arr[row+1][column] = false;
                        arr[row+2][column] = false;
                        order.pop_back();
                        generateMaze(arr,row+2,column,end);
                    }
                    
                    break;
            }
        }
    }
}

/*******************************************************************************
 * void displayMaze(const bool arr[][COLUMNS])
 *_________________________________________________________________
 * <description>
 * - This function randomizes the order of the direction
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const bool arr[][COLUMNS]: array with boolean
 *
 * POSTCONDITIONS:
 *  The program outputs generated maze
 *
 *******************************************************************************/
void displayMaze(const bool arr[][COLUMNS]) // IN - array with boolean
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            if(arr[i][j])
                cout << "\u25A0 ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
