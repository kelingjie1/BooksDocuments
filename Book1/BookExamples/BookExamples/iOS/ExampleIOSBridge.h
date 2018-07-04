//
//  ExampleIOSBridge.h
//  BookExamples
//
//  Created by lingtonke on 2018/4/10.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#ifndef ExampleIOSBridge_h
#define ExampleIOSBridge_h

class ExampleIOSBridge
{
public:
    static void createTextureFromFile(string file,GLuint &width,GLuint &height,GLuint &texture);
};

#endif
