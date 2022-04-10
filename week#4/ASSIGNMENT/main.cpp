/*******************************************************************************
 * AUTHOR            : Jessica Hahm
 * ASSIGNMENT #04    : Bulletin Board
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 02/09/22
*******************************************************************************/

#include "message.h"    // include Message class 
#include "bboard.h"     // include BBoard class
#include "user.h"       // include User class

/*******************************************************************************
 *
 * Bulletin Board
 *_________________________________________________________________
 *  This program generates bulletin board program that user can log in, 
 *      add messages, and see messages
 *    - returns the messages that user entered 
 *_________________________________________________________________
 * INPUTS:
 *  string title: title of the board
 *  char fileName[]: name of the input file
 *  string author: author of the message
 *  string subject: subject of the message
 *  string body: body of the message
 *  string username: username of the user
 *  string password: password of the user
 *
 * OUTPUTS:
 *  string author: author of the message
 *  string body: body of the message
 *  string subject: subject of the message
 *
*******************************************************************************/

int main(int size,      // IN - number of comman line arguments
     char* fileName[])  // IN - file name of input file
{
    string inputFileName;   // IN/CALC - file name of input file

    // store input file name with c-string to input file name with string type
    inputFileName = fileName[1];    

    // create a BBoard class
    BBoard board("Jessica's Bulletin Board"); 

    // setup BBoard class by reading input file and store the info. into class
    board.setup(inputFileName);

    // user logs in to the bulletin board program
    board.login();

    // the program runs
    board.run();

    return 0;
}