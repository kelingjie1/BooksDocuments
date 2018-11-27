//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//
#include "ExampleTransitionVertex.h"
#include <iostream>

const int lineCount = 40;
const float duration = 10;

void ExampleTransitionVertex::setup()
{
    setupShader("ExampleBase3D.vs", "ExampleBase3D.fs");
    texLocation = glGetUniformLocation(program, "tex");
    mvpLocation = glGetUniformLocation(program, "mvp");
    GLuint width,height;
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
    
    for (int i=0; i<lineCount; i++)
    {
        vector<TexVertex> vertice;
        vertice.resize(4);
        int index = 0;
        vertice[index].x = -1;
        vertice[index].y = 2*i/(float)lineCount-1;
        vertice[index].z = 0;
        vertice[index].u = 0;
        vertice[index].v = i/(float)lineCount;
        
        index++;
        vertice[index].x = -1;
        vertice[index].y = 2*(i+1)/(float)lineCount-1;
        vertice[index].z = 0;
        vertice[index].u = 0;
        vertice[index].v = (i+1)/(float)lineCount;
        
        index++;
        vertice[index].x = 1;
        vertice[index].y = 2*(i+1)/(float)lineCount-1;
        vertice[index].z = 0;
        vertice[index].u = 1;
        vertice[index].v = (i+1)/(float)lineCount;
        
        index++;
        vertice[index].x = 1;
        vertice[index].y = 2*i/(float)lineCount-1;
        vertice[index].z = 0;
        vertice[index].u = 1;
        vertice[index].v = i/(float)lineCount;
        verticeList.push_back(vertice);
    }
    
}

void ExampleTransitionVertex::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    for (int i=0;i<verticeList.size();i++)
    {
        float time = totalTime-(int)(totalTime/duration)*duration;
        if (time>duration/2)
        {
            time = duration-time;
        }
        //构造模型坐标变换矩阵(根据时间进行旋转)
        if (i%2)
        {
            modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(time/4,0,0));
        }
        else
        {
            modelMatrix = ExampleUtil::Matrix4MakeTransition(Vector3f(-time/4,0,0));
        }
        //传入矩阵数据，列优先存储
        glUniformMatrix4fv(mvpLocation, 1, false, modelMatrix.data());
        
        vector<TexVertex> &vertice = verticeList[i];
        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
        glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
        //绘制三角形扇形，形成正方形
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
}
