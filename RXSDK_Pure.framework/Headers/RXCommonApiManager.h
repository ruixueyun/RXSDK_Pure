//
//  RXApiManager.h
//  OverseaSocialApp
//
//  Created by 陈汉 on 2021/4/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXCommonApiManager : NSObject

// 法务信息 url
+ (NSString *)getCommonConfigUrl;

// 登录 url
+ (NSString *)getLoginUrl;

// 刷新token url
+ (NSString *)getRefreshTokenUrl;

// 绑定邮箱 url
+ (NSString *)getBindingEmailUrl;

// 解绑邮箱 url
+ (NSString *)getReliveBindingEmailUrl;

// 绑定手机 url
+ (NSString *)getBindingPhoneUrl;

// 解绑手机 url
+ (NSString *)getReliveBindingPhoneUrl;

// 注册 url
+ (NSString *)getRegistUrl;

// 获取验证码 url
+ (NSString *)getCaptchaUrl;

// 实名认证 url
+ (NSString *)getApproveUrl;

// 获取用户信息 url
+ (NSString *)getUserInfoUrl;

// 修改用户信息 url
+ (NSString *)getUpdateUserInfoUrl;

// 修改密码 url
+ (NSString *)getUpdatePasswordUrl;

// 重置密码 url
+ (NSString *)getResetPasswordUrl;

// 上报定位 url
+ (NSString *)getReportLocationUrl;

// 删除定位 url
+ (NSString *)getDeleteLocationUrl;

// 获取附近人 url
+ (NSString *)getRadiusAccountUrl;

// 设置用户自定义信息 url
+ (NSString *)getSetUserCustomUrl;

// 添加自定义关系 url
+ (NSString *)getAddRelationUrl;

// 删除自定义关系 url
+ (NSString *)getDeleteRelationUrl;

// 更新自定关系备注 url
+ (NSString *)getUpdateRemarkUrl;

// 获取自定关系列表 url
+ (NSString *)getRelationListUrl;

// 添加好友 url
+ (NSString *)getAddFriendUrl;

// 删除好友 url
+ (NSString *)getDeleteFriendUrl;

// 更新好友备注 url
+ (NSString *)getUpdateFriendRemarkUrl;

// 获取好友列表 url
+ (NSString *)getFriendListUrl;

// 创建排行榜 url
+ (NSString *)getCreateRankUrl;

// 获取排行榜 url
+ (NSString *)getRankListUrl;

// 上报排行榜分数
+ (NSString *)getReportRankScoreUrl;

// 获取openId url
+ (NSString *)getOpenIdUrl;

// 获取分享信息 url
+ (NSString *)getShareInfoUrl;

// 大厅更新检查 url
+ (NSString *)getCheckUpdate_appUrl;

// 活动更新检查 url
+ (NSString *)getCheckUpdate_activityUrl;

// 游戏更新检查 url
+ (NSString *)getCheckUpdate_gameUrl;

// 申请注销账号 url
+ (NSString *)getDestroyAccountUrl;

// 撤销注销申请 url
+ (NSString *)getRepealDestroyAccountUrl;

// 上传推送配置 url
+ (NSString *)getUploadPushInfoUrl;

// 绑定别名 url
+ (NSString *)getBindingPushAliasUrl;

// 增加用户标签 url
+ (NSString *)getAddTagsPushUrl;

// 移除用户标签 url
+ (NSString *)getDeleteTagsPushUrl;

// 解绑用户与渠道SDK的关联
+ (NSString *)getReliveBindingPushDeviceUrl;

// 推送日志上报 url
+ (NSString *)getReportPushLogUrl;

// 数据埋点 url
+ (NSString *)getReportLogUrl;

// 下单 url
+ (NSString *)getPayOrderInfoUrl;

// 获取通路配置 url
+ (NSString *)getSharePlatformsUrl;

@end

NS_ASSUME_NONNULL_END
