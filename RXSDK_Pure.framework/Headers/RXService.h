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
- (void)rx_LoginCallBackWithResponse:(NSDictionary * _Nullable)response error:(RXCommonRequestError *)error;

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
 * 登录请求
 * @param extDic 扩展字段，可传nil
 * @param username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * @param password 非账号登录传空
 * @param loginOpenId 登陆返回的loginopenid字段，二次登录用，可传nil
 * @param loginType 登录类型
 */
- (void)loginWithExtDic:(NSMutableDictionary * _Nullable)extDic
               username:(NSString * _Nullable)username
               password:(NSString * _Nullable)password
            loginOpenId:(NSString * _Nullable)loginOpenId
              loginType:(LoginType)loginType;

/**
 * 获取法务配置信息
 */
- (void)getLegalInfo:(void(^)(NSDictionary *response, RXCommonRequestError *error))complete;

/**
 * 苹果登录
 */
- (void)loginReq_apple;

/**
 * 自定义请求
 * @param url 接口名
 * @param header 请求头
 * @param body 请求参数
 */
- (void)requestWithUrl:(NSString *)url
                header:(NSMutableDictionary * _Nullable)header
                  body:(NSMutableDictionary * _Nullable)body
              complete:(void(^)(NSDictionary *response, RXCommonRequestError *error))complete;

/**
 * 获取当前请求域名
 */
- (NSString *)getApiDomain;

@end

NS_ASSUME_NONNULL_END
