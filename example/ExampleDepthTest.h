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
class ExampleDepthTest : public ExampleCube3D
{
public:
    virtual void render() {
        //开启深度测试
        glEnable(GL_DEPTH_TEST);
        //设置深度测试通过方式
        glDepthFunc(GL_LESS);
        //绘制立方体
        ExampleCube3D::render();
        //关闭深度测试
        glDisable(GL_DEPTH_TEST);
    }
};

