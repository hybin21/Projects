/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT     : Bulletin Board
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/09/22
*******************************************************************************/


#ifndef BBOARD_H  // checks if headerfile has been created before
#define BBOARD_H  // defines the board_h constant

#include<iostream>
#include<vector>
#include "user.h"       // contains user.h
#include "message.h"    // contains message.h

using namespace std;

class BBoard
{
    private:    
        string title;           // IN/OUT - represents title of the board
        vector<User> user_list; // IN/OUT - represents user list 
        User current_user;      // IN/OUT - represents current user
        vector<Message> message_list;   // IN/OUT - represents message list

    public:
        /*****************
        ** CONSTRUCTORS **
        *****************/
        BBoard();       // default constructor
        BBoard          // constructor with one parameter
                (const string &ttl);    // IN - title of the board

        /*****************
        **   MUTATORS   **
        *****************/
        void setup      // set up user list
                (const string &input_file); // IN - input file name
        void login();   // asks for and validates current user/password
        void run();     // contains the main loop of the BBoard
    
    private:

        /*****************
        **   MUTATORS   **
        *****************/
        void add_user   // adds the users from the file to user_list
                (const string &name,    // IN - username to be added
                 const string &pass);   // IN - password to be added
        void add_message(); // adds messages from the user to message_list

        /***************
        **  Accessor  **
        ***************/
        bool user_exists        // check if the user exits
                (const string &name,    // IN - uesrname to be checked
                 const string &pass) const; // IN - password to be checked
        User get_user       // returns the USer with the given name
                (const string &name) const;     // IN - username
        void display() const;   // displays all messages in message_list
        
};
#endif

/****************************************************************
* BBoard class
*   This class represents a bulletin board and allows users to 
     perform basic function, such as login, add messages, etc
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* BBoard();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* BBoard(const string &ttl);
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &ttl: title of the board
*   Return: none
***************************************************************/

/*****************
**   MUTATORS   **
*****************/

/****************************************************************
* void setup(const string &input_file)
*
*   Mutator; This method sets up user_list

* --------------------------------------------------------------
*   Parameters: 
    const string &input_file: input file name

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/


/****************************************************************
* void login()
*
*   Mutator; This method asks for and validates current 
        username and password

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/


/****************************************************************
* void run()
*
*   Mutator; This method contains the main loop of the BBoard

* --------------------------------------------------------------
*   Parameters: N/A 

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/


/****************************************************************
* void add_user(const string &name, const string &pass)
*
*   Mutator; This method adds the users from the 
                file to user_list

* --------------------------------------------------------------
*   Parameters: 
        const sring &name: username to be added to user_list
        const string &pass: password to be added to user_list

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/


/****************************************************************
* void add_message()
*
*   Mutator; This method adds message from the user
                to message_list

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/

/*****************
**   Accessor   **
******************/

/****************************************************************
* bool user_exists(const string &name, const string *pass) const
*
*   Accessor; This method checks if the user exists

* --------------------------------------------------------------
*   Parameters: 
        const string &name: username to be checked
        const string &pass: password to be checekd

* --------------------------------------------------------------
*   Return: true if the user exists, fals if it's not

***************************************************************/

/****************************************************************
* User get_user(const string &name) const
*
*   Accessor; This method returns the User with the given name

* --------------------------------------------------------------
*   Parameters: 
        const string &name: username of the user to be returned

* --------------------------------------------------------------
*   Return: the User with the given name

***************************************************************/

/****************************************************************
* void display() const
*   Accessor; This method displays messages in message_list

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/
