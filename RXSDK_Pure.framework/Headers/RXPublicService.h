//
//  RXPublicService.h
//  RXSDK
//
//  Created by 陈汉 on 2023/12/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXPublicService : NSObject

@property (nonatomic, copy) NSString *wAppid;
@property (nonatomic, copy) NSString *aliAuthKey;
@property (nonatomic, copy) NSString *googleClientId;

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取登录方式
 */
- (NSMutableArray *)getLoginMethods;

@end

NS_ASSUME_NONNULL_END
