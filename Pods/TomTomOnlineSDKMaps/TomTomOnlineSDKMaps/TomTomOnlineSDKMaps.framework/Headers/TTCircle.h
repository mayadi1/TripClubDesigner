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
#import "TTOverlay.h"

/**
 A circular overlay with a configurable radius and centered on a specific geographic coordinate.
 */
@interface TTCircle : TTOverlay


/**
 Creates and returns a TTCircle object using the specified coordinate and radius.

 @param coordinate The center point of the circle, specified as a latitude and longitude value.
 @param radius The radius of the circle in meters. 
 @param opacity opacity for the circle.
 @param width width for the circle.
 @param color color for the circle.
 @param fill fill for the circle.
 @param colorOutline colorOutline for the circle.
 @return TTCircle
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coordinate
                                    radius:(CLLocationDistance)radius
                                   opacity:(float)opacity
                                     width:(float)width
                                     color:(UIColor *)color
                                      fill:(BOOL)fill
                               colorOutlet:(UIColor *)colorOutline;

/**
 Creates and returns a TTCircle object using the specified coordinate and radius.

 @param coordinate The center point of the circle, specified as a latitude and longitude value.
 @param radius The radius of the circle in meters. 
 @param width width for the circle.
 @param color color for the circle.
 @param fill fill for the circle.
 @param colorOutline colorOutline for the circle.
 @return TTCircle
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coordinate
                                    radius:(CLLocationDistance)radius
                                     width:(float)width
                                     color:(UIColor *)color
                                      fill:(BOOL)fill
                               colorOutlet:(UIColor *)colorOutline;


/**
 Creates and returns a TTCircle object using the specified coordinate and radius.
 The circle color and colorOutline are set a default value WHITE color.
 The width path is set a default value 5.0.

 @param coordinate The center point of the circle, specified as a latitude and longitude value.
 @param radius The radius of the circle in meters.
 @return TTCircle
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coordinate
                                    radius:(CLLocationDistance)radius;

/**
 The center point of the circle, specified as a latitude and longitude value.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/**
 The radius of the circle in meters. 
 */
@property (nonatomic, assign, readonly) CLLocationDistance radius;

/**
 The opacity color to use for the circle.
 */
@property (nonatomic, assign, readonly) float opacity;

/**
 The width to use for the circle in pixels.
 */
@property (nonatomic, assign, readonly) float width;

/**
 The fill color to use for the circle.
 */
@property (nonatomic, strong, readonly) UIColor *color;

/**
 The flag YES/NO for fill to use for the circle.
 */
@property (nonatomic, assign, readonly) bool fill;

/**
 The color of the circle’s outline.
 */
@property (nonatomic, strong, readonly) UIColor *colorOutline;

@end
