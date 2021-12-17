//
//  IVPlayerProgressView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/3/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IVPlayerProgressDelegate <NSObject>
//拖动进度条 type: 0开始触碰 1正在拖拽 2结束拖拽
- (void)palyerProgressDidMoveWithCurrentTime:(CGFloat)currentTime type:(int)type;

@end

@interface IVPlayerProgressView : UIView
//设置当前进度
@property(nonatomic,assign) CGFloat currentProgress;
//当前时间
@property(nonatomic,assign) CGFloat currentTime;
//总时间
@property(nonatomic,assign) CGFloat duration;

@property(nonatomic,weak) id <IVPlayerProgressDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
