//
//  RXOSSPutManager.h
//  RXSDK
//
//  Created by 陈汉 on 2023/12/8.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXOSSPutManager : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 上传文件
 * @note 有上传进度回调
 * @param bodyData 文件二进制
 */
- (void)uploadWithBodyData:(NSData *)bodyData ossPath:(NSString *)ossPath process:(void(^)(float process))process complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
