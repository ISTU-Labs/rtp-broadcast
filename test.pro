#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T10:51:45
#
#-------------------------------------------------

QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mypro
TEMPLATE = app

INCLUDEPATH += .
##########
#INCLUDEPATH += D:/myFile/lib/magistrant_test_4/jthread/include/
#INCLUDEPATH += D:/myFile/lib/magistrant_test_4/jrtplib/include
#INCLUDEPATH += /usr/include /usr/include/AL /usr/include/qt/ /usr/include/qt/QtGui /usr/include/qt/QtCore /usr/lib/qt//mkspecs/linux-g++ /usr/include/qt/QtWidgets /usr/include/qt/QtOpenGL /home/eugeneai/.local/include
INCLUDEPATH += /home/eugeneai/.local/include/emiplib
############

#######


#LIBS += -lasound    # зависит от используемого audio i/o
#LIBS += -laudiofile # зависит от используемого audio i/o
################
LIBS += -L/home/eugeneai/.local/lib64 -lemip -Wl,-rpath=/home/eugeneai/.local/lib64
LIBS += -ljthread -lpthread -ljrtp -ljthread -lpthread -lspeex -lspeexdsp -lopus -lasound -lportaudio -lopenal -lsndfile -lSDL -ljack -lavcodec -lavutil -lswscale -lpulse-simple
#-lemiplib
LIBS += -ljrtp
LIBS += -ljthread
#LIBS += -Wl, -LD:/myFile/lib/magistrant_test_4/jrtplib/lib -ljrtp
#LIBS += -Wl, -LD:/myFile/lib/magistrant_test_4/jthread/lib -ljthread
###############

##############
#подключить грустную библиотеку виндовую
#D:\myFile\mainwindow.cpp:38: ошибка: undefined reference to `_imp__WSAStartup@8'


#LIBS += -Wl, -lws2_32

#удалить moc файлы.
#проблему не решит.



#LIBS += -Wl,-Bstatic -lspeex -Wl,-Bdynamic
#LIBS += -Wl,-Bstatic -lspeexdsp -Wl,-Bdynamic
#uncomment if you want PortAudio
#LIBS += -Wl,-Bstatic -lportaudio -Wl,-Bdynamic





#INCLUDEPATH += .
#INCLUDEPATH += C:\Users\studentvt\Documents\magistrant_test_4\jthread\include
#INCLUDEPATH += C:\Users\studentvt\Documents\magistrant_test_4\jrtplib\include
#INCLUDEPATH += C:\Users\studentvt\Documents\magistrant_test_4\include\emiplib


#LIBS += -lasound    # зависит от используемого audio i/o
#LIBS += -laudiofile # зависит от используемого audio i/o
#LIBS += -LC:\Users\studentvt\Documents\magistrant_test_4\jrtplib\lib -ljrtp
#LIBS += -LC:\Users\studentvt\Documents\magistrant_test_4\jthread\lib -ljthread
#LIBS += -LC:\Users\studentvt\Documents\magistrant_test_4\lib -lemiplib
#LIBS += -lWs2_32
#LIBS += -Wl,-Bstatic -lspeex -Wl,-Bdynamic
#LIBS += -Wl,-Bstatic -lspeexdsp -Wl,-Bdynamic
#uncomment if you want PortAudio
#LIBS += -Wl,-Bstatic -lportaudio -Wl,-Bdynamic


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

DISTFILES +=

RESOURCES += \
    mail.qrc \
    emailsend256.qrc \
    emailsend256.qrc \
    emailsend256.qrc
