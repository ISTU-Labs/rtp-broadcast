#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHash>
#include <QtNetwork>
#include <QHashIterator>
#include <QUdpSocket>
#include <QList>
#include <QString>
#include <mipconfig.h>
#include <mipavcodecencoder.h>
#include <mipaudiosession.h>
#include <mippainputoutput.h>
#include <iostream>
#include <jrtplib3/rtpipv4address.h>

MIPAudioSessionParams Aparams;
MIPAudioSession audioSess;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timerDelete = new QTimer(this);
    timerAlive =  new QTimer(this);
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
    connect(timerDelete, SIGNAL(timeout()), this, SLOT(DeleteUser()));
    connect(timerAlive, SIGNAL(timeout()), this, SLOT(sendAlive()));

    udpSocket->bind(BCAST_TEXT_PORT, QUdpSocket::ShareAddress);
    messageNo = 1;

#ifdef WIN32
    WSADATA dat;
    WSAStartup(MAKEWORD(2,2),&dat);
#endif // WIN32
}

MainWindow::~MainWindow()
{
    delete ui;
    #ifdef WIN32
        WSACleanup();
    #endif // WIN32
}
void MainWindow::on_MyButton_clicked()
{
    //connect
    startBroadcasting();
    timerDelete->start(100);
    timerAlive->start(1000);

}

void MainWindow::startBroadcasting()
{
    broadcastDatagram();
}

void MainWindow::sendAlive()
{
    QByteArray datagram = "EVMp_ALIVE_"+QByteArray::number(nick.size(),10);
    datagram.append("_" +nick);
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(BCAST_ADDRESS), BCAST_TEXT_PORT);
}

void MainWindow::broadcastDatagram()
{
    //ui->label1->setText(tr("Now broadcasting datagram %1").arg(messageNo));

    QByteArray datagram = "EVMp_CONNECT_"+QByteArray::number(ui->lineEdit->text().size(),10);
    //datagram.append(ui->lineEdit->text().size());
    datagram.append("_"+ui->lineEdit->text());
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(BCAST_ADDRESS), BCAST_TEXT_PORT);
    nick = ui->lineEdit_2->text();
    ui->label_3->setText(nick);
    ui->lineEdit_2->clear();
}

void MainWindow::processPendingDatagrams()
{

    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        QHostAddress sender;
        quint16 senderPort;

        QString string;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(),&sender, &senderPort);
        QByteArray processText = processIncomingText(datagram, sender); //Обработка входящего сообщения

        if(processText==""){
        } else if(processText.contains("msg")){
            datagram = datagram.mid(13,datagram.size()-1);
            qDebug()<<datagram;
            ui->listWidget_2->addItem(processText.mid(3));
            //ui->listWidget->clear();

            ///Обновление
            QHashIterator<QHostAddress,QTime> i(qHash);
            while(i.hasNext()){
                i.next();
                if(qNames.contains(i.key())){

                //ui->listWidget->addItem(qNames.value(i.key())+" "+deleteDots(i.key()));
                }
            }

        } else {
            if (localIP(sender))
            {
                qHash.insert(sender,QTime::currentTime());
                qNames.insert(sender, processText);
                //ui->listWidget->clear();

                ///Обновление
                QHashIterator<QHostAddress,QTime> i(qHash);
                while(i.hasNext())
                {
                    i.next();
                    if(qNames.contains(i.key())){
                       // ui->listWidget->addItem(qNames.value(i.key())+" "+deleteDots(i.key()));
                    }
                }
            }
        }

    }
}

QString MainWindow::deleteDots(QHostAddress string)
{
    QStringList stringList= string.toString().split(":");
    QString returnString = stringList.at(stringList.size()-1);
    return returnString;

}


void MainWindow::DeleteUser()
{
    /// уменьшние  счетчиков в хэше
    QHashIterator<QHostAddress,QTime> i(qHash);

    ///Запись данных
    while(i.hasNext()){
        i.next();
        QTime Ti=QTime::currentTime();

        if (i.value().secsTo(Ti)>10){
            qHash.remove(i.key());
            qNames.remove(i.key());
        }
    }

}


///определяет мой является ли моим ip
bool MainWindow::localIP(QHostAddress hostadress)
{

  QHostAddress addr = QHostAddress(deleteDots(hostadress));


  if (QNetworkInterface::allAddresses().contains(addr) || addr.isLoopback()) return false;

  return true;
}

void MainWindow::on_ButtonStop_clicked()
{
        timer->stop();
        timerAlive->stop();
        udpSocket->close();
        audioSess.destroy(); //остановили сессию
}

void MainWindow::on_sendButton_clicked()
{
    QByteArray datagram = "EVMp_SENDMSG_";
    datagram.append(ui->lineEdit->text());
    ui->listWidget_2->addItem(nick+":"+ui->lineEdit->text());
    ui->lineEdit->clear();
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(BCAST_ADDRESS), BCAST_TEXT_PORT);
}
QByteArray MainWindow ::processIncomingText(QByteArray datagram, QHostAddress sender)
{


    if (datagram.contains("EVMp_ALIVE_") || datagram.contains("EVMp_CONNECT_") )
    {
        if (datagram.contains("EVMp_ALIVE_")) {return datagram.mid(13);}
        if (datagram.contains("EVMp_CONNECT_")) {return datagram.mid(15);}

    }
    else if(datagram.contains("EVMp_SENDMSG_") && qNames.contains(sender)){
            qDebug() << datagram.mid(12);
              QByteArray ret = "msg";
              ret.append(qNames.value(sender));
              ret.append(":");
              ret.append(datagram.mid(12));
              return ret;
    }

    return "";

}

using namespace jrtplib;

void checkRet(bool ret,const MIPErrorBase &obj)
{
    if (!ret)
    {
        std::cerr << obj.getErrorString() << std::endl;
        exit(-1);
    }
}

class MyAudioSession : public MIPAudioSession
{
protected:
    void onInputThreadExit(bool err, const std::string &compName, const std::string &errStr)
    {
        if (err)
        {
            std::cerr << "Input chain thread exited due to an error" << std::endl;
            std::cerr << "Component: " << compName << std::endl;
            std::cerr << "Error: " << errStr << std::endl;
        }
    }
    void onOutputThreadExit(bool err, const std::string &compName, const std::string &errStr)
    {
        if (err)
        {
            std::cerr << "Output chain thread exited due to an error" << std::endl;
            std::cerr << "Component: " << compName << std::endl;
            std::cerr << "Error: " << errStr << std::endl;
        }
    }
};

void MainWindow::on_ButtonListen_clicked()
{

}

void MainWindow::on_sendButton_windowIconChanged(QIcon const&)
{

}

void MainWindow::on_CallButton_clicked()
{
#ifdef MIPCONFIG_SUPPORT_PORTAUDIO
    std::string errStr;

    if (!MIPPAInputOutput::initializePortAudio(errStr))
    {
        std::cerr << "Can't initialize PortAudio: " << errStr << std::endl;
        exit(-1);
    }
#endif // MIPCONFIG_SUPPORT_PORTAUDIO

    bool ret;

    int audioPort = BCAST_SND_PORT;

    // An object defining properties of the following audio session.

    Aparams.setPortbase(audioPort);
//Aparams.setCompressionType(MIPAudioSessionParams::Speex);
//Aparams.setAcceptOwnPackets(true);
//Aparams.setInputDevice("/dev/dsp1");
    //Aparams.setOutputDevice("/dev/dsp");
    //Aparams.setSpeexEncoding(MIPAudioSessionParams::UltraWideBand);
    //Aparams.setSpeexOutgoingPayloadType(97);
   // Aparams.setSpeexIncomingPayloadType(97);
   // Aparams.setOpusIncomingPayloadType(98);

    std::cout << "Starting audio session at portbase " << audioPort << std::endl;

    ret = audioSess.init(&Aparams);
    checkRet(ret, audioSess);
    //for(int i=0;i<arrayAdress.count();i++){
        //qDebug() <<arrayAdress.keys().at(i);
        //QStringList mass = arrayAdress.keys().at(i).split(".");
   // }

    uint8_t ipLocal[4] = { 172, 27, 24, 101 };

    ret = audioSess.addDestination(jrtplib::RTPIPv4Address(ipLocal, audioPort));

   //for (auto it : qHash) {
   //
   //}

    //std::string dummy;
    //std::cout << "Type something to exit" << std::endl;
    //std::cin >> dummy;

    std::cout << "Exiting..." << std::endl;

    //audioSess.destroy();

//#ifdef MIPCONFIG_SUPPORT_PORTAUDIO
    //MIPPAInputOutput::terminatePortAudio();
//#endif // MIPCONFIG_SUPPORT_PORTAUDIO
}
