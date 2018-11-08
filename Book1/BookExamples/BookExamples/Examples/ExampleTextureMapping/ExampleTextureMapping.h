//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
class ExampleTextureMapping : public Example
{
public:
    GLuint texture;
    GLuint texLocation;
    vector<GLfloat> vertice;
    vector<GLfloat> texCoords;
    virtual void setup();
    virtual void render();
};

