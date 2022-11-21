# RXSDK_Pure
瑞雪通行SDK-iOS

## 综述
### 关于定位
总体来说瑞雪是一个解决游戏产品通用问题的 BaaS 服务，主要通过私有化方式进行部署，即为每个项目团队都独立部署一套独占服务。

### 交付方式 
瑞雪主要功能分为两部：ToC 的接口服务与 ToB 的管理后台，其中接口的绝大部分运行参数通过管理后台由项目团队进行配置。

为了减轻项目团队的接入成本，瑞雪也提供了各端的 SDK 实现，CP 可以通过继承 SDK 快速接入使用瑞雪的各项能力。


## 功能使用
本文详细说明iOS端推流SDK API、SDK的基本使用流程，以及相关功能的使用示例。
在需要使用通行证功能的类中引用头文件`#import <RXSDK_Pure/RXSDK_Pure.h>`
异步api控制台均有log输出。格式为xxx成功，xxx失败。可通过控制台log查看api调用结果。
例如：登录成功：返回数据
     登录失败：返回数据
     获取验证码成功：返回数据
     获取验证码失败：返回数据

### 初始化
* 初始化用于本地保存productId、channelId、cpid、baseUrlList等数据，调用即成功。
* 接口原型：
```
/**
 * 初始化SDK
 * @param productId 产品id
 * @param channelId 渠道id
 * @param cpid 客户端id
 * @param baseUrlList 请求域名队列
 */
- (void)initWithProductId:(NSString *)productId
                channelId:(NSString *)channelId
                     cpid:(NSString *)cpid
              baseUrlList:(NSArray *)baseUrlList;
```
* 调用示例：
```
[[RXService sharedSDK] initWithProductId:@"1002"
                               channelId:@"100"
                                    cpid:@"1000049"
                             baseUrlList:@[@"https://ruixue.weiletest.com/"]];
```
### 通行证
### 登录
* 登录结果由代理异步回调，在需要接收回调的类中添加`<RXLoginDelegate>`，并指定代理接收对象`[RXServicesharedSDK].loginDelegate = self;`，实现代理方法。

* 首次登录调用1. 登录请求，将登录成功后返回的login_openid保存到本地，调用二次登录需要使用login_openid进行登录。
* 微信登录需要接入微信组件（登录、分享） 
* 一键登录需要接入一键登录 

**1. 登录请求**
* 接口原型：
```
/**
 * 登录请求
 * @param extDic 扩展字段，可传nil
 * @param username 非账号登录传空，账号注册为账号，手机注册为手机号，邮箱注册为邮箱
 * @param password 非账号登录传空
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 * @param loginType 登录类型
 * @param migrate_args 任意合法的  类型, 比如 string, number，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)loginWithExtDic:(NSMutableDictionary * _Nullable)extDic
               username:(NSString * _Nullable)username
               password:(NSString * _Nullable)password
            sign_fields:(NSArray * _Nullable)sign_fields
              loginType:(LoginType)loginType
           migrate_args:(id _Nullable)migrate_args;
```
* 调用示例：
```
[[RXService sharedSDK] loginWithExtDic:dic username:@"testaccount22" password:@"111111a" sign_fields:@[@"xxx", @"xxx"] loginType:LoginTypeVisitor migrate_args:nil];
```
**2. 二次登录**
* 接口原型：
```
/**
 * 二次登录
 * @param loginOpenId 登录返回的login_openid
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 * @param extDic 扩展字段，可传nil
 */
- (void)loginWithLoginOpenId:(NSString *)loginOpenId
                 sign_fields:(NSArray * _Nullable)sign_fields
                      extDic:(NSMutableDictionary * __nullable)extDic;
```
* 调用示例：
```
[[RXService sharedSDK] loginWithLoginOpenId:@"login_openid" sign_fields:@[@"xxx", @"xxx"] extDic:nil];
```
**3. 苹果登录**

苹果登录需在Xcode > General > Signing & Capabilities中添加Sign in with Apple

* 接口原型：
```
/**
 * 苹果登录
 * @param migrate_args 任意合法的  类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 * @param sign_fields 指定对登录成功后返回的特定字段, 使用 CPKEY 计算签名. CP 服务器可重新计算签名并与登录返回的签名比对, 作为对瑞雪登录数据的校验. 支持的字段包括: nickname, avatar, openid, region, sex, age, 计算签名的逻辑会对指定字段进行排序, 此处传参与顺序无关。类型为字符串数组 @[@"nickname",@"avatar"]  非必须
 */
- (void)loginReq_appleWithMigrate_args:(id _Nullable)migrate_args
                           sign_fields:(NSArray * _Nullable)sign_fields;
```
* 调用示例：
```
[[RXService sharedSDK] loginReq_appleWithMigrate_args:nil sign_fields:@[@"xxx", @"xxx"]];
```
**4. 回调**
* 接口原型：
```
/**
 * 登录回调
 * @param response 返回数据，登录失败返回nil
 * @param error 错误返回，登录成功返回nil
 */
- (void)rx_LoginCallBackWithResponse:(NSDictionary * _Nullable)response error:(RX_CommonRequestError *)error;
```
* 调用示例：
```
- (void)rx_LoginCallBackWithResponse:(NSDictionary *)response error:(RXCommonRequestError *)error
{
    if (!error) {
        NSLog(@"登录成功");
    } else {
        NSLog(@"登录失败");
    }
}
```

### 注册
* 接口原型：
```
/**
 * 注册
 * @param username 账号注册为账号，手机注册为手机号，邮箱注册为邮箱  必须
 * @param password 密码  必须
 * @param captchaCode 验证码  手机或邮箱注册为必须，账号注册非必须
 * @param nickname 昵称  非必须
 * @param avatarUrl 头像地址  非必须
 * @param sex 性别,1:男,0:女  非必须
 * @param migrate_args 任意合法的  类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)registWithUsername:(NSString *)username
                  password:(NSString *)password
               captchaCode:(NSString * _Nullable)captchaCode
                  nickname:(NSString * _Nullable)nickname
                 avatarUrl:(NSString * _Nullable)avatarUrl
                       sex:(NSString * _Nullable)sex
              migrate_args:(id _Nullable)migrate_args
                  complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] registWithUsername:@"chenhan111"
                                    password:@"111111a"
                                 captchaCode:nil
                                    nickname:nil
                                   avatarUrl:nil
                                         sex:nil
                                migrate_args:nil
                                    complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {
            
}];
```

### 申请注销账号
* 接口原型：
```
/**
 * 申请注销账号
 * @param IDCard 身份证  必须
 * @param realname 真实姓名  必须
 * @param cpdata CP自定义数据 非必须
 */
- (void)destroyAccountWithIDCard:(NSString *)IDCard
                        realname:(NSString *)realname
                          cpdata:(NSString * _Nullable)cpdata
                        complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXDestroyAccountService sharedSDK] destroyAccountWithIDCard:身份证 realname:姓名 cpdata:@{} complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 撤销注销申请
* 接口原型：
```
/**
 * 撤销注销申请
 */
- (void)repealDestroyAccountWithComplete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXDestroyAccountService sharedSDK] repealDestroyAccountWithComplete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 获取法务配置
* key列表：
key    备注
00001    用户服务协议
00002    隐私保护指引
00003    第三方SDK目录
00004    健康游戏公告
00005    适龄提示
00006    绿色游戏公告
00007    版号信息
00008    游戏账号注销条件
00009    游戏账号注销协议
00010    其他
* 接口原型：
```
/**
 * 获取法务配置信息
 */
- (void)getLegalInfo:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;
```
* 调用示例：
```
[[RXService sharedSDK] getLegalInfo:^(NSDictionary * _Nonnull response, RX_CommonRequestError * _Nonnull error) {
        
}];
```

## 公共API
### 自定义请求
客户端可通过自定义请求调用SDK未实现的临时接口。
* 接口原型：
```
/**
 * 自定义请求
 * @param url 接口名
 * @param header 请求头
 * @param body 请求参数
 */
- (void)requestWithUrl:(NSString *)url
                header:(NSMutableDictionary * _Nullable)header
                  body:(NSMutableDictionary * _Nullable)body
              complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;
```
* 调用示例：
```
    NSMutableDictionary *header = [NSMutableDictionary dictionary];
    NSMutableDictionary *body = [NSMutableDictionary dictionary];
    [[RXService sharedSDK] requestWithUrl:@"url" header:header body:body complete:^(NSDictionary * _Nonnull response, RXCommonRequestError * _Nonnull error) {
            
    }];
```
### 获取当前请求域名
* 接口原型：
```
/**
 * 获取当前请求域名
 */
- (NSString *)getApiDomain;
```
* 调用示例：
```
[[RXService sharedSDK] getApiDomain];
```

### 获取设备码
* 接口原型：
```
/**
 * 获取设备码
 */
- (NSString *)getDeviceIDInKeychain;
```
* 调用示例：
```
[[RXApiService sharedSDK] getDeviceIDInKeychain];
```

### 获取openID
获取SDK本地保存的openID。
* 接口原型：
```
/**
 * 获取openID
 */
- (NSString *)getOpenID;
```
* 调用示例：
```
[[RXService sharedSDK] getOpenID];
```

## 用户
### 获取验证码
* 获取验证码需填写对应意图 purpose
* type和target需对应，否则无法接收验证码
```
/**
 * 获取验证码
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱）
 * @param purpose 短信意图
 */
- (void)getCaptchaCodeWithType:(CaptchaType)type
                        target:(NSString *)target
                       purpose:(NSString *)purpose
                      complete:(RequestComplete)complete;
```
* type验证码类型类型：
```
CaptchaType_email    邮箱
CaptchaType_phone    手机
```
* purpose短信意图：
```
register    注册
bindphone    绑定手机
unbindphone    解绑手机
resetpwd    重置密码
bindemail    绑定邮箱
unbindemail    解绑邮箱
login    登录
setpwd    设置密码
```

### 绑定邮箱
* 接口原型：
```
/**
 * 绑定邮箱
 * @param captchaCode 验证码
 * @param password 密码
 * @param email 邮箱
 * @param migrate_args 任意合法的  类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingEmailWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              email:(NSString *)email
                       migrate_args:(id _Nullable)migrate_args
                           complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] bindingEmailWithCaptchaCode:@"0545" password:nil email:@"894306571@qq.com" migrate_args:nil complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 解绑邮箱
* 接口原型：
```
/**
 * 解绑邮箱
 * @param captchaCode 验证码
 * @param email 邮箱
 */
- (void)reliveBindingEmailWithCaptchaCode:(NSString *)captchaCode
                                    email:(NSString *)email
                                 complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] reliveBindingEmailWithCaptchaCode:@"0322" email:@"894306571@qq.com" complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {
            
}];
```

### 绑定手机
* 接口原型：
```
/**
 * 绑定手机
 * @param captchaCode 验证码
 * @param password 密码
 * @param phone 手机号
 * @param migrate_args 任意合法的  类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingPhoneWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              phone:(NSString *)phone
                       migrate_args:(id _Nullable)migrate_args
                           complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] bindingPhoneWithCaptchaCode:@"7238" password:nil phone:@"18698646213" migrate_args:nil complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 解绑手机
* 接口原型：
```
/**
 * 解绑手机
 * @param captchaCode 验证码
 * @param phone 手机号
 */
- (void)reliveBindingPhoneWithCaptchaCode:(NSString *)captchaCode
                                    phone:(NSString *)phone
                                 complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] reliveBindingPhoneWithCaptchaCode:@"0013" phone:@"12345678901" complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 获取用户信息
* 接口原型：
```
/**
 * 获取用户信息
 */
- (void)getUserInfoWithComplete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] getUserInfoWithComplete complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 修改用户信息
* 接口原型：
```
/**
 * 修改用户信息
 * @param avatarUrl 头像url 非必传
 * @param nickname 用户昵称 非必传
 * @param sex 性别 1男 0女 非必传
 * @param w_avatarurl 微信原始头像 非必传
 */
- (void)updateUserInfoWithAvatarUrl:(NSString *)avatarUrl
                           nickname:(NSString *)nickname
                                sex:(NSString *)sex
                        w_avatarurl:(NSString *)w_avatarurl
                           complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] updateUserInfoWithAvatarUrl:@"" nickname:@"test" sex:@"1" w_avatarurl:@"" complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {
            
}];
```

### 修改密码
新密码和旧密码不能一致。
* 接口原型：
```
/**
 * 修改密码
 * @param oldPwd 旧密码
 * @param newPwd 新密码
 */
- (void)updatePasswordWithOldPwd:(NSString *)oldPwd
                          newPwd:(NSString *)newPwd
                        complete:(RequestComplete)complete;
```
* 调用示例：
···
[[RXApiService sharedSDK] updatePasswordWithOldPwd:@"111111b" newPwd:@"111111a" complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {
            
}];
```

### 重置密码
* 接口原型：
```
/**
 * 重置密码
 * @param username 用户名
 * @param password 密码
 * @param captchaCode 验证码
 * @param migrate_args 任意合法的  类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)resetPasswordWithUsername:(NSString *)username
                         password:(NSString *)password
                      captchaCode:(NSString *)captchaCode
                     migrate_args:(id _Nullable)migrate_args
                         complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] resetPasswordWithUsername:@"18698646213" password:@"111111b" captchaCode:@"4599" migrate_args:nil complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {

}];
```

### 实名认证
* 接口原型：
```
/**
 * 实名认证
 * @param realName 真实姓名  必须
 * @param idCard 身份证  必须
 */
- (void)approveWithRealName:(NSString *)realName
                     idCard:(NSString *)idCard
                   complete:(RequestComplete)complete;
```
* 调用示例：
```
[[RXApiService sharedSDK] approveWithRealName:姓名 idCard:身份证 complete:^(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error) {
                
}];
```
