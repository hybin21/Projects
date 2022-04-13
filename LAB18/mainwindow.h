#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_INPUT_BOX_textChanged(const QString &arg1);

    void on_F_BUTTON_clicked();

    void on_C_BUTTON_clicked();

    void on_SLIDER_valueChanged(int value);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
