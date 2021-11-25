//
//  IVPlayerLoadingView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/2/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IVPlayerLoadingView : UIView

//开始动画并显示
- (void)startAnimating;

//停止动画并隐藏
- (void)stopAnimating;


@end

NS_ASSUME_NONNULL_END
