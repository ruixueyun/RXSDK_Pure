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
/**
 * 扩展字段，拼接url用
 */
@property (nonatomic, strong) NSDictionary *ext;
/**
 * 是否使用短链接  YES 使用短链接，NO 不使用短链接，默认 NO
 * @note 在 link 分享类型时使用短链接 SDK 会将最终的分享 url 替换为短链接
 * @note 在 image 分享类型时使用短链接 SDK 会将原始的长链接转成短链接后生成二维码并拼接到图片中
 */
@property (nonatomic, assign) BOOL useShortUrl;
/**
 * 是否自动上报分享结果  YES 自动上报，NO 不自动上报，默认 YES
 */
@property (nonatomic, assign) BOOL autoReport;
/**
 * 使用自动分享上报时可以写入自定义数据，手动上报时该属性不生效
 */
@property (nonatomic, strong) NSDictionary *properties;

@end

NS_ASSUME_NONNULL_END
