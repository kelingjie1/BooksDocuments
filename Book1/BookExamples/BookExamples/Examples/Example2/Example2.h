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
#include <vector>
using namespace std;
class Example2 : public Example
{
    std::vector<GLfloat> vertice;
public:
    virtual void setup();
    virtual void render();
};


#endif /* Example2_h */
