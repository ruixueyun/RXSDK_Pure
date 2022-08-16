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
 * 检测客户端与服务器漏单情况处理
 */
+ (void)checkOrderStatus:(void (^)(BOOL success))result;

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
 * 查询商品信息
 * @param productIdArr 商品id
 */
- (void)getProductInfoWithProductIdArr:(NSArray *)productIdArr
                              complete:(void(^)(NSArray<SKProduct *> *productInfoList))complete;

@end

NS_ASSUME_NONNULL_END
