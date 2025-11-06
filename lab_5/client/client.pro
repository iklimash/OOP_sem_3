QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    application.cpp \
    main.cpp \
    interface.cpp \
    ../common/communicator.cpp \
    ../common/common.cpp


HEADERS += \
    application.h \
    interface.h \
    ../common/communicator.h \
    ../common/common.h


