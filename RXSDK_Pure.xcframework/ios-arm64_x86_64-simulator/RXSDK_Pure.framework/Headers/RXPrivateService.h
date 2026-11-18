//
//  RXPrivateService.h
//  RXSDK
//
//  Created by 陈汉 on 2024/4/10.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXPrivateService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 发送失败通知
 * @note UIKit 专用
 */
- (void)postLoginError:(NSDictionary *)error
             loginType:(LoginType)loginType;

/**
 * 获取请求地区
 */
- (NSString *)getRequestArea;

/**
 * 绑定账号
 */
- (void)bindThirdAccountWithMethod:(NSString *)method
                               ext:(NSDictionary *)ext
                          complete:(RequestComplete)complete;

/**
 * 处理 URL Scheme 回调
 * @param app 应用实例
 * @param url 回调 URL
 * @param options 附加参数
 * @return 是否成功处理
 * @note 需在 AppDelegate 的 application:openURL:options: 方法中调用
 */
- (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<NSString *, id> *)options;

/**
 * 处理 Universal Link 回调
 * @param application 应用实例
 * @param userActivity 用户活动对象
 * @param restorationHandler 恢复处理回调
 * @return 是否成功处理
 * @note 需在 AppDelegate 的 application:continueUserActivity:restorationHandler: 方法中调用
 */
- (BOOL)application:(UIApplication *)application
continueUserActivity:(NSUserActivity *)userActivity
  restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

@end

NS_ASSUME_NONNULL_END
