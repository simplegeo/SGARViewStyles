//
// SGRecordContainer.h
// SGLocatorServices
//
// Created by Derek Smith on 8/27/09.
// Copyright 2009 SimpleGeo. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SGAnnotationView.h"

@class SGARView;

/*!
* @class SGAnnotationViewContainer
* @abstract Containers provide a storage structure for @link //simplegeo/ooc/cl/SGRecordAnnotationView SGRecordAnnotationViews @/link in the AR view.
* @discussion The main intention of a container is to allow the user to be able to separate records from each other. Because there can be
* a high volume of records per location, users can drag views into containers until they reach the desired view.
*
* Containers are registered with the AR view by @link //simplegeo/ooc/instm/SGChromeManager/addContainer: addContainer: @/link.
*
*/
@interface SGAnnotationViewContainer : UIButton {
 
    BOOL rotatable;
 
    SGARView* arView; 
    
    UIImage* normalImage;
    UIImage* highlightedImage;
    
 
}

/*!
* @property
* @abstract The @link //simplegeo/ooc/cl/SGARView SGARView @/link that controls the container.
*/
@property (nonatomic, readonly) SGARView* arView;

/*!
 * @property
 * @abstract The image that represents the container in its normal state.
 * @discussion Setting this property will resize the container to the size
 * of the image. If nil is passed, then the size will stay the same.
 */
@property (nonatomic, retain) UIImage* normalImage;

/*!
 * @property
 * @abstract The image that represents the container in its highlighted state.
 * @discussion When a container experiences a UIControlEventTouchDrageEnter control
 * event, it will present this image. Set this proper to nil if you do not wish to have 
 * the container highlighted.
 */
@property (nonatomic, retain) UIImage* highlightedImage;

/*!
* @method addRecordAnnotationViews:
* @abstract ￼Adds an array of @link //simplegeo/ooc/cl/SGRecordAnnotationView annotation views @/link to the container.
* @param view ￼The array of views to add to the container.
*/
- (void) addRecordAnnotationViews:(NSArray*)view;

/*!
* @method getRecordAnnotationViews
* @abstract ￼ Returns the @link //simplegeo/ooc/cl/SGRecordAnnotationView record views @/link associated with the container.
* @result The record views associated with the container.￼
*/
- (NSArray*) getRecordAnnotationViews;

/*!
* @method getRecordAnnotations
* @abstract ￼Returns the @link //simplegeo/ooc/cl/SGRecordAnnotation SGRecordAnnotations @/link of all annotation views held by the container.
* @result ￼The annotations within the container.
*/
- (NSArray*) getRecordAnnotations;

/*!
* @method removeAnnotationView:
* @abstract ￼Removes a @link //simplegeo/ooc/cl/SGRecordAnnotationView annotation view @/link from the container.
* @param view ￼The view to remove.
*/
- (void) removeAnnotationView:(SGAnnotationView*)view;

/*!
* @method removeAllAnnotationViews
* @abstract ￼ Removes all annotations views held by the container.
*/
- (void) removeAllAnnotationViews;

/*!
* @method isEmpty
* @abstract ￼Determines whether the container is empty.
* @result ￼YES if the container is empty; otherwise NO.
*/
- (BOOL) isEmpty;


/*!
* @method shouldAddViews:
* @abstract This method is called before annotation views are added to the container. The default return
* value is YES.
* @param views ￼The @link //simplegeo/ooc/cl/SGAnnotationView annotation views @/link that will be added to
* the container.
* @result ￼YES if the views should be added to the container. Otherwise, NO.
*/
- (BOOL) shouldAddViews:(NSArray*)views;


@end

