//
//  RXKeyboard.h
//  RXSDK-Pure
//
//  Created by 陈汉 on 2025/5/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RXKeyboardViewDelegate <NSObject>
- (void)rxKeyboardViewDidInput:(NSString *)input;
- (void)rxKeyboardViewDidDelete;
- (void)rxKeyboardViewDidFinish;
- (void)rxKeyboardViewDidCancel;
- (void)rxKeyboardViewDidBeginLongPressDelete;
- (void)rxKeyboardViewDidEndLongPressDelete;
@end

@interface RXKeyboard : UIView

- (instancetype)initWithKeyboardTextColor:(NSString *)keyboardTextColor
                       keyboardClickColor:(NSString *)keyboardClickColor
                              deleteImage:(NSString *)deleteImage
                                lineColor:(NSString *)lineColor;

@property (nonatomic, weak) id <RXKeyboardViewDelegate> delegate;
@property (nonatomic, strong) NSString *deleteImage;
@property (nonatomic, strong) NSString *keyboardTextColor;
@property (nonatomic, strong) NSString *keyboardClickColor;
@property (nonatomic, strong) NSString *lineColor;

@end

NS_ASSUME_NONNULL_END
