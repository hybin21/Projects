#include <iostream>
#include "IntList.h"
#include <time.h>
#include <stdlib.h>

#define TO_STREAM(stream,variable) (stream) <<#variable": "<<(variable)

using namespace std;

/*******************************************************************
 * Linked List Recursion
 * _________________________________________________________________
 * The program is a linked list of nodes (IntNode), which store a
 *    integer. It contains functions such as display(), push_front(),
 *    push_back(), pop_front(), select_sort(), insert_sorted(), and
 *    remove_duplicates() in order to manipulate the list.
 *    Big 3: Copy constructor, assing operator and destructor
 *    Recursion: length() const, sum() const, reverseDisplay() const;
 * _________________________________________________________________
 * INPUT:
 *    - none
 *
 * OUTPUT:
 *    - L1 : IntList object, testing IntList class member functions
 *    - L2 : IntList object, testing IntList class member functions
 *    - L3 : IntList object, testing IntList class member functions
 ******************************************************************/

int main()
{
    IntList L1;
    IntList L3;
    
    IntListIterator it;
    
    int testNum;
    
    cout << "Enter test number: " << endl;
    cin >> testNum;
    
    for (unsigned i = 0; i < 10; i++){
        L1.push_front(i);
    }
    
    if(testNum == 1)
    {
        cout<< "L1: ";
        for (it = L1.begin(); it != L1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
        return 0;
    }
    else if (testNum == 2)
    {
        cout << "TESTING: L1 front and back functions" << endl;
        cout << L1.front() << "\t" << L1.back() << endl << endl;
        return 0;
    }
    else if(testNum == 3)
    {
        cout << "TESTING: length, sum, and reverse display of L1" << endl;
        cout << "Length: " << L1.length() << endl;
        cout << "Sum   : " << L1.sum() << endl;
        cout << "Reverse display: " << endl;
        L1.reverseDisplay();
        cout << endl << endl;
        return 0;
    }
    
    //for testing copy constructor (testNum == 4)
    IntList L2(L1);
    for (unsigned i = 0; i < 5; i++){
        L1.push_front(i);
    }
    
    if(testNum == 4)
    {
        cout << "TESTING: Copy constructor (L2): " << endl;
        cout << "L1: ";
        for (it = L1.begin(); it != L1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
        cout << "L2: ";
        for (it = L2.begin(); it != L2.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
        
        cout << "TESTING: L2 front and back functions" << endl;
        cout << L2.front() << "\t" << L2.back() << endl << endl;
    
        cout << "TESTING: length, sum, and reverse display of L2" << endl;
        cout << "Length: " << L2.length() << endl;
        cout << "Sum   : " << L2.sum() << endl;
        cout << "Reverse display: " << endl;
        L2.reverseDisplay();
        cout << endl << endl;
        return 0;
    }

    //for testing assignment operator (testNum == 5)
    L3 = L2;
    for (unsigned i = 0; i < 5; i++){
        L2.push_front(i);
    } 
    
    if (testNum == 5)
    {
        cout << "TESTING: Assign operator (L3 = L2 ; empty L3): " << endl;
        cout << "L2: ";
        for (it = L2.begin(); it != L2.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
        cout << "L3: ";
        for (it = L3.begin(); it != L3.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
        
        cout << "TESTING: L3 front and back functions" << endl;
        cout << L3.front() << "\t" << L3.back() << endl << endl;
    
        cout << "TESTING: length, sum, and reverse display of L3" << endl;
        cout << "Length: " << L3.length() << endl;
        cout << "Sum   : " << L3.sum() << endl;
        cout << "Reverse display: " << endl;
        L3.reverseDisplay();
        cout << endl << endl;
        return 0;

    }

    for (unsigned i = 0; i < 10; i++){
            L1.push_front(i);
    }
    L2 = L1;

    if (testNum == 6)
    {
        cout << "New L1 for testing Assignment operator: " << endl;
        for (it = L1.begin(); it != L1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "TESTING: Assign operator (L2 = L1):" << endl;

        cout << "L2: ";
        for (it = L2.begin(); it != L2.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
    
        cout << "TESTING: L2 front and back functions" << endl;
        cout << L2.front() << "\t" << L2.back() << endl << endl;
    
        cout << "TESTING: length, sum, and reverse display of NEW L2" << endl;
        cout << "Length: " << L2.length() << endl;
        cout << "Sum   : " << L2.sum() << endl;
        cout << "Reverse display: " << endl;
        L2.reverseDisplay();
        cout << endl << endl;
        return 0;
    }
    
    
    IntList L4;
    int count = 0;
    
    if(testNum == 7)
    {
        cout << "Testing: Iterator copying elements of L1 into L4:" << endl;
        for (it = L1.begin(); it != L1.end(); ++it, count++ )
        {
            if ((*it)%3 == 0)
                L4.push_back(*it);
            if (count%2 == 0)
                L4.push_front(*it);
        }
        
        cout << "L4: ";
        for (it = L4.begin(); it != L4.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
    
        cout << "TESTING: L4 front and back functions" << endl;
        cout << L4.front() << "\t" << L4.back() << endl << endl;
    }
    return 0;
}
