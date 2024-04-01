//
//  RXShareConfig.h
//  RXSDK
//
//  Created by 陈汉 on 2024/1/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXShareConfig : NSObject

/**
 * 埋点标识
 */
@property (nonatomic, copy) NSString *func;
/**
 * 分享平台
 * wechat、system、facebook、messenger、line、tiktok、zalo
 */
@property (nonatomic, copy) NSString *platform;
/**
 * 地区码
 */
@property (nonatomic, copy) NSString *region;
/**
 * 透传参数，原样返回
 */
@property (nonatomic, copy) NSString *transmits;
/**
 * iOS唤醒协议
 */
@property (nonatomic, copy) NSString *iOSScheme;
/**
 * android唤醒协议
 */
@property (nonatomic, copy) NSString *androidScheme;
/**
 * 由cp控制是否使用游戏协议，如传0则在落地页上操作不会尝试打开应用，直接跳转到对应商店，如传1则会尝试打开应用
 */
@property (nonatomic, copy) NSString *useScheme;
/**
 * 是否读取缓存，默认不读取
 */
@property (nonatomic, assign) BOOL readCache;
/**
 * 分享到好友还是朋友圈   0 好友 1 朋友圈
 */
@property (nonatomic, assign) NSInteger shareScene;
/**
 * 客户端透传数据
 */
@property (nonatomic, strong) NSDictionary *game_info;

@end

NS_ASSUME_NONNULL_END
