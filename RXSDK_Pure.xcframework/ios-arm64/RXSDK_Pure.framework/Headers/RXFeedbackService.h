//
//  RXFeedbackService.h
//  RXSDK
//
//  Created by 陈汉 on 2023/10/12.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXFeedbackService : NSObject

@property (nonatomic, assign) NSInteger feedbackId;  // 反馈id
@property (nonatomic, copy) NSString *logPath;  // 反馈id

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取意见反馈类型
 */
- (void)getFeedbackKindListWithComplete:(RequestComplete)complete;

/**
 * 创建意见反馈
 * @note params 说明
 - game_id:游戏ID    #NSInteger
 - kind_id:意见反馈ID    #NSInteger
 - kind_name:"意见反馈类型"    #NSString
 - priority:紧急程度 1:紧急 2:不紧急    #NSInteger
 - content:"反馈内容"    #NSString
 - picture:"图片url"    #NSString
 - player_gameid:"玩家游戏id"    #NSString
 - send_voided_mails:作废是否发邮件 1:发 2:不发    #NSInteger
 */
- (void)createFeedbackWithParams:(NSDictionary *)params
                        complete:(RequestComplete)complete;

/**
 * 满意度评价
 * @note params 说明
 - key_number:创建意见反馈的ID    #NSInteger
 - pleased_status:满意度 1:满意 2:不满意    #NSInteger
 - reason:"理由"    #NSString
 */
- (void)satisfactionEvaluationWithParams:(NSDictionary *)params
                                complete:(RequestComplete)complete;

/**
 * 上报反馈日志
 * @note 客服后台创建反馈时生效
 * @param data 文件二进制
 */
- (void)reportFeedbackLogWithData:(NSData *)data
                         complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
