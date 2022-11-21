//
//  RXShareService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/6.
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

typedef void(^ShareCallBack)(BOOL success);

@interface RXShareService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取分享信息
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码 非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)getShareInfoWithFunc:(NSString *)func
                    platform:(NSString *)platform
                      region:(NSString *)region
                   transmits:(NSString * _Nullable)transmits
                         ext:(NSDictionary * _Nullable)ext
                    complete:(RequestComplete)complete;

/**
 * 系统分享（直接调用，不需要获取分享信息）
 * @param func 埋点标识  必须
 * @param platform 分享平台 wechat
 * @param region 地区码  非必须
 * @param transmits 透传参数，原样返回， 请使用key=value形式，并对值使用urlencode，返回时会原样返回  非必须
 * @param ext 扩展字段，拼接url用  非必须
 */
- (void)SystemShareWithFunc:(NSString *)func
                   platform:(NSString *)platform
                     region:(NSString *)region
                  transmits:(NSString * _Nullable)transmits
                        ext:(NSDictionary * _Nullable)ext
                   complete:(ShareCallBack)complete;

/**
 * 系统分享
 * @param shareInfo 获取分享信息返回的内容  必须
 */
- (void)SystemShareWithShareInfo:(NSDictionary *)shareInfo
                        complete:(ShareCallBack)complete;


/**
 * 获取通路配置
 */
- (void)getSharePlatformsWithComplete:(RequestComplete)complete;

/**
 * 分享上报
 * @param distinctId 用户唯一标识，一般为 openid（由CP调用时传入），nil默认为openid
 * @param properties 自定义属性
 */
- (void)shareReportWithDistinctId:(NSString *)distinctId
                       properties:(NSDictionary * _Nullable)properties
                         complete:(RequestComplete)complete;

@end

NS_ASSUME_NONNULL_END
