//
//  IVPlayerManager.h
//  IVPlayer
//
//  Created by Di Guo on 2020/12/24.
//

#import <Foundation/Foundation.h>
#import<UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface IVPlayerManager : NSObject

/// 渠道标识key，需求定制化channe标识，默认nil通用模式（暂预留）
@property(nonatomic,strong) NSString *channel;

/// 视频播放完成后是否回到起始点 默认：NO  如果 YES 视频播放完成后将回到0秒初始位置
@property(nonatomic,assign) BOOL goStartWhenFinish;

/// 图片资源未加载完成前的占位代替图
@property(nonatomic,strong) UIImage *placeholderImage;

/// 设置资源未加载完毕是否进入loading状态直到加载完成才继续播放，默认：NO忽略资源加载情况  YES将会等待资源再次加载，如果再次加载失败将会通过IVPlayer代理通知videoResumeWhenResourceType: downloadFailInPlayer: media_id: withError:
@property(nonatomic,assign) BOOL openLoading;

/// 设置资源加载超时的时间/s （loading）默认8秒
@property(nonatomic,assign) NSTimeInterval timeoutInterval;

/// 是否打印调试log， 默认：NO不打印
@property(nonatomic,assign) BOOL isDebugLog;

/// 是否开启数据上报功能，默认：YES 统计操作数据
@property(nonatomic,assign) BOOL dataStatistics;


/// 单例管理类
+ (instancetype)playerManager;


/// 加载单个协议资源，仅加载协议数据前10秒的资源数据 （协议数据、图片、音频）
/// @param source   项目ID或协议地址
+ (void)requestResourceFromIvSource:(NSString*)source;


/// 加载多个协议数组资源，仅加载协议数据前10秒的资源数据 （协议数据、图片、音频）
/// @param sources   项目ID或协议地址
+ (void)requestResourceFromIvSources:(NSMutableArray<NSString*>*)sources;


/// SDK版本号, 双端统一
+ (NSString*)version;


/// build版本
+ (NSString*)build;


/// 获取缓存资源数据大小:单位/B（ 1G == 1000Mb == 1000 * 1000kb == 1000 * 1000 * 1000b）
+ (unsigned long long)getResourceFileSizeAtIVFilePath;


/// 删除所有IV资源缓存数据
+ (void)clearAllIVResourceFile;



@end

NS_ASSUME_NONNULL_END
