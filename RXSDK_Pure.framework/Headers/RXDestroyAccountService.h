//
//  RXDestroyAccountService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/16.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

/** 按钮点击类型 */
typedef enum : NSUInteger {
    DestroyClickType_normal,  // 知道了
    DestroyClickType_repeal,  // 撤销
    DestroyClickType_login,   // 继续登录
} DestroyClickType;


@interface RXDestroyAccountService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 申请注销账号
 * @param IDCard 身份证  必须
 * @param realname 真实姓名  必须
 * @param cpdata CP自定义数据 非必须
 */
- (void)destroyAccountWithIDCard:(NSString *)IDCard
                        realname:(NSString *)realname
                          cpdata:(NSString * _Nullable)cpdata
                        complete:(RequestComplete)complete;

/**
 * 撤销注销申请
 */
- (void)repealDestroyAccountWithComplete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
