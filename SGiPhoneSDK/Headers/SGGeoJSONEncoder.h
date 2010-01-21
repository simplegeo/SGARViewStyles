//
// SGGeoJSONEncoder.h
// SGiPhoneSDK
//
// Created by Derek Smith on 11/11/09.
// Copyright 2009 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SGRecordAnnotation.h"


/*!
* @class SGGeoJSONEncoder 
* @abstract Converts annotations into GeoJSON dictionaries.
* @discussion Currently, SimpleGeo only supports a single type of GeoJSON, which is a Point.
* SimpleGeo GeoJSON objects only represent records. All records have this JSON structure:
*
* {
*  "coordinate" : (-83.012, 12.0),
*  "type" : "Point",
*  "properties" : {"id" : "some1212id",
*                  "layer" : "com.simplegeo.test",
*                  "type" : "object",
*                  "expires" : 383729018239,
*                  "created" : 383498483393}
* }
*
* SimpleGeo GeoJSON objects allow user-defined properties. For instance:
*
* {
*  "coordinate" : (-83.012, 12.0),
*  "type" : "Point",
*  "properties" : {"id" : "some1212id",
*                  "layer" : "com.simplegeo.test",
*                  "type" : "object",
*                  "expires" : 383729018239,
*                  "created" : 383498483393,
*                  "name" : "Mr. Bean",
*                  "hobby" : "dancing"}
* } 
*
* The user-defined properties in the above example are name and hobby. SimpleGeo will store and fetch 
* any user-defined property when updating and retrieving records.\
*
* For further information on GeoJSON See @link http://geojson.org/geojson-spec.html#point here @/link
*/
@interface SGGeoJSONEncoder : NSObject {

}

/*!
* @method geoJSONDictionaryForRecordAnnotation:
* @abstract ￼Converts @link //simplegeo/ooc/intf/SGRecordAnnotation SGRecordAnnotation @/link into a 
* valid GeoJSON dictionary.
* @discussion ￼The only type supported at the moment is Point. The properties value is created by calling
* @link //simplegeo/ooc/instm/SGRecordAnnotation/propertiesForRecord propertiesForRecord @/link
* on the annotation record if it is implemented. If it is not, the method will create a default
* dictionary that is comprised of the keys: id, layer, type, created and expires.
* 
* @param record ￼The record to convert to a GeoJSON dictionary.
* @result ￼A GeoJSON dictionary.
*/
+ (NSMutableDictionary*) geoJSONDictionaryForRecordAnnotation:(id<SGRecordAnnotation>)record;

/*!
* @method geoJSONDictionaryForPoint:properties:
* @abstract ￼Converts a coordinate and properties into a GeoJSON dictionary.
* @param coord ￼The coordinate to add to the dictionary.
* @param properties ￼The properties to add to the dictionary.
* @result ￼The GeoJSON dictionary.
*/
+ (NSMutableDictionary*) geoJSONDictionaryForPoint:(CLLocationCoordinate2D)coord properties:(NSDictionary*)properties;

/*!
* @method recordIdFromGeoJSONDictionary:
* @abstract ￼Returns the @link //simplegeo/ooc/instp/SGRecordAnntation recordId @/link for
* a given GeoJSON dictionary.
* @param geoJSONDictionary ￼
* @result ￼The record id for the GeoJSON dictionary.
*/
+ (NSString*) recordIdFromGeoJSONDictionary:(NSDictionary*)geoJSONDictionary;

/*!
 * @method layerFromGeoJSONDictionary:
 * @abstract ￼Returns the @link //simplegeo/ooc/instp/SGRecordAnntation layer @/link for
 * a given GeoJSON dictionary.
 * @param geoJSONDictionary ￼
 * @result ￼The layer for the GeoJSON dictionary.
 */
+ (NSString*) layerFromGeoJSONDictionary:(NSDictionary*)geoJSONDictionary;

@end
