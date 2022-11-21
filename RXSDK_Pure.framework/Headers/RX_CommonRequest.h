//
//  RXRequest.h
//  OverseaSocialApp
//
//  Created by 陈汉 on 2021/4/15.
//

#import <Foundation/Foundation.h>
#import "RX_CommonRequestConfigure.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RequestMethod) {
    RequestMethod_Get = 0,
    RequestMethod_Post,
    RequestMethod_Put,
    RequestMethod_Delete
};

@interface RX_CommonRequest : NSObject

@property (nonatomic, copy) NSString * apiName;
@property (nonatomic, strong) NSDictionary * params;
@property (nonatomic, strong) NSData *gzipParam;
@property (nonatomic, strong) NSDictionary * headParams;
@property (nonatomic, assign) RequestMethod requestMethod;
@property (nonatomic, copy) NSString * apiFlag;
@property (nonatomic, assign) NSTimeInterval startTime;
@property (nonatomic, copy) NSString * baseUrl;
@property (nonatomic, assign) BOOL isSetQueryStringSerialization; //是否序列化请求 body请求 默认YES
@property (nonatomic, assign) BOOL ssl;//是YES则自动转https,YES则不转
@property (nonatomic, assign) BOOL isGzip;
@property (nonatomic, assign) NSInteger failedTimes; // 失败次数

- (instancetype) initWithApiName:(NSString *)apiName andParams:(NSDictionary * __nullable)parmas;

- (instancetype) initWithApiName:(NSString *)apiName andParams:(NSDictionary * __nullable)parmas requsetMethod:(RequestMethod)method;

+ (void)rx_requestWithUrl:(NSString *)urlString
               parameters:(nullable id)parameters
                  headers:(nullable NSDictionary <NSString *, NSString *> *)headers
              requestType:(NSString *)requestType
             SuccessBlock:(nullable void (^)(NSURLSessionDataTask * _Nonnull, id _Nullable))successBlock
               ErrorBlock:(void (^)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))errorBlock;

@end

NS_ASSUME_NONNULL_END
