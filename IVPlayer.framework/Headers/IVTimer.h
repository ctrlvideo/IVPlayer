//
//  IVTimer.h
//  IVPlayer
//
//  Created by Di Guo on 2021/8/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IVTimerDelegate <NSObject>
@optional
//计时更新通知
- (void)timeDidUpdateWithTime:(float)time;
//计时完成通知
- (void)timeDidFinishWithSkipTime:(float)skipTime object:(NSObject *)object type:(int)type;
@end

@interface IVTimer : NSObject

//中途暂停
- (void)suspend;

//继续运行
- (void)resume;

//停止
- (void)stop;

//开始运行到计时
- (void)startCountdownAndRunTime:(float)time;

//中途叠加时间
- (void)addTime:(float)time;

//设置当前时间
- (void)setTime:(float)time;

//计时器的频率，默认0.1 意思就是1秒执行10次，数值越小触发的频率越高
@property(nonatomic,assign) float frequency;

//记录当前是否正在运行计时器
@property(nonatomic,assign) BOOL runing;

//记录运行结束后跳转的时间点
@property(nonatomic,assign) float skip_time;

//记录对象信息
@property(nonatomic,strong) NSObject *object;

//当前计时的类型 0:seek，1:显示
@property(nonatomic,assign) int type;

//计时通知代理
@property(nonatomic,weak) id <IVTimerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
