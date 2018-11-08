//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example6_h
#define Example6_h

#include "Example.h"
class ExampleVAO : public Example
{
public:
    vector<GLfloat> vertice;
    vector<GLushort> indice;
    GLuint vbo;
    GLuint ebo;
    GLuint vao;
    virtual void setup();
    virtual void render();
};

#endif /* Example6_h */
