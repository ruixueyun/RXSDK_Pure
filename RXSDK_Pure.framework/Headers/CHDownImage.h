//
//  CHDownImage.h
//  Night7App-iOS
//
//  Created by 陈汉 on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define TRUrlToData_TimeOut 20.0

NS_ASSUME_NONNULL_BEGIN

@interface CHDownImage : NSURL

+ (NSData *)urlToData:(NSString *)imageUrl;
//异步下载
+ (void)asyurlToData:(NSString *)imageUrl withHandler:(void (^)(NSURLResponse* response, NSData* data, NSError* connectionError)) handler;
+ (NSData *)dataScaleToBytes:(long)bytes withImageData:(NSData *)imageData;

@end

NS_ASSUME_NONNULL_END
