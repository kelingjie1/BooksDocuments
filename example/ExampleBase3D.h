//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
#include "ExampleUtil.h"

class ExampleBase3D : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint mvpLocation;

    vector<TexVertex> vertice;

    mat4 modelMatrix;
    mat4 viewMatrix;
    mat4 projectionMatrix;
public:
    virtual void setup() {
        Example::setup();
        program = ExampleUtil::instance()->createProgram("ExampleBase3D.vs", "ExampleBase3D.fs");
        texLocation = glGetUniformLocation(program, "tex");
        mvpLocation = glGetUniformLocation(program, "mvp");
        texture = ExampleUtil::instance()->createTexture(QImage(":/64.jpg"));
        vertice = TexVertex::makeRect();
    }
    virtual void render() {
        Example::render();
        glClearColor(0.0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glUniform1i(texLocation, 0);

        //构造模型坐标变换矩阵(根据时间进行旋转)
        modelMatrix = glm::rotate(mat4(1),totalTime,vec3(0,1,0));

        //构造观察矩阵，相机位置（0，0，-10），目标位置（0，0，0），上方向向量（0，1，0）
        viewMatrix = glm::lookAt(vec3(0, 0, -10),vec3(0, 0, 0),vec3(0, 1, 0));

        //构造透视投影矩阵，传入视窗尺寸viewWidth，viewHeight，及投影角度PI/4，近裁面距离1，远裁面距离10000
        projectionMatrix = glm::perspective(3.1415926f/4,viewWidth/viewHeight,1.0f,10000.0f);

        //计算MVP矩阵
        mat4 mvpMatrix = projectionMatrix*viewMatrix*modelMatrix;
        //传入矩阵数据，列优先存储
        auto ptr = value_ptr(mvpMatrix);
        glUniformMatrix4fv(mvpLocation, 1, false, ptr);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
        glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
        //绘制三角形扇形，形成正方形
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
    virtual ~ExampleBase3D(){}
};

