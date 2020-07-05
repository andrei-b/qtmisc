#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"
#include <functional>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Calculator * calculator = new Calculator(this);
    connect(calculator, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)));
    connect(ui->pushButton, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(0); });
    connect(ui->pushButton_2, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(1); });
    connect(ui->pushButton_3, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(2); });
    connect(ui->pushButton_4, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(3); });
    connect(ui->pushButton_5, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(4); });
    connect(ui->pushButton_6, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(5); });
    connect(ui->pushButton_7, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(6); });
    connect(ui->pushButton_8, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(7); });
    connect(ui->pushButton_9, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(8); });
    connect(ui->pushButton_10, &QPushButton::clicked, this,  [calculator]() {calculator->digitButtonPressed(9); });
    connect(ui->pushButton_11, &QPushButton::clicked, this,  [calculator]() {calculator->operationButtonPressed(opPlus); });
    connect(ui->pushButton_12, &QPushButton::clicked, this,  [calculator]() {calculator->operationButtonPressed(opMinus); });
    connect(ui->pushButton_13, &QPushButton::clicked, this,  [calculator]() {calculator->operationButtonPressed(opEqual); });
    connect(ui->pushButton_14, &QPushButton::clicked, this,  [calculator]() {calculator->operationButtonPressed(opCancel); });
}

Dialog::~Dialog()
{
    delete ui;
}
