/*
*  SGAnnotation.h
*  CCLocatorServices
*
*  Created by Derek Smith on 9/22/09.
*  Copyright 2010 SimpleGeo. All rights reserved.
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
* @abstract The layer where the record is registered.
* @discussion The convention for layers is a reverse URL  (e.g com.simplgeo.tree). 
* @result￼ The name of the layer.
*/
- (NSString*) layer;

@optional

/*!
* @method type
* @abstract￼ The type of record. Default is object.
* @discussion￼ A list of types can be found in SGLocationTypes.h.
* @result￼ The type for the record.
*/
- (NSString*) type;

/*!
* @method properties
* @abstract￼ The properties associated with the record.
* @result￼ Extra properties that help define the record.
*/
- (NSDictionary*) properties;

/*!
* @method created
* @abstract￼ The time at which the record was created, in Unix time. Default is a current timestamp.
* @result The time interval.
*/
- (double) created;

/*!
* @method expires
* @abstract￼ The time at which the record will expire, in Unix time. Default is 24 hours from creation.
* @result￼ The time interval.
*/
- (double) expires;

/*!
* @method updateRecordWithGeoJSONObject:
* @abstract￼ Updates the annotation with the contents of a GeoJSON Object.
* @param dictionary ￼The GeoJSON dictionary.
*/
- (void) updateRecordWithGeoJSONObject:(NSDictionary*)dictionary;

@end