#include "mainwindow.h"
#include "./ui_mainwindow.h"
QString TEMP;
double INPUT;
bool clicked_F;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_INPUT_BOX_textChanged(const QString &arg1)
{
    TEMP = arg1;
    INPUT = TEMP.toDouble();
    TEMP = QString::number(INPUT);
}


void MainWindow::on_F_BUTTON_clicked()
{
     INPUT =(INPUT-32)*.5556;
     TEMP = QString::number(INPUT);
     ui->OUTPUT_BOX->setText(TEMP);
     ui->SLIDER->setRange(-328,392);
     clicked_F = true;
}


void MainWindow::on_C_BUTTON_clicked()
{
    INPUT = (INPUT * 1.8) + 32;
    TEMP = QString::number(INPUT);
    ui->OUTPUT_BOX->setText(TEMP);
    ui->SLIDER->setRange(-200,200);
    clicked_F = false;
}

void MainWindow::on_SLIDER_valueChanged(int value)
{
    INPUT = value;
    QString input = QString::number(INPUT);
    ui->INPUT_BOX->textChanged(input);
    ui->INPUT_BOX->setText(input);
    if(clicked_F)
    {
        INPUT =(INPUT-32)*.5556;
        TEMP = QString::number(INPUT);
        ui->OUTPUT_BOX->setText(TEMP);
    }
    else
    {
        INPUT = (INPUT * 1.8) + 32;
        TEMP = QString::number(INPUT);
        ui->OUTPUT_BOX->setText(TEMP);
    }
}


