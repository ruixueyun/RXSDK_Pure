//
//  RXPayService.h
//  RXSDK
//
//  Created by 陈汉 on 2022/4/8.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
