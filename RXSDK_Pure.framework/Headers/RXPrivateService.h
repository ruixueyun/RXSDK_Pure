//
//  RXPrivateService.h
//  RXSDK
//
//  Created by 陈汉 on 2024/4/10.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXPrivateService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 发送失败通知
 * @note UIKit 专用
 */
- (void)postLoginError:(NSDictionary *)error
             loginType:(LoginType)loginType;

@end

NS_ASSUME_NONNULL_END
