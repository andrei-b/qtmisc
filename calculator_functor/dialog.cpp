#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"
#include <functional>

struct PressDigit
{
    Calculator * calc;
    int dig;
    PressDigit(Calculator * calculator, int digit) : calc(calculator), dig(digit)
    {
    }
    void operator()()
    {
        calc->digitButtonPressed(dig);
    }
};

struct PressOp
{
    Calculator * calc;
    int op;
    PressOp(Calculator * calculator, int operation) : calc(calculator), op(operation)
    {
    }
    void operator()()
    {
        calc->operationButtonPressed(op);
    }
};

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Calculator * calculator = new Calculator(this);
    connect(calculator, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)));
    connect(ui->pushButton, &QPushButton::clicked, this, PressDigit(calculator, 0));
    connect(ui->pushButton_2, &QPushButton::clicked, this, PressDigit(calculator, 1));
    connect(ui->pushButton_3, &QPushButton::clicked, this, PressDigit(calculator, 2));
    connect(ui->pushButton_4, &QPushButton::clicked, this, PressDigit(calculator, 3));
    connect(ui->pushButton_5, &QPushButton::clicked, this, PressDigit(calculator, 4));
    connect(ui->pushButton_6, &QPushButton::clicked, this, PressDigit(calculator, 5));
    connect(ui->pushButton_7, &QPushButton::clicked, this, PressDigit(calculator, 6));
    connect(ui->pushButton_8, &QPushButton::clicked, this, PressDigit(calculator, 7));
    connect(ui->pushButton_9, &QPushButton::clicked, this, PressDigit(calculator, 8));
    connect(ui->pushButton_10, &QPushButton::clicked, this, PressDigit(calculator, 9));
    connect(ui->pushButton_11, &QPushButton::clicked, this, PressOp(calculator, opPlus));
    connect(ui->pushButton_12, &QPushButton::clicked, this, PressOp(calculator, opMinus));
    connect(ui->pushButton_13, &QPushButton::clicked, this, PressOp(calculator, opEqual));
    connect(ui->pushButton_14, &QPushButton::clicked, this, PressOp(calculator, opCancel));
}

Dialog::~Dialog()
{
    delete ui;
}
