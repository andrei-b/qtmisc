#include "task.h"
#include "callasync.h"
#include "myobject.h"
#include <QThread>
#include <QCoreApplication>


Task::Task(QObject *parent) : QObject(parent)
{
}

void Task::run()
{
    QThread t;
    t.start();
    MyObject m;
    PostToThread(&t, &m, &MyObject::f1);
    QThread::sleep(1);
    t.quit();
    t.wait();
    QCoreApplication::exit(0);
}
