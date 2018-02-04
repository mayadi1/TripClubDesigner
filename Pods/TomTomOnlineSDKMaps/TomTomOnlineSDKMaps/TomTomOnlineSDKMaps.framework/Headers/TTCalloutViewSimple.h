/**
 * Copyright (c) 2017 TomTom N.V. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom N.V. and its subsidiaries and may be used
 * for internal evaluation purposes or commercial use strictly subject to separate licensee
 * agreement between you and TomTom. If you are the licensee, you are only permitted to use
 * this Software in accordance with the terms of your license agreement. If you are not the
 * licensee then you are not authorised to use this software in any manner and should
 * immediately return it to TomTom N.V.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TTCalloutView.h"
#import "TTAnnotation.h"


/**
 The TTCalloutViewSimple view displays additional information such as a title string.
 */
@interface TTCalloutViewSimple : UIView <TTCalloutView>


/**
 Initializes and returns a new callout view simple.

 @param text The text to be displayed by the view.
 @return instance of TTCalloutViewSimple.
 */
- (instancetype)initWithText:(NSString *)text;


/**
 Initializes and returns a new callout view simple.

 @param annotation The annotation object to be displayed by the view.
 @return instance of TTCalloutViewSimple.
 */
- (instancetype)initWithAnnotation:(TTAnnotation *)annotation;


/**
 The annotation object currently associated with the view.
 */
@property (nonatomic, strong) TTAnnotation *annotation;

/**
 The text to be displayed by the view.
 */
@property (nonatomic, strong, readonly) NSString *text;

@end
