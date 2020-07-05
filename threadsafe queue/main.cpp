#include "threadsafequeue.h"
#include <QString>
#include <QtConcurrent>
#include <string>
#include <thread>
#include <iostream>

typedef ThreadSafeQueue<QString> TSQueue;

static TSQueue q;

void pushData(int n)
{
    using namespace std::chrono_literals;
    for(int i = 0; i < 1024; i++) {
        QString msg = QString("%1: message #%2").arg(n).arg(i);
        q.push(msg);
        std::this_thread::sleep_for(1000ns);
    }
}

void popData()
{
    for(int i = 0; i < 2048; i++) {
        std::cout << q.pop()->toStdString() << std::endl;
    }
}


int main()
{
    QtConcurrent::run(&pushData, 1);
    QtConcurrent::run(&pushData, 2);
    QtConcurrent::run(&popData);
}

/*int main()
{
    std::thread t1(&pushData);
    std::thread t2(&popData);
    std::thread t3(&pushData);
    t1.join();
    t2.join();
    t3.join();
}*/
