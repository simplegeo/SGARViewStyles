//
// SGGeoJSONEncoder.h
// SGiPhoneSDK
//
// Created by Derek Smith on 11/11/09.
// Copyright 2010 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SGRecordAnnotation.h"
#import "GeoJSON+NSArray.h"
#import "GeoJSON+NSDictionary.h"

/*!
* @class SGGeoJSONEncoder 
* @abstract Converts annotations into GeoJSONObjects and vice-versa.
* @discussion Objects returned from SGLocationService are represented as GeoJSON object. A GeoJSON object
* is just an NSDictionary with specific key/values. For further information on
* GeoJSON See @link http://geojson.org/geojson-spec.html#point here @/link
*/
@interface SGGeoJSONEncoder : NSObject {

}

/*!
* @method recordsForGeoJSONObject:
* @abstract ￼Returns a list of @link //simplegeo/ooc/intf/SGRecord SGRecord @/link
* @param geojsonObject A valid GeoJSON object.
* @result ￼An array of newly allocated records that were constructed from the GeoJSONObject.
*/
+ (NSArray*) recordsForGeoJSONObject:(NSDictionary*)geojsonObject;

/*!
* @method recordForGeoJSONObject:
* @abstract ￼Creates a new //simplegeo/ooc/intf/SGRecord SGRecord @/link fromt a GeoJSON object.
* @param geojsonObject ￼ A valid GeoJSON object.
* @result ￼A new @link //simplegeo/ooc/intf/SGRecord SGRecord @/link created from the geoJSONObject.
*/
+ (id<SGRecordAnnotation>) recordForGeoJSONObject:(NSDictionary *)geojsonObject;

/*!
* @method geoJSONObjectForRecordAnnotations:
* @abstract ￼Returns a new GeoJSONObject that was constructed from the list of
* @link //simplegeo/ooc/intf/SGRecordAnnotation SGRecordAnnotation @/link objects.
* @param recordAnnotations The array of record annotations that help construct the GeoJSON object. ￼
* @result A new GeoJSON object.
*/
+ (NSDictionary*) geoJSONObjectForRecordAnnotations:(NSArray*)recordAnnotations;

+ (NSDictionary*) geoJSONObjectForRecordAnnotation:(id<SGRecordAnnotation>)recordAnnotation;

/*!
* @method layerNameFromLayerLink:
* @abstract Returns the layer name from the layer link of a GeoJSON object.
* @param layerLink ￼The link to the layer that stores a GeoJSON object.
* @result ￼The layer that was obtained from the layer link.
*/
+ (NSString*) layerNameFromLayerLink:(NSString*)layerLink;

                                      
@end
