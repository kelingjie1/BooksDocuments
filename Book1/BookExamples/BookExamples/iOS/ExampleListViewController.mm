//
//  ViewController.m
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#import "ExampleListViewController.h"
#import "ExampleViewController.h"
#import "ExampleUtil.h"
#import "ExampleClearBuffer.h"
#import "ExampleBaseShader.h"
#import "ExampleVertexIndice.h"
#import "ExampleVBO.h"
#import "ExampleEBO.h"
#import "ExampleVAO.h"
#import "ExampleMemoryMapping.h"
#import "ExampleTextureMapping.h"
#import "ExampleTextureAnimation.h"
#import "ExampleBase3D.h"
#import "ExampleCube3D.h"
#import "ExampleDepthTest.h"
#import "ExampleCullFace.h"
#import "Example14.h"
#import "Example15.h"
#import "Example16.h"
#import "Example17.h"
#import "Example18.h"
#import "Example19.h"
#import "Example20.h"

DemoData *Demo(NSString *title,Example *example)
{
    DemoData *demo = [[DemoData alloc] init];
    demo.title = title;
    demo.example = example;
    return demo;
}

@implementation DemoData

- (void)dealloc
{
    if (self.example)
    {
        delete self.example;
    }
    self.example = nil;
}

@end

@implementation ExampleListCell

@end

@interface ExampleListViewController ()

@property (nonatomic) NSArray<DemoData*> *demoDatas;

@end

@implementation ExampleListViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    ExampleUtil::instance->resourcesDir = [[[NSBundle mainBundle] resourcePath] cStringUsingEncoding:NSUTF8StringEncoding];
    self.demoDatas = @[Demo(@"Example -- 清空缓冲区", new ExampleClearBuffer()),
                       Demo(@"Example -- 绘制图像", new ExampleBaseShader()),
                       Demo(@"Example -- 使用顶点索引", new ExampleVertexIndice()),
                       Demo(@"Example -- 使用顶点缓冲区(VBO)", new ExampleVBO()),
                       Demo(@"Example -- 使用索引缓冲区(EBO)", new ExampleEBO()),
                       Demo(@"Example -- 使用顶点数组对象(VAO)", new ExampleVAO()),
                       Demo(@"Example -- 内存映射", new ExampleMemoryMapping()),
                       Demo(@"Example -- 创建并使用纹理", new ExampleTextureMapping()),
                       Demo(@"Example -- 纹理动画", new ExampleTextureAnimation()),
                       Demo(@"Example -- 三维场景", new ExampleBase3D()),
                       Demo(@"Example -- 三维方块", new ExampleCube3D()),
                       Demo(@"Example -- 深度测试", new ExampleDepthTest()),
                       Demo(@"Example -- 背面剔除", new ExampleCullFace()),
                       ];
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return self.demoDatas.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    ExampleListCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"Example" forIndexPath:indexPath];
    cell.titleLable.text = self.demoDatas[indexPath.item].title;
    return cell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    ExampleViewController *vc = [[ExampleViewController alloc] init];
    vc.example = self.demoDatas[indexPath.item].example;
    [self.navigationController pushViewController:vc animated:YES];
    
}


@end
