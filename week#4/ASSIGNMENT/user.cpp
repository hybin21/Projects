#include "user.h"   // include User class header file

/****************
** CONSTRUCTOR ** 
*****************/

/*****************************************************************************
* USer();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/
User::User()
{
    this->username = "";
    this->password = "";
}

/*****************************************************************************
* User(const string &uname, const string &pass)
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &uname: username of the User
        const string &pass: password of the User
*   Return: none 
*****************************************************************************/
User::User(const string &uname, // IN - username of the User
         const string &pass)    // IN - username of the User
{
    this->username = uname;
    this->password = pass;
}
/*****************
**   Accessor   ** 
******************/

/*****************************************************************************
 * Method get_username: Class User
 * 
 * ---------------------------------------------------------------------------
 * This methods returns the username of the User
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    User class should have valid username 
 *    
 * POST-CONDITIONç
 *   This function returns the username of the User
 * 
 *****************************************************************************/
string User::get_username() const
{
    return this->username;
}   

/*****************************************************************************
 * Method check: Class User
 * 
 * ---------------------------------------------------------------------------
 * This methods checks if the User exists in the user_list
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    const string &uname: username to be checked
 *    const string &pass: password to be checked
 *    
 * POST-CONDITIONç
 *   This function returns true if the user in the list, false if it's not
 * 
 *****************************************************************************/
bool User::check(const string& uname,   // IN - username of the user 
                 const string& pass) const  // IN - password of the user
{
    // when username or password are empty
    if(uname == "" || pass == "")   
        return false;
    
    // when username and password are the same
    else if(uname == this->username && pass == this->password)
        return true;
    
    // else
    return false;
}

/******************
**    Mutator    ** 
*******************/

/*****************************************************************************
 * Method set_password:  Class User
 * 
 * ---------------------------------------------------------------------------
 * This methods sets password of the User
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    const string &newpass: new password of the User
 *    
 * POST-CONDITIONç
 *   This function changes the password to newpass
 * 
 *****************************************************************************/
void User::set_password(const string &newpass)  // IN - new password
{
    this->password = newpass;
}