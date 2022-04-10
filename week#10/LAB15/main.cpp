#include <iostream>
#include "doublyLinkedList.h"
#include <vector>
using namespace std;
/*******************************************************************************
 * LAB 14 - DOUBLY LINKED LISTS
 * ----------------------------------------------------------------------------
 * In this lab, we test class DoublyLinkedList, which includes IntNodes that
 * are linked to nodes in the front and back of them.
 * ----------------------------------------------------------------------------
 * INPUT:
 *  test_choice     : User-inputted integer. Test case number.
 ******************************************************************************/
/*******************************************************************************
 * testX()
 * ----------------------------------------------------------------------------
 * Tests the class DoublyLinkedList and LinkedListIterator on multiple
 * functions.
 ******************************************************************************/
void test1();   // push_front(), push_back()
void test2();   // pop_front(), pop_back()
void test3();   // constructor, destructor
void test4();   // overloaded assignment operator (=)
void test5();   // front(), back(), length()
void test6();   // begin(), end()
void test7();   // sort()
void test8();   // insert_sorted()
void test9();   // remove()

int main()
{
    
    // vector<int> v(5);
    // vector<int>::iterator itv;
    // itv = v.begin();
    // cout << *itv << endl;
    // itv = v.end();
    // cout << *itv << endl;
    
    // VARIABLE
    int test_choice;            // Choice of test case to execute.

    // Notifies the user of what test cases are available.
    cout << "TEST CASES\n"
         << "1: push_front and push_back\n"
         << "2: pop_front and pop_back\n"
         << "3: constructor and destructor\n"
         << "4: overloaded assignment operator\n"
         << "5: front, back, and length\n"
         << "6: iterator\n"
         << "7: sort\n"
         << "8: insert_sorted\n"
         << "9: remove\n"
         << "0: exit program\n";

    // PROCESSING: Continually loops until the user exits the program.
    do
    {

        // INPUT: Asks the user for a test case to execute.
        cout << "\n-------------------------------------" << endl;
        cout << "Enter a test case number: ";
        cin >> test_choice;
        cout << endl;

        // PROCESSING: Chooses the test case to execute.
        switch(test_choice){
            case 1: test1(); break;
            case 2: test2(); break;
            case 3: test3(); break;
            case 4: test4(); break;
            case 5: test5(); break;
            case 6: test6(); break;
            case 7: test7(); break;
            case 8: test8(); break;
            case 9: test9(); break;
        }
    }while(test_choice != 0);
}

/*******************************************************************************
 *  void test1()
 *       Tests the push_back and push_front functions.
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test1(){
    // VARIABLE
    DoublyLinkedList D;

    // OUTPUT: Notifies the user of what functions are being tested.
    cout << "Testing push_back and push_front functions.\n\n";

    // PROCESSING: Test the push_back function.
//    cout << "Calling push_back(i) 5 times.\n";
//    for(int i = 0; i < 6; i++){
//        D.push_back(i);
//    }
//    D.display();

    IntListIterator it;
    it = D.begin();
    // PROCESSING: Tests the push_front function.
    cout << "\nCalling push_front(2) 5 times.\n";
    for(int i = 1; i < 6; i++){
        //cout << "pushing " << i << endl;
        D.push_front(i);
        //cout << *it << endl;
    }
    
    //it = D.end();
    //++it;
    //cout << *it << endl;
    
    // for(int i = 0; i < 4; i++)
    // {
    //     ++it;
    //     cout << *it << endl;
    // }
    // IntListIterator it;
    // it = D.begin();
    // cout << "begin: ";
    // cout << *it << endl;
    
    // // ++it;
    // // cout << *it << endl;
    
    // it = D.end();
    // cout << "end: ";
    // cout << *it << endl;
    // //it = D.begin();
    // //++it;
    // //cout << *it << endl;
    // cout << "eq: " << endl; 
    cout << "\nCalling push_back() 5 times.\n";
    for(int i = 1; i < 6; i++){
        //cout << "pushing " << i << endl;
        D.push_back(i*10);
        //cout << *it << endl;
    }
	
	cout << "test\n";
    for(it = D.begin(); it != D.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl; 
    
    cout << "test2\n";
    for(it = D.end(); it != D.begin(); --it)
    {
        cout << *it << " ";
    }
    cout << endl; 
}

/*******************************************************************************
 *  void test2()
 *       Tests pop_front() and pop_back().
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test2(){
    // VARIABLE
    DoublyLinkedList D;         // Tested List. Goes from 0 to 10.

    // OUTPUT: Notifies the user of what functions will be tested.
    cout << "Testing pop_front and pop_back functions.\n";

    // PROCESSING: Creates a LinkedList to test on.
    for(int i = 0; i < 11; i++){
        D.push_back(i);
    }
	
	IntListIterator it;
	for(it = D.begin(); it != D.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;
	
	cout << "D should have numbers 0 through 10: "; 
    D.display();

    // PROCESSING: Tests pop_back().
    cout << "\nCalling pop_back() 4 times.\n";
    for(int i = 0; i < 4; i++){
        D.pop_back();
    }
    // OUTPUT: Outputs the result.
    D.display();
#if 1
    // PROCESSING: Tests pop_front().
    cout << "\nCalling pop_front() 4 times.\n";
    for(int i = 0; i < 4; i++){
        D.pop_front();
    }
    // OUTPUT: Outputs the result.
    D.display();

    // PROCESSING: Tests the List when deleting all elements.
    cout << "\nCalling pop_front() 3 times.\n";
    for(int i = 0; i < 3; i++){
        D.pop_front();
    }
    // OUTPUT: Outputs the result.
    D.display();
#endif
}

/*******************************************************************************
 *  void test3()
 *       Tests the constructor and destructor.
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test3(){
    // VARIABLE
    DoublyLinkedList D;     // Tested List. An default constesuctor.

    // OUTPUT: Notifies the user of what function is being tested.
    cout << "Testing default constructor.\n";

    // Tests the program on displaying a List with no elements.
    D.display();
}

/*******************************************************************************
 *  void test4()
 *       Tests the overloaded assignment operator.
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test4(){
    // VARIABLES
    DoublyLinkedList D,     // Tested List. Contains only 5's.
                     E;     // Assigned list. Goes from 0 to 4.

    // OUTPUT: Notifies the user of what function will be tested.
    cout << "Testing overloaded assignment operator.\n\n";

    // PROCESSING: Adds IntNodes to both Lists.
    for(int i = 0; i < 5; i++){
        D.push_back(5);
    }
    for(int i = 0; i < 5; i++){
        E.push_back(i);
    }

    // OUTPUT: Outputs the values of both Lists for comparison.
    cout << "DoublyLinkedList D: ";
    D.display();
    cout << "\nDoublyLinkedList E: ";
    E.display();

    // PROCESSING: Uses an overloaded assignment operator on D to copy values
    //             from E.
    cout << "\nCalling D=E;\n";
    D = E;

    // OUTPUT: Outputs the result.
    cout << "DoublyLinkedListD: ";
    D.display();

}

/*******************************************************************************
 *  void test5()
 *       Tests front(), back(), and length().
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test5(){
    // VARIABLES
    DoublyLinkedList D,     // Tested List. Contains values.
                     E;     // Tested List. A default constructor.

    // OUTPUT:Notifies the user of what functions are being tested.
    cout << "Testing front(), back(), and length() functions.\n\n";

    // PROCESSING: Adds values to D from the back.
    for(int i = 0; i < 11; i++){
        D.push_back(i);
    }
    // OUTPUT: Displays the values of D.
    D.display();

    // PROCESSING: Outputs the front node, back node, and total number of nodes
    //             inbetween.
    cout << "\nCalling front(), back(), and length() functions for D.";
    cout << "\nFront: " << D.front();
    cout << "\nBack: " << D.back();
    cout << "\nLength: " << D.length();

    // PROCESSING: Outputs the front, back, and length of a List with no nodes
    //             given.
    cout << "\n\nCalling front(), back(), and length() functions for E.";
    cout << "\nFront: " << E.front();
    cout << "\nBack: " << E.back();
    cout << "\nLength: " << E.length();
}

/*******************************************************************************
 *  void test6()
 *       Tests begin() and end().
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test6(){
    // VARIABLE
    DoublyLinkedList D;         // Tested List.

    // PROCESSING: Adds new nodes to D.
    for(int i = 0; i < 11; i++){
        D.push_back(i);
    }

    // PROCESSING: Outputs the front and back of D using the iterator functions.
    cout << "Testing IntListIterator begin and end functions.\n";
    cout << *D.begin() << "\t" << *D.end();
}

/*******************************************************************************
 *  void test7()
 *       Tests select_sort().
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test7(){
    // VARIABLE
    DoublyLinkedList D;     // Tested List. Contains a random set of numbers.

    // OUTPUT: Notifies the user of what function is being tested.
    cout << "Testing select_sort() function.\n";

    // PROCESSING: Assigns several integers to D from the back.
    D.push_back(100);
    D.push_back(20);
    D.push_back(45);
    D.push_back(8);
    D.push_back(200);

    // OUTPUT: Displays the List to the user.
    cout << "DoublyLinkedList D: ";
    D.display();

    // PROCESSING: Sorts the List from lowest to highest using the select_sort
    //             method.
    cout << "\nCalling select_sort()" << endl;
    D.select_sort();

    // OUPTUT: Displays the newly organized List to the user.
    cout << "DoublyLinkedList D: ";
    D.display();
}

/*******************************************************************************
 *  void test8()
 *       Tests insert_sorted()
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test8(){
    // VARIABLE
    DoublyLinkedList D;         // Tested List. Values inserted via
                                // insert_sorted().

    // OUTPUT: Notifies the user of what function is being tested.
    cout << "Testing insert_sorted() function.\n";

	cout << "Calling insert_sorted() 20 times.\n";
	for(int i = 0; i < 20; i++)
	{
		int num = rand() % 20;
		//cout << "num: " << num << endl;
		D.insert_sorted(num);
		D.display();
	}
	
#if 0
    // PROCESSING: Uses insert_sorted on a List with no values.
    cout << "Calling insert_sorted(3).\n";
    D.insert_sorted(3);
    D.display();

    // PROCESSING: Uses insert_sorted on a List with the same value as the
    //             inputted value.
    cout << "\nCalling insert_sorted(3) again.\n";
    D.insert_sorted(3);
    D.display();

    // PROCESSING: Uses insert_sorted for a value that must be put in the back.
    cout << "\nCalling insert_sorted(9).\n";
    D.insert_sorted(9);
    D.display();

    // PROCESSING: Uses insert_sorted for a value that is in the middle.
    cout << "\nCalling insert_sorted(5).\n";
    D.insert_sorted(5);
    D.display();

    // PROCESSING: Uses insert_sorted for a value that must be in the front.
    cout << "\nCalling insert_sorted(1).\n";
    D.insert_sorted(1);
    D.display();
#endif
}

/*******************************************************************************
 *  void test9()
 *       Tests remove()
 *  Returns nothing -> outputs tests and results.
 ******************************************************************************/
void test9(){
    // VARIABLE
    DoublyLinkedList D;         // Tested List. Removes specified nodes from it.

    // OUTPUT: Notifies the user of what function is being tested.
    cout << "Testing remove() function.\n\n";

    // PROCESSING: Add values to D from the back.
    for(int i = 0; i < 11; i++){
        D.push_back(i);
    }
    cout << "DoublyLinkedList D: ";
    D.display();

    // PROCESSING: Removes the node from D with a value of 4.
    cout << "\nCalling remove(4).\n";
    D.remove(4);
    D.display();

    // PROCESSING: Removes the node from D at the beginning.
    cout << "\nCalling remove(0).\n";
    D.remove(0);
    D.display();

    // PROCESSING: Removes the node from D at the end.
    cout << "\nCalling remove(10).\n";
    D.remove(10);
    D.display();

    // PROCESSING: Tests the function to not remove nodes that are not present.
    cout << "\nCalling remove(100).\n";
    D.remove(100);
    D.display();
}
