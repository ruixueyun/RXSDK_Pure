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
 "register"   // 短信意图-注册
 "bindphone" // 短信意图-绑定手机
 "unbindphone"// 短信意图-解绑手机
 "resetpwd"   // 短信意图-重置密码
 "bindemail" // 验证码意图 绑定邮箱
 "unbindemail"// 验证码意图 解绑邮箱
 "login"// 登录
 "setpwd"// 设置密码
 */
- (void)getCaptchaCodeWithType:(CaptchaType)type
                        target:(NSString *)target
                       purpose:(NSString *)purpose
                      complete:(RequestComplete)complete;

/**
 * 绑定邮箱
 * @param captchaCode 验证码
 * @param password 密码
 * @param email 邮箱
 */
- (void)bindingEmailWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              email:(NSString *)email
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
 * 绑定手机
 * @param captchaCode 验证码
 * @param password 密码
 * @param phone 手机号
 */
- (void)bindingPhoneWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              phone:(NSString *)phone
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
 * 修改密码
 * @param oldPwd 旧密码
 * @param newPwd 新密码
 */
- (void)updatePasswordWithOldPwd:(NSString *)oldPwd
                          newPwd:(NSString *)newPwd
                        complete:(RequestComplete)complete;

/**
 * 重置密码
 * @param username 用户名
 * @param password 密码
 * @param captchaCode 验证码
 */
- (void)resetPasswordWithUsername:(NSString *)username
                         password:(NSString *)password
                      captchaCode:(NSString *)captchaCode
                         complete:(RequestComplete)complete;

/**
 * 注册
 * @param extDic 扩展字段  非必须
 * @param username 账号注册为账号，手机注册为手机号，邮箱注册为邮箱  必须
 * @param password 密码  必须
 * @param captchaCode 验证码  必须
 * @param nickname 昵称  非必须
 * @param avatarUrl 头像地址  非必须
 * @param birthday 出生日期（例2000-01-01）  非必须
 * @param sex 性别,1:男,0:女  非必须
 * @param refereeid 推荐人id  非必须
 * @param registType 注册类型（1-普通账号注册，2-手机号注册，3-邮箱注册）：手机号注册必须填写验证码，邮箱注册必填验证码  必须
 */
- (void)registWithExtDic:(NSMutableDictionary * _Nullable)extDic
                username:(NSString *)username
                password:(NSString *)password
             captchaCode:(NSString *)captchaCode
                nickname:(NSString * _Nullable)nickname
               avatarUrl:(NSString * _Nullable)avatarUrl
                birthday:(NSString * _Nullable)birthday
                     sex:(NSString * _Nullable)sex
               refereeid:(NSString * _Nullable)refereeid
              registType:(RegistType)registType
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
 * 获取设备码
 */
- (NSString *)getDeviceIDInKeychain;

@end

NS_ASSUME_NONNULL_END
