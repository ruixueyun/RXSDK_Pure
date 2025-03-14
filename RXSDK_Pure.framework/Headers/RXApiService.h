//
//  RXApiService.h
//  RXSDK
//
//  Created by 陈汉 on 2021/11/9.
//

#import <Foundation/Foundation.h>
#import "RXPublicHeader.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    CaptchaType_email,  // 邮箱
    CaptchaType_phone,   // 手机
} CaptchaType; // 验证码类型

@interface RXApiService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 获取验证码
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱），传空或nil默认为当前绑定的手机或邮箱
 * @param purpose 用途
 * ！register           // 注册
 * ！bindphone      // 绑定手机
 * ！unbindphone  // 解绑手机
 * ！resetpwd        // 重置密码
 * ！changepwd    // 修改密码
 * ！bindemail       // 绑定邮箱
 * ！unbindemail   // 解绑邮箱
 * ！login               // 登录
 */
- (void)getCaptchaCodeWithType:(CaptchaType)type
                        target:(NSString *)target
                       purpose:(NSString *)purpose
                      complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use sendCaptchaWithType:target:purpose:complete instead");

/**
 * 发送验证码
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱），传空或nil默认为当前绑定的手机或邮箱
 * @param purpose 用途
 * ！register           // 注册
 * ！bindphone      // 绑定手机
 * ！unbindphone  // 解绑手机
 * ！resetpwd        // 重置密码
 * ！changepwd    // 修改密码
 * ！bindemail       // 绑定邮箱
 * ！unbindemail   // 解绑邮箱
 * ！login               // 登录
 */
- (void)sendCaptchaWithType:(CaptchaType)type
                     target:(NSString *)target
                    purpose:(NSString *)purpose
                   complete:(RequestComplete)complete;

/**
 * 发送验证码
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱），传空或nil默认为当前绑定的手机或邮箱
 * @param randstr 图形验证随机串，可传空
 * @param ticket 图形验证凭证，可传空
 * @param purpose 用途
 * ！register           // 注册
 * ！bindphone      // 绑定手机
 * ！unbindphone  // 解绑手机
 * ！resetpwd        // 重置密码
 * ！changepwd    // 修改密码
 * ！bindemail       // 绑定邮箱
 * ！unbindemail   // 解绑邮箱
 * ！login               // 登录
 */
- (void)sendCaptchaWithType:(CaptchaType)type
                     target:(NSString *)target
                    purpose:(NSString *)purpose
                     ticket:(NSString *)ticket
                    randstr:(NSString *)randstr
                   complete:(RequestComplete)complete;

/**
 * 校验验证码
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱），传空或nil默认为当前绑定的手机或邮箱
 * @param captcha_code 验证码
 * @param purpose 用途
 * ！register           // 注册
 * ！bindphone      // 绑定手机
 * ！unbindphone  // 解绑手机
 * ！resetpwd        // 重置密码
 * ！changepwd    // 修改密码
 * ！bindemail       // 绑定邮箱
 * ！unbindemail   // 解绑邮箱
 * ！login               // 登录
 */
- (void)verifyCaptchaCodeWithType:(CaptchaType)type
                           target:(NSString *)target
                          purpose:(NSString *)purpose
                     captcha_code:(NSString *)captcha_code
                         complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use verifyCaptchaWithType:target:purpose:complete instead");

/**
 * 校验验证码
 * @param type 验证码类型
 * @param target 发送的目标（手机或邮箱），传空或nil默认为当前绑定的手机或邮箱
 * @param captchaCode 验证码
 * @param purpose 用途
 * ！register           // 注册
 * ！bindphone      // 绑定手机
 * ！unbindphone  // 解绑手机
 * ！resetpwd        // 重置密码
 * ！changepwd    // 修改密码
 * ！bindemail       // 绑定邮箱
 * ！unbindemail   // 解绑邮箱
 * ！login               // 登录
 */
- (void)verifyCaptchaWithType:(CaptchaType)type
                       target:(NSString *)target
                      purpose:(NSString *)purpose
                  captchaCode:(NSString *)captchaCode
                     complete:(RequestComplete)complete;

/**
 * 绑定邮箱
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param captchaCode 验证码
 * @param password 密码
 * @param email 邮箱
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingEmailWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              email:(NSString *)email
                       migrate_args:(id _Nullable)migrate_args
                           complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use bindEmailWithEmail:password:CaptchaCode:migrateArgs:complete instead");

/**
 * 绑定邮箱
 * @param captchaCode 验证码
 * @param password 密码
 * @param email 邮箱
 * @param migrateArgs 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindEmailWithEmail:(NSString *)email
                  password:(NSString *)password
               captchaCode:(NSString *)captchaCode
               migrateArgs:(id _Nullable)migrateArgs
                  complete:(RequestComplete)complete;

/**
 * 解绑邮箱
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param captchaCode 验证码
 * @param email 邮箱
 */
- (void)reliveBindingEmailWithCaptchaCode:(NSString *)captchaCode
                                    email:(NSString *)email
                                 complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use unBindEmailWithEmail:captchaCode:complete instead");

/**
 * 解绑邮箱
 * @param captchaCode 验证码
 * @param email 邮箱
 */
- (void)unBindEmailWithEmail:(NSString *)email    
                 captchaCode:(NSString *)captchaCode
                    complete:(RequestComplete)complete;

/**
 * 绑定手机
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param captchaCode 验证码
 * @param password 密码
 * @param phone 手机号
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindingPhoneWithCaptchaCode:(NSString *)captchaCode
                           password:(NSString *)password
                              phone:(NSString *)phone
                       migrate_args:(id _Nullable)migrate_args
                           complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use bindPhoneWithCaptchaCode:password:phone:migrateArgs:complete instead");

/**
 * 绑定手机
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param captchaCode 验证码
 * @param password 密码
 * @param phone 手机号
 * @param migrateArgs 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)bindPhoneWithCaptchaCode:(NSString *)captchaCode
                        password:(NSString *)password
                           phone:(NSString *)phone
                     migrateArgs:(id _Nullable)migrateArgs
                        complete:(RequestComplete)complete;

/**
 * 解绑手机
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param captchaCode 验证码
 * @param phone 手机号
 */
- (void)reliveBindingPhoneWithCaptchaCode:(NSString *)captchaCode
                                    phone:(NSString *)phone
                                 complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use unBindPhoneWithCaptchaCode:phone:complete instead");

/**
 * 解绑手机
 * @param captchaCode 验证码
 * @param phone 手机号
 */
- (void)unBindPhoneWithCaptchaCode:(NSString *)captchaCode
                             phone:(NSString *)phone
                          complete:(RequestComplete)complete;

/**
 * 修改手机号
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param oldphone_captcha 当前登录的手机号的 unbindphone 验证码
 * @param newphone 新的手机号
 * @param newphone_captcha 新手机号的 bindphone 验证码
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)changePhoneWithOldphone_captcha:(NSString *)oldphone_captcha
                               newphone:(NSString *)newphone
                       newphone_captcha:(NSString *)newphone_captcha
                           migrate_args:(id _Nullable)migrate_args
                               complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use changePhoneWithOldPhoneCaptcha:newphone:newPhoneCaptcha:migrateArgs:complete instead");

/**
 * 修改手机号
 * @param oldPhoneCaptcha 当前登录的手机号的 unbindphone 验证码
 * @param newphone 新的手机号
 * @param newPhoneCaptcha 新手机号的 bindphone 验证码
 * @param migrateArgs 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)changePhoneWithOldPhoneCaptcha:(NSString *)oldPhoneCaptcha
                              newphone:(NSString *)newphone
                       newPhoneCaptcha:(NSString *)newphone_captcha
                           migrateArgs:(id _Nullable)migrateArgs
                              complete:(RequestComplete)complete;

/**
 * 获取用户信息
 */
- (void)getUserInfoWithComplete:(RequestComplete)complete;

/**
 * 修改用户信息
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param avatarUrl 头像url 非必传
 * @param nickname 用户昵称 非必传
 * @param sex 性别 1男 0女 非必传
 * @param w_avatarurl 微信原始头像 非必传
 */
- (void)updateUserInfoWithAvatarUrl:(NSString *)avatarUrl
                           nickname:(NSString *)nickname
                                sex:(NSString *)sex
                        w_avatarurl:(NSString *)w_avatarurl
                           complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use updateUserInfo:nickname:sex:region:complete instead");

/**
 * 修改用户信息
 * @param avatarUrl 头像url 非必传
 * @param nickname 用户昵称 非必传
 * @param sex 性别 1男 0女 非必传
 * @param region 地区码 非必传
 */
- (void)updateUserInfo:(NSString *)avatarUrl
              nickname:(NSString *)nickname
                   sex:(NSString *)sex
                region:(NSString *)region
              complete:(RequestComplete)complete;

/**
 * 修改密码
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param oldPwd 旧密码
 * @param newPwd 新密码
 */
- (void)updatePasswordWithOldPwd:(NSString *)oldPwd
                          newPwd:(NSString *)newPwd
                        complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use changePasswordWithOldPwd:newPwd:complete instead");

/**
 * 修改密码
 * @param oldPwd 旧密码
 * @param newPwd 新密码
 */
- (void)changePasswordWithNewPwd:(NSString *)newPwd
                          oldPwd:(NSString *)oldPwd
                        complete:(RequestComplete)complete;

/**
 * 重置密码
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param username 用户名
 * @param password 密码
 * @param captchaCode 验证码
 * @param migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)resetPasswordWithUsername:(NSString *)username
                         password:(NSString *)password
                      captchaCode:(NSString *)captchaCode
                     migrate_args:(id _Nullable)migrate_args
                         complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use resetPasswordWithUsername:password:captchaCode:migrateArgs:complete instead");

/**
 * 重置密码
 * @param username 用户名
 * @param password 密码
 * @param captchaCode 验证码
 * @param migrateArgs 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)resetPasswordWithUsername:(NSString *)username
                         password:(NSString *)password
                      captchaCode:(NSString *)captchaCode
                      migrateArgs:(id _Nullable)migrateArgs
                         complete:(RequestComplete)complete;

/**
 * 注册
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param username 账号注册为账号，手机注册为手机号，邮箱注册为邮箱  必须
 * @param password 密码  必须
 * @param captchaCode 验证码  手机或邮箱注册为必须，账号注册非必须
 * @param ext 扩展字段
 * ！ext参数说明：
 * ！nickname 昵称  非必须    #NSString类型
 * ！avatarUrl 头像地址  非必须    #NSString类型
 * ！sex 性别,1:男,0:女  非必须    #NSString类型
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)registWithUsername:(NSString * _Nullable)username
                  password:(NSString * _Nullable)password
               captchaCode:(NSString * _Nullable)captchaCode
                       ext:(NSDictionary * _Nullable)ext
                  complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use registerWithUsername:nickname:sex:region:complete instead");

/**
 * 注册
 * @param username 账号注册为账号，手机注册为手机号，邮箱注册为邮箱  必须
 * @param password 密码  必须
 * @param captchaCode 验证码  手机或邮箱注册为必须，账号注册非必须
 * @param ext 扩展字段
 * ！ext参数说明：
 * ！nickname 昵称  非必须    #NSString类型
 * ！avatarUrl 头像地址  非必须    #NSString类型
 * ！sex 性别,1:男,0:女  非必须    #NSString类型
 * ！migrate_args 任意合法的 json 类型, 比如 string, nujber，账号迁移用的参数, 调用 CP account-query 及 account-queryandbind 接口时透传给 CP  非必须
 */
- (void)registerWithUsername:(NSString * _Nullable)username
                    password:(NSString * _Nullable)password
                 captchaCode:(NSString * _Nullable)captchaCode
                         ext:(NSDictionary * _Nullable)ext
                    complete:(RequestComplete)complete;

/**
 * 实名认证
 * @note 建议使用新方法，旧方法如出现问题在以后的版本不再维护
 * @param realName 真实姓名  必须
 * @param idCard 身份证  必须
 */
- (void)approveWithRealName:(NSString *)realName
                     idCard:(NSString *)idCard
                   complete:(RequestComplete)complete DEPRECATED_MSG_ATTRIBUTE("use realAuthWithRealName:idCard:complete instead");

/**
 * 实名认证
 * @param realName 真实姓名  必须
 * @param idCard 身份证  必须
 */
- (void)realAuthWithRealName:(NSString *)realName
                      idCard:(NSString *)idCard
                    complete:(RequestComplete)complete;

/**
 * 查询用户拥有的账号
 * 当用户无法提供正常的凭证登录某些账号时，可以调用本接口，提供该账号相关的其他用户信息进行查询，然后通过其他接口创建新的账号绑定这个旧账号的用户
 * @param method 登录方式，对应"登录/绑定三方账号" 接口参数中的 method 字段。
 * @param devicecode 设备码，不传默认取当前设备码。
 * @param states 账号的位标记，各个位的含义如下（由低到高，最低位为第 0 位）：
 * ！第 0 位：表示该账号由于某些原因，用户已经无法提供登录的凭证
 */
- (void)searchHasAccountsWithMethod:(NSString *)method
                         devicecode:(NSString * _Nullable)devicecode
                             states:(NSInteger)states
                           complete:(RequestComplete)complete;

/**
 * 媒体平台自定义行为上报
 * @param params 上报数据
 * ！params 参数说明：
 * ！action 自定义行为
 */
- (void)addAttributionWithParams:(NSDictionary *)params
                        complete:(RequestComplete)complete;

/**
 * 同步三方授权信息
 * @param params 与登录的ext结构相同
 */
- (void)syncInfoWithParams:(NSDictionary *)params
                  complete:(RequestComplete)complete;

/**
 * 获取设备码
 */
- (NSString *)getDeviceIDInKeychain DEPRECATED_MSG_ATTRIBUTE("use getDeviceCode instead");

/**
 * 获取设备码
 */
- (NSString *)getDeviceCode;

/**
 * 获取当前时区与UTC时差
 */
- (NSString *)getTimeZoneOffset;

/**
 * 获取当前手机语言
 */
- (NSString *)getSystemLanguage;

/**
 * 刷新token
 */
- (void)refreshTokenWithComplete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 获取idfa
 */
+ (NSString *)getIDFA;

/**
 * 请求福利码
 * autoRefresh 是否自动刷新，YES自动刷新并返回福利码，NO不自动刷新
 */
- (void)getPromoDisplayKeyWithAutoRefresh:(BOOL)autoRefresh complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 获取福利码
 * cdkey 福利码
 */
- (void)exchangePromoCDKEY:(NSString *)cdkey complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 获取公告列表
 * limit 返回公告条数，数量范围 1-100，超过100则只返回最近100条
 */
- (void)getAnnouncementWithLimit:(int)limit complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 获取当前本地保存的全量公告(国内外UI SDK内部逻辑调用)
 */
- (NSArray *)getLocalAnnouncement;

/**
 * 获取本地公告是否已读记录(国内外UI SDK内部逻辑调用)
 */
- (NSDictionary *)getLocalAnnouncementReadList;

/**
 * 同步公告是否已读记录到本地(国内外UI SDK内部逻辑调用)
 */
- (void)syncLocalAnnouncementRecord:(NSDictionary *)dict;

/**
 * 保存全量公告数据以及本地是否已读未读记录(主库内部逻辑调用)
 */
- (void)getLocalAnnouncementAndSetReadOrNotRecord;


/**
 * 获取邮箱列表
 * cpUserID 游戏用户id
 */
- (void)getEmailListWithCpUserID:(NSString *)cpUserID complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 获取邮箱详情
 * cpUserID 游戏用户id
 * emailID 邮件id
 */
- (void)getEmailDetailWithCpUserID:(NSString *)cpUserID emailID:(NSInteger)emailID complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 领取道具
 * cpUserID 游戏用户id
 * type 传1为领取当前礼物，需要同时传emailID；传2，为一键领取所有礼物，无需传emailID，或传0即可
 * emailID 邮箱id
 */
- (void)receivePropsWithCpUserID:(NSString *)cpUserID type:(NSInteger)type emailID:(NSInteger)emailID complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 删除邮件
 * cpUserID 游戏用户id
 * type 传1为删除当前邮件，需要同时传emailID；传2，为一键删除所有邮件，无需传emailID，或传0即可
 * emailID 邮箱id
 */
- (void)deleteEmailWithCpUserID:(NSString *)cpUserID type:(NSInteger)type emailID:(NSInteger)emailID complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;


/**
 * 创建反馈
 * content 反馈内容，必填
 * attachments 附件地址数组，非必填
 * phone 手机号，必填
 * tags 游戏透传标识
 *
 */
- (void)feedbackCreateWithContent:(NSString *)content attachments:(NSArray *)attachmentsArray phone:(NSString *)phone tags:(NSArray *)tagArray complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 获取反馈列表
 * page 页数，必填
 * size 每页个数，必填
 * status 状态，1 未处理 2已处理，0为不传，获取所有状态
 */
- (void)getFeedbackListWithPage:(int)page size:(int)size status:(int)status complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 获取反馈详情
 * feedbackID 反馈id
 */
- (void)getFeedbackDetailWithFeedbackID:(int)feedbackID complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 领取反馈回复中的道具
 * feedbackID 反馈id
 */
- (void)feedbackGetpropWithFeedbackID:(int)feedbackID complete:(void(^)(NSDictionary * _Nullable response, RX_CommonRequestError * _Nullable error))complete;

/**
 * 图形验证 UI
 * @param appid 图形验证码 appid
 */
- (void)captchaVerifyUIWithAppid:(NSString *)appid
                        complete:(RequestComplete)complete;

/**
 * login_openid 是否失效，YES 失效，NO 有效
 */
- (BOOL)loginOpenidExpireInvalid;

/**
 * 获取商业化窗口信息
 */
- (void)getOperationSceneWithComplete:(RequestComplete)complete;

/**
 * 商业化信息上报
 */
- (void)reportWindowExposureWithWindowData:(NSDictionary *)windowData
                                  complete:(RequestComplete)complete;

/**
 * 游戏区服信息查询
 * @param areaId 区服 id
 */
- (void)searchGameAreaInfoWithAreaId:(NSString *)areaId
                            complete:(RequestComplete)complete;

/**
 * 游戏区服信息修改
 * @param areaId 区服 id
 * @param areaName 区服名
 * @param areaStatus 区服状态
 * @param areaType 区服类型
 * @param extension 扩展字段
 */
- (void)updateGameAreaInfoWithAreaId:(NSString *)areaId
                            areaName:(NSString *)areaName
                          areaStatus:(NSString *)areaStatus
                            areaType:(NSString *)areaType
                           extension:(NSDictionary *)extension
                            complete:(RequestComplete)complete;

/**
 * 创建游戏区服
 * @param areaId 区服 id
 * @param areaName 区服名
 * @param areaStatus 区服状态
 * @param areaType 区服类型
 * @param extension 扩展字段
 */
- (void)createGameAreaWithAreaId:(NSString *)areaId
                        areaName:(NSString *)areaName
                      areaStatus:(NSString *)areaStatus
                        areaType:(NSString *)areaType
                       extension:(NSDictionary *)extension
                        complete:(RequestComplete)complete;

/**
 * 删除游戏区服
 * @param areaId 区服 id
 */
- (void)deleteGameAreaWithAreaId:(NSString *)areaId
                        complete:(RequestComplete)complete;

/**
 * 查询区服列表信息
 */
- (void)searchGameAreaListInfoWithComplete:(RequestComplete)complete;

/**
 * 创建角色
 * @param areaId 区服 id
 * @param characterFaction 角色阵营
 * @param characterId 角色id
 * @param characterLevel 角色等级
 * @param characterName 角色名
 * @param characterProfession 角色职业
 * @param characterStatus 角色状态
 * @param characterType 角色类型
 * @param characterVipLevel 角色VIP等级
 * @param cpUserId 游戏用户 id
 * @param extension 扩展字段
 */
- (void)createGameCharacterWithAreaId:(NSString *)areaId
                     characterFaction:(NSString *)characterFaction
                          characterId:(NSString *)characterId
                       characterLevel:(NSString *)characterLevel
                        characterName:(NSString *)characterName
                  characterProfession:(NSString *)characterProfession
                      characterStatus:(NSString *)characterStatus
                        characterType:(NSString *)characterType
                    characterVipLevel:(NSString *)characterVipLevel
                             cpUserId:(NSString *)cpUserId
                            extension:(NSDictionary *)extension
                             complete:(RequestComplete)complete;

/**
 * 修改游戏角色信息
 * @param areaId 区服 id
 * @param characterFaction 角色阵营
 * @param characterId 角色id
 * @param characterLevel 角色等级
 * @param characterName 角色名
 * @param characterProfession 角色职业
 * @param characterStatus 角色状态
 * @param characterType 角色类型
 * @param characterVipLevel 角色VIP等级
 * @param cpUserId 游戏用户 id
 * @param extension 扩展字段
 */
- (void)updateGameCharacterInfoWithAreaId:(NSString *)areaId
                         characterFaction:(NSString *)characterFaction
                              characterId:(NSString *)characterId
                           characterLevel:(NSString *)characterLevel
                            characterName:(NSString *)characterName
                      characterProfession:(NSString *)characterProfession
                          characterStatus:(NSString *)characterStatus
                            characterType:(NSString *)characterType
                        characterVipLevel:(NSString *)characterVipLevel
                                 cpUserId:(NSString *)cpUserId
                                extension:(NSDictionary *)extension
                                 complete:(RequestComplete)complete;

/**
 * 删除游戏角色
 * @param areaId 区服 id
 * @param characterId 角色id
 * @param cpUserId 游戏用户 id
 */
- (void)deleteGameCharacterWithAreaId:(NSString *)areaId
                          characterId:(NSString *)characterId
                             cpUserId:(NSString *)cpUserId
                             complete:(RequestComplete)complete;

/**
 * 查询账号下角色信息列表
 * @param cpUserId 游戏用户 id
 */
- (void)searchGameCharacterListInfoWithCpUserId:(NSString *)cpUserId
                                       complete:(RequestComplete)complete;

/**
 * 查询账号下某个区服下的角色信息列表
 * @param areaId 区服 id
 * @param cpUserId 游戏用户 id
 */
- (void)searchGameCharacterListInAreaWithAreaId:(NSString *)areaId
                                       cpUserId:(NSString *)cpUserId
                                       complete:(RequestComplete)complete;

/**
 * 查询具体角色信息
 * @param areaId 区服 id
 * @param cpUserId 游戏用户 id
 * @param characterId 角色id
 */
- (void)searchGameCharacterInfoWithAreaId:(NSString *)areaId
                                 cpUserId:(NSString *)cpUserId
                              characterId:(NSString *)characterId
                                 complete:(RequestComplete)complete;

/**
 * 用户行为统计
 */
- (void)trackUserActionWithDistinctId:(NSString * _Nullable)distinctId
                           properties:(NSDictionary * _Nullable)properties;

/**
 * 终止用户行为统计
 */
- (void)stopTrackUserAction;

@end

NS_ASSUME_NONNULL_END
