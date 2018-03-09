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