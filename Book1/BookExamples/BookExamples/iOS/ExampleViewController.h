//
//  Example1ViewController.h
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "Example.h"

@interface ExampleViewController : GLKViewController

@property (nonatomic) Example *example;
@property (nonatomic) EAGLContext *context;
@property (nonatomic) EAGLSharegroup *shareGroup;
@property (nonatomic) GLKView *glview;

@end
