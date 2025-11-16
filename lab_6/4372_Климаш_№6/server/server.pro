QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += ../common

SOURCES += \
    application.cpp \
    complex.cpp \
    main.cpp \
    ../common/communicator.cpp \
    ../common/common.cpp

HEADERS += \
    application.h \
    array.h \
    complex.h \
    polinom.h \
    ../common/communicator.h \
    ../common/common.h

