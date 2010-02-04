//
// SGMovableStack.h
// SGLocatorServices
//
// Created by Derek Smith on 8/27/09.
// Copyright 2010 SimpleGeo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SGAnnotationView.h"

/*!
 * @class
 * @abstract The view that appears when a drag event occurs over an @link //simplegeo/ooc/cl/SGAnnotationView SGAnnotationView @/link 
 * in the AR enviornment.
 * @discussion The movable stack will display its collected annotation views in a spilled card deck fashion. The first collected view
 * will be on top of the other views.
 *
 * To change how the stack is presented, override @link drawStackAtPoint:roll: drawStackAtPoint:roll @/link. This method 
 * will notify the stack when the origin of the stack has moved along with the orientation of the device.
*/
@interface SGMovableStack : UIView {
 
    NSInteger maxStackAmount; 
 
}

/*!
 * @property
 * @abstract The maximum number of allowed @link //simplegeo/ooc/cl/SGAnnotationView SGAnnotationViews @/link 
 * to collect. Defaults to 20.
 */
@property (nonatomic, assign) NSInteger maxStackAmount;

/*!
 * @method addAnnotationView:
 * @abstract ￼Adds an annotation view to the stack.
 * @discussion ￼If the movable stack is empty, adding an annotation view will add the stack
 * as a subview of the @link //simplegeo/ooc/cl/SGARView SGARView @/link.
 * @param view ￼The @link //simplegeo/ooc/cl/SGAnnotaitonView SGAnnotationView @/link to add to the movable stack.
 */
- (void) addAnnotationView:(SGAnnotationView*)view;

/*!
 * @method stack 
 * @abstract ￼ Returns an array of @link //simplegeo/ooc/cl/SGAnnotationView SGAnntationViews @/link that are
 * associated with the movable stack.
 * @result ￼ The views associated with the stack.
 */
- (NSArray*) stack;

/*!
 * @method emptyStack:
 * @abstract ￼Removes all @link //simplegeo/ooc/cl/SGAnnotationView SGAnnotationViews @/link from the stack.
 * @discussion When emptying a stack, there are two options. By passing in the value YES once the stack is emptied,
 * the views will return back to the AR enviornment. If you specify NO, then the views will no longer be present
 * in the AR enviornment.
 * @param stillCaptured ￼YES to keep the views alive in the AR enviornment. Otherwise; NO.
 */
- (void) emptyStack:(BOOL)stillCaptured;

/*!
 * @method drawStackAtPoint:
 * @abstract ￼Called everytime the stack is moved around on the @link //simplegeo/ooc/cl/SGARView SGARView @/link.
 * @discussion ￼Since the movable stack can move around as a subview of the @link //simplegeo/ooc/cl/SGARView SGARView @/link,
 * the position needs to be updated. 
 * @param point ￼The new point of the movable stack.
 * @param roll The roll orientation of the device.
 */
- (void) drawStackAtPoint:(CGPoint)point roll:(double)roll;

@end
