/*******************************************************************************
 * AUTHOR            : Jessica Hahm
 * ASSIGNMENT #02    : Student Record
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 01/24/22
*******************************************************************************/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<cmath>

/*******************************************************************************
 *
 * Assignment 2- Student Record
 *_________________________________________________________________
 * <description>
 * This program computes and stores each student's test average
 *_________________________________________________________________
 * INPUTS:
 *  string inputFileName: input file name from the user
 *  string outputFileName: output file name fro the user
 *
 * OUTPUTS:
 *  each subject's grade report based on student's info
 *
*******************************************************************************/

using namespace std;

const int MAX_SIZE = 20;    // Max. num that Student array can store

struct Student     // structure type variable named Student
{
    char lastName[MAX_SIZE];    // IN - student's last name
    char firstName[MAX_SIZE];   // IN - students' first name
    char course;                // IN - course name
    int testOne;                // IN - score of test1
    int testTwo;                // IN - score of test2
    int finalExam;              // IN - score of final exam
    double testAvg;             // CALC&OUT - average score of three tests
};

//FUNCTION PROTOTYPES

/*******************************************************************************
 * openFile(ifstream& inStream, ofstream& outStream)
 *  <description>
 *  open input file with user's input file name and check if it's valid 
 *  - returns nothing
 *      
*******************************************************************************/

void openFile(ifstream& inStream,   // IN - input file stream
            ofstream& outStream);   // IN - output file stream

/*******************************************************************************
 * readFile(ifstream& inStream, Student *&list)
 *  <description>
 *  read input file and store the data into the program
 *  - returns nothing
 *      
*******************************************************************************/

int readFile(ifstream& inStream,    // IN - input file stream
            Student *&list);        // CALC&OUT - student's list with data

/*******************************************************************************
 * findAvg(Student *&list, const int size)
 *  <description>
 *  find the average based on test scores
 *  - returns nothing
 *      
*******************************************************************************/

void findAvg(Student *&list,    // CALC&OUT - student's list with data
            const int size);    // IN - size of the list

/*******************************************************************************
 * findGrade(Student *&list, const int avg)
 *  <description>
 *  find the grade based on test scores
 *  - returns the grade
 *      
*******************************************************************************/

char findGrade(Student *&list,  // CALC&OUT - student's list with data
                const int avg); // IN - student's average score

/*******************************************************************************
 * sortName(Student *& list, const int size)
 *  <description>
 *  sort student's name in alphabetical order
 *  - returns list with sorted student's name
 *      
*******************************************************************************/

void sortName(Student *& list,  // CALC&OUT - student's list with data
             const int size);   // IN - size of the list

/*******************************************************************************
 * displayGrade(ostream & outStream,Student *&list, const int size, char subject)
 *  <description>
 *  display the grade chart
 *  - returns notghing
 *      
*******************************************************************************/

void displayGrade(ostream & outStream,  // IN - output stream
                    Student *&list,     // IN - studetn's data list
                    const int size,     // IN - list's size
                    char subject);      // IN - subject initial



int main(void)
{
    ifstream inStream;                  // IN - input file stream
    ofstream outStream;                 // CALC&OUT - output file stream
    int size;                           // CALC&OUT - size of the list

    // PROCESSING: open input and output file and check if it's valid
    openFile(inStream,outStream);

    Student *list;

    size = readFile(inStream,list);

    findAvg(list,size);

    cout << "Student Grade Summary\n";
    cout << "---------------------\n\n\n";
    
    // PROCESSING: sort student's name
    sortName(list,size);

    // OUT: display each subject grade table
    displayGrade(cout, list, size, 'E');
    displayGrade(cout, list, size, 'H');
    displayGrade(cout, list, size, 'M');

    // PROCESSING: close file stream  
    inStream.close();
    outStream.close();

    // PROCESSING: dealloate the memory
    delete[] list;

    return 0;
}

//FUNCTION DEFINITIONS

/*******************************************************************************
 * openFile(ifstream& inStream, ofstream& outStream)
 *_________________________________________________________________
 * open input and output files and check if it's valid
 * - returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   ifstream& inStream: input file stream
 *   ofstream& outStream: output file stream
 *
 * POSTCONDITIONS:
 *  returns nothing
 *
*******************************************************************************/

void openFile(ifstream& inStream,   // IN - input file stream
             ofstream& outStream)   // IN - output file stream
{
    string fileName;    // IN - user inputs the file name
    bool check;         // CALC&OUT - decide to ask user for the file name again

    check = true;

    while(check)
    {
        cout << "Please enter the name of the input file.\n";
        cout << "Filename: ";
        cin >> fileName;

        inStream.open(fileName);

        if(inStream.fail())
            inStream.close();
        else
        {
            cout << endl;
            check = false;
        }
    }

    while(!check)
    {
        cout << "Please enter the name of the output file.\n";
        cout << "Filename: ";
        cin >> fileName;
        outStream.open(fileName);
        if(outStream.fail())
            outStream.close();
        else
        {
            cout << "Processing Complete\n\n";
            check = true;
        }
    }
}

/*******************************************************************************
 * readFile(ifstream& inStream, Student *&list)
 *_________________________________________________________________
 * read input file and store the data into lsit structure
 *  returns size of the list(structure) array
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   ifstream& inStream: input file stream
 *   Student *&list: Student type array using dynamic memory allocation
 *
 * POSTCONDITIONS:
 *  returns size of the lsit
 *
*******************************************************************************/

int readFile(ifstream& inStream,    // IN - input file stream
             Student *&list)        // CALC&OUT - student's list with data
{
    int size;           // CLAC&OUT - size of the array of student
    char course;        // CALC&OUT - course initial
    int score;          // CALC&OUT - student's test score
    string tempName;    // CALC&OUT - temporary name of student

    // PROCESSING: read the size of the list
    inStream >> size;
    inStream.ignore();

    // PROCESSING: allocate the memory
    list = new Student[size];

    for(int i = 0; i < size; i++)
    {
        inStream.get(list[i].lastName,20,',');
        inStream.ignore();

        inStream.get(list[i].firstName,20,',');
        inStream.ignore();
        
        inStream >> course;
        list[i].course = course;
        inStream.ignore();

        inStream >> score;
        list[i].testOne = score;
        inStream.ignore();

        inStream >> score;
        list[i].testTwo = score;
        inStream.ignore();

        inStream >> score;
        list[i].finalExam = score;
        inStream.ignore();
    }
    return size;
}

/*******************************************************************************
 * findAvg(Student *&list, const int size)
 *_________________________________________________________________
 * find the average based on grades
 *  returns nothing
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Student *&list: Student type array using dynamic memory allocation
 *   const int size: size of the list
 *
 * POSTCONDITIONS:
 *  returns nothing
 *
*******************************************************************************/

void findAvg(Student *&list,    // CALC&OUT - student's list with data
            const int size)     // IN - size of the list
{
    double avg;         // CALC&OUT - average of student's or class' score

    for(int i = 0; i < size; i++)
    {
        avg = (list[i].testOne + list[i].testTwo) * 0.3 
             + list[i].finalExam * 0.4;
        list[i].testAvg = avg;
    }
}

/*******************************************************************************
 * findGrade(Student *&list, const int avg)
 *_________________________________________________________________
 * find the grade based on average
 *  returns grade
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Student *&list: Student type array using dynamic memory allocation
 *   const int avg: average score of student or class
 *
 * POSTCONDITIONS:
 *  returns grade
 *
*******************************************************************************/

char findGrade(Student *&list,      // CALC&OUT - student's list with data
            const int avg)          // IN - studen't average score
{
    char grade;     // CALC&OUT - grade based on average

    if(avg >= 90 && avg <= 100)
        return 'A';
    else if(avg >= 80 && avg <= 89.99)
        return 'B';
    else if(avg >= 70 && avg <=79.99)
        return 'C';
    else if(avg >= 60 && avg <= 69.99)
        return 'D';
    else 
        return 'F';

}

/*******************************************************************************
 * sortName(Student *& list, const int size)
 *_________________________________________________________________
 * sort student's name in alphabetical order
 *  returns list with sorted student's name
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   Student *&list: Student type array using dynamic memory allocation
 *   const int size: size of the list
 *
 * POSTCONDITIONS:
 *  returns list with sorted student's name
 *
*******************************************************************************/


void sortName(Student *& list,  // CALC&OUT - student's list with data
             const int size)    // IN - size of the list
{   
    Student temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = 1; j < size; j++)
        {   
            // PROCESSING: sort the name by using function "strcmp()""
            if(strcmp(list[j].lastName, list[j-1].lastName) < 0)
            {
                temp = list[j-1];
                list[j-1] = list[j];
                list[j] = temp;
            }
        }
    }
   
}

/*******************************************************************************
 * displayGrade(ostream & outStream,Student *&list, 
 *                 const int size, char subject)
 *_________________________________________________________________
 * display the grade of students
 *  returns the chart of grade
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   ostream& outStream: output stream
 *   Student *&list: Student type array using dynamic memory allocation
 *   const int size: size of the list
 *   char subject: student's subject
 *
 * POSTCONDITIONS:
 *  display the grade chart
 *
*******************************************************************************/

void displayGrade(ostream & outStream,      // IN - output stream
                 Student *&list,            // IN - student's data list
                 const int size,            // IN - list's size
                 char subject)              // IN - subject initial
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    char name[40];          // CALC&OUT - student's name
    char grade;             // CALC&OUT - student's or class' grade
    double classSum;        // CALC&OUT - class summary
    int count;              // CALC&OUT - the number of students
    double classAvg;        // CALC&OUT - calculated class average
    int index;              // CALC&OUT - index number of list

    classSum = 0; 
    count = 0; 
    
    if(subject == 'E')
        cout << "ENGLISH CLASS\n\n";
    else if(subject == 'H')
        cout << "HISTORY CLASS\n\n";
    else if(subject == 'M')
        cout << "MATH CLASS\n\n";

    cout << left << setw(37) << "Student Name" <<
         left << setw(13) << "Test Avg" << "Grade\n";

    for(int i = 0; i < 64; i++)
        cout << "-";
    cout << endl;

    for(int i = 0; i < size; i++)
    {

        grade = findGrade(list, list[i].testAvg);

        if(list[i].course == subject)
        {
            // PROCESSING: integrate student's first and last name
            strcpy(name,list[i].lastName);
            strcat(name,", ");
            strcat(name, list[i].firstName);

            cout << left << setw(40) << name 
            << left << setw(8) << list[i].testAvg 
            << right << setw(5) << grade << endl;

            classSum += list[i].testAvg;
            count++;
        }
    }
    
    // PROCESSING: calculate the class average
    classAvg = classSum / count;

    grade = findGrade(list,classAvg);

    cout << endl << left << setw(40) << "Class Average" 
    << left << setw(8) << classAvg 
    << right << setw(5) << grade << endl;

    for(int i = 0; i < 64; i++)
        cout << "-";
    cout << endl;

}