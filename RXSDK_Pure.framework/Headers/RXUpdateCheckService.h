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
 * 大厅更新检查（GET版本，不返回下载地址）
 * @param region 地区码  非必须
 * @param client_version 客户端大厅当前版本  非必须
 * @param type 脚本类型，默认lua，可选json，u3d等  非必须
 * @param json 输出文件后缀，默认lua，可选json  非必须
 */
- (void)checkUpdate_AppWithRegion:(NSString * _Nullable)region
                   client_version:(NSString * _Nullable)client_version
                             type:(NSString * _Nullable)type
                             json:(NSString * _Nullable)json
                         complete:(RequestComplete)complete;

/**
 * 大厅更新检查（POST版本，返回下载地址）
 * @param region 地区码  非必须
 * @param client_version 客户端大厅当前版本  非必须
 * @param games key客户端游戏id value版本  非必须
 * @param activities key客户端活动别名 value版本  非必须
 * @param type 脚本类型，默认lua，可选json，u3d等  非必须
 * @param json 输出文件后缀，默认lua，可选json  非必须
 */
- (void)checkUpdate_AppWithRegion:(NSString * _Nullable)region
                   client_version:(NSString * _Nullable)client_version
                            games:(NSDictionary * _Nullable)games
                       activities:(NSDictionary * _Nullable)activities
                             type:(NSString * _Nullable)type
                             json:(NSString * _Nullable)json
                         complete:(RequestComplete)complete;

/**
 * 活动更新检查
 * @param game_version 当前游戏版本  必须
 * @param game_check_version 指定游戏版本  非必须
 * @param short_name 活动短名  必须
 * @param type 脚本类型，默认lua，可选json，u3d等  非必须
 * @param json 输出文件后缀，默认lua，可选json  非必须
 */
- (void)checkUpdate_ActivityWithGame_version:(NSInteger)game_version
                          game_check_version:(NSString * _Nullable)game_check_version
                                  short_name:(NSString *)short_name
                                        type:(NSString * _Nullable)type
                                        json:(NSString * _Nullable)json
                                    complete:(RequestComplete)complete;

/**
 * 游戏更新检查
 * @param game_id 游戏ID  必须
 * @param game_version 当前游戏版本  必须
 * @param game_check_version 指定游戏版本  非必须
 * @param type 脚本类型，默认lua，可选json，u3d等  非必须
 * @param json 输出文件后缀，默认lua，可选json  非必须
 */
- (void)checkUpdate_GameWithGame_id:(NSInteger)game_id
                       game_version:(NSInteger)game_version
                 game_check_version:(NSString * _Nullable)game_check_version
                               type:(NSString * _Nullable)type
                               json:(NSString * _Nullable)json
                           complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
