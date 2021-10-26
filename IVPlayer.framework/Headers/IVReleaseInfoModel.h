//
//  IVReleaseInfoModel.h
//  IVPlayer
//
//  Created by Di Guo on 2020/11/24.
//

#import <Foundation/Foundation.h>
@class IVReleaseParamsModel;
@class IVReleaseControllerModel;
@class IVReleaseControllerCustomModel;

NS_ASSUME_NONNULL_BEGIN

@interface IVReleaseInfoModel : NSObject

//项目ID
@property(nonatomic,strong) NSString *project_id;
//功能版本号，向下兼容
@property(nonatomic,strong) NSString *sdk_version;
//视频播放器url
@property(nonatomic,strong) NSString *url;
//项目是否已下架 NO已下架  YES正常
@property(nonatomic,assign) bool is_show;
//视频基础参数
@property(nonatomic,strong) IVReleaseParamsModel *v_params;
//播放器标题
@property(nonatomic,strong) NSString *player_title;
//播放器cover封面
@property(nonatomic,strong) NSString *player_cover;
//播控设置对象
@property(nonatomic,strong) IVReleaseControllerModel *player_controller;
//视频关键帧信息，兼容部分Web播放器
@property(nonatomic,strong) NSString *real_keyframes;
//播放器显示创作者
@property(nonatomic,strong) NSString *author;
//互动视频访问密码
@property(nonatomic,strong) NSString *access_password;
//分享标题
@property(nonatomic,strong) NSString *share_title;
//分享描述
@property(nonatomic,strong) NSString *share_desc;
//分享描述
@property(nonatomic,strong) NSString *share_thumb;

@end


@interface  IVReleaseParamsModel : NSObject

//视频时长
@property(nonatomic,assign) float duration;
//视频宽度
@property(nonatomic,assign) int width;
//视频高度
@property(nonatomic,assign) int height;
//视频帧率
@property(nonatomic,assign) int fps;
//视频的码率
@property(nonatomic,assign) int v_bitRate;

@end


@interface IVReleaseControllerModel : NSObject

//显示开始按钮
@property(nonatomic,assign) bool show_start_btn;
//显示标题
@property(nonatomic,assign) bool show_title;
//显示播放暂停按钮
@property(nonatomic,assign) bool show_playPause_btn;
//显示前进后退15秒
@property(nonatomic,assign) bool show_skip15Second_btn;
//显示倍速
@property(nonatomic,assign) bool show_multiSpeed_btn;
//显示前后互动点功能
@property(nonatomic,assign) bool show_fbPoint_btn;
//显示进度条
@property(nonatomic,assign) bool show_seekbar;
//显示作者
@property(nonatomic,assign) bool show_author;
//外链返回后播放原节点
@property(nonatomic,assign) bool back_recovery_play;
//隐藏水印
@property(nonatomic,assign) bool hidden_watermark;
//水印链接URL
@property(nonatomic,strong) NSString *custom_watermark_url;
//是否自定义样式
@property(nonatomic,assign) bool is_custom_style;
//自定义样式对象
@property(nonatomic,strong) IVReleaseControllerCustomModel *custom_style;

@end


@interface IVReleaseControllerCustomModel : NSObject

//开始图标
@property(nonatomic,strong) NSString *start_icon;
//播放图标
@property(nonatomic,strong) NSString *play_icon;
//暂停图标
@property(nonatomic,strong) NSString *pause_icon;
//进度条颜色 例如：rgba(119, 224, 255, 1):rgba(83, 152, 248, 1)
@property(nonatomic,strong) NSString *seekbar_color;
//解析出来的进度条颜色数组
@property(nonatomic,strong) NSArray *seekbar_color_array;

@end


NS_ASSUME_NONNULL_END
