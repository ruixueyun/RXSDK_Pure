//
//  RXSdkInitConfig.h
//  RXSDK
//
//  Created by 陈汉 on 2024/1/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXSdkInitConfig : NSObject

/**
 * CP 唯一 ID，从 7 位数 1000000 开始递增
 */
@property (nonatomic, copy) NSString *cpId;
/**
 * 瑞雪内部的应用 ID，由各 CP 自行在后台创建，字符串类型
 */
@property (nonatomic, copy) NSString *productId;
/**
 * 瑞雪内部 CP 某应用的渠道 ID，由各 CP 自行在后台创建，字符串类型
 */
@property (nonatomic, copy) NSString *channelId;
/**
 * 瑞雪域名地址 https://domain.com/格式
 */
@property (nonatomic, copy) NSArray *baseUrlList;
/**
 * 日志开关，debug默认开启，release默认关闭
 */
@property (nonatomic, copy) NSString *isLogEnable;
/**
 * 首次启动是否展示用户隐私授权页面，YES展示，NO不展示
 * @note 默认NO不展示
 */
@property (nonatomic, assign) BOOL usePrivacy;
/**
 * 自定义协议键值对
 * @note key:00001（00001为示例，实际值是瑞雪协议key）或链接  value:《用户协议》
 */
@property (nonatomic, strong) NSMutableDictionary *agreementMap;
/**
 * 协议标题
 * @note 默认为 “用户协议和隐私政策”
 */
@property (nonatomic, copy) NSString *agreementTitle;
/**
 * 是否打开DNS，YES打开，NO关闭，默认为NO
 */
@property (nonatomic, assign) BOOL isUseDNS;
/**
 * 是否开启竞速，YES打开，NO关闭，默认为NO
 */
@property (nonatomic, assign) BOOL openRacing;

@end

NS_ASSUME_NONNULL_END
