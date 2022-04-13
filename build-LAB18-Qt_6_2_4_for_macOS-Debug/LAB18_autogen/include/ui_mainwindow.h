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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(466, 383);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        INPUT_BOX = new QLineEdit(centralwidget);
        INPUT_BOX->setObjectName(QString::fromUtf8("INPUT_BOX"));
        INPUT_BOX->setGeometry(QRect(150, 50, 141, 41));
        OUTPUT_BOX = new QLineEdit(centralwidget);
        OUTPUT_BOX->setObjectName(QString::fromUtf8("OUTPUT_BOX"));
        OUTPUT_BOX->setGeometry(QRect(150, 240, 141, 41));
        SLIDER = new QSlider(centralwidget);
        SLIDER->setObjectName(QString::fromUtf8("SLIDER"));
        SLIDER->setGeometry(QRect(140, 190, 160, 25));
        SLIDER->setOrientation(Qt::Horizontal);
        F_BUTTON = new QPushButton(centralwidget);
        F_BUTTON->setObjectName(QString::fromUtf8("F_BUTTON"));
        F_BUTTON->setGeometry(QRect(150, 110, 61, 51));
        C_BUTTON = new QPushButton(centralwidget);
        C_BUTTON->setObjectName(QString::fromUtf8("C_BUTTON"));
        C_BUTTON->setGeometry(QRect(230, 110, 61, 51));
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
        F_BUTTON->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        C_BUTTON->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
