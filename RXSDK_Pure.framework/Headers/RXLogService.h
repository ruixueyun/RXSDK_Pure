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
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param reportTime 上报间隔（秒），-1 为默认值 [默认60s]
 * @param maxCount 最大缓存数--达到最大缓存数量触发上报条件（例：传100 缓存数据量达到100时触发上报），默认100条
 */
- (void)configWithReportTime:(NSInteger)reportTime
                    maxCount:(NSInteger)maxCount DEPRECATED_MSG_ATTRIBUTE("use trackConfigWithReportTime:maxCount:complete instead");

/**
 * 埋点配置
 * 添加埋点后SDK会根据配置定期上报
 * @param reportTime 上报间隔（秒），-1 为默认值 [默认60s]
 * @param maxCount 最大缓存数--达到最大缓存数量触发上报条件（例：传100 缓存数据量达到100时触发上报），默认100条
 */
- (void)trackConfigWithReportTime:(NSInteger)reportTime
                         maxCount:(NSInteger)maxCount;

/**
 * 数据埋点（批量上报）
 * @note 需要在初始化后调用
 * @param event 埋点标识
 * @param distinctId 用户唯一标识
 * ！！注：登录后SDK会将openID保存，distinctId传空默认为openID。首次登录前需先调用getDistinctId获取distinctId作为标识。
 * ！！登录前的埋点行为可先调用[[RXService sharedSDK] getOpenID];查看本地是否存有openID，如果没有则调用getDistinctId获取distinctId作为标识。避免丢失埋点事件！！
 * @param properties 自定义属性
 */
- (BOOL)addLogWithEvent:(NSString *)event
             distinctId:(NSString * _Nullable)distinctId
             properties:(NSDictionary * _Nullable)properties DEPRECATED_MSG_ATTRIBUTE("use dataTrackWithEvent:distinctId:properties instead");

/**
 * 数据埋点（逐条上报）
 * @note 需要在初始化后调用
 * @param event 埋点标识
 * @param distinctId 用户唯一标识，传空默认为openID
 * @param properties 自定义属性
 */
- (BOOL)addLogSingleWithEvent:(NSString *)event
                   distinctId:(NSString * _Nullable)distinctId
                   properties:(NSDictionary * _Nullable)properties;

/**
 * 数据埋点（批量上报）
 * @note 需要在初始化后调用
 * @param event 埋点标识
 * @param distinctId 用户唯一标识
 * ！！注：登录后SDK会将openID保存，distinctId传空默认为openID。首次登录前需先调用getDistinctId获取distinctId作为标识。
 * ！！登录前的埋点行为可先调用[[RXService sharedSDK] getOpenID];查看本地是否存有openID，如果没有则调用getDistinctId获取distinctId作为标识。避免丢失埋点事件！！
 * @param properties 自定义属性
 */
- (BOOL)dataTrackWithEvent:(NSString *)event
                distinctId:(NSString * _Nullable)distinctId
                properties:(NSDictionary * _Nullable)properties;

/**
 * 设置公共属性
 * 设置后由SDK填入自定义属性中进行上报，设置后SDK进行缓存，多次设置则会覆盖
 * @properties 公共属性
 */
- (void)setPublicProperties:(NSDictionary *)properties;

/**
 * 修改公共属性
 * 修改的属性会将原有属性覆盖，未设置的属性则会补入缓存中
 * @properties 公共属性
 */
- (void)updatePublicProperties:(NSDictionary *)properties;

/**
 * 删除公共属性
 * 删除缓存的某个公共属性
 * @properties 公共属性key
 */
- (void)deletePublicProperties:(NSArray *)properties;

/**
 * 获取distinctId
 */
- (NSString *)getDistinctId;

/**
 * 获取日志
 * @note 记录登录和支付关键节点的日志，存在本地，默认最大 200 条，超过 200 条清空当前缓存重新记录
 */
- (NSString *)getSDKLog;

@end

NS_ASSUME_NONNULL_END
