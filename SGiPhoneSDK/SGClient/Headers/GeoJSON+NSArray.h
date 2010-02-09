//
//  SGGeoJSONNSArray.h
//  SGClient
//
//  Created by Derek Smith on 2/1/10.
//  Copyright 2010 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
* @category NSArray(SGGeoJSONObject)
* @abstract Ease the pain of accessing SimpleGeo GeoJSON values.
*/
@interface NSArray (GeoJSONObject)

/*!
* @method x
* @abstract Retrieve the x coordinate of the point.
* @result The x value for the point.
*/
- (double) x;

/*!
* @method y
* @abstract Retrieve the y coordinate of the point. ￼
* @result ￼The y value for the point.
*/
- (double) y;

/*!
* @method latitude
* @abstract ￼Retrieve the latitude of the point (y)
* @result The latitude value for the point.
*/
- (double) latitude;

/*!
* @method longitude
* @abstract Retrieve the longitude of the point (x)
* @result ￼The longitude value for the point.
*/
- (double) longitude;

@end

/*!
* @category NSMutableArray(SGGeoJSONObject)
* @abstract Ease the pain of storing SimpleGeo GeoJSON values.
*/
@interface NSMutableArray (GeoJSONObject)

/*!
* @method setX:
* @abstract Stores the new x value at index 0.
* @param x The new x value.
*/
- (void) setX:(double)x;

/*!
* @method setY:
* @abstract Stores the new y value at index 1.
* @param x The new y value.
*/
- (void) setY:(double)y;

/*!
* @method setLatitude:
* @abstract Stores the new latitude value at index 1.
* @param x The new latitude value.
*/
- (void) setLatitude:(double)latitude;

/*!
* @method setLongitude:
* @abstract Stores the new longitude value at index 0.
* @param x The new longitude value.
*/
- (void) setLongitude:(double)longitude;

@end

