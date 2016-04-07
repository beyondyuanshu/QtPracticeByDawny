#ifndef QTUTIL_H
#define QTUTIL_H

#include <QObject>

class QtUtil : public QObject
{
    Q_OBJECT
public:
    explicit QtUtil(QObject *parent = 0);

    static bool rmRecursively(const QString &dirPath);
    static bool copyRecursively(const QString &srcFilePath, const QString &tgtFilePath);
    static bool iterateDir(const QString &dirPath);

signals:

public slots:
};

#endif // QTUTIL_H
