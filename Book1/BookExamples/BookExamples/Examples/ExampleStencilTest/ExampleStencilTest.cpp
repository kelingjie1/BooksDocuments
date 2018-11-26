//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleStencilTest.h"
void ExampleStencilTest::drawCube(float scale)
{
    //构造观察矩阵，相机位置（0，0，-10），目标位置（0，0，0），上方向向量（0，1，0）
    viewMatrix = ExampleUtil::Matrix4MakeLookAt(0, 10, -10, 0, 0, 0, 0, 1, 0)*ExampleUtil::Matrix4MakeYRotation(totalTime/5)*ExampleUtil::Matrix4MakeScale(Vector3f(scale,scale,scale));
    
    //构造透视投影矩阵，传入视窗尺寸viewWidth，viewHeight，及投影角度PI/4，近裁面距离1，远裁面距离10000
    projectionMatrix = ExampleUtil::Matrix4MakePerspective(viewWidth, viewHeight, 3.1415926/4, 1, 10000);
    
    //计算MVP矩阵
    Matrix4f vpMatrix = projectionMatrix*viewMatrix;
    //传入矩阵数据，列优先存储
    glUniformMatrix4fv(vpLocation, 1, false, vpMatrix.data());
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
    
    //前
    modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(0,0,1));
    glUniformMatrix4fv(mLocation, 1, false, modelMatrix.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    //后
    modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(0,0,-1));
    glUniformMatrix4fv(mLocation, 1, false, modelMatrix.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    //左
    modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(-1,0,0))*ExampleUtil::Matrix4MakeYRotation(PI/2);
    glUniformMatrix4fv(mLocation, 1, false, modelMatrix.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    
    //右
    modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(1,0,0))*ExampleUtil::Matrix4MakeYRotation(PI/2);
    glUniformMatrix4fv(mLocation, 1, false, modelMatrix.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    //上
    modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(0,1,0))*ExampleUtil::Matrix4MakeXRotation(PI/2);
    glUniformMatrix4fv(mLocation, 1, false, modelMatrix.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    //下
    modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(0,-1,0))*ExampleUtil::Matrix4MakeXRotation(PI/2);
    glUniformMatrix4fv(mLocation, 1, false, modelMatrix.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void ExampleStencilTest::setup()
{
    setupShader("ExampleStencilTest.vs", "ExampleStencilTest.fs");
    colorProgram = program;
    setupShader("ExampleCube3D.vs", "ExampleCube3D.fs");
    texLocation = glGetUniformLocation(program, "tex");
    vpLocation = glGetUniformLocation(program, "vp");
    mLocation = glGetUniformLocation(program, "m");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
    vertice = TexVertex::makeRect();
}

void ExampleStencilTest::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    //开启模板测试
    glEnable(GL_STENCIL_TEST);
    //开启深度测试
    glEnable(GL_DEPTH_TEST);
    //设置模板操作（模板测试失败保持模板值，模板测试成功深度测试失败保留模板值，全部成功替换模板值）
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    //设置模板测试总是成功，并设置模板值为1，比较掩码为0xFF
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    //设置模板写入掩码为0xFF（原样写入）
    glStencilMask(0xFF);
    //绘制立方体
    drawCube(1);
    
    //设置深度测试比较方式为：不等，比较值为1，比较掩码为0xFF
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    //设置写入掩码为0x00（无法写入）
    glStencilMask(0x00);
    //切换颜色绘制程序
    glUseProgram(colorProgram);
    //绘制一个1.1倍大的立方体
    drawCube(1.1);
    //恢复模板写入掩码，否则后续glClear操作对模板缓冲区的操作会失效
    glStencilMask(0xFF);
    //关闭深度测试
    glDisable(GL_DEPTH_TEST);
    //关闭模板测试
    glDisable(GL_STENCIL_TEST);
    
}
