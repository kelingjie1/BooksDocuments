//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
class ExampleClearBuffer : public Example
{
public:
    virtual void render() {
        Example::render();
        //设置清除颜色(RGBA)
        glClearColor(0.0, 0.5, 0.5, 1);
        //清除颜色缓冲区
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

