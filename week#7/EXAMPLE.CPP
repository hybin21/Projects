#include<iostream>

using namespace std;

class foo{
public:
    //constructor
    foo();
    
    //copy constructor
   foo(foo&);
    
    //destructor
    ~foo();
        
    //overloaded asssignment operator
   foo& operator=(const foo&);
        
    void display();
   void addOne();
        
private:
    int size;
    int *intPtr;
};

int main(){
    foo f1;

    f1.display();

    cout << endl;
    foo f2(f1);
    f2.display();
    f2.addOne();
    
    cout << endl;
    cout << "after addOne" << endl;
    cout << "displaying f2: ";
    f2.display();
    cout << "displaying f1: ";
    f1.display();
    cout << endl;
    
    
    cout << endl;
    foo f3;
    cout << "Using the assignment operator for f3 = f2\n";
    f3 = f2;
    cout << "displaying f3: ";
    f3.display();
    cout << "displaying f2: ";
    f2.display();

    cout << endl;
    foo f4 = f2;
    cout << "displaying f4: ";
    f4.display();
   
}

foo::foo(){
    cout << "default constructor called" << endl;
    size = 10;
    intPtr = new int[size];
    for (int i = 0; i < size; i++)
        intPtr[i] = i*5;
}

foo::~foo(){
    cout << "Destructor called" << endl;
    delete [] intPtr;
}



foo::foo(foo& other){
    cout << "copy constructor called" << endl;
    size = other.size;
    
    //dyanmically allocating memory to new object
    intPtr = new int[size];
    
    //copy over elements from old object to new object
    for (int i = 0; i < size; i++)
        intPtr[i] = other.intPtr[i];
}



foo& foo::operator=(const foo& other){

        cout << "copy assignment operator called" << endl;
        size = other.size;
        
        //free up memory allocated from default constructor
        if(intPtr)
            delete [] intPtr;
        
        //dyanmically allocating memory to new object
        intPtr = new int[size];
        
        //copy over elements from old object to new object
        for (int i = 0; i < size; i++)
            intPtr[i] = other.intPtr[i];

    return *this;
}


void foo::display(){
    cout << "Base address: " << intPtr << endl;
    for (int i = 0; i < size; i++)
        cout << intPtr[i] << " ";
    cout << endl;
}

void foo::addOne(){
    for (int i = 0; i < size; i++)
        intPtr[i] = intPtr[i] + 1;    
}
