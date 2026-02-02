//
//  RXService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/9/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RXPublicHeader.h"
#import "RXError.h"
#import "RXSdkInitConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 全局通用回调type类型
 */
static NSInteger feedbakc_report = 10001; // 上报用户反馈

@protocol RXPublicDelegate <NSObject>

/**
 * 全局通用回调
 * @param type 回调类型
 * @param response 回调数据
 */
- (void)rxPublicCallback:(NSInteger)type response:(NSDictionary *)response;

@end

@protocol RXLoginDelegate <NSObject>

/**
 * 登录回调
 * @param response 返回数据，登录失败返回nil
 * @param error 错误返回，登录成功返回nil
 */
- (void)rx_LoginCallBackWithResponse:(NSDictionary * _Nullable)response error:(RX_CommonRequestError *)error;

/**
 * 防沉迷回调
 * @param response 返回数据，登录失败返回nil
 * @param error 错误返回，登录成功返回nil
 */
- (void)rx_antiCallBackWithResponse:(NSDictionary *)response error:(NSError *)error;

@end

@interface RXService : NSObject

@property (nonatomic, weak) id <RXLoginDelegate> loginDelegate;
@property (nonatomic, weak) id <RXPublicDelegate> publicDelegate;
@property (nonatomic, strong) RXSdkInitConfig *sdkConfig;

@property (nonatomic, readonly, assign) BOOL isUseFastAuth;
@property (nonatomic, readonly, assign) BOOL useCustomKeyboard;

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 初始化SDK
 * 初始化后会 SDK 会自动激活
 * @param config 初始化配置
 */
- (void)initWithConfig:(RXSdkInitConfig *)config
              complete:(RequestComplete)complete;

/**
 * 初始化SDK
 * 初始化后会 SDK 会自动激活
 * @param productId 产品id
 * @param channelId 渠道id
 * @param cpid 瑞雪为每个项目分配的一个唯一 ID
 * @param baseUrlList 请求域名队列
 * @param complete 初始化结果回调
 */
- (void)initWithProductId:(NSString *)productId
                channelId:(NSString *)channelId
                     cpid:(NSString *)cpid
              baseUrlList:(NSArray *)baseUrlList
                 complete:(RequestComplete)complete;

/**
 * 初始化SDK
 * @param profile 初始化配置表，需要符合 jsonString 格式
 * @param complete 初始化结果回调
 * @note 注意：此方法和 initWithProductId 只会生效一种，后调用的会将前一份数据覆盖
 */
- (void)initWithProfile:(NSString *)profile
               complete:(RequestComplete)complete;

/**
 * 用户激活
 * @param sourceAd 扩展信息
 * ！sourceAd参数说明：
 * ！source_ad 客户端采集到的广告相关的信息  非必须    #NSDictionary类型
 * ！user_agent 一种方式获取的 user_agent，若为空，则取 user-agent header 的值  非必须    #NSString类型
 * ！user_agent1 其他方式获取的 user_agent  非必须    #NSString类型
 * ！user_agent2 其他方式获取的 user_agent  非必须    #NSString类型
 */
- (void)requestActivatedWithSourceAd:(NSDictionary * _Nullable)sourceAd
                            complete:(RequestComplete)complete;

/**
 * 设置初始化参数
 * @note 调用后只保存初始化参数，不做激活等流程
 * @param productId 产品id
 * @param channelId 渠道id
 * @param cpid 瑞雪为每个项目分配的一个唯一 ID
 * @param baseUrlList 请求域名队列
 * @param complete 初始化结果回调
 */
- (void)setInitParamsWithProductId:(NSString *)productId
                         channelId:(NSString *)channelId
                              cpid:(NSString *)cpid
                       baseUrlList:(NSArray *)baseUrlList
                          complete:(RequestComplete)complete;

/**
 * 设置子渠道id
 */
- (void)setSubChannelId:(NSString *)subChannelId;

/**
 * 登录请求
 * @param extDic 扩展字段，可传nil
 * ！验证码登录需传captcha_code  #NSString类型
 * ！extDic = @{@"captcha_code" : @"验证码"}
 * ！断线重连 ext 中传 reconnect_login = YES
 * @param username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * @param password 非账号登录传空
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 * @param loginType 登录类型
 * @param migrate_args 任意合法的 json 类型, 比如 string, number，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)loginWithExtDic:(NSMutableDictionary * _Nullable)extDic
               username:(NSString * _Nullable)username
               password:(NSString * _Nullable)password
            sign_fields:(NSArray * _Nullable)sign_fields
              loginType:(LoginType)loginType
           migrate_args:(id _Nullable)migrate_args DEPRECATED_MSG_ATTRIBUTE("use loginWithLoginType:username:password:captchaCode:loginOpenId:extDic:signFields:migrateArgs instead");

/**
 * 二次登录
 * @param loginOpenId 登录返回的login_openid
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 * @param extDic 扩展字段，可传nil
 * ！断线重连 ext 中传 reconnect_login = YES
 */
- (void)loginWithLoginOpenId:(NSString *)loginOpenId
                 sign_fields:(NSArray * _Nullable)sign_fields
                      extDic:(NSMutableDictionary * __nullable)extDic DEPRECATED_MSG_ATTRIBUTE("use loginWithLoginType:username:password:captchaCode:loginOpenId:extDic:signFields:migrateArgs instead");

/**
 * 苹果登录
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 */
- (void)loginReq_appleWithMigrate_args:(id _Nullable)migrate_args
                           sign_fields:(NSArray * _Nullable)sign_fields DEPRECATED_MSG_ATTRIBUTE("use loginWithLoginType:username:password:captchaCode:loginOpenId:extDic:signFields:migrateArgs instead");

/**
 * 登录请求
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param loginType 登录类型
 * @param username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * @param password 非账号登录传空
 * @param captchaCode 验证码，登录方式为验证码时必传，其他登录方式可传空
 * @param permissions 登录获取的权限数组，FaceBook、Line时必传，其他登录方式可传空
 * @param loginOpenId 二次登录openId，nil或空为普通登录
 * @param extDic 扩展字段，可传nil
 * ！断线重连 ext 中可传 reconnect_login = YES
 * @param signFields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 * @param migrateArgs 任意合法的 json 类型, 比如 string, number，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)loginWithLoginType:(LoginType)loginType
                  username:(NSString * _Nullable)username
                  password:(NSString * _Nullable)password
               captchaCode:(NSString * _Nullable)captchaCode
               permissions:(NSArray * _Nullable)permissions
               loginOpenId:(NSString *)loginOpenId
                    extDic:(NSMutableDictionary * _Nullable)extDic
                signFields:(NSArray * _Nullable)signFields
               migrateArgs:(id _Nullable)migrateArgs;

/**
 * 登录请求
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param loginType 登录类型
 * @param username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * @param password 非账号登录传空
 * @param captchaCode 验证码，登录方式为验证码时必传，其他登录方式可传空
 * @param permissions 登录获取的权限数组，FaceBook、Line时必传，其他登录方式可传空
 * @param loginOpenId 二次登录openId，nil或空为普通登录
 * @param extDic 扩展字段，可传nil
 * ！断线重连 ext 中可传 reconnect_login = YES
 * @param signFields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 * @param migrateArgs 任意合法的 json 类型, 比如 string, number，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 * @param complete 登录回调
 */
- (void)loginWithLoginType:(LoginType)loginType
                  username:(NSString * _Nullable)username
                  password:(NSString * _Nullable)password
               captchaCode:(NSString * _Nullable)captchaCode
               permissions:(NSArray * _Nullable)permissions
               loginOpenId:(NSString * _Nullable)loginOpenId
                    extDic:(NSMutableDictionary * _Nullable)extDic
                signFields:(NSArray * _Nullable)signFields
               migrateArgs:(id _Nullable)migrateArgs
                  complete:(RequestComplete)complete;

/**
 * 获取法务配置信息
 */
- (void)getLegalInfo:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 自定义请求
 * @param url 接口名，可传路径或完整url，传路径则拼接初始化的baseUrl
 * @param header 请求头
 * @param body 请求参数
 * @param method 请求类型  1 Post请求，2 Get请求
 * @param needLogin 接口是否需要登录，不需要登录则请求头中的ruixue-accesstoken会被清空
 */
- (void)createRequestWithUrl:(NSString *)url
                      header:(NSMutableDictionary * _Nullable)header
                        body:(NSMutableDictionary * _Nullable)body
                      method:(NSInteger)method
                   needLogin:(BOOL)needLogin
                    complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

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
 * 获取openID
 */
- (NSString *)getOpenID;

/**
 * 获取当前baseUrl
 */
- (NSString *)getFirstBaseUrl;

/**
 * 设置当前语言
 * @param language  语言需符合标准格式，如en、cn等
 */
- (void)setLanguage:(NSString *)language;

/**
 * 设置密码等级
 * @param type 密码强度等级枚举
 */
- (void)setPasswordStrength:(RXPasswordStrength)type;

/**
 * 设置密码正则
 * 需要先将密码强度设置为自定义
 */
- (void)setPwdPattern:(NSString *)pattern;

/**
 * 设置商品 id 和 超时时间
 * @param productId  商品 id
 * @param timeout 超时时间，默认 2 秒
 */
- (void)setIAPProductId:(NSString *)productId timeout:(NSInteger)timeout;

/**
 * 设置游戏角色 id
 * @param roleId 游戏角色 id
 * @param regionTag 区服信息
 */
- (void)setGameInfoWithRoleId:(NSString *)roleId
                    regionTag:(NSString *)regionTag;

/**
 * 设置自定义错误码信息
 * @param msgDic 设置自定义错误码的字典
 */
- (void)configErrorMsg:(NSDictionary *)msgDic;

- (NSDictionary *)getConfigData;

/**
 * 获取启动参数
 */
- (NSDictionary *)getLaunchOptions;

/**
 * 获取启动参数 SceneDelegate
 */
- (UISceneConnectionOptions *)getConnectOptions;

/**
 * 设置当前地区
 * @param area 地区码
 */
- (void)setArea:(NSString *)area;

/**
 * 绑定账号
 * @param ext 说明
 * -- "method" : "wechat"  登录方式，暂时只支持微信
 */
- (void)bindAccountWithExt:(NSDictionary *)ext
                  complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
