#include "fiforead_other.h"

FIFOReadOther::FIFOReadOther()
{
  //  connect(this, &FIFORead::readWork, this, &FIFORead::readSlot);
    connect(this, &FIFOReadOther::readWorkO, this, &FIFOReadOther::loopSlotO);

}

void FIFOReadOther::loopSlotO(){
    qDebug("loop start read" );

    char arr1[80];

    int fr = open(this->myfifo.toLatin1().data(), O_RDONLY);

    qDebug("otkryl canal read");

    read(fr, arr1, sizeof(arr1));

    printf("User2: %s\n", arr1);
    QByteArray answer;
    /*for(int i = 0; i<arr1->length(); i++){
        answer.append(arr1[i]);
    }*/

    getWrite = arr1;
    ::close(fr);
    qDebug("Zakryl read");


    emit finished();
    emit readWorkO();
}

QString FIFOReadOther::getMessageO(){
    qDebug() << getWrite;
    return getWrite;
}

void FIFOReadOther::setChannelO(QString str){

    myfifo = str;
}

void FIFOReadOther::readSlotO()
{
    qDebug() << myfifo<< " setchannel 3";

    emit readWorkO();

}
