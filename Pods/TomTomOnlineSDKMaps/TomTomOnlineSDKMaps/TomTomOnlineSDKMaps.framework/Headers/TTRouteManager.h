
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "TTMapRoute.h"

@protocol TTRouteDelegate <NSObject>

@optional

/**
 Triggered when on of the routes on the map is clicked

 @param route route TTMapRoute
 */
- (void)routeClicked:(TTMapRoute * _Nonnull)route;

@end

@protocol TTRouteManager <NSObject>

@property (nonatomic, weak) id <TTRouteDelegate> _Nullable delegate;

/**
 Array of route that are present on the map
 */
@property (nonatomic, strong, readonly) NSArray<TTMapRoute *> * _Nonnull routes;

/**
 Draws new route on the map

 @param route route TTMapRoute
 */
- (void)addRoute:(TTMapRoute * _Nonnull)route;

/**
 Removes given route from map.
 Throws exception if route was not added to map before.

 @param route route TTMapRoute
 */
- (void)removeRoute:(TTMapRoute * _Nonnull)route;

/**
 Removes all route from the map
 */
- (void)removeAllRoutes;

/**
 Finds best zoom level and bounding box to present given route.
 Throws exception if route was not added to map before.

 @param route route TTMapRoute
 */
- (void)showRouteOverview:(TTMapRoute *_Nonnull)route;

/**
 Finds best zoom level and bounding box to present all routes that are added to map.
 */
- (void)showAllRoutesOverview;

@end
