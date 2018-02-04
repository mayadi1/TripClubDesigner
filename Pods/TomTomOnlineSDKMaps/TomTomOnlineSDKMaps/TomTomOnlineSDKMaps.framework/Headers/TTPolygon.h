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

#import <TomTomOnlineSDKMaps/TomTomOnlineSDKMaps.h>
#import "TTOverlay.h"


/**
 A closed polygon shape.
 */
@interface TTPolygon : TTOverlay


/**
 Creates and returns a TTPolygon object from the specified set of map points.

 @param coordinates The array of map coordinates defining the shape.
 @param count The count of array corrds
 @param opacity opacity
 @param color color.
 @param colorOutline colorOutline.
 @return TTPolygon
 */
+ (instancetype)polygonWithCoordinates:(CLLocationCoordinate2D *)coordinates
                                  count:(NSUInteger)count
                                opacity:(float)opacity
                                  color:(UIColor *)color
                           colorOutline:(UIColor *)colorOutline;


/**
 Creates and returns a TTPolygon object from the specified set of map points.
 The polygon color and colorOutline are set a default value WHITE color.

 @param coordinates The array of map coordinates defining the shape.
 @param count The count of array coordinates.
 @return TTPolygon
 */
+ (instancetype)polygonWithCoordinates:(CLLocationCoordinate2D *)coordinates
                                 count:(NSUInteger)count;


/**
 The array of map coordinates defining the shape.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D *coordinates;

/**
 The number of items in the coordinates array.
 */
@property (nonatomic, assign, readonly) NSUInteger count;


/**
 Opacity
 */
@property (nonatomic, assign, readonly) float opacity;


/**
 The fill color to use for the path.
 */
@property (nonatomic, strong, readonly) UIColor *color;


/**
 The outline color to use for the path.
 */
@property (nonatomic, strong, readonly) UIColor *colorOutline;

@end
