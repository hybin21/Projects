/*******************************************************************************
 * AUTHOR         : Jessica Hahm
 * ASSIGNMENT 08  : Inheritance
 * CLASS          : CS3A
 * SECTION        : 32276
 * DUE DATE       : 04/06/22
*******************************************************************************/
#include "cs003AStudent.h"
#include "student.h"

/*******************************************************************************
 *
 * CS003AStudent class
 *_________________________________________________________________
 * <description>
 * This class performs computes basic function for cs003A students
 *_________________________________________________________________
 * INPUTS:
 *  N/A
 *
 * OUTPUTS:
 *  displays cs003a studets' data
 *
*******************************************************************************/

/****************
** CONSTRUCTOR **
*****************/

/*****************************************************************************
* CS003AStudent()
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
CS003AStudent::CS003AStudent(): Student(),totalScore(),java(false),gradDate(){}

/*****************************************************************************
* CS003AStudent(const string name,
                             const unsigned studentId,
                             const string phone,
                             const unsigned age,
                             const char gender,
                             const string class_Standing,
                             const double gpa,
                             const double score,
                             const bool know_java,
                             const Date &grad)
*   Constructor; Initialize class attributes
*   Parameters: 
        const string name: name of the sudent
        const string phone: phone number of the student
        const unsigned age: age of the student
        const char gender: gender of the student
        const string class_Standing: class stadning of the student
        const double gpa: gpa of the student
        const double score: score of the student
        const bool know_java: knowledge of JAVA of the student
        const Date &grad: expecting grad date of the student
*   Return: none
*****************************************************************************/
CS003AStudent::CS003AStudent(const string name, // IN - name of the student
        const unsigned studentId,  // IN - studetn id of the student
        const string phone, // IN - phone number of the student
        const unsigned age, // IN - age of the student
        const char gender,  // IN - gender of the student
        const string class_Standing,    // IN - class standing of the student
        const double gpa,   // IN - gpa of the student
        const double score, // IN - total score of the student
        const bool know_java,   // IN - knowledge of JAVA of the student
        const Date &grad) // IN - expected grad date of the student
        :Student(name,studentId,phone,age,gender,class_Standing,gpa),
        totalScore(score),java(know_java),gradDate(grad){}

/****************
**   MUTATOR   **
*****************/


/*****************************************************************************
 * setName(const string name):  Class CS003AStudent
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
 *      CS003AStudent object has a new name
 *
 *****************************************************************************/                      
void CS003AStudent::setName(const string name)  // IN - name of the student
{
    Student::setName(name);
}

/*****************************************************************************
 * setAge(const unsigned age):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the age of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsigned age: age of the student 
 * POST-CONDITION
 *      CS003AStudent object has a new age
 *****************************************************************************/   
void CS003AStudent::setAge(const unsigned age)  // IN - age of the student
{
    Student::setAge(age);
}

/*****************************************************************************
 * setPhone(const string phone):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the phone number of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      string phone: phone number of the student
 * POST-CONDITION
 *      CS003AStudent object has a new phone number
 *
 *****************************************************************************/   
void CS003AStudent::setPhone(
            const string phone)    // IN - phone numebr of the student
{
    Student::setPhone(phone);
}

/*****************************************************************************
 * setId(const unsigned studentId):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the student ID of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      unsinged studentID: student ID of the student
 * POST-CONDITION
 *      CS003AStudent object has a new student ID
 *
 *****************************************************************************/   
void CS003AStudent::setId(
        const unsigned studentId) // IN - student id of the student
{
    Student::setId(studentId);
}

/*****************************************************************************
 * setClass_Standing(const string classStanding):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the class_standing of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      string classStanding: class standing of the student
 * POST-CONDITION
 *      CS003AStudent object has a new class standing
 *
 *****************************************************************************/   
void CS003AStudent::setClass_Standing(
            const string classStanding) // IN - class satnding of the student
{
    Student::setClass_Standing(classStanding);
}

/*****************************************************************************
 * setTotalScore(const double score):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the total score that student has earned 
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      double score: total score of the student
 * POST-CONDITION
 *      CS003AStudent object has a new total scores
 *****************************************************************************/   
void CS003AStudent::setTotalScore(
                const double score) // IN - new total score of the student
{
    this->totalScore = score;
}

/*****************************************************************************
 * setKnowledgeOfJava(const bool know)):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the student's knowledge of JAVA
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      bool know: knowledge of JAVA
 * POST-CONDITION
 *      CS003AStudent object has a new boolean variable of knowledge of JAVA
 *****************************************************************************/   
void CS003AStudent::setKnowledgeOfJava(
                        const bool know) // IN - knowledge of JAVA
{
    this->java = know;
}

/*****************************************************************************
 * setGradDate(const Date &newDate):  Class CS003AStudent
 *
 * ---------------------------------------------------------------------------
 * This method sets the expected graduation date of the student
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      Date newDate: expected grad date of the student
 * POST-CONDITION
 *      CS003AStudent object has a new grad date
 *****************************************************************************/   
void CS003AStudent::setGradDate(
            const Date &newDate)    // IN - expected graduation date
{
    this->gradDate = newDate;
}

/****************
 *** ACCESSORS ***
 ****************/

/*****************************************************************************
 * print()const:  Class CS003AStudent
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
void CS003AStudent::print()const
{
    Student::print();
    cout << "Total Score: " << totalScore<< endl;
    cout << "Knowledge of JAVA: "<< java<< endl;
    cout << "Graduation Date: ";
    gradDate.printNumeric();
    cout << endl;
}