/*
* SGARResponder.h
* SGiPhoneSDK
*
* Created by Derek Smith on 10/13/09.
* Copyright 2010 SimpleGeo. All rights reserved.
*
*/


/*!
* @protocol SGARResponder
* @abstract Defines￼ the protocol for objects to respond to gesture and touch events created in the @link //simplegeo/ooc/cl/SGARView SGARView @/link.
* @discussion There are essentially two different enviornments where touch evenets can be generated, the augmented reality enviornment and the 
* normal UIResponder chain. In order to loop in the AR envoirnment with the UIResponder chain, pre-calculations of touch events need to be
* acknowledged by the the AR view before they can be released onto the normal UIResponder chain. This protocol attempts to provides callback
* notifications when gestures are created within the AR envoirnment.
*
* SGARResponders are registered with @link //simplegeo/ooc/cl/SGARView SGARView @/link via
* @link //simplegeo/ooc/instm/SGARView/addResponder: addResponder: @/link.
*/
@protocol SGARResponder <NSObject>

@optional

/*!
* @method ARSingleTap:
* @abstract Notifies the reciever when a single touch event has occurred.
* @param point ￼The point at which the touch event occurred.
*/
- (void) ARSingleTap:(CGPoint)point;

/*!
* @method ARDoubleTap:
* @abstract ￼Notifies the reciever when a double touch event has occurred.
* @param point ￼The point at which the touch event occurred.
*/
- (void) ARDoubleTap:(CGPoint)point;


/*!
* @method ARSingleTapAtPoint:andPoint:
* @abstract Notifies the reciever when a single touch event occurs at two points.
* @param pointOne ￼One of the two points at which the touch event occurred.
* @param pointTwo ￼The other point at which the touch event occurred.
*/
- (void) ARSingleTapAtPoint:(CGPoint)pointOne andPoint:(CGPoint)pointTwo;

/*!
* @method ARPinchAtPoint:andPoint:withDistance:
* @abstract Notifies the reciever when a pinch event occurs.
* @param pointOne ￼One of the two points at which the touch event occurred.
* @param pointTwo ￼The other point at which the touch event occurred.
* @param distance ￼The distance between the two points. Why? For convience.
*/
- (void) ARPinchAtPoint:(CGPoint)pointOne andPoint:(CGPoint)pointTwo withDistance:(CGFloat)distance;

/*!
* @method ARPullAtPoint:andPoint:withDistance:
* @abstract Notifies the reciever when a pull event occurs.
* @param pointOne ￼One of the two points at which the touch event occurred.
* @param pointTwo ￼The other point at which the touch event occurred.
* @param distance ￼The distance between the two points. Why? Because I can.
*/
- (void) ARPullAtPoint:(CGPoint)pointOne andPoint:(CGPoint)pointTwo withDistance:(CGFloat)distance;

/*!
* @method ARMoveFromPoint:toPoint:
* @abstract Notifies the reciever when a drag event occurs.
* @param fromPoint ￼The start point of the drag.
* @param toPoint ￼The end point of the drag.
*/
- (void) ARMoveFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint;

/*!
* @method ARMoveEndedAtPoint:
* @abstract Notifies the reicever when a drag events finishs.
* @param point ￼The point at which the drag event was completed.
*/
- (void) ARMoveEndedAtPoint:(CGPoint)point;

/*!
* @method ARViewDidShake
* @abstract Notifies the reciever when the view is shaken.
*/
- (void) ARViewDidShake;

@end
