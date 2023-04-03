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
static NSInteger RXNetworkError_noNetwork = 1120;        // 证书验证错误
static NSInteger RXNetworkError_connectionLost = 1130;   // 网络中断
static NSInteger RXNetworkError_timeOut = 1131;          // 超时错误，连接或请求数据超时


/* 初始化错误码 */
static NSInteger RXInitError_default = 2000;     // 初始化参数错误
static NSInteger RXInitError_third = 2002;      // 三方初始化错误，或未初始化


/* 登录错误码 */
static NSInteger RXLoginError_default = 3000;             // 登录参数错误
static NSInteger RXLoginError_cancel = 3001;              // 登录取消或没授权
static NSInteger RXLoginError_third = 3002;               // 三方登录错误
static NSInteger RXLoginError_passwordRuleFail = 3100;    // 密码正则验证错误
static NSInteger RXLoginError_passwordEmpty = 3101;       // 密码不能为空


/* 支付错误码 */
static NSInteger RXPayError_default = 4000;         // 支付参数错误
static NSInteger RXPayError_repeat = 4100;          // 重复下单
static NSInteger RXPayError_iapFail = 4200;         // 苹果支付异常
static NSInteger RXPayError_repayFail = 4201;       // 补单失败
static NSInteger RXPayError_noProducts = 4202;      // 没有商品


/* 分享错误码 */
static NSInteger RXShareError_default = 5000;   // 分享参数错误
static NSInteger RXShareError_cancel = 5001;    // 分享取消
static NSInteger RXShareError_third = 5002;     // 三方分享错误


/* 权限错误码 */
static NSInteger RXLimitError_default = 6000;       // 隐私协议拒绝
static NSInteger RXLimitError_notOpen = 6001;       // 权限被拒绝或未开启
static NSInteger RXLimitError_closeView = 6010;     // 关闭窗口
static NSInteger RXLimitError_locationFail = 6020;  // 定位失败
static NSInteger RXLimitError_noWechat = 6101;      // 微信未安装


/* 通用错误码 */
static NSInteger RXThirdError_default = 8000;       // 未知三方错误码
static NSInteger RXError_default = 9000;            // 未知错误


@interface RXErrorTool : NSObject

+ (NSInteger)getNetworkError:(NSInteger)code;

+ (NSString *)getRXErrorMsg:(NSInteger)code;

@end

NS_ASSUME_NONNULL_END
