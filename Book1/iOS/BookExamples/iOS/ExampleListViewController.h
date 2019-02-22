//
//  ViewController.h
//  BookExamples
//
//  Created by lingtonke on 2018/3/8.
//  Copyright © 2018年 lingtonke. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Example.h"

@interface DemoData : NSObject

@property (nonatomic) NSString *title;
@property (nonatomic) Example *example;

@end

@interface ExampleListCell : UICollectionViewCell

@property (strong, nonatomic) IBOutlet UILabel *titleLable;

@end

@interface ExampleListViewController : UICollectionViewController


@end

