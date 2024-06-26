//
//  RXPublicHeader.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/7.
//


#ifndef RXPublicHeader_h
#define RXPublicHeader_h


#import "RX_CommonRequestError.h"
#import "RXSdkInitConfig.h"

typedef enum {
    RegistTypeAccount = 1, // 账号注册
    RegistTypePhone,  // 手机号注册
    RegistTypeEmail  // 邮箱注册
} RegistType;

typedef enum {
    LoginTypeVisitor,  // 游客登录
    LoginTypeAccount,  // 账号登录
    LoginTypeEmail,    // 邮箱登录
    LoginTypeAuth,     // 本机一键登录
    LoginTypeW,        // 微信登录
    LoginTypeApple,    // 苹果登录
    LoginTypeQuick,    // 二次登录
    LoginTypeGoogle,   // 谷歌登录
    LoginTypeFacebook, // facebook登录
    LoginTypeVirtual,  // 虚拟登录
    LoginTypeCapCode,  // 验证码登录
    LoginTypeLine,     // line登录
    LoginTypeZalo,     // zalo登录
    LoginTypeTikTok,   // tiktok登录
    LoginTypeSnapChat, // snapChat登录
    LoginTypeInstagram,// instagram登录
    LoginTypeReddit,   // reddit登录
    LoginTypeDefault   // 自定义登录
} LoginType;

typedef enum : NSUInteger {
    Default = 0,      // 默认 6-32 位任意字符
    Custom = 1,       // 自定义密码正则
    Average = 2,      // 简易密码， 6-32 位任意字符
    Strong = 3,       // 强密码，  6-32 位，包含数字+字母+特殊符号
} RXPasswordStrength;

typedef void(^RequestComplete)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error);


#pragma mark -- track key
static NSString * _Nullable const rxlog_version_check_process = @"#version_check_process";  // 版本检查
static NSString * _Nullable const rxlog_login_page_show = @"#login_page_show";              // 展示登录 UI
static NSString * _Nullable const rxlog_login_page_hide = @"#login_page_hide";              // 关闭登录 UI
static NSString * _Nullable const rxlog_agreement_process = @"#agreement_process";          // 隐私协议
static NSString * _Nullable const rxlog_login_process = @"#login_process";                  // 登录流程

#endif /* RXPublicHeader_h */
