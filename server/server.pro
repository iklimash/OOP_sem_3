QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += ../common

SOURCES += \
    application.cpp \
    array.cpp \
    complex.cpp \
    main.cpp \
    interface.cpp \
    polinom.cpp \
    ../common/communicator.cpp \
    ../common/common.cpp

HEADERS += \
    application.h \
    array.h \
    complex.h \
    interface.h \
    number.h \
    polinom.h \
    ../common/communicator.h \
    ../common/common.h

