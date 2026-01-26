//
//  RXSDK.h
//  RXSDK
//
//  Created by Auto Generated on 2026/1/20.
//
//  统一 SDK 入口类，封装所有 Public 服务方法

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>
#import "RXPublicHeader.h"
#import "RXError.h"
#import "RXSdkInitConfig.h"
#import "RXShareConfig.h"
#import "RXCustomShareConfig.h"
#import "RXDeregisterConfig.h"
#import "RXLoginConfig.h"
#import "RXApiService.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 回调类型定义

typedef void(^RXSDKRequestComplete)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error);
typedef void(^RXSDKShareCallBack)(BOOL success);

#pragma mark - RXSDK 接口类

@interface RXSDK : NSObject

#pragma mark - 单例

/**
 * 获取 SDK 实例（单例）
 */
+ (instancetype)sharedSDK;

#pragma mark - ==================== 初始化 ====================

/**
 * 初始化 SDK（配置对象）
 * 初始化后会 SDK 会自动激活
 * @param config 初始化配置
 * @param complete 初始化结果回调
 */
- (void)initWithConfig:(RXSdkInitConfig *)config
              complete:(RXSDKRequestComplete)complete;

/**
 * 用户激活
 * @param sourceAd 扩展信息
 * @param complete 激活结果回调
 */
- (void)requestActivatedWithSourceAd:(NSDictionary * _Nullable)sourceAd
                            complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 登录 ====================

/**
 * 登录请求（配置对象方式，推荐）
 * @param config 登录配置
 * @param complete 登录结果回调
 *
 * @example 游客登录
 * RXLoginConfig *config = [[RXLoginConfig alloc] init];
 * config.loginType = LoginTypeVisitor;
 * [[RXSDK sharedSDK] loginWithConfig:config complete:^(NSDictionary *response, RX_CommonRequestError *error) { }];
 *
 * @example 账号密码登录
 * RXLoginConfig *config = [[RXLoginConfig alloc] init];
 * config.loginType = LoginTypeAccount;
 * config.username = @"user";
 * config.password = @"password";
 * [[RXSDK sharedSDK] loginWithConfig:config complete:^(NSDictionary *response, RX_CommonRequestError *error) { }];
 *
 * @example 验证码登录
 * RXLoginConfig *config = [[RXLoginConfig alloc] init];
 * config.loginType = LoginTypeCapCode;
 * config.username = @"13800138000";
 * config.captchaCode = @"123456";
 * [[RXSDK sharedSDK] loginWithConfig:config complete:^(NSDictionary *response, RX_CommonRequestError *error) { }];
 *
 * @example 苹果登录
 * RXLoginConfig *config = [[RXLoginConfig alloc] init];
 * config.loginType = LoginTypeApple;
 * [[RXSDK sharedSDK] loginWithConfig:config complete:^(NSDictionary *response, RX_CommonRequestError *error) { }];
 *
 * @example 二次登录
 * RXLoginConfig *config = [[RXLoginConfig alloc] init];
 * config.loginType = LoginTypeApple;
 * config.loginOpenId = @"xxx";
 * [[RXSDK sharedSDK] loginWithConfig:config complete:^(NSDictionary *response, RX_CommonRequestError *error) { }];
 */
- (void)loginWithConfig:(RXLoginConfig *)config
               complete:(RXSDKRequestComplete)complete;

/**
 * 获取法务配置信息
 */
- (void)getLegalInfo:(RXSDKRequestComplete)complete;

/**
 * 自定义请求
 * @param url 接口名
 * @param header 请求头
 * @param body 请求参数
 * @param method 请求类型 1 Post 2 Get
 * @param needLogin 是否需要登录
 */
- (void)createRequestWithUrl:(NSString *)url
                      header:(NSMutableDictionary * _Nullable)header
                        body:(NSMutableDictionary * _Nullable)body
                      method:(NSInteger)method
                   needLogin:(BOOL)needLogin
                    complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 配置 ====================

/**
 * 设置子渠道 id
 */
- (void)setSubChannelId:(NSString *)subChannelId;

/**
 * 设置当前语言
 * @param language 语言码，如 en、zh-Hans 等
 */
- (void)setLanguage:(NSString *)language;

/**
 * 设置密码强度等级
 */
- (void)setPasswordStrength:(RXPasswordStrength)type;

/**
 * 设置密码正则（需先设置密码强度为自定义）
 */
- (void)setPwdPattern:(NSString *)pattern;

/**
 * 设置商品 id 和超时时间
 */
- (void)setIAPProductId:(NSString *)productId timeout:(NSInteger)timeout;

/**
 * 设置游戏角色信息
 * @param roleId 游戏角色 id
 * @param regionTag 区服信息
 */
- (void)setGameInfoWithRoleId:(NSString *)roleId
                    regionTag:(NSString *)regionTag;

/**
 * 设置自定义错误码信息
 */
- (void)configErrorMsg:(NSDictionary *)msgDic;

/**
 * 设置当前地区
 */
- (void)setArea:(NSString *)area;

#pragma mark - ==================== 信息获取 ====================

/**
 * 获取当前请求域名
 */
- (NSString *)getApiDomain;

/**
 * 获取广告信息
 */
- (NSDictionary *)getAdInfo;

/**
 * 清空广告信息
 */
- (void)deleteAdInfo;

/**
 * 获取 OpenID
 */
- (NSString *)getOpenID;

/**
 * 获取当前 baseUrl
 */
- (NSString *)getFirstBaseUrl;

/**
 * 获取配置数据
 */
- (NSDictionary *)getConfigData;

/**
 * 获取启动参数
 */
- (NSDictionary *)getLaunchOptions;

/**
 * 获取启动参数（SceneDelegate）
 */
- (UISceneConnectionOptions *)getConnectOptions;

#pragma mark - ==================== 验证码 ====================

/**
 * 发送验证码
 * @param type 验证码类型
 * @param target 发送目标（手机或邮箱）
 * @param purpose 用途：register/bindphone/unbindphone/resetpwd/changepwd/bindemail/unbindemail/login
 */
- (void)sendCaptchaWithType:(CaptchaType)type
                     target:(NSString *)target
                    purpose:(NSString *)purpose
                   complete:(RXSDKRequestComplete)complete;

/**
 * 发送验证码（带图形验证）
 */
- (void)sendCaptchaWithType:(CaptchaType)type
                     target:(NSString *)target
                    purpose:(NSString *)purpose
                     ticket:(NSString *)ticket
                    randstr:(NSString *)randstr
                   complete:(RXSDKRequestComplete)complete;

/**
 * 校验验证码
 */
- (void)verifyCaptchaWithType:(CaptchaType)type
                       target:(NSString *)target
                      purpose:(NSString *)purpose
                  captchaCode:(NSString *)captchaCode
                     complete:(RXSDKRequestComplete)complete;

/**
 * 图形验证 UI
 */
- (void)captchaVerifyUIWithAppid:(NSString *)appid
                        complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 账号绑定 ====================

/**
 * 绑定邮箱
 */
- (void)bindEmailWithEmail:(NSString *)email
                  password:(NSString *)password
               captchaCode:(NSString *)captchaCode
               migrateArgs:(id _Nullable)migrateArgs
                  complete:(RXSDKRequestComplete)complete;

/**
 * 解绑邮箱
 */
- (void)unBindEmailWithEmail:(NSString *)email
                 captchaCode:(NSString *)captchaCode
                    complete:(RXSDKRequestComplete)complete;

/**
 * 绑定手机
 */
- (void)bindPhoneWithCaptchaCode:(NSString *)captchaCode
                        password:(NSString *)password
                           phone:(NSString *)phone
                     migrateArgs:(id _Nullable)migrateArgs
                        complete:(RXSDKRequestComplete)complete;

/**
 * 解绑手机
 */
- (void)unBindPhoneWithCaptchaCode:(NSString *)captchaCode
                             phone:(NSString *)phone
                          complete:(RXSDKRequestComplete)complete;

/**
 * 修改手机号
 */
- (void)changePhoneWithOldPhoneCaptcha:(NSString *)oldPhoneCaptcha
                              newphone:(NSString *)newphone
                       newPhoneCaptcha:(NSString *)newPhoneCaptcha
                           migrateArgs:(id _Nullable)migrateArgs
                              complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 用户信息 ====================

/**
 * 获取用户信息
 */
- (void)getUserInfoWithComplete:(RXSDKRequestComplete)complete;

/**
 * 修改用户信息
 */
- (void)updateUserInfo:(NSString *)avatarUrl
              nickname:(NSString *)nickname
                   sex:(NSString *)sex
                region:(NSString *)region
                   ext:(NSDictionary *)ext
              complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 密码 ====================

/**
 * 修改密码
 */
- (void)changePasswordWithNewPwd:(NSString *)newPwd
                          oldPwd:(NSString *)oldPwd
                        complete:(RXSDKRequestComplete)complete;

/**
 * 重置密码
 */
- (void)resetPasswordWithUsername:(NSString *)username
                         password:(NSString *)password
                      captchaCode:(NSString *)captchaCode
                      migrateArgs:(id _Nullable)migrateArgs
                         complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 注册 ====================

/**
 * 注册账号
 */
- (void)registerWithUsername:(NSString * _Nullable)username
                    password:(NSString * _Nullable)password
                 captchaCode:(NSString * _Nullable)captchaCode
                         ext:(NSDictionary * _Nullable)ext
                    complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 实名认证 ====================

/**
 * 实名认证
 */
- (void)realAuthWithRealName:(NSString *)realName
                      idCard:(NSString *)idCard
                    complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 设备信息 ====================

/**
 * 获取设备码
 */
- (NSString *)getDeviceCode;

/**
 * 获取当前时区与 UTC 时差
 */
- (NSString *)getTimeZoneOffset;

/**
 * 获取当前手机语言
 */
- (NSString *)getSystemLanguage;

/**
 * 获取 IDFA
 */
+ (NSString *)getIDFA;

#pragma mark - ==================== Token ====================

/**
 * 刷新 Token
 */
- (void)refreshTokenWithComplete:(RXSDKRequestComplete)complete;

/**
 * login_openid 是否失效
 */
- (BOOL)loginOpenidExpireInvalid;

#pragma mark - ==================== 游戏区服/角色 ====================

/**
 * 查询游戏区服信息
 */
- (void)searchGameAreaInfoWithAreaId:(NSString *)areaId
                            complete:(RXSDKRequestComplete)complete;

/**
 * 查询区服列表信息
 */
- (void)searchGameAreaListInfoWithComplete:(RXSDKRequestComplete)complete;

/**
 * 修改游戏区服信息
 */
- (void)updateGameAreaInfoWithAreaId:(NSString *)areaId
                            areaName:(NSString *)areaName
                          areaStatus:(NSString *)areaStatus
                            areaType:(NSString *)areaType
                           extension:(NSDictionary *)extension
                            complete:(RXSDKRequestComplete)complete;

/**
 * 创建游戏区服
 */
- (void)createGameAreaWithAreaId:(NSString *)areaId
                        areaName:(NSString *)areaName
                      areaStatus:(NSString *)areaStatus
                        areaType:(NSString *)areaType
                       extension:(NSDictionary *)extension
                        complete:(RXSDKRequestComplete)complete;

/**
 * 删除游戏区服
 */
- (void)deleteGameAreaWithAreaId:(NSString *)areaId
                        complete:(RXSDKRequestComplete)complete;

/**
 * 创建游戏角色
 */
- (void)createGameCharacterWithAreaId:(NSString *)areaId
                     characterFaction:(NSString *)characterFaction
                          characterId:(NSString *)characterId
                       characterLevel:(NSString *)characterLevel
                        characterName:(NSString *)characterName
                  characterProfession:(NSString *)characterProfession
                      characterStatus:(NSString *)characterStatus
                        characterType:(NSString *)characterType
                    characterVipLevel:(NSString *)characterVipLevel
                             cpUserId:(NSString *)cpUserId
                            extension:(NSDictionary *)extension
                             complete:(RXSDKRequestComplete)complete;

/**
 * 修改游戏角色信息
 */
- (void)updateGameCharacterInfoWithAreaId:(NSString *)areaId
                         characterFaction:(NSString *)characterFaction
                              characterId:(NSString *)characterId
                           characterLevel:(NSString *)characterLevel
                            characterName:(NSString *)characterName
                      characterProfession:(NSString *)characterProfession
                          characterStatus:(NSString *)characterStatus
                            characterType:(NSString *)characterType
                        characterVipLevel:(NSString *)characterVipLevel
                                 cpUserId:(NSString *)cpUserId
                                extension:(NSDictionary *)extension
                                 complete:(RXSDKRequestComplete)complete;

/**
 * 删除游戏角色
 */
- (void)deleteGameCharacterWithAreaId:(NSString *)areaId
                          characterId:(NSString *)characterId
                             cpUserId:(NSString *)cpUserId
                             complete:(RXSDKRequestComplete)complete;

/**
 * 查询账号下角色信息列表
 */
- (void)searchGameCharacterListInfoWithCpUserId:(NSString *)cpUserId
                                       complete:(RXSDKRequestComplete)complete;

/**
 * 查询账号下某个区服下的角色信息列表
 */
- (void)searchGameCharacterListInAreaWithAreaId:(NSString *)areaId
                                       cpUserId:(NSString *)cpUserId
                                       complete:(RXSDKRequestComplete)complete;

/**
 * 查询具体角色信息
 */
- (void)searchGameCharacterInfoWithAreaId:(NSString *)areaId
                                 cpUserId:(NSString *)cpUserId
                              characterId:(NSString *)characterId
                                 complete:(RXSDKRequestComplete)complete;

/**
 * 查询游戏角色信息
 */
- (void)searchGameAccountWithComplete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 公告/邮件 ====================

/**
 * 获取公告列表
 * @param limit 返回公告条数，范围 1-100
 */
- (void)getAnnouncementWithLimit:(int)limit
                        complete:(RXSDKRequestComplete)complete;

/**
 * 获取临时公告
 */
- (void)getTempNotice:(RXSDKRequestComplete)complete;

/**
 * 获取邮箱列表
 */
- (void)getEmailListWithCpUserID:(NSString *)cpUserID
                        complete:(RXSDKRequestComplete)complete;

/**
 * 获取邮箱详情
 */
- (void)getEmailDetailWithCpUserID:(NSString *)cpUserID
                           emailID:(NSInteger)emailID
                          complete:(RXSDKRequestComplete)complete;

/**
 * 领取道具
 */
- (void)receivePropsWithCpUserID:(NSString *)cpUserID
                            type:(NSInteger)type
                         emailID:(NSInteger)emailID
                        complete:(RXSDKRequestComplete)complete;

/**
 * 删除邮件
 */
- (void)deleteEmailWithCpUserID:(NSString *)cpUserID
                           type:(NSInteger)type
                        emailID:(NSInteger)emailID
                       complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 反馈 ====================

/**
 * 创建反馈
 */
- (void)feedbackCreateWithContent:(NSString *)content
                      attachments:(NSArray *)attachmentsArray
                            phone:(NSString *)phone
                             tags:(NSArray *)tagArray
                         complete:(RXSDKRequestComplete)complete;

/**
 * 获取反馈列表
 */
- (void)getFeedbackListWithPage:(int)page
                           size:(int)size
                         status:(int)status
                       complete:(RXSDKRequestComplete)complete;

/**
 * 获取反馈详情
 */
- (void)getFeedbackDetailWithFeedbackID:(int)feedbackID
                               complete:(RXSDKRequestComplete)complete;

/**
 * 领取反馈回复中的道具
 */
- (void)feedbackGetpropWithFeedbackID:(int)feedbackID
                             complete:(RXSDKRequestComplete)complete;

/**
 * 获取意见反馈类型
 */
- (void)getFeedbackKindListWithComplete:(RXSDKRequestComplete)complete;

/**
 * 创建意见反馈
 */
- (void)createFeedbackWithParams:(NSDictionary *)params
                        complete:(RXSDKRequestComplete)complete;

/**
 * 满意度评价
 */
- (void)satisfactionEvaluationWithParams:(NSDictionary *)params
                                complete:(RXSDKRequestComplete)complete;

/**
 * 上报反馈日志
 */
- (void)reportFeedbackLogWithData:(NSData *)data
                         complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 福利码 ====================

/**
 * 请求福利码
 */
- (void)getPromoDisplayKeyWithAutoRefresh:(BOOL)autoRefresh
                                 complete:(RXSDKRequestComplete)complete;

/**
 * 获取福利码
 */
- (void)exchangePromoCDKEY:(NSString *)cdkey
                  complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 商业化 ====================

/**
 * 获取商业化窗口信息
 */
- (void)getOperationSceneWithComplete:(RXSDKRequestComplete)complete;

/**
 * 商业化信息上报
 */
- (void)reportWindowExposureWithWindowData:(NSDictionary *)windowData
                                  complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 客服 ====================

/**
 * 获取客服消息未读数
 */
- (void)getServiceChatUnreadCount:(RXSDKRequestComplete)complete;

/**
 * 清空客服消息未读数
 */
- (void)clearServiceChatUnreadCount:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 埋点 ====================

/**
 * 用户行为统计
 */
- (void)trackUserActionWithDistinctId:(NSString * _Nullable)distinctId
                           properties:(NSDictionary * _Nullable)properties;

/**
 * 终止用户行为统计
 */
- (void)stopTrackUserAction;

#pragma mark - ==================== 支付（IAP）====================

/**
 * 设置重复下单间隔
 */
- (void)setIAPInterval:(NSInteger)interval;

/**
 * 内购支付
 */
- (void)iap:(NSDictionary *)dict complete:(RXSDKRequestComplete)complete;

/**
 * 查询是否需要补单
 */
- (BOOL)checkHasFailedOrder;

/**
 * 补单
 */
- (void)reFailOrderWithMaxCount:(NSInteger)maxCount
                       complete:(RXSDKRequestComplete)complete;

/**
 * 查询商品信息
 */
- (void)getProductInfoWithProductIdArr:(NSArray *)productIdArr
                              complete:(void(^)(NSArray<SKProduct *> *productInfoList))complete;

/**
 * 获取初始化保存的计费点
 */
- (NSDictionary *)getProductInfo;

/**
 * 获取地区货币符号
 */
- (void)getLocaleIdentifierWithProductId:(NSString *)productId
                                 timeout:(NSInteger)timeout
                                complete:(RXSDKRequestComplete)complete;

/**
 * StoreKit2 查询未完成交易
 */
- (void)sk2UnfinishUncompletedTransactionsWithOrderInfo:(NSDictionary *)orderInfo
                                         completeHandle:(RXSDKRequestComplete)handle;

/**
 * 查询订单状态
 */
- (void)tradeQueryWithOrderNo:(NSString *)orderNo
                     complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 分享 ====================

/**
 * 一键分享
 */
- (void)share:(RXShareConfig *)config
     complete:(RXSDKRequestComplete)complete;

/**
 * 自定义分享
 */
- (void)shareCustom:(RXCustomShareConfig *)config
           complete:(RXSDKRequestComplete)complete;

/**
 * 分享调度初始化
 */
- (void)shareSchedulingInitWithFuncs:(NSArray *)funcs
                            complete:(RXSDKRequestComplete)complete;

/**
 * 获取埋点调度
 */
- (void)getShareSchedulingWithFuncs:(NSArray *)funcs
                           complete:(RXSDKRequestComplete)complete;

/**
 * 获取分享信息
 */
- (void)getShareInfoWithConfig:(RXShareConfig *)config
                      complete:(RXSDKRequestComplete)complete;

/**
 * 系统分享
 */
- (void)SystemShareWithShareInfo:(NSDictionary *)shareInfo
                        complete:(RXSDKShareCallBack)complete;

/**
 * 获取通路配置
 */
- (void)getSharePlatformsWithComplete:(RXSDKRequestComplete)complete;

/**
 * 分享/广告结果上报
 */
- (void)shareSchedulingReportWithFunc:(NSString *)func
                             platform:(NSString *)platform
                               region:(NSString *)region
                            transmits:(NSString * _Nullable)transmits
                     scheduling_event:(BOOL)scheduling_event
                      scheduling_type:(NSString *)scheduling_type
                           properties:(NSDictionary * _Nullable)properties
                             complete:(RXSDKRequestComplete)complete;

/**
 * 获取短链接
 */
- (void)getShortUrl:(NSString *)url
           complete:(RXSDKRequestComplete)complete;

/**
 * 获取短链接（带 og 标签）
 */
- (void)getShortUrl:(NSString *)url
              title:(NSString *)title
            content:(NSString *)content
              image:(NSString *)image
                ext:(NSDictionary *)ext
           complete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 日志埋点 ====================

/**
 * 埋点配置
 */
- (void)trackConfigWithReportTime:(NSInteger)reportTime
                         maxCount:(NSInteger)maxCount;

/**
 * 设置是否为测试数据
 */
- (void)setTrackEnv:(BOOL)env;

/**
 * 数据埋点（批量上报）
 */
- (BOOL)dataTrackWithEvent:(NSString *)event
                distinctId:(NSString * _Nullable)distinctId
                properties:(NSDictionary * _Nullable)properties;

/**
 * 数据埋点（单条上报）
 */
- (BOOL)addLogSingleWithEvent:(NSString *)event
                   distinctId:(NSString * _Nullable)distinctId
                   properties:(NSDictionary * _Nullable)properties
                     complete:(RXSDKRequestComplete)complete;

/**
 * 设置公共属性
 */
- (void)setPublicProperties:(NSDictionary *)properties;

/**
 * 修改公共属性
 */
- (void)updatePublicProperties:(NSDictionary *)properties;

/**
 * 删除公共属性
 */
- (void)deletePublicProperties:(NSArray *)properties;

/**
 * 获取 distinctId
 */
- (NSString *)getDistinctId;

/**
 * 获取 SDK 日志
 */
- (NSString *)getSDKLog;

#pragma mark - ==================== 注销账号 ====================

/**
 * 申请注销账号
 */
- (void)deregisterWithConfig:(RXDeregisterConfig *)config
                    complete:(RXSDKRequestComplete)complete;

/**
 * 撤销注销申请
 */
- (void)deregisterCancelWithComplete:(RXSDKRequestComplete)complete;

#pragma mark - ==================== 评分 ====================

/**
 * 应用内拉起 App Store 评分页面
 */
- (void)inAppStoreReview:(NSString *)appid
                complete:(void(^)(void))complete;

/**
 * 跳转到 App Store 评分
 */
- (void)toAppStoreReview:(NSString *)appid
             writeReview:(BOOL)writeReview;

/**
 * 应用内评分弹框
 */
- (void)alertAppReview;

@end

NS_ASSUME_NONNULL_END
