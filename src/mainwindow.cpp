#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QString>
#include <QPixmap>
extern "C"{
#include "s21_smartcalc.h"
#include "s21_list.h"
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    window2 = new GraphWindow(this);
      connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(s21_digit_numbers()));
      connect(ui->pushButton_left, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_right, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(s21_operations()));
      connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(s21_functions()));
      connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(s21_on_pushButton_DELETE_clicked()));
      connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(s21_on_pushButton_X_clicked()));
      connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(s21_on_pushButton_TOCHKA_clicked()));
      connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(s21_on_pushButton_EQUAL_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::s21_digit_numbers()
{
    QPushButton *button = (QPushButton *)sender();

       QString new_label = ui->result_text->text() + button->text();


        ui->result_text->setText(new_label);
}

void MainWindow::s21_operations()
{
    QPushButton *button = (QPushButton *)sender();

    QString new_label;

    new_label = ui->result_text->text();

    if (button->text() == "÷" && !(ui->result_text->text().endsWith("÷")) && !(ui->result_text->text().endsWith("/"))) {
            new_label += "/";
    } else if (button->text() == "*" && !(ui->result_text->text().endsWith("*")) && !(ui->result_text->text().endsWith("*"))) {
        new_label += "*";
    } else if (button->text() == "+" && !(ui->result_text->text().endsWith("+"))) {
        new_label += "+";
    } else if (button->text() == "-" && !(ui->result_text->text().endsWith("-"))) {
        new_label += "-";
    } else if (button->text() == "^" && !(ui->result_text->text().endsWith("^"))) {
        new_label += "^";
    } else if (button->text() == "mod" && !(ui->result_text->text().endsWith("mod"))) {
        new_label += "mod";
    } else if (button->text() == "(") {
        new_label += "(";
    } else if (button->text() == ")") {
        new_label += ")";
    }

    ui->result_text->setText(new_label);
}
void MainWindow::s21_functions()
{
    QPushButton *button = (QPushButton *)sender();

    QString new_label;

    new_label = ui->result_text->text() + button->text() + "(";

    ui->result_text->setText(new_label);

}
void MainWindow::s21_on_pushButton_DELETE_clicked()
{
    ui->result_text->setText("");
}
void MainWindow::s21_on_pushButton_X_clicked()
{

    QString new_label;

    if (!(ui->result_text->text().endsWith("x")))
        new_label = ui->result_text->text() + "x";

    ui->result_text->setText(new_label);
}
void MainWindow::s21_on_pushButton_TOCHKA_clicked()
{
    if (!(ui->result_text->text().endsWith('.')))
        ui->result_text->setText(ui->result_text->text() + ".");
}


void MainWindow::s21_on_pushButton_EQUAL_clicked()
{
    char* str = new char(ui->result_text->text().length());
    QByteArray barr = ui->result_text->text().toLatin1();
    strlcpy(str, barr, ui->result_text->text().length() + 1);

    if (s21_validator(str) == 0) {
        ui->result_text->setText("Invalid Input");
    } else if (ui->result_text->text().contains("x")) {
        window2->on_to_draw_button_clicked(str);
        window2->show();
    } else {
     double result = s21_smart_calc(str, 0.0);

     QString numberResult = QString::number(result);
     ui->result_text->setText(numberResult);
    }
    delete(str);
}
