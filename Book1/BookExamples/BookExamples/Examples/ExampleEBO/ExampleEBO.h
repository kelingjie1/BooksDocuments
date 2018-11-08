//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example5_h
#define Example5_h

#include "Example.h"
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

#endif /* Example5_h */
