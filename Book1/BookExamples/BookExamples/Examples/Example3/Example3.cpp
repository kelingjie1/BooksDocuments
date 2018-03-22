//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "Example3.h"

void Example3::setup()
{
    Example2::setup();
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertice.size(), vertice.data(), GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
}

void Example3::render()
{
    Example::render();
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);
    //最后一个参数和Examle2就不一样了
    //在没有使用VBO的情况下用来传递数据
    //在使用VBO的情况下用来表示数据在VBO中的偏移
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
    int index = (int)totalTime/2%7;
    GLsizei vertice_num = (GLsizei)vertice.size()/2;
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
        //循环绘制线(0-1-2-3-4-5-0)
        glDrawArrays(GL_LINE_STRIP, 0, vertice_num);
    }
    else if (index==3)
    {
        //连续绘制线(0-1-2-3-4-5)
        glDrawArrays(GL_LINE_LOOP, 0, vertice_num);
    }
    else if (index==4)
    {
        //绘制三角形(0-1-2,3-4-5)
        glDrawArrays(GL_TRIANGLES, 0, vertice_num);
    }
    else if (index==5)
    {
        //绘制连续三角形(0-1-2,2-1-3,2-3-4,4-3-5)
        glDrawArrays(GL_TRIANGLE_STRIP, 0, vertice_num);
    }
    else if (index==6)
    {
        //绘制三角形扇形(0-1-2,0-2-3,0-3-4,0-4-5)
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertice_num);
    }
}
