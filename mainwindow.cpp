#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QString rd, QString wt, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fifoReadOther = new FIFOReadOther();
    fifoWriteOther = new FIFOWriteToOther();

    fifoWriteOther->setChannelO(wt);
    fifoReadOther->setChannelO(rd);


    QString str = "";
    str.append("читатает из ");
    str.append(rd);
    ui->label_2->setText(str);
    str = "";
    str.append("пишет в ");
    str.append(wt);
    ui->label_3->setText(str);
    on_pushButton_4_clicked();//read при инициализации

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

    QString str =ui->lineEdit->text();

    fifoWriteOther->setMessageO(str);

    fifoWriteOther->moveToThread(write_threadOther);

    connect(write_threadOther, SIGNAL(started()), fifoWriteOther, SLOT(writeSlotO()));
    connect(fifoReadOther, SIGNAL(finished()), read_threadOther, SLOT(terminate()));


    write_threadOther->start();

}


void MainWindow::on_pushButton_3_clicked()
{
    QProcess process;

    process.startDetached( QApplication::applicationDirPath() + "/FIFOTest", QStringList()
                           << "-w" << "./tmp/myfifoSon"
                           << "-r" << "./tmp/myfifoFather");

    //Если просто start, то займет родительский процесс
    //process.start( QApplication::applicationDirPath() + "/sao-mp/program", QStringList() << "");
    if( !process.waitForStarted() || !process.waitForFinished() ) {
        return;
    }
}




void MainWindow::on_pushButton_4_clicked()
{
        fifoReadOther->moveToThread(read_threadOther);
        connect(read_threadOther, SIGNAL(started()), fifoReadOther, SLOT(readSlotO()));
           connect(fifoReadOther, SIGNAL(finished()), this, SLOT(getReadedO()));

        read_threadOther->start();

}


void MainWindow::getReadedO()
{

    ui->label_output->setText(fifoReadOther->getMessageO());

}




void MainWindow::on_pushButton_6_clicked()
{
    if (!QDir("tmp").exists()){
        QDir().mkdir(/*QApplication::applicationDirPath() + */"./tmp");
    }

    mkfifo("./tmp/myfifoFather", S_IFIFO | 0666);
    mkfifo("./tmp/myfifoSon", S_IFIFO | 0666);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->label_output->setText(ui->lineEdit->text());
}



