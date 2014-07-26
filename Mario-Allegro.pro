LIBS += -lallegro -lallegro_main -lallegro_dialog -lallegro_image -lallegro_audio -lallegro_acodec

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    gamescreen.cpp \
    inputmanager.cpp \
    mario.cpp \
    gameobject.cpp \
    map.cpp \
    maploader.cpp \
    position.cpp \
    hill.cpp \
    bush.cpp \
    wall.cpp \
    block.cpp \
    cloud.cpp \
    castle.cpp \
    secretbox.cpp \
    pipe.cpp \
    rectangle.cpp \
    brick.cpp \
    enemy.cpp \
    turtle.cpp \
    owl.cpp \
    flag.cpp \
    soundmanager.cpp

HEADERS += \
    gamescreen.h \
    inputmanager.h \
    mario.h \
    gameobject.h \
    map.h \
    maploader.h \
    position.h \
    hill.h \
    bush.h \
    wall.h \
    block.h \
    cloud.h \
    castle.h \
    secretbox.h \
    pipe.h \
    rectangle.h \
    brick.h \
    enemy.h \
    turtle.h \
    owl.h \
    flag.h \
    soundmanager.h
