//
//  RXPublicHeader.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/7.
//

#ifndef RXPublicHeader_h
#define RXPublicHeader_h


#import "RXCommonRequestError.h"

typedef enum {
    RegistTypeAccount = 1, // 账号注册
    RegistTypePhone,  // 手机号注册
    RegistTypeEmail  // 邮箱注册
}RegistType;

typedef void(^RequestComplete)(NSDictionary * _Nullable response, RXCommonRequestError * _Nullable error);

#pragma mark -- 错误码
/*---- 支付 ----*/
#define CHECKORDERFAILED -10000  // 补单失败
#define NOPRODUCT        -10001  // 没有商品
#define IAPFAILED        -10002  // 苹果支付异常

#endif /* RXPublicHeader_h */
