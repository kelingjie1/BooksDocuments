//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleCullFace.h"
void ExampleCullFace::render()
{
    glEnable(GL_CULL_FACE);
    ExampleBase3D::render();
    glDisable(GL_CULL_FACE);
}
