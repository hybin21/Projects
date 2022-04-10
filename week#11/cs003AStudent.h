/******************************************************************************
 * AUTHOR       : Jessica Hahm
 * ASSIGNMENT#8 : Inheritance
 * CLASS        : 32276 CS3A
 * SECTION      : 11
 * DUE DATE     : 04/6/2022
 ******************************************************************************/
#ifndef CS003ASTUDENT_H
#define CS003ASTUDENT_H

#include "student.h"
#include "date.h"
#include <iostream>
using namespace std;

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
class CS003AStudent: public Student
{
    private:
        double totalScore;  // IN - total score that student has earned
        bool java;  // IN -student's knowledge of JAVA
        Date gradDate; // IN - student's expected grad date
    public:

        /****************
        ** CONSTRUCTOR **
        ****************/
        CS003AStudent();
        CS003AStudent(const string name, // IN - name of the student
        const unsigned studentId,  // IN - studetn id of the student
        const string phone, // IN - phone number of the student
        const unsigned age, // IN - age of the student
        const char gender,  // IN - gender of the student
        const string class_Standing,    // IN - class standing of the student
        const double gpa,   // IN - gpa of the student
        const double score, // IN - total score of the student
        const bool know_java,   // IN - knowledge of JAVA of the student
        const Date &grad); // IN - expected grad date of the student
        /**************
        **  MUTATOR  **
        ***************/
        void setName(const string name); // IN - name of the student
        void setAge(const unsigned age); // IN - age of the student
        void setPhone(const string phone); // IN - phone # of the student
        void setId(const unsigned studentId);// IN - student ID of the student
        void setClass_Standing(
            const string classStanding);// IN - class standing of the student 
        void setTotalScore(
            const double score); // IN - total score of the student
        void setKnowledgeOfJava(
            const bool know);   // IN - student's knowledge of JAVA
        void setGradDate(
            const Date & newDate);  // IN - expected grad date 

        /***************
        *** ACCESSOR ***
        ****************/
        virtual void print()const;
};
#endif

/******************************************************************************
 * CS003AStudent Class
 *  <description>: performs computes basic function for cs003A students
 *
 *****************************************************************************/

/****************
** CONSTRUCTOR **
****************/

/******************************************************************************
 * CS003AStudent()
 *  Constructor: Initialize class attributes
 *-----------------------------------------------------------------------------
 *  Parameters: none
 *-----------------------------------------------------------------------------
 *  Return: nothing
 *****************************************************************************/

/******************************************************************************
 * CS003AStudent(const string name,
            const unsigned studentId,
            const string phone,
            const unsigned age,
            const char gender,
            const string class_Standing,
            const double gpa,
            const double score,
            const bool know_java,
            const Date & grad)
 *  Constructor: Initialize class attributes
 *-----------------------------------------------------------------------------
 *  Parameters: 
 *      const string name: name of the sudent
        const string phone: phone number of the student
        const unsigned age: age of the student
        const char gender: gender of the student
        const string class_Standing: class stadning of the student
        const double gpa: gpa of the student
        const double score: score of the student
        const bool know_java: knowledge of JAVA of the student
        const Date &grad: expecting grad date of the student
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

/******************************************************************************
 * void setTotalScore(const double score)
 *  Mutator: This method sets the total score that student has earned 
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *    double score: total score of the student  
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void setKnowledgeOfJava(const bool know)
 *  Mutator: This method sets the student's knowledge of JAVA
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      bool know: knowledge of JAVA
 *-----------------------------------------------------------------------------
 *  Return: none
 *****************************************************************************/

/******************************************************************************
 * void setGradDate(const Date & newDate)
 *  Mutator: This method sets the expected graduation date of the student
 *-----------------------------------------------------------------------------
 *  Parameter: 
 *      Date newDate: expected grad date of the student
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

