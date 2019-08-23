#-------------------------------------------------
#
# Project created by QtCreator 2019-06-13T15:16:23
#
#-------------------------------------------------

QT       += core gui \
            opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
win32-msvc*: {
    QMAKE_CFLAGS *= /utf-8
    QMAKE_CXXFLAGS *= /utf-8
}

INCLUDEPATH += \
        Library/glm \
        Library/

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        example/Example.h \
        example/ExampleBase3D.h \
        example/ExampleBaseShader.h \
        example/ExampleClearBuffer.h \
        example/ExampleColorChannel.h \
        example/ExampleCube3D.h \
        example/ExampleCullFace.h \
        example/ExampleDepthTest.h \
        example/ExampleEBO.h \
        example/ExampleGrayColor.h \
        example/ExampleInvertColor.h \
        example/ExampleLUT.h \
        example/ExampleLight.h \
        example/ExampleMagnifier.h \
        example/ExampleMemoryMapping.h \
        example/ExampleRotation.h \
        example/ExampleScaleFragment.h \
        example/ExampleScaleVertex.h \
        example/ExampleStencilTest.h \
        example/ExampleTextureAnimation.h \
        example/ExampleTextureMapping.h \
        example/ExampleTransitionFragment.h \
        example/ExampleTransitionVertex.h \
        example/ExampleUtil.h \
        example/ExampleVAO.h \
        example/ExampleVBO.h \
        example/ExampleVertexIndice.h \
        mainwindow.h \
        renderview.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
