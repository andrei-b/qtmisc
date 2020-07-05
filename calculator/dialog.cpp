#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"
#include <QSignalMapper>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSignalMapper * mapper = new QSignalMapper(0);
    connect(ui->pushButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton, digit0);
    connect(ui->pushButton_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_2, digit1);
    connect(ui->pushButton_3, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_3, digit2);
    connect(ui->pushButton_5, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_5, digit3);
    connect(ui->pushButton_4, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_4, digit4);
    connect(ui->pushButton_6, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_6, digit5);
    connect(ui->pushButton_8, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_8, digit6);
    connect(ui->pushButton_7, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_7, digit7);
    connect(ui->pushButton_9, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_9, digit8);
    connect(ui->pushButton_10, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton_10, digit9);

    Calculator * calculator = new Calculator(0);
    connect(mapper, SIGNAL(mapped(int)), calculator, SLOT(digitButtonPressed(int)));
    connect(calculator, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT(display(int)));

    QSignalMapper * mapper2 = new QSignalMapper(0);
    connect(ui->pushButton_11, SIGNAL(clicked()), mapper2, SLOT(map()));
    mapper2->setMapping(ui->pushButton_11, opPlus);
    connect(ui->pushButton_12, SIGNAL(clicked()), mapper2, SLOT(map()));
    mapper2->setMapping(ui->pushButton_12, opMinus);
    connect(ui->pushButton_13, SIGNAL(clicked()), mapper2, SLOT(map()));
    mapper2->setMapping(ui->pushButton_13, opEqual);
    connect(ui->pushButton_14, SIGNAL(clicked()), mapper2, SLOT(map()));
    mapper2->setMapping(ui->pushButton_14, opCancel);
    connect(mapper2, SIGNAL(mapped(int)), calculator, SLOT(operationButtonPressed(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
