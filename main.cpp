#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include "example/ExampleUtil.h"

bool ExampleUtil::isOpenGLES = false;
int main(int argc, char *argv[])
{
    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
        fmt.setVersion(3, 3);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        ExampleUtil::isOpenGLES = false;
    } else {
        fmt.setVersion(3, 0);
        ExampleUtil::isOpenGLES = true;
    }
    QSurfaceFormat::setDefaultFormat(fmt);
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();

    return a.exec();
}
