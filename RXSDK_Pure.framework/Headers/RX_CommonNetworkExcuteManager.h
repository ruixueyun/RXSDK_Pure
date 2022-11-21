//
//  RX_NetworkExcuteManager.h
//  OverseaSocialApp
//
//  Created by 陈汉 on 2021/4/15.
//

#import <Foundation/Foundation.h>
#import "RX_CommonNetworkExcute.h"
#import "RXCommonApiManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface RX_CommonNetworkExcuteManager : NSObject

+ (RX_CommonNetworkExcute *) commonRequestClient;

+ (NSMutableDictionary *)headParams;

@end

NS_ASSUME_NONNULL_END
