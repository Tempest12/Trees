#-------------------------------------------------
#
# Project created by QtCreator 2013-01-09T20:31:47
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTProjectTemplate
TEMPLATE = app

LIBS += -lGL -lGLU -lglut

SOURCES +=\
        mainwindow.cpp \
    glpanel.cpp \
    Config.cpp \
    Envelope.cpp \
    Point3f.cpp \
    StringLib.cpp \
    Tree.cpp \
    Trikey.cpp \
    Vector3f.cpp \
    AttractionPoint.cpp \
    Main.cpp \
    MathLib.cpp \
    Node.cpp \
    Colour4f.cpp

HEADERS  += mainwindow.h \
    glpanel.h \
    Config.hpp \
    Envelope.hpp \
    Point3f.hpp \
    StringLib.hpp \
    Tree.hpp \
    Trikey.hpp \
    Vector3f.hpp \
    AttractionPoint.hpp \
    Main.hpp \
    MathLib.hpp \
    Node.hpp \
    Colour4f.hpp

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -Wall

OTHER_FILES += \
    config.txt
