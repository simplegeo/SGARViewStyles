//
// SGRecord.h
// SGLocatorServices
//
// Created by Derek Smith on 8/17/09.
// Copyright 2009 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

#import "SGRecordAnnotation.h"

/*!
* @class SGRecord
* @abstract Stores location data for any particular record.
* @discussion This class provides the standard functionality that allows a record from SimpleGeo to be placed inside of a
* @link //simplegeo/ooc/cl/SGARView SGARView @/link while acting as a stand-alone object for record retrieval and updates
* used by @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link. This object is valid wherever 
* @link //simplegeo/ooc/intf/SGRecordAnnotation SGRecordAnnotation @/link or @link //simplegeo/ooc/intf/SGAnnotation @/link is required.
* 
* It is recommended that this class be subclassed because most records stored in SimpleGeo will have user-defined properties. See 
* @link //simplegeo/ooc/cl/SGGeoJSONEncoder SGGeoJSONEncoder @/link.
*/
@interface SGRecord : NSObject <SGRecordAnnotation>
{
    NSString* recordId;
 
    double latitude;
    double longitude;
 
    NSTimeInterval creationTimeInterval;
    NSTimeInterval expirationTimeInterval;
 
 	NSString* type;
 	NSString* layer;
    
    NSMutableDictionary* userDefinedProperties;
}

/*!
* @property
* @abstract See @link //simplegeo/ooc/instp/SGRecordAnnotaiton/recordId SGRecordAnnotation @/link
*/
@property (nonatomic, retain) NSString* recordId;

/*!
* @property
* @abstract The latitude of the record.
*/
@property (nonatomic, assign) double latitude;

/*!
* @property
* @abstract The longitude of the record.
*/
@property (nonatomic, assign) double longitude;

/*!
* @property
* @abstract See @link //simplegeo/ooc/instp/SGRecordAnnotation/creationTimeInterval SGRecordAnnotation @/link
*/
@property (nonatomic, assign) NSTimeInterval creationTimeInterval;

/*!
* @property
* @abstract See @link //simplegeo/ooc/instp/SGRecordAnnotation/expirationTimeInterval SGRecordAnnotation @/link
*/
@property (nonatomic, assign) NSTimeInterval expirationTimeInterval;

/*!
* @property
* @abstract See @link //simplegeo/ooc/instp/SGRecordAnnotation/type SGRecordAnnotation @/link
*/
@property (nonatomic, retain) NSString* type;

/*!
* @property
* @abstract See @link //simplegeo/ooc/inspt/SGRecordAnnotation/layer SGRecordAnnotation @/link
* @discussion When a new record object is created, the layer property is assigned the bundle identifier. 
*/
@property (nonatomic, retain) NSString* layer;

/*!
* @property
* @abstract Extra properties that are not defined, nor required by SimpleGeo.
* @discussion This dictionary stores and updates properties (e.g. name, age, color) that are
* not required by SimpleGeo. It is updated by @link updateRecordWithGeoJSONDictionary: updateRecordWithGeoJSONDictionary: @/link.
*/
@property (nonatomic, readonly) NSMutableDictionary* userDefinedProperties;

/*!
* @method updateRecordWithGeoJSONDictionary:
* @abstract Updates the record with a dictionary. See @link //simplegeo/ooc/instm/SGRecordAnnotation/updateRecordWithGeoJSONDictionary: updateRecordWithGeoJSONDictionary: @/link. 
* @discussion The default implementation will update all of the non-user defined properties including the coordinate. Subclasses
* are encouraged to override this method to allow user-defined properties to be extracted from the dictionary. Be sure to call
* [super updateRecordWithGeoJSONDictionary:dictionary] to allow this class to assign the non-user defined values to the record.
*/
- (void) updateRecordWithGeoJSONDictionary:(NSDictionary*)dictionary;

/*!
* @method propertiesForRecord
* @abstract Returns a dictionary representation of the non-user defined properites. See @link ￼//simplegeo/ooc/instm/SGRecordAnnotation/propertiesForRecord propertiesForRecord @/link. 
* @discussion ￼The default implementaion will return a dictionary with id, layer, type, expires and created defined as keys with the
* proper values attached to them. Be sure to call [super propertiesForRecord] to take advantage of this classes default implementation.
* @result The dictionary representation of the properties for this record.
*/
- (NSDictionary*) propertiesForRecord;

@end



