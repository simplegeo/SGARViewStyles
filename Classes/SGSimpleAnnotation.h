//
//  SGSimpleAnnotation.h
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/9/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SimpleGeo.h"

@interface SGSimpleAnnotation : NSObject <SGAnnotation> {

    NSString* title;
    NSString* subtitle;
    
    CLLocationCoordinate2D coordinate;
}

@property (nonatomic, retain) NSString* title;
@property (nonatomic, retain) NSString* subtitle;
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

- (id) initWithLocation:(CLLocationCoordinate2D)coord andDictionary:(NSDictionary*)dictionary;

@end
