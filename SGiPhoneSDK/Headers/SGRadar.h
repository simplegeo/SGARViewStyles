//
// SGRadar.h
// SGLocatorServices
//
// Created by Derek Smith on 8/24/09.
// Copyright 2009 SimpleGeo. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SGAnnotationView.h"

/*!
* @enum SGCardinalDirection
* @abstract The four cardinal directions.
* @constant kSGCardinalDirection_North The north direction.
* @constant kSGCardinalDirection_East The east direction.
* @constant kSGCardinalDirection_South The south direction.
* @constant kSGCardinalDirection_West The west direction.
*/
enum SGCardinalDirection {
 
    kSGCardinalDirection_North = 0,
    kSGCardinalDirection_East,
    kSGCardinalDirection_South,
 	kSGCardinalDirection_West
 
};

typedef NSInteger SGCardinalDirection;

/*!
* @class SGRadar
* @abstract A radar shows the current heading of the device based on the true north value gathered from
* CoreLocation. It is also the job of the radar to display the @link //simplegeo/ooc/cl/SGRecordAnnotation SGRecordAnnotations @/link in
* the proper position based on their geographic coordinate and the current location of the device.
* @discussion ￼For every @link //simplegeo/ooc/cl/SGAnnotationView annotation view @/link that is registered with the @link //simplegeo/ooc/cl/SGARView SGARView @/link,
* the @link //simplegeo/ooc/instp/SGAnnotationView/radarTargetButton radarTargetButton @/link is added as a subview of this view.
*
* Both the heading and the radar can be represented by separate images. The default representation calls upon CoreGraphics to render the simple shapes.
* You can change the colors of the default representation by calling @link radarBorderColor radarBorderColor @/link, @link radarCircleColor radarCircleColor @/link
* and @link headingColor headingColor @/link. If no image is present in either 3 image views, the default representation will persist.
*/
@interface SGRadar : UIView {
 
    UIImageView* currentLocationImageView;
 	UIImageView* headingImageView;
 	UIImageView* radarBackgroundImageView;
 
 	BOOL rotatable;
 	BOOL shouldShowCardinalDirections;
 
    CGFloat cardinalDirectionOffset;
 
    UIColor* radarBorderColor;
    UIColor* radarCircleColor;
 
    UIColor* headingColor; 
 
}

/*!
* @property
* @abstract The image view that represents the the devices current location.
* @discussion The default image is a white plus sign.
*/
@property (nonatomic, readonly) UIImageView* currentLocationImageView;

/*!
* @property 
* @abstract The background image view of the radar.
*/
@property (nonatomic, readonly) UIImageView* radarBackgroundImageView;

/*!
* @property
* @abstract The image view that contains the image used for the heading.
*/
@property (nonatomic, readonly) UIImageView* headingImageView;

/*!
* @property
* @abstract Determines whether the radar rotates with the device. This is determined by the roll parameter in
* @link drawRadarWithHeading:roll: drawRadarWithHeading:roll: @/link.
*/
@property (nonatomic, assign) BOOL rotatable;

/*!
* @property
* @abstract Set this to YES to show all of the cardinal direction labels. Otherwise; NO. The default
* is YES.
* @discussion To hide individual labels, use @link labelForCardinalDirection: labelForCardinalDirection @/link.
*/
@property (nonatomic, assign) BOOL shouldShowCardinalDirections;

/*!
* @property
* @abstract The amount of pixel separation between a cardinal direction label and the radar image. A negative value will
* decrease the distance while a postivie value with increase the distance.
*/
@property (nonatomic, assign) CGFloat cardinalDirectionOffset;

/*!
* @property
* @abstract The border color of the circular radar. The default RGBA value is 0.6, 0.6, 0.6, 0,7. 
*/
@property (nonatomic, retain) UIColor* radarBorderColor;

/*!
* @property
* @abstract The color of the radar. The default RGBA value is 0.0, 0.0, 0.0, 0.7.
*/
@property (nonatomic, retain) UIColor* radarCircleColor;

/*!
* @property
* @abstract The color of the header circular segment. The default RGBA value is 1.0, 1.0, 1.0, 0.7.
*/
@property (nonatomic, retain) UIColor* headingColor;

/*!
* @method labelForCardinalDirection:
* @abstract ￼Returns the label associated with the @link SGCardinalDirection SGCardinalDirection @/link.
* @param direction ￼The direction of the desired label.
* @result ￼The label.
*/
- (UILabel*) labelForCardinalDirection:(SGCardinalDirection)direction;

/*!
* @method drawRadarWithHeading:roll:
* @abstract This method is called whenever the radar needs to redisplayed.
* @discussion Since the radar's orientation depends upon the heading and z axis orientation of the device,
* the view must be updated constantly. 
* @param heading ￼
* @param roll ￼
*/
- (void) drawRadarWithHeading:(double)heading roll:(double)roll;

@end
