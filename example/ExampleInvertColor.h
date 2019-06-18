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

class ExampleInvertColor : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint timeLocation;
    GLuint mvpLocation;
    vector<TexVertex> vertice;
    mat4 modelMatrix;
public:
    virtual void setup() {
        program = ExampleUtil::instance()->createProgram("ExampleBase3D.vs", "ExampleInvertColor.fs");
        texLocation = glGetUniformLocation(program, "tex");
        timeLocation = glGetUniformLocation(program, "time");
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

        modelMatrix = mat4(1);
        glUniformMatrix4fv(mvpLocation, 1, false, value_ptr(modelMatrix));
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
};
