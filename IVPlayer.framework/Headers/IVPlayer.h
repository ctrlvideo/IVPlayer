//
//  IVPlayer.h
//  IVPlayer
//
//  Created by Di Guo on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IVPlayerDelegate.h"
#import "IVPlayerControlView.h"


NS_ASSUME_NONNULL_BEGIN


@interface IVPlayer : NSObject

/// 项目ID  仅读
@property(nonatomic,strong,readonly) NSString *projectId;

/// 播放状态
@property(nonatomic,assign,readonly) IVPlayerStatus status;

/// 当前播放时间
@property(nonatomic,assign,readonly) CGFloat time;

/// 互动层视图
@property(nonatomic,strong,readonly) UIView *view;

/// 视频片段数组
@property(nonatomic,strong,readonly) NSArray <IVPlayerNodeModel*> *nodeModels;

/// 当前片段模型
@property(nonatomic,strong,readonly) IVPlayerNodeModel *currentNodeModel;

/// 播放通知代理
@property(nonatomic,weak) id <IVPlayerDelegate> delegate;

/// 播控通知代理 （自定义播控代理）注意：设置此代理默认的播控层将隐藏移除
@property(nonatomic,weak) id <IVPlayerControlDelegate> playerControlDelegate;

/// IVPlayer是否运行中
@property(nonatomic,assign,readonly) BOOL isPlaying;

/// 是否绘制手势识别的相机画面
@property(nonatomic,assign) BOOL drawCamera;

/// 手势识别相机画面视图 （需要设置属性showCamera:YES，否则默认nil不绘制）
@property(nonatomic,strong,readonly) CAEAGLLayer *cameraLayer;


/// 构建自定义播控层 ( 自定义继承重写播控层 , 如果完全自定义请忽略此接口采用继承playerControlDelegate自定义的方式 )
/// @param controlView  自定义继承的播控
- (instancetype)initWithControlView:(__kindof IVPlayerControlView*)controlView;


/// 设置项目ID开始加载
/// @param projectId  项目ID
- (void)setStartLoadWithProjectId:(NSString*)projectId;


/// 设置配置URL开始加载
/// @param config_url  配置url
- (void)setStartLoadWithConfig_url:(NSString*)config_url;


/// 设置ZIP协议资源开始加载
/// @param resourcePath 本地zip协议资源文件路径，注意路径格式必须是 file://开头且.zip后缀结尾
/// @param fileName  文件名称不带.zip后缀
- (void)setStartLoadWithResourcePath:(NSString*)resourcePath fileName:(NSString*)fileName;


/// 设置访问用户ID
/// @param userId 数据上报统计的用户ID，使用此接口需要设置IVPlayerManager的dataStatistics为YES
- (void)setCommitUserId:(NSString*)userId;


/// 获取当前播放的片段数据
- (IVPlayerNodeModel*)getCurrentPlayingProgressInfoModel;


/// 根据下标获取片段数据
/// @param index 节点下标
- (IVPlayerNodeModel*)getProgressNodeFromIndex:(int)index;


/// 播放器跳转到指定的时间
/// @param time  要跳转的时间
- (void)seekToTime:(CGFloat)time;


/// 设置播放速率 （主要是防止原生播放器设置速率会触发播放操作）
/// @param rate 速率
- (void)setRate:(CGFloat)rate;


/// 重置
- (void)reset;


/// 播放
- (void)play;


/// 暂停
- (void)pause;


/*-**以下属于同步视频播放器状态接口，不建议手动调用，交给视频播放器状态回调中自动同步即可**-*/


/// 视频准备就绪
- (void)onReady;


/// 播放状态
- (void)onPlay;


/// 暂停状态
- (void)onPause;


/// 加载中状态
- (void)onLoading;


/// 加载完毕
- (void)onEndLoading;


/// 加载失败状态
- (void)onFailureWithError:(nullable NSError*)error;


@end



NS_ASSUME_NONNULL_END
