//
// SGLayerMapView.h
// CCLocatorServices
//
// Created by Derek Smith on 9/30/09.
// Copyright 2009 SimpleGeo. All rights reserved.
//

#import <MapKit/MapKit.h>

#import "SGLayer.h"

/*!
 * @class
 * @abstract Displays records from a layer on a MKMapView.
 * @discussion ￼This is just a simple subclass of MKMapView which uses the records 
 * for each registered layer as annotations. SGLayerMapView will automatically
 * load more records from SimpleGeo when the view is animated. Just add @link //simplegeo/ooc/cl/SGLayer SGLayer @/link
 * object to the map view. You can disable this feature
 * by calling @link stopRetrieving stopRetrieving @/link since every record retrieval requires
 * an HTTP request.
 *
 * The map view will build records based on the SGLayers @link //simplegeo/ooc/instm/recordFromDicitonary: recordFromDictionary: @/link
 * method. Records are not automatically added to their layer when they are retrieved. In order to add retrieved records to their SGLayer object,
 * @link addRetrievedRecrodsToLayer addRetrievedRecrodsToLayer @/link should be set to YES.
 */
@interface SGLayerMapView : MKMapView <MKMapViewDelegate, SGLocationServiceDelegate> {
 
    NSInteger limit;
 
}

/*!
 * @property
 * @abstract The amount of records to retrieve each time the map view
 * detects it needs to refresh its annotations.
 */
@property (nonatomic, assign) NSInteger limit;

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
 * @param layer ￼The layer.
 */
- (void) addLayer:(SGLayer*)layer;

/*!
 * @method removeLayer:
 * @abstract ￼Removes a layer from the map view.
 * @param layer ￼The layer.adddRetrievedRecrodsToLayer
 */
- (void) removeLayer:(SGLayer*)layer;

@end
