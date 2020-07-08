#include "callasync.h"

void CallAtThread(QThread * thread, Func1 f)
{
    QMetaObject::invokeMethod(QAbstractEventDispatcher::instance(thread), f, Qt::QueuedConnection);
}

void CallLater(Func1 f)
{
    CallAtThread(QThread::currentThread(), f);
}


