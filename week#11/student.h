/******************************************************************************
 * AUTHOR       : Jessica Hahm
 * ASSIGNMENT#8 : Inheritance
 * CLASS        : 32276 CS3A
 * SECTION      : 11
 * DUE DATE     : 04/6/2022
 ******************************************************************************/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

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

class Student
{
private:
    string  name;   // IN - student's name
    unsigned studentId; // IN - student's student ID
    string phoneNumber; // IN - student's phone number
    unsigned age;   // IN - student's age
    char gender;    // IN - student's gender
    string classStanding;   // IN - student's class standing
    double GPA; // IN - student's GPA

public:
    /****************
     ** CONSTRUCTOR **
    ****************/
    Student();
    Student(const string name,  // IN - student's name
            const unsigned studentId,   // IN - student's student ID
            const string phone, // IN - student's phone number
            const unsigned age, // IN - student's age
            const char gender,  // IN - student's gender
            const string class_Standing,    // IN - student's class standing
            const double gpa);  // IN - student's gpa
    /**************
    **  MUTATOR  **
    ***************/
    void setName(const string name);    // IN - student's name
    void setId(const unsigned studentId);   // IN - student's student ID
    void setPhone(const string phone);  // IN - student's phone #
    void setAge(const unsigned age);    // IN - student's age
    void setGender(const char gender);  // IN - student's gender
    void setClass_Standing(
            const string classStanding);// IN - student's class standing   
    void setGPA(const double gpa);  // IN - student's gpa

    /***************
    *** ACCESSOR ***
    ****************/
    virtual void print() const;

};
#endif

/******************************************************************************
 * Student Class
 *  <description>: performs computes basic function for Student obejct
 *
 *****************************************************************************/

/****************
** CONSTRUCTOR **
****************/

/******************************************************************************
 * Student()
 *  Constructor: Initialize class attributes
 *-----------------------------------------------------------------------------
 *  Parameters: none
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/******************************************************************************
 * Student(const string name,
            const unsigned studentId,
            const string phone,
            const unsigned age,
            const char gender,
            const string class_Standing,
            const double gpa)
 *  Constructor: Initialize class attributes
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      const string name: name of the sudent
        const string phone: phone number of the student
        const unsigned age: age of the student
        const char gender: gender of the student
        const string class_Standing: class stadning of the student
        const double gpa: gpa of the student
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/****************
 *** MUTATORS ***
 ****************/

/******************************************************************************
 * void setName(const string name)
 *  Mutator: This method sets the name of the student
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      string name: name of the student
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void setAge(const unsigned age)
 *  Mutator: This method sets the age of the student
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      unsigned age: age of the student 
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void setPhone(const string phone)
 *  Mutator: This method sets the phone number of the student
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      string phone: phone number of the student
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void setId(const unsigned studentId)
 *  Mutator: This method sets the student ID of the student
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      unsinged studentID: student ID of the student
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 *  void setClass_Standing(const string classStanding)
 *  Mutator: This method sets the class_standing of the student
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      string classStanding: class standing of the student
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/****************
 *** ACCESSORS ***
 ****************/

/******************************************************************************
 * void print()const
 *  Accessor:  This method prints the student's data
 *-----------------------------------------------------------------------------
 *  Parameter: none
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

