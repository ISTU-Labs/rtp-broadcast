#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QHash>
#include <QtNetwork>
#include <QUdpSocket>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void startBroadcasting();
    void broadcastDatagram();
    void processPendingDatagrams();

    void on_MyButton_clicked();
    void on_ButtonListen_clicked();
    void sendAlive();

    void DeleteUser();

    void on_ButtonStop_clicked();

    void on_sendButton_clicked();

    //void on_sendButton_windowIconChanged(const QIcon &icon);
    void on_sendButton_windowIconChanged(QIcon const&);

    void on_CallButton_clicked();

public:
    QString deleteDots(QHostAddress hostadress);
    //bool findSuchAdress(QString string);
    bool localIP(QHostAddress hostadress);
    QString nick;
    QByteArray processIncomingText(QByteArray datagram,QHostAddress sender);
    QHash<QHostAddress, QString> qNames;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QHash<QHostAddress,QTime> qHash;
    QUdpSocket *udpSocket;
    QUdpSocket *udpSocket1;
    QTimer *timer;
    QTimer *timerDelete;
    QTimer *timerAlive;

    int messageNo;
    QList<QString> list;
    int indicator;
};

#endif // MAINWINDOW_H
