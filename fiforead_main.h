#ifndef FIFOREAD_MAIN_H
#define FIFOREAD_MAIN_H

#include <QProcess>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#include <QDir>
#include <QDebug>
#include <QThread>
class FIFOReadMain : public QObject
{
    Q_OBJECT
    public:
        FIFOReadMain();
        QString getMessageM();
       // explicit FIFORead(QObject *parent = nullptr);

    public slots:
        void readSlotM();
        void loopSlotM();

    signals:
        void readSignalM();
        void readedM();

        void readWorkM();

    private:
        int counter ;
        QString getWrite;
};

#endif // FIFOREAD_MAIN_H

