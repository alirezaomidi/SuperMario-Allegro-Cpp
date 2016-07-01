LIBS += -lallegro -lallegro_main -lallegro_dialog -lallegro_image -lallegro_audio -lallegro_acodec

QT += core
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    src/main.cpp \
    src/gamescreen.cpp \
    src/inputmanager.cpp \
    src/mario.cpp \
    src/gameobject.cpp \
    src/map.cpp \
    src/maploader.cpp \
    src/position.cpp \
    src/hill.cpp \
    src/bush.cpp \
    src/wall.cpp \
    src/block.cpp \
    src/cloud.cpp \
    src/castle.cpp \
    src/secretbox.cpp \
    src/pipe.cpp \
    src/rectangle.cpp \
    src/brick.cpp \
    src/enemy.cpp \
    src/turtle.cpp \
    src/owl.cpp \
    src/flag.cpp \
    src/soundmanager.cpp

HEADERS += \
    src/gamescreen.h \
    src/inputmanager.h \
    src/mario.h \
    src/gameobject.h \
    src/map.h \
    src/maploader.h \
    src/position.h \
    src/hill.h \
    src/bush.h \
    src/wall.h \
    src/block.h \
    src/cloud.h \
    src/castle.h \
    src/secretbox.h \
    src/pipe.h \
    src/rectangle.h \
    src/brick.h \
    src/enemy.h \
    src/turtle.h \
    src/owl.h \
    src/flag.h \
    src/soundmanager.h

CONFIG(release) {
    DESTDIR = build
    OBJECTS_DIR = build
}

RESOURCES +=
