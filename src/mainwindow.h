#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GraphWindow *window2;

private slots:
    void s21_digit_numbers();
    void s21_on_pushButton_TOCHKA_clicked();
    void s21_on_pushButton_EQUAL_clicked();
    void s21_operations();
    void s21_functions();
    void s21_on_pushButton_DELETE_clicked();
    void s21_on_pushButton_X_clicked();
};
#endif // MAINWINDOW_H
