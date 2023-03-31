//
//  RXPublicHeader.h
//  RXSDK
//
//  Created by 陈汉 on 2021/12/7.
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
    LoginTypeVirtual,  // 虚拟登录
    LoginTypeCapCode,  // 验证码登录
    LoginTypeLine      // line登录
}LoginType;


typedef void(^RequestComplete)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error);

#endif /* RXPublicHeader_h */
