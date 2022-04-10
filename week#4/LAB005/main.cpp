/*******************************************************************************
 * AUTHOR         : Jessica Hahm, Jason Boenjamin
 * Lab #5         : Vectors Review
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 02/03/22
*******************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

/*******************************************************************************
 *
 * Vectors
 *_________________________________________________________________
 * <description>
 * This program performs vector member functions
 *_________________________________________________________________
 * INPUTS:
 *  vector<int> v       : Default vector 
 *  vector<int> v2 (5)  : Vector with size 5, all initialized to 0
 *  vector<int> v3(5,9) : Vector with size 5, all initialized to 9
 *
 * OUTPUTS:
 *  N/A
 *
*******************************************************************************/


int main(void)
{
    
    vector<int> v;          // IN - vector with default contuctor
    vector<int> v2 (5);     // IN  - vector with one constructor
    vector<int> v3(5,9);    // IN - vector with two constructor
    vector<int>::iterator it;   // CALC - iterator
    
    it = v.begin();
    
    //Test case to test the default constructor
    cout << "Testing default constructor\n";
    cout << "size: "<< v.size() << " capacity: "<< v.capacity() << endl;
    cout << "Testing empty member function\n";
    if(v.empty())
        cout << "v is empty\n";
    else
        cout << "v is not empty\n";
    
    //Test case to test the one parameter constructor
    cout << "\nTesting One parameter constructor\n";
    cout << "size: "<< v2.size() << " capacity: "<< v2.capacity() << endl;
    cout << "Testing empty member function\n";
    if(v2.empty())
        cout << "v2 is empty\n";
    else
    {
        cout << "v is not empty\n";
        cout << "Testing at function by displaying v2\n";
        for(int i = 0; i < v2.size(); i++)
            cout << v2[i] << " ";
        cout << endl;
    }
        
    //Test case to test the two parameter constructor
    cout << "\nTesting Two parameter constructor\n";
    cout << "size: "<< v3.size() << " capacity: "<< v3.capacity() << endl;
    cout << "Testing empty member function\n";
    if(v3.empty())
        cout << "v3 is empty\n";
    else
    {
        cout << "v is not empty\n";
        cout << "Testing at function by displaying v3\n";
        for(int i = 0; i < v3.size(); i++)
            cout << v3[i] << " ";
        cout << endl;
    }
        

    //Test case to test the push_back() function
    cout << "\nTesting push back function\n";
    for(int i = 0; i < 10; i++)
    {
        v.push_back(0);
        cout << "size: " <<  v.size() << " capacity: " << v.capacity() << endl;
    }
    
    //Test case to test the pop_back() function
    cout << "\nTesting pop back function\n";
    for(int i = 0; i < 2; i++)
    {
        v.pop_back();
        cout << "size: "<< v.size() << " capacity: " << v.capacity()<< endl;
    }


    for(int i = 0; i < v.size(); i++)
        v[i] = i;
    cout << endl;

    cout << "Testing front and back functions\n";
    cout << "front: " << v.front() << " back: " << v.back() << endl; 

    //Test case to test the insert() function
    cout << "\nTesting insert() function by adding at position 5\n";

    it = v.insert(v.begin()+5, 100);
    for(int i = 0 ; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    
    //Test case to test the erase() function
    cout << "\nTesting erase() function by erasing position 6\n";
    it = v.erase(v.begin() + 6);
    for(int i = 0 ; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    //Test case to test the resize() function with one parameter
    cout << "\nTesting resize() function (one parameter)\n";
    v.resize(20, 0);
    cout <<"size: " << v.size() << " capacity: " << v.capacity() << endl;
    for(int i = 0; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.resize(10);
        
    cout <<"size: " << v.size() << " capacity: " << v.capacity() << endl;
    for(int i = 0; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
   
   //Test case to test the resize() function with two parameter
    cout << "\nTesting resize() function (two parameter)\n";
    v.resize(20,101);
    cout << "size: "<< v.size() << " capacity: " << v.capacity() << endl;
   
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;
    v.resize(10);
    cout << "size: " << v.size() << " capacity: "<< v.capacity() << endl;
   
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

     cout << endl;

   //Test case to test the assign() function
    cout << "\nTesting assign() function\n";
    v2.resize(20);
    v2.assign(5,102);
    cout << "size: " << v2.size() << " capacity: "<< v2.capacity() << endl;
   
    for(int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    
    cout << endl;

   //Test case to test the clear() function
    cout << "\nTesting clear() function\n";
    v2.clear();
    cout << "size: "<< v2.size()<< " capacity: " << v2.capacity() << endl<< endl;

    return 0;
}
