//
//  RXService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/9/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

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

typedef enum {
    LoginTypeVisitor,  // 游客登录
    LoginTypeAccount, // 账号登录
    LoginTypeEmail,  // 邮箱登录
    LoginTypeAuth,   // 本机一键登录
    LoginTypeW, // 微信登录
    LoginTypeApple,   // 苹果登录
    LoginTypeQuick,   // 二次登录
    LoginTypeGoogle,  // 谷歌登录
    LoginTypeFacebook, // facebook登录
    LoginTypeVirtual  // 虚拟登录
}LoginType;


@interface RXService : NSObject

@property (nonatomic, weak) id <RXLoginDelegate> loginDelegate;

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 初始化SDK
 * @param productId 产品id
 * @param channelId 渠道id
 * @param cpid 客户端id
 * @param baseUrlList 请求域名队列
 */
- (void)initWithProductId:(NSString *)productId
                channelId:(NSString *)channelId
                     cpid:(NSString *)cpid
              baseUrlList:(NSArray *)baseUrlList;

/**
 * 用户激活
 * @param sourceAd 客户端采集到的广告相关的信息 非必传，不传则SDK默认取剪贴板内容
 */
- (void)requestActivatedWithSourceAd:(NSDictionary * _Nullable)sourceAd
                            complete:(RequestComplete)complete;

/**
 * 登录请求
 * @param extDic 扩展字段，可传nil
 * @param username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * @param password 非账号登录传空
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关  非必须
 * @param loginType 登录类型
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)loginWithExtDic:(NSMutableDictionary * _Nullable)extDic
               username:(NSString * _Nullable)username
               password:(NSString * _Nullable)password
            sign_fields:(NSString * _Nullable)sign_fields
              loginType:(LoginType)loginType
           migrate_args:(id _Nullable)migrate_args;

/**
 * 登录请求
 * @param loginType 登录类型
 * @param loginInfo 登录数据
 * ！loginInfo参数说明：
 * ！extDic 扩展字段，可传nil
 * ！username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * ！password 非账号登录传空
 * ！sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关  非必须
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)loginWithLoginInfo:(NSMutableDictionary * _Nullable)loginInfo
                 loginType:(LoginType)loginType;

/**
 * 二次登录
 * @param loginOpenId 登录返回的login_openid
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关  非必须
 * @param extDic 扩展字段，可传nil
 */
- (void)loginWithLoginOpenId:(NSString *)loginOpenId
                 sign_fields:(NSString * _Nullable)sign_fields
                      extDic:(NSMutableDictionary * __nullable)extDic;

/**
 * 获取法务配置信息
 */
- (void)getLegalInfo:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 苹果登录
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关  非必须
 */
- (void)loginReq_appleWithMigrate_args:(id _Nullable)migrate_args
                           sign_fields:(NSString * _Nullable)sign_fields;

/**
 * 自定义请求
 * @param url 接口名
 * @param header 请求头
 * @param body 请求参数
 */
- (void)requestWithUrl:(NSString *)url
                header:(NSMutableDictionary * _Nullable)header
                  body:(NSMutableDictionary * _Nullable)body
              complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 获取当前请求域名
 */
- (NSString *)getApiDomain;

/**
 * 获取剪贴板广告信息
 */
- (NSDictionary *)getAdInfo;

/**
 * 获取openID
 */
- (NSString *)getOpenID;

@end

NS_ASSUME_NONNULL_END
