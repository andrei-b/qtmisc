#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

enum Buttons {
    digit0 = 0,
    digit1,
    digit2,
    digit3,
    digit4,
    digit5,
    digit6,
    digit7,
    digit8,
    digit9,
    opPlus,
    opMinus,
    opCancel,
    opEqual,
    opNone
};

enum Modes {
    InputMode,
    CopyMode
};


class QWidget;
class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = 0);
signals:
    void valueChanged(int value);
public slots:
    void digitButtonPressed(int button);
    void operationButtonPressed(int button);
private:
    int operation;
    Modes mode;
    int bgValue, fgValue, sign;
};

#endif // CALCULATOR_H
