#include "myobject.h"
#include "callasync.h"
#include <iostream>

MyObject::MyObject(QObject *parent) : QObject(parent), i(4)
{

}

void f2 ()
{
        std::cout << "f2 called" << std::endl;
}

void MyObject::f1()
{
    CallLater(&f2);
    std::cout << i << std::endl;
    std::cout << "f1 called" << std::endl;
}
