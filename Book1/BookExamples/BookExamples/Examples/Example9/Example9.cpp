//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "Example9.h"

const GLfloat spriteWidth = 100.0/1024.0;
const GLfloat spriteHeight = 100.0/1024.0;
const int spriteRowCount = 10;
const int spriteColumnCount = 10;
const int spriteCount = spriteRowCount*spriteColumnCount;

void Example9::setup()
{
    setupShader("Example9.vs", "Example9.fs");
    texLocation = glGetUniformLocation(program, "tex");
    xLocation = glGetUniformLocation(program, "x");
    yLocation = glGetUniformLocation(program, "y");
    widthLocation = glGetUniformLocation(program, "width");
    heightLocation = glGetUniformLocation(program, "height");
    mvpLocation = glGetUniformLocation(program, "mvp");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("star.png", width, height, texture);
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
    
    viewMatrix = ExampleUtil::Matrix4MakeLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);
    projectionMatrix = ExampleUtil::Matrix4MakePerspective(viewWidth, viewHeight, 3.1415926/4, 1, 10000);
}

void Example9::render()
{
    Example::render();
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    GLuint index = (int)(totalTime*10)%200;
    //ping-pong模式，往返播放
    if (index>=100)
    {
        index = 199-index;
    }
    //计算行列位置
    GLfloat x = (int)(index%spriteRowCount);
    GLfloat y = (int)(index/spriteRowCount);
    
    //设置相关变量
    glUniform1f(xLocation, x);
    glUniform1f(yLocation, y);
    glUniform1f(widthLocation, spriteWidth);
    glUniform1f(heightLocation, spriteHeight);
    Matrix4f modelMatrix = ExampleUtil::Matrix4MakeYRotation(totalTime);
    Matrix4f mvpMatrix = projectionMatrix*viewMatrix*modelMatrix;
    glUniformMatrix4fv(mvpLocation, 1, false, mvpMatrix.data());
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Example9Vertex), vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(Example9Vertex), (char*)vertice.data()+sizeof(GLfloat)*3);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
