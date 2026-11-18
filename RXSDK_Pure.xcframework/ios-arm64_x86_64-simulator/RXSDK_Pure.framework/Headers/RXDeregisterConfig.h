//
//  RXDeregisterConfig.h
//  RXSDK
//
//  Created by 陈汉 on 2024/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXDeregisterConfig : NSObject

// 身份证 必须
@property (nonatomic, copy) NSString *idCard;
// 真实姓名 必须
@property (nonatomic, copy) NSString *realname;
// CP自定义数据 非必须
@property (nonatomic, copy) NSString *cpdata;
// 三方渠道透传数据 非必须
@property (nonatomic, copy) NSDictionary *thirdParams;

@end

NS_ASSUME_NONNULL_END
