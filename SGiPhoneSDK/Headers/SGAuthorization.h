/*
 * SGAuthorization.h
 * SGiPhoneSDK
 *
 * Created by Derek Smith on 10/31/09.
 * Copyright 2009 SimpleGeo. All rights reserved.
 *
 */

/*!
 * @protocol
 * @abstract Encapsulates HTTP request sent from @link //simplegeo/ooc/cl/SGLocationService SGLocationService @/link 
 * with the proper authorization.
 * @discussion The only class that implemenets this protocol is @link //simplegeo/ooc/cl/SGOAuth SGOAuth @/link. The main uses of this
 * protocol is to add authentication to an HTTP request. Currently, the only type of authentication that is supported by
 * SimpleGeo is OAuth.
 */
@protocol SGAuthorization <NSObject>

@end
