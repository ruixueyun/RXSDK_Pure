//
//  RXNetworkExcute.h
//  OverseaSocialApp
//
//  Created by 陈汉 on 2021/4/15.
//

#import <Foundation/Foundation.h>
#import "RX_CommonRequest.h"
#import "RX_CommonRequestConfigure.h"
#import "RX_CommonRequestError.h"

typedef void(^RequestHelloTimeOut)(RX_CommonRequest * _Nullable request);
typedef void(^RequestTokenExpired)(void);
typedef void(^RequestTimeExpend)(NSTimeInterval interval,NSString * _Nullable apiName);
typedef void(^RequestProgress)(NSProgress * _Nullable progress);
typedef void(^RequestSuccess)(id _Nullable responseObject);
typedef void(^RequestFailed)(RX_CommonRequestError * _Nullable error);
@protocol RequestDelegate<NSObject>

@optional

/**
 成功返回
 */
- (void)requestInterfaceExcuteSuccess:(id _Nullable )retObj
                              apiName:(NSString *_Nullable)apiName
                              apiFlag:(NSString *_Nullable)apiFlag;

/**
 错误返回
 */
- (void)requestInterfaceExcuteError:(NSError *_Nullable)error
                            apiName:(NSString *_Nullable)apiName
                            apiFlag:(NSString *_Nullable)apiFlag
                             retObj:(id _Nullable )retObj;
/**
 错误返回
 */
- (void)requestInterfaceExcuteError:(NSError *_Nullable)error
                            apiName:(NSString *_Nullable)apiName
                            apiFlag:(NSString *_Nullable)apiFlag;

@end

NS_ASSUME_NONNULL_BEGIN

@interface RX_CommonNetworkExcute : NSObject

//@property (nonatomic, strong) AFHTTPSessionManager * tManager;
@property (nonatomic, strong) RX_CommonRequestConfigure * configure;
@property (nonatomic, weak) id<RequestDelegate> delegate;
@property (nonatomic, strong) RequestHelloTimeOut helloBlock;
@property (nonatomic, strong) RequestTokenExpired tokenBlock;
@property (nonatomic, strong) RequestTimeExpend timeBlock;

/**
 初始化单例

 @param configure 网络请求配置对象
 @return 网络请求管理类
 */
+ (instancetype) shareInstanceWithConfig:(RX_CommonRequestConfigure *)configure;
//代理返回的请求
/**
 普通POST GET 请求

 @param request 请求的URL参数信息
 */
- (void) beginRequest:(RX_CommonRequest *)request;


/**
 普通POST GET 请求

 @param request 请求的URL参数信息
 @param success 成功返回
 @param failure 失败返回
 */
- (void) beginRequest:(RX_CommonRequest *)request
              success:(RequestSuccess)success
              failure:(RequestFailed)failure;

/**
 多个请求

 @param array 数组
 */
- (void) beginRequestWithArray:(NSArray<RX_CommonRequest *> *) array;

@end

NS_ASSUME_NONNULL_END
