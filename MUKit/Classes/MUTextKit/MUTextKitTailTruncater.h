//
//  MUTextKitTailTruncater.h
//  MUAsyncDisplayLayer
//
//  Created by Jekity on 2018/9/6.
//  Copyright © 2018年 Jekity. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MUTextKitContext;
@interface MUTextKitTailTruncater : NSObject
/**
 The character range from the original attributedString that is displayed by the renderer given the parameters in the
 initializer.
 */
@property (nonatomic, assign, readonly) NSArray * _Nullable visibleRanges;

/**
 Returns the first visible range or an NSRange with location of NSNotFound and size of 0 if no first visible
 range exists
 */
@property (nonatomic, assign, readonly) NSRange firstVisibleRange;

/**
 A truncater object is initialized with the full state of the text.  It is a Single Responsibility Object that is
 mutative.  It configures the state of the TextKit components (layout manager, text container, text storage) to achieve
 the intended truncation, then it stores the resulting state for later fetching.
 
 The truncater may mutate the state of the text storage such that only the drawn string is actually present in the
 text storage itself.
 
 The truncater should not store a strong reference to the context to prevent retain cycles.
 */
- (instancetype _Nullable )initWithContext:(MUTextKitContext *_Nullable)context
     truncationAttributedString:(NSAttributedString * _Nullable)truncationAttributedString
         avoidTailTruncationSet:(NSCharacterSet * _Nullable)avoidTailTruncationSet;

/**
 Actually do the truncation.
 */
- (void)truncate;
@end
