//
// Created by lingtonke on 2019/2/22.
//

#pragma once

#ifdef ANDROID
#include <GLES3/gl3.h>
#else
#include "ExampleIOSBridge.h"
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#endif
