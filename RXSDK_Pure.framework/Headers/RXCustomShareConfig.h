//
//  RXCustomShareConfig.h
//  RXSDK
//
//  Created by 陈汉 on 2024/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXCustomShareConfig : NSObject

/**
 * 分享平台
 * wechat、system、facebook、messenger、line、tiktok
 */
@property (nonatomic, copy) NSString *platform;
/**
 * 三方 appid
 */
@property (nonatomic, copy) NSString *thirdAppid;
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
 * 分享类型，text/image/landing/link/video
 */
@property (nonatomic, copy) NSString *materialType;
/**
 * url或本地路径
 */
@property (nonatomic, copy) NSString *image;
/**
 * url或本地路径
 * @note 多图
 */
@property (nonatomic, copy) NSArray *images;
/**
 * url或本地路径
 */
@property (nonatomic, copy) NSString *video;
/**
 * url或本地路径
 * @note 多视频
 */
@property (nonatomic, copy) NSArray *videos;
/**
 * 分享链接
 */
@property (nonatomic, copy) NSString *url;
/**
 * 分享标题
 */
@property (nonatomic, copy) NSString *title;
/**
 * 分享描述
 */
@property (nonatomic, copy) NSString *content;
/**
 * 分享到好友还是朋友圈   0 好友 1 朋友圈
 */
@property (nonatomic, assign) NSInteger shareScene;
/**
 * 二维码坐标 x
 */
@property (nonatomic, assign) NSInteger x;
/**
 * 二维码坐标 y
 */
@property (nonatomic, assign) NSInteger y;
/**
 * 二维码坐标 width
 */
@property (nonatomic, assign) NSInteger width;
/**
 * 二维码坐标 height
 */
@property (nonatomic, assign) NSInteger height;
/**
 * 客户端透传数据
 */
@property (nonatomic, strong) NSDictionary *game_info;

@end

NS_ASSUME_NONNULL_END
