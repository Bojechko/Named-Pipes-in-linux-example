#ifndef FIFOWRITE_TO_OTHER_H
#define FIFOWRITE_TO_OTHER_H

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
class FIFOWriteToOther : public QObject
{
    Q_OBJECT
    public:

        FIFOWriteToOther();
       // explicit FIFORead(QObject *parent = nullptr);
        void setChannelO(QString str);

    public slots:
        void writeSlotO();
        void setMessageO(QString);
        void loopSlotO();


    signals:
        void writeSignalO();
        void finished();

        void writeWorkO();

    private:

        QString toWrite;
        QString myfifo;

};

#endif // FIFOWRITE_TO_OTHER_H

