//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "../Example.h"
class ExampleEBO : public Example
{
public:
    vector<GLfloat> vertice;
    vector<GLushort> indice;
    GLuint vbo;
    GLuint ebo;
    virtual void setup();
    virtual void render();
    virtual void release();
};

