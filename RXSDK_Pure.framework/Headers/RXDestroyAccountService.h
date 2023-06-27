//
//  RXDestroyAccountService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/16.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

/** 按钮点击类型 */
typedef enum : NSUInteger {
    DestroyClickType_normal,  // 知道了
    DestroyClickType_repeal,  // 撤销
    DestroyClickType_login,   // 继续登录
    DestroyClickType_logout,  // 退出登录
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
