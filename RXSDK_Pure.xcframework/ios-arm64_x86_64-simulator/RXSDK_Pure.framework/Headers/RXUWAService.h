//
//  RXUWAService.h
//  RXSDK-Pure
//
//  Created by root11 on 2024/8/27.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"


#pragma mark - 注意！！！GPM指标由自定义SDK与UWA两种方式上传，SDK直接在此类中执行定时获取并上传；UWA在C#获取主库中的开关与时间间隔，并创建定时器上传。如需修改，则需要修改SDK与C#两处

NS_ASSUME_NONNULL_BEGIN

typedef void (^IOSOnPerformanceCallback)(NSString *data);

@interface RXUWAService : NSObject

@property (nonatomic, copy) IOSOnPerformanceCallback getInfoBlock;

/**
 * 单例
 */
+ (instancetype)sharedSDK;

/**
 * GPM性能指标上报
 * SDK会根据配置定期上报,上报间隔（秒），默认60s
 */
- (void)configWithReportTime;

/**
 * Unity获取上传类型与上传间隔
 */
- (void)getTypeAndTsWithBlock:(IOSOnPerformanceCallback)callBack;

/**
 * 上传Unity UWA信息，用于Unity调用此方法上传新能指标
 */
- (void)uploadUWAInfo:(NSString *)infoString;

/**
 * 获取uwa上报的用户属性的不同，并同步到本地
 */
- (NSDictionary *)getUwaInfoCompareWithDict:(NSDictionary *)dict;

/**
 * 获取sdk上报的属性的不同，并同步到本地
 */
- (NSDictionary *)getSDKInfoCompareWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
