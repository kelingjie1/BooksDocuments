//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
class ExampleVertexIndice : public Example
{
public:
    vector<GLfloat> vertice;
    vector<GLushort> indice;
    virtual void setup() {
        Example::setup();
        program = ExampleUtil::instance()->createProgram("Example2.vs", "Example2.fs");
        //初始化顶点数据
        vertice.resize(vertice_num*2);
        int offset = 0;
        vertice[offset] = 0.0;
        vertice[offset+1] = 0.0;

        offset+=2;
        vertice[offset] = 0.0;
        vertice[offset+1] = 0.4;

        offset+=2;
        vertice[offset] = 0.4;
        vertice[offset+1] = 0.4;

        offset+=2;
        vertice[offset] = 0.4;
        vertice[offset+1] = 0.0;

        //初始化顶点索引
        //三角形0-1-2
        indice.push_back(0);
        indice.push_back(1);
        indice.push_back(2);
        //三角形0-2-3
        indice.push_back(0);
        indice.push_back(2);
        indice.push_back(3);
    }
    virtual void render() {
        Example::render();
        glClearColor(0.0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);

        //允许使用0号顶点数组
        glEnableVertexAttribArray(0);
        //向0号顶点数组传递数据
        glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, vertice.data());
        //使用顶点索引来绘制图形
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indice.data());
    }
};

