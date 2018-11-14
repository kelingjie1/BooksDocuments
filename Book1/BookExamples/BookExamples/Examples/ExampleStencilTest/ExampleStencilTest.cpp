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
    vertice.resize(4);
    vertice[0].x = -1;
    vertice[0].y = -1;
    vertice[0].z = 0;
    vertice[0].u = 0;
    vertice[0].v = 0;
    
    vertice[1].x = -1;
    vertice[1].y = 1;
    vertice[1].z = 0;
    vertice[1].u = 0;
    vertice[1].v = 1;
    
    vertice[2].x = 1;
    vertice[2].y = 1;
    vertice[2].z = 0;
    vertice[2].u = 1;
    vertice[2].v = 1;
    
    vertice[3].x = 1;
    vertice[3].y = -1;
    vertice[3].z = 0;
    vertice[3].u = 1;
    vertice[3].v = 0;
}

void ExampleStencilTest::render()
{
    Example::render();
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_DEPTH_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilMask(0xFF);
    drawCube(1);
    
    
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);
    glUseProgram(colorProgram);
    drawCube(1.1);
    glStencilMask(0xFF);
    glDisable(GL_STENCIL_TEST);
    
}
