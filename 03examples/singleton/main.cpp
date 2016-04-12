#include <QCoreApplication>
#include <QDebug>

#include "zsingletonhelper.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ZSingletonHelper *helper = ZSingletonHelper::getInstancePtr();
    qDebug() << helper;

    ZSingletonHelper *helper2 = ZSingletonHelper::getInstancePtr();
    qDebug() << helper2;

    return a.exec();
}

