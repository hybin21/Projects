/*******************************************************************************
 * AUTHOR    : <name(s)>
 * LAB #00   : <lab_name>
 * CLASS     : CS3A
 * SECTION   : 32276
 * DUE DATE  : 00/00/00
*******************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
 

using namespace std;

const string COURSE_ONE = "ENGLISH";
const string COURSE_TWO = "HISTORY";
const string COURSE_THREE = "MATH";


/*******************************************************************************
 *
 * <lab_title>
 *_________________________________________________________________
 * <description>
 * 
 *_________________________________________________________________
 * INPUTS:
 *  int <variable_name>:
 *  string <variable_name>:
 *
 * OUTPUTS:
 *  int <variable_name>:
 *  string <variable_name>: 
 *
*******************************************************************************/

//FUNCTION PROTOTYPES

/*******************************************************************************
 * <function_name>
 *  <description>
 *  - returns ...
 *      
*******************************************************************************/

/*****************************************************************************
 * openInputFile
 * This function is just used to open a provided text file and 
 * check for invalid input.
 * - returns none
*****************************************************************************/

void openInputFile(ifstream& inStream, string inputFileName,bool &valid);  


void openOutputFile(ofstream& outStream, string outputFileName,bool &valid);


void receiveFileNames(string &inFile,string &outFile);

void readFile(struct Student *&list,string inFile);

void writeFile(const struct Student *list,char course,string courseName);

double computeAverage(const struct Student *list);

struct Student
{
    char lastName [20];
    char firstName [20];
    char course;
    int testOne;
    int testTwo;
    int finalExam;
    double testAverage;
    char grade;
};

int main()
{
    Student *list;
    
    readFile(list,"test1.txt");

    cout << "\nStudent Grade Summary" << endl
         << "---------------------" << endl << endl;

    writeFile(list,COURSE_ONE[0],COURSE_ONE + " CLASS");
    writeFile(list,COURSE_TWO[0],COURSE_TWO + " CLASS");
    writeFile(list,COURSE_THREE[0],COURSE_THREE + " CLASS");
    

    // for(int i = 0; i < 8; i++)
    // {
    //     cout << list[i].lastName << endl;
    //     cout << list[i].firstName << endl;
    //     cout << list[i].course << endl;
    //     cout << list[i].testOne << endl;
    //     cout << list[i].testTwo << endl;
    //     cout << list[i].finalExam << endl;
    //     cout << list[i].testAverage << endl << endl;
    // }



}

//FUNCTION DEFINITIONS

/*****************************************************************************
 * FUNCTION  openInputFile
 *________________________________________________
 * Opens a given file and displays an error message for invalid input
 *________________________________________________
 * PRE-CONDITIONS
 * inputFileName must be defined by the user
 *
 * POST-CONDITIONS
 * none
****************************************************************************/

void openInputFile(ifstream& inStream, string inputFileName,bool &valid)  
{
    //processing
    inStream.open(inputFileName);
    if(inStream.fail())
    {
        valid = false;
    }
   
}

void openOutputFile(ofstream& outStream, string outputFileName,bool &valid)
{
    outStream.open(outputFileName);
    if(outStream.fail())
    {
        valid = false;
    }
}

void receiveFileNames(string &inFile,string &outFile)
{
    ifstream inStream;
    ofstream outStream;
    bool inValid;
    bool outValid;

    inValid = false;
    outValid = false;

    while (!inValid)
    {
        cout << "Please enter the name of the input file." << endl
            << "Filename:";
        cin >> inFile; 

        openInputFile(inStream,inFile,inValid);
    }

    while (!outValid)
    {
        cout << "Please enter the name of the input file." << endl
            << "Filename:";
        cin >> inFile; 

        openOutputFile(outStream,outFile,outValid);
    }

    inStream.close();
    outStream.close();
    

}

void readFile(Student *&list,string inFile)
{
    ifstream inStream;
    int size;
    double avg;
    inStream.open(inFile);


    inStream >> size;
    list = new Student[size];


    for(int i = 0; i < size; i++)
    {
        inStream.get(list[i].lastName,20,',');
        inStream.ignore();

        inStream.get(list[i].firstName,20,',');
        inStream.ignore();
        
        inStream >> list[i].course;
        inStream.ignore();

        inStream >> list[i].testOne;
        inStream.ignore();

        inStream >> list[i].testTwo;
        inStream.ignore();

        inStream >> list[i].finalExam;
        inStream.ignore();

        list[i].testAverage = (list[i].testOne*.3) + (list[i].testTwo*.3) + (list[i].finalExam*.4);
        avg = list[i].testAverage;

        if (avg >= 90 && avg <= 100)
        {
            list[i].grade = 'A';
        }
        else if (avg >= 80 && avg <= 89.99)
        {
            list[i].grade = 'B';
        }
        else if (avg >= 70 && avg <= 79.99)
        {
            list[i].grade = 'C';
        }
        else if (avg >= 60 && avg <= 69.99)
        {
            list[i].grade = 'D';
        }
        else if (avg < 60)
        {
            list[i].grade = 'F';
        }
        
    }

    inStream.close();

}

void writeFile(const struct Student *list,char course,string courseName)
{
    
    char temp[40];
    double avg;
    int count;
    char classGrade;
    int width;

    // width = 40;
    avg = 0;
    count = 0;
    
    cout << courseName << endl << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << left << setw(37) << "Student Name"<<left<<setw(13)<<"Test Avg" << "Grade" << endl
         << "----------------------------------------------------------------" << endl;

    for (int i = 0; i < 8; i++)
    {
        if (list[i].course == course)
        {
            strcpy(temp,list[i].lastName);
            strcat(temp,", ");
            strcat(temp,list[i].firstName);

            if (strlen(temp) < 13)
            {
                width = 41;
            }
            else    
            {
                width = 40;
            }
            
            cout << left << setw(width) << temp 
                << left << setw(8) << list[i].testAverage 
                << right << setw(6) << list[i].grade << endl;

            avg+=list[i].testAverage;
            count++;
        }
        
    }
    avg = avg/count;

    if (avg >= 90 && avg <= 100)
    {
        classGrade = 'A';
    }
    else if (avg >= 80 && avg <= 89.99)
    {
        classGrade = 'B';
    }
    else if (avg >= 70 && avg <= 79.99)
    {
        classGrade = 'C';
    }
    else if (avg >= 60 && avg <= 69.99)
    {
        classGrade = 'D';
    }
    else if (avg < 60)
    {
        classGrade = 'F';
    }

    cout << endl    
         <<  left << setw(40) << "Class Average" << left << setw(8) << avg << right 
         <<  setw(6) << classGrade << endl
         << "----------------------------------------------------------------" << endl << endl;

}


/*******************************************************************************
 * <function_name>
 *_________________________________________________________________
 * <description>
 * - returns ...
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   <variable_name>:
 *   <variable_name>:
 *
 * POSTCONDITIONS:
 *  <return description>
 *
*******************************************************************************/