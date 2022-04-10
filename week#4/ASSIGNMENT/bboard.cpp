#include "bboard.h"     // include BBoard class header file
#include "user.h"       // include User class header file
#include "message.h"    // include Message class headerr file
#include <fstream>      
#include <string>
#include <cstdlib>


/****************
** CONSTRUCTOR ** 
*****************/

/*****************************************************************************
* BBoard();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none 
*****************************************************************************/
BBoard::BBoard()
{
    this->title = "";
    this->user_list.clear();
    this->current_user = User();
    this->message_list.clear();
}

/*****************************************************************************
* BBoard(const string &ttl);
*   Constructor; Initialize class attributes
*   Parameters: 
        const string &ttl: title of the board
*   Return: none 
*****************************************************************************/
BBoard::BBoard(const string &ttl)   // IN - title of the board
{
    this->title = ttl;
    this->user_list.clear();
    this->current_user = User();
    this->message_list.clear();
}

/******************
**    Mutator    ** 
*******************/

/*****************************************************************************
 * Method setup:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods sets up user_list
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    const string &input_file: name of input file
 *    
 * POST-CONDITIONç
 *   user_list contains information from the input file
 * 
 *****************************************************************************/
void BBoard::setup(const string &input_file)    // IN - input file name
{
    ifstream inStream;      // IN - input file stream
    string username;        // CALC/OUT - username to read from the input file
    string password;        // CALC/OUT - password to read from the input file
    
    // open input file
    inStream.open(input_file);

    // when file name is invalid
    if (inStream.fail())
    {
        cout << "Input file doesn't exist\n";
        exit(1);
    }
    else
    {
        while (!inStream.eof())
        {
            inStream >> username;
            if (username != "end")
            {
                inStream >> password;
                add_user(username, password);
            }
        }
    }

    inStream.close();
}

/*****************************************************************************
 * Method login:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods asks for and validates current username and password
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    user_list should have user's information from the input file
 *    
 * POST-CONDITIONç
 *   user's username and password are stored in current_user User
 * 
 *****************************************************************************/
void BBoard::login()
{
    string username;    // IN - useranme of the User
    string password;    // IN - password of the User
    bool check;         // CALC - check if username and password are valid

    check = true;

    while (check)
    {
        cout << "Welcome!\n";
        cout << "Enter your username (\"Q\" or \"q\" to quit): \n";
        cin >> username;
        if (username == "Q" || username == "q")
        {
            cout << "\nBye\n";
            exit(0);
        }
        else
        {
            cout << "Enter your password: \n";
            cin >> password;
            if (user_exists(username, password))
            {
                this->current_user = get_user(username);
                cout << "Welcome back " << current_user.get_username() << "!\n\n";
                check = false;
            }
        }
    }
}

/*****************************************************************************
 * Method run:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods contains the main loop of the BBoard
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *    user should be logged in to the board
 *    
 * POST-CONDITIONç
 *   current_user can view, add messages and quit the BBoard program
 * 
 *****************************************************************************/
void BBoard::run()
{
    char option;        // IN - user inputs option to run the program

    option = 'A';

    // until user inputs Q or q to quit the program
    while (option != 'Q')
    {
        cout << "Menu\n";
        cout << "  - Display Messages ('D' or 'd')\n";
        cout << "  - Add New Message ('N' or 'n')\n";
        cout << "  - Quit ('Q' or 'q')\n";
        cout << "Choose an action: ";
        cin >> option;

        option = toupper(option);
        
        // user chooses to display messages
        if (option == 'D')
            display();
        
        // user chooses to add new message
        else if (option == 'N')
            add_message();

        // user chooses to quit the program
        else if (option == 'Q')
        {
            cout << "\nBye!\n";
            exit(0);
        }
    }
}

/*****************************************************************************
 * Method add_user:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods adds the users from the file to user_list
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const string &name: username of the user to be added
 *      const string &pass: password of the user to be added
 *    
 * POST-CONDITIONç
 *   the user is added to user_list
 * 
 *****************************************************************************/
void BBoard::add_user(const string &name,   // IN - username to be added
                      const string &pass)   // IN - password to be added
{
    User tempUser;  // CALC - temproary User to store the info. to user_list

    tempUser = User(name, pass);
    
    this->user_list.push_back(tempUser);
}

/*****************************************************************************
 * Method add_message:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods adds message from the user to message_list
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      message_list should be declared
 *    
 * POST-CONDITIONç
 *   the new message is added to message_list
 * 
 *****************************************************************************/
void BBoard::add_message()
{
    string tempSub;     // IN - temporary subject to be added to message_list
    string tempBody;    // IN - temporary body to be added to message_list
    Message newMessage; // CALC/OUT - newMessage to be added to message_list

    cin.ignore();
    cout << "\nEnter Subject: ";
    getline(cin, tempSub);
    cout << "Enter Body: ";
    getline(cin, tempBody);
    cout << "Message Recorded!\n\n";
    newMessage = Message(this->current_user.get_username(), tempSub, tempBody);
    message_list.push_back(newMessage);
}

/*****************
**   Accessor   **
******************/

/*****************************************************************************
 * Method user_exists:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods checks if the user exists
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const string &name: username to be checked if the user exists
 *      const string &pass: password to be checked if the user exists
 *    
 * POST-CONDITIONç
 *   the function will return if the user exists in user_list, 
 *      false if it's not
 * 
 *****************************************************************************/
bool BBoard::user_exists(const string &name,    // IN - username to be checked
                const string &pass) const       // IN - password to be checked
{
    for (int i = 0; i < user_list.size(); i++)
    {
        // when user is found in the user_list
        if (user_list[i].check(name, pass))
            return true;
    }
    return false;
}


/*****************************************************************************
 * Method get_user:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods returns the User with the given name
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      const string &name: username of the user to be returned
 *    
 * POST-CONDITIONç
 *   the function will return the User with the given name
 * 
 *****************************************************************************/
User BBoard::get_user(const string &name) const // IN - usrname of the user 
{
    for (int i = 0; i < user_list.size(); i++)
    {
        if (user_list[i].get_username() == name)
            return user_list[i];
    }
    return User();
}

/*****************************************************************************
 * Method display:  Class BBoard
 * 
 * ---------------------------------------------------------------------------
 * This methods displays messages in message_list
 * 
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      message_list should conatin any message
 *    
 * POST-CONDITIONç
 *   user can see the messages in the message_list
 * 
 *****************************************************************************/
void BBoard::display() const
{
    // when message_list is empty
    if (message_list.size() == 0)
        cout << "\nNothing to display\n";
    else
    {   cout << endl;
        for (int i = 0; i < 47; i++)
            cout << "-";
        cout << endl;
        for (int i = 0; i < message_list.size(); i++)
        {
            cout << "Message #" << i + 1 << " : ";
            message_list[i].display();
        }
        cout << endl;
    }
}

