//
//  RXLogService.h
//  RXSDK
//
//  Created by 陈汉 on 2022/3/1.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXLogService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 埋点配置
 * 添加埋点后SDK会根据配置定期上报
 * @param reportTime 上报间隔（秒），默认60s
 * @param maxCount 最大缓存数--达到最大缓存数量触发上报条件（例：传100 缓存数据量达到100时触发上报），默认100条
 */
- (void)configWithReportTime:(NSInteger)reportTime
                    maxCount:(NSInteger)maxCount;

/**
 * 数据埋点（批量上报）
 * @param event 埋点标识
 * @param distinctId 用户唯一标识
 * ！！注：登录后SDK会将openID保存，distinctId传空默认为openID。首次登录前需先调用getDistinctId获取distinctId作为标识。
 * ！！登录前的埋点行为可先调用[[RXService sharedSDK] getOpenID];查看本地是否存有openID，如果没有则调用getDistinctId获取distinctId作为标识。避免丢失埋点事件！！
 * @param properties 自定义属性
 */
- (void)addLogWithEvent:(NSString *)event
             distinctId:(NSString * _Nullable)distinctId
             properties:(NSDictionary * _Nullable)properties;

/**
 * 数据埋点（逐条上报）
 * @param event 埋点标识
 * @param distinctId 用户唯一标识，传空默认为openID
 * @param properties 自定义属性
 */
- (void)addLogSingleWithEvent:(NSString *)event
                   distinctId:(NSString * _Nullable)distinctId
                   properties:(NSDictionary * _Nullable)properties;

/**
 * 获取distinctId
 */
- (NSString *)getDistinctId;

@end

NS_ASSUME_NONNULL_END
