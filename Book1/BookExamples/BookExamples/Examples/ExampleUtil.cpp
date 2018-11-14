//
//  ExampleUtil.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleUtil.h"
#include "Eigen/Eigen"

ExampleUtil *ExampleUtil::instance = new ExampleUtil();

ExampleTexture::ExampleTexture(string file)
{
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
}

Matrix4f ExampleUtil::Matrix4MakeLookAt(float eyeX, float eyeY, float eyeZ,
                                        float targetX, float targetY, float targetZ,
                                        float upX, float upY, float upZ)
{
    Vector3f eye = { eyeX, eyeY, eyeZ };
    Vector3f target = { targetX, targetY, targetZ };
    Vector3f up = { upX, upY, upZ };
    Vector3f z = (eye-target).normalized();
    Vector3f x = (z.cross(up)).normalized();
    Vector3f y = x.cross(z);
    
    Matrix4f m;
    m<<
    x[0], y[0], z[0], -x.dot(eye),
    x[1], y[1], z[1], -y.dot(eye),
    x[2], y[2], z[2], -z.dot(eye),
    0,0,0,1.0f;
    return m;
}

Matrix4f ExampleUtil::Matrix4MakePerspective(float viewWidth, float viewHeight, float angle,
                                             float zNear, float zFar)
{
    float aspect = viewWidth/viewHeight;
    float xScale = cos(angle/2)/sin(angle/2)/aspect;
    float yScale = cos(angle/2)/sin(angle/2);
    
    Matrix4f m;
    m<<
    xScale,0,0,0,
    0,yScale,0,0,
    0,0,-(zFar+zNear)/(zFar-zNear),-2*zFar*zNear/(zFar-zNear),
    0,0,-1,0;
    return m;
}

Matrix4f ExampleUtil::Matrix4MakeXRotation(float radians)
{
    float cos = cosf(radians);
    float sin = sinf(radians);
    
    Matrix4f m;
    m<< 1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cos , sin , 0.0f,
        0.0f, -sin, cos , 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f;
    
    return m;
}

Matrix4f ExampleUtil::Matrix4MakeYRotation(float radians)
{
    float cos = cosf(radians);
    float sin = sinf(radians);
    Matrix4f m;
    m<< cos , 0.0f, -sin, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        sin , 0.0f, cos , 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f;
    
    return m;
}

Matrix4f ExampleUtil::Matrix4MakeZRotation(float radians)
{
    float cos = cosf(radians);
    float sin = sinf(radians);
    
    Matrix4f m;
    m<< cos , sin , 0.0f, 0.0f,
        -sin, cos , 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f;
    
    return m;
}

Matrix4f ExampleUtil::Matrix4MakeTransition(Vector3f v)
{
    
    Matrix4f m;
    m<< 1.0f, 0.0f, 0.0f, v.x(),
        0.0f, 1.0f, 0.0f, v.y(),
        0.0f, 0.0f, 1.0f, v.z(),
        0.0f, 0.0f, 0.0f, 1.0f ;
    
    return m;
}

Matrix4f ExampleUtil::Matrix4MakeScale(Vector3f v)
{
    
    Matrix4f m;
    m<< v.x(), 0.0f , 0.0f , 0.0f,
        0.0f , v.y(), 0.0f , 0.0f,
        0.0f , 0.0f , v.z(), 0.0f,
        0.0f , 0.0f , 0.0f , 1.0f;
    
    return m;
}
