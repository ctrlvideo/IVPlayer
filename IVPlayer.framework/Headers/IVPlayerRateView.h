//
//  IVPlayerRateView.h
//  IVPlayer
//
//  Created by Di Guo on 2021/4/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class IVPlayerRateTableViewCell;
@class IVPlayerRateModel;


@protocol IVPlayerRateViewDelegate <NSObject>
//点击速率通知
- (void)playerRateViewDidClickListWithModel:(IVPlayerRateModel*)model;

@end


@interface IVPlayerRateView : UIView <UITableViewDelegate,UITableViewDataSource>
//背景view
@property(nonatomic,strong) UIView *backView;
//速率列表
@property(nonatomic,strong) UITableView *tableView;
//速率列表
@property(nonatomic,strong) NSArray *rates;
//当前选中的速率item
@property(nonatomic,strong) IVPlayerRateModel *rateModel;
//代理
@property(nonatomic,weak) id <IVPlayerRateViewDelegate> delegate;

@end


@interface IVPlayerRateTableViewCell : UITableViewCell

//数据源模型
@property(nonatomic,strong) IVPlayerRateModel *rateModel;
//列表标题
@property(nonatomic,strong) UILabel *title;

@end


@interface IVPlayerRateModel : NSObject

//标题
@property(nonatomic,strong) NSString *title;
//速率值
@property(nonatomic,assign) CGFloat rate;
//当前是否选中
@property(nonatomic,assign) BOOL isSelected;

@end



NS_ASSUME_NONNULL_END
