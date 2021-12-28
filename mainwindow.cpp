#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->plusMinus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->point, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->division, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->multiplication, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->plus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->division ->setCheckable(true);
    ui->multiplication ->setCheckable(true);
    ui->plus ->setCheckable(true);
    ui->minus ->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    QPushButton *button = (QPushButton*)sender();
    double all_numbers;
    QString new_label;

    if (ui->resultShow->text().contains(".") && button->text() == "0") {
        new_label = ui->resultShow->text() + button->text();
    }
    else {
        all_numbers = (ui->resultShow->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->resultShow->setText(new_label);
}


void MainWindow::on_point_clicked()
{
    if (!(ui->resultShow->text().contains('.'))) {
    ui->resultShow->setText(ui->resultShow->text() + ".");
    }
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton*)sender();
    double all_numbers;
    QString new_label;

    if (button->text() == "+/-") {
        all_numbers = (ui->resultShow->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->resultShow->setText(new_label);
    }
    else if (button->text() == "%") {
        all_numbers = (ui->resultShow->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->resultShow->setText(new_label);
    }
}

void MainWindow::math_operations(){
    QPushButton *button = (QPushButton*)sender();
    num_first = ui->resultShow->text().toDouble();
    ui->resultShow->setText("");
    button->setChecked(true);
}

void MainWindow::on_clear_clicked()
{
    ui->plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->multiplication->setChecked(false);
    ui->division->setChecked(false);

    ui->resultShow->setText("0");
}


void MainWindow::on_equal_clicked()
{

    double labelNumber, num_second;
    QString new_label;

    num_second = ui->resultShow->text().toDouble();

    if (ui->plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->resultShow->setText(new_label);
        ui->plus->setChecked(false);
    }
    else if (ui->minus->isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->resultShow->setText(new_label);
        ui->minus->setChecked(false);
    }
    else if (ui->division->isChecked()) {
        if (num_second == 0) {
            ui->resultShow->setText("0");
        }
        else {
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->resultShow->setText(new_label);
        ui->division->setChecked(false);
        }
    }
    else if (ui->multiplication->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->resultShow->setText(new_label);
        ui->multiplication->setChecked(false);
        }

}


