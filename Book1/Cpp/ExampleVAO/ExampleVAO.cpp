//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleVAO.h"

const int vertice_num = 4;

void ExampleVAO::setup()
{
    Example::setup();
    setupShader("Example2.vs", "Example2.fs");
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
    
    //生成一个顶点数组对象编号
    glGenVertexArrays(1, &vao);
    //绑定顶点数组对象
    glBindVertexArray(vao);
    
    //生成一个缓冲区对象编号
    glGenBuffers(1, &vbo);
    //将缓冲区绑定到顶点缓冲区
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //向顶点缓冲区中传递数据
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertice.size(), vertice.data(), GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
    
    //生成一个缓冲区对象编号
    glGenBuffers(1, &ebo);
    //将缓冲区绑定到索引缓冲区
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    //向索引缓冲区中传递数据
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indice.size()*sizeof(GLushort), indice.data(), GL_STREAM_DRAW);
    //取消顶点数组对象绑定
    glBindVertexArray(0);
    
    //顶点数组对象绑定期间创建和绑定的缓冲区等操作都属于该顶点数组对象
    //取消缓冲区绑定要在取消顶点数组对象绑定之后
    
    //取消顶点缓冲区绑定
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //取消索引缓冲区绑定
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ExampleVAO::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, (GLsizei)indice.size(), GL_UNSIGNED_SHORT, 0);
}
