#include "qtutil.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QProcess>
#include <QApplication>
#include <QCryptographicHash>
#include <QDebug>

QtUtil::QtUtil(QObject *parent) : QObject(parent)
{

}

bool QtUtil::rmRecursively(const QString &dirPath) {
    QProcess process;
#ifdef _WIN32
    QStringList args;
    args << "/c" << "rd" << "/s" << "/q" << dirPath;
    process.start("cmd", args);
    process.waitForFinished();
#else
    process.start(QString("rm -rf %1").arg(dirPath));
    process.waitForFinished();
#endif

    QDir dir(dirPath);
    return !dir.exists();
    //    QDir dir(dirPath);
    //    if (!dir.exists())
    //        return true;
    //    foreach(const QFileInfo &info, dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
    //        if (info.isDir()) {
    //            if (!rmRecursively(info.filePath()))
    //                return false;
    //        } else {
    //            if (!QFile::remove(info.absoluteFilePath())) {
    //                qDebug() << "xx" << info.absoluteFilePath();
    //                return false;
    //            }
    //        }
    //    }
    //    QDir parentDir(QFileInfo(dirPath).path());
    //    return parentDir.rmdir(QFileInfo(dirPath).fileName());
}

bool QtUtil::copyRecursively(const QString &srcFilePath, const QString &tgtFilePath)
{
    QFileInfo srcFileInfo(srcFilePath);
    if (srcFileInfo.isDir()) {
        QDir targetDir(tgtFilePath);
        targetDir.cdUp();
        if (!targetDir.mkpath(QFileInfo(tgtFilePath).filePath())) {
            qDebug() << "mkdir error" << QFileInfo(tgtFilePath).filePath();
            return false;
        }
        QDir sourceDir(srcFilePath);
        QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
        foreach (const QString &fileName, fileNames) {
            const QString newSrcFilePath
                    = srcFilePath + QLatin1Char('/') + fileName;
            const QString newTgtFilePath
                    = tgtFilePath + QLatin1Char('/') + fileName;
            if (!copyRecursively(newSrcFilePath, newTgtFilePath))
                return false;
        }
    } else {
        QFile file;
        if (!file.copy(srcFilePath, tgtFilePath)) {
            qDebug() << "copy file error:" << srcFilePath << tgtFilePath << file.errorString();
            return false;
        }
    }
    return true;
}

bool QtUtil::iterateDir(const QString &dirPath)
{
    do {
        QDir dir(dirPath);
        if (!dir.exists()) {
            break;
        }

        QMap<QString, QString> map;
        QDirIterator iter(dirPath,
                          QStringList() << ".svn",
                          QDir::Dirs | QDir::Hidden, QDirIterator::Subdirectories);
        while (iter.hasNext()) {
            iter.next();
            map.insert(iter.filePath(), QCryptographicHash::hash(iter.filePath().toUtf8(), QCryptographicHash::Md5).toHex().toUpper());
        }

        QMap<QString, QString>::const_iterator i = map.constBegin();
        while (i != map.constEnd()) {
            qDebug() << i.key() << ": " << i.value() << endl;
            bool result = copyRecursively(i.key(), QString("%1/PackerTmp/%2").arg(qApp->applicationDirPath()).arg(i.value()));
            if (!result) {
                break;
            }
            qDebug() << result;
            ++i;
        }
    } while (0);

    //    foreach (const QString &filePath, fullFilePathList) {
    //        QString destFilename = QString(filePath).remove("/");
    //        bool result = copyRecursively(filePath, QString("%1/%2").arg(qApp->applicationDirPath()).arg(destFilename));
    //        qDebug() << destFilename << result << endl;
    //    }

    return true;
}
