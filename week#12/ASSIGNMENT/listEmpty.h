#ifndef LISTEMPTY_H
#define LISTEMPTY_H
#include "linkedList.h"
#include <iostream>
using namespace std;

class ListEmpty
{   
    private:
        string message;
    
public:
    ListEmpty(){message = "List is empty!";}
    ListEmpty(string input){message = input;}
    string what() {return message;}
};
#endif

