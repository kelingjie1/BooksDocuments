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
    setupShader("Example2.vs", "Example2.fs");
    
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
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    //允许使用0号顶点数组
    glEnableVertexAttribArray(0);
    //向0号顶点数组传递数据
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, vertice.data());
    int index = (int)totalTime%7;
    glLineWidth(10);
    if (index==0)
    {
        //绘制点
        glDrawArrays(GL_POINTS, 0, vertice_num);
    }
    else if (index==1)
    {
        //绘制线(0-1,2-3,4-5)
        glDrawArrays(GL_LINES, 0, vertice_num);
    }
    else if (index==2)
    {
        //连续绘制线(0-1-2-3-4-5-0)
        glDrawArrays(GL_LINE_STRIP, 0, vertice_num);
    }
    else if (index==3)
    {
        //循环绘制线(0-1-2-3-4-5)
        glDrawArrays(GL_LINE_LOOP, 0, vertice_num);
    }
    else if (index==4)
    {
        //绘制三角形(0-1-2,3-4-5)
        glDrawArrays(GL_TRIANGLES, 0, vertice_num);
    }
    else if (index==5)
    {
        //绘制三角形条带(0-1-2,2-1-3,2-3-4,4-3-5)
        glDrawArrays(GL_TRIANGLE_STRIP, 0, vertice_num);
    }
    else if (index==6)
    {
        //绘制三角形扇形(0-1-2,0-2-3,0-3-4,0-4-5)
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertice_num);
    }

}
