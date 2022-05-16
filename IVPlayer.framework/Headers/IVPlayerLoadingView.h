//
//  IVPlayerLoadingView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/2/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IVPlayerLoadingView : UIView

//是否正在加载中
@property(nonatomic,assign) BOOL loading;

//开始动画并显示 delay:是否启动延迟显示
- (void)startAnimating:(BOOL)delay;

//停止动画并隐藏
- (void)stopAnimating;


@end

NS_ASSUME_NONNULL_END
