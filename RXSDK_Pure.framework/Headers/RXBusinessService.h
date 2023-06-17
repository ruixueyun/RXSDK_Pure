//
//  RXBusinessService.h
//  RXSDK
//
//  Created by 陈汉 on 2023/5/27.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RXBusinessDelegate <NSObject>
/**
 * 商业化窗口数据回调
 * @param response 返回数据，失败返回nil
 * @param error 错误返回，成功返回nil
 */
- (void)businessCallBackWithResponse:(NSDictionary * _Nullable)response error:(RX_CommonRequestError *)error;

@end

@interface RXBusinessService : NSObject

@property (nonatomic, weak) id <RXBusinessDelegate> delegate;

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取商业化窗口全量数据，数据通过delegate回调
 */
- (void)getAllBusinessData;

/**
 * 获取指定商业化窗口数据，数据通过delegate回调
 * @param window_key 窗口key
 * @param event 事件
 * @param before_event 前置事件
 */
- (void)getBusinessDataWithWindow_key:(NSString *)window_key
                                event:(NSString *)event
                         before_event:(NSString * _Nullable)before_event;

/**
 * 更新商业化窗口数据
 * 用于立即更新商业化窗口数据
 * ！！！商业化窗口数据会定时更新，请谨慎使用本接口，避免造成资源浪费！！！
 */
- (void)refreshBusinessData;

@end

NS_ASSUME_NONNULL_END