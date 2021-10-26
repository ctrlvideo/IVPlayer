//
//  IVPlayerControlView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/1/4.
//

#import <UIKit/UIKit.h>
#import <IVPlayer/IVReleaseInfoModel.h>
#import <IVPlayer/IVPlayerLoadingView.h>
#import <IVPlayer/IVEventCallModel.h>
#import <IVPlayer/IVError.h>
#import <IVPlayer/IVPlayerDefine.h>
#import <IVPlayer/IVPlayerProgressView.h>
#import <IVPlayer/IVPlayerRateView.h>
#import <IVPlayer/IVTimer.h>

NS_ASSUME_NONNULL_BEGIN


@protocol IVPlayerControlViewDelegate <NSObject>
//点击播放按钮
- (void)playerControlViewDidClickPlayButton;
//点击暂停按钮
- (void)playerControlViewDidClickPauseButton;
//设置播放速率
- (void)playerControlViewWillSetVideoRate:(CGFloat)rate;
//设置seek时间
- (void)playerControlViewWillSetVideoSeekTime:(CGFloat)time;

@end

@interface IVPlayerControlView : UIView

//中心播放按钮
@property(nonatomic,strong) UIButton *centerPlayButton;
//工具播放按钮
@property(nonatomic,strong) UIButton *toolPlayButton;
//速率按钮
@property(nonatomic,strong) UIButton *rateButton;
//加载中动画view
@property(nonatomic,strong) IVPlayerLoadingView *loadingView;
//进度条view
@property(nonatomic,strong) IVPlayerProgressView *progressView;
//速率选项view
@property(nonatomic,strong) IVPlayerRateView *rateView;
//视频标题
@property(nonatomic,strong) UILabel *titleLabel;
//显示播控计时器
@property(nonatomic,strong) IVTimer *timer;
//是否正在加载中
@property(nonatomic,assign) BOOL onLoading;
//显示播控的持续时间 - 默认5秒
@property(nonatomic,assign) CGFloat duration;


@property(nonatomic,weak) id <IVPlayerControlViewDelegate> delegate;

//记录视频信息模型
@property(nonatomic,strong) IVReleaseInfoModel *infoModel;

//是否禁止显示播放按钮(被动暂停时，禁止显示播放暂停按钮)
@property(nonatomic,assign) BOOL showPlayViewEnabled;

//是否禁止显示进度条
@property(nonatomic,assign) BOOL showProgressViewEnabled;

//播放状态
@property(nonatomic,assign) IVPlayerStatus status;

//是否加载中
- (void)loadingChangeWithStatus:(BOOL)loading;

//加载失败状态
- (void)failureWithError:(nullable IVError*)error;

//显示或隐藏播控栏
- (void)showOrHidenAllControlSubview;

//显示或隐藏播控栏 YES显示 NO隐藏
- (void)showOrHidenAllControlSubview:(BOOL)show;

//设置当前播放器的时间
- (void)setPlayerInCurrentTime:(CGFloat)time;

//准备、重置
- (void)ready;


@end

NS_ASSUME_NONNULL_END
