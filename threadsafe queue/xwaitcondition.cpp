#include "xwaitcondition.h"
#include <QDeadlineTimer>

XWaitCondition::XWaitCondition() : QWaitCondition()
{

}

bool XWaitCondition::wait(QMutex *lockedMutex, Func f)
{
    while (!f()) {
        wait(lockedMutex, QDeadlineTimer::Forever);
    }
    return true;
}

bool XWaitCondition::wait(QMutex *lockedMutex, QDeadlineTimer deadline)
{
    return QWaitCondition::wait(lockedMutex, deadline);
}

bool XWaitCondition::wait(QMutex *lockedMutex, unsigned long time)
{
    return QWaitCondition::wait(lockedMutex, time);
}

bool XWaitCondition::wait(QReadWriteLock *lockedReadWriteLock, QDeadlineTimer deadline)
{
    return QWaitCondition::wait(lockedReadWriteLock, deadline);
}

bool XWaitCondition::wait(QReadWriteLock *lockedReadWriteLock, unsigned long time)
{
    return QWaitCondition::wait(lockedReadWriteLock, time);
}
