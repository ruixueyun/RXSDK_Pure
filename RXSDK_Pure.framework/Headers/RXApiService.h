//
//  RXApiService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/11/9.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    CaptchaType_email, // 邮箱
    CaptchaType_phone // 手机
} CaptchaType; // 验证码类型

@interface RXApiService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取验证码
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱）
 * @param purpose 用途
 "register"           // 注册
 "bindphone"      // 绑定手机
 "unbindphone"  // 解绑手机
 "resetpwd"        // 重置密码
 "bindemail"       // 绑定邮箱
 "unbindemail"   // 解绑邮箱
 "login"               // 登录
 "setpwd"           // 设置密码
 */
- (void)getCaptchaCodeWithType:(CaptchaType)type
                        target:(NSString *)target
                       purpose:(NSString *)purpose
                      complete:(RequestComplete)complete;

/**
 * 获取验证码
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！phone 手机号（phone/email二选一，不可同时传入）    #NSString类型
 * ！email 邮箱（phone/email二选一，不可同时传入）    #NSString类型
 * ！purpose 用图    #NSString类型
 "register"           // 注册
 "bindphone"      // 绑定手机
 "unbindphone"  // 解绑手机
 "resetpwd"        // 重置密码
 "bindemail"       // 绑定邮箱
 "unbindemail"   // 解绑邮箱
 "login"               // 登录
 "setpwd"           // 设置密码
 */
- (void)getCaptchaCodeWithParams:(NSDictionary *)params
                        complete:(RequestComplete)complete;

/**
 * 绑定邮箱
 * @param captchaCode 验证码
 * @param password 密码
 * @param email 邮箱
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingEmailWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              email:(NSString *)email
                       migrate_args:(id _Nullable)migrate_args
                           complete:(RequestComplete)complete;

/**
 * 绑定邮箱
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！captcha_code 验证码    #NSString类型
 * ！password 密码    #NSString类型
 * ！email 邮箱    #NSString类型
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingEmailWithParams:(NSDictionary *)params
                      complete:(RequestComplete)complete;

/**
 * 解绑邮箱
 * @param captchaCode 验证码
 * @param email 邮箱
 */
- (void)reliveBindingEmailWithCaptchaCode:(NSString *)captchaCode
                                    email:(NSString *)email
                                 complete:(RequestComplete)complete;

/**
 * 解绑邮箱
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！captcha_code 验证码    #NSString类型
 * ！email 邮箱    #NSString类型
 */
- (void)reliveBindingEmailWithParams:(NSDictionary *)params
                            complete:(RequestComplete)complete;

/**
 * 绑定手机
 * @param captchaCode 验证码
 * @param password 密码
 * @param phone 手机号
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingPhoneWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              phone:(NSString *)phone
                       migrate_args:(id _Nullable)migrate_args
                           complete:(RequestComplete)complete;

/**
 * 绑定手机
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！phone 手机号    #NSString类型
 * ！captcha_code 验证码    #NSString类型
 * ！password 密码    #NSString类型
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingPhoneWithParams:(NSDictionary *)params
                      complete:(RequestComplete)complete;

/**
 * 解绑手机
 * @param captchaCode 验证码
 * @param phone 手机号
 */
- (void)reliveBindingPhoneWithCaptchaCode:(NSString *)captchaCode
                                    phone:(NSString *)phone
                                 complete:(RequestComplete)complete;

/**
 * 解绑手机
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！phone 手机号    #NSString类型
 * ！captcha_code 验证码    #NSString类型
 */
- (void)reliveBindingPhoneWithParams:(NSDictionary *)params
                            complete:(RequestComplete)complete;

/**
 * 获取用户信息
 */
- (void)getUserInfoWithComplete:(RequestComplete)complete;

/**
 * 修改用户信息
 * @param avatarUrl 头像url 非必传
 * @param nickname 用户昵称 非必传
 * @param sex 性别 1男 0女 非必传
 * @param w_avatarurl 微信原始头像 非必传
 */
- (void)updateUserInfoWithAvatarUrl:(NSString *)avatarUrl
                           nickname:(NSString *)nickname
                                sex:(NSString *)sex
                        w_avatarurl:(NSString *)w_avatarurl
                           complete:(RequestComplete)complete;

/**
 * 修改用户信息
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！avatarurl 头像url    #NSString类型
 * ！nickname 用户昵称    #NSString类型
 * ！sex 性别 1男 0女    #NSInteger类型
 * ！wechat_avatarurl 微信原始头像    #NSString类型
 */
- (void)updateUserInfoWithParams:(NSDictionary *)params
                        complete:(RequestComplete)complete;

/**
 * 修改密码
 * @param oldPwd 旧密码
 * @param newPwd 新密码
 */
- (void)updatePasswordWithOldPwd:(NSString *)oldPwd
                          newPwd:(NSString *)newPwd
                        complete:(RequestComplete)complete;

/**
 * 修改密码
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！old_password 旧密码    #NSString类型
 * ！new_password 新密码    #NSString类型
 */
- (void)updatePasswordWithParams:(NSDictionary *)params
                        complete:(RequestComplete)complete;

/**
 * 重置密码
 * @param username 用户名
 * @param password 密码
 * @param captchaCode 验证码
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)resetPasswordWithUsername:(NSString *)username
                         password:(NSString *)password
                      captchaCode:(NSString *)captchaCode
                     migrate_args:(id _Nullable)migrate_args
                         complete:(RequestComplete)complete;

/**
 * 重置密码
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！username 用户名    #NSString类型
 * ！password 密码    #NSString类型
 * ！captcha_code 验证码    #NSString类型
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)resetPasswordWithParams:(NSDictionary *)params
                       complete:(RequestComplete)complete;

/**
 * 注册
 * @param username 账号注册为账号，手机注册为手机号，邮箱注册为邮箱  必须
 * @param password 密码  必须
 * @param captchaCode 验证码  手机或邮箱注册为必须，账号注册非必须
 * @param nickname 昵称  非必须
 * @param avatarUrl 头像地址  非必须
 * @param sex 性别,1:男,0:女  非必须
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)registWithUsername:(NSString *)username
                  password:(NSString *)password
               captchaCode:(NSString * _Nullable)captchaCode
                  nickname:(NSString * _Nullable)nickname
                 avatarUrl:(NSString * _Nullable)avatarUrl
                       sex:(NSString * _Nullable)sex
              migrate_args:(id _Nullable)migrate_args
                  complete:(RequestComplete)complete;

/**
 * 注册
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！username 账号注册为账号，手机注册为手机号，邮箱注册为邮箱    #NSString类型
 * ！password 密码    #NSString类型
 * ！nickname 昵称    #NSString类型
 * ！captcha_code 验证码    #NSString类型
 * ！avatarUrl 头像地址    #NSString类型
 * ！sex 性别,1:男,0:女    #NSInteger类型
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)registWithParams:(NSDictionary *)params
                complete:(RequestComplete)complete;

/**
 * 实名认证
 * @param realName 真实姓名  必须
 * @param idCard 身份证  必须
 */
- (void)approveWithRealName:(NSString *)realName
                     idCard:(NSString *)idCard
                   complete:(RequestComplete)complete;

/**
 * 实名认证
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！realname 真实姓名    #NSString类型
 * ！idcard 身份证    #NSString类型
 */
- (void)approveWithParams:(NSDictionary *)params
                 complete:(RequestComplete)complete;

/**
 * 获取设备码
 */
- (NSString *)getDeviceIDInKeychain;

@end

NS_ASSUME_NONNULL_END
