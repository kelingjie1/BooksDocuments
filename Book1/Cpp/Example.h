//
//  Example.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//
#pragma once

#include "Platform.h"
#include <Eigen/Eigen>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "ExampleUtil.h"

using namespace std;
static inline void LKLogError(string str)
{
    cout<<str;
}

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
} __attribute__((packed));

class Example
{
public:
    float viewWidth;
    float viewHeight;
protected:

    double totalTime;
    clock_t lastTime;
    GLuint program;
public:
    virtual void setupShader(string vs,string fs);
    virtual void setup();
    virtual void render();
    virtual void release();
};
