//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once
#include "../Example.h"
class ExampleBaseShader : public Example
{
public:
    std::vector<GLfloat> vertice;
    virtual void setup();
    virtual void render();
};

