/*
* SGAlbum.h
* SGLocatorServices
*
* Created by Derek Smith on 8/20/09.
* Copyright 2010 SimpleGeo. All rights reserved.
*/

#import <UIKit/UIKit.h>

/*!
* @protocol SGAlbum
* @abstract Defines an album that is used in @link //simplegeo/ooc/cl/SGCoverFlowView SGCoverFlowView @/link ￼
* @discussion The @link //simplegeo/ooc/cl/SGCoverFlowView SGCoverFlowView @/link uses this protocol in
* in order to display items. The @link coverImage coverImage @/link will be displayed in the view when
* the album is in range. The @link title title @/link and @link subtitle subtitle @/link are displayed
* below the coverImage whenever the album is centered in the view.
*/
@protocol SGAlbum

@required

/*!
* @method coverImage   ￼ 
* @result ￼The image to be displayed in the @link //simplegeo/ooc/cl/SGCoverFlowView SGCoverFlowView @/link.
*/
- (UIImage*) coverImage;

/*!
* @method title
* @result ￼The title to be displayed under the image.
*/
- (NSString*) title;

/*!
* @method subtitle
* @result The subtitle to be displayed under the title.
*/
- (NSString*) subtitle;

@end
