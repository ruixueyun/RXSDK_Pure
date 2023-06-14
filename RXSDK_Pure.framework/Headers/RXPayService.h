//
//  RXPayService.h
//  RXSDK
//
//  Created by 陈汉 on 2022/4/8.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXPayService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 是否开启storeKit2，默认不开启
 * ！storeKit2 限制 iOS15 以上使用
 */
- (void)setOpenStoreKit2:(BOOL)openStoreKit2;

/**
 * 设置重复下单间隔，单位秒（s），默认300s
 * 防止支付结果回调前重复下单导致订单验证错误
 */
- (void)setPayInterval:(NSInteger)interval;

/**
 * 下单
 {
 @"currency" : @"币种 默认传: CNY",
 @"goods_tag" : @"商品标签",
 @"trade_no" : @"订单号",
 @"env" : @"是否使用沙盒环境支付 0 正式 1 沙盒",
 @"type" : @"apple",
 @"indulge_auth" : @"是否进行防沉迷验证  0不验证，1验证，默认不验证",
 @"is_debug" : @"是否测试订单 默认0 正式  1为测试订单",
 @{ext} : @"支付扩展字段 三方支付额外传递参数",
 @"notify_url" : @"支付成功通知CP发货地址",
 @"transmit_args" : @"客户端透传参数 非必传"
 }
 */
- (void)requestWithDict:(NSDictionary *)dict completeHandle:(RequestComplete)handle;

/**
 * 查询是否需要补单
 */
- (BOOL)checkHasFailedOrder;

/**
 * 补单
 * @param maxCount 最大重试数，默认5次
 */
- (void)repayFailOrderWithMaxCount:(NSInteger)maxCount
                          complete:(RequestComplete)complete;

/**
 * 查询商品信息
 * @param productIdArr 商品id
 */
- (void)getProductInfoWithProductIdArr:(NSArray *)productIdArr
                              complete:(void(^)(NSArray<SKProduct *> *productInfoList))complete;

@end

NS_ASSUME_NONNULL_END
