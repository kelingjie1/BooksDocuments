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

class ExampleLUT : public Example
{
protected:
    GLuint texture;
    GLuint lut;
    GLuint lutbase;
    GLuint texLocation;
    GLuint lutLocation;
    GLuint intensityLocation;
    GLuint mvpLocation;
    vector<TexVertex> vertice;
    mat4 modelMatrix;
public:
    virtual void setup() {
        Example::setup();
        program = ExampleUtil::instance()->createProgram("ExampleBase3D.vs", "ExampleLUT.fs");
        texLocation = glGetUniformLocation(program, "tex");
        lutLocation = glGetUniformLocation(program, "lut");
        intensityLocation = glGetUniformLocation(program, "intensity");
        texture = ExampleUtil::instance()->createTexture(QImage(":/64.jpg"));
        lut = ExampleUtil::instance()->createTexture(QImage(":/lut.png"));
        lutbase = ExampleUtil::instance()->createTexture(QImage(":/lutbase.png"));
        vertice = TexVertex::makeRect();
    }
    virtual void render() {
        Example::render();
        glClearColor(0.0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glUniform1i(texLocation, 0);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, lut);
        glUniform1i(lutLocation, 1);

        modelMatrix = mat4(1);
        glUniformMatrix4fv(mvpLocation, 1, false, value_ptr(modelMatrix));
        glUniform1f(intensityLocation,totalTime-floor(totalTime));


        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
        glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);
        //绘制三角形扇形，形成正方形
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    }
};
