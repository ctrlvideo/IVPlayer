//
//  IVPlayerEventBarView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/4/12.
//

#import <UIKit/UIKit.h>
#import "IVPlayerNodeModel.h"


NS_ASSUME_NONNULL_BEGIN

@protocol IVPlayerEventBarDelegate <NSObject>
//点击上一个事件
- (void)eventBarClickLastNode:(IVPlayerNodeModel*)nodeModel;
//点击下一个事件
- (void)eventBarClickNextNode:(IVPlayerNodeModel*)nodeModel;
//点击播放按钮 YES播放 NO暂停
- (void)eventBarDidClickPlay:(BOOL)play;
//点击速率按钮
- (void)eventBarDidClickRateButton;
//进度条拖动代理
- (void)eventBarDidMoveProgressWithTiem:(CGFloat)time type:(int)type;

@end

@interface IVPlayerEventBarView : UIView

//当前播放时间
@property(nonatomic,assign) CGFloat currentTime;
//总节点数组
@property(nonatomic,strong) NSArray <IVPlayerNodeModel*> *nodeModels;
//当前节点模型
@property(nonatomic,strong) IVPlayerNodeModel *currentNodeModel;
//代理
@property(nonatomic,weak) id <IVPlayerEventBarDelegate> delegate;
//是否播放中状态
@property(nonatomic,assign) BOOL isPlaying;
//是否显示播放按钮
@property(nonatomic,assign) BOOL showPlay;
//是否显示进度条
@property(nonatomic,assign) BOOL showProgress;
//是否显示倍速
@property(nonatomic,assign) BOOL showRate;
//是否显示节点
@property(nonatomic,assign) BOOL showNode;

//是否可用播放按钮
@property(nonatomic,assign) BOOL play_enabled;
//是否可用节点
@property(nonatomic,assign) BOOL node_enabled;
//是否可用进度条
@property(nonatomic,assign) BOOL progre_enabled;
//是否可用倍速
@property(nonatomic,assign) BOOL rate_enabled;


//准备、重置
- (void)reset;

//显示隐藏播放按钮
- (void)playButtonShow:(BOOL)show;

//设置当前速率按钮的标题
- (void)setRateButtonTitle:(NSString*)title;

//获取bundle资源图片
- (UIImage*)getBundleImageWithName:(NSString*)name;


@end

NS_ASSUME_NONNULL_END
