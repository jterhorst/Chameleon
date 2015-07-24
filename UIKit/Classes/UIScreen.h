/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of The Iconfactory nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>

extern NSString *const UIScreenDidConnectNotification;
extern NSString *const UIScreenDidDisconnectNotification;
extern NSString *const UIScreenModeDidChangeNotification;

typedef enum {
    UIScreenOverscanCompensationScale,
    UIScreenOverscanCompensationInsetBounds,
    UIScreenOverscanCompensationInsetApplicationFrame,
} UIScreenOverscanCompensation;

@class UIImageView, CALayer, UIKitView, UIScreenMode, UIPopoverController;

@interface UIScreen : NSObject {
@private
    UIImageView *_grabber;
    CALayer *_layer;
    __unsafe_unretained UIKitView *_UIKitView;
    UIScreenMode *_currentMode;
    __unsafe_unretained UIPopoverController *_popoverController;
}

+ (UIScreen *)mainScreen;
+ (NSArray *)screens;

@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic, readonly) CGRect applicationFrame;
@property (nonatomic, readonly, copy) NSArray *availableModes;      // only ever returns the currentMode
@property (nonatomic, retain) UIScreenMode *currentMode;            // ignores any attempt to set this
@property (nonatomic, readonly) CGFloat scale;
@property (nonatomic, assign) UIScreenOverscanCompensation overscanCompensation; // has no effect
@property (nonatomic, retain) UIScreen *mirroredScreen; // always returns nil
@property (nonatomic) CGFloat brightness;         // has no effect; defaults to 0.0

@end
