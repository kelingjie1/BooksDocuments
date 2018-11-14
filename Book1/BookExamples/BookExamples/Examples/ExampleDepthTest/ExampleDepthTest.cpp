//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleDepthTest.h"

void ExampleDepthTest::render()
{
    glEnable(GL_DEPTH_TEST);
    ExampleCube3D::render();
    glDisable(GL_DEPTH_TEST);
}
