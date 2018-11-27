//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleMagnifier.h"

void ExampleMagnifier::setup()
{
    setupShader("ExampleScaleFragment.vs", "ExampleMagnifier.fs");
    texLocation = glGetUniformLocation(program, "tex");
    posLocation = glGetUniformLocation(program, "pos");
    viewSizeLocation = glGetUniformLocation(program, "viewSize");
    glUseProgram(program);
    glUniform2f(viewSizeLocation, viewWidth, viewHeight);
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
    vertice = TexVertex::makeRect();
}

void ExampleMagnifier::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    
    //设置放大镜中心点坐标
    glUniform2f(posLocation,sin(totalTime/10)/2*0.2+0.5,cos(totalTime/10)/2*0.2+0.5);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
    //绘制三角形扇形，形成正方形
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
