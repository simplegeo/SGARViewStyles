//
// SGCoverFlowView.h
// SGLocatorServices
//
// Created by Derek Smith on 8/20/09.
// Copyright 2010 SimpleGeo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>


@protocol SGAlbum;
@protocol SGCoverFlowViewDelegate;

/*!
* @class SGCoverFlowView
* @abstract Displays images along with small descriptions in a manner that resembles Apple's cover flow.
* @discussion This view recieves its data from @link addAlbum: addAlbum: @/link. All albums that are added
* to the view must conform to @link //simplegeo/ooc/intf/SGAlbum.
*
* To recieves a notificaiton when an album is selected within the view, you must add a delegate that conforms
* to @link SGCoverFlowViewDelegate SGCoverFlowViewDelegate @/link.
*
* The @link sliderBar sliderBar @/link is exposed to allow customization. The current bar is set to the default
* style. The cover flow view will only display 6 albums at a time, applying the proper transformations.
*/
@interface SGCoverFlowView : UIView {
    
    UISlider* sliderBar;
    
    UIButton* closeButton;
    
    UILabel* titleLabel;
    UILabel* subtitleLabel;
    
    id<SGCoverFlowViewDelegate> delegate;
    
    NSInteger amountOfViews;
    
    
}

/*!
* @property
* @abstract The slider bar that affects which cover is centered within the view.
*/
@property (nonatomic, readonly) UISlider* sliderBar;

/*!
* @property
* @abstract The close button that is in charge of removing the view.
*/
@property (nonatomic, readonly) UIButton* closeButton;

/*!
* @property
* @abstract The label that is located directly under the cover.
*/
@property (nonatomic, readonly) UILabel* titleLabel;

/*!
* @property
* @abstract The label that is located directly under the title label.
*/
@property (nonatomic, readonly) UILabel* subtitleLabel;

/*!
* @property
* @abstract The delegate that is notified when a user selects an album.
*/
@property (nonatomic, assign) id<SGCoverFlowViewDelegate> delegate;

/*!
* @property
* @abstract The amount of albums the SGCoverFlowView can contain.
*/
@property (nonatomic, assign) NSInteger amountOfViews;

/*!
* @method initWithFrame:maximumAlbums:
* @abstract ￼Initializes a new cover flow view.
* @param frame ￼The frame of the view.
* @param albumAmount ￼The maximum amount of albums to display at one time.
* @result ￼The cover flow view.
*/
- (id) initWithFrame:(CGRect)frame maximumAlbums:(NSInteger)albumAmount;

/*!
* @method addAlbum:
* @abstract ￼Adds an album to the cover flow view.
* @param album ￼The album to add.
*/
- (void) addAlbum:(id<SGAlbum>)album;

/*!
* @method removeAlbum:
* @abstract ￼Removes an album from the cover flow view.
* @param album ￼The album to remove.
*/
- (void) removeAlbum:(id<SGAlbum>)album;

/*!
* @method addAlbums:
* @abstract ￼Adds an array of albums to the cover flow view.
* @param albums ￼The array to add to the view.
*/
- (void) addAlbums:(NSArray*)albums;

/*!
* @method removeAllAlbums
* @abstract ￼ Removes all albums contained in the cover flow view.
*/
- (void) removeAllAlbums;

@end

/*!
* @protocol SGCoverFlowViewDelegate 
* @abstract Defines the single callback method that notifies when an album is
* selected.￼
*/
@protocol SGCoverFlowViewDelegate

/*!
* @method coverFlowView:didSelectAlbum:
* @abstract Called when an album has been selected from within the cover flow view.
* @param view ￼The cover flow view where the selection took place.
* @param album ￼The album that was selected.
*/
- (void) coverFlowView:(SGCoverFlowView*)view didSelectAlbum:(id<SGAlbum>)album;

@end

