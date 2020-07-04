#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include "xwaitcondition.h"
#include <QMutex>
#include <QQueue>
#include <QMutexLocker>
#include <QSharedPointer>


template<typename T>
class ThreadSafeQueue
{
private:
    mutable QMutex m_mutex;
    QQueue<T> m_queue;
    XWaitCondition m_cond;
public:
    ThreadSafeQueue()
    {
    }

    ThreadSafeQueue(ThreadSafeQueue const& other)
    {
        QMutexLocker lk(&other.m_mutex);
        m_queue=other.m_queue;
    }

    void push(T value)
    {
        QMutexLocker lk(&m_mutex);
        m_queue.push_front(value);
        m_cond.notify_one();
    }

    void pop(T& value)
    {
        QMutexLocker lk(&m_mutex);
        m_cond.wait(lk,[this]{return !m_queue.empty();});
        value=m_queue.front();
        m_queue.pop_front();
    }

    QSharedPointer<T> pop()
    {
        QMutexLocker lk(&m_mutex);
        m_cond.wait(&m_mutex,[this]()->bool{return !m_queue.empty();});
        QSharedPointer<T> res(new T(m_queue.front()));
        m_queue.pop_front();
        return res;
    }

    bool tryPop(T& value)
    {
        QMutexLocker lk(&m_mutex);
        if(m_queue.empty)
            return false;
        value=m_queue.front();
        m_queue.pop();
        return true;
    }

    QSharedPointer<T> tryPop()
    {
        QMutexLocker lk(&m_mutex);
        if(m_queue.empty())
            return std::shared_ptr<T>();
        QSharedPointer<T> res(new T(m_queue.front()));
        m_queue.pop();
        return res;
    }

    bool empty() const
    {
        QMutexLocker lk(&m_mutex);
        return m_queue.empty();
    }
};


#endif // THREADSAFEQUEUE_H
