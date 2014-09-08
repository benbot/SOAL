TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shader.cpp \
    vertexArrayObject.cpp

include(deployment.pri)
qtcAddDeployment()


unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/lib/ -lSDL2

INCLUDEPATH += $$PWD/../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../usr/include

unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/lib/ -lGL -lGLU -lGLEW

INCLUDEPATH += $$PWD/../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../usr/include

INCLUDEPATH += /usr/include/glm

HEADERS += \
    shader.hpp \
    vertexArrayObject.hpp
