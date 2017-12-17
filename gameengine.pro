TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test/main.cpp \
    src/point.cpp \
    src/vector.cpp

SUBDIRS += \
    gameengine.pro

DISTFILES += \
    build/gameengine

HEADERS += \
    include/point.h \
    include/vector.h
