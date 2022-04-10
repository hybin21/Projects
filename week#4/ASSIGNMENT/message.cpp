#include "message.h"    // include Message class header file


/****************
** CONSTRUCTOR ** 
*****************/

/*****************************************************************************
* Message();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/
Message::Message()
{
    this->author = "";
    this->subject = "";
    this->body = "";
}

/*****************************************************************************
* Message(const string &athr, const string &sbjct, const string &body)
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &athr: author of the message
        const string &sbjct: subject of the message
        const string &body: body of the message
*   Return: none 
*****************************************************************************/
Message::Message(const string &athr,    // IN - auhtor of the message
                 const string &sbjct,   // IN - subject of the message
                 const string &body)    // IN - body of the message
{
    this->author = athr;
    this->subject = sbjct;
    this->body = body;
}

/*****************
**   Accessor   ** 
******************/

/*****************************************************************************
 * Method display:  Class Message
 * 
 * ---------------------------------------------------------------------------
 * This methods display message
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    Message class should have message with context
 *    
 * POST-CONDITIONç
 *   This function display the message
 * 
 *****************************************************************************/
void Message::display() const
{
    cout << this->subject << endl;
    cout << "from " << this->author << ": " << this->body << endl;
    for (int i = 0; i < 47; i++)
        cout << "-";
    cout << endl;
}