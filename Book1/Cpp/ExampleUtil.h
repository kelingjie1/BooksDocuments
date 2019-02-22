//
//  ExampleUtil.hpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#pragma once
#include <string>

#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

#define PI 3.1415926

class ExampleTexture
{
public:
    GLuint texture;
    GLuint width;
    GLuint height;
    ExampleTexture(string file);
};

class ExampleUtil
{
public:
    static ExampleUtil *instance;
    string resourcesDir;
    static Matrix4f Matrix4MakeLookAt(float eyeX, float eyeY, float eyeZ,
                                      float targetX, float targetY, float targetZ,
                                      float upX, float upY, float upZ);
    static Matrix4f Matrix4MakePerspective(float viewWidth, float viewHeight, float angle,
                                           float zNear, float zFar);
    static Matrix4f Matrix4MakeXRotation(float radians);
    static Matrix4f Matrix4MakeYRotation(float radians);
    static Matrix4f Matrix4MakeZRotation(float radians);
    static Matrix4f Matrix4MakeTransition(Vector3f v);
    static Matrix4f Matrix4MakeScale(Vector3f v);
};
