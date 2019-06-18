//
//  Example1.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once

#include "Example.h"
class ExampleTextureMapping : public Example
{
public:
    GLuint texture;
    GLuint texLocation;
    vector<GLfloat> vertice;
    vector<GLfloat> texCoords;
    virtual void setup() {
        program = ExampleUtil::instance()->createProgram("Example7.vs", "Example7.fs");
        texLocation = glGetUniformLocation(program, "tex");
        texture = ExampleUtil::instance()->createTexture(QImage(":/64.jpg"));
        vertice.resize(12);
        vertice[0] = -1;
        vertice[1] = -1;
        vertice[2] = 0;
        vertice[3] = 0;
        vertice[4] = 1;
        vertice[5] = -1;

        vertice[6] = -1;
        vertice[7] = 0;
        vertice[8] = 0;
        vertice[9] = 1;
        vertice[10] = 1;
        vertice[11] = 0;

        texCoords.resize(6);
        texCoords[0] = 0;
        texCoords[1] = 0;
        texCoords[2] = 0.5;
        texCoords[3] = 1;
        texCoords[4] = 1;
        texCoords[5] = 0;
    }
    virtual void render() {
        Example::render();
        glClearColor(0.0, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glUniform1i(texLocation, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, vertice.data());
        glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, texCoords.data());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, vertice.data()+6);
        glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, texCoords.data());
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

