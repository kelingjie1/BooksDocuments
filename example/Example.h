//
//  Example.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//
#pragma once

#include "ExampleUtil.h"

using namespace std;
#pragma  pack(1)
struct TexVertex
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat u;
    GLfloat v;
    static vector<TexVertex> makeRect()
    {
        vector<TexVertex> vertice;
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
        return vertice;
    }
};
#pragma pack()
class Example: public QOpenGLExtraFunctions
{
public:
    float viewWidth = 0;
    float viewHeight = 0;
protected:

    float totalTime = 0;
    float deltaTime = 0;
    chrono::system_clock::time_point lastTime;
    GLuint program = 0;
public:
    Example():QOpenGLExtraFunctions(QOpenGLContext::currentContext()) {

    }
    virtual void setup() {
        lastTime = chrono::system_clock::now();
    }
    virtual void render() {
        auto newTime = chrono::system_clock::now();
        deltaTime = chrono::duration_cast<chrono::milliseconds>(newTime-lastTime).count()/1000.0f;
        totalTime += deltaTime;
        lastTime = newTime;
    }
    virtual void release() {
        if (program)
        {
            glDeleteProgram(program);
            program = 0;
        }
    }
};
