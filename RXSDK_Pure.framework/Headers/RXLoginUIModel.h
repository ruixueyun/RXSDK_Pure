//
//  RXLoginUIModel.h
//  RXSDK
//
//  Created by 陈汉 on 2023/12/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LoginModeNormal = 0, // 常规模式
    LoginModeQuick = 1,   // 快速模式
} LoginMode;

@interface RXLoginUIModel : NSObject
/**
 * @note 要配置的登录类型，按照数组顺序展示
 * wechat          微信
 * visitor            游客登录
 * apple             苹果登录
 * account         账号登录
 * captchacode 验证码登录
 * quickphone   一键登录
 */
@property (nonatomic, strong) NSArray *loginMethods;
/**
 * 协议地址，顺序为 0位用户协议，1位隐私协议
 */
@property (nonatomic, strong) NSArray *privacies;
/**
 * 协议显示名称，顺序为 0位用户协议，1位隐私协议
 */
@property (nonatomic, strong) NSArray *privacieTitles;
/**
 * 登录显示的logo
 */
@property (nonatomic, strong) UIImage *logoImage;
/**
 * 登录页是否显示关闭按钮，默认显示
 */
@property (nonatomic, assign) BOOL isShowClose;
/**
 * 显示账号密码登录或验证码登录，0 账号密码登录  1 验证码登录  默认验证码登录
 */
@property (nonatomic, assign) NSInteger loginViewType;
/**
 * 账号密码登录方式键盘类型，1 全键盘  2 数字键盘 3 邮箱键盘  默认全键盘
 */
@property (nonatomic, assign) NSInteger keyboardType;
/**
 * 实名认证地区
 * @note 海外根据不同地区展示不同样式的实名认证 UI，默认 姓名+身份证样式，目前支持 VN（越南地区样式）
 */
@property (nonatomic, strong) NSString *realAuthRegion;
/**
 * 验证码登录的新用户是否弹出设置密码，默认不弹出
 * @note 弹出设置密码后登录数据将在设置成功或关闭设置页面后返回
 */
@property (nonatomic, assign) BOOL setFirstNeedSetPassword;
/**
 * 是否显示底部快速登录按钮，默认显示
 */
@property (nonatomic, assign) BOOL setQuickButtonBarVisible;
/**
 * 处于注销中的用户登录后是否显示注销窗口，默认不显示
 */
@property (nonatomic, assign) BOOL setDeregisterShow;
/**
 * 如果账号在注销中是继续登录还是退出登录
 * YES 继续登录 | NO 退出登录
 */
@property (nonatomic, assign) BOOL setLoginContinue;
/**
 * 自定义参数
 */
@property (nonatomic, strong) NSDictionary *setCustomParams;
/**
 * 自定义透传参数
 */
@property (nonatomic, strong) NSDictionary *setCustomExt;
/**
 * 微信appid
 * @note 使用微信登录必传
 */
@property (nonatomic, strong) NSString *wxAppid;
/**
 * 一键登录客户端秘钥
 * @note 使用一键登录必传
 */
@property (nonatomic, strong) NSString *quickphoneKey;
/**
 * 快速开始登录方式显示名称
 * @note 默认显示 “快速开始”
 */
@property (nonatomic, strong) NSString *guestTitle;
/**
 * google登录客户端秘钥
 * @note 使用google登录必传
 */
@property (nonatomic, strong) NSString *googleClientid;
/**
 * FaceBook、Line登录权限数组
 * @note 使用FaceBook、Line登录必传
 */
@property (nonatomic, strong) NSArray *permissionsArray;
/**
 * 是否隐藏邮箱注册按钮，YES 隐藏  NO 不隐藏，默认 NO
 */
@property (nonatomic, assign) BOOL closeEmailRegister;
/**
 * 是否为审核模式
 * @note 审核模式只展示苹果登录，且和正常样式不同
 */
@property (nonatomic, assign) BOOL isAudit;
/**
 * 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  
 */
@property (nonatomic, strong) NSArray *signFields;
/**
 * 任意合法的 json 类型, 比如 string, number，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP
 */
@property (nonatomic, assign) id migrateArgs;
/**
 * 二次登录 loginOpenid
 * @note 传入 method 和 loginOpenid 后将不会拉起登录 UI，直接调用二次登录，登录失效会默认进行授权登录
 */
@property (nonatomic, strong) NSString *loginOpenid;
/**
 * 二次登录 method
 * @note 传入 method 和 loginOpenid 后将不会拉起登录 UI，直接调用二次登录，登录失效会默认进行授权登录
 */
@property (nonatomic, strong) NSString *method;

@end

NS_ASSUME_NONNULL_END
