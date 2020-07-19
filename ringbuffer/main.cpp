#include <iostream>
#include <QAtomicInt>
#include <QtConcurrent>
#include <QRandomGenerator>

class RingBuffer
{
public:
    RingBuffer(int size) : _size(size), _buffer(new int[size]), _writePtr(0), _readPtr(0), _readyElements(0)
    {
    }
    ~RingBuffer()
    {
        delete[] _buffer;
    }
    int count() // число непрочитанных элементов в буфере
    {
        return _readyElements;
    }
    bool add(int v)
    {
        if(_readyElements >= _size)
            return false;
        _buffer[_writePtr] = v;
        _writePtr = (_writePtr + 1)%_size;
        _readyElements++;
        return true;
    }
    bool take(int & v)
    {
        if (_readyElements == 0)
            return false;
        v = _buffer[_readPtr];
        _readPtr = (_readPtr+1)%_size;
        _readyElements--;
        return true;
    }
private:
    int _size;
    int * _buffer;
    int _writePtr;
    int _readPtr;
    QAtomicInt _readyElements;
};

RingBuffer rb(16);

void produce()
{
    QRandomGenerator rg(1234);
    for (int i = 0; i < 0xFFFFFF; i++) {
        //QThread::usleep(rg.bounded(100));
        while(!rb.add(i));
    }
}

void consume()
{
    int prev = -1;
    QRandomGenerator rg(321);
    for (int i = 0; i < 0xFFFFFF; i++) {
        //QThread::usleep(rg.bounded(80));
        int current;
        while(!rb.take(current));
        if (current - prev != 1) {
            std::cout << "ERROR" << std::endl;
            return;
        }
        prev = current;
        std::cout << current << std::endl;
    }
    std::cout << "SUCCESS" << std::endl;
}

int main(int argc, char *argv[])
{

    QtConcurrent::run(&produce);
    QtConcurrent::run(&consume);
}
