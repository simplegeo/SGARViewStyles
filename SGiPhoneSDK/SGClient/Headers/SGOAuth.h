//
// SGOAuth.h
// SGClient
//
// Created by Derek Smith on 10/31/09.
// Copyright 2010 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGAuthorization.h"

@class SGLocationService;

/*!
 * @class SGOAuth 
 * @abstract ￼This class maintains a single 2-legged OAuth implementation.
 * @discussion ￼In order to use 2-legged OAuth @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link, you must set 
 * @link //simplegeo/ooc/instp/SGLocationService/HTTPAuthorizer HTTPAuthorizer @/link. All HTTP requests that come from
 * @link //simplegeo/ooc/cl/SGLocationService SGLLocationService @/link will be wrapped by this authorization protocol.
*/
@interface SGOAuth : NSObject <SGAuthorization> {

 
    NSString* secretKey;
    NSString* consumerKey;
 
    @private
    NSDictionary* oAuthParams;
}

/*!
 * @ property
 * @abstract The secret key.
 */
@property (nonatomic, readonly) NSString* secretKey;

/*!
 * @property
 * @abstract The consumer key.
 */
@property (nonatomic, readonly) NSString* consumerKey;

/*!
 * @method resume
 * @abstract ￼Initializes a new instance with the most recently used secret and consumer key.
 * @result ￼ A new instance of SGOAuth.
 */
+ (SGOAuth*) resume;

/*!
* @method save
* @abstract Stores the token in the user's standard defaults. ￼
*/
- (void) save;

/*!
* @method unSave
* @abstract Removes any token that is stored in the user's standard defaults.
*/
- (void) unSave;

/*!
 * @method initWithKey:secret:
 * @abstract ￼Initializes a new instance of SGOAuth with the proper credentials.
 * @param key ￼The consumer key.
 * @param secret ￼The secret key/
 * @result ￼A new instance of SGOAuth.
 */
- (id) initWithKey:(NSString *)key secret:(NSString *)secret;

@end
