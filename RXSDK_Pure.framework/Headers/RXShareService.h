//
//  RXShareService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/6.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^NewShareCallBack)(NSDictionary *response, RX_CommonRequestError *error);
typedef void(^ShareCallBack)(BOOL success);

@interface RXShareService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 分享调度初始化
 * @param funcs 埋点数组，传空获取所有埋点调度
 */
- (void)shareSchedulingInitWithFuncs:(NSArray *)funcs
                            complete:(RequestComplete)complete;

/**
 * 获取埋点调度
 * @param funcs 埋点数组，传空获取所有埋点调度
 */
- (void)getShareSchedulingWithFuncs:(NSArray *)funcs
                           complete:(RequestComplete)complete;

/**
 * 分享
 * 调用后根据 platform 自动拉起对应平台的分享
 * @note 如果需要自定义分享数据请使用  获取分享信息+对应平台拉起分享接口
 * @param func 埋点标识  必须
 * @param platform 分享平台
 * @note 平台类型说明：
 * ！wechat
 * ！facebook
 * ！line
 * ！messenger
 * ！system
 * @param report 是否自动上报，默认自动上报
 * @param region 地区码 非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)shareWithFunc:(NSString *)func
             platform:(NSString *)platform
               region:(NSString *)region
               report:(BOOL)report
            transmits:(NSString * _Nullable)transmits
                  ext:(NSDictionary * _Nullable)ext
             complete:(RequestComplete)complete;

/**
 * 获取分享信息
 * @param func 埋点标识  必须
 * @param platform 分享平台 
 * @note 平台类型说明：
 * ！wechat
 * ！facebook
 * ！line
 * ！messenger
 * ！system
 * @param region 地区码 非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)getShareInfoWithFunc:(NSString *)func
                    platform:(NSString *)platform
                      region:(NSString *)region
                   transmits:(NSString * _Nullable)transmits
                         ext:(NSDictionary * _Nullable)ext
                    complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use getShareInfoWithFunc:platform:region:transmits:ext:readCache:complete instead");

/**
 * 获取分享信息
 * @param func 埋点标识  必须
 * @param platform 分享平台
 * @note 平台类型说明：
 * ！wechat
 * ！facebook
 * ！line
 * ！messenger
 * ！system
 * @param region 地区码 非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 * @param readCache 是否读取缓存，YES 读取缓存   NO 不读取缓存，建议读取缓存
 */
- (void)getShareInfoWithFunc:(NSString *)func
                    platform:(NSString *)platform
                      region:(NSString *)region
                   transmits:(NSString * _Nullable)transmits
                         ext:(NSDictionary * _Nullable)ext
                   readCache:(BOOL)readCache
                    complete:(RequestComplete)complete;

/**
 * 系统分享（直接调用，不需要获取分享信息）
 * @param func 埋点标识  必须
 * @param platform 分享平台
 * @note 平台类型说明：
 * ！wechat
 * ！facebook
 * ！line
 * ！messenger
 * ！system
 * @param region 地区码  非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)SystemShareWithFunc:(NSString *)func
                   platform:(NSString *)platform
                     region:(NSString *)region
                  transmits:(NSString * _Nullable)transmits
                        ext:(NSDictionary * _Nullable)ext
                   complete:(ShareCallBack)complete DEPRECATED_MSG_ATTRIBUTE("use shareWithFunc:platform:region:report:transmits:ext:complete instead");

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
 * @param distinctId 用户唯一标识，一般为 openid（由CP调用时传入），nil默认为openid
 * @param properties 自定义属性
 */
- (void)shareReportWithDistinctId:(NSString *)distinctId
                       properties:(NSDictionary * _Nullable)properties
                         complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use shareSchedulingReportWithFunc:platform:region:transmits:scheduling_event:scheduling_type:scheduling_strategy_id:complete instead");

/**
 * 分享/广告结果上报
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码 非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param scheduling_event 上报结果  YES 成功   NO 失败
 * @param scheduling_type 上报类型  ad 广告   share 分享
 * @param properties 自定义属性
 */
- (void)shareSchedulingReportWithFunc:(NSString *)func
                             platform:(NSString *)platform
                               region:(NSString *)region
                            transmits:(NSString * _Nullable)transmits
                     scheduling_event:(BOOL)scheduling_event
                      scheduling_type:(NSString *)scheduling_type
                           properties:(NSDictionary * _Nullable)properties
                             complete:(RequestComplete)complete;

/**
 * 获取自动重定向短链接
 * @param url 要生成短链接的url
 */
- (void)getShortUrl:(NSString *)url
           complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
