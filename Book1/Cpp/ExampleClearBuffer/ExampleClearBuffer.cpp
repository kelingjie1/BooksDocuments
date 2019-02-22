//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleClearBuffer.h"

void ExampleClearBuffer::setup()
{
    
}

void ExampleClearBuffer::render()
{
    //设置清除颜色(RGBA)
    glClearColor(0.5, 1.0, 0.5, 1);
    //清除颜色缓冲区
    glClear(GL_COLOR_BUFFER_BIT);
}
