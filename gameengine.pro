TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lSDL2

SOURCES += main.cpp \
    src/point.cpp \
    src/vector.cpp \
    test/test.cpp \
    src/camera.cpp \
    src/renderer.cpp

SUBDIRS += \
    gameengine.pro

DISTFILES += \
    build/gameengine

HEADERS += \
    include/point.h \
    include/vector.h \
    include/camera.h \
    include/renderer.h
