//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example8_h
#define Example8_h

#include "Example.h"
class Example8 : public Example
{
public:
    GLuint texture;
    GLuint texLocation;
    GLuint xLocation;
    GLuint yLocation;
    GLuint widthLocation;
    GLuint heightLocation;
    
    vector<GLfloat> vertice;
    vector<GLfloat> texCoords;
    virtual void setup();
    virtual void render();
};

#endif /* Example8_h */
