//
//  NSStringAdditions.h
//  SGLocatorServices
//
//  Created by Derek Smith on 7/5/09.
//  Copyright 2010 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (SimpleGeo) 

- (NSString *)URLEncodedString;
- (NSString *)MinimalURLEncodedString;
- (NSString *)URLDecodedString;

@end
