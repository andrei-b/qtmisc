#include "calculator.h"
#include <QWidget>


Calculator::Calculator(QObject *parent) :
    QObject(parent)
{
    operation = opNone;
    mode = InputMode;
    fgValue = 0;
    bgValue = 0;
	sign = 1;
    emit valueChanged(fgValue);
}

void Calculator::digitButtonPressed(int button)
{
    if (mode == CopyMode) {
        bgValue = fgValue;
        fgValue = 0;
        mode = InputMode;
    }
    fgValue = fgValue*10 + sign*((int) button);
    emit valueChanged(fgValue);
}

void Calculator::operationButtonPressed(int button)
{
    if ((button == opMinus)&&(mode == InputMode)&&(fgValue == 0)) {
        sign = -1;
    } else {
        sign = 1;
    }
    if ((button != opCancel)&&(button != opEqual)) {
        mode = CopyMode;
        operation = (int) button;
        return;
    }
    if (button == opEqual) {
        switch (operation) {
            case opPlus:
              fgValue += bgValue;
              break;
            case opMinus:
              fgValue = bgValue - fgValue;
            default:;
          }
          mode = CopyMode;
          bgValue = 0;
    }
    if (button == opCancel) {
        bgValue = fgValue = 0;
        operation = opNone;
        mode = InputMode;
    }
    emit valueChanged(fgValue);
}
