#include <QCoreApplication>

#include <QSystemSemaphore>
#include <QSharedMemory>

#include <QDebug>

#include "kdrunoncechecker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Method 1
    KDRunOnceChecker runCheck(qApp->applicationDirPath() + QLatin1String("/lockmyApp1234865.lock"));
    if (runCheck.isRunning(KDRunOnceChecker::ConditionFlag::Lockfile)) {
        // It is possible to install an application and thus the maintenance tool into a
        // directory that requires elevated permission to create a lock file. Since this
        // cannot be done without requesting credentials from the user, we silently ignore
        // the fact that we could not create the lock file and check the running processes.
        if (runCheck.isRunning(KDRunOnceChecker::ConditionFlag::ProcessList)) {
            //            QInstaller::MessageBoxHandler::information(0, QLatin1String("AlreadyRunning"),
            //                                                       QString::fromLatin1("Waiting for %1").arg(qAppName()),
            //                                                       QString::fromLatin1("Another %1 instance is already running. Wait "
            //                                                                           "until it finishes, close it, or restart your system.").arg(qAppName()));
        }
        qDebug() << QString::fromLatin1("Another %1 instance is already running. Wait "
                                        "until it finishes, close it, or restart your system.").arg(qAppName());
        return EXIT_FAILURE;
    }

    // Method 2
    QSystemSemaphore sema("SEMEPHORE_RUNONCE", 1, QSystemSemaphore::Open);
    sema.acquire();
    QSharedMemory mem("RunonceSingleProcessHandler");
    if (!mem.create(1)) {
        qDebug() << QString::fromLatin1("Another %1 instance is already running. Wait "
                                        "until it finishes, close it, or restart your system.").arg(qAppName());

        sema.release();
        return 0;
    }
    sema.release();

    // Method 3

    return a.exec();
}

