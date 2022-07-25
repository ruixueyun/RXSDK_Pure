//
//  RXContactService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/2.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"
#import "RXLocationModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXContactService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取位置信息
 */
- (void)getLocationInfo:(void(^)(RXLocationModel *location))complete;

/**
 * 开启定位上报
 * @param duration 上报间隔（秒），最小30
 * @param types 坐标分组类型，自定义，必传
 */
- (void)openLocationReportWithDuration:(NSInteger)duration
                                 types:(NSArray * __nonnull)types;

/**
 * 关闭定位上报
 */
- (void)stopLocationReport;

/**
 * 删除位置信息
 * @param types 用户类型定义
 */
- (void)deleteLocationWithTypes:(NSArray *)types
                       complete:(RequestComplete)complete;

/**
 * 获取附近人
 * @param radius 半径（米）
 * @param count 查询数量，（默认0，0为全部）非必传
 * @param page 页数，从1开始
 * @param page_size 每页数量
 * @param type 查询类型
 */
- (void)getRadiusAccount:(NSInteger)radius
                   count:(NSInteger)count
                    page:(NSInteger)page
               page_size:(NSInteger)page_size
                    type:(NSString *)type
                complete:(RequestComplete)complete;

/**
 * 设置用户自定义信息
 * @param custom 自定义信息，最大长度为 512 字节
 */
- (void)setUserCustomWithCustom:(NSString *)custom
                       complete:(RequestComplete)complete;

/**
 * 添加自定义关系
 * @param target 目标openId  必须
 * @param types 自定义关系类型列表，value必须为BOOL  必须
 * @param target_remarks 用户给Target设置的备注信息（最长512字符） 非必须
 * @param user_remarks Target给用户设置的备注信息（最长512字符） 非必须
 */
- (void)addRelationWithTarget:(NSString *)target
                        types:(NSDictionary *)types
               target_remarks:(NSString * _Nullable)target_remarks
                 user_remarks:(NSString * _Nullable)user_remarks
                     complete:(RequestComplete)complete;

/**
 * 删除自定义关系
 * @param target 目标openId  必须
 * @param types 自定义关系类型列表，value必须为BOOL  必须
 */
- (void)deleteRelationWithTarget:(NSString *)target
                           types:(NSDictionary *)types
                        complete:(RequestComplete)complete;

/**
 * 更新用户自定义关系备注
 * @param target 目标openId  必须
 * @param target_remarks 用户给Target设置的备注信息（最长512字符） 必须
 * @param type 自定义关系类型  必须
 */
- (void)updateRemarksWithTarget:(NSString *)target
                 target_remarks:(NSString *)target_remarks
                           type:(NSString *)type
                       complete:(RequestComplete)complete;

/**
 * 获取自定义关系列表
 * @param type 自定义关系类型  必须
 */
- (void)getRelationListWithType:(NSString *)type
                       complete:(RequestComplete)complete;

/**
 * 添加好友
 * @param target 目标openId  必须
 * @param target_remarks 用户给Target设置的备注信息（最长512字符） 非必须
 * @param user_remarks Target给用户设置的备注信息（最长512字符） 非必须
 */
- (void)addFriendWithTarget:(NSString *)target
             target_remarks:(NSString * _Nullable)target_remarks
               user_remarks:(NSString * _Nullable)user_remarks
                   complete:(RequestComplete)complete;

/**
 * 删除好友
 * @param target 目标openId  必须
 */
- (void)deleteFriendWithTarget:(NSString *)target
                      complete:(RequestComplete)complete;

/**
 * 更新好友备注
 * @param target 目标openId  必须
 * @param target_remarks 用户给Target设置的备注信息（最长512字符） 必须
 */
- (void)updateFriendRemarkWithTarget:(NSString *)target
                      target_remarks:(NSString *)target_remarks
                            complete:(RequestComplete)complete;

/**
 * 获取好友列表
 */
- (void)getFriendListWithComplete:(RequestComplete)complete;

/**
 * 创建排行榜
 * @param rankId 类型 1:日榜 3:月榜 4:季榜 5:半年榜 6:年榜 99:长期榜单  必须
 */
- (void)createRankWithRankId:(NSString *)rankId
                    complete:(RequestComplete)complete;

/**
 * 获取排行榜
 * @param rankId  必须
 * @param userId  必须
 */
- (void)getRankListWithRankId:(NSString *)rankId
                       userId:(NSInteger)userId
                     complete:(RequestComplete)complete;

/**
 * 上报排行榜分数
 * @param rankId 排行榜标识  必须
 * @param openId 用户openId  必须
 * @param score 分数  必须
 * @param userId 用户userId  必须
 */
- (void)reportRankScoreWithRankId:(NSString *)rankId
                           openId:(NSString *)openId
                            score:(NSInteger)score
                           userId:(NSInteger)userId
                         complete:(RequestComplete)complete;

/**
 * 获取openId
 * @param userId 用户userId  必须
 */
- (void)getOpenIdWithUserId:(NSInteger)userId
                   complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
