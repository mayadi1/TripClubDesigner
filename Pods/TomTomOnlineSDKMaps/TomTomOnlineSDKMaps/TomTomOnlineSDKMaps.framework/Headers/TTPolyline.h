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
#import <CoreLocation/CoreLocation.h>


/**
 A shape consisting of one or more connected line segments.
 */
@interface TTPolyline : TTOverlay


/**
 Creates and returns an TTPolyline object from the specified set of coordinates.

 @param coordinates The array of coordinates defining the shape.
 @param count The number of items in the coordinates array.
 @param opacity The opacity for the path.
 @param width The width for the path. Should be greater than 0.
 @param color The color for the path.
 @return TTPolyline
 */
+ (instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coordinates
                                  count:(NSUInteger)count
                                opacity:(float)opacity
                                  width:(float)width
                                  color:(UIColor *)color;


/**
 Creates and returns an TTPolyline object from the specified set of coordinates.
 The polyline color and colorOutline are set a default value WHITE color.
 The width path is set a default value 5.0.

 @param coordinates The array of coordinates defining the shape.
 @param count The number of items in the coordinates array.
 @return TTPolyline
 */
+ (instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coordinates
                                  count:(NSUInteger)count;

/**
 The array of coordinates defining the shape.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D *coordinates;

/**
 The number of items in the coordinates array.
 */
@property (nonatomic, assign, readonly) NSUInteger count;


/**
 The opacity for the path.
 */
@property (nonatomic, assign, readonly) float opacity;


/**
 The width for the path. Should be greater than 0.
 */
@property (nonatomic, assign, readonly) float width;


/**
 The fill color to use for the path.
 */
@property (nonatomic, strong, readonly) UIColor *color;


@end
