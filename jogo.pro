# -------------------------------------------------
# Project created by QtCreator 2009-11-09T21:38:00
# -------------------------------------------------
TARGET = jogo
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    Socket.cpp \
    Servidor.cpp \
    Chat.cpp
HEADERS += mainwindow.h \
    Socket.h \
    Servidor.h \
    Chat.h \
    ui_Chat.h
FORMS += mainwindow.ui \
    Chat.ui
QT += network
