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
#import <CoreLocation/CoreLocation.h>

@interface TTCameraPosition : NSObject

/**
  Focal point the camera is pointing at.
 */
@property (nonatomic, readonly, assign) CLLocationCoordinate2D cameraPosition;

/**
 Animation time for the camera update. If it is not set, the defualt animation time which is 1 second will be executed. If you do not want animation, pass 0.
 */
@property (nonatomic, readonly) int animationDuration;
/**
 Rotation angle, in degrees clockwise from north.
 */
@property (nonatomic, readonly) double bearing;
/**
 The tilt angle, in degrees.
 */
@property (nonatomic, readonly) double pitch;
/**
 Camera zoom level.
 */
@property (nonatomic, readonly) int zoom;

/**
 A class that that describes all camera position parameters, such as location, zoom zoom level, pitch angle and bearing.

 @param cameraPosition CameraPosition coordinate.
 @param animationDuration Animation time for the camera update.
 @param bearing Rotation angle, in degrees clockwise from north
 @param pitch The latitude that the camera is pointing at.
 @param zoom Camera zoom level.
 @return TTCameraPosition object.
 */
- (id)initWithCamerPosition:(CLLocationCoordinate2D)cameraPosition withAnimationDuration:(int)animationDuration withBearing:(double)bearing withPitch:(double)pitch withZoom:(int)zoom;

/**
 A class that that describes all camera position parameters, such as location pitch angle and bearing.

 @param cameraPosition CameraPosition coordinate.
 @param animationDuration Animation time for the camera update.
 @param bearing Rotation angle, in degrees clockwise from north
 @param pitch The latitude that the camera is pointing at.
 @return TTCameraPosition object.
 */
- (id)initWithCamerPosition:(CLLocationCoordinate2D)cameraPosition withAnimationDuration:(int)animationDuration withBearing:(double)bearing withPitch:(double)pitch;

/**
 A class that that describes all camera position parameters, such as location with bearing, and animation duration.

 @param cameraPosition CameraPosition coordinate.
 @param animationDuration Animation time for the camera update.
 @param bearing Rotation angle, in degrees clockwise from north
 @return TTCameraPosition object.
 */
- (id)initWithCamerPosition:(CLLocationCoordinate2D)cameraPosition withAnimationDuration:(int)animationDuration withBearing:(double)bearing;

/**
 A class that that describes all camera position parameters, such as location with animation Duration.

 @param cameraPosition CameraPosition coordinate.
 @param animationDuration Animation time for the camera update.
 @return TTCameraPosition object.
 */
- (id)initWithCamerPosition:(CLLocationCoordinate2D)cameraPosition withAnimationDuration:(int)animationDuration;

- (BOOL) isEqual:(id)object;
- (NSUInteger)hash;

@end
