//
//  RXLoginInfo.h
//  RXSDK
//
//  Created by 陈汉 on 2022/10/27.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXLoginInfo : NSObject
@property (nonatomic, strong) NSMutableDictionary *extDic;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *sign_fields;
@property (nonatomic, assign) LoginType loginType;
@property (nonatomic, copy) id migrate_args;
@end

NS_ASSUME_NONNULL_END
