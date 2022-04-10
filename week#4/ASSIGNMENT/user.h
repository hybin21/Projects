/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT     : Bulletin Board
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/09/22
*******************************************************************************/

#ifndef USER_H  // checks if headerfile has been created before
#define USER_H  // definees the user_h constant

#include<iostream>

using namespace std;

class User
{
    private:
        string username;    // IN/OUT - represents username of the User
        string password;    // IN/OUT - represents password of the User
    public:

        /*****************
        ** CONSTRUCTORS **
        *****************/
        User(); // default constructor
        User    // constructor with two variables
            (const string& uname,   // IN/OUT - username of the User
            const string& pass);    // IN/OUT - password of the User

        /***************
        **  Accessor  **
        ***************/
        string get_username() const;    // return username of the User
        bool check  // check if the user exists in the user_list
            (const string& uname,   // IN - username to be checked
            const string& pass) const;   // IN - password to be checked
        
        /*****************
        **   MUTATORS   **
        *****************/
        void set_password       // set password of the User
            (const string &newpass);    // IN - new password 
};
#endif

/****************************************************************
* User class
*   This class represents user and allows users to perfrom
     basic function, such as check the user or change password
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* User();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
***************************************************************/

/****************************************************************
* User(const string &uname, const string &pass)
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &uname: username of the user
        const string &pass: password of the user
*   Return: none
***************************************************************/

/*****************
**   Accessor   **
******************/

/****************************************************************
* string get_username() const
*
*   Accessor; This method returns username of the User

* --------------------------------------------------------------
*   Parameters: N/A

* --------------------------------------------------------------
*   Return: username of the User

***************************************************************/

/****************************************************************
* bool check(const string &uname, const string &pass) const
*
*   Accessor; This method checks if the User exists in the 
                user_list

* --------------------------------------------------------------
*   Parameters: 
        const string &name: username of the user to be checked
        const string &pass: password of the user to be checkeed

* --------------------------------------------------------------
*   Return: true if the user exists in the list, 
            false if it's not

***************************************************************/

/*****************
**   MUTATORS   **
*****************/

/****************************************************************
* void set_password(const string &newpass)
*
*   Mutator; This method sets password of the User

* --------------------------------------------------------------
*   Parameters: 
    const string &newpass: new password

* --------------------------------------------------------------
*   Return: N/A

***************************************************************/