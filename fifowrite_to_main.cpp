#include "fifowrite_to_main.h"
#include <QDebug>

FIFOWriteToMain::FIFOWriteToMain()
{

    connect(this, &FIFOWriteToMain::writeWorkM, this, &FIFOWriteToMain::loopSlotM);

}

void FIFOWriteToMain::loopSlotM(){
    int fd1;
    qDebug("loop start write" );

    // FIFO file path
    char * myfifo =  "./tmp/myfifoWrite";
    char str[toWrite.size()] ;

    memcpy(str, toWrite.toStdString().c_str(), toWrite.size());

    fd1 = open(myfifo,O_RDWR);
    qDebug("otkryl canal write");
    fgets(str, toWrite.size(), stdin);
    write(fd1, str, strlen(str)+1);
    ::close(fd1);
    qDebug("zakryl canal write");
    //sleep(100);
    emit finished();
}

void FIFOWriteToMain::setMessageM(QString str){
    toWrite = str;
    qDebug() << str << " setMessageM";

}


void FIFOWriteToMain::writeSlotM()
{
    counter = 0;

    emit writeWorkM();
}
