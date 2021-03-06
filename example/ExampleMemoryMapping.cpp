//
//  Example1.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleMemoryMapping.h"

const int vertice_num = 4;

void ExampleMemoryMapping::setup()
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
    
    //生成一个缓冲区对象编号
    glGenBuffers(1, &vbo);
    //将缓冲区绑定到顶点缓冲区
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //计算缓冲区大小
    GLuint length = (GLuint)(sizeof(GLfloat)*vertice.size());
    //在显存中分配一块指定大小的区域
    glBufferData(GL_ARRAY_BUFFER, length, nullptr, GL_STREAM_DRAW);
    //将顶点缓冲区所在的显存映射到内存上
    void *data = glMapBufferRange(GL_ARRAY_BUFFER, 0, length, GL_MAP_WRITE_BIT|GL_MAP_READ_BIT);
    //拷贝数据
    memcpy(data, vertice.data(), length);
    //关闭内存映射
    glUnmapBuffer(GL_ARRAY_BUFFER);
    //取消顶点缓冲区绑定
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    //生成一个缓冲区对象编号
    glGenBuffers(1, &ebo);
    //将缓冲区绑定到索引缓冲区
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    //计算缓冲区大小
    length = (GLuint)(indice.size()*sizeof(GLushort));
    //在显存中分配一块指定大小的区域
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, length, nullptr, GL_STREAM_DRAW);
    //将索引缓冲区所在的显存映射到内存上
    data = glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, length, GL_MAP_WRITE_BIT|GL_MAP_READ_BIT);
    //拷贝数据
    memcpy(data, indice.data(), length);
    //关闭内存映射
    glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
    //取消索引缓冲区绑定
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ExampleMemoryMapping::render()
{
    Example::render();
    glClearColor(0.5, 1.0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    
    //重新绑定顶点缓冲区
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);
    //最后一个参数和Examle2就不一样了
    //在没有使用VBO的情况下用来传递数据
    //在使用VBO的情况下用来表示数据在VBO中的偏移
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
    //重新绑定索引缓冲区
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    //最后一次参数和Example3就不一样了
    //在没有使用EBO的情况下用来传递数据
    //在使用EBO的情况下用来表示数据在EBO中的偏移
    glDrawElements(GL_TRIANGLES, (GLsizei)indice.size(), GL_UNSIGNED_SHORT, 0);
    
}

void ExampleMemoryMapping::release()
{
    if (vbo)
    {
        glDeleteBuffers(1, &vbo);
        vbo = 0;
    }
    if (ebo)
    {
        glDeleteBuffers(1, &ebo);
        ebo = 0;
    }
    
}

