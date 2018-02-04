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

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "TTAnnotationManager.h"
#import "TTRouteManager.h"
#import "TTCameraPosition.h"

typedef struct TTLatLngBounds{
    CLLocationCoordinate2D seBounds;
    CLLocationCoordinate2D neBounds;
} TTLatLngBounds;

NS_INLINE TTLatLngBounds TTLatLngBoundsMake(CLLocationCoordinate2D seBounds, CLLocationCoordinate2D neBounds) {
    TTLatLngBounds bounds;
    bounds.seBounds = seBounds;
    bounds.neBounds = neBounds;
    return bounds;
}

@class TTMapView;


/**
 TTMapTilesType
 Enumeration Cases

 - TTMapTilesNone: TTMapTilesNone - No tiles.
 - TTMapTilesVector: TTMapTilesVector - Vector tiles.
 - TTMapTilesRaster: TTMapTilesRaster - Raster tiles.
 */
typedef NS_ENUM (NSInteger, TTMapTilesType) {
    TTMapTilesNone,
    TTMapTilesVector,
    TTMapTilesRaster
};

/**
 TTMapLayersType
 Enumeration Cases

 - TTMapLayersNone: TTMapLayersNone - No layers.
 - TTMapLayersHybrid: TTMapLayersHybrid - Hybrid layer (layers and road).
 */
typedef NS_ENUM(NSInteger, TTMapLayersType) {
    TTMapLayersNone,
    TTMapLayersHybrid
};

/**
 TTMapTrafficType
 Enumeration Cases

 - TTMapTrafficNone: TTMapTrafficNone - No traffic.
 - TTMapTrafficFlow: TTMapTrafficFlow - Only traffic flow.
 - TTMapTrafficIncidents: TTMapTrafficIncidents - Only traffic incidents.
 */
typedef NS_OPTIONS(NSInteger, TTMapTrafficType) {
    TTMapTrafficNone,
    TTMapTrafficFlow,
    TTMapTrafficIncidents
};

/**
 * The `TTMapViewDelegate` protocol defines a set of optional methods that you can use to receive map-related update messages.
 * Because many map operations require the `TTMapView` class to load data asynchronously, the map view calls these methods to notify your application when specific operations complete.
 */
@protocol TTMapViewDelegate <NSObject>

@optional
/**
 Tells the delegate that the specified map view with pan gesture recognizer.

 @param mapView The map view.
 @param coordinate for panning.
 */
- (void)mapView:(nonnull TTMapView *)mapView didPanning:(CLLocationCoordinate2D)coordinate;


/**
 Tells the delegate that the specified map view with double tap gesture recognizer.

 @param mapView The map view.
 @param coordinate for a double tap.
 */
- (void)mapView:(nonnull TTMapView *)mapView didDoubleTap:(CLLocationCoordinate2D)coordinate;


/**
 Tells the delegate that the specified map view with single tap gesture recognizer.

 @param mapView The map view.
 @param coordinate for a single tap.
 */
- (void)mapView:(nonnull TTMapView *)mapView didSingleTap:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that the specified map view with long press gesture recognizer.

 @param mapView The map view.
 @param coordinate for a long press.
 */
- (void)mapView:(nonnull TTMapView *)mapView didLongPress:(CLLocationCoordinate2D)coordinate;

/**
 Tells the delegate that specified map view with rotate gesture recognizer.

 @param mapView The map view.
 @param angle in radians.
 */
- (void)mapView:(nonnull TTMapView *)mapView didRotate:(CGFloat)angle;

@end

/**
 * An `TTMapView` object provides an embeddable map interface.
 * You use this class as-is to display map information and to manipulate the map contents from your application.
 * You can center the map on a given coordinate, specify the size of the area you want to display and annotate the map with custom information.
 */
@interface TTMapView : UIView

@property (nonatomic, weak) IBOutlet UIButton * _Nullable compassButton;
@property (nonatomic, weak) IBOutlet UIButton * _Nullable centerButton;
@property (nonatomic, weak) IBOutlet UIButton * _Nullable copyrightsButton;

/**
 *  UI compass and center buttons components
 */

@property (nonatomic) NSLayoutConstraint * _Nullable leftLayoutConstarintCompassButton;
@property (nonatomic) NSLayoutConstraint * _Nullable topLayoutConstraintCompassButton;

@property (nonatomic) NSLayoutConstraint * _Nullable leftLayoutConstarintCenterButton;
@property (nonatomic) NSLayoutConstraint * _Nullable bottomLayoutConstraintCenterButton;

@property (weak, nonatomic) _Nullable id<TTMapViewDelegate> delegate;
@property (nonatomic, strong, readonly) id <TTAnnotationManager> _Nullable annotationManager;
@property (nonatomic, strong, readonly) id<TTRouteManager> _Nullable routeManager;

/**
 * Returns current rotation of the map in degrees range from 0 to 360
 *
 * Allows also to set rotation degrees is in range 0 - 360 where 0 == 360 which is Nort up
 * Bigger values than 360 are also allowed. For 540 it will do 540 % 360 = 180
 */
@property (nonatomic, assign) double bearing;

/**
 * Determines if current location indicator/radius should be displayed on the map.
 * It works only if users allow application to use GPS fix and NSLocationWhenInUseUsageDescription and
 * location permissions are gained by calling requestLocationAuthorization method.
 */
@property (nonatomic, assign, getter=isShowsUserLocation) BOOL showsUserLocation;


/**
 * Returns current user coordinate location.
 * If the current location is not available, latitude and longitude returned by the method will be equal to 0.
 */
@property (nonatomic, readonly, getter=userLocation) CLLocationCoordinate2D userLocation;

/**
 Determines map view insets for functions like show route overview, center on, camera concept.
 A default set to 0.
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 * Center map on given coordinates
 @param coordinate location Coordinate to center map on.
 */
- (void)centerOnCoordinate:(CLLocationCoordinate2D)coordinate;


/**
 * Center map on given latitude and longitude.
 * Latitude and longitude is set in degrees minutes seconds format.
 @param latitude Latitude to center map on.
 @param longitude Longitude to center map on.
 */
- (void)centerOnLatitude:(double)latitude withLongitude:(double)longitude;


/**
 * Center map on given coordinates and with given zoom level.
 * When zoom level is out of range, the minimum zoom level will be set.
 @param coordinate Coordinate to center map on.
 @param zoom Map zoom level in range 0 - 18 where 0 is whole world and 18 highest zoom level.
 */
- (void)centerOnCoordinate:(CLLocationCoordinate2D)coordinate withZoom:(double)zoom;


/**
 * Center map on given latitude and longitude with a given zoom level.
 * When zoom level is out of range, the minimum zoom level will be set.
 * Latitude and longitude are set in degrees minutes seconds format.
 @param latitude Latitude to center map on.
 @param longitude Longitude to center map on.
 @param zoom Map zoom level in range 0 - 18 where 0 is whole world and 18 highest zoom level.
 */
- (void)centerOnLatitude:(double)latitude withLongitude:(double)longitude withZoom:(double)zoom;


/**
 * Coordinates of map center
 @return map center coordinate
 */
- (CLLocationCoordinate2D)centerCoordinate;

/**
 * The zoom in and out of the map.
 * Zoom levels are in range <18,0)
 * Where 0 is whole world.
 * 18 is the highest zoom level.
 @return zoom Map Level.
 */
- (double)zoom;

/**
 * Set 2D mode or 3D for a map.
 @param perspective true if 3D mode, false otherwise.
 */
- (void)setPerspective3D:(BOOL)perspective;


/**
 * Is perspective 3D active.
 @return BOOL true if a 3D mode is active, false otherwise.
 */
- (BOOL)isPerspective3D;

/**
 Rotate map to given degrees with given rotation center.
 Degrees is in range 0 - 360 where 0 == 360 which is Nort up
 Bigger values than 360 are also allowed. For 540 it will do 540 % 360 = 180

 @param degrees determines how to rotate map
 @param coordinate that takes as center of rotation
 */
- (void)setBearing:(double)degrees coordinate:(CLLocationCoordinate2D)coordinate;

/**
 The method for style to be used to render tiles.
 @param tiles TTMapTrafficType visible for None, Vector or Raster type.
 */
- (void)setTilesType:(TTMapTilesType)tiles;

/**
 The method for style to be used to render layers.
 @param layers TTMapLayersType visible for None or Hybrid.
 */
- (void)setLayersType:(TTMapLayersType)layers;

/**
 The method for style to be used to render traffic tiles
 @param traffic TTMapTrafficType visible for None, Traffic or Incidents type.
 */
- (void)setTrafficType:(TTMapTrafficType)traffic;


/**
 Get Current screen bounds
 @return TTLatLngBounds
 */
- (TTLatLngBounds)currentBounds;

/**
 The method for setting camera position
 @param cameraPosition object TTCameraPosition
 */
-(void)setCameraPosition:(TTCameraPosition*_Nonnull)cameraPosition;

/**
 Get Camera Position object.
 @return TTCameraPostion object present current state of camera.
 */
-(TTCameraPosition * _Nonnull)cameraPosition;

@end
