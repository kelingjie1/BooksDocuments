//
//  Example.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <string>
#include <iostream>
#include <fstream>
#include "ExampleUtil.h"

#ifndef Example_h
#define Example_h
static inline void LKLogError(string str)
{
    cout<<str;
}

class Example
{
protected:
    GLuint program;
public:
    virtual void setupShader(string vs,string fs);
    virtual void setup();
    virtual void render();
};


#endif /* Example_h */
