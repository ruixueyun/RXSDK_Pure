//
//  AppleLogin.h
//  iosSDK
//
//  Created by 刘清林 on 2020/6/29.
//  Copyright © 2020 weile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
 
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, AppleLoginType) {
    AppleLoginTypeUnknown = 0,
    AppleLoginTypeSuccessful,
    AppleLoginTypeUserSuccessful,
    AppleLoginTypeFailure
};
 
@interface AppleLogin : NSObject

+ (instancetype)sharedManager;

///  Apple登录
/// @param user 选填，已存user可以直接快速验证，没有传nil ，断网可验证。
/// @param view <#view description#>
/// @param rect <#rect description#>
/// @param block <#block description#>
//+(instancetype)appLogoinFromUser:(NSString *)user block:(void(^)(NSInteger state,NSString *msg,id data))block;
- (void)singInLogin:(NSString *)user block:(void(^)(NSInteger state,NSString *msg,id data))block;
@end
 
NS_ASSUME_NONNULL_END

