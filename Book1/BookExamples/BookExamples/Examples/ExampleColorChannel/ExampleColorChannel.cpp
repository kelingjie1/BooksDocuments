//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleColorChannel.h"


void ExampleColorChannel::setup()
{
    setupShader("ExampleBase3D.vs", "ExampleColorChannel.fs");
    texLocation = glGetUniformLocation(program, "tex");
    timeLocation = glGetUniformLocation(program, "time");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
    vertice = TexVertex::makeRect();
}

void ExampleColorChannel::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    modelMatrix = Matrix4f::Identity();
    glUniformMatrix4fv(mvpLocation, 1, false, modelMatrix.data());
    glUniform1f(timeLocation,totalTime);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
    //绘制三角形扇形，形成正方形
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

