#ifndef ZSINGLETONHELPER_H
#define ZSINGLETONHELPER_H

#include <QObject>
#include "../../01src/sdk/includes/singleton.h"

class ZSingletonHelper : public QObject, public Singleton <ZSingletonHelper>
{
    Q_OBJECT
public:
    explicit ZSingletonHelper(QObject *parent = 0);

signals:

public slots:
};

#endif // ZSINGLETONHELPER_H
