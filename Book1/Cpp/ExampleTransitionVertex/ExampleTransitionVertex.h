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

class ExampleTransitionVertex : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint mvpLocation;
    vector<vector<TexVertex>> verticeList;
    Matrix4f modelMatrix;
public:
    virtual void setup();
    virtual void render();
};

