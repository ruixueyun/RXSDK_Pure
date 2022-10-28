//
//  RXPublicHeader.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/7.
//

#ifndef RXPublicHeader_h
#define RXPublicHeader_h


#import "RX_CommonRequestError.h"

typedef enum {
    RegistTypeAccount = 1, // 账号注册
    RegistTypePhone,  // 手机号注册
    RegistTypeEmail  // 邮箱注册
}RegistType;

typedef enum {
    LoginTypeVisitor,  // 游客登录
    LoginTypeAccount,  // 账号登录
    LoginTypeEmail,    // 邮箱登录
    LoginTypeAuth,     // 本机一键登录
    LoginTypeW,        // 微信登录
    LoginTypeApple,    // 苹果登录
    LoginTypeQuick,    // 二次登录
    LoginTypeGoogle,   // 谷歌登录
    LoginTypeFacebook, // facebook登录
    LoginTypeVirtual   // 虚拟登录
}LoginType;


typedef void(^RequestComplete)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error);

#pragma mark -- 错误码
/*---- 支付 ----*/
#define CHECKORDERFAILED -10000  // 补单失败
#define NOPRODUCT        -10001  // 没有商品
#define IAPFAILED        -10002  // 苹果支付异常

#endif /* RXPublicHeader_h */
