//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleBaseShader.h"

const int vertice_num = 6;

void ExampleBaseShader::setup()
{
    Example::setup();
    //编译顶点着色器和片段着色器
    program = ExampleUtil::instance()->createProgram("Example2.vs", "Example2.fs");
    
    //初始化顶点数据
    vertice.resize(vertice_num*2);
    int offset = 0;
    vertice[offset] = 0.0;
    vertice[offset+1] = 0.0;
    
    offset+=2;
    vertice[offset] = 0.2;
    vertice[offset+1] = 0.4;
    
    offset+=2;
    vertice[offset] = 0.4;
    vertice[offset+1] = 0.4;

    offset+=2;
    vertice[offset] = 0.4;
    vertice[offset+1] = 0.0;
    
    offset+=2;
    vertice[offset] = 0.6;
    vertice[offset+1] = 0.2;
    
    offset+=2;
    vertice[offset] = 0.6;
    vertice[offset+1] = 0.6;
}

void ExampleBaseShader::render()
{


}
