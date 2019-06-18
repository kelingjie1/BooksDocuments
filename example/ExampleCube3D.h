//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
#include "ExampleUtil.h"

class ExampleCube3D : public Example
{
protected:
    GLuint texture;
    GLuint texLocation;
    GLuint vpLocation;
    GLuint mLocation;
    
    vector<TexVertex> vertice;
    vector<GLushort> indice;
    
    mat4 modelMatrix;
    mat4 viewMatrix;
    mat4 projectionMatrix;
public:
    virtual void setup() {
        program = ExampleUtil::instance()->createProgram("ExampleCube3D.vs", "ExampleCube3D.fs");
        texLocation = glGetUniformLocation(program, "tex");
        vpLocation = glGetUniformLocation(program, "vp");
        mLocation = glGetUniformLocation(program, "m");
        texture = ExampleUtil::instance()->createTexture(QImage(":/64.jpg"));
        vertice = TexVertex::makeRect();
    }
    virtual void render() {
        Example::render();
        glClearColor(0.0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glUseProgram(program);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glUniform1i(texLocation, 0);



        //构造观察矩阵，相机位置（0，0，-10），目标位置（0，0，0），上方向向量（0，1，0）
        viewMatrix = glm::lookAt(vec3(0, 10, -10),vec3(0, 0, 0),vec3(0, 1, 0))*glm::rotate(mat4(1),totalTime/5,vec3(0,1,0));

        //构造透视投影矩阵，传入视窗尺寸viewWidth，viewHeight，及投影角度PI/4，近裁面距离1，远裁面距离10000
        projectionMatrix = glm::perspective(3.1415926f/4,viewWidth/viewHeight,1.0f,10000.0f);

        //计算MVP矩阵
        mat4 vpMatrix = projectionMatrix*viewMatrix;
        //传入矩阵数据，列优先存储
        glUniformMatrix4fv(vpLocation, 1, false, value_ptr(vpMatrix));

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(TexVertex), vertice.data());
        glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(TexVertex), (char*)vertice.data()+sizeof(GLfloat)*3);

        //前
        modelMatrix = glm::translate(mat4(1),vec3(0,0,1));
        glUniformMatrix4fv(mLocation, 1, false, value_ptr(modelMatrix));
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        //后
        modelMatrix = glm::translate(mat4(1),vec3(0,0,-1));
        glUniformMatrix4fv(mLocation, 1, false, value_ptr(modelMatrix));
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        //左

        modelMatrix = glm::translate(mat4(1),vec3(-1,0,0))*glm::rotate(mat4(1),PI/2,vec3(0,1,0));
        glUniformMatrix4fv(mLocation, 1, false, value_ptr(modelMatrix));
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);


        //右
        modelMatrix = glm::translate(mat4(1),vec3(1,0,0))*glm::rotate(mat4(1),PI/2,vec3(0,1,0));
        glUniformMatrix4fv(mLocation, 1, false, value_ptr(modelMatrix));
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        //上
        modelMatrix = glm::translate(mat4(1),vec3(0,1,0))*glm::rotate(mat4(1),PI/2,vec3(1,0,0));
        glUniformMatrix4fv(mLocation, 1, false, value_ptr(modelMatrix));
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        //下
        modelMatrix = glm::translate(mat4(1),vec3(0,-1,0))*glm::rotate(mat4(1),PI/2,vec3(1,0,0));
        glUniformMatrix4fv(mLocation, 1, false, value_ptr(modelMatrix));
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
};

