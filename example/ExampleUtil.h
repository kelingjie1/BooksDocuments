//
//  ExampleUtil.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once
#include <string>
#include <iostream>
#include <QFile>
#include <QImage>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLExtraFunctions>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <ObjectiveGL/ObjectiveGL.h>

using namespace std;
using namespace glm;
using namespace ObjectiveGL;

#define PI 3.1415926f

class ExampleUtil:public QOpenGLExtraFunctions
{
public:
    static ExampleUtil *instance() {
        static ExampleUtil x;
        return &x;
    }
    static bool isOpenGLES;
    ExampleUtil():QOpenGLExtraFunctions(QOpenGLContext::currentContext()) {

    }

    shared_ptr<GLTexture> createGLTexture(QImage image) {
        image = image.convertToFormat(QImage::Format_RGBA8888);
        auto texture = GLTexture::create();
        texture->setImageData(image.bits(),image.width(),image.height());
        return texture;
    }

    GLuint createTexture(QImage image) {
        image = image.convertToFormat(QImage::Format_RGBA8888);
        GLuint texture;
        glGenTextures(1,&texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        return texture;
    }
    QString getShaderStr(QString name) {
        QFile vsFile(":/Resource/shader/"+name);
        vsFile.open(QIODevice::ReadOnly|QIODevice::Text);
        auto vsQStr = vsFile.readAll();
        if (isOpenGLES) {
            vsQStr.insert(0,"#version 300 es\n");
        }
        else {
            vsQStr.insert(0,"#version 330\n");
        }
       return vsQStr;
    }

    shared_ptr<GLProgram> createGLProgram(QString vs,QString fs) {
        auto vsStr = getShaderStr(vs).toStdString();
        auto fsStr = getShaderStr(fs).toStdString();
        auto program = GLProgram::create();
        program->setRenderShader(vsStr,fsStr);
        return program;
    }

    GLuint createProgram(QString vs,QString fs) {
        GLint success;
        GLchar infoLog[512];
        auto vsStr = getShaderStr(vs).toStdString();
        auto fsStr = getShaderStr(fs).toStdString();


        //创建顶点着色器对象
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const GLchar* vsSource = vsStr.c_str();
        //将源代码传入顶点着色器
        glShaderSource(vertexShader, 1, &vsSource, nullptr);
        //编译顶点着色器
        glCompileShader(vertexShader);
        //获取编译结果
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            //获取错误信息
            glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
            cout<<(string("vertexShader compile error")+infoLog);
            //删除顶点着色器对象
            glDeleteShader(vertexShader);
            return 0;
        }

        //创建片段着色器对象
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const GLchar* fsSource = fsStr.c_str();
        //将源代码传入片段着色器
        glShaderSource(fragmentShader, 1, &fsSource, nullptr);
        //编译片段着色器
        glCompileShader(fragmentShader);
        //获取编译结果
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            //获取错误信息
            glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
            cout<<string("fragmentShader compile error:")+infoLog;
            //删除片段着色器对象
            glDeleteShader(fragmentShader);
            return 0;
        }

        //创建程序对象
        GLuint program = glCreateProgram();
        if (!program)
        {
            cout<<"glprogram create failed";
        }
        //绑定顶点着色器
        glAttachShader(program, vertexShader);
        //绑定片段着色器
        glAttachShader(program, fragmentShader);

        GLint linked;

        //链接程序
        glLinkProgram(program);
        //获取程序状态
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked)
        {
            //获取错误信息
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            cout<<string("program link error:")+infoLog;
            //删除程序对象
            glDeleteProgram(program);
            return 0;
        }
        //删除顶点着色器对象
        glDeleteShader(vertexShader);
        //删除片段着色器对象
        glDeleteShader(fragmentShader);

        return program;
    }
};
