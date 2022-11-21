//
//  RXConfig.h
//  RXSDK
//
//  Created by 陈汉 on 2021/9/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXConfig : NSObject

+ (instancetype)sharedManager;

/**
 * 环境  -- 0beta  1生产  默认生产
 */
@property (nonatomic, assign) NSInteger envSer;

/**
 * 通用域名
 */
@property (nonatomic, copy) NSString *apiDomain;

/**
 * 是否是国际版  OS需要设置为YES，其他target设置为NO
 */
@property (nonatomic, assign) BOOL isOS;

@end

NS_ASSUME_NONNULL_END
