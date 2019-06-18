#ifndef SFRENDERVIEW_H
#define SFRENDERVIEW_H

#include <QWidget>
#include <QtWidgets/QOpenGLWidget>
#include <functional>
class RenderView : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit RenderView(QWidget *parent = nullptr) {

    }

    virtual void initializeGL() {
        if (initializeFunc)
        {
            initializeFunc();
        }
    }
    virtual void resizeGL(int w, int h) {
        if (resizeFunc)
        {
            resizeFunc(w,h);
        }
    }
    virtual void paintGL() {
        if (drawFunc)
        {
            drawFunc();
        }
        update();
    }
    std::function<void()> initializeFunc;
    std::function<void(int w,int h)> resizeFunc;
    std::function<void()> drawFunc;
signals:

public slots:
};

#endif // SFRENDERVIEW_H
