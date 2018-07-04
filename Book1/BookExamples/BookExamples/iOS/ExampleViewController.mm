//
//  Example1ViewController.m
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#import "ExampleViewController.h"

@implementation ExampleViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    self.shareGroup = self.context.sharegroup;
    self.glview = (GLKView*)self.view;
    self.glview.context = self.context;
    [EAGLContext setCurrentContext:self.context];
    self.example->viewWidth = self.view.frame.size.width;
    self.example->viewHeight = self.view.frame.size.height;
    self.example->setup();
//    EAGLContext *context = [EAGLContext currentContext];
//    GLuint buffer0;
//    glGenBuffers(1, &buffer0);
//    NSLog(@"%d",buffer0);
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        EAGLContext *context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3 sharegroup:self.shareGroup];
//        [EAGLContext setCurrentContext:context];;
//        GLuint buffer1;
//        glGenBuffers(1, &buffer1);
//        NSLog(@"%@",context);
//    });
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    self.example->render();
}

@end
