#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderview.h"

#include "example/ExampleClearBuffer.h"
#include "example/ExampleBaseShader.h"
#include "example/ExampleVertexIndice.h"
#include "example/ExampleVBO.h"
#include "example/ExampleEBO.h"
#include "example/ExampleVAO.h"
#include "example/ExampleMemoryMapping.h"
#include "example/ExampleTextureMapping.h"
#include "example/ExampleTextureAnimation.h"
#include "example/ExampleBase3D.h"
#include "example/ExampleCullFace.h"
#include "example/ExampleCube3D.h"
#include "example/ExampleDepthTest.h"
#include "example/ExampleStencilTest.h"
#include "example/ExampleScaleVertex.h"
#include "example/ExampleScaleFragment.h"
#include "example/ExampleMagnifier.h"
#include "example/ExampleTransitionVertex.h"
#include "example/ExampleTransitionFragment.h"
#include "example/ExampleRotation.h"
#include "example/ExampleInvertColor.h"
#include "example/ExampleGrayColor.h"
#include "example/ExampleColorChannel.h"
#include "example/ExampleLUT.h"
#include "example/ExampleLight.h";


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#define A(x,y) examples.push_back(make_pair(x,[=]()->Example*{return new y();}));

    A("清空缓冲区",ExampleClearBuffer);
    A("绘制图像",ExampleBaseShader);
    A("使用顶点索引",ExampleVertexIndice);
    A("使用顶点缓冲区(VBO)",ExampleVBO);
    A("使用索引缓冲区(EBO)",ExampleEBO);
    A("使用顶点数组对象(VAO)",ExampleVAO);
    A("内存映射",ExampleMemoryMapping);
    A("创建并使用纹理",ExampleTextureMapping);
    A("纹理动画",ExampleTextureAnimation);
    A("三维场景",ExampleBase3D);
    A("背面剔除",ExampleCullFace);
    A("三维方块",ExampleCube3D);
    A("深度测试",ExampleDepthTest);
    A("模板测试",ExampleStencilTest);
    A("放大和缩小（顶点实现）",ExampleScaleVertex);
    A("放大和缩小（片段实现）",ExampleScaleFragment);
    A("放大镜",ExampleMagnifier);
    A("错位平移（顶点实现）",ExampleTransitionVertex);
    A("错位平移（片段实现）",ExampleTransitionFragment);
    A("旋涡效果",ExampleRotation);
    A("反色效果",ExampleInvertColor);
    A("灰度效果",ExampleGrayColor);
    A("色彩分离",ExampleColorChannel);
    A("颜色查找表",ExampleLUT);
    A("基础光照",ExampleLight);
#undef A
    for (int i=0;i<examples.size();i++) {
        ui->listWidget->addItem(examples[i].first);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    ui->openGLWidget->setParent(nullptr);
    delete ui->openGLWidget;
    if (current) {
        delete current;
    }

    RenderView *view = new RenderView();
    ui->openGLWidget = view;
    ui->centralWidget->layout()->addWidget(view);
    view->initializeFunc = [=](){
        cout<<glGetString(GL_VERSION)<<endl;
        this->current = examples[ui->listWidget->currentRow()].second();
        this->current->viewWidth = view->width();
        this->current->viewHeight = view->height();
        this->current->setup();
    };
    view->resizeFunc = [=](int w,int h) {
        this->current->viewWidth = w;
        this->current->viewHeight = h;
    };
    view->drawFunc = [=]() {
        this->current->render();
        //view->context()->swapBuffers(view->context()->surface());
    };

}
