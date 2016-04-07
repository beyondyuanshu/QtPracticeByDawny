#ifndef ZDMHTTPTEST_H
#define ZDMHTTPTEST_H

#include <QObject>

class ZDMHttpTest : public QObject
{
    Q_OBJECT
public:
    explicit ZDMHttpTest(QObject *parent = 0);

    static void getTest();
    static void postTest();

signals:

public slots:
};

#endif // ZDMHTTPTEST_H
