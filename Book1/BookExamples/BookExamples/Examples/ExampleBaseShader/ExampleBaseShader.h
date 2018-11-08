//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example2_h
#define Example2_h

#include "Example.h"
class ExampleBaseShader : public Example
{
public:
    std::vector<GLfloat> vertice;
    virtual void setup();
    virtual void render();
};


#endif /* Example2_h */
