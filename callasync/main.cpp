#include "task.h"
#include <QCoreApplication>
#include <QMetaObject>
#include <QThread>
#include <QTimer>
#include <QAbstractEventDispatcher>
#include <QMetaMethod>
#include <functional>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Task t;
    QTimer::singleShot(0, &t, &Task::run);
    return a.exec();
}
