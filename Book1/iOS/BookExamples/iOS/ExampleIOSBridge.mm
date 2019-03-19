//
//  ExampleIOSBridge.m
//  BookExamples
//
//  Created by lingtonke on 2018/4/10.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#include "ExampleIOSBridge.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ExampleUtil.h"

void ExampleIOSBridge::createTextureFromFile(string file,GLuint &width,GLuint &height,GLuint &texture)
{
    
    NSString *fileName = [NSString stringWithUTF8String:file.c_str()];
    NSString *respath = [NSString stringWithUTF8String:ExampleUtil::instance->resourcesDir.c_str()];
    NSString *path = [respath stringByAppendingPathComponent:[NSString stringWithFormat:@"image/%@",fileName]];
    UIImage *image = [UIImage imageWithContentsOfFile:path];
    width = (GLsizei)CGImageGetWidth(image.CGImage);
    height = (GLsizei)CGImageGetHeight(image.CGImage);
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContext *context = CGBitmapContextCreate(nil, width, height, 8, 4*width, colorSpace, kCGBitmapByteOrder32Host | kCGImageAlphaPremultipliedFirst);
    //CoreGraphic的坐标系和OpenGL的是颠倒的，要转回来
    CGContextTranslateCTM(context, 0, height);
    CGContextScaleCTM(context, 1.0, -1.0);
    CGContextDrawImage(context, CGRectMake(0, 0, width, height), image.CGImage);
    const void *bitmapdata = CGBitmapContextGetData(context);
    //生成一个纹理编号
    glGenTextures(1, &texture);
    //将该编号的纹理绑定为2D纹理
    glBindTexture(GL_TEXTURE_2D, texture);
    //将数据传递到显存中的纹理中
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bitmapdata);
    //设置纹理的过滤模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);

}

