//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleScaleVertex.h"

void ExampleScaleVertex::setup()
{
    setupShader("ExampleBase3D.vs", "ExampleBase3D.fs");
    texLocation = glGetUniformLocation(program, "tex");
    mvpLocation = glGetUniformLocation(program, "mvp");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
    vertice = TexVertex::makeRect();
}

void ExampleScaleVertex::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    //构造模型坐标变换矩阵(根据时间进行旋转)
    float scale = sin(totalTime/10);
    modelMatrix = ExampleUtil::Matrix4MakeScale(Vector3f(scale,scale,scale));
    //传入矩阵数据，列优先存储
    glUniformMatrix4fv(mvpLocation, 1, false, modelMatrix.data());
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
    //绘制三角形扇形，形成正方形
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
