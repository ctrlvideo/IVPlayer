//
//  IVPlayerManager.h
//  IVPlayer
//
//  Created by Di Guo on 2020/12/24.
//

#import <Foundation/Foundation.h>
#import<UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


//log日志输出类型，注意：优先级别0最高
typedef NS_OPTIONS(NSUInteger, IVPlayerLogTypes){
    IVPlayerLogTypeNormal  = 0,//不输出任何日志
    IVPlayerLogTypeAll     = 1 << 0,//输出所有日志
    IVPlayerLogTypeError   = 1 << 1,//只输出错误和故障信息
    IVPlayerLogTypeTime    = 1 << 2,//只输出seek和播放时间进度等信息
    IVPlayerLogTypeFlow    = 1 << 3,//只输出播放流程和断点等信息
    IVPlayerLogTypeFile    = 1 << 4,//只输出资源下载缓存等信息
};


@interface IVPlayerManager : NSObject

/// 渠道标识key，需求定制化channe标识，默认nil通用模式（暂预留）
@property(nonatomic,strong) NSString *channel;

/// 视频播放完成后是否回到起始点 默认：NO  如果 YES 视频播放完成后将回到0秒初始位置
@property(nonatomic,assign) BOOL goStartWhenFinish;

/// 图片资源未加载完成前的占位代替图
@property(nonatomic,strong) UIImage *placeholderImage;

/// 设置资源未加载完毕是否进入loading状态直到加载完成才继续播放，默认：NO忽略资源加载情况  YES将会等待资源再次加载结果
/// 如果再次加载失败将会触发IVPlayerDelegate代理通知回调videoResumeWhenResourceType: downloadFailInPlayer: media_id: withError:
@property(nonatomic,assign) BOOL openLoading;

/// 设置资源加载超时的时间/s （loading）默认8秒
@property(nonatomic,assign) NSTimeInterval timeoutInterval;

/// 是否输出调试日志， 默认：IVPlayerLogTypeNormal不打印
@property(nonatomic,assign) IVPlayerLogTypes logTypes;

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


/// SDK版本号（主流版本一般有重大更新才会变跟）
+ (NSString*)version;


/// build版本号 （bug修复或功能迭代版本号，值对应每个version版本从低到高依次递增）
+ (NSString*)build;


/// 获取缓存资源数据大小:单位/B（ 1G == 1000Mb == 1000 * 1000kb == 1000 * 1000 * 1000b）
+ (unsigned long long)getResourceFileSizeAtIVFilePath;


/// 删除所有IV资源缓存数据
+ (void)clearAllIVResourceFile;



@end

NS_ASSUME_NONNULL_END
