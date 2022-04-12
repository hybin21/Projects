#include <iostream>
#include "linkedList.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void testInts();
void testDoubles();
void testStrings();

int main()
{ 
    int choice;
    
    cout << "Choose a data type to test template with" << endl;

    cout << "1.integer\n2.doubles\n3.strings" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            testInts();
            break;
        case 2:
            testDoubles();
            break;
        case 3:
            testStrings();
            break;
        default:
            testStrings();
            break;
    }
    
    return 0;
}

void testInts()
{
    LinkedList<int> L1, L2;
    
    LinkedList<int>::Iterator it;

    cout << "Testing front() back() and pop_front() on empty list" << endl;
    try
    {
        cout << L1.front() << endl;
    }
    catch(ListEmpty<int> e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << L1.back() << endl;
    }
    catch(ListEmpty<int> e)
    {
        cout << e.what() << endl;
    }
    try
    {
        L1.pop_front();
    }
    catch(ListEmpty<int> e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "Exception thrown" << endl;
    }
    

    cout << "Testing display function on empty List\n";
    L1.display();
    
    cout << "\nTesting display function on one item List\n";
    L1.push_front(100);
    L1.display();
    cout << endl;
    
    cout << "\nTesting display function on two item List\n";
    L1.push_front(200);
    L1.display();
    cout << endl;
    
    cout << "\nTesting push_front function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.push_front(i);
    }
    
    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;
    
    cout << "\nTesting the pop_front function\n";
    for (unsigned i = 0; i < 5; i++){
        L1.pop_front();
    }
    
    cout << "Testing iterator to print list after calling pop_front 5 times\n";
    for(it = L1.begin(); it != L1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nTesting push_back function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.push_back(rand()%10);
    }
    
    L1.display();
    cout << endl;
    
    cout << "\nTesting select_sort() function\n";
    L1.select_sort();
    L1.display();
    cout << endl;
    
    cout << "\nTesting insert_sorted function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.insert_sorted(rand()%10);
        cout << endl;
        L1.display();
    }
    
    cout << "\nTesting remove_duplicates() function\n";
    L1.remove_duplicates();
    L1.display();
    cout << endl;
	
	cout << "\nTesting push_back() and push_front() function\n";
    for (int i = 0; i < 10; i++){
        L2.push_front(i);
        L2.push_back(i);
    }

	cout << endl;
    cout << "Displaying with iterator" << endl;
    for(it = L2.begin(); it != L2.end(); ++it)
    {
        cout << *it << " ";
    }
	cout << endl;  
}
void testDoubles()
{
    LinkedList<double> L1, L2;
    
    LinkedList<double>::Iterator it;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << "Testing front() back() and pop_front() on empty list" << endl;
    try
    {
        cout << L1.front() << endl;
    }
    catch(const ListEmpty<int> &e)
    {
        cout << "List is empty so there is no front" << endl;
    }
    try
    {
        cout << L1.back() << endl;
    }
    catch(const ListEmpty<int> &e)
    {
        cout << "List is empty so there is no back" << endl;
    }
    catch(...)
    {
        cout << "Exception thrown" << endl;
    }
    

    cout << "Testing display function on empty List\n";
    L1.display();
    
    cout << "\nTesting display function on one item List\n";
    L1.push_front(13.1434);
    L1.display();
    cout << endl;
    
    cout << "\nTesting display function on two item List\n";
    L1.push_front(12.11);
    L1.display();
    cout << endl;
    
    cout << "\nTesting push_front function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.push_front(i/.3*2);
    }
    
    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;
    
    cout << "\nTesting the pop_front function\n";
    for (unsigned i = 0; i < 5; i++){
        L1.pop_front();
    }
    
    cout << "Testing iterator to print list after calling pop_front 5 times\n";
    for(it = L1.begin(); it != L1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nTesting push_back function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.push_back((rand()%10) * 1.2 * 42);
    }
    
    L1.display();
    cout << endl;
    
    cout << "\nTesting select_sort() function\n";
    L1.select_sort();
    L1.display();
    cout << endl;
    
    cout << "\nTesting insert_sorted function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.insert_sorted(rand()%10);
        cout << endl;
        L1.display();
    }
    
    cout << "\nTesting remove_duplicates() function\n";
    L1.remove_duplicates();
    L1.display();
    cout << endl;
	
	cout << "\nTesting push_back() and push_front() function\n";
    for (int i = 0; i < 10; i++){
        L2.push_front(i/2.1);
        L2.push_back(i/1.232);
    }

	cout << endl;
    cout << "Displaying with iterator" << endl;
    for(it = L2.begin(); it != L2.end(); ++it)
    {
        cout << *it << " ";
    }
	cout << endl;
	cout << endl;
}
void testStrings()
{
    LinkedList<string> L1, L2;
    
    LinkedList<string>::Iterator it;

    string words[] = {"Hello","Angel","CS003A","Happy","Food",
          "Computer","Science","Tacos","Dog","Guitar"};



    cout << "Testing front() back() and pop_front() on empty list" << endl;
    try
    {
        cout << L1.front() << endl;
    }
    catch(const ListEmpty<int> &e)
    {
        cout << "List is empty so there is no front" << endl;
    }
    try
    {
        cout << L1.back() << endl;
    }
    catch(const ListEmpty<int> &e)
    {
        cout << "List is empty so there is no back" << endl;
    }
    catch(...)
    {
        cout << "Exception thrown" << endl;
    }
    

    cout << "Testing display function on empty List\n";
    L1.display();
    
    cout << "\nTesting display function on one item List\n";
    L1.push_front("Hello");
    L1.display();
    cout << endl;
    
    cout << "\nTesting display function on two item List\n";
    L1.push_front("World");
    L1.display();
    cout << endl;
    
    cout << "\nTesting push_front function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.push_front(words[i]);
    }
    
    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;
    
    cout << "\nTesting the pop_front function\n";
    for (unsigned i = 0; i < 5; i++){
        L1.pop_front();
    }
    
    cout << "Testing iterator to print list after calling pop_front 5 times\n";
    for(it = L1.begin(); it != L1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nTesting push_back function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.push_back(words[rand()%10]);
    }
    
    L1.display();
    cout << endl;
    
    cout << "\nTesting select_sort() function\n";
    L1.select_sort();
    L1.display();
    cout << endl;
    
    cout << "\nTesting insert_sorted function (by calling it 10 times)\n";
    for (unsigned i = 0; i < 10; i++){
        L1.insert_sorted(words[rand()%10]);
        cout << endl;
        L1.display();
    }
    
    cout << "\nTesting remove_duplicates() function\n";
    L1.remove_duplicates();
    L1.display();
    cout << endl;
	
	cout << "\nTesting push_back() and push_front() function\n";
    for (int i = 0; i < 10; i++){
        L2.push_front(words[i]);
        L2.push_back(words[i]);
    }

	cout << endl;
    cout << "Displaying with iterator" << endl;
    for(it = L2.begin(); it != L2.end(); ++it)
    {
        cout << *it << " ";
    }
	cout << endl;
    

}
