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
#import "Example1.h"
#import "Example2.h"
#import "Example3.h"
#import "Example4.h"
#import "Example5.h"
#import "Example6.h"
#import "Example7.h"
#import "Example8.h"

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
    self.demoDatas = @[Demo(@"Example1 -- 清空缓冲区", new Example1()),
                       Demo(@"Example2 -- 绘制图像", new Example2()),
                       Demo(@"Example3 -- 使用顶点索引", new Example3()),
                       Demo(@"Example4 -- 使用顶点缓冲区(VBO)", new Example4()),
                       Demo(@"Example5 -- 使用索引缓冲区(EBO)", new Example5()),
                       Demo(@"Example6 -- 使用顶点数组对象(VAO)", new Example5()),
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
