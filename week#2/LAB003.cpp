/*******************************************************************************
 * AUTHOR    : Jessica Hahm, Jibran Khan
 * LAB #03   : Structures - Inventory Bins
 * CLASS     : CS003A
 * SECTION   : 32276
 * DUE DATE  : 1/19/21
*******************************************************************************/

#include<iostream>
#include<fstream>
#include<istream>
#include<iomanip>

using namespace std;

/*******************************************************************************
 *
 * Structures - Inventory Bins
 *_________________________________________________________________
 * <description>
 *  This program simulates inventory bin in a warehouse
 *  - returns the inventory lists 
 *_________________________________________________________________
 * INPUTS:
 *  string inputFileName: User inputs file name
 *  string descripiton: User inputs new description to add a item
 *  int number: User inputs a number of new item
 *  char optoin: User decides to add item, search item, or quit
 *  char modifyChart: User decides to add or remove the number of item
 * 
 * OUTPUTS:
 *  returns invenotry lists
 * 
*******************************************************************************/


struct Inventory                                                                    // strucutre type variable
{
    string Description;                                                             // description of item
    int numOfParts;                                                                 // number of item
};

//FUNCTION PROTOTYPES

/*******************************************************************************
 * openInputFile(ifstream& inStream, string inputFileName)
 *  This function check if the input file is valid
 *  - returns "Input file opening failed." if the input file is invalid
 *      
*******************************************************************************/
void openInputFile(ifstream& inStream,                                              // IN - input file stream
                     string inputFileName);                                         // IN - input file name


/*******************************************************************************
 * storeInventory(ifstream& inStream, Inventory currentInventory[])
 *  This funtions read inventory list from the input file and store it
 *  - returns nothing
 *      
*******************************************************************************/
int storeInventory(ifstream& inStream,                                              // IN - input file stream
                    Inventory currentInventory[]);                                  // CALC - current inventory array


/*******************************************************************************
 * showMenu(int version)
 *  This function displays menu and ask user to enter the option
 *  - returns character correspoinding to the option
 *      
*******************************************************************************/
char showMenu(int version);                                                         // IN - version of menu(1: general, 2: when user choses 's')


/*******************************************************************************
 * findDescripiton(Inventory currentInventory[],string description, int size)
 *  This function finds a description from the user in the currentInventory[]
 *  - returns the correspoinding index number of description/ -1 when not found
 *      
*******************************************************************************/
int findDescription(Inventory currentInventory[],                                   // IN - current inventory array
                    string description,                                             // IN - description from the user
                     int size);                                                     // IN - size of "currentInventory[]"


/*******************************************************************************
 * addParts(Inventory currentInventory[], int index)
 *  This function adds parts to specific item
 *  - returns nothing
 *      
*******************************************************************************/
void addParts(Inventory currentInventory[],                                         // CALC - current inventory array 
                int index);                                                         // IN - index number of the element to be added

/*******************************************************************************
 * removeParts(Inventory currentInventory[], int index)
 *  This function removes parts to specific item
 *  - returns nothing
 *      
*******************************************************************************/
void removeParts(Inventory currentInventory[],                                      // CALC - current inventory array
                 int index);                                                        // IN - index number of the element to be removed

/*******************************************************************************
 * addItem(Inventory currentInventory[], int& size)
 *  This function add item to currentInventory
 *  - returns size of the currentInventory[](call-by-reference)
 *      
*******************************************************************************/
void addItem(Inventory currentInventory[],                                          // CALC - current inventory array
                int& size);                                                         // CALC - size of the array(Call-by-reference)


/*******************************************************************************
 * void displayInventory(const Inventory currentInventry[], const int size          // IN - current inventory array(constant variable)
 *  This function displays the currentInventory
 *  - returns the current inventory chart
 *      
*******************************************************************************/
void displayInventory(const Inventory currentInventry[],                            // IN - current inventory array(constant variable)
                        const int size);                                            // IN - size of the array(constant variable)



int main()
{
    string fileName;                                                                // IN - User inputs file name
    string partName;                                                                // IN -  User inputs description to select a bin
    int size;                                                                       // CALC - size of the array
    int index;                                                                      // CALC - correspoinding index number of certain item
    char option;                                                                    // IN - User chooses from the general option 
    char modifyChart;                                                               // IN -  User chooses from the option for modifying item
    bool run;                                                                       // CALC - boolean variable to run the program
    Inventory currentInventory[30];                                                 // CALC - array with current items' description and number
    
    ifstream inStream;                                                              // IN - input file stream
    option = 'a';
    modifyChart = 'a';
    run = true;

    // INPUT -- get the input file from the user
    cout << "Enter name of inventory file: ";
    cin >> fileName;
    openInputFile(inStream, fileName);
    size = storeInventory(inStream,currentInventory);

    // PROCESSING -- run the program until user enter 'q' to stop
    while(run)
    {   
        // OUTPUT -- show current inventory chart
        displayInventory(currentInventory,size);

        // PROCESSING -- provie a general menu(a,s,q) 
        option = showMenu(1);

        // PROCESSING -- until user intputs valid otion
        while(!(option == 'a' || option == 's' || option == 'q'))
            option = showMenu(1);

        // PROCESSING -- when user decides to add item to the list
        if(option == 'a')
            addItem(currentInventory,size);

        // PROCESSING -- when user decides to search certain item
        else if(option == 's')
        {
            cout << "Bin Selection: ";
            cin.ignore();
            getline(cin,partName);

            // PROCESSING -- find description in the current inventory
            index = findDescription(currentInventory,partName,size);

            // PROCESSING -- when index number is foun
            if(index != -1)
            {   
                // PROCESSING -- provide a menu for modifying item
                modifyChart = showMenu(2);

                // PROCESSSING --  until user inptus valid optoin
                while(!(modifyChart == 'a' || modifyChart == 'r'))
                    modifyChart = showMenu(2);
                
                // PROCESSING -- when user wants to add the numebr of item
                if(modifyChart == 'a')
                    addParts(currentInventory,index);

                // PROCESSING -- whne user want to remove the numebr of item
                else if(modifyChart == 'r')
                    removeParts(currentInventory,index);
            }
            // PROCESSING -- when the item doesn't exist 
            else
                cout << "The item doesn't exist!\n";
        }
        // PROCESSING -- when the user wants to stop running the program
        else if(option == 'q')
        {
            cout << "Good Bye!!!\n";
            run = false;
        }
    }
}

//FUNCTION DEFINITIONS

/*******************************************************************************
 * openInputFile(ifstream& inStream, string inputFileName)
 *_________________________________________________________________
 * This function check if the input file is valid
 *  - returns "Input file opening failed." whem it's invalid
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   ifstream& inStream: input file stream
 *   string inputFileName: input file name from the user
 *
 * POSTCONDITIONS:
 *  N/A
 * 
*******************************************************************************/
void openInputFile(ifstream& inStream,                                              // IN - input file stream                                                                              
                 string inputFileName)                                              // IN - input file name
{   
    inStream.open(inputFileName);                     

    // PROCESSING -- when input file is invalid 
    if(inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
}   

/*******************************************************************************
 * storeInventory(ifstream& inStream, Inventory currentInventory[])
 *_________________________________________________________________
 *  This funtions read inventory list from the input file and store it
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   ifstream& inStream: input file stream
 *   Inventory currentInventory[]: structure array with current inventory
 *
 * POSTCONDITIONS:
 *  returns currentInventor[] with data from the input file
 *
*******************************************************************************/
int storeInventory(ifstream& inStream,                                              // IN - input file stream             
                 Inventory currentInventory[])                                      // IN - input file name
{
    string description;                                                             // IN - description from the input file
    int number;                                                                     // IN - number of individual item from the file
    int size;                                                                       // IN - the total item numebrs
    char next;                                                                      // CALC - temporary variable to read the fil

    size = 0;

    // PROCESSING -- read until end of file
    while(inStream >> next)
    {
        inStream.putback(next);
        getline(inStream,description);

        // PROCESSING -- store description to currenInventory[]
        currentInventory[size].Description = description;
        inStream >> number;

        // PROCESSING -- store number of parts to currenInventory[]
        currentInventory[size].numOfParts = number;
        inStream.ignore();

        // PROCESSING -- increase size of currentInventory[]
        size++;
    }

    // OUT -- return the size currentInventory[] for later calculation
    return size;
}

/*******************************************************************************
 * showMenu(int version)  
 *_________________________________________________________________
 *  This function displays menu and ask user to enter the option
 *  - returns character correspoinding to the option
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   int version: menu for general or selection
 *
 * POSTCONDITIONS:
 *  char option: retuns options from the user
 *
*******************************************************************************/
char showMenu(int version)                                                          // IN - version of menu(1: general, 2: when user choses 's')
{
    char option;                                                                    // IN - user chooses the option
    cout << "\nMenu:\n";

    // PROCESSING -- general menu which gets 'a','s' or 'q'
    if(version == 1)
    {
        cout << "Add a new item (a)\n";
        cout << "Select a bin (s)\n";
        cout << "Quit (q)\n";
        
        cout << "\nSelection: ";
        cin >> option;
        if(option == 'a' || option == 's' || option == 'q')
            return option;
    }

    // PROCESSING -- menu for modifying item which gets 'a' or 'r'
    else if(version == 2)
    {
        cout << "Add parts (a)\n";
        cout << "Remove parts (r)\n";
        cout << "\nSelection: ";
        cin >> option;
        if(option == 'a' || option == 'r')
            return option;
        else;
    }

    return 0;
}

/*******************************************************************************
 * findDescription(Inventory currenInventory[], string descriptino, int size)
 *_________________________________________________________________
 *  This function finds a description from the user in the currentInventory[]
 *  - returns the correspoinding index number of description/ -1 when not found
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Inventory currentInventory[]: structure array with current inventory
 *   string description: description from the user
 *   int size: size of the currentInventory array
 *
 * POSTCONDITIONS:
 *  int index: corresponding index of the description in the array
 *
*******************************************************************************/
int findDescription(Inventory currentInventory[],                                   // IN - current inventory array
                    string description,                                             // IN - description from the user
                    int size)                                                       // IN - size of currentInventory[]
{
    int index;                                                                      // CALC - corresponding index number to descritpion
    index = -1;
    for(int i = 0; i < size; i++)
    {
        // PROCESSING -- when description is found in currentInventory[]
        if(description == currentInventory[i].Description)
        {
            index = i;
            break;
        }
    }
    return index;
}

/*******************************************************************************
 * addParts(Inventory currentInventory[], int index)
 *_________________________________________________________________
 *  This function adds parts to specific item
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Inventory currentInventory[]: structure array with current inventory
 *   int index: corresponding index of the description in the arra
 *
 * POSTCONDITIONS:
 *  the numebr of item is added
 *
*******************************************************************************/
void addParts(Inventory currentInventory[],                                         // CALC - current inventory array
                 int index)                                                         // IN - index number of the element to be added
{
    int number;                                                                     // IN - user inputs the number of parts to be added
    cout << "Number of parts to add: ";
    cin >> number;

    // PROCESSING -- add more number into the item
    currentInventory[index].numOfParts += number;
}

/*******************************************************************************
 * reomoveParts(Inventory currentInventory[], int index)
 *_________________________________________________________________
 *  This function removes parts to specific item
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Inventory currentInventory[]: structure array with current inventory
 *   int index: corresponding index of the description in the arra
 *
 * POSTCONDITIONS:
 *  the numebr of item is removed
 *
*******************************************************************************/
void removeParts(Inventory currentInventory[],                                      // CALC - current inventory array
                int index)                                                          // IN - index numebr of the element to be removed 
{
    int number;                                                                     // IN - user inputs the number of parts to be removed
    cout << "Number of parts to remove: ";
    cin >> number;

    // PROCESSING -- the programa can't have negative numebr for item
    if(currentInventory[index].numOfParts - number >= 0)
        currentInventory[index].numOfParts -= number;
     
}

/*******************************************************************************
 * addItem(Inventory currentInventory[], int& size)
 *_________________________________________________________________
 *  This function add item to currentInventory
 *  - returns size of the currentInventory[](call-by-reference)
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Inventory currentInventory[]: structure array with current inventory
 *   int& size: the size of currentInventory[]
 *
 * POSTCONDITIONS:
 *  the size of currentInventory[] is changed and item is added to the list
 *
*******************************************************************************/
void addItem(Inventory currentInventory[],                                          // IN - current inventory array(constant variable)
             int& size)                                                             // IN - size of the array(constant variable)
{
    string partName;                                                                // IN - uesr inputs the item name
    int number;                                                                     // IN - user inputs the numebr of item
    int index;                                                                      // CALC - check if the item already exists in the inventory

    // PROCESSING -- invnetory can't store more than 30items
    if(size < 30)
    {
        // INPUT -- get the description of item from the user to add
        cout <<"\nEnter Part Description: ";
        cin.ignore();
        getline(cin,partName);

        // PROCESSING -- check if the item already exists in the inventory
        index = findDescription(currentInventory,partName,size);

        // PROCESSING -- when item already exists in the inventory
        if(index != -1)
        {
            cout << "The " << partName << " already exists!\n";
            cout << "Numper of parts to add: ";
            cin >> number;

            // PROCESSING -- add the number of item into the inventory
            currentInventory[index].numOfParts += number;
        }

        // PROGRESSING -- when item doesn't exist in the inventory
        else
        {
            cout << "Number of Parts in the Bin: ";
            cin >> number;

            // PROGRESSING -- add item into the inventory
            currentInventory[size].Description = partName;
            currentInventory[size].numOfParts = number;
            size++;
            cout << endl;
        }
    }
    else
        cout << endl;
    
}

/*******************************************************************************
 * displayInventory(const Inventory currentInventory[], const int size)
 *_________________________________________________________________
 *  This function displays the currentInventory
 *  - returns the current inventory chart
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   const Inventory currentInventory[]: current inventory array(const)
 *   const int size: size of currentInventory[]
 * 
 * POSTCONDITIONS:
 *  dipsaly currentInventory 
 *
*******************************************************************************/
void displayInventory(const Inventory currentInventry[],                            // IN - current inventory array(constant variable)
                        const int size)                                             // IN - size of the array(costant variable)
{
    for(int i = 0; i < size; i++)
    {   
        // OUTPUT -- display the current inventory chart
        cout << left << setw(20) << currentInventry[i].Description 
            << right << setw(3) << currentInventry[i].numOfParts << endl;
    }
}

