//
//  Example.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "Example.h"
GLchar vsStr[2000];
GLchar fsStr[2000];
void Example::setupShader(string vs, string fs)
{
    GLint success;
    GLchar infoLog[512];
    
    fstream vsFile(ExampleUtil::instance->resourcesDir+"/shader/"+vs,ios::in);
    fstream fsFile(ExampleUtil::instance->resourcesDir+"/shader/"+fs,ios::in);
    
    
    vsFile.read(vsStr, 2000);
    fsFile.read(fsStr, 2000);
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vsSource = vsStr;
    glShaderSource(vertexShader, 1, &vsSource, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        LKLogError(string("vertexShader compile error")+infoLog);
        glDeleteShader(vertexShader);
    }
    
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fsSource = fsStr;
    glShaderSource(fragmentShader, 1, &fsSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        LKLogError(string("fragmentShader compile error:")+infoLog);
        glDeleteShader(fragmentShader);
    }
    
    program = glCreateProgram();
    if (!program)
    {
        LKLogError("glprogram create failed");
    }
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    
    GLint linked;
    
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked)
    {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        LKLogError(string("program link error:")+infoLog);
        glDeleteProgram(program);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Example::setup()
{
    lastTime = clock();
}

void Example::render()
{
    clock_t newTime = clock();
    double timeDelta = (newTime-lastTime)/100000.0;
    if (timeDelta>1)
    {
        timeDelta = 1;
    }
    lastTime = newTime;
    totalTime += timeDelta;
}
