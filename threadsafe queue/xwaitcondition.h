#ifndef XWAITCONDITION_H
#define XWAITCONDITION_H

#include <QWaitCondition>
#include <functional>

using Func = std::function<bool()>;

class XWaitCondition : public QWaitCondition
{
public:
    XWaitCondition();
    bool wait(QMutex *lockedMutex, Func f);
    bool wait(QMutex *lockedMutex, QDeadlineTimer deadline);
    bool wait(QMutex *lockedMutex, unsigned long time);
    bool wait(QReadWriteLock *lockedReadWriteLock, QDeadlineTimer deadline);
    bool wait(QReadWriteLock *lockedReadWriteLock, unsigned long time);
};

#endif // XWAITCONDITION_H
