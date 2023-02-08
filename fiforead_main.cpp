#include "fiforead_main.h"

FIFOReadMain::FIFOReadMain()
{
  //  connect(this, &FIFORead::readWork, this, &FIFORead::readSlot);
    connect(this, &FIFOReadMain::readWorkM, this, &FIFOReadMain::loopSlotM);

}

void FIFOReadMain::loopSlotM(){
    qDebug("loop start read" );

    QByteArray arr1[80];
    for(int i = 0; i < 80; i++){
        arr1[i] = 0;
    }
    const char *path = "./tmp/myfifoWrite";
    int fr = open(path, O_RDONLY);
    qDebug("otkryl canal read");

    read(fr, arr1, sizeof(arr1));
    qDebug() << arr1 << " read arr1";

    printf("User2: %s\n", arr1);
    QByteArray answer;
    for(int i = 0; i < arr1->length(); i++){
        answer.append(arr1[i]);
    }

    getWrite = answer;
    qDebug() << getWrite << " read";
    ::close(fr);
    qDebug("Zakryl read");

    emit readedM();

    emit readWorkM();
}

QString FIFOReadMain::getMessageM(){
    qDebug() << getWrite << " setMessageM";
    return getWrite;
}

void FIFOReadMain::readSlotM()
{

    emit readWorkM();

}
