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
    src/renderer.cpp \
    src/linesegment.cpp \
    src/drawobject.cpp \
    src/circle.cpp \
    src/triangle.cpp \
    src/quad.cpp \
    src/polygon.cpp \
    src/lighting.cpp

SUBDIRS += \
    gameengine.pro

DISTFILES += \
    build/gameengine

HEADERS += \
    include/point.h \
    include/vector.h \
    include/camera.h \
    include/renderer.h \
    include/linesegment.h \
    include/drawobject.h \
    include/circle.h \
    include/triangle.h \
    include/quad.h \
    include/polygon.h \
    include/lighting.h
