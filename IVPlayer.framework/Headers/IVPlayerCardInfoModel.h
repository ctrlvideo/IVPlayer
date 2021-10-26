//
//  IVPlayerCardInfoModel.h
//  IVPlayer
//
//  Created by Di Guo on 2021/5/26.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IVPlayerCardInfoModel : NSObject

//头像：支持UIImage、NSString地址，（如果传入类型是NSString默认是URL地址，而不是Assets里的资源名称）
@property(nonatomic,strong) id iconImage;
//头像占位图，资源未加载完成前的代替图
@property(nonatomic,strong) UIImage *placeholderImage;
//昵称
@property(nonatomic,strong) NSString *nickName;
//文本信息
@property(nonatomic,strong) NSString *text;

@end

NS_ASSUME_NONNULL_END
