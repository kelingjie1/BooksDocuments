//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "ExampleBase3D.h"
class ExampleCullFace : public ExampleBase3D
{
public:
    virtual void render() {
        glEnable(GL_CULL_FACE);
        ExampleBase3D::render();
        glDisable(GL_CULL_FACE);
    }
};

