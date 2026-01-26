//
//  RXLoginConfig.h
//  RXSDK
//
//  Created by Auto Generated on 2026/1/22.
//
//  登录配置类，封装登录请求所需的所有参数

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXLoginConfig : NSObject

#pragma mark - 必须参数

/**
 * 登录类型
 * @note 必须设置
 * 支持的登录类型:
 * - LoginTypeVisitor: 游客登录
 * - LoginTypeAccount: 账号密码登录
 * - LoginTypeCapCode: 验证码登录
 * - LoginTypeApple: 苹果登录
 * - LoginTypeW: 微信登录
 * - LoginTypeGoogle: Google 登录
 * - LoginTypeFacebook: Facebook 登录
 * - LoginTypeLine: Line 登录
 * - LoginTypeAuth: 一键登录
 * - LoginTypeZalo: Zalo 登录
 * - LoginTypeTikTok: TikTok 登录
 * - LoginTypeSnapChat: SnapChat 登录
 */
@property (nonatomic, assign) LoginType loginType;

#pragma mark - 账号密码登录参数

/**
 * 用户名/手机号/邮箱
 * @note 账号密码登录、验证码登录时必传，其他登录方式可传空
 */
@property (nonatomic, copy, nullable) NSString *username;

/**
 * 密码
 * @note 账号密码登录时必传，其他登录方式可传空
 */
@property (nonatomic, copy, nullable) NSString *password;

#pragma mark - 验证码登录参数

/**
 * 验证码
 * @note 验证码登录时必传，其他登录方式可传空
 */
@property (nonatomic, copy, nullable) NSString *captchaCode;

#pragma mark - 三方登录参数

/**
 * 权限数组
 * @note Facebook、Line 登录时必传，其他登录方式可传空
 */
@property (nonatomic, strong, nullable) NSArray *permissions;

#pragma mark - 二次登录参数

/**
 * 二次登录 openId
 * @note nil 或空为普通登录，传入有效值则进行二次登录
 */
@property (nonatomic, copy, nullable) NSString *loginOpenId;

#pragma mark - 扩展参数

/**
 * 扩展字段
 * @note 可传 nil
 * - reconnect_login: 断线重连时传 YES
 */
@property (nonatomic, strong, nullable) NSMutableDictionary *extDic;

/**
 * 签名字段
 * @note 指定对登录成功后返回的特定字段使用 CPKEY 计算签名
 * 支持的字段包括: nickname, avatar, openid, region, sex, age
 * 示例: @[@"nickname", @"avatar"]
 */
@property (nonatomic, strong, nullable) NSArray *signFields;

/**
 * 账号迁移参数
 * @note 任意合法的 json 类型, 比如 string, number
 * 调用 CP account-query 及 account-queryandbind 接口时透传给 CP
 */
@property (nonatomic, strong, nullable) id migrateArgs;

@end

NS_ASSUME_NONNULL_END
