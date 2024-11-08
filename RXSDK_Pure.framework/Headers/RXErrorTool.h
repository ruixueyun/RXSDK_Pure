//
//  RXErrorTool.h
//  RXSDK
//
//  Created by 陈汉 on 2023/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/* 网络错误码 */
static NSInteger RXNetworkError_default = 1100;          // 网络连接错误
static NSInteger RXNetworkError_certificateBad = 1110;   // 证书错误
static NSInteger RXNetworkError_certificateValid = 1111; // 证书验证错误
static NSInteger RXNetworkError_noNetwork = 1120;        // 未知主机错误，检查网络连通性
static NSInteger RXNetworkError_connectionLost = 1130;   // 网络中断
static NSInteger RXNetworkError_timeOut = 1131;          // 超时错误，连接或请求数据超时


/* 初始化错误码 */
static NSInteger RXInitError_default = 2000;     // 初始化参数错误
static NSInteger RXInitError_init = 2001;        // SDK初始化错误，或未初始化
static NSInteger RXInitError_third = 2002;       // 三方初始化错误，或未初始化


/* 登录错误码 */
static NSInteger RXLoginError_default = 3000;             // 登录参数错误
static NSInteger RXLoginError_cancel = 3001;              // 登录取消或没授权
static NSInteger RXLoginError_third = 3002;               // 三方登录错误
static NSInteger RXLoginError_passwordRuleFail = 3100;    // 密码正则验证错误
static NSInteger RXLoginError_passwordEmpty = 3101;       // 密码不能为空
static NSInteger RXLoginError_passwordFit = 3102;         // 新旧密码不一致


/* iap错误码 */
static NSInteger RXIAPError_default = 4000;         // iap参数错误
static NSInteger RXIAPError_cancel = 4001;          // iap取消
static NSInteger RXIAPError_repeat = 4100;          // 重复下单
static NSInteger RXIAPError_iapFail = 4200;         // iap异常
static NSInteger RXIAPError_reFail = 4201;       // 补单失败
static NSInteger RXIAPError_noProducts = 4202;      // 没有商品
static NSInteger RXIAPError_ipaError = 4203;        // iap回调失败code0


/* 分享错误码 */
static NSInteger RXShareError_default = 5000;   // 分享参数错误
static NSInteger RXShareError_cancel = 5001;    // 分享取消
static NSInteger RXShareError_third = 5002;     // 三方分享错误


/* 权限错误码 */
static NSInteger RXLimitError_default = 6000;       // 隐私协议拒绝
static NSInteger RXLimitError_notOpen = 6001;       // 权限被拒绝或未开启
static NSInteger RXLimitError_closeView = 6010;     // 关闭窗口
static NSInteger RXLimitError_locationFail = 6020;  // 定位失败
static NSInteger RXLimitError_noApp = 6100;         // 未安装应用
static NSInteger RXLimitError_noWechat = 6101;      // 微信未安装

/* 数据上报 */
static NSInteger RXTrackError_byteLimit = 7001;      // 文件超过最大限制

/* 通用错误码 */
static NSInteger RXThirdError_default = 8000;       // 未知三方错误码
static NSInteger RXError_default = 9000;            // 未知错误


@interface RXErrorTool : NSObject

+ (NSInteger)getNetworkError:(NSInteger)code;

+ (NSString *)getRXErrorMsg:(NSInteger)code;

/**
 * 设置自定义错误码信息,由RXService调用
 */
+ (void)configErrorMsg:(NSDictionary *)msgDic;

/**
 * 获取自定义error信息, 有$code$、$msg$时替换为对应的code、msg
 * code 错误码
 * networkMsg 网络请求错误信息，仅限于网络请求场景使用此参数，其他场景此参数传空
 */
+ (NSString *)getCustomRXErrorMsg:(NSInteger)code withNetWorkErrorMsg:(NSString *)networkMsg;

@end

NS_ASSUME_NONNULL_END
