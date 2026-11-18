//
//  RXIAPService.h
//  RXSDK
//
//  Created by 陈汉 on 2022/4/8.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXIAPService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 设置重复下单间隔，单位秒（s），默认300s
 * 防止结果回调前重复下单导致订单验证错误
 */
- (void)setInterval:(NSInteger)interval;

/**
 * iap
 {
    @"currency" : @"币种 默认传: CNY",
    @"goods_tag" : @"商品标签",
    @"trade_no" : @"订单号",
    @"env" : @"是否使用沙盒环境 0 正式 1 沙盒",
    @"indulge_auth" : @"是否进行防沉迷验证  0不验证，1验证，默认不验证",
    @"is_debug" : @"是否测试订单 默认0 正式  1为测试订单",
    @"ext" :{ @"扩展字段"},
    @"notify_url" : @"通知CP发货地址",
    @"transmit_args" : @"客户端透传参数 非必传"
 }
 */
- (void)iap:(NSDictionary *)dict complete:(RequestComplete)complete;

/**
 * iap
 {
    @"currency" : @"币种 默认传: CNY",
    @"goods_tag" : @"商品标签",
    @"trade_no" : @"订单号",
    @"env" : @"是否使用沙盒环境 0 正式 1 沙盒",
    @"indulge_auth" : @"是否进行防沉迷验证  0不验证，1验证，默认不验证",
    @"is_debug" : @"是否测试订单 默认0 正式  1为测试订单",
    @"ext" :{ @"扩展字段"},
    @"notify_url" : @"通知CP发货地址",
    @"transmit_args" : @"客户端透传参数 非必传"
 }
 */
- (void)requestWithDict:(NSDictionary *)dict completeHandle:(RequestComplete)handle DEPRECATED_MSG_ATTRIBUTE("use pay:complete: instead");

/**
 * 查询是否需要补单
 */
- (BOOL)checkHasFailedOrder;

/**
 * storekit2 查询
 */
- (void)sk2UnfinishUncompletedTransactionsWithOrderInfo:(NSDictionary *)orderInfo
                                         completeHandle:(RequestComplete)handle;

/**
 * 补单
 * @param maxCount 最大重试数，默认5次
 */
- (void)reFailOrderWithMaxCount:(NSInteger)maxCount
                       complete:(RequestComplete)complete;

/**
 * 查询商品信息
 * @param productIdArr 商品id
 */
- (void)getProductInfoWithProductIdArr:(NSArray *)productIdArr
                              complete:(void(^)(NSArray<SKProduct *> *productInfoList))complete;

/**
 * 获取初始化保存的计费点
 */
- (NSDictionary *)getProductInfo;

/**
 * 获取地区 货币符号
 * @param productId 商品 id
 * @param timeout 请求超时时间，默认 2 秒，小于 0 为默认时间
 */
- (void)getLocaleIdentifierWithProductId:(NSString *)productId
                                 timeout:(NSInteger)timeout
                                complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
