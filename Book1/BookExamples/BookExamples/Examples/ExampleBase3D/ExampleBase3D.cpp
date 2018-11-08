//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleBase3D.h"

void ExampleBase3D::setup()
{
    setupShader("Example9.vs", "Example9.fs");
    texLocation = glGetUniformLocation(program, "tex");
    mvpLocation = glGetUniformLocation(program, "mvp");
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

void ExampleBase3D::render()
{
    Example::render();
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniform1i(texLocation, 0);
    
    //构造模型坐标变换矩阵(根据时间进行旋转)
    modelMatrix = ExampleUtil::Matrix4MakeYRotation(totalTime);
    
    //构造观察矩阵，相机位置（0，0，-10），目标位置（0，0，0），上方向向量（0，1，0）
    viewMatrix = ExampleUtil::Matrix4MakeLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);
    
    //构造透视投影矩阵，传入视窗尺寸viewWidth，viewHeight，及投影角度PI/4，近裁面距离1，远裁面距离10000
    projectionMatrix = ExampleUtil::Matrix4MakePerspective(viewWidth, viewHeight, 3.1415926/4, 1, 10000);
    
    //计算MVP矩阵
    Matrix4f mvpMatrix = projectionMatrix*viewMatrix*modelMatrix;
    //传入矩阵数据，列优先存储
    glUniformMatrix4fv(mvpLocation, 1, false, mvpMatrix.data());
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Example9Vertex), vertice.data());
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(Example9Vertex), (char*)vertice.data()+sizeof(GLfloat)*3);
    //绘制三角形扇形，形成正方形
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
