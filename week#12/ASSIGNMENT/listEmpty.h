#ifndef LISTEMPTY_H
#define LISTEMPTY_H
#include "linkedList.h"
#include <iostream>
using namespace std;

/*******************************************************************************
 *
 * ListEmpty
 *_________________________________________________________________
 * <description>
 * This class performs when there's is an exception case
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays the error message
 *
*******************************************************************************/
class ListEmpty
{   
    private:
        string message; // IN/CALC/OUT - message to be ouptut 
    
public:
    /****************
    ** CONSTRUCTOR **
    ****************/
    ListEmpty(){message = "List is empty!";}    
    ListEmpty(string input){message = input;}   // IN - customized message

    /***************
    **  ACCESSOR  **
    ****************/
    string what() const {return message;} 
};
#endif
/****************
** CONSTRUCTOR **
 ****************/   
/******************************************************************************
 * ListEmpty(string input)
 *  Constructor: initializes an ListEmtpy class
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      string input: message to be output
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/***************
**  ACCESSOR  **
****************/

/*****************************************************************************
 * string what() const:  Class ListEmpty
 *
 * ---------------------------------------------------------------------------
 * This function outputs the error message
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 * POST-CONDITIONç
 *   the error message is output
 *
 *****************************************************************************/