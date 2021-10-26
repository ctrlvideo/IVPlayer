//
//  IVPlayerDefine.h
//  IVPlayer
//
//  Created by Di Guo on 2020/12/24.
//

#import <IVPlayer/IVPlayerManager.h>

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
//#define KServer @"https://apiivetest.ctrlvideo.com"
#define KServer @"https://apiive.ctrlvideo.com"
//视频协议地址
#define KGetVideoProtocolInfoUrl [NSString stringWithFormat:@"%@/player/ajax/get_ivideo_info/?project_id=",KServer]
//定义项目配置地址URL,pverVersion需要请求版本的协议，version当前SDK的版本
#define KVideoProtocolUrl(projectId,pverVersion,version) [NSString stringWithFormat:@"%@%@&pver=%@&version=%@",KGetVideoProtocolInfoUrl,projectId,pverVersion,version]

//弱引用self
#define weakSelf(type)  __weak typeof(type) weak##type = type;

//屏幕尺寸
#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
//导航栏+状态高度
#define KStatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#define KNaviStatusBarHeight (KStatusBarHeight + 44)


//日志输出
#define IVLog(...) if([IVPlayerManager playerManager].isDebugLog) NSLog(@"IVLog-%s第%d行:%@",__FILE_NAME__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])



#endif /* IVPlayerDefine_h */
