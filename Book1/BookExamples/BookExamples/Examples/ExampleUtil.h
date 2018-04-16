//
//  ExampleUtil.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//
#include <string>
#include "ExampleIOSBridge.h"

#ifndef ExampleUtil_h
#define ExampleUtil_h

using namespace std;

class ExampleTexture
{
public:
    GLuint texture;
    GLuint width;
    GLuint height;
    ExampleTexture(string file);
};

class ExampleUtil
{
public:
    static ExampleUtil *instance;
    string resourcesDir;
};

#endif /* ExampleUtil_h */
