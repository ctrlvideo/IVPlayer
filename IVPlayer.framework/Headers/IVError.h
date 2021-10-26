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
 0 网络错误
 1 项目config_url为空或不存在
 2 项目ID为空或不存在
 3 播放时间错误    （播放器返回的时间范围错误）
 4 播控资源加载错误 （图片音频等资源下载错误）    [IVPlayerManager playerManager].openLoading == YES时有效
 5 视频资源加载错误 （播放器视频加载错误）
 6 设备系统版本过低，不支持运行
 7 项目已下架
 8 SDK版本过低，需要更新升级
 */


@interface IVError : NSObject


//便捷构建
+ (instancetype)errorWithCode:(NSInteger)code withMessage:(NSString*)message;
+ (instancetype)errorWithCode:(NSInteger)code withMessage:(NSString*)message error:(nullable NSError*)error;

//错误信息
@property(nonatomic,strong) NSString *message;
//错误码
@property(nonatomic,assign) NSInteger code;

//错误类型信息 (code：3、6、7、8时值为nil，1、2时可能为nil)
@property(nonatomic,strong,nullable) NSError *error;

@end

NS_ASSUME_NONNULL_END
