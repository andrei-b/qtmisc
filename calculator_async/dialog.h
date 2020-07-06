#ifndef DIALOG_H
#define DIALOG_H

#include "calculator.h"
#include <QDialog>
#include <QThread>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
   void digitButtonClicked(Buttons button);
   void operationButtonClicked(Buttons button);
private:
    Ui::Dialog *ui;
    QThread * calcThread;
};

#endif // DIALOG_H
