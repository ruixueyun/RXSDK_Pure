//
//  RXLocationModel.h
//  RXSDK
//
//  Created by 陈汉 on 2022/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXLocationModel : NSObject
@property (nonatomic, assign) double longitude;        // 经度
@property (nonatomic, assign) double latitude;         // 纬度
@property (nonatomic, copy) NSString *name;            // 位置
@property (nonatomic, copy) NSString *country;         // 国家
@property (nonatomic, copy) NSString *city;            // 市
@property (nonatomic, copy) NSString *subLocality;     // 区
@property (nonatomic, copy) NSString *thoroughfare;    // 街道
@property (nonatomic, copy) NSString *subThoroughfare; // 子街道
@end

NS_ASSUME_NONNULL_END
