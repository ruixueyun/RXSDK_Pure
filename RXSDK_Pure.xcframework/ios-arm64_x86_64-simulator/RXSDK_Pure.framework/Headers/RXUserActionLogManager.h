//
//  RXUserActionLogManager.h
//  RXSDK-Pure
//
//  Created by 陈汉 on 2025/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXUserActionLogManager : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 数据埋点（批量上报）
 * @param event 埋点标识
 * @param distinctId 用户唯一标识，传空默认为openID
 * @param properties 自定义属性
 */
- (BOOL)addUserActionWithEvent:(NSString *)event
                    distinctId:(NSString * _Nullable)distinctId
                    properties:(NSDictionary * _Nullable)properties;

/**
 * 数据埋点（批量上报）
 * @note private
 */
- (BOOL)addUserActionWithScene:(NSString *)scene
                        action:(NSString * _Nullable)action
                    properties:(NSDictionary * _Nullable)properties;

/**
 * 数据埋点（批量上报）网络请求
 * @note private
 */
- (BOOL)addUserActionRequestWithHeader:(NSDictionary *)header
                                  body:(NSDictionary * _Nullable)body
                                   url:(NSString *)url
                             errorCode:(NSInteger)errorCode
                              errorMsg:(NSString *)errorMsg
                            properties:(NSDictionary * _Nullable)properties;

/**
 * 终止用户行为统计
 */
- (void)stopTrackUserAction;

@end

NS_ASSUME_NONNULL_END
