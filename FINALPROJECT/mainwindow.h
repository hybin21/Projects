/*******************************************************************************
 * AUTHOR            : Jessica Hahm
 * ASSIGNMENT #10    : FINAL ASSIGNMENT
 * CLASS             : CS3A
 * SECTION           : 32276
 * DUE DATE          : 04/28/22
*******************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QInputDialog>
#include <iostream>
#include <QGraphicsTextItem>


#include "vector.h"
#include "linkedlist.h"
#include "complex.h"
#include "rational.h"
#include "date.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  // IN - parent function

    void runIntList(
            LinkedList<int> & inputIntList);    // IN - input list
    void runDoubleList(
            LinkedList<double> & inputDoubleList); // IN - input list
    void runStringList(
            LinkedList<string> & inputStringList); // IN - input list
    void runRationalList(
            LinkedList<Rational> & inputRationalList); // IN - input list
    void runDateList(
            LinkedList<Date> & inpuDatetList);  // IN - input list
    void runComplexList(
            LinkedList<Complex> & inputComplexList);    // IN - input list
    void findFunction(int type);    // IN - function type
    QString returnRational(
            const Rational & inputRational);    // IN - input list
    QString returnDate(
            const Date & inputDate);    // IN - input list
    QString returnComplex(
            const Complex & inputComplex);  // IN - input list
    Complex   readComplex(
            const string string_input); // IN - input list
    void drawIntList(
            LinkedList<int> & inputIntList);    // IN - input list
    void drawDoubleList(
            LinkedList<double> & inputDoubleList);  // IN - input list
    void drawStringList(
            LinkedList<string> & inputStringList);  // IN - input list
    void drawRationalList(
            LinkedList<Rational> & inputRationalList);  // IN - input list
    void drawDateList(
            LinkedList<Date> & inputDateList);  // IN - input list
    void drawComplexList(
            LinkedList<Complex> & inputComplexList);    // IN - input list


    ~MainWindow();


private slots:

    void on_ENTER_2_clicked();

    int on_TYPE_currentIndexChanged(int index); // IN - index

    int on_FUNCTION_currentIndexChanged(int index); // IN -  index

    void on_COPY_currentIndexChanged(int index);    // IN - index

private:
    Ui::MainWindow *ui; //CALC/OUT -
    QGraphicsScene * scene; // CLAC/OUT - scene for the graphics
    QGraphicsTextItem * text;   // CALC/OUT - text object for the grahics

    QStringListModel * intModel;    // CALC/OUT - model for type int
    QStringListModel * doubleModel; // CALC/OUT - model for type double
    QStringListModel * stringModel; // CALC/OUT - model for type string
    QStringListModel * complexModel;    // CALC/OUT - model for type complex
    QStringListModel * rationalModel;   // CALC/OUT - model for type rational
    QStringListModel * dateModel;   // CALC/OUT - model for type date

    Vector<LinkedList<int>> intVector;  // CALC/OUT - intLinkedList vector
    Vector<LinkedList<double>> doubleVector;    // CALC/OUT - doubleLinkedList vector
    Vector<LinkedList<string>> stringVector;    // CALC/OUT -  doubleLinkedList vector
    Vector<LinkedList<Rational>> rationalVector;    // CALC/OUT - doubleLinkedList vector
    Vector<LinkedList<Date>> dateVector;    // CALC/OUT - doubleLinkedList vector
    Vector<LinkedList<Complex>> complexVector;  // CALC/OUT - doubleLinkedList vector


};
#endif // MAINWINDOW_H

/****************************************************************
* MainWindow Class
*   This class runs a linkedlist program
***************************************************************/

/*****************
** CONSTRUCTORS **
*****************/

/****************************************************************
* void runIntList(LinkedList<int> & inputIntList);
*   - run int list
*   Parameters:
*       LinkedList<int> & inputIntList: input list
*   Return: none
***************************************************************/

/****************************************************************
* void runDoubleList(LinkedList<double> & inputDoubleList);
*   - run double list
*   Parameters:
*       LinkedList<double> & inputDoubleList: input list
*   Return: none
***************************************************************/

/****************************************************************
* void runStringList(LinkedList<string> & inputStringList);
*   - run string list
*   Parameters:
*       LinkedList<string> & inputStringList: input list
*   Return: none
***************************************************************/

/****************************************************************
* vvoid runRationalList(LinkedList<Rational> &
*                   inputRationalList);
*   - run rationla list
*   Parameters:
*       LinkedList<rationla> & inputRationalList: input list
*   Return: none
***************************************************************/

/****************************************************************
* void runDateList(LinkedList<Date> & inpuDatetList);
*   - run Date list
*   Parameters:
*       LinkedList<Date> & inpuDatetList: input list
*   Return: none
***************************************************************/

/****************************************************************
* void runComplexList(LinkedList<Complex> & inputComplexList);
*   - run Complex list
*   Parameters:
*       LinkedList<Complex> & inputComplexList: input list
*   Return: none
***************************************************************/

/****************************************************************
* void findFunction(int type);
*   - find function
*   Parameters:
*      int type: type of the function
*   Return: none
***************************************************************/

/****************************************************************
* QString returnRational(const Rational & inputRational);
*   - returns rational into QString
*   Parameters:
*      const Rational & inputRational: input list
*   Return: QString of the rational
***************************************************************/

/****************************************************************
* QString returnDate(const Date & inputDate);
*   - returns date into QString
*   Parameters:
*      const Date & inputDate: input list
*   Return: QString of the Date
***************************************************************/

/****************************************************************
* QString returnComplex(const Complex & inputComplex);
*   - returns Complex into QString
*   Parameters:
*      const Complex & inputComplex: input list
*   Return: QString of the Complex
***************************************************************/

/****************************************************************
* Complex  readComplex(const string string_input);
*   - reads Complex object
*   Parameters:
*      const string string_input: input string to be converted
*           to Complex
*   Return: Complex object
***************************************************************/

/****************************************************************
* void drawIntList(LinkedList<int> & inputIntList);
*   - draw intlist
*   Parameters:
*      LinkedList<int> & inputIntList: input list
*   Return: N/A
***************************************************************/

/****************************************************************
* void drawDoubleList(LinkedList<double> & inputDoubleList);
*   - draw Doublelist
*   Parameters:
*      LinkedList<double> & inputDoubleList: input list
*   Return: N/A
***************************************************************/

/****************************************************************
* void drawStringList(LinkedList<string> & inputStringList);
*   - draw Stringlist
*   Parameters:
*      LinkedList<string> & inputStringList: input list
*   Return: N/A
***************************************************************/

/****************************************************************
* void drawRationalList(LinkedList<Rational> &
*               inputRationalList);
*   - draw Rationallist
*   Parameters:
*      LinkedList<Rational> & inputRationalList: input list
*   Return: N/A
***************************************************************/

/****************************************************************
* void drawDateList(LinkedList<Date> & inputDateList);
*   - draw Datelist
*   Parameters:
*      LinkedList<Date> & inputDateList: input list
*   Return: N/A
***************************************************************/

/****************************************************************
* void drawComplexList(LinkedList<Complex> & inputComplexList);
*   - draw Complexlist
*   Parameters:
*      LinkedList<Complex> & inputComplexList: input list
*   Return: N/A
***************************************************************/

