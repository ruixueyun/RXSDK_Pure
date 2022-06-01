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
 * @param transmitargs 透传参数，原样返回  非必须
 * @param custom 自定义参数，URLENCODE  非必须
 * @param region 地区码  必须
 * @param shareScene 分享方式 0-好友 1-朋友圈
 * @param urlCustom 落地页拼接自定义参数  非必须
 */
- (void)getShareInfoWithFunc:(NSString *)func
                transmitargs:(NSString * _Nullable)transmitargs
                      custom:(NSString * _Nullable)custom
                      region:(NSString *)region
                  shareScene:(NSInteger)shareScene
                   urlCustom:(NSDictionary * _Nullable)urlCustom
                    complete:(RequestComplete)complete;

/**
 * 系统分享
 * @param shareInfo 获取分享信息返回的内容  必须
 */
- (void)SystemShareWithShareInfo:(NSDictionary *)shareInfo
                        complete:(ShareCallBack)complete;

/**
 * 获取指定埋点次数信息
 * @param func_tags 埋点标识数组  必须
 */
- (void)getShareLimitInfoWithFunc_tags:(NSArray *)func_tags
                              complete:(RequestComplete)complete;

/**
 * 分享上报
 * @param param 上报参数  必须
 sourceChannel  string  非必须
 func  string  必须  埋点
 result  string  必须  结果 ok or fail
 type  string  非必须  类型share/ad
 method  number  非必须  分享方式 1广告，2好友列表 4朋友圈 (2+4正常分享)，8指定分享
 material  string  非必须  资源类型URL、IMAGE、TEXT、AD=广告
 materialid  number  非必须  分享内容ID，客户端无使用，回调原样返回ADID
 transmitargs  string  非必须  透传参数，原样返回
 custom  string  非必须  自定义参数，URLENCODE
 adPlatform  string  非必须  广告平台
 region  string  非必须  地区码
 */
- (void)getshareReportWithParam:(NSDictionary *)param
                       complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
