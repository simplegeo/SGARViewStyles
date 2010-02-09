//
//  CLLocationAdditions.h
//  SGLocatorServices
//
//  Created by Derek Smith on 7/4/09.
//  Copyright 2010 SimpleGeo. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>


@interface CLLocation (SGLocatorService)

- (BOOL) isEqualToLocation:(CLLocation*)location;

- (double) getBearingFromCoordinate:(CLLocationCoordinate2D)coord;

@end
