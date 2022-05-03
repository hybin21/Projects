#include "mainwindow.h"
#include "./ui_mainwindow.h"

QString TEMP;
int TYPE;   // IN - type of the value
int FUNCTION;   // IN - function type
int INT_COUNT = 0;  // IN - count for int
int DOUBLE_COUNT = 0;   // IN - count for double
int STRING_COUNT = 0;   // IN - count for string
int RATIONAL_COUNT = 0; // IN - count for rational
int DATE_COUNT = 0; // IN - count for date
int COMPLEX_COUNT = 0;  // IN - count for complex
int version = 0;    // IN - version of the list



QStringList intModelContent(
        "Original (int)");  // CALC - model for int
QStringList doubleModelContent(
        "Original (double)");    // CALC - model for double
QStringList stringModelContent(
        "Original (string)");    // CALC - model for string
QStringList rationalModelContent(
        "Original (rational)");    // CALC - model for rational
QStringList dateModelContent(
        "Original (date)");    // CALC - model for date
QStringList complexModelContent(
        "Original (complex)");  // CALC - model for complex


MainWindow::MainWindow(QWidget *parent) // IN - parent class
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    LinkedList<int> intList;    // CALC/OUT - int linkedList
    LinkedList<double> doubleList;  // CALC/OUT - double linkedList
    LinkedList<string> stringList;  // CALC/OUT - string linkedList
    LinkedList<Rational> rationalList;  // CALC/OUT - rational linkedList
    LinkedList<Date> dateList;  // CALC/OUT - Date linkedList
    LinkedList<Complex> complexList;    // CALC/OUT - Complex linkedList

    intVector.push_back(intList);
    doubleVector.push_back(doubleList);
    stringVector.push_back(stringList);
    rationalVector.push_back(rationalList);
    dateVector.push_back(dateList);
    complexVector.push_back(complexList);

    ui->setupUi(this);

    intModel = new QStringListModel(this);
    doubleModel = new QStringListModel(this);
    stringModel = new QStringListModel(this);
    rationalModel = new QStringListModel(this);
    complexModel = new QStringListModel(this);
    dateModel = new QStringListModel(this);

}

/***************
** DESTRUCTOR **
****************/

/*****************************************************************************
* ~MainWindow()
*   Destructor; destroy class attributes
*   Parameters: none
*   Return: none
*****************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/*****************************************************************************
 * on_ENTER_2_clicked():  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs the functions based on the variable type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONç
 *   program will run the linkedList widget
 *
 *****************************************************************************/
void MainWindow::on_ENTER_2_clicked()
{
    switch(TYPE)
    {
    case 0:
        runIntList(intVector[version]);
        intModel->setStringList(intModelContent);
        ui->COPY->setModel(intModel);
        break;
    case 1:
        runDoubleList(doubleVector[version]);
        doubleModel->setStringList(doubleModelContent);
        ui->COPY->setModel(doubleModel);
        break;
    case 2:
        runStringList(stringVector[version]);
        stringModel->setStringList(stringModelContent);
        ui->COPY->setModel(stringModel);
        break;
    case 3:
        runRationalList(rationalVector[version]);
        rationalModel->setStringList(rationalModelContent);
        ui->COPY->setModel(rationalModel);

        break;
    case 4:
        runDateList(dateVector[version]);
        dateModel->setStringList(dateModelContent);
        ui->COPY->setModel(dateModel);

        break;
    case 5:
        runComplexList(complexVector[version]);
        complexModel->setStringList(complexModelContent);
        ui->COPY->setModel(complexModel);
        break;
    default: ;

    }
}

/*****************************************************************************
 * void drawIntList(LinkedList<int> & inputIntList):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function draws intlist
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *      LinkedList<int> & inputIntList: input list
 *
 * POST-CONDITIONç
 *   program will draw intlist
 *
 *****************************************************************************/
void MainWindow::drawIntList(
        LinkedList<int> & inputIntList)    // IN - input list
{
    scene = new QGraphicsScene();
    QBrush intBrush(QColor(137, 127, 176)); // CALC - brush
    QPen blackPen(Qt::black);   // CALC - pen
    blackPen.setWidth(2);
    LinkedList<int>::Iterator it;   // CALC - iterator
    it = inputIntList.begin();
    text = new QGraphicsTextItem;

    QString output;
    for(int i = 0; i < inputIntList.length(); i++)
    {
        scene->addRect(-80+100*i,-80,70,30,blackPen,intBrush);
        scene->addLine(-20+100*i,-80,-20+100*i,-50,blackPen);
        scene->addLine(-10+100*i,-65,20+100*i,-65,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-61,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-69,blackPen);

        output = QString::number(*it);
        text = scene->addText(output);
        text->setPos(-55+100*i,-77);
        ++it;
    }
    QGraphicsView * graphicsView = // CALC/OUT - graphics view to draw the node
            new QGraphicsView(scene);
    graphicsView->show();
}

/*****************************************************************************
 * void drawDoubleList(LinkedList<double> & inputDoubleList):
 *      Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function draws doubleList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously defined values:
 *     LinkedList<double> & inputDoubleListt: input list
 *
 * POST-CONDITIONç
 *   program will draw doubleList
 *
 *****************************************************************************/
void MainWindow::drawDoubleList(
        LinkedList<double> & inputDoubleList)   // IN - input list
{
    scene = new QGraphicsScene();
    QBrush doubleBrush(QColor(207,161,197));    // CALC - brush
    QPen blackPen(Qt::black);   // CALC - pen
    blackPen.setWidth(2);
    LinkedList<double>::Iterator it;    // CALC - iterator
    it = inputDoubleList.begin();
    text = new QGraphicsTextItem;

    QString output;
    for(int i = 0; i < inputDoubleList.length(); i++)
    {
        scene->addRect(-80+100*i,-80,70,30,blackPen,doubleBrush);
        scene->addLine(-20+100*i,-80,-20+100*i,-50,blackPen);
        scene->addLine(-10+100*i,-65,20+100*i,-65,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-61,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-69,blackPen);

        output = QString::number(*it);
        text = scene->addText(output);
        text->setPos(-60+100*i,-77);
        ++it;
    }
    QGraphicsView * graphicsView =  // CALC/OUT - graphics view to draw the node
            new QGraphicsView(scene);
    graphicsView->show();
    graphicsView->setBackgroundBrush(Qt::white);
}

/*****************************************************************************
 * void drawStringList(LinkedList<string> & inputStringList):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function draws stringList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<string> & inputDoubleListt: input list
 *
 * POST-CONDITIONç
 *   program will draw stringList
 *
 *****************************************************************************/
void MainWindow::drawStringList(
        LinkedList<string> & inputStringList)   // IN - input list
{
    scene = new QGraphicsScene();
    QBrush stringBrush(QColor(161,207,188));    // CALC - brush
    QPen blackPen(Qt::black);   // CALC - pen
    blackPen.setWidth(2);
    LinkedList<string>::Iterator it;    // CALC - iterator
    it = inputStringList.begin();
    text = new QGraphicsTextItem;

    QString output;
    for(int i = 0; i < inputStringList.length(); i++)
    {
        scene->addRect(-80+100*i,-80,70,30,blackPen,stringBrush);
        scene->addLine(-20+100*i,-80,-20+100*i,-50,blackPen);
        scene->addLine(-10+100*i,-65,20+100*i,-65,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-61,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-69,blackPen);

        output = QString::fromStdString(*it);
        text = scene->addText(output);
        text->setPos(-70+100*i,-77);
        ++it;
    }
    QGraphicsView * graphicsView =// CALC/OUT - graphics view to draw the node
            new QGraphicsView(scene);
    graphicsView->show();
    graphicsView->setBackgroundBrush(Qt::white);
}

/*****************************************************************************
 * void drawRationalList(LinkedList<Rational> & inputRationalList):
 *               Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function draws rationalList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<Rational> & inputRationalList: input list
 *
 * POST-CONDITIONç
 *   program will draw rationalList
 *
 *****************************************************************************/
void MainWindow::drawRationalList(
        LinkedList<Rational> & inputRationalList)   // IN - input list
{
    scene = new QGraphicsScene();
    QBrush rationalBrush(QColor(173,221,255));  // CALC - brush
    QPen blackPen(Qt::black);   // CALC - pen
    blackPen.setWidth(2);
    LinkedList<Rational>::Iterator it;  // CALC - iterator
    it = inputRationalList.begin();
    text = new QGraphicsTextItem;

    QString output;
    for(int i = 0; i < inputRationalList.length(); i++)
    {
        scene->addRect(-80+100*i,-80,70,30,blackPen,rationalBrush);
        scene->addLine(-20+100*i,-80,-20+100*i,-50,blackPen);
        scene->addLine(-10+100*i,-65,20+100*i,-65,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-61,blackPen);
        scene->addLine(20+100*i,-65,16+100*i,-69,blackPen);

        output = returnRational(*it);
        text = scene->addText(output);
        text->setPos(-60+100*i,-77);
        ++it;
    }
    QGraphicsView * graphicsView =// CALC/0UT - graphics view to draw the node
            new QGraphicsView(scene);
    graphicsView->show();
    graphicsView->setBackgroundBrush(Qt::white);
}

/*****************************************************************************
 * void drawDateList(LinkedList<Date> & inputDateList):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function draws dateList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<Date> & inputDateList: input list
 *
 * POST-CONDITIONç
 *   program will draw dateList
 *
 *****************************************************************************/
void MainWindow::drawDateList(
        LinkedList<Date> & inputDateList)   // IN - input list
{
    scene = new QGraphicsScene();
    QBrush dateBrush(QColor(163, 106, 126));    // CALC - brush
    QPen blackPen(Qt::black);   // CALC - pen
    blackPen.setWidth(2);
    LinkedList<Date>::Iterator it;  // CALC - iterator
    it = inputDateList.begin();
    text = new QGraphicsTextItem;

    QString output;
    for(int i = 0; i < inputDateList.length(); i++)
    {
        scene->addRect(-80+130*i,-80,100,30,blackPen,dateBrush);
        scene->addLine(10+130*i,-80,10+130*i,-50,blackPen);
        scene->addLine(20+130*i,-65,50+130*i,-65,blackPen);
        scene->addLine(50+130*i,-65,46+130*i,-61,blackPen);
        scene->addLine(50+130*i,-65,46+130*i,-69,blackPen);

        output = returnDate(*it);
        text = scene->addText(output);
        text->setPos(-75+130*i,-77);
        ++it;
    }
    QGraphicsView * graphicsView =  // CALC/OUT - graphics view to draw node
            new QGraphicsView(scene);
    graphicsView->show();
    graphicsView->setBackgroundBrush(Qt::white);
}

/*****************************************************************************
 * void drawComplexList(LinkedList<Complex> & inputComplexList):
 *          Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function draws ComplexList
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputComplexList values:
 *     LinkedList<Complex> & inputComplexList: input list
 *
 * POST-CONDITIONç
 *   program will draw ComplexList
 *
 *****************************************************************************/
void MainWindow::drawComplexList(
        LinkedList<Complex> & inputComplexList) // IN - input list
{
    scene = new QGraphicsScene();
    QBrush complexBrush(QColor(199, 155, 145)); // CALC - brush
    QPen blackPen(Qt::black);   // CALC - pen
    blackPen.setWidth(2);
    LinkedList<Complex>::Iterator it;   // CALC - itertor
    it = inputComplexList.begin();
    text = new QGraphicsTextItem;

    QString output;
    for(int i = 0; i < inputComplexList.length(); i++)
    {
        scene->addRect(-80+130*i,-80,100,30,blackPen,complexBrush);
        scene->addLine(10+130*i,-80,10+130*i,-50,blackPen);
        scene->addLine(20+130*i,-65,50+130*i,-65,blackPen);
        scene->addLine(50+130*i,-65,46+130*i,-61,blackPen);
        scene->addLine(50+130*i,-65,46+130*i,-69,blackPen);

        output = returnComplex(*it);
        text = scene->addText(output);
        text->setPos(-60+130*i,-77);
        ++it;
    }
    QGraphicsView * graphicsView =  // CALC - graphics view to draw the node
            new QGraphicsView(scene);
    graphicsView->show();
    graphicsView->setBackgroundBrush(Qt::white);
}

/*****************************************************************************
 * void runIntList(LinkedList<int> & inputIntList):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<int> & inputIntList: input list
 *
 * POST-CONDITIONç
 *   program will run functions of the data type
 *
 *****************************************************************************/
void MainWindow::runIntList(
        LinkedList<int> & inputIntList) // IN - input list
{

    LinkedList<int>::Iterator it;   // CALC - iterator
    LinkedList<int> newList;    // CALC - new list
    QString userInput;  // IN - input from the user
    QString output, // OUT - output for display
            temp;   // CALC - temp string variable
    QStringList value;  // CALC - value of the input
    int input = ui->INPUT->text().toInt();  // IN - input of the intList
    int start,  // IN - start index
            end,    //  IN - end index
            insertIndex,    // IN - index to be inserted
            checkIndex(0),  // IN - check if the index is valid
            count(0);   // IN - count to validate the input
    bool check(true),   // IN - check to validate the input
            valid(true),    // IN - validate the input when throw the exception
            ok; // IN - button of QInputDialog

    switch(FUNCTION)
    {
    case 0: // display all
        if(inputIntList.length() > 0)
        {
            for(it = inputIntList.begin(); it != inputIntList.end(); ++it)
                output += QString::number(*it) + " ";
            ui->OUTPUT->setText(output);
            QMessageBox::information(this,"IntList information","display_all function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"IntList Warning","This list is empty");
        }
        break;

    case 1: // display part

        if(inputIntList.length() > 0)
        {
            while(valid)
            {
                try
                {
                    output = "Range: 0 ~ "+QString::number(inputIntList.length()-1);
                    userInput = userInput = QInputDialog::getText(0,"Enter index(start-end)",output,QLineEdit::Normal,"",&ok);
                    output.clear();
                    if(ok && !userInput.isEmpty())
                    {
                        for(int i = 0; i < userInput.length(); i++)
                        {
                            if(userInput[i] == '-')
                            {

                                value.push_back(temp);
                                temp.clear();
                            }
                            else
                                temp += userInput[i];
                        }
                        value.push_back(temp);
                        temp.clear();
                        throw(value.length());
                    }
                    else
                        break;
                }
                catch(long long length)
                {
                    if(length != 2)
                    {
                        value.clear();
                        valid = true;
                    }
                    else
                    {

                        start = value[0].toInt();
                        end = value[1].toInt();
                        if(start >= 0 && start < inputIntList.length() && end >= 0 && end < inputIntList.length())
                        {
                            count = 0;
                            valid = false;
                            for(it = inputIntList.begin(); it != inputIntList.end(); ++it)
                            {

                                if(count >= start && count <= end)
                                {
                                    checkIndex = 1;
                                    output += QString::number(*it) + " ";
                                }
                                  count++;

                            }
                            if(checkIndex)
                            {
                                ui->OUTPUT->setText(output);
                                output.clear();
                                QMessageBox::information(this,"IntList information","display_part function worked");
                            }
                            else
                                QMessageBox::warning(this,"IntList warning","invalid index");
                        }
                        else
                            QMessageBox::warning(this,"IntList warning","invalid index");
                    }
                }

            }
        }
        else
            QMessageBox::warning(this,"IntList Warning","This list is empty");
        break;

    case 2: // push_back
        inputIntList.push_back(input);
        QMessageBox::information(this,"IntList information","push_back function worked");
        break;

    case 3: // push_front
        inputIntList.push_front(input);
        QMessageBox::information(this,"IntList information","push_front function worked");
        break;

    case 4: // pop_front
        if(inputIntList.length() > 0)
        {
            inputIntList.pop_front();
            QMessageBox::information(this,"IntList information","pop_front function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"IntList warning","This LinkedList is empty");
        }
        break;

    case 5: // insert_sort
        inputIntList.insert_sorted(input);
        QMessageBox::information(this,"IntList information","insert_sorted function worked");
        break;
    case 6: // insert
        output = "Range: 0 ~ "+QString::number(inputIntList.length());
        insertIndex = QInputDialog::getInt(0,"Enter index",output,0,0,1000,1,&ok);
        if(ok)
        {
            inputIntList.insert(insertIndex,input);
            QMessageBox::information(this,"IntList information","insert function worked");
        }
        else
            break;

        break;
    case 7: // select_sort
        if(inputIntList.length() > 0)
        {
            inputIntList.select_sort();
            QMessageBox::information(this,"IntList information","select_sort function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"IntList warning","This LinkedList is empty");
        }
        break;
    case 8: // remove_duplicates
        if(inputIntList.length() > 0)
        {
            inputIntList.remove_duplicates();
            QMessageBox::information(this,"IntList information","remove_duplicates function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"IntList warning","This LinkedList is empty");
        }
        break;
    case 9:// copy
        newList = inputIntList;
        intVector.push_back(newList);
        INT_COUNT++;
        output = "DUPLICATE_" + QString::number(INT_COUNT) + "_INT";
        intModelContent.push_back(output);
        intModel->setStringList(intModelContent);
        ui->COPY->setModel(intModel);
        QMessageBox::information(this,"IntList information","copy function worked");
        break;
    case 10:
        intVector.erase(version);
        intModelContent.pop_back();
        ui->COPY->setModel(intModel);
        break;
    case 11:
        drawIntList(inputIntList);
        break;
    default:
        break;
    }
    ui->INPUT->clear();

}

/*****************************************************************************
 * void runDoubleList(LinkedList<double> & inputDoubleList):
 *          Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<double> & inputDoubleList: input list
 *
 * POST-CONDITIONç
 *   program will run functions of the data type
 *
 *****************************************************************************/
void MainWindow::runDoubleList(
        LinkedList<double> & inputDoubleList)   // IN - input list
{
    LinkedList<double> newList; // CALC - iterator
    LinkedList<double>::Iterator it;    // CALC - new list
    QString userInput;  // IN - input from the user
    QString output, // OUT - output for display
            temp;   // CALC - value of the list
    QStringList value;  // CALC - value of the input
    int start,  // IN - start index
            end,    // IN - end index
            insertIndex,    // IN - index to be isnerted
            checkIndex(0),  // IN - check if the index is valid
            count(0);   // IN - count to validate the input
    double input =  // IN - input of the intList
            ui->INPUT->text().toDouble();
    bool check(true),   // IN - check to validate the input
            valid(true),    // IN - validate th einput when throw the excpetion
            ok; // IN - button of QInputDialog

    switch(FUNCTION)
    {
    case 0:
        if(inputDoubleList.length() > 0)
        {
            for(it = inputDoubleList.begin(); it != inputDoubleList.end(); ++it)
                output += QString::number(*it) + " ";
            ui->OUTPUT->setText(output);
            QMessageBox::information(this,"DoubleList information", "display_all function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"DoubleList Warning","This list is empty");
        }
        break;
    case 1:
        if(inputDoubleList.length() > 0)
        {
            while(valid)
            {
                try
                {
                    output = "Range: 0 ~ "+QString::number(inputDoubleList.length()-1);
                    userInput = userInput = QInputDialog::getText(0,"Enter index(start-end)",output,QLineEdit::Normal,"",&ok);
                    output.clear();
                    if(ok && !userInput.isEmpty())
                    {
                        for(int i = 0; i < userInput.length(); i++)
                        {
                            if(userInput[i] == '-')
                            {
                                count++;
                                value.push_back(temp);
                                temp.clear();
                            }
                            else
                                temp += userInput[i];
                        }
                        value.push_back(temp);
                        temp.clear();
                        throw(value.length());
                    }
                    else
                        break;
                }
                catch(long long length)
                {
                    if(length != 2)
                    {
                        value.clear();
                        valid = true;
                    }
                    else
                    {

                        start = value[0].toInt();
                        end = value[1].toInt();
                        if(start >= 0 && start < inputDoubleList.length() && end >= 0 && end < inputDoubleList.length())
                        {
                            count = 0;
                            valid = false;
                            for(it = inputDoubleList.begin(); it != inputDoubleList.end(); ++it)
                            {
                                if(count >= start && count <= end)
                                {
                                    checkIndex = 1;
                                    output += QString::number(*it) + " ";
                                }
                                count++;
                            }
                            if(checkIndex)
                            {
                                ui->OUTPUT->setText(output);
                                QMessageBox::information(this,"DoubleList information","display_part function worked");
                            }
                            else
                                QMessageBox::warning(this,"DoubleList warning","invalid index");
                        }
                        else
                            QMessageBox::warning(this,"DoubleList warning","invalid index");
                    }
                }

            }
        }
        else
            QMessageBox::warning(this,"DoubleList Warning","This list is empty");
        break;
    case 2:
        inputDoubleList.push_back(input);
        QMessageBox::information(this,"DoubleList information","push_back function worked");
        break;
    case 3:
        inputDoubleList.push_front(input);
        QMessageBox::information(this,"DoubleList information","push_front function worked");
        break;
    case 4:
        if(inputDoubleList.length() > 0)
        {
            inputDoubleList.pop_front();
            QMessageBox::information(this,"DoubleList information","pop_front function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"DoubleList Warning","This list is empty");
        }
        break;
    case 5:
        inputDoubleList.insert_sorted(input);
        QMessageBox::information(this,"DoubleList information","insert_sorted function worked");
        break;
    case 6:
        output = "Range: 0 ~ "+QString::number(inputDoubleList.length());
        insertIndex = QInputDialog::getInt(0,"Enter index",output,0,0,1000,1,&ok);
        if(ok)
        {
            inputDoubleList.insert(insertIndex,input);
            QMessageBox::information(this,"inputDoubleList information","insert function worked");
        }
        else
            break;
        break;
    case 7:
        if(inputDoubleList.length() > 0)
        {
            inputDoubleList.select_sort();
            QMessageBox::information(this,"DoubleList information","select_sort function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"DoubleList Warning","This list is empty");
        }
        break;
    case 8:
        if(inputDoubleList.length() > 0)
        {
            inputDoubleList.remove_duplicates();
            QMessageBox::information(this,"DoubletList information","remove_duplicates function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this,"DoubleList Warning","This list is empty");
        }
        break;
    case 9:
        newList = inputDoubleList;
        doubleVector.push_back(newList);
        DOUBLE_COUNT++;
        output = "DUPLICATE_" + QString::number(DOUBLE_COUNT) + "_DOUBLE";
        doubleModelContent.push_back(output);
        doubleModel->setStringList(doubleModelContent);
        ui->COPY->setModel(doubleModel);
        QMessageBox::information(this,"DoubleList information","copy function worked");
        break;
    case 10:
        doubleVector.pop_back();
        doubleModelContent.pop_back();
        ui->COPY->setModel(doubleModel);
        break;
    case 11:
        drawDoubleList(inputDoubleList);
        break;
    default: ;
    }
    ui->INPUT->clear();
}


/*****************************************************************************
 * void runStringList(LinkedList<string> & inputStringList): Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<string> & inputStringList: input list
 *
 * POST-CONDITIONç
 *   program will run functions of the data type
 *
 *****************************************************************************/
void MainWindow::runStringList(
        LinkedList<string> & inputStringList)   // IN - input  list
{
    LinkedList<string> newList; // CALC - new list
    LinkedList<string>::Iterator it;    // CALC - iterator
    QString userInput;  // IN - user input
    QString output, // OUT - output for display
            temp;   // CALC - temp string variable
    QStringList value;  // CALC - value of the inputList
    int start,  // IN - start index
            end,    // IN - end index
            insertIndex,    // IN - index to be inserted
            checkIndex(0),  // IN - check if the index is valid
            count(0);   // IN - count to validate the input
    string input =
            ui->INPUT->text().toStdString(); // IN - input of the stringList
    bool check(true)    // CALC - check to validate the input
            ,valid(true),   // CALC - check if input is valid
            ok; // IN - button of QInputDialog

    switch(FUNCTION)
    {
    case 0:
        if(inputStringList.length() > 0)
        {
            for(it = inputStringList.begin(); it != inputStringList.end(); ++it)
                output += QString::fromStdString(*it) + " ";
            ui->OUTPUT->setText(output);
            QMessageBox::information(this,"StringList information", "display_all function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "StringList Warning","This list is empty");
        }
        break;
    case 1:
        if(inputStringList.length() > 0)
        {
            while(valid)
            {
                try
                {
                    output = "Range: 0 ~ "+QString::number(inputStringList.length()-1);
                    userInput = userInput = QInputDialog::getText(0,"Enter index(start-end)",output,QLineEdit::Normal,"",&ok);
                    output.clear();
                    if(ok && !userInput.isEmpty())
                    {
                        for(int i = 0; i < userInput.length(); i++)
                        {
                            if(userInput[i] == '-')
                            {
                                count++;
                                value.push_back(temp);
                                temp.clear();
                            }
                            else
                                temp += userInput[i];
                        }
                        value.push_back(temp);
                        temp.clear();
                        throw(value.length());
                    }
                    else
                        break;
                }
                catch(long long length)
                {
                    if(length != 2)
                    {
                        value.clear();
                        valid = true;
                    }
                    else
                    {

                        start = value[0].toInt();
                        end = value[1].toInt();
                        if(start >= 0 && start < inputStringList.length() && end >= 0 && end < inputStringList.length())
                        {
                            count = 0;
                            valid = false;
                            for(it = inputStringList.begin(); it != inputStringList.end(); ++it)
                            {
                                if(count >= start && count <= end)
                                {
                                    checkIndex = 1;
                                    output += QString::fromStdString(*it) + " ";
                                }
                                count++;
                            }
                            if(checkIndex)
                            {
                                ui->OUTPUT->setText(output);
                                QMessageBox::information(this,"StringList information","display_part function worked");
                            }
                            else
                                QMessageBox::warning(this,"StringList warning","invalid index");
                        }
                        else
                            QMessageBox::warning(this,"StringList warning","invalid index");
                    }
                }

            }
        }
        else
            QMessageBox::warning(this,"StringList Warning","This list is empty");
        break;
    case 2:
        inputStringList.push_back(input);
        QMessageBox::information(this,"StringList information","push_back function worked");
        break;
    case 3:
        inputStringList.push_front(input);
        QMessageBox::information(this,"StringList information","push_front function worked");
        break;
    case 4:
        if(inputStringList.length() > 0)
        {
            inputStringList.pop_front();
            QMessageBox::information(this,"StringList information","pop_front function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "StringList Warning","This list is empty");
        }
        break;
    case 5:
        inputStringList.insert_sorted(input);
        QMessageBox::information(this,"StringList information","insert_sorted function worked");
        break;
    case 6:
        output = "Range: 0 ~ "+QString::number(inputStringList.length());
        insertIndex = QInputDialog::getInt(0,"Enter index",output,0,0,1000,1,&ok);
        if(ok)
        {
            inputStringList.insert(insertIndex,input);
            QMessageBox::information(this,"StringList information","insert function worked");
        }
        else
            break;
        break;
    case 7:
        if(inputStringList.length() > 0)
        {
            inputStringList.select_sort();
            QMessageBox::information(this,"StringList information","select_sort function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "StringList Warning","This list is empty");
        }
        break;
    case 8:
        if(inputStringList.length() > 0)
        {
            inputStringList.remove_duplicates();
            QMessageBox::information(this,"StringList information","remove_duplicates function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "StringList Warning","This list is empty");
        }
        break;
    case 9:
        newList = inputStringList;
        stringVector.push_back(newList);
        STRING_COUNT++;
        output = "DUPLICATE_" + QString::number(STRING_COUNT) + "_STRING";
        stringModelContent.push_back(output);
        stringModel->setStringList(stringModelContent);
        ui->COPY->setModel(stringModel);
        QMessageBox::information(this,"StringList information","copy function worked");
        break;
    case 10:
        stringVector.pop_back();
        stringModelContent.pop_back();
        ui->COPY->setModel(stringModel);
        break;
    case 11:
        drawStringList(inputStringList);
        break;
    default: ;
    }
    ui->INPUT->clear();

}

/*****************************************************************************
 * QString returnRational(const Rational & inputRational):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *    const Rational & inputRational: input list
 *
 * POST-CONDITIONç
 *   program returns the qstring of the rational data
 *
 *****************************************************************************/
QString MainWindow::returnRational(
        const Rational & inputRational) // IN - input rational list
{
    return QString::number(inputRational.getNumer()) +
            "/" + QString::number(inputRational.getDenom());
}

/*****************************************************************************
 * void runRationalList(LinkedList<Rational> & inputRationalList):
 *           Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<Rational> & inputRationalList: input list
 *
 * POST-CONDITIONç
 *   program will run functions of the data type
 *
 *****************************************************************************/
void MainWindow::runRationalList(
        LinkedList<Rational> & inputRationalList)   // IN - input list
{
    LinkedList<Rational> newList;   // CALC/OUT - new list
    LinkedList<Rational>::Iterator it;  // CALC - iterator

    Rational input; // IN - input of the rational List
    QString userInput,  // IN - input from user
            output, // OUT - output to display the list
            temp;   // CALC - temp QString
    QStringList value;  // CALC - value of the input
    string display; // CALC - string to used for display
    int numer,  // IN - numerator
        denom,  // IN - denominator
        start,  // IN - start index
        end,    // IN - end index
        count(0),   // CALC - count to validate the input
        checkIndex(0),  // CALC - check if index is valid
        insertIndex;   // IN - index to be inserted
    bool check(true),   // CALC - check to be used for the input validation
         ok,    // IN - button of QInputDialog
         valid(1);  // CALC - validate the input

    switch(FUNCTION)
    {
    case 0: // x
        if(inputRationalList.length() > 0)
        {
            for(it = inputRationalList.begin(); it != inputRationalList.end(); ++it)
               output += returnRational(*it) + " ";
            ui->OUTPUT->setText(output);
            QMessageBox::information(this, "RationalList information", "display_all function worked");
            return;
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "RationalList Warning","This list is empty");
        }
        break;
    case 1: // x
        if(inputRationalList.length() > 0)
        {
            while(valid)
            {
                try
                {
                    output = "Range: 0 ~ "+QString::number(inputRationalList.length()-1);
                    userInput = userInput = QInputDialog::getText(0,"Enter index(start-end)",output,QLineEdit::Normal,"",&ok);
                    output.clear();
                    if(ok && !userInput.isEmpty())
                    {
                        for(int i = 0; i < userInput.length(); i++)
                        {
                            if(userInput[i] == '-')
                            {
                                count++;
                                value.push_back(temp);
                                temp.clear();
                            }
                            else
                                temp += userInput[i];
                        }
                        value.push_back(temp);
                        temp.clear();
                        throw(value.length());
                    }
                    else
                        break;
                }
                catch(long long length)
                {
                    if(length != 2)
                    {
                        value.clear();
                        valid = true;
                    }
                    else
                    {
                        start = value[0].toInt();
                        end = value[1].toInt();
                        if(start >= 0 && start < inputRationalList.length() && end >= 0 && end < inputRationalList.length())
                        {
                            count = 0;
                            valid = false;
                            for(it = inputRationalList.begin(); it != inputRationalList.end(); ++it)
                            {
                                if(count >= start && count <= end)
                                {
                                    checkIndex = 1;
                                    output += returnRational(*it) + " ";
                                }
                                count++;
                            }
                            if(checkIndex)
                            {
                                ui->OUTPUT->setText(output);
                                QMessageBox::information(this,"RationalList information","display_part function worked");
                            }
                            else
                                QMessageBox::warning(this,"RationalList warning","invalid index");
                        }
                        else
                            QMessageBox::warning(this,"RationalList warning","invalid index");
                    }
                }

            }
        }
        else
            QMessageBox::warning(this,"RationalList Warning","This list is empty");
        break;
    case 2:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Rational","numer/denom",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);
                            display = temp.toStdString();
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                    break;
            }
            catch(long long length)
            {
                if(length != 2)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    numer = value[0].toInt();
                    denom = value[1].toInt();
                    input.setValue(numer,denom);
                    inputRationalList.push_back(input);
                    QMessageBox::information(this,"RationalList information","push_back function worked");
                }
            }

        }
        break;
    case 3:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Rational","numer/denom",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);
                            display = temp.toStdString();
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                    break;
            }
            catch(long long length)
            {
                if(length != 2)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    numer = value[0].toInt();
                    denom = value[1].toInt();
                    input.setValue(numer,denom);
                    inputRationalList.push_front(input);
                    QMessageBox::information(this,"RationalList information","push_front function worked");

                }
            }

        }
        break;
    case 4: // x
        if(inputRationalList.length() > 0)
        {
            inputRationalList.pop_front();
            QMessageBox::information(this,"RationalList information","pop_front function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "RationalList Warning","This list is empty");
        }
        break;
    case 5: // x
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Rational","numer/denom",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);
                            display = temp.toStdString();
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                    break;
            }
            catch(long long length)
            {
                if(length != 2)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    numer = value[0].toInt();
                    denom = value[1].toInt();
                    input.setValue(numer,denom);
                    inputRationalList.insert_sorted(input);
                    QMessageBox::information(this,"RationalList information","insert_sorted function worked");

                }
            }

        }
        break;
    case 6: // x
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Rational and index","numer/denom/index",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                {
                    break;
                }
            }
            catch(long long length)
            {
                if(length != 4)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    numer = value[0].toInt();
                    denom = value[1].toInt();
                    insertIndex = value[2].toInt();
                    input.setValue(numer,denom);
                    inputRationalList.insert(insertIndex,input);
                    QMessageBox::information(this,"RationalList information","insert function worked");
                }
            }
        }
        break;
    case 7:
        if(inputRationalList.length() > 0)
        {
            inputRationalList.select_sort();
            QMessageBox::information(this,"RationalList information","select_sort function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "RationalList Warning","This list is empty");
        }
        break;
    case 8: // x
        if(inputRationalList.length() > 0)
        {
            inputRationalList.remove_duplicates();
            QMessageBox::information(this,"RationalList information","remove_duplicates function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "RationalList Warning","This list is empty");
        }
        break;
    case 9:
        newList = inputRationalList;
        rationalVector.push_back(newList);
        RATIONAL_COUNT++;
        output = "DUPLICATE_" + QString::number(RATIONAL_COUNT) + "_RATIONAL";
        rationalModelContent.push_back(output);
        rationalModel->setStringList(rationalModelContent);
        ui->COPY->setModel(rationalModel);
        QMessageBox::information(this,"RationalList information","copy function worked");
        break;
    case 10:
        rationalVector.pop_back();
        rationalModelContent.pop_back();
        ui->COPY->setModel(rationalModel);
        break;
    case 11:
        drawRationalList(inputRationalList);
        break;
    default:;
    }
    ui->INPUT->clear();
}

/*****************************************************************************
 * QString returnDate(const Date & inputDate):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *   const Date & inputDate): input list
 *
 * POST-CONDITIONç
 *   program returns the qstring of the Date data
 *
 *****************************************************************************/
QString MainWindow::returnDate(const Date & inputDate)  // IN - input list
{
    return QString::number(inputDate.returnMonth())
            + "/" + QString::number(inputDate.returnDay())
            + "/" + QString::number(inputDate.returnYear());

}

/*****************************************************************************
 * void runDateList(LinkedList<Date> & inputDateList):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<Date> & inputDateList: input list
 *
 * POST-CONDITIONç
 *   program will run functions of the data type
 *
 *****************************************************************************/
void MainWindow::runDateList(
        LinkedList<Date> & inputDateList)   // IN - input list
{
    LinkedList<Date> newList;   // CALC - new list
    LinkedList<Date>::Iterator it;  // CALC - iterator
    Date input; // IN - input from the user
    QString userInput,  // IN - input from the user
            output, // OUT - output to be used when program dispalys the list
            temp;  // CALC - temp variable
    QStringList value;  // CALC - value of the inputList
    string wholeData;   // IN - string version of user's input
    int month,  // IN - month of the input
        day,    // IN - day of the input
        year,   // IN - year of th einput
        start,  // IN - starting index
        end,    // IN - ending index
        count(0),   // IN - count to validate the input
        checkIndex(0),  // IN - check index
        insertIndex;    // IN - index to be inserted
    bool check(true),   // CALC - check to be used for validation
         valid(true),   // CACL - check if input is valid
         ok;    // IN - button of QInputDialog
    switch(FUNCTION)
    {
    case 0:
        if(inputDateList.length() > 0)
        {
            for(it = inputDateList.begin(); it != inputDateList.end(); ++it)
                output += returnDate(*it) + " ";
            ui->OUTPUT->setText(output);
            QMessageBox::information(this, "DateList information", "display_all function worked");
            return;
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "DatelList Warning","This list is empty");
        }
        break;

    case 1:
        if(inputDateList.length() > 0)
        {
            while(valid)
            {
                try
                {
                    output = "Range: 0 ~ "+QString::number(inputDateList.length()-1);
                    userInput = userInput = QInputDialog::getText(0,"Enter index(start-end)",output,QLineEdit::Normal,"",&ok);
                    output.clear();
                    if(ok && !userInput.isEmpty())
                    {
                        for(int i = 0; i < userInput.length(); i++)
                        {
                            if(userInput[i] == '-')
                            {
                                count++;
                                value.push_back(temp);
                                temp.clear();
                            }
                            else
                                temp += userInput[i];
                        }
                        value.push_back(temp);
                        temp.clear();
                        throw(value.length());
                    }
                    else
                        break;
                }
                catch(long long length)
                {
                    if(length != 2)
                    {
                        value.clear();
                        valid = true;
                    }
                    else
                    {

                        start = value[0].toInt();
                        end = value[1].toInt();
                        if(start >= 0 && start < inputDateList.length() && end >= 0 && end < inputDateList.length())
                        {
                            count = 0;
                            valid = false;
                            for(it = inputDateList.begin(); it != inputDateList.end(); ++it)
                            {
                                if(count >= start && count <= end)
                                {
                                    checkIndex = 1;
                                    output += returnDate(*it) + " ";
                                }
                                count++;
                            }
                            if(checkIndex)
                            {
                                ui->OUTPUT->setText(output);
                                QMessageBox::information(this,"DateList information","display_part function worked");
                            }
                            else
                                QMessageBox::warning(this,"DateList warning","invalid index");
                        }
                        else
                            QMessageBox::warning(this,"DateList warning","invalid index");
                    }
                }

            }
        }
        else
            QMessageBox::warning(this,"DateList Warning","This list is empty");
        break;

    case 2:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Date","month/day/year",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                {
                    break;
                }

            }
            catch(long long length)
            {
                if(length != 3)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    month = value[0].toInt();
                    day = value[1].toInt();
                    year = value[2].toInt();
                    input.setValue(month,day,year);
                    inputDateList.push_back(input);
                    QMessageBox::information(this,"DateList information","push_back function worked");
                 }
            }
        }
        break;
    case 3:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Date","month/day/year",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);

                            wholeData = temp.toStdString();
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                {
                    break;
                }

            }
            catch(long long length)
            {
                if(length != 3)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    month = value[0].toInt();
                    day = value[1].toInt();
                    year = value[2].toInt();
                    input.setValue(month,day,year);
                    inputDateList.push_front(input);
                    QMessageBox::information(this,"DateList information","push_front function worked");
                 }
            }
        }
        break;
    case 4:
        if(inputDateList.length() > 0)
        {
            inputDateList.pop_front();
            QMessageBox::information(this,"DateList information","pop_front function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "DatelList Warning","This list is empty");
        }
        break;
    case 5:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Date","month/day/year",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);

                            wholeData = temp.toStdString();
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                {
                    break;
                }

            }
            catch(long long length)
            {
                if(length != 3)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    month = value[0].toInt();
                    day = value[1].toInt();
                    year = value[2].toInt();
                    input.setValue(month,day,year);
                    inputDateList.insert_sorted(input);
                    QMessageBox::information(this,"DateList information","insert_sorted function worked");
                 }
            }
        }
        break;
    case 6:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Date and index","month/day/year/index",QLineEdit::Normal,"",&ok);
                if(ok && !userInput.isEmpty())
                {
                    for(int i = 0; i < userInput.length(); i++)
                    {
                        if(userInput[i] == '/')
                        {
                            count++;
                            value.push_back(temp);

                            wholeData = temp.toStdString();
                            temp.clear();
                        }
                        else
                            temp += userInput[i];
                    }
                    value.push_back(temp);
                    temp.clear();
                    throw(value.length());
                }
                else
                {
                    break;
                }
            }
            catch(long long length)
            {
                if(length != 4)
                {
                    value.clear();
                    valid = true;
                }
                else
                {
                    valid = false;
                    month = value[0].toInt();
                    day = value[1].toInt();
                    year = value[2].toInt();
                    insertIndex = value[3].toInt();
                    input.setValue(month,day,year);
                    inputDateList.insert(insertIndex,input);
                    QMessageBox::information(this,"DateList information","insert function worked");
                }
            }
        }
        break;
    case 7:
        if(inputDateList.length() > 0)
        {
            inputDateList.select_sort();
            QMessageBox::information(this,"DateList information","select_sort function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "DatelList Warning","This list is empty");
        }
        break;
    case 8:
        if(inputDateList.length() > 0)
            inputDateList.remove_duplicates();
        break;

    case 9:
        newList = inputDateList;
        dateVector.push_back(newList);
        DATE_COUNT++;
        output = "DUPLICATE_" + QString::number(DATE_COUNT) + "_DATE";
        dateModelContent.push_back(output);
        dateModel->setStringList(dateModelContent);
        ui->COPY->setModel(dateModel);
        QMessageBox::information(this,"DateList information","copy function worked");
        break;
    case 10:
        dateVector.pop_back();
        dateModelContent.pop_back();
        ui->COPY->setModel(dateModel);
        break;
    case 11:
        drawDateList(inputDateList);
        break;
    default:;
    }
}

/*****************************************************************************
 * QString returnComplex(const Complex & inputComplex):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *    const Complex & inputComplex: input list
 *
 * POST-CONDITIONç
 *   program returns the qstring of the Complex data
 *
 *****************************************************************************/
QString MainWindow::returnComplex(
        const Complex & inputComplex)   // IN - input lsit
{
    QString input;  // CALC/OUT - input to be returned in QString
    input += QString::number(inputComplex.returnReal());
    if(inputComplex.returnImagin() < 0)
        input += QString::number(inputComplex.returnImagin()) + "i";
    else
        input += "+" + QString::number(inputComplex.returnImagin()) + "i";
    return input;

}

/*****************************************************************************
 * Complex readComplex(const string temp):  Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function converts string into Complex
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     const string temp: string to be converted into Complex
 *
 * POST-CONDITIONç
 *   program will return Complex object
 *
 *****************************************************************************/
Complex MainWindow::readComplex(
          const string temp)    // IN - string to be converted to complex
{
    Complex input;  // IN - complex to be returned
    int im; // CALC - imaginary number
    int re; // CALC - real number
    string numTemp; // CALC - stores temporary number
    string realT;   // CALC - store real number
    string imaginT; // CALC - store imaginary number

    im = 0;
    re = 0;
    realT = "";
    imaginT  = "";

    for(int i = 0; i < temp.size(); i++)
      {
        if(i == 0)
        {
          if(temp[i]== '-')
            numTemp += temp[i];
          else if(temp[i] == 'i')
          {
            numTemp += '1';
            im = 1;
          }
          else
            numTemp += temp[i];
        }
        else
        {
          if(temp[i] == 'i')
          {
            if(temp[i-1] == '-')
            {
              numTemp += '1';
              imaginT += numTemp;
            }
            else if(temp[i-1] == '+')
            {
                numTemp += '1';
                imaginT += numTemp;
            }
            else
            {
              imaginT += numTemp;
              numTemp.clear();
            }
            im = 1;
          }
          else if(temp[i]=='-')
          {

            realT += numTemp;
            numTemp .clear();
            imaginT += temp[i];
            re=1;
          }
          else if(temp[i]=='+')
          {
            realT += numTemp;
            numTemp.clear();
            re=1;
          }
          else if(isdigit(temp[i])||temp[i]=='.')
            numTemp += temp[i];
        }
      }
      if(re != 0 && im == 0 && numTemp != "")
      {
        realT = numTemp;
        imaginT.clear();
      }
      else if(re == 0 && im != 0 && numTemp != "")
      {
        realT.clear();
        imaginT = numTemp;
      }
      else if(re == 0 && im == 0 && numTemp == "")
      {
        realT = "";
        imaginT = "";
      }
      else if(re == 0 && im == 0 && numTemp != "")
      {
        realT = numTemp;
        imaginT.clear();
      }

      if(realT.empty())
        input.setReal(0);
      else
        input.setReal(stod(realT));

      if(imaginT.empty())
        input.setImain(0);
      else
        input.setImain(stod(imaginT));

      return input;
}

/*****************************************************************************
 * void runComplexList(LinkedList<Complex> & inputComplexList):
 *           Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function runs functions of the data type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     LinkedList<Complex> & inputComplexList: input list
 *
 * POST-CONDITIONç
 *   program will run functions of the data type
 *
 *****************************************************************************/
void MainWindow::runComplexList(
        LinkedList<Complex> & inputComplexList) // IN - input list
{
    LinkedList<Complex> newList;    // CALC/OUT - new list
    LinkedList<Complex>::Iterator it;   // CALC - iterator
    Complex input;  // IN - input of the complex list

    QString userInput,// IN - input from the user
            output, // OUT - output to display the list
            temp;   // CALC - temp QString
    string wholeData;   // CALC - stores input from the user
    QStringList value;  // CALC - value of the input
    double real,    // IN - real number
           imagin,  // IN - imagiary number
           start,   // IN - starting index
           end, // IN - ending index
           count(0),    // CALC - count to validate the input
           checkIndex(0),   // CALC - check if index is valid
           insertIndex; // IN - index tob e inserted
    bool check(true),   // CALC - check to be used for the input validation
         valid(true),   // CALC - validate the input
         ok;    // IN - button of QInputBotton
    switch(FUNCTION)
    {
    case 0:
        if(inputComplexList.length() > 0)
        {
            for(it = inputComplexList.begin(); it != inputComplexList.end(); ++it)
                output += returnComplex(*it) + " ";
            ui->OUTPUT->setText(output);
            QMessageBox::information(this, "ComplexList information", "display_all function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "ComplexlList Warning","This list is empty");
        }
        break;
    case 1:
        if(inputComplexList.length() > 0)
        {
            while(valid)
            {
                try
                {
                    output = "Range: 0 ~ "+QString::number(inputComplexList.length()-1);
                    userInput = userInput = QInputDialog::getText(0,"Enter index(start-end)",output,QLineEdit::Normal,"",&ok);
                    output.clear();
                    if(ok && !userInput.isEmpty())
                    {
                        for(int i = 0; i < userInput.length(); i++)
                        {
                            if(userInput[i] == '-')
                            {
                                count++;
                                value.push_back(temp);
                                temp.clear();
                            }
                            else
                                temp += userInput[i];
                        }
                        value.push_back(temp);
                        temp.clear();
                        throw(value.length());
                    }
                    else
                        break;
                }
                catch(long long length)
                {
                    if(length != 2)
                    {
                        value.clear();
                        valid = true;
                    }
                    else
                    {
                        start = value[0].toInt();
                        end = value[1].toInt();
                        if(start >= 0 && start < inputComplexList.length() && end >= 0 && end < inputComplexList.length())
                        {
                            valid = false;
                            count = 0;
                            for(it = inputComplexList.begin(); it != inputComplexList.end(); ++it)
                            {

                                if(count >= start && count <= end)
                                {
                                    checkIndex = 1;
                                    output += returnComplex(*it) + " ";
                                }
                                count++;
                            }
                            if(checkIndex)
                            {
                                ui->OUTPUT->setText(output);
                                output.clear();
                                QMessageBox::information(this,"ComplexList information","display_part function worked");
                            }
                            else
                                QMessageBox::warning(this,"ComplexList warning","invalid index");
                        }
                        else
                            QMessageBox::warning(this,"ComplexList warning","invalid index");
                    }
                }

            }
        }
        else
            QMessageBox::warning(this,"ComplexList Warning","This list is empty");
        break;
    case 2:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Complex number","real# (+/-) imaginary# i");
                wholeData = userInput.toStdString();
                input = readComplex(wholeData);
                throw(input);
            }
            catch(Complex input)
            {
                valid = false;
            }
            catch(...)
            {
                return;
            }
        }

        inputComplexList.push_back(input);
        QMessageBox::information(this,"ComplexList information","push_back function worked");
        break;
    case 3:

        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Complex number","real# (+/-) imaginary# i");
                wholeData = userInput.toStdString();
                input = readComplex(wholeData);
                throw(input);
            }
            catch(Complex input)
            {
                valid = false;
            }
            catch(...)
            {
                return;
            }
        }
        inputComplexList.push_front(input);
        QMessageBox::information(this,"ComplexList information","push_front function worked");
        break;
        break;
    case 4:
        if(inputComplexList.length() > 0)
        {
            inputComplexList.pop_front();
            QMessageBox::information(this,"ComplexList information","pop_front function worked");
        }
        else
            QMessageBox::warning(this,"ComplexList Warning","This list is empty");
        break;
    case 5:
        userInput = QInputDialog::getText(0,"Enter Complex number","real# (+/-) imaginary# i");
        wholeData = userInput.toStdString();
        readComplex(wholeData);
        inputComplexList.insert_sorted(input);
        QMessageBox::information(this,"ComplexList information","insert_sorted function worked");
        break;
    case 6:
        while(valid)
        {
            try
            {
                userInput = QInputDialog::getText(0,"Enter Complex number and index","real# (+/-) imaginary# i/index");
                value = userInput.split("/");
                wholeData = value[0].toStdString();
                input = readComplex(wholeData);
                throw(input);
            }
            catch(Complex input)
            {
                valid = false;
            }
            catch(...)
            {
                return;
            }
        }
        insertIndex = value[1].toInt();
        inputComplexList.insert(insertIndex,input);
        QMessageBox::information(this,"ComplexList information","insert function worked");
        break;
    case 7:
        if(inputComplexList.length() > 0)
        {
            inputComplexList.select_sort();
            QMessageBox::information(this,"ComplexList information","select_sort function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "ComplexlList Warning","This list is empty");
        }
        break;
    case 8:
        if(inputComplexList.length() > 0)
        {
            inputComplexList.remove_duplicates();
            QMessageBox::information(this,"ComplexList information","remove_duplicates function worked");
        }
        else
        {
            ui->OUTPUT->clear();
            QMessageBox::warning(this, "ComplexlList Warning","This list is empty");
        }
        break;
    case 9:
        newList = inputComplexList;
        complexVector.push_back(newList);
        COMPLEX_COUNT++;
        output = "DUPLICATE_" + QString::number(DATE_COUNT) + "_COMPLEX";
        complexModelContent.push_back(output);
        complexModel->setStringList(complexModelContent);
        ui->COPY->setModel(complexModel);
        QMessageBox::information(this,"DateList information","copy function worked");
        break;
    case 10:
        complexVector.pop_back();
        complexModelContent.pop_back();
        ui->COPY->setModel(complexModel);
        break;
    case 11:
        drawComplexList(inputComplexList);
        break;
    default:;
    }
}

/*****************************************************************************
 * int on_TYPE_currentIndexChanged(int index):
 *           Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function returns the variable type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     int index: chosen index from the combo box
 *
 * POST-CONDITIONç
 *   program will return the variable type
 *
 *****************************************************************************/
int MainWindow::on_TYPE_currentIndexChanged(
        int index)  // IN - chosen index from the combo box
{
    TYPE = index;
    return TYPE;
}

/*****************************************************************************
 * int on_FUNCTION_currentIndexChanged(int index):
 *           Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function returns the function type
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     int index: chosen index from the combo box
 *
 * POST-CONDITIONç
 *   program will return the function type
 *
 *****************************************************************************/
int MainWindow::on_FUNCTION_currentIndexChanged(
        int index)  // IN - chose index from combo box
{
    FUNCTION = index;
    return FUNCTION;
}

/*****************************************************************************
 * int on_COPY_currentIndexChanged(int index):
 *           Class MainWindow
 *
 * ---------------------------------------------------------------------------
 * This function returns the version of the list
 *
 * ---------------------------------------------------------------------------
 * PRE-CONDITION
 *   The following need previously inputStringList values:
 *     int index: chosen index from the combo box
 *
 * POST-CONDITIONç
 *   program will return the version of the list
 *
 *****************************************************************************/
void MainWindow::on_COPY_currentIndexChanged(
        int index)  // IN - chosen index from combo box
{
    version = index;
}

