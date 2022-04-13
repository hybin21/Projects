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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *INPUT_BOX;
    QLineEdit *OUTPUT_BOX;
    QSlider *SLIDER;
    QPushButton *F_BUTTON;
    QPushButton *C_BUTTON;
    QLabel *current;
    QLabel *converted;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(466, 383);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(134, 155, 199);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        INPUT_BOX = new QLineEdit(centralwidget);
        INPUT_BOX->setObjectName(QString::fromUtf8("INPUT_BOX"));
        INPUT_BOX->setGeometry(QRect(160, 60, 141, 41));
        INPUT_BOX->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"color: rgb(2, 2, 2);\n"
"background-color: rgb(255, 255, 255);"));
        OUTPUT_BOX = new QLineEdit(centralwidget);
        OUTPUT_BOX->setObjectName(QString::fromUtf8("OUTPUT_BOX"));
        OUTPUT_BOX->setGeometry(QRect(160, 250, 141, 41));
        OUTPUT_BOX->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        SLIDER = new QSlider(centralwidget);
        SLIDER->setObjectName(QString::fromUtf8("SLIDER"));
        SLIDER->setGeometry(QRect(150, 190, 160, 25));
        SLIDER->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        SLIDER->setOrientation(Qt::Horizontal);
        F_BUTTON = new QPushButton(centralwidget);
        F_BUTTON->setObjectName(QString::fromUtf8("F_BUTTON"));
        F_BUTTON->setGeometry(QRect(160, 120, 61, 51));
        F_BUTTON->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
        C_BUTTON = new QPushButton(centralwidget);
        C_BUTTON->setObjectName(QString::fromUtf8("C_BUTTON"));
        C_BUTTON->setGeometry(QRect(240, 120, 61, 51));
        C_BUTTON->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        current = new QLabel(centralwidget);
        current->setObjectName(QString::fromUtf8("current"));
        current->setGeometry(QRect(170, 40, 131, 20));
        current->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        converted = new QLabel(centralwidget);
        converted->setObjectName(QString::fromUtf8("converted"));
        converted->setGeometry(QRect(160, 230, 141, 20));
        converted->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 466, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        F_BUTTON->setText(QCoreApplication::translate("MainWindow", "F->C", nullptr));
        C_BUTTON->setText(QCoreApplication::translate("MainWindow", "C->F", nullptr));
        current->setText(QCoreApplication::translate("MainWindow", "Current Temperature", nullptr));
        converted->setText(QCoreApplication::translate("MainWindow", "Converted Temperature", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
