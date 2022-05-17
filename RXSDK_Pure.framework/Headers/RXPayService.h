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

/** 检测客户端与服务器漏单情况处理*/
+ (void)checkOrderStatus:(void (^)(BOOL success))result;

- (void)requestWithDict:(NSDictionary *)dict completeHandle:(RequestComplete)handle;

/**
 * 查询商品信息
 * @param productIdArr 商品id
 */
- (void)getProductInfoWithProductIdArr:(NSArray *)productIdArr
                              complete:(void(^)(NSArray<SKProduct *> *productInfoList))complete;

@end

NS_ASSUME_NONNULL_END
