//
//  IVPlayerDelegates.h
//  IVPlayer
//
//  Created by Di Guo on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import <IVPlayer/IVPlayerDefine.h>
#import <IVPlayer/IVPlayerNodeModel.h>
#import <IVPlayer/IVReleaseInfoModel.h>
#import <IVPlayer/IVPlayerCardInfoModel.h>
#import <IVPlayer/IVError.h>
#import <IVPlayer/IVEventCallModel.h>

@class IVPlayer;


NS_ASSUME_NONNULL_BEGIN


//*******************播放控制代理********************//
@protocol IVPlayerControlDelegate <NSObject>


/// 播放状态改变通知
/// @param player  当前player
- (void)player:(IVPlayer*)player playerControlDidChangeStatus:(IVPlayerStatus)status;


/// 是否禁止显示播放按钮 (被动暂停时，禁止显示播放暂停按钮)
/// @param player 当前player
/// @param playButtonEnabled YES 禁止显示 NO 可以显示
- (void)player:(IVPlayer*)player playerControlPlayButtonEnabled:(BOOL)playButtonEnabled;


/// 是否禁止显示进度条 (播控UI显示时，禁止显示进度条)
/// @param player 当前player
/// @param playProgressViewEnabled  YES 禁止显示 NO 可以显示
- (void)player:(IVPlayer*)player playerControlPlayProgressViewEnabled:(BOOL)playProgressViewEnabled;


@optional


/// 播控加载状态改变
/// @param player 当前player
/// @param loading  YES:加载中  NO:加载结束
- (void)player:(IVPlayer*)player didChangeLoading:(BOOL)loading;


/// 播控即将执行初始化
/// @param player  当前player
- (void)playerControlWillInitFromPlayer:(IVPlayer*)player;


/// 播控即将销毁释放
/// @param player 当前player
- (void)playerControlDidDeallocFromPlayer:(IVPlayer*)player;


/// 事件片段开始时通知
/// @param player 当前player
/// @param nodeModel 事件节点模型
- (void)player:(IVPlayer*)player onEventStartWithNodeModel:(IVPlayerNodeModel*)nodeModel;


/// 事件片段结束时通知
/// @param player 当前player
/// @param nodeModel 事件节点模型
- (void)player:(IVPlayer*)player onEventEndWithNodeModel:(IVPlayerNodeModel*)nodeModel;


/// 加载失败
/// @param player 当前player
/// @param error   IVError 类型
- (void)player:(IVPlayer*)player failureWithError:(IVError*)error;


/// 视频协议加载成功设置视频信息
/// @param player 当前player
/// @param infoModel  视频信息模型
- (void)player:(IVPlayer*)player playerControlLoadFinishWithInfoModel:(IVReleaseInfoModel*)infoModel;

@end




//*******************播放器代理********************//
@protocol IVPlayerDelegate <NSObject>


/// 获取当前播放器时间 - 注意float至少精确到小数点后三位
/// @param player  当前player
- (CGFloat)timeInCurrentVideoFromPlayer:(IVPlayer*)player;


/// 设置播放器seek到某一个时间点
/// @param player  当前player
/// @param time  播放器seek的时间点 （时间CGFloat类型转换CMTime参考Demo）
- (void)player:(IVPlayer*)player playSetCurrentVideoSeekToTime:(CGFloat)time;


/// 视频开始播放通知
/// @param player  当前player
- (void)videoDidPlayInPlayer:(IVPlayer*)player;


/// 视频暂停播放通知
/// @param player  当前player
- (void)videoDidPauseInPlayer:(IVPlayer*)player;


@optional


/// 播控协议数据开始加载
/// @param player  当前player
- (void)playerWillStartLoadRequestInPlayer:(IVPlayer*)player;


/// 播控协议数据加载完毕，互动数据准备就绪
/// @param player  当前player
/// @param infoModel 视频信息
- (void)player:(IVPlayer*)player didFinishBeReadyPlayWithInfoModel:(IVReleaseInfoModel*)infoModel;


/// 播控加载错误，互动视频加载错误时回调
/// @param player  当前player
/// @param error   对应IVError枚举类型
- (void)player:(IVPlayer*)player requestLoadFailWithError:(IVError*)error;


/// 播控加载状态改变
/// @param player 当前player
/// @param loading  YES:加载中  NO:加载结束
- (void)player:(IVPlayer*)player didChangeLoading:(BOOL)loading;


/// 播放状态改变
/// @param player 当前player
/// @param status 对应IVPlayerStatus枚举类型
- (void)player:(IVPlayer*)player didChangeStatus:(IVPlayerStatus)status;


/// 资源下载失败：return 是否继续播放，如果NO 播控将处于停止状态
/// @param player 当前player
/// @param type 资源类型 0图片 1音频 (目前只处理了图片，音频暂不会通知)
/// @param media_id 素材ID
/// @param error 错误信息
- (BOOL)player:(IVPlayer*)player resumeWhenResourceDownloadFailOnType:(NSInteger)type media_id:(NSString*)media_id withError:(IVError*)error;


/// 获取互动信息
/// @param player  当前player
/// @param resultModel  互动信息模型
- (void)player:(IVPlayer*)player onEventCallback:(IVEventCallModel*)resultModel;


/// 显示结局卡信息
/// @param player  当前player
/// @param infoModel 结局卡事件信息
- (IVPlayerCardInfoModel*)cardInfoModelOnPlayer:(IVPlayer *)player eventInfoModel:(IVEventCallExposureModel*)infoModel;


/// 分享通知
/// @param player 当前player
/// @param infoModel 视频信息模型
- (void)player:(IVPlayer *)player shareWithVideoInfoModel:(IVReleaseInfoModel*)infoModel;


/// 按钮触发拨打电话  -（实现此代理即可自定义拨打UI样式，否则使用默认系统拨打电话）
/// @param player  当前player
/// @param number  电话号码
- (void)player:(IVPlayer *)player callPhoneWithNumber:(NSString*)number;


/// 触发打开网页 -（实现此代理即可自定义网页UI样式，否则内部弹出默认网页控制器）
/// @param player 当前player
/// @param urlString 加载网页地址
- (void)player:(IVPlayer*)player loadWebViewWithUrlString:(NSString*)urlString;


/// 打开APP -（实现此代理即可自定义跳转app逻辑，否则内部实现默认的逻辑）
/// @param player 当前player
/// @param scheme 第三方APP的scheme
/// @param webUrl APP没安装的备用网址
- (void)player:(IVPlayer*)player openAppWithScheme:(NSString*)scheme webUrl:(NSString*)webUrl;


/// 打开小程序 - （APP内有小程序功能可实现此接口）
/// @param player 当前player
/// @param miniprogramId 小程序ID
/// @param path 小程序路径
- (void)player:(IVPlayer*)player openMiniprogramId:(NSString*)miniprogramId path:(NSString*)path;


/// 点击屏幕时触发，如果点击的对象为播控按钮则不会触发此通知
/// @param player 当前player
/// @param point   触摸在view上的坐标点
- (void)player:(IVPlayer*)player didTouchTapGestureWithPoint:(CGPoint)point;


/// 播控调整速率
/// @param player 当前player
/// @param rate  视频速率
- (void)player:(IVPlayer*)player setVideoRate:(CGFloat)rate;


@end


NS_ASSUME_NONNULL_END
