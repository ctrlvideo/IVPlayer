//
//  IVPlayerNodeModel.h
//  IVPlayer
//
//  Created by Di Guo on 2021/2/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


//播放器状态
typedef enum : NSUInteger {
    IVPlayerNodeProgressType,//进度片段
    IVPlayerNodeEventType,//事件片段
}IVPlayerNodeType;


@interface IVPlayerNodeModel : NSObject
//片段类型
@property(nonatomic,assign) IVPlayerNodeType  type;
//开始时间
@property(nonatomic,assign) float startTime;
//结束时间
@property(nonatomic,assign) float endTime;
//持续时长
@property(nonatomic,assign) float duration;
//所在数组的下标
@property(nonatomic,assign) int index;

//所在当前分支的时间 (只有通过getCurrentPlayingProgressInfoModel获取的本类对象该属性才有效)
@property(nonatomic,assign) float position;

//视频当前播放时间是否已进入此片段
@property(nonatomic,assign) bool onNode;

@end




NS_ASSUME_NONNULL_END
