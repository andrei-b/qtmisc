#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);
public slots:
    void f1();
signals:
private:
    int i;
};

#endif // MYOBJECT_H
