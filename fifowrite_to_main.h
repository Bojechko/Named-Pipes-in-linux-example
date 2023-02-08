#ifndef FIFOWRITE_TO_MAIN_H
#define FIFOWRITE_TO_MAIN_H

//#include "mainwindow.h"

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


class FIFOWriteToMain : public QObject
{
    Q_OBJECT
    public:
        FIFOWriteToMain();
       // explicit FIFORead(QObject *parent = nullptr);

    public slots:
        void writeSlotM();
//        void getMessageM(QString);
        void setMessageM(QString);
        void loopSlotM();

    signals:
        void writeSignalM();

        void writeWorkM();
        void finished();

    private:
        QString toWrite;
        int counter ;
      //  void readUpdate();
};

#endif // FIFOWRITE_TO_OTHER_H

