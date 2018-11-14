//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
#include "ExampleCube3D.h"
class ExampleStencilTest : public ExampleCube3D
{
public:
    GLuint colorProgram;
    void drawCube(float scale);
    virtual void setup();
    virtual void render();
};

