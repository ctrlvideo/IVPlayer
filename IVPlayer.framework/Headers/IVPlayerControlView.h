//
//  IVPlayerControlView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/1/4.
//

#import <UIKit/UIKit.h>
#import "IVReleaseInfoModel.h"
#import "IVPlayerLoadingView.h"
#import "IVPlayerRateView.h"
#import "IVPlayerEventBarView.h"
#import "IVEventCallModel.h"
#import "IVError.h"
#import "IVPlayerDefine.h"
#import "IVPlayerNodeModel.h"
#import "IVTimer.h"

NS_ASSUME_NONNULL_BEGIN


@protocol IVPlayerControlViewDelegate <NSObject>
//点击播放按钮 是否中间的按钮
- (void)playerControlViewDidClickPlayButton:(BOOL)center;
//点击暂停按钮
- (void)playerControlViewDidClickPauseButton;
//设置播放速率
- (void)playerControlViewWillSetVideoRate:(CGFloat)rate;
//点击上一个节点
- (void)playerControlViewDidClickLastNode:(IVPlayerNodeModel*)nodeModel;
//点击下一个节点
- (void)playerControlViewDidClickNextNode:(IVPlayerNodeModel*)nodeModel;
//设置seek时间
- (void)playerControlViewWillSetVideoSeekTime:(CGFloat)time;
//播控滑动进度条，type: 0 began, 1 move, 2 ended
- (void)playerControlViewMoveProgressWithTime:(CGFloat)time type:(int)type;

@end

@interface IVPlayerControlView : UIView

//中心播放按钮
@property(nonatomic,strong) UIButton *centerPlayButton;
//加载中动画view
@property(nonatomic,strong) IVPlayerLoadingView *loadingView;
//速率选项view
@property(nonatomic,strong) IVPlayerRateView *rateView;
//事件bar
@property(nonatomic,strong) IVPlayerEventBarView *eventBar;
//视频标题
@property(nonatomic,strong) UILabel *titleLabel;
//显示播控计时器
@property(nonatomic,strong) IVTimer *timer;
//是否正在加载中
@property(nonatomic,assign) BOOL onLoading;
//显示播控的持续时间 - 默认8秒
@property(nonatomic,assign) CGFloat duration;
//记录视频信息模型
@property(nonatomic,strong) IVReleaseInfoModel *infoModel;
//是否禁止显示播放按钮(被动暂停时，禁止显示播放暂停按钮)
@property(nonatomic,assign) BOOL showPlayViewEnabled;
//是否禁止显示进度条
@property(nonatomic,assign) BOOL showProgressViewEnabled;
//播放状态
@property(nonatomic,assign) IVPlayerStatus status;
//事件代理
@property(nonatomic,weak) id <IVPlayerControlViewDelegate> delegate;

//设置加载状态  delay:是否启动延迟显示
- (void)loadingChangeWithStatus:(BOOL)loading delay:(BOOL)delay;

//加载失败状态
- (void)failureWithError:(nullable IVError*)error;

//显示或隐藏播控栏
- (void)showOrHidenAllControlSubview;

//显示或隐藏播控栏 YES显示 NO隐藏
- (void)showOrHidenAllControlSubview:(BOOL)show animation:(BOOL)animation;

//设置当前播放器的时间
- (void)setPlayerInCurrentTime:(CGFloat)time;

//设置当前播放数据节点
- (void)setPlayerNodeModels:(NSArray<IVPlayerNodeModel*>*)nodeModels;

//设置当前播放节点
- (void)setCurrentPlayerNodeModel:(IVPlayerNodeModel*)nodeModel;

//准备、重置
- (void)reset;


@end

NS_ASSUME_NONNULL_END
