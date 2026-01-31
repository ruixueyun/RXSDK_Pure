//
//  RXNotificationCenter.h
//  RXSDK-Pure
//
//  Created by 陈汉 on 2025/9/24.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

static NSString *const rxUserDefault_aliDNS = @"rxUserDefault_aliDNS";
static NSString *const rxUserDefault_tencentDNS = @"rxUserDefault_tencentDNS";

static NSString *const rxUserDefault_adjust_init = @"rxUserDefault_adjust_init";
static NSString *const rxUserDefault_adjust_event = @"rxUserDefault_adjust_event";
static NSString *const rxUserDefault_adjust_session = @"rxUserDefault_adjust_session";
static NSString *const rxUserDefault_adjust_phone = @"rxUserDefault_adjust_phone";
static NSString *const rxUserDefault_adjust_email = @"rxUserDefault_adjust_email";

static NSString *const rxUserDefault_bda_init = @"rxUserDefault_bda_init";
static NSString *const rxUserDefault_bda_start = @"rxUserDefault_bda_start";
static NSString *const rxUserDefault_bda_event = @"rxUserDefault_bda_event";

static NSString *const rxUserDefault_firebase_instanceid = @"rxUserDefault_firebase_instanceid";

static NSString *const rxUserDefault_share_w = @"rxUserDefault_share_w";
static NSString *const rxUserDefault_share_fb = @"rxUserDefault_share_fb";
static NSString *const rxUserDefault_share_messenger = @"rxUserDefault_share_messenger";
static NSString *const rxUserDefault_share_line = @"rxUserDefault_share_line";
static NSString *const rxUserDefault_share_tiktok = @"rxUserDefault_share_tiktok";
static NSString *const rxUserDefault_share_zalo = @"rxUserDefault_share_zalo";
static NSString *const rxUserDefault_share_snapchat = @"rxUserDefault_share_snapchat";
static NSString *const rxUserDefault_share_reddit = @"rxUserDefault_share_reddit";

static NSString *const rxUserDefault_login_w = @"rxUserDefault_login_w";
static NSString *const rxUserDefault_login_fb = @"rxUserDefault_login_fb";
static NSString *const rxUserDefault_login_google = @"rxUserDefault_login_google";
static NSString *const rxUserDefault_login_line = @"rxUserDefault_login_line";
static NSString *const rxUserDefault_login_tiktok = @"rxUserDefault_login_tiktok";
static NSString *const rxUserDefault_login_zalo = @"rxUserDefault_login_zalo";
static NSString *const rxUserDefault_login_snapchat = @"rxUserDefault_login_snapchat";
static NSString *const rxUserDefault_login_reddit = @"rxUserDefault_login_reddit";
static NSString *const rxUserDefault_login_ins = @"rxUserDefault_login_ins";

static NSString *const rxUserDefault_bind_w = @"rxUserDefault_bind_w";

static NSString *const rxUserDefault_asa = @"rxUserDefault_asa";

static NSString *const rxUserDefault_ui_showPrivacy = @"rxUserDefault_ui_showPrivacy";
static NSString *const rxUserDefault_ui_hidehud = @"rxUserDefault_ui_hidehud";
static NSString *const rxUserDefault_ui_gonggao = @"rxUserDefault_ui_gonggao";

static NSString *const rxUserDefault_osui_hidehud = @"rxUserDefault_osui_hidehud";
static NSString *const rxUserDefault_osui_gonggao = @"rxUserDefault_osui_gonggao";
static NSString *const rxUserDefault_osui_sync_fb = @"rxUserDefault_osui_sync_fb";
static NSString *const rxUserDefault_osui_sync_line = @"rxUserDefault_osui_sync_line";

static NSString *const rxUserDefault_uwa_gpm = @"rxUserDefault_uwa_gpm";

static NSString *const rxUserDefault_rx_gpm = @"rxUserDefault_rx_gpm";

static NSString *const rxUserDefault_alist = @"rxUserDefault_alist";

static NSString *const rxUserDefault_ab = @"rxUserDefault_ab";

static NSString *const rxUserDefault_oi = @"rxUserDefault_openinstall";

static NSString *const rxUserDefault_gdt_init = @"rxUserDefault_gdt_init";
static NSString *const rxUserDefault_gdt_register = @"rxUserDefault_gdt_register";
static NSString *const rxUserDefault_gdt_login = @"rxUserDefault_gdt_login";

typedef void(^DNSRequestSuccessBlock)(NSURLSessionDataTask * _Nonnull, id _Nullable);
typedef void(^DNSRequestFailBlock)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull);
typedef void(^ShareBlock)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull);

@interface RXNotificationCenter : NSObject

+ (void)postNoti:(NSString *)name object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;

@property (nonatomic, copy) DNSRequestSuccessBlock dnsSuccessBlock;
@property (nonatomic, copy) DNSRequestFailBlock dnsFailBlock;
@property (nonatomic, copy) RequestComplete shareDNSBlock;

@end

NS_ASSUME_NONNULL_END
