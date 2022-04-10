#include <iostream>
#include "IntList.h"

using namespace std;


int main()
{
    IntList L1, L2;

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
    for (int i = 0; i < 10; i++)
    {
        L1.push_front(i);
    }

    cout << "Testing display function on list with several items\n";
    L1.display();
    cout << endl;

    cout << "\nTesting the pop_front function\n";
    for (int i = 0; i < 5; i++)
    {
        L1.pop_front();
    }

    cout << "Testing display function after calling pop_front 5 times\n";
    L1.display();
    cout << endl;
}

/*
Testing display function on empty List

Testing display function on one item List
100

Testing display function on two item List
200 100

Testing push_front function (by calling it 10 times)
Testing display function on list with several items
9 8 7 6 5 4 3 2 1 0 200 100

Testing the pop_front function
Testing display function after calling pop_front 5 times
4 3 2 1 0 200 100
*/