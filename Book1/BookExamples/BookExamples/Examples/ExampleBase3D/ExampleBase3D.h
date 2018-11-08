//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example9_h
#define Example9_h

#include "Example.h"
#include "ExampleUtil.h"
struct Example9Vertex
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat u;
    GLfloat v;
    
} __attribute__((packed));

class ExampleBase3D : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint mvpLocation;
    
    vector<Example9Vertex> vertice;
    
    Matrix4f modelMatrix;
    Matrix4f viewMatrix;
    Matrix4f projectionMatrix;
public:
    virtual void setup();
    virtual void render();
};

#endif /* Example9_h */
