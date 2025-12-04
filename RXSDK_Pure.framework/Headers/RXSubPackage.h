//
//  RXSubPackage.h
//  RXSDK-Pure
//
//  Created by 陈汉 on 2025/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXSubPackage : NSObject

+ (instancetype)sharedSDK;

/** AliDNS  **/
@property (nonatomic, assign) BOOL aAliDNS;

/** TencentDNS  **/
@property (nonatomic, assign) BOOL aTencentDNS;

/** Adjust  **/
@property (nonatomic, assign) BOOL aAdjust;
@property (nonatomic, strong) NSString *adid;

/** Firebase  **/
@property (nonatomic, assign) BOOL aFirebase;
@property (nonatomic, strong) NSString *instanceId;

/** w  **/
@property (nonatomic, assign) BOOL aW;

/** Facebook  **/
@property (nonatomic, assign) BOOL aFacebook;

/** Google  **/
@property (nonatomic, assign) BOOL aGoogle;

/** Line  **/
@property (nonatomic, assign) BOOL aLine;

/** TikTok  **/
@property (nonatomic, assign) BOOL aTikTok;

/** Zalo  **/
@property (nonatomic, assign) BOOL aZalo;

/** Snapchat  **/
@property (nonatomic, assign) BOOL aSnapchat;

/** Reddit  **/
@property (nonatomic, assign) BOOL aReddit;

/** Instagram  **/
@property (nonatomic, assign) BOOL aInstagram;

/** ASA  **/
@property (nonatomic, assign) BOOL aASA;

/** UIKit  **/
@property (nonatomic, assign) BOOL aRXUI;

/** OSUIKit  **/
@property (nonatomic, assign) BOOL aRXOSUI;

/** BDA  **/
@property (nonatomic, assign) BOOL aBDA;

/** Push  **/
@property (nonatomic, assign) BOOL aPush;

/** UWA  **/
@property (nonatomic, assign) BOOL aUWA;

/** RXGPM  **/
@property (nonatomic, assign) BOOL aRXGPM;

/** RXList  **/
@property (nonatomic, assign) BOOL aRXList;

/** RXAB  **/
@property (nonatomic, assign) BOOL aRXAB;

/** RXOpeninstall  **/
@property (nonatomic, assign) BOOL aRXOpeninstall;

/** RXGDT  **/
@property (nonatomic, assign) BOOL aRXGDT;

@end

NS_ASSUME_NONNULL_END
