//
//  SGSimpleAnnotation.m
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/9/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGSimpleAnnotation.h"


@implementation SGSimpleAnnotation

@synthesize title, subtitle, coordinate;

- (id) initWithLocation:(CLLocationCoordinate2D)coord andDictionary:(NSDictionary*)dictionary
{
    if(self = [super init]) {
        
        self.title = [dictionary objectForKey:@"title"];
        self.subtitle = [dictionary objectForKey:@"subtitle"];
        coordinate = coord;
    }
    
    return self;
}

- (void) dealloc
{
    if(title)
        [title release];
    
    if(subtitle)
        [subtitle release];
    
    [super dealloc];
}

@end
