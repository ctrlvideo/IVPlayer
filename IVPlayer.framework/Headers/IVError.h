//
//  IVError.h
//  IVPlayer
//
//  Created by Di Guo on 2020/11/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 错误码code：
 
 
 ****** 以下错误项目无法正常运行，视频播放会终止 ******
 1  请求协议数据异常，网络错误                                       --请求协议数据失败时抛出
 2  项目config_url为空或不存在(或本地zip资源解析失败)                 --初始化项目失败时抛出
 3  项目projectId为空或不存在                                      --初始化项目失败时抛出
 4  播放时间错误    （播放器返回的时间范围错误）                       --播放视频的时间和协议数据的时间不匹配
 5  视频资源加载错误 （播放器视频加载错误）                            --播放器的视频播放错误时上报的
 6  设备系统版本过低，不支持运行                                     --当前运行的iOS设备系统过低时抛出，目前最低支持iOS9
 7  项目已下架                                                    --初始化协议时检测到项目已下架无法播放
 8  SDK版本过低，需要更新升级                                       --初始化协议时检测到SDK版本低于协议数据版本抛出
 
 
 ****** 以下错误项目可以正常运行，但功能会异常 ******
 100  播控资源加载错误                                            --请求资源文件错误时，需要开启openLoading属性才抛出
 101  未开启录音权限                                             --语音识别事件出现时检测到设备未开通权限异常时抛出
 102  未开启语音识别权限                                          --语音识别事件出现时检测到设备未开通语音识别权限异常时抛出
 103  未开启相机权限                                             --手势识别事件出现时检测到设备未开通权限异常时抛出
 104  数据提交失败                                               --表单、投票、统计等数据提交失败时抛出
 105  语音识别失败                                               --语音识别功能开启异常，可能数据错误或硬件错误导致
 106  语音评测功能异常                                            --语音评测功能开启异常，权限功能或数据异常
 
 */


@interface IVError : NSObject
//错误信息
@property(nonatomic,strong) NSString *message;
//错误码
@property(nonatomic,assign) NSInteger code;

//系统抛出的错误信息
@property(nonatomic,strong,nullable) NSError *error;


//便捷构建
+ (instancetype)errorWithCode:(NSInteger)code withMessage:(NSString*)message;
+ (instancetype)errorWithCode:(NSInteger)code withMessage:(NSString*)message error:(nullable NSError*)error;


@end

NS_ASSUME_NONNULL_END
