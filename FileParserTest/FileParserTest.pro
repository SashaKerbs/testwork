TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    argumentparser.cpp \
    fileparser.cpp

HEADERS += \
    argumentparser.h \
    fileparser.h
