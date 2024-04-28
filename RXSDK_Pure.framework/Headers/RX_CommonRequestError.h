//
//  RXRequestError.h
//  OverseaSocialApp
//
//  Created by 陈汉 on 2021/4/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RX_CommonRequestError : NSObject
@property (nonatomic, strong) NSError * error;    // http错误信息
@property (nonatomic, strong) NSDictionary *responesObject;  // 服务端错误信息
@end

NS_ASSUME_NONNULL_END
