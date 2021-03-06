//
//  UIView+Helpers.h
//
//  Created by Andrew Carter on 11/9/11.
/*
    用来进行相对布局,方便的获取view,设置view的某些和大小相关的属性的拓展
 */
#import <UIKit/UIKit.h>

@interface UIView (Helpers)

typedef NS_ENUM(NSUInteger, UIViewAlignment)
{
    UIViewAlignmentLeft = 1 << 0,
    UIViewAlignmentRight = 1 << 1,
    UIViewAlignmentTop = 1 << 2,
    UIViewAlignmentBottom = 1 << 3,
    
    UIViewAlignmentLeftEdge = 1 << 5,
    UIViewAlignmentRightEdge = 1 << 6,
    UIViewAlignmentTopEdge = 1 << 7,
    UIViewAlignmentBottomEdge = 1 << 8,
    
    UIViewAlignmentHorizontalCenter = 1 << 9,
    UIViewAlignmentVerticalCenter = 1 << 10,
};

typedef NS_ENUM(NSInteger, VerticalLayoutType) {
    VerticalLayoutTypeTop,
    VerticalLayoutTypeCenter,
    VerticalLayoutTypeBottom
};

@property (nonatomic) CGFloat frameOriginX;
@property (nonatomic) CGFloat frameOriginY;
@property (nonatomic) CGFloat frameSizeWidth;
@property (nonatomic) CGFloat frameSizeHeight;
@property (nonatomic) CGSize frameSize;
@property (nonatomic) CGPoint frameOrigin;

@property (nonatomic) CGFloat frameMaxX;
@property (nonatomic) CGFloat frameMaxY;


@property (nonatomic) CGPoint frameCenter;
@property (nonatomic) CGFloat frameCenterX;
@property (nonatomic) CGFloat frameCenterY;




+ (CGRect)alignRect:(CGRect)startingRect
             toRect:(CGRect)referenceRect
      withAlignment:(UIViewAlignment)alignment
             insets:(UIEdgeInsets)insets
andReferenceIsSuperView:(BOOL)isReferenceSuperView;

// Init
- (id)initWithSize:(CGSize)size;

//Alignment
- (void)alignRelativeToView:(UIView*)alignView 
              withAlignment:(UIViewAlignment)alignment 
                  andInsets:(UIEdgeInsets)insets;

- (void)alignRelativeToSuperView:(UIView*)alignView 
                   withAlignment:(UIViewAlignment)alignment 
                       andInsets:(UIEdgeInsets)insets;

- (void)centerAlignHorizontalForView:(UIView *)view;
- (void)centerAlignVerticalForView:(UIView *)view;

- (void)centerAlignHorizontalForView:(UIView *)view offset:(CGFloat)offset;
- (void)centerAlignVerticalForView:(UIView *)view offset:(CGFloat)offset;
- (void)centerAlignForView:(UIView *)view;

- (void)centerAlignForSuperview;
- (void)centerAlignHorizontalForSuperView;
- (void)centerAlignHorizontalForSuperView:(CGFloat)offset;

- (void)centerAlignVerticalForSuperView;

- (void)leftAlignForView:(UIView *)view;
- (void)rightAlignForView:(UIView *)view;
- (void)topAlignForView:(UIView *)view;
- (void)bottomAlignForView:(UIView *)view;

- (void)leftAlignForView:(UIView *)view offset:(CGFloat)offset;
- (void)rightAlignForView:(UIView *)view offset:(CGFloat)offset;
- (void)topAlignForView:(UIView *)view offset:(CGFloat)offset;
- (void)bottomAlignForView:(UIView *)view offset:(CGFloat)offset;

- (void)topAlignForSuperView;
- (void)bottomAlignForSuperView;
- (void)leftAlignForSuperView;
- (void)rightAlignForSuperView;

- (void)topAlignForSuperViewOffset:(CGFloat)offset;
- (void)bottomAlignForSuperViewOffset:(CGFloat)offset;
- (void)leftAlignForSuperViewOffset:(CGFloat)offset;
- (void)rightAlignForSuperViewOffset:(CGFloat)offset;



//Positioning Relative to View
- (void)setFrameOriginYBelowView:(UIView *)view;
- (void)setFrameOriginYAboveView:(UIView *)view;
- (void)setFrameOriginXRightOfView:(UIView *)view;
- (void)setFrameOriginXLeftOfView:(UIView *)view;

- (void)setFrameOriginYBelowView:(UIView *)view offset:(CGFloat)offset;
- (void)setFrameOriginYAboveView:(UIView *)view offset:(CGFloat)offset;
- (void)setFrameOriginXRightOfView:(UIView *)view offset:(CGFloat)offset;
- (void)setFrameOriginXLeftOfView:(UIView *)view offset:(CGFloat)offset;

//Resizing
- (void)setFrameSizeToImageSize;

//Making rounded corners
- (void)roundCornersTopLeft:(CGFloat)topLeft topRight:(CGFloat)topRight bottomLeft:(CGFloat)bottomLeft bottomRight:(CGFloat)bottomRight;
static inline UIImage* createRoundedCornerMask(CGRect rect, CGFloat radius_tl, CGFloat radius_tr, CGFloat radius_bl, CGFloat radius_br);

//Fade Edges
- (void)setHorizontalFadeMaskWithLeftOffset:(CGFloat)leftOffset rightOffset:(CGFloat)rightOffset;
- (void)setVerticalFadeMaskWithTopOffset:(CGFloat)topOffset bottomOffset:(CGFloat)bottomOffset;

// Snapshot creation
- (UIImageView *)createSnapshot __deprecated;
- (UIImage *)snapshotImage;

/*
 * iOS 6 and prior: calls -snapshotView and wraps the result in a UIImageView
 * on iOS 7 and up: calls and returns the stock -snapshotView method
 */

//- (UIView *)snapshotImageView;

/* Debug
 *
 * The functions below are only performed in DEBUG mode
 * @param "showInRelease" will apply the function in both DEBUG and RELEASE mode
 */
- (void)showDebugFrame;
- (void)hideDebugFrame;
- (void)showDebugFrame:(BOOL)showInRelease;

- (void)logFrameChanges;

// Layout Helpers
+ (CGFloat)alignVertical:(VerticalLayoutType)type
                   views:(NSArray*)views
             withSpacing:(CGFloat)spacing
                  inView:(UIView*)view
      shrinkSpacingToFit:(BOOL)shrinkSpacingToFit;

+ (CGFloat)alignVertical:(VerticalLayoutType)type
                   views:(NSArray*)views
        withSpacingArray:(NSArray*)spacing
                  inView:(UIView*)view
      shrinkSpacingToFit:(BOOL)shrinkSpacingToFit;

// subviews
+ (UIView *)firstResponder;
- (UIView *)firstResponderInSubviews;
- (NSArray *)subviewsOfClass:(Class)aClass recursive:(BOOL)recursive;

/**
 *  获取cell所在的tableview,一般只是用来确定UITableViewCell的所属UITableview
 *
 *  @return 找到的UITableview
 */
- (UITableView *)fdd_superTableView;


/**
 *  获取view所在的tableViewCell
 *
 *  @return view所在的tableViewCell
 */
- (UITableViewCell*)fdd_superTableCell;

/**
 *  获取第一响应对象,可以是自己,或者自己的子类中寻找
 *
 *  @return 第一响应对象
 */
- (UIView *)fdd_findFirstResponder;


/**
 *  在自己的子视图中寻找类型为 cls的视图
 *
 *  @param cls 要找寻的视图类型
 *
 *  @return 找到的视图,如果没找到,返回nil
 */
- (UIView *)descendantOrSelfWithClass:(Class)cls;

/**
 *  在自己的父类中寻找类型为cls的视图
 *
 *  @param cls 要找寻的视图类型
 *
 *  @return 找到的视图,如果没找到,返回nil
 */
- (UIView *)ancestorOrSelfWithClass:(Class)cls;

/**
 *  移除所有的子类视图
 */
- (void)removeAllSubviews;


/**
 *  Rounded corners using performant Bezier Path
 *
 *  @param inRadius radius of the corners
 */
- (void)addBezierPathRoundedCornersWithRadius:(CGFloat)inRadius;

- (void)setRoundedCorners:(UIRectCorner)corners radius:(CGFloat)radius;
- (void)setRoundedCornersWithRadius:(CGFloat)radius;

@end


@interface UIView (CALayer) //取自 https://github.com/youknowone/FoundationExtension
@property(assign) CGFloat borderWidth;
@property(copy) UIColor *borderColor;
@property(assign) CGFloat cornerRadius;

@property(retain) UIColor *shadowColor;
@property(assign) CGSize shadowOffset;
@property(assign) float shadowAlpha;
@property(assign) CGFloat shadowRadius;
@end


@interface UIView (Animation) //取自 https://github.com/youknowone/FoundationExtension
/*!
 *  @brief Set whether the view is hidden.
 *  @details If 'animated' property is NO, this method calls [-setHidden:][0]; Otherwise, when starting, object's 'hidden' property is set to NO. If given hidden parameter is YES, 'hidden' property is set to YES after end of animation. This may cause confliction with other animations or accessors.
 *  @param hidden If YES, the view become hidden; otherwise, NO.
 *  @param animated If YES, animates the transition; otherwise, does not.
 *  @see [hidden][0]
 [0]: http://developer.apple.com/library/ios/documentation/UIKit/Reference/UIView_Class/UIView/UIView.html#//apple_ref/occ/instp/UIView/hidden
 */
- (void)setHidden:(BOOL)hidden animated:(BOOL)animated;
@end
