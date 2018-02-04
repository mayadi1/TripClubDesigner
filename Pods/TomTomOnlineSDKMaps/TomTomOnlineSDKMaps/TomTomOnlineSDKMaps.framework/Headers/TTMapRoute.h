
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>


/**
 Base class defining route that can be added to the map.
 */
@interface TTMapRoute : NSObject <TTRouteData>

- (instancetype _Nonnull )init NS_UNAVAILABLE;

+ (TTMapRoute *_Nonnull)routeWithRouteData:(id<TTRouteData> _Nonnull)routeData;
+ (TTMapRoute *_Nonnull)routeWithRouteData:(id<TTRouteData> _Nonnull)routeData
                        imageStart:(UIImage * _Nullable)imageStart
                          imageEnd:(UIImage * _Nullable)imageEnd;
+ (TTMapRoute *_Nonnull)routeWithCoordinates:(CLLocationCoordinate2D *_Nonnull)coordinates
                               count:(NSUInteger)count;
+ (TTMapRoute *_Nonnull)routeWithCoordinates:(CLLocationCoordinate2D *_Nonnull)coordinates
                               count:(NSUInteger)count
                          imageStart:(UIImage * _Nullable)imageStart
                            imageEnd:(UIImage * _Nullable)imageEnd;

/**
 Determines which style load present route.
 */
@property (nonatomic, assign, getter=isActive) BOOL active;

/**
 This property can be used to associate any kind of data with a route.
 */
@property (nonatomic, strong) NSObject * _Nullable extraData;

- (NSArray<NSValue *> *_Nonnull)fullRoute;

@end
