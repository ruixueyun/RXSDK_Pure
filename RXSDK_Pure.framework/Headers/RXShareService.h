//
//  RXShareService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/6.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ShareCallBack)(BOOL success);

@interface RXShareService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取分享信息
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码 非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)getShareInfoWithFunc:(NSString *)func
                    platform:(NSString *)platform
                      region:(NSString *)region
                   transmits:(NSString * _Nullable)transmits
                         ext:(NSDictionary * _Nullable)ext
                    complete:(RequestComplete)complete;

/**
 * 获取分享信息
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！func 埋点标识     #NSString类型
 * ！region 地区码     #NSString类型
 * ！platform 分享平台 wechat     #NSString类型
 * ！transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回     #NSString类型
 * ！protocol_android android唤醒协议     #NSString类型
 * ！protocol_ios iOS唤醒协议     #NSString类型
 */
- (void)getShareInfoWithParams:(NSDictionary *)params
                      complete:(RequestComplete)complete;

/**
 * 系统分享（直接调用，不需要获取分享信息）
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码  非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须 、
 */
- (void)SystemShareWithFunc:(NSString *)func
                   platform:(NSString *)platform
                     region:(NSString *)region
                  transmits:(NSString * _Nullable)transmits
                        ext:(NSDictionary * _Nullable)ext
                   complete:(ShareCallBack)complete;

/**
 * 系统分享
 * @param shareInfo 获取分享信息返回的内容  必须
 */
- (void)SystemShareWithShareInfo:(NSDictionary *)shareInfo
                        complete:(ShareCallBack)complete;


/**
 * 获取通路配置
 */
- (void)getSharePlatformsWithComplete:(RequestComplete)complete;

/**
 * 分享上报
 * @param distinctId 用户唯一标识，一般为 OpenID（由CP调用时传入）
 * @param properties 自定义属性
 */
- (void)shareReportWithDistinctId:(NSString *)distinctId
                       properties:(NSDictionary * _Nullable)properties
                         complete:(RequestComplete)complete;

/**
 * 分享上报
 * @param params 获取验证码请求参数
 * ！params参数说明：
 * ！distinctId 用户唯一标识，一般为 OpenID    #NSString类型
 * ！properties 自定义属性    #NSDictionary类型
 */
- (void)shareReportWithParams:(NSDictionary *)params
                     complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
