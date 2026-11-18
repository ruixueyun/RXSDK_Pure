//
//  RXRequestConfigure.h
//  OverseaSocialApp
//
//  Created by 陈汉 on 2021/4/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RX_CommonRequestConfigure : NSObject
@property (nonatomic, strong) NSMutableDictionary * mheadParams;
@property (nonatomic, strong) NSString * baseUrl;
@end

NS_ASSUME_NONNULL_END
