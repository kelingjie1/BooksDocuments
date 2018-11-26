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

class ExampleMagnifier : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint posLocation;
    GLuint viewSizeLocation;
    vector<TexVertex> vertice;
public:
    virtual void setup();
    virtual void render();
};

