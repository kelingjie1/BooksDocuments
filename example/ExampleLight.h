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

class ExampleLight : public Example
{
protected:
    shared_ptr<GLProgram> program;
    shared_ptr<GLBuffer> vbo;
    shared_ptr<GLVertexArray> vao;
    vector<TexVertex> vertice;
    shared_ptr<GLFrameBuffer> frameBuffer;
    mat4 modelMatrix;
public:
    virtual void setup() {
        Example::setup();
        frameBuffer = GLFrameBuffer::createWithCurrent();
        program = ExampleUtil::instance()->createGLProgram("ExampleLight.vs","ExampleLight.fs");
        vbo = GLBuffer::create();
        vbo->alloc(sizeof(TexVertex),vertice.size(),vertice.data());
        vao = GLVertexArray::create();
        vao->setBuffer(GL_ARRAY_BUFFER,vbo);
        vao->setDrawMode(GL_TRIANGLE_FAN);
        vector<GLVertexArrayParams> params;
        params.push_back(GLVertexArrayParams(GL_FLOAT,3));
        params.push_back(GLVertexArrayParams(GL_FLOAT,2));
        vao->setParams(params);
        vertice = TexVertex::makeRect();
    }
    virtual void render() {
        Example::render();
        frameBuffer->draw(program,vao,GLDrawOption());

    }
};
