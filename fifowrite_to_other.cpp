#include "fifowrite_to_other.h"


FIFOWriteToOther::FIFOWriteToOther()
{
    connect(this, &FIFOWriteToOther::writeWorkO, this, &FIFOWriteToOther::loopSlotO);
}

void FIFOWriteToOther::loopSlotO(){

    qDebug("loop start write" );


    // FIFO file path

    char str[80] ;

    memcpy(str, toWrite.toStdString().c_str(), toWrite.size());

    int fr = open(this->myfifo.toLatin1().data(), O_WRONLY);
    qDebug("otkryl canal write");

    write(fr, str, strlen(str)+1);
    ::close(fr);
    qDebug("zakryl canal write");
    //sleep(100);


}

void FIFOWriteToOther::setMessageO(QString str){

    toWrite = str;
    qDebug()<<str;
    emit writeWorkO();

}

void FIFOWriteToOther::setChannelO(QString str){

    myfifo = str;
    qDebug() << myfifo << " setchannel";

}

void FIFOWriteToOther::writeSlotO()
{
    emit writeWorkO();
}
