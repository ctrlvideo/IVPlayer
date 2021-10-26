//
//  IVPlayerProgressView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/3/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IVPlayerProgressView : UIView
//设置当前进度
@property(nonatomic,assign) CGFloat currentProgress;
//当前时间
@property(nonatomic,assign) CGFloat currentTime;
//总时间
@property(nonatomic,assign) CGFloat duration;

@end

NS_ASSUME_NONNULL_END
