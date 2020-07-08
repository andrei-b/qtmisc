#ifndef CALLASYNC_H
#define CALLASYNC_H

#include <QThread>
#include <QMetaObject>
#include <QMetaMethod>
#include <QAbstractEventDispatcher>
#include <functional>

using Func1 = std::function<void()>;

void CallAtThread(QThread * thread, Func1 f);
void CallLater(Func1 f);

template <typename Func>
void PostToThread(QThread * thread, typename QtPrivate::FunctionPointer<Func>::Object *obj, Func slot)
{
    if (obj->thread() != thread)
        obj->moveToThread(thread);
    QMetaObject::invokeMethod(obj, slot, Qt::QueuedConnection, nullptr);
}
#endif // CALLASYNC_H
