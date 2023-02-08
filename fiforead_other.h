#ifndef FIFOREAD_OTHER_H
#define FIFOREAD_OTHER_H

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
class FIFOReadOther : public QObject
{
    Q_OBJECT
    public:
        FIFOReadOther();
        QString getMessageO();
       // explicit FIFORead(QObject *parent = nullptr);
        void setChannelO(QString str);

    public slots:
        void readSlotO();
        void loopSlotO();

    signals:
        void readSignalO();
        void readedO();

        void finished();


        void readWorkO();


    private:
        int counter ;
       //const char *myfifo;

        QString myfifo;
        QString getWrite;
};

#endif // FIFOREAD_MAIN_H

