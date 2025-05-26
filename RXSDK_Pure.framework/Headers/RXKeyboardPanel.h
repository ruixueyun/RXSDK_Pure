#import <UIKit/UIKit.h>
#import "RXKeyboard.h"

@protocol RXKeyboardPanelDelegate <NSObject>
@optional
// 键盘弹出
- (void)rxKeyboardPanelDidShow;
// 键盘隐藏
- (void)rxKeyboardPanelDidHide;
// 输入监听
- (void)rxKeyboardPanelDidInput:(NSString *)input;
// 删除监听
- (void)rxKeyboardPanelDidDelete;
// 点击完成监听
- (void)rxKeyboardPanelDidFinish:(NSString *)result;
// 取消监听
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
