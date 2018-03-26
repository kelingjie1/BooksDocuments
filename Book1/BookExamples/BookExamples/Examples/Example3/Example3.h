//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#ifndef Example3_h
#define Example3_h

#include "Example.h"
class Example3 : public Example
{
public:
    std::vector<GLfloat> vertice;
    std::vector<GLushort> indice;
    virtual void setup();
    virtual void render();
};

#endif /* Example3_h */
