/*
*  SGAnnotation.h
*  CCLocatorServices
*
*  Created by Derek Smith on 9/22/09.
*  Copyright 2009 SimpleGeo. All rights reserved.
*
*/

#import <MapKit/MapKit.h>

/*!
* @protocol SGAnnotation
* @abstract Just a simple re-definition of MKAnnotation for the sake of notation.
* @discussion In order for an object to become displayable in an @link //simplegeo/ooc/cl/SGARView SGARView @/link,
* the object must implement this protocol. Each object serves as a data source for a view within the AR enviornment.
* The AR view requires, at a minimum, a lat/long coordinate in order
* to display an object. @link //simplegeo/ooc/cl/SGRecordAnnotationView SGRecordAnnotationViews @/link will use title and subtitle
* properties if they are provided.
*/
@protocol SGAnnotation <MKAnnotation>


@end

/*!
* @protocol SGRecordAnnotation    
* @abstract This protocol helps with the retrieval and updating process of records used in @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link.
* @discussion The SGRecordAnnotation is used to provide annotation-related information for both the @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link
* and the @link //simplegeo/ooc/cl/SGARView SGARView @/link. Using the @link //simplegeo/ooc/cl/SGGeoJSONCode SGGeoJSONEncoder @/link, the location service
* is able to create a simple GeoJSON representation of the record and update or retain information about it.
*
* Although not all methods require implementation, both @link propertiesForRecord propertiesForRecord @/link and @link updateRecordWithGeoJSONDictionary: updateRecordWithGeoJSONDictionary: @/link.
* should be implemented. Anytime a record needs to be updated with SimpleGeo, the location service will call propertiesForRecord in order to provide the
* user-defined properties within the GeoJSON object that will be sent. Implementing @link updateRecordWithGeoJSONDictionary: updateRecordWithGeoJSONDictionary: @/link.
* provides an easy, accessable method of updating an object from a returned GeoJSON object from SimpleGeo.
*/
@protocol SGRecordAnnotation <SGAnnotation>

/*!
* @method recordId
* @abstract￼ Returns the unique identifer for the record.
* @result￼ The unique identifier for the record.
*/
- (NSString*) recordId;

/*!
* @method layer
* @discussion The convention for layers is a reverse URL  (e.g com.simplgeo.tree). 
* @result￼ The name of the layer the record belongs to.
*/
- (NSString*) layer;

@optional

/*!
* @method type
* @abstract￼ The type of record.
* @discussion￼ Currently, there are only four types: object, media, person, and place. Default is object.
* @result￼ The type for the record.
*/
- (NSString*) type;

/*!
* @method propertiesForRecord
* @abstract￼ Creates a dictionary representation of the record.
* @discussion￼ This method is mainly used by @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link.
* The dictionary returned by this method will be encoded into a GeoJSON object. This means that the only supported
* values in the dictionary are NSNumber, NSString, NSArray, NSDictionary and NSNull.
* 
* It is not necessary to implement this method, but highly recommended. The @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link
* will create a bare-bones dictionary representation of the record and use that to store in SimpleGeo.
* Only the required fields will be assigned a value. Record specific keys (e.g "name", "email_address")
* will not be present in the default dictionary and will not be used in record update/retrieval.
* @result￼ The dictionary representation of the record.
*/
- (NSDictionary*) propertiesForRecord;

/*!
* @method createdTimeInterval
* @abstract￼ The time at which the record was created, in Unix time. Default is a current timestamp.
* @result The time interval.
*/
- (double) createdTimeInterval;

/*!
* @method expirationTimeInterval
* @abstract￼ The time at which the record will expire, in Unix time. Default is 24 hours from creation.
* @result￼ The time interval.
*/
- (double) expirationTimeInterval;

/*!
* @method updateRecordWithGeoJSONDictionary:
* @abstract￼ Updates the annotation with the contents of a GeoJSON NSDictionary.
* @discussion￼ Much like @link propertiesForRecord propertiesForRecord @/link, it is recommended to implement
* this method. The @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link will
* update recordId, the properties decalred in this protocol, but it won't update the user-defined properties.
* @param dictionary ￼The GeoJSON dictionary.
*/
- (void) updateRecordWithGeoJSONDictionary:(NSDictionary*)dictionary;

@end
