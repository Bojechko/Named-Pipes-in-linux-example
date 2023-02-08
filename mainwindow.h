#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#include <fiforead_other.h>
#include <fifowrite_to_other.h>
#include <QCommandLineParser>

#include <QDir>
#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
 //   void sendMessageM(QString);

    void sendMessageO(QString);


public:
    MainWindow(QString rd, QString wt, QWidget *parent = nullptr);



    ~MainWindow();

public slots:
    void getReadedO();

private slots:



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();



private:

    FIFOReadOther *fifoReadOther ;
    FIFOWriteToOther *fifoWriteOther;

    QThread *read_threadOther = new QThread;
    QThread *write_threadOther = new QThread;


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
