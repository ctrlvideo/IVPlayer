//
//  IVPlayerDefine.h
//  IVPlayer
//
//  Created by Di Guo on 2020/12/24.
//

#import "IVPlayerManager.h"

#ifndef IVPlayerDefine_h
#define IVPlayerDefine_h

//播放器状态
typedef enum : NSUInteger {
    IVPlayerStatusInitialize = 0,//正在初始化
    IVPlayerStatusWaitingToPlay = 1,//等待播放：视频模型数据未初始化完成但用户点击了播放
    IVPlayerStatusPause = 2,//暂停
    IVPlayerStatusPlaying = 3,//播放中
    IVPlayerStatusFinished = 4,//播放完成
    IVPlayerStatusError = 5,//视频、协议数据加载错误，错误码对应IVPlayer代理通知的IVError
} IVPlayerStatus;


//服务器主机地址
#define KServer @"https://apiive-v3.ctrlvideo.com"
//视频协议URL
#define KGetVideoProtocolInfoUrl [NSString stringWithFormat:@"%@/player/ajax/get_ivideo_info/?project_id=",KServer]
//协议配置URL,pverVersion：当前协议的版本号，version：当前SDK的版本号
#define KVideoProtocolUrl(projectId,pverVersion,version) [NSString stringWithFormat:@"%@%@&pver=%@&version=%@",KGetVideoProtocolInfoUrl,projectId,pverVersion,version]
//数据上报URL
#define KPushVideoPlayInfoUrl [NSString stringWithFormat:@"%@/player/ajax/post_ivideo_action/",KServer]

//弱引用self
#define weakSelf(type)  __weak typeof(type) weak##type = type;

//日志输出
#define IVLog(type,...) if (!([IVPlayerManager playerManager].logTypes & IVPlayerLogTypeNormal)) if ([IVPlayerManager playerManager].logTypes & IVPlayerLogTypeAll || [IVPlayerManager playerManager].logTypes & type) NSLog(@"IVLog-%s第%d行:%@",__FILE_NAME__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])

#endif /* IVPlayerDefine_h */
