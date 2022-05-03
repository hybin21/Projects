/********************************************************************************
** Form generated from reading UI file 'newwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINDOW_H
#define UI_NEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_NewWindow
{
public:

    void setupUi(QDialog *NewWindow)
    {
        if (NewWindow->objectName().isEmpty())
            NewWindow->setObjectName(QString::fromUtf8("NewWindow"));
        NewWindow->resize(400, 300);

        retranslateUi(NewWindow);

        QMetaObject::connectSlotsByName(NewWindow);
    } // setupUi

    void retranslateUi(QDialog *NewWindow)
    {
        NewWindow->setWindowTitle(QCoreApplication::translate("NewWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewWindow: public Ui_NewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINDOW_H
