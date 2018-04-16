//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example7_h
#define Example7_h

#include "Example.h"
class Example7 : public Example
{
public:
    GLuint texture;
    GLuint texLocation;
    vector<GLfloat> vertice;
    vector<GLfloat> texCoords;
    virtual void setup();
    virtual void render();
};

#endif /* Example7_h */
