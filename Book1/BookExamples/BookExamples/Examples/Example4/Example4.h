//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example4_h
#define Example4_h

#include "Example.h"
class Example4 : public Example
{
public:
    std::vector<GLfloat> vertice;
    virtual void setup();
    virtual void render();
};

#endif /* Example4_h */
