//
//  IVEventCallModel.h
//  IVPlayer
//
//  Created by Di Guo on 2020/12/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class IVEventCallSpotEventModel;
@class IVEventCallSpotOptionModel;


@interface IVEventCallModel : NSObject

/*type: 决定当前类对应的类型
 0互动点信息     IVEventCallSpotModel
 1互动曝光信息   IVEventCallExposureModel
 2互动操作信息   IVEventCallOperateModel
 
 信息内容说明：根据callType对本类做实例类型转换
 callType == 0 当前类实例类型为IVEventCallSpotModel 且只在项目初始化完成时调用一次
 callType == 1 当前类实例类型为IVEventCallExposureModel 每当视频时间播放到互动事件时间点时触发
 callType == 2 当前类实例类型为IVEventCallOperateModel  每当用户操作互动事件按钮时或被动事件触发时通知
 */
@property(nonatomic,assign) NSInteger callType;

@end


//互动点信息-简洁模型
@interface IVEventCallSpotModel : IVEventCallModel

//项目ID
@property(nonatomic,strong) NSString *project_id;
//访客唯一id
@property(nonatomic,strong) NSString *guest_id;
//事件信息数组
@property(nonatomic,strong) NSArray <IVEventCallSpotEventModel*> *event_info;
@end

//事件模型
@interface IVEventCallSpotEventModel : NSObject
//开始时间
@property(nonatomic,assign) float start_time;
//结束时间
@property(nonatomic,assign) float end_time;
//持续时间
@property(nonatomic,assign) float duration;
//事件ID
@property(nonatomic,strong) NSString *event_id;
//事件名称
@property(nonatomic,strong) NSString *name;
//事件类型
@property(nonatomic,strong) NSString *type;
//控件数组
@property(nonatomic,strong) NSArray <IVEventCallSpotOptionModel*> *options;

@end

//控件模型
@interface IVEventCallSpotOptionModel : NSObject
//控件名称
@property(nonatomic,strong) NSString *option_name;
//控件ID
@property(nonatomic,strong) NSString *option_id;
//控件文本内容
@property(nonatomic,strong) NSString *text;

@end



//互动点曝光-简洁模型
@interface IVEventCallExposureModel : IVEventCallModel
//事件ID
@property(nonatomic,strong) NSString *event_id;
//事件名称
@property(nonatomic,strong) NSString *name;
//事件类型
@property(nonatomic,strong) NSString *type;

@end





//互动操作-简洁模型
@interface IVEventCallOperateModel : IVEventCallModel
//事件ID
@property(nonatomic,strong) NSString *event_id;
//事件名称
@property(nonatomic,strong) NSString *name;
//事件类型
@property(nonatomic,strong) NSString *type;
//用户行为还是被动触发 YES:用户行为 NO:被动触发
@property(nonatomic,assign) bool factitious;
//成功失败类事件操作结果 -1选择 0失败 1成功
@property(nonatomic,assign) int branch;
//控件操作的ID
@property(nonatomic,strong) NSString *option_id;
//控件操作的名称
@property(nonatomic,strong) NSString *option_name;

@end






NS_ASSUME_NONNULL_END
