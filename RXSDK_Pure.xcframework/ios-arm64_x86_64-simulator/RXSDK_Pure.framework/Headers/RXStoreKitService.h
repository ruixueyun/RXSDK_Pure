//
//  RXStoreKitService.h
//  RXSDK
//
//  Created by 陈汉 on 2023/7/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXStoreKitService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 应用内拉起App页面评分
 * @param complete 点击完成或取消回调
 * 注意：此处点击完成并不代表用户已经完成评分，仅监听VC dismiss
 */
- (void)inAppStoreReview:(NSString *)appid
                complete:(void(^)(void))complete;

/**
 * 跳转到App Store评分
 * @param writeReview 是否直接拉起评论页
 */
- (void)toAppStoreReview:(NSString *)appid
             writeReview:(BOOL)writeReview;

/**
 * 应用内评分弹框
 */
- (void)alertAppReview;

@end

NS_ASSUME_NONNULL_END
