//
// SGARView.h
// LocationDemo
//
// Created by Derek Smith on 8/7/09.
// Copyright 2010 SimpleGeo. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@class SGAnnotationView;
@class SGRadar;
@class SGMovableStack;
@class SGAnnotationViewContainer;

@protocol SGARViewDataSource;
@protocol SGAnnotation;
@protocol SGARResponder;

/*!
 * @class SGARView
 * @abstract Displays @link //simplegeo/ooc/intf/SGAnnotation SGAnnotations @/link in an augmented reality enviornment.
 * @discussion The main intention of this class is to be used as the cameraOverlayView for @link UIImagePickerController UIImagePickerController @/link
 * when the camera source type is selected. You can easily create this as a subview of another view and still achieve the same effect if 
 * you wish.
 *
 * The SRARView is responsible for rendering the entire augmented reality scene. The view asks the @link SGARViewDataSource data source @/link
 * for the annotations and their corresponding views.
 */
@interface SGARView : UIView
{
    id<SGARViewDataSource> dataSource;
 
    CLLocationManager* locationManager;
 
    SGRadar* radar;
 	SGMovableStack* movableStack;
 
 	BOOL enableWalking;
 	BOOL enableGridLines;
 
    UIColor* gridLineColor;
 
}


/*!
 * @property
 * @abstract See @link SGARViewDataSource data source @/link
 */
@property (nonatomic, assign) id<SGARViewDataSource> dataSource;

/*!
 * @property
 * @abstract The location manager that is used for obtaining the heading and location of the device.
 */
@property (nonatomic, readonly) CLLocationManager* locationManager;

/*!
 * @property
 * @abstract The @link //simplegeo/ooc/cl/SGRadar radar @/link that is associated with the AR view.
 */
@property (nonatomic, retain) SGRadar* radar;

/*!
 * @property
 * @abstract YES if gridlines should be drawn. Otherwize; NO. The default is NO.
 */
@property (nonatomic, assign) BOOL enableGridLines;

/*!
 * @property
 * @abstract Allows a user to move around in the AR view.
 * @discussion The notion of walking just means that the user is able to create touch events that will move them
 * in the direction at which they are facing in the AR enviornment. For example, if a user is facing North and they create a pinch
 * gesture, they will decrease the distance between their current position in the AR view to the records that
 * are displayed directly North of them. The change in position is reflected both in the AR enviornment and also in the @link radar radar @/link.
 *
 * The following gestures will generate the effect: pinch => forward, pull => backward, double tap => move forward 3 meters, and single tap => move
 * backward 3 meters.
 */
@property (nonatomic, assign) BOOL enableWalking;

/*!
 * @property
 * @abstract The color of the grid lines.
 */
@property (nonatomic, retain) UIColor* gridLineColor;

/*!
 * @property
 * @abstract The @link //simplegeo/ooc/cl/SGMovableStack movable stack @/link that is present when a drag event
 * is produced over a @link //simplegeo/ooc/cl/SGAnnotationView annotation view @/link within the AR enviornment.
 * @discussion If a movable to stack is present, it will be added as a subview of @link //simplegeo/ooc/cl/SGARView SGARView @/link. Set
 * this property to nil in order to not allow views to be collected.
 */
@property (nonatomic, retain) SGMovableStack* movableStack;


/*!
 * @method dequeueReuseableAnnotationViewWithIdentifier:
 * @abstract ￼Returns an unused, pre-allocate @link SGAnnotationView SGAnnotationView @/link view if one is available.
 * @discussion This methods behaves identically to that of UITableView's dequeue method. After a call
 * to @link reloadData reloadData @/link, the view will remove all views from the enviornment and
 * prepare them all for reuse.
 * @param viewId ￼The identifier associated with the desired annotation view.
 * @result ￼An unused object view; otherwise nil if there are none.
 */
- (SGAnnotationView*) dequeueReuseableAnnotationViewWithIdentifier:(NSString*)viewId;

/*!
 * @method reloadData
 * @abstract ￼ Removes all annotation views from the envoirnment and loads in a new data set from @link dataSource dataSource @/link.
 * @discussion Once reloadData is called, all annotaiton views are sent @link //simplegeo/ooc/instm/SGAnnotationView/prepareForReuse prepareForReuses @/link.
 * The views are then awaiting to be dequeue and resused.
 */
- (void) reloadData;

/*!
 * @method startAnimation
 * @abstract ￼ Begins rendering the AR enviornment.
 * @discussion ￼ See @link stopAnimation stopAnimation @/link
 */
- (void) startAnimation;

/*!
 * @method stopAnimation
 * @abstract ￼ Stops rendering the augment reality view.
 * @discussion ￼ You can use both this method and @link startAnimation startAnimation @/link to create
 * a freeze frame wihin the augmented reality or just to stop the rendering process altogether.
 * You must call @link clear clear @/link in order to reset the entire view.
 */
- (void) stopAnimation;

/*!
 * @method clear
 * @abstract ￼ Resets the view sending a release call to all annotation views.
 * @discussion This is much different then @link reloadData reloadData @/link. It does not go through the entire
 * process of asking the @link dataSource dataSource @/link for new annotations. It assumes that you no longer
 * want to display anything in the AR enviornment and that your only desire is to have a blank camera view.
 */
- (void) clear;

/*!
 * @method addResponder:
 * @abstract ￼Adds a @link //simplegeo/ooc/cl/SGARResponder responder @/link to the responder chain to be notified of incoming
 * touch events and gestures.
 * @param responder ￼The responder to add.
 */
- (void) addResponder:(id<SGARResponder>)responder;


/*!
 * @method removeResponder:
 * @abstract ￼Removes the a @link //simplegeo/ooc/cl/SGARResponder responder @/link from the responder chain.
 * @param responder ￼The responder to remove.
 */
- (void) removeResponder:(id<SGARResponder>)responder;

/*!
 * @method addContainer:
 * @abstract ￼Adds a new conatiner as a subview of the @link //simplegeo/ooc/cl/SGARView SGARView @/link.
 * @discussion If the container has served its purpose, call @link removeContainer: removeContainer: @/link to remove it from its
 * superview. If the view is hidden or transparent in some way, it is still liable for touch events.
 * @param container ￼The @//simplegeo/ooc/cl/SGAnnotationViewContainer SGAnnotationViewContainer @/link. 
 */
- (void) addContainer:(SGAnnotationViewContainer*)container;

/*!
 * @method removeContainer:
 * @abstract Remove the conatiner from its superview and unregister it from touch events.
 * @param container ￼The @//simplegeo/ooc/cl/SGAnnotationViewContainer SGAnnotationViewContainer @/link to remove.
 */
- (void) removeContainer:(SGAnnotationViewContainer*)container;


/*!
 * @method getContainers
 * @abstract ￼ Returns all @link //simplegeo/ooc/cl/SGAnnotationViewContainer SGAnnotationViewContainers @/link that are currently
 * registered with the @link //simplegeo/ooc/cl/SGARView SGARView @/link.
 * @result ￼ An array of @link //simplegeo/ooc/cl/SGAnnotationViewContainer SGAnnotationViewContainers @/link.
 */
- (NSArray*) getContainers;

@end

/*!
 * @protocol SGARViewDataSource
 * @abstract Responsible for providing all the annotations and their views.
 */
@protocol SGARViewDataSource <NSObject>

/*!
 * @method arView:annotationsAtLocation:
 * @abstract ￼Provides the annotations for the location.
 * @param arView The @link SGARView AR view @/link that needs annotations.
 * @param location ￼The location.
 * @result ￼An array of @link //simplegeo/ooc/cl/SGAnnotation annotations @/link.
 */
- (NSArray*) arView:(SGARView*)arView annotationsAtLocation:(CLLocation*)location;

/*!
 * @method arView:viewForAnnotation:
 * @abstract ￼Provides the view for the specified @link //simplegeo/ooc/cl/SGAnnotation annotation @/link.
 * @discussion This allows the data source to prepare the annotation for display (e.g. changing location, title). You can also
 * return a nil value which would not display a view for the specified annotation.
 * @param arView ￼The @link SGARView AR view @/link that needs views for its annotaitons.
 * @param annotation The annotation that nee￼ds a view.
 * @result ￼The view for the annotation.
 */
- (SGAnnotationView*) arView:(SGARView*)arView viewForAnnotation:(id<SGAnnotation>)annotation;

@optional

/*!
 * @method arView:didAddAnnotationViews:
 * @abstract ￼Notifies the delegate when @link //simplegeo/ooc/cl/SGAnnotationView SGAnnotationViews @/link have
 * been added to the arView.
 * @param arView ￼The @link SGARView SGARView @/link that added the annotation views.
 * @param views ￼The annotation views.
 */
- (void) arView:(SGARView*)arView didAddAnnotationViews:(NSArray*)views;

@end

