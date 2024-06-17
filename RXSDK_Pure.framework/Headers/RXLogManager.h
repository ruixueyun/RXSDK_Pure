//
//  RXLogManager.h
//  RXSDK-Pure
//
//  Created by 陈汉 on 2024/6/14.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"
#import "RXApiService.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXLogManager : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 添加登录日志
 */
- (void)addLoginLogWithLoginType:(LoginType)loginType
                       errorInfo:(NSDictionary *)errorInfo;

/**
 * 添加注册日志
 */
- (void)addRegisterLogWithErrorInfo:(NSDictionary *)errorInfo;

/**
 * 添加获取验证码日志
 */
- (void)addCaptchaCodeLogWithPurpose:(NSString *)purpose
                           errorInfo:(NSDictionary *)errorInfo;

/**
 * 添加校验验证码日志
 */
- (void)addVerifyCaptchaCodeLogWithErrorInfo:(NSDictionary *)errorInfo
                                        type:(CaptchaType)type;

/**
 * 添加三方授权日志
 */
- (void)addThirdLoginLogWithLoginType:(LoginType)loginType
                                begin:(BOOL)begin
                            errorInfo:(NSDictionary *)errorInfo;

@end

NS_ASSUME_NONNULL_END
