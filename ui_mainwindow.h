/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *sendButton;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QPushButton *ButtonStop;
    QPushButton *CallButton;
    QPushButton *MyButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1040, 570);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(920, 460, 111, 41));
        sendButton->setStyleSheet(QStringLiteral("color: rgb(255, 110, 14);"));
        QIcon icon;
        icon.addFile(QStringLiteral("emailsend256.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/prefix1/emailsend256.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/prefix1/emailsend256.png"), QSize(), QIcon::Selected, QIcon::Off);
        sendButton->setIcon(icon);
        sendButton->setIconSize(QSize(150, 130));
        sendButton->setFlat(false);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 121, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 60, 251, 16));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(72, 90, 171, 20));
        ButtonStop = new QPushButton(centralWidget);
        ButtonStop->setObjectName(QStringLiteral("ButtonStop"));
        ButtonStop->setGeometry(QRect(900, 10, 111, 23));
        CallButton = new QPushButton(centralWidget);
        CallButton->setObjectName(QStringLiteral("CallButton"));
        CallButton->setGeometry(QRect(30, 460, 81, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/phone.png"), QSize(), QIcon::Normal, QIcon::Off);
        CallButton->setIcon(icon1);
        CallButton->setIconSize(QSize(110, 90));
        MyButton = new QPushButton(centralWidget);
        MyButton->setObjectName(QStringLiteral("MyButton"));
        MyButton->setGeometry(QRect(250, 90, 111, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 130, 1001, 300));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        listWidget_2 = new QListWidget(layoutWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        verticalLayout->addWidget(listWidget_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 470, 171, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(630, 470, 281, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        sendButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        sendButton->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        sendButton->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217", nullptr));
        ButtonStop->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 ", nullptr));
        CallButton->setText(QString());
        MyButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\264\320\273\321\217 \320\263\320\276\320\273\320\276\321\201\320\276\320\262\320\276\320\263\320\276 \320\262\321\213\320\267\320\276\320\262\320\260", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\264\320\273\321\217 \321\202\320\276\320\263\320\276 \321\207\321\202\320\276 \320\261\321\213 \320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\262 \321\207\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
