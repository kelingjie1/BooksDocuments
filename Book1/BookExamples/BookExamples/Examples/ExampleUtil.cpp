//
//  ExampleUtil.cpp
//  BookExamples
//
//  Created by lingtonke on 2018/3/9.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleUtil.h"
ExampleUtil *ExampleUtil::instance = new ExampleUtil();

ExampleTexture::ExampleTexture(string file)
{
    ExampleIOSBridge::createTextureFromFile("64.jpg", width, height, texture);
}
