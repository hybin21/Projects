/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *INPUT;
    QLineEdit *OUTPUT;
    QLabel *INPUT_LABEL;
    QLabel *OUTPUT_LABEL;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QComboBox *COPY;
    QComboBox *TYPE;
    QComboBox *FUNCTION;
    QPushButton *ENTER_2;
    QPushButton *CLOSE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(570, 306);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 204, 230);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        INPUT = new QLineEdit(centralwidget);
        INPUT->setObjectName(QString::fromUtf8("INPUT"));
        INPUT->setGeometry(QRect(20, 30, 181, 31));
        INPUT->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"\n"
"background-color: rgb(107, 96, 121);"));
        OUTPUT = new QLineEdit(centralwidget);
        OUTPUT->setObjectName(QString::fromUtf8("OUTPUT"));
        OUTPUT->setGeometry(QRect(230, 30, 301, 181));
        OUTPUT->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"\n"
"background-color: rgb(107, 96, 121);"));
        INPUT_LABEL = new QLabel(centralwidget);
        INPUT_LABEL->setObjectName(QString::fromUtf8("INPUT_LABEL"));
        INPUT_LABEL->setGeometry(QRect(90, 10, 58, 16));
        INPUT_LABEL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        OUTPUT_LABEL = new QLabel(centralwidget);
        OUTPUT_LABEL->setObjectName(QString::fromUtf8("OUTPUT_LABEL"));
        OUTPUT_LABEL->setGeometry(QRect(350, 10, 58, 16));
        OUTPUT_LABEL->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(20, 80, 187, 171));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        COPY = new QComboBox(splitter);
        COPY->setObjectName(QString::fromUtf8("COPY"));
        COPY->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        splitter->addWidget(COPY);
        TYPE = new QComboBox(splitter);
        TYPE->addItem(QString());
        TYPE->addItem(QString());
        TYPE->addItem(QString());
        TYPE->addItem(QString());
        TYPE->addItem(QString());
        TYPE->addItem(QString());
        TYPE->setObjectName(QString::fromUtf8("TYPE"));
        TYPE->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        splitter->addWidget(TYPE);
        splitter_2->addWidget(splitter);
        FUNCTION = new QComboBox(splitter_2);
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->addItem(QString());
        FUNCTION->setObjectName(QString::fromUtf8("FUNCTION"));
        FUNCTION->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        splitter_2->addWidget(FUNCTION);
        ENTER_2 = new QPushButton(splitter_2);
        ENTER_2->setObjectName(QString::fromUtf8("ENTER_2"));
        ENTER_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        splitter_2->addWidget(ENTER_2);
        CLOSE = new QPushButton(splitter_2);
        CLOSE->setObjectName(QString::fromUtf8("CLOSE"));
        CLOSE->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        splitter_2->addWidget(CLOSE);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 570, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(CLOSE, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        INPUT_LABEL->setText(QCoreApplication::translate("MainWindow", "  INPUT", nullptr));
        OUTPUT_LABEL->setText(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
        TYPE->setItemText(0, QCoreApplication::translate("MainWindow", "INT", nullptr));
        TYPE->setItemText(1, QCoreApplication::translate("MainWindow", "DOUBLE", nullptr));
        TYPE->setItemText(2, QCoreApplication::translate("MainWindow", "STRING", nullptr));
        TYPE->setItemText(3, QCoreApplication::translate("MainWindow", "RATIONAL", nullptr));
        TYPE->setItemText(4, QCoreApplication::translate("MainWindow", "DATE", nullptr));
        TYPE->setItemText(5, QCoreApplication::translate("MainWindow", "COMPLEX", nullptr));

        FUNCTION->setItemText(0, QCoreApplication::translate("MainWindow", "DISLAY ALL", nullptr));
        FUNCTION->setItemText(1, QCoreApplication::translate("MainWindow", "DISPLAY PART", nullptr));
        FUNCTION->setItemText(2, QCoreApplication::translate("MainWindow", "PUSH BACK", nullptr));
        FUNCTION->setItemText(3, QCoreApplication::translate("MainWindow", "PUSH FRONT", nullptr));
        FUNCTION->setItemText(4, QCoreApplication::translate("MainWindow", "POP FRONT", nullptr));
        FUNCTION->setItemText(5, QCoreApplication::translate("MainWindow", "INSERT SORT", nullptr));
        FUNCTION->setItemText(6, QCoreApplication::translate("MainWindow", "INSERT", nullptr));
        FUNCTION->setItemText(7, QCoreApplication::translate("MainWindow", "SELECT SORT", nullptr));
        FUNCTION->setItemText(8, QCoreApplication::translate("MainWindow", "REMOVE DUPLICATES", nullptr));
        FUNCTION->setItemText(9, QCoreApplication::translate("MainWindow", "COPY", nullptr));
        FUNCTION->setItemText(10, QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        FUNCTION->setItemText(11, QCoreApplication::translate("MainWindow", "DRAW ", nullptr));

        ENTER_2->setText(QCoreApplication::translate("MainWindow", "ENTER", nullptr));
        CLOSE->setText(QCoreApplication::translate("MainWindow", "CLOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
