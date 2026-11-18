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


#pragma mark - 将 三方返回的 登录、分享，以及一些客户端错误码上报到大数据中
/**
 * 将三方返回的 登录、分享，以及一些客户端错误码上报到大数据中，此方法仅上传请求底层，报错后瑞雪code < 2000的网络错误
 * request 请求对象
 * parameters 请求参数
 * headers 请求头
 * requestType 请求类型
 * thirdType 三方类型
 * error 错误
 *
 */
+ (void)addErrorLogWithRequest:(NSMutableURLRequest *)request
                    parameters:(id)parameters
                       headers:(nullable NSDictionary <NSString *, NSString *> *)headers
                   requestType:(NSString *)requestType
                     thirdType:(NSString *)thirdType
                         error:(NSError * _Nullable)error;

/**
 * 将 三方返回的 登录、分享，以及一些客户端错误码上报到大数据中
 * @param headerDic 请求头
 * @param bodyDic 请求体
 * @param action 动作
 * @param url 请求地址
 * @param type 三方类型
 * @param code 错误码
 * @param msg 错误信息
 * @param thirdcode 三方错误码,无值则传-123
 * @param thirdmsg 三方错误信息
 * @param traceid 唯一标识
 *
 */
- (void)addErrorMsgWithRequestHeader:(NSDictionary *)headerDic
                             bodyDic:(NSDictionary *)bodyDic
                              action:(NSString *)action
                                 url:(NSString *)url
                                code:(NSInteger)code
                                 msg:(NSString *)msg
                           thirdType:(NSString *)type
                           thirdcode:(NSInteger)thirdcode
                            thirdmsg:(NSString *)thirdmsg
                             traceid:(NSString *)traceid;

/**
 * 将 三方返回的 登录、分享，以及一些客户端错误码上报到大数据中
 * @param headerDic 请求头
 * @param bodyDic 请求体
 * @param action 动作
 * @param url 请求地址
 * @param type 三方类型
 * @param code 错误码
 * @param msg 错误信息
 * @param thirdcode 三方错误码
 * @param thirdmsg 三方错误信息
 * @param traceid 唯一标识
 */
- (void)trackErrorPrivateMsgWithRequestHeader:(NSDictionary *)headerDic
                                      bodyDic:(NSDictionary *)bodyDic
                                       action:(NSString *)action
                                          url:(NSString *)url
                                         code:(NSInteger)code
                                          msg:(NSString *)msg
                                    thirdType:(NSString *)type
                                    thirdcode:(NSInteger)thirdcode
                                     thirdmsg:(NSString *)thirdmsg
                                      traceid:(NSString *)traceid
                                   properties:(NSDictionary *)properties;

@end

NS_ASSUME_NONNULL_END
