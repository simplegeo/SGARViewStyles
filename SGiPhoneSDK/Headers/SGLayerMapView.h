//
// SGLayerMapView.h
// CCLocatorServices
//
// Created by Derek Smith on 9/30/09.
// Copyright 2009 SimpleGeo. All rights reserved.
//

#import <MapKit/MapKit.h>

#import "SGLayer.h"
#import "SGGeoJSONEncoder.h"

/*!
* @class
* @abstract Displays records from a layer on a MKMapView.
* @discussion ￼This is just a simple subclass of MKMapView which uses the records 
* for each registered layer as annotations. SGLayerMapView will automatically
* load more records from SimpleGeo after the view is animated. In addition, the map will attempt to load more
* records based on the @link reloadTimeInterval reloadTimeInterval @/link if no movement is created.
* Just add @link //simplegeo/ooc/cl/SGLayer SGLayer @/link object to the map view. You can disable this feature
* by calling @link stopRetrieving stopRetrieving @/link since every record retrieval requires
* an HTTP request. Also, the map will remove annotation as they move out of view. 
*
* The map view will build records based on the SGLayers 
* @link //simplegeo/ooc/instm/SGLayer/recordAnnotationFromGeoJSONDictionary: recordAnnotationFromGeoJSONDictionary: @/link
* method. Records are not automatically added to their layer when they are retrieved. In order to add
* retrieved records to their SGLayer object,
* @link addRetrievedRecrodsToLayer addRetrievedRecrodsToLayer @/link should be set to YES.
*/
@interface SGLayerMapView : MKMapView <MKMapViewDelegate, SGLocationServiceDelegate> {
 
    NSInteger limit;
    
    NSTimeInterval reloadTimeInterval;
    BOOL addRetrievedRecordsToLayer;
    
 
}

/*!
* @property
* @abstract The amount of records to retrieve each time the map view
* detects it needs to refresh its annotations.
*/
@property (nonatomic, assign) NSInteger limit;

/*!
* @property
* @abstract The time interval (expressed in seconds) that tells the map to
* retrieve annotations when no movement has occurred.
* @discussion Set this value to a negative interval to not load any records
* when no animations have occurred.
*/
@property (nonatomic, assign) NSTimeInterval reloadTimeInterval;

/*!
* @property
* @abstract Determines whether or not to add retrieved records to
* each SGLayer object as they are loaded by the map.
*/
@property (nonatomic, assign) BOOL addRetrievedRecordsToLayer;

/*!
* @method startRetrieving
* @abstract ￼ Enables fetching records for each layer from SimpleGeo when the map view's region changes.
*/
- (void) startRetrieving;

/*!
* @method stopRetrieving
* @abstract ￼ Disables fetching records for each layer from SimpleGeo when the map view's region changes.
*/
- (void) stopRetrieving;

/*!
* @method addLayers: 
* @abstract ￼Adds an array of layers to be displayed in the map view.
* @param layers ￼The array of layers.
*/
- (void) addLayers:(NSArray*)layers;

/*!
* @method removeLayers:
* @abstract ￼Removes an array of layers from the map view.
* @param layers ￼The array of layers.
*/
- (void) removeLayers:(NSArray*)layers;

/*!
* @method addLayer:
* @abstract ￼Adds a layer to the map view. 
* @param layer ￼The @link //simplegeo/ooc/cl/SGLayer SGLayer @/link to register
* with the map.
*/
- (void) addLayer:(SGLayer*)layer;

/*!
* @method removeLayer:
* @abstract ￼Removes a layer from the map view.
* @discussion Remvoing a layer will also remove any annotation that are present
* on the map.
* @param layer ￼The @link //simplegeo/ooc/cl/SGLayer SGLayer @/link to remove from the map.
*/
- (void) removeLayer:(SGLayer*)layer;

@end
