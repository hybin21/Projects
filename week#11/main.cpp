/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT 08  : Inheritance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 04/06/22
*******************************************************************************/
#include<iostream>
#include <fstream>
#include "cs003AStudent.h"

/*******************************************************************************
 *
 * Inheritance
 *_________________________________________________________________
 * <description>
 * This programs performs Student data program by using inheritance
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays Student object's data
 *
*******************************************************************************/
using namespace std;

/****************************************************************
* int readFile(Student * array[])
*
* This method reads input file

* --------------------------------------------------------------
*   Parameters: 
        Student * array[]: array to store the data from the file

* --------------------------------------------------------------
*   Return: number of the students

***************************************************************/
int readFile(Student * array[]);    // CALC/OUT - array to store the data

/****************************************************************
* void printAny(Student * student)
*
* This method prints any student objects(cs003a/ student)
* --------------------------------------------------------------
*   Parameters: 
*       Student * student: object to output
* --------------------------------------------------------------
*   Return: none

***************************************************************/
void printAny(Student * student);   // OUT - object to output

int main(void)
{
    cout<<"\n ---Test 1: Student class---\n";
    Student *stu;   // CALC/OUT - student object
    stu = new Student();

    stu->print();
    cout << endl;

    stu->setName("Katy Perry");
    stu->print();
    cout << endl;

    stu->setId(999899);
    stu->print();
    cout << endl;

    stu->setPhone("949-555-1234");
    stu->print();
    cout << endl;

    stu->setAge(30);
    stu->print();
    cout << endl;

    stu->setGender('F');
    stu->print();
    cout << endl;

    stu->setClass_Standing("Freshman");
    stu->print();
    cout << endl;

    stu->setGPA(4);
    stu->print();
    cout << endl;

    delete stu;

    cout<<" ---End of Student class test--- \n";


    cout<<endl<<endl;

    cout<<"\n ---Test 2: CS133Student class---\n";

    CS003AStudent *cs;  // CALC/OUT - CS003AStudent object 
    cs = new CS003AStudent();


    cs->print();
    cout << endl;

    cs->setName("Jim Cramer");
    cs->print();
    cout << endl;

    cs->setId(668899);
    cs->print();
    cout << endl;


    cs->setPhone("949-665-1234");
    cs->print();
    cout << endl;


    cs->setAge(63);
    cs->print();
    cout << endl;


    cs->setGender('M');
    cs->print();
    cout << endl;


    cs->setClass_Standing("Freshman");
    cs->print();
    cout << endl;

    cs->setGPA(3.3);
    cs->print();
    cout << endl;

    cs->setTotalScore(500);
    cs->print();
    cout << endl;


    cs->setKnowledgeOfJava("yes");
    cs->print();
    cout << endl;

    cs->setGradDate(Date(5,16,2015));
    cs->print();
    cout << endl; 

    delete cs;  

    cout<<"\n ---End of CS133Student class test--- \n";

    cout << "\n\n ---Final output---\n";
    Student *list[10];  // CALC/OUT - Student object array
    int size = readFile(list);  // CALC - number of the students

    list[size++] = new CS003AStudent("Jim Cramer", 668899, "949-665-1234", 63, 'M',
    "Freshman", 3.3, 500, "yes", Date(5,12,2016));

    list[size++] = new CS003AStudent("Clayton Kershaw", 156789, "248-555-6543", 29, 'M',
    "Sophomore", 2.5, 700, "no", Date(5,11,2015));

    list[size++] = new CS003AStudent("Jim Rome", 876545, "703-703-7654", 40, 'M',
    "Sophomore", 3.2, 800, "yes", Date(5,11,2015));


    for(int i = 0; i < size; i++)
    {
        printAny(list[i]);
        cout << endl;
    }
    for(int i = 0; i < size; i++)
        delete list[i];

    return 0;
}

/*******************************************************************************
 * int readFile(Student * array[])
 *_________________________________________________________________
 * This function reads input file
 *  - returns size of the array
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Student array[]: Student array to store the data from the input file
 *
 * POSTCONDITIONS:
 *  int size: size of the array
 * 
*******************************************************************************/
int readFile(Student * array[]) // CALC - student array to store the data
{
    string firstName;   // IN - student's firstname
    string lastName;    // IN - student's lastname
    string name;        // IN - student's full name
    int id;             // IN - student's student id
    string phoneNum;    // IN - student's phone #
    int age;            // IN - student's age
    char gender;        // IN - student's gender
    string classStanding;// IN - student's class standing
    double GPA;         // IN - student's gpa
    
    ifstream inStream;   // IN - input stream
    int size(0);         // IN - size of the array

    inStream.open("students.txt");
    if(!inStream)
    {
        cout << "Error! Unable to read the file\n";
        exit(0);
    }
    
    while(!inStream.eof())
    {
        inStream>>firstName>> lastName;
        inStream >> id;
        inStream >> phoneNum;
        inStream >> age;
        inStream >> gender;
        inStream >> classStanding;
        inStream >> GPA;
        name = firstName + " " + lastName;
        array[size] = new Student(name,id,
        phoneNum,age,gender,classStanding,GPA);
        size++;
    }
    
    inStream.close();
    return size;

}

/*******************************************************************************
 * void printAny(Student * student)
 *_________________________________________________________________
 * This function prints any student class object(Student/CS003AStudent)
 *  - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Student student: student obejct to outptut
 *
 * POSTCONDITIONS:
 *  N/A
 * 
*******************************************************************************/
void printAny(Student * student)    // OUT - student objedt to output
{
    student->print();
}