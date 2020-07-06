#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"
#include <functional>
#include <QThread>

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
    calcThread = new QThread(this);
    calcThread->start();
    Calculator * calculator = new Calculator(0);
    calculator->moveToThread(calcThread);
    connect(calculator, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)), Qt::QueuedConnection);
    connect(ui->pushButton, &QPushButton::clicked, calculator, PressDigit(calculator, 0), Qt::QueuedConnection);
    connect(ui->pushButton_2, &QPushButton::clicked, calculator, PressDigit(calculator, 1), Qt::QueuedConnection);
    connect(ui->pushButton_3, &QPushButton::clicked, calculator, PressDigit(calculator, 2), Qt::QueuedConnection);
    connect(ui->pushButton_4, &QPushButton::clicked, calculator, PressDigit(calculator, 3), Qt::QueuedConnection);
    connect(ui->pushButton_5, &QPushButton::clicked, calculator, PressDigit(calculator, 4), Qt::QueuedConnection);
    connect(ui->pushButton_6, &QPushButton::clicked, calculator, PressDigit(calculator, 5), Qt::QueuedConnection);
    connect(ui->pushButton_7, &QPushButton::clicked, calculator, PressDigit(calculator, 6), Qt::QueuedConnection);
    connect(ui->pushButton_8, &QPushButton::clicked, calculator, PressDigit(calculator, 7), Qt::QueuedConnection);
    connect(ui->pushButton_9, &QPushButton::clicked, calculator, PressDigit(calculator, 8), Qt::QueuedConnection);
    connect(ui->pushButton_10, &QPushButton::clicked, calculator, PressDigit(calculator, 9), Qt::QueuedConnection);
    connect(ui->pushButton_11, &QPushButton::clicked, calculator, PressOp(calculator, opPlus), Qt::QueuedConnection);
    connect(ui->pushButton_12, &QPushButton::clicked, calculator, PressOp(calculator, opMinus), Qt::QueuedConnection);
    connect(ui->pushButton_13, &QPushButton::clicked, calculator, PressOp(calculator, opEqual), Qt::QueuedConnection);
    connect(ui->pushButton_14, &QPushButton::clicked, calculator, PressOp(calculator, opCancel), Qt::QueuedConnection);
}

Dialog::~Dialog()
{
    calcThread->quit();
    calcThread->wait();
    delete ui;
}
