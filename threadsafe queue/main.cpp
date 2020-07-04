#include "threadsafequeue.h"
#include <QString>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>
#include <string>
#include <thread>
#include <iostream>

typedef ThreadSafeQueue<QString> TSQueue;

static TSQueue q;

void pushData()
{
    using namespace std::chrono_literals;
    for(int i = 0; i < 1024; i++) {
        QString msg = QString("message #%1").arg(i);
        q.push(msg);
        std::this_thread::sleep_for(1000ns);
    }
}

void popData()
{
    for(int i = 0; i < 1024; i++) {
        auto msg = *q.pop().get();
        std::cout << msg.toStdString() << std::endl;
    }
}

int main()
{
    std::thread t1(&pushData);
    std::thread t2(&popData);
    t1.join();
    t2.join();
}
