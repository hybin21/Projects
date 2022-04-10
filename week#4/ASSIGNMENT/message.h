/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT     : Bulletin Board
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/09/22
*******************************************************************************/

#ifndef MESSAGE_H  // checks if headerfile has been created before
#define MESSAGE_H  // defines the message_h constant

#include<iostream>

using namespace std;

class Message
{
    private:
        string author;  // IN/OUT - represents author of the message
        string subject; // IN/OUT - represents subject of the message
        string body;    // IN/OUT - represents body of the message
    public:

        /*****************
        ** CONSTRUCTORS **
        *****************/
        Message();  // default contructor
        Message     // constructor with three parameterrs
            (const string &athr,    // IN - author of the memssage
             const string &sbjct,   // IN - subject of the message
             const string &body);   // IN - body of the message

        /***************
        **  Accessor  **
        ***************/
        void display() const;   // display message
};
#endif

/****************************************************************
* Message class
*   This class represents a message of bulletin board 
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* Message();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* Message   
    (const string &athr, const string &sbjct, const string &body);
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &athr: author of the message
        const string &sbjct: subect of the  message
        cosnt string &body: body of the message
*   Return: none
***************************************************************/

/*****************
**   Accessor   **
******************/

/****************************************************************
* void display() const
*
*   Accessor; This methods displays message

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/