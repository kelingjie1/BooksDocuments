//
//  Example.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//
#pragma once
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
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
