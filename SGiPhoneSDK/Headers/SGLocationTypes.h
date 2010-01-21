/*
 * SGLocationTypes.h
 * SgLocatorServices
 *
 * Created by Derek Smith on 9/15/09.
 * Copyright 2009 SimpleGeo. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/*!
 * @defined kSGLocationType_Person
 * @abstract A person type.
 */
#define kSGLocationType_Person @"person"

/*!
 * @defined kSGLocationType_Place
 * @abstract A place type.
 */
#define kSGLocationType_Place @"place"

/*!
 * @defined kSGLocationType_Object
 * @abstract A object type.
 */
#define kSGLocationType_Object @"object"

/*!
 * @defined kSGLocationType_Media
 * @abstract A media type.
 */
#define kSGLocationType_Media @"media"




typedef NSString SGLocationType;

/*!
 * @struct SGGeohash
 * @field latitude The latitude.
 * @field longitude The longitude. 
 * @field precision
 */
typedef struct {

    double latitude;
    double longitude;
 
    int precision;

} SGGeohash;

/*!
 * @function SGGeohashMake(double, double, SGLocationZoomLevel)
 * @abstract Creates a new SGGeohash structure.
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @param precision The precision. 
 * @result A new SGGeohash structure.
*/
extern SGGeohash SGGeohashMake(double latitude, double longitude, int precision);
