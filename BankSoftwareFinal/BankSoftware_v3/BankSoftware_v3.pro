TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    bankaccount.cpp \
    checkingaccount.cpp \
    savingsaccount.cpp \
    user.cpp \
    login.cpp

HEADERS += \
    window.h \
    bankaccount.h \
    checkingaccount.h \
    savingsaccount.h \
    user.h \
    login.h
