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
    
    //读取顶点着色器和片段着色器代码
    fstream vsFile(ExampleUtil::instance->resourcesDir+"/shader/"+vs,ios::in);
    fstream fsFile(ExampleUtil::instance->resourcesDir+"/shader/"+fs,ios::in);
    
    memset(vsStr, 0, 2000);
    memset(fsStr, 0, 2000);
    vsFile.read(vsStr, 2000);
    fsFile.read(fsStr, 2000);
    
    
    //创建顶点着色器对象
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vsSource = vsStr;
    //将源代码传入顶点着色器
    glShaderSource(vertexShader, 1, &vsSource, nullptr);
    //编译顶点着色器
    glCompileShader(vertexShader);
    //获取编译结果
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        //获取错误信息
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        LKLogError(string("vertexShader compile error")+infoLog);
        //删除顶点着色器对象
        glDeleteShader(vertexShader);
    }
    
    //创建片段着色器对象
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fsSource = fsStr;
    //将源代码传入片段着色器
    glShaderSource(fragmentShader, 1, &fsSource, nullptr);
    //编译片段着色器
    glCompileShader(fragmentShader);
    //获取编译结果
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        //获取错误信息
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        LKLogError(string("fragmentShader compile error:")+infoLog);
        //删除片段着色器对象
        glDeleteShader(fragmentShader);
    }
    
    //创建程序对象
    program = glCreateProgram();
    if (!program)
    {
        LKLogError("glprogram create failed");
    }
    //绑定顶点着色器
    glAttachShader(program, vertexShader);
    //绑定片段着色器
    glAttachShader(program, fragmentShader);
    
    GLint linked;
    
    //链接程序
    glLinkProgram(program);
    //获取程序状态
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked)
    {
        //获取错误信息
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        LKLogError(string("program link error:")+infoLog);
        //删除程序对象
        glDeleteProgram(program);
    }
    //删除顶点着色器对象
    glDeleteShader(vertexShader);
    //删除片段着色器对象
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
    cout<<totalTime<<endl;
}

void Example::release()
{
    if (program)
    {
        glDeleteProgram(program);
        program = 0;
    }
    lastTime = 0;
    totalTime = 0;
}
