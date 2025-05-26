#import <UIKit/UIKit.h>
#import "RXKeyboard.h"

@protocol RXKeyboardPanelDelegate <NSObject>
@optional
- (void)rxKeyboardPanelDidShow;
- (void)rxKeyboardPanelDidHide;
- (void)rxKeyboardPanelDidInput:(NSString *)input;
- (void)rxKeyboardPanelDidDelete;
- (void)rxKeyboardPanelDidFinish:(NSString *)result;
- (void)rxKeyboardPanelDidCancel;
@end

typedef enum : NSUInteger {
    RXKeyboardStyleDefault,
    RXKeyboardStyleLight,
} RXKeyboardStyle;

@interface RXKeyboardPanel : UIView
@property (nonatomic, strong, readonly) UITextField *textField;
@property (nonatomic, weak) id<RXKeyboardPanelDelegate> delegate;
@property (nonatomic, assign) NSInteger keyboardHeight;
@property (nonatomic, copy) NSString *defaultText;
@property (nonatomic, assign) float animationDuration;
@property (nonatomic, assign) RXKeyboardStyle keyboardStyle;

- (instancetype)initWithKeyboardStyle:(RXKeyboardStyle)keyboardStyle;

- (void)showInView:(UIView *)parentView;
- (void)hide;
@end
