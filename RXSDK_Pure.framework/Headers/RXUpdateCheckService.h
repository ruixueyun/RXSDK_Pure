//
//  RXUpdateCheckService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/16.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXUpdateCheckService : NSObject

@property (nonatomic, assign) BOOL isTest;  // YES测试， NO正式，默认正式

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 大厅更新检查
 * @param region 地区码  非必须
 * @param client_version 客户端大厅当前版本  非必须
 */
- (void)checkUpdate_AppWithRegion:(NSString *)region
                   client_version:(NSString *)client_version
                         complete:(RequestComplete)complete;

/**
 * 活动更新检查
 * @param game_version 当前游戏版本  必须
 * @param game_check_version 指定游戏版本  非必须
 * @param short_name 活动短名  必须
 */
- (void)checkUpdate_ActivityWithGame_version:(NSInteger)game_version
                          game_check_version:(NSString *)game_check_version
                                  short_name:(NSString *)short_name
                                    complete:(RequestComplete)complete;

/**
 * 游戏更新检查
 * @param game_id 游戏ID  必须
 * @param game_version 当前游戏版本  必须
 * @param game_check_version 指定游戏版本  非必须
 */
- (void)checkUpdate_GameWithGame_id:(NSInteger)game_id
                       game_version:(NSInteger)game_version
                 game_check_version:(NSString *)game_check_version
                           complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
