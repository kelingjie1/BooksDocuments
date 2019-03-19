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
#import "ExampleStencilTest.h"
#import "ExampleScaleVertex.h"
#import "ExampleScaleFragment.h"
#import "ExampleMagnifier.h"
#import "ExampleTransitionVertex.h"
#import "ExampleTransitionFragment.h"
#import "ExampleRotation.h"
#import "ExampleInvertColor.h"
#import "ExampleGrayColor.h"
#import "ExampleColorChannel.h"
#import "ExampleLUT.h"

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
    ExampleUtil::instance->resourcesDir = [[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"Resource"] cStringUsingEncoding:NSUTF8StringEncoding];
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
                       Demo(@"Example -- 背面剔除", new ExampleCullFace()),
                       Demo(@"Example -- 三维方块", new ExampleCube3D()),
                       Demo(@"Example -- 深度测试", new ExampleDepthTest()),
                       Demo(@"Example -- 模板测试", new ExampleStencilTest()),
                       Demo(@"Example -- 放大和缩小（顶点实现）", new ExampleScaleVertex()),
                       Demo(@"Example -- 放大和缩小（片段实现）", new ExampleScaleFragment()),
                       Demo(@"Example -- 放大镜", new ExampleMagnifier()),
                       Demo(@"Example -- 错位平移（顶点实现）", new ExampleTransitionVertex()),
                       Demo(@"Example -- 错位平移（片段实现）", new ExampleTransitionFragment()),
                       Demo(@"Example -- 旋涡效果", new ExampleRotation()),
                       Demo(@"Example -- 反色效果", new ExampleInvertColor()),
                       Demo(@"Example -- 灰度效果", new ExampleGrayColor()),
                       Demo(@"Example -- 色彩分离", new ExampleColorChannel()),
                       Demo(@"Example -- 颜色查找表", new ExampleLUT()),
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