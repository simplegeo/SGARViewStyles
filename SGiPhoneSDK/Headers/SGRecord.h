//
// SGRecord.h
// SGLocatorServices
//
// Created by Derek Smith on 8/17/09.
// Copyright 2010 SimpleGeo. All rights reserved.
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

    NSTimeInterval created;
    NSTimeInterval expires;
 
 	NSString* type;
 	NSString* layer;
    
    NSString* layerLink;
    NSString* selfLink;
    
    NSMutableDictionary* properties;
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
* @abstract See @link //simplegeo/ooc/instp/SGRecordAnnotation/created SGRecordAnnotation @/link
*/
@property (nonatomic, assign) NSTimeInterval created;

/*!
* @property
* @abstract See @link //simplegeo/ooc/instp/SGRecordAnnotation/expires SGRecordAnnotation @/link
*/
@property (nonatomic, assign) NSTimeInterval expires;

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
* @abstract A link to the layer where this record is kept.
* @discussion The initial value is nil. When the object is updated from a GeoJSON object
* recieved from SimpleGeo, this property will be set.
*/
@property (nonatomic, retain) NSString* layerLink;

/*!
 * @property
 * @abstract A link to the record.
 * @discussion The initial value is nil. When the object is updated from a GeoJSON object
 * recieved from SimpleGeo, this property will be set.
 */
@property (nonatomic, retain) NSString* selfLink;

/*!
* @property
* @abstract Extra properties that are not defined, nor required by SimpleGeo.
* @discussion This dictionary stores and updates properties (e.g. name, age, color) that are
* not required by SimpleGeo. It is updated by @link updateRecordWithGeoJSONObject: updateRecordWithGeoJSONObject: @/link.
*/
@property (nonatomic, retain) NSMutableDictionary* properties;

/*!
* @method updateRecordWithGeoJSONObject:
* @abstract Updates the record using the GeoJSONOBject. 
* See @link //simplegeo/ooc/instm/SGRecordAnnotation/updateRecordWithGeoJSONObject: updateRecordWithGeoJSONObject: @/link. 
*/
- (void) updateRecordWithGeoJSONObject:(NSDictionary*)dictionary;

@end



