//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
#include "ExampleUtil.h"

class ExampleCube3D : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint vpLocation;
    GLuint mLocation;
    
    vector<TexVertex> vertice;
    vector<GLushort> indice;
    
    Matrix4f modelMatrix;
    Matrix4f viewMatrix;
    Matrix4f projectionMatrix;
public:
    virtual void setup();
    virtual void render();
};

