//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleCube3D.h"

void ExampleCube3D::setup()
{
    setupShader("ExampleCube3D.vs", "ExampleCube3D.fs");
    texLocation = glGetUniformLocation(program, "tex");
    vpLocation = glGetUniformLocation(program, "vp");
    mLocation = glGetUniformLocation(program, "m");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
    vertice = TexVertex::makeRect();
}

void ExampleCube3D::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    
    
    //构造观察矩阵，相机位置（0，0，-10），目标位置（0，0，0），上方向向量（0，1，0）
    viewMatrix = ExampleUtil::Matrix4MakeLookAt(0, 10, -10, 0, 0, 0, 0, 1, 0)*ExampleUtil::Matrix4MakeYRotation(totalTime/5);
    
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
