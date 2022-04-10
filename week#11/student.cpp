/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT 08  : Inheritance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 04/06/22
*******************************************************************************/
#include "student.h"

/*******************************************************************************
 *
 * Student class
 *_________________________________________________________________
 * <description>
 * This class performs computes basic function for Student objects
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays Student object's data
 *
*******************************************************************************/

/*****************************************************************************
* Student()
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
Student::Student()
{
    name = "";
    studentId = 0;
    phoneNumber = "";
    age = 0;
    gender = 'a';
    classStanding = "";
    GPA = 0;

}

/*****************************************************************************
* CS003AStudent(const string name,
                             const unsigned studentId,
                             const string phone,
                             const unsigned age,
                             const char gender,
                             const string class_Standing,
                             const double gpa)
*   Constructor; Initialize class attributes
*   Parameters: 
        const string name: name of the sudent
        const string phone: phone number of the student
        const unsigned age: age of the student
        const char gender: gender of the student
        const string class_Standing: class stadning of the student
        const double gpa: gpa of the student
*   Return: none
*****************************************************************************/
Student::Student(const string name, // IN - name of the student
        const unsigned studentId,  // IN - studetn id of the student
        const string phone, // IN - phone number of the student
        const unsigned age, // IN - age of the student
        const char gender,  // IN - gender of the student
        const string class_Standing,    // IN - class standing of the student
        const double gpa)   // IN - gpa of the student
{
    this->name = name;
    this->studentId = studentId;
    this->phoneNumber = phone;
    this->age = age;
    this->gender = gender;
    this->classStanding = class_Standing;
    this->GPA = gpa;
}

/****************
**   MUTATOR   **
*****************/


/*****************************************************************************
 * setName(const string name):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets the name of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      string name: name of the student
 * 
 * POST-CONDITION:
 *      Student object has a new name
 *
 *****************************************************************************/ 
void Student::setName(const string name)    // IN - name of the student  
{
    this->name = name;
}  

/*****************************************************************************
 * setId(const unsigned studentId):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets the student ID of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsinged studentID: student ID of the student
 * POST-CONDITION
 *     Student object has a new student ID
 *
 *****************************************************************************/  
void Student::setId(const unsigned studentId)   // IN - student's student ID
{
    this->studentId = studentId;
}

/*****************************************************************************
 * setPhone(const string phone):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets the phone number of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      string phone: phone number of the student
 * POST-CONDITION
 *      Student object has a new phone number
 *
 *****************************************************************************/   
void Student::setPhone(const string phone)  // IN - student's phone #
{
    this->phoneNumber = phone;
}

/*****************************************************************************
 * setAge(const unsigned age):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets the age of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned age: age of the student 
 * POST-CONDITION
 *      Student object has a new age
 *****************************************************************************/  
void Student::setAge(const unsigned age)    // IN - age of the student
{
    this->age = age;
}

/*****************************************************************************
 * setGender(const char gender):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets the gender of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      char gender: gender of the student 
 * POST-CONDITION
 *      Student object has a new gender
 *****************************************************************************/
void Student::setGender(const char gender)  // IN - gender of the student
{
    this->gender = gender;
}

/*****************************************************************************
 * setClass_Standing(const string classStanding):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets the class_standing of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      string classStanding: class standing of the student
 * POST-CONDITION
 *      Student object has a new class standing
 *
 *****************************************************************************/  
void Student::setClass_Standing(
            const string classStanding) // IN - student's class standing
{
    this->classStanding = classStanding;
}

/*****************************************************************************
 * setGPA(const double gpa):  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method sets GPA of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      double gpa: GPA of the student
 * POST-CONDITION
 *      Student object has a new gpa
 *
 *****************************************************************************/ 
void Student::setGPA(const double gpa)  // IN - gpa of the student
{
    this->GPA = gpa;
}

/****************
 *** ACCESSORS ***
 ****************/

/*****************************************************************************
 * print()const:  Class Student
 *
 * ---------------------------------------------------------------------------
 * This method prints the student's data
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values: none
 * POST-CONDITION
 *      Student's data should be output
 *****************************************************************************/ 
void Student::print() const
{
    cout << "Name: "<< name << endl;
    cout << "ID: "<< studentId<< endl;
    cout << "Phone Number: "<< phoneNumber<< endl;
    cout << "Age: "<< age << endl;
    cout << "Gender: " << gender<< endl;
    cout << "Class Standing: "<< classStanding << endl;
    cout << "GPA: "<< GPA<< endl;
}

