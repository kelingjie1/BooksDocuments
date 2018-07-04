//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "Example8.h"

const GLfloat spriteWidth = 100.0/1024.0;
const GLfloat spriteHeight = 100.0/1024.0;
const int spriteRowCount = 10;
const int spriteColumnCount = 10;
const int spriteCount = spriteRowCount*spriteColumnCount;

void Example8::setup()
{
    setupShader("Example8.vs", "Example8.fs");
    texLocation = glGetUniformLocation(program, "tex");
    xLocation = glGetUniformLocation(program, "x");
    yLocation = glGetUniformLocation(program, "y");
    widthLocation = glGetUniformLocation(program, "width");
    heightLocation = glGetUniformLocation(program, "height");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("star.png", width, height, texture);
    float scale = viewWidth/viewHeight;
    vertice.resize(8);
    vertice[0] = -1;
    vertice[1] = -scale;
    
    vertice[2] = -1;
    vertice[3] = scale;
    
    vertice[4] = 1;
    vertice[5] = scale;
    
    vertice[6] = 1;
    vertice[7] = -scale;
    
    texCoords.resize(8);
    texCoords[0] = 0;
    texCoords[1] = 0;
    
    texCoords[2] = 0;
    texCoords[3] = 1;
    
    texCoords[4] = 1;
    texCoords[5] = 1;
    
    texCoords[6] = 1;
    texCoords[7] = 0;
}

void Example8::render()
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
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, texCoords.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
