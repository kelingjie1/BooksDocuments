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
#include <ObjectiveGL/ObjectiveGL.h>
using namespace ObjectiveGL;
#pragma  pack(1)
struct LightVertex
{
    GLfloat position[3];
    GLfloat uv[2];
    GLfloat normal[3];
    static vector<LightVertex> makeRect()
    {
        vector<LightVertex> vertice;
        vertice.resize(4);
        vertice[0].position[0] = -1;
        vertice[0].position[1] = -1;
        vertice[0].position[2] = 0;
        vertice[0].uv[0] = 0;
        vertice[0].uv[1] = 0;
        
        vertice[1].position[0] = -1;
        vertice[1].position[1] = 1;
        vertice[1].position[2] = 0;
        vertice[1].uv[0] = 0;
        vertice[1].uv[1] = 1;
        
        vertice[2].position[0] = 1;
        vertice[2].position[1] = 1;
        vertice[2].position[2] = 0;
        vertice[2].uv[0] = 1;
        vertice[2].uv[1] = 1;
        
        vertice[3].position[0] = 1;
        vertice[3].position[1] = -1;
        vertice[3].position[2] = 0;
        vertice[3].uv[0] = 1;
        vertice[3].uv[1] = 0;
        
        for (auto &vertex:vertice) {
            vertex.normal[0] = 0;
            vertex.normal[1] = 0;
            vertex.normal[2] = 1;
        }
        
        return vertice;
    }
};
#pragma pack()
class ExampleLight : public Example
{
protected:
    shared_ptr<GLProgram> program;
    shared_ptr<GLBuffer> vbo;
    shared_ptr<GLVertexArray> vao;
    vector<LightVertex> vertice;
    shared_ptr<GLTexture> texture;
    shared_ptr<GLFrameBuffer> frameBuffer;
    GLDrawOption drawOption;
    mat4 modelMatrix;
    mat4 viewMatrix;
    mat4 projectionMatrix;
public:
    virtual void setup() {
        Example::setup();
        program = ExampleUtil::instance()->createGLProgram("ExampleDiffuseLight.vs","ExampleDiffuseLight.fs");
        vbo = GLBuffer::create();
        vertice = LightVertex::makeRect();
        vbo->alloc(sizeof(LightVertex),vertice.size(),vertice.data());
        vao = GLVertexArray::create();
        vao->setBuffer(GL_ARRAY_BUFFER,vbo);
        vao->setDrawMode(GL_TRIANGLE_FAN);
        vector<GLVertexArrayParams> params;
        params.push_back(GLVertexArrayParams(GL_FLOAT,3));
        params.push_back(GLVertexArrayParams(GL_FLOAT,2));
        params.push_back(GLVertexArrayParams(GL_FLOAT,3));
        vao->setParams(params);
        drawOption.enableBlend = false;
        drawOption.enableDepthTest = true;
        
        texture = ExampleUtil::instance()->createGLTexture(QImage(":/64.jpg"));
        program->setTexture("tex", texture);
        //构造透视投影矩阵，传入视窗尺寸viewWidth，viewHeight，及投影角度PI/4，近裁面距离1，远裁面距离10000
        projectionMatrix = glm::perspective(3.1415926f/4,viewWidth/viewHeight,1.0f,10000.0f);

        
    }
    virtual void render() {
        Example::render();
        frameBuffer = GLFrameBuffer::createWithCurrent();
        frameBuffer->clearColor();
        frameBuffer->clearDepth();
        
        //构造观察矩阵，相机位置（0，0，-10），目标位置（0，0，0），上方向向量（0，1，0）
        viewMatrix = glm::lookAt(vec3(0, 10, -10),vec3(0, 0, 0),vec3(0, 1, 0));
        auto rotation = glm::rotate(mat4(1),totalTime,vec3(0,1,0));
        auto vpMatrix = projectionMatrix*viewMatrix;
        auto m = value_ptr(vpMatrix);
        program->setUniformMatrix("vp",vector<float>(m,m+16));
        
        //前
        modelMatrix = glm::translate(rotation,vec3(0,0,1));
        m = value_ptr(modelMatrix);
        program->setUniformMatrix("m",vector<float>(m,m+16));
        frameBuffer->draw(program,vao,drawOption);

        //后
        modelMatrix = glm::translate(glm::rotate(rotation,PI,vec3(0,1,0)),vec3(0,0,1));
        m = value_ptr(modelMatrix);
        program->setUniformMatrix("m",vector<float>(m,m+16));
        frameBuffer->draw(program,vao,drawOption);

        //左

        modelMatrix = glm::translate(glm::rotate(rotation,-PI/2,vec3(0,1,0)),vec3(0,0,1));
        m = value_ptr(modelMatrix);
        program->setUniformMatrix("m",vector<float>(m,m+16));
        frameBuffer->draw(program,vao,drawOption);


        //右
        modelMatrix = glm::translate(glm::rotate(rotation,PI/2,vec3(0,1,0)),vec3(0,0,1));
        m = value_ptr(modelMatrix);
        program->setUniformMatrix("m",vector<float>(m,m+16));
        frameBuffer->draw(program,vao,drawOption);

        //上
        modelMatrix = glm::translate(glm::rotate(rotation,PI/2,vec3(1,0,0)),vec3(0,0,-1));
        m = value_ptr(modelMatrix);
        program->setUniformMatrix("m",vector<float>(m,m+16));
        frameBuffer->draw(program,vao,drawOption);

        //下
        modelMatrix = glm::translate(glm::rotate(rotation,-PI/2,vec3(1,0,0)),vec3(0,0,-1));
        m = value_ptr(modelMatrix);
        program->setUniformMatrix("m",vector<float>(m,m+16));
        frameBuffer->draw(program,vao,drawOption);

    }
};
