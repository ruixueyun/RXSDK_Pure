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
 * @param platform 分享平台
 * @param region 地区码  必须
 * @param shareScene 分享方式 0-好友 1-朋友圈
 * @param transmits 透传参数，原样返回  非必须
 */
- (void)getShareInfoWithFunc:(NSString *)func
                    platform:(NSString *)platform
                      region:(NSString *)region
                  shareScene:(NSInteger)shareScene
                   transmits:(NSDictionary * _Nullable)transmits
                    complete:(RequestComplete)complete;

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

@end

NS_ASSUME_NONNULL_END
