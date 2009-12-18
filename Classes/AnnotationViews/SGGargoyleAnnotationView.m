//
//  SGGargoyleAnnotationView.m
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/22/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGGargoyleAnnotationView.h"
#import "SGSimpleAnnotation.h"

static double delta = 0.000005;

@implementation SGGargoyleAnnotationView

@synthesize anchorManager;

- (id) initAtPoint:(CGPoint)point reuseIdentifier:(NSString*)reuseIdentifier
{
    if(self = [super initAtPoint:point reuseIdentifier:reuseIdentifier]) {
        
        self.targetType = kSGAnnotationViewTargetType_Custom;
        self.inspectorType = kSGAnnotationViewTargetType_Custom;
        
        UIImageView* gargoyleImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Gargoyle.png"]];
        [self addSubview:gargoyleImageView];
        self.frame = CGRectMake(0.0, 0.0,
                                gargoyleImageView.image.size.width,
                                gargoyleImageView.image.size.height);
                
        [self.radarTargetButton setImage:[UIImage imageNamed:@"GargoyleTarget.png"] forState:UIControlStateNormal];
        anchorManager = nil;
        
        count = 0;
        
        self.isCapturable = NO;
        
        up = rand() % 2;
        left = rand() % 2;
    }
    
    return self;
}

// Override this puppy so we can adjust the location of the annotation
// everytime it is accessed in the AR view; which is essentially everytime
// it needs to be drawn.
- (id<SGAnnotation>) annotation
{
    SGSimpleAnnotation* simpleAnnotation = (SGSimpleAnnotation*)[super annotation];
    
    // Increment the gargoyle so it moves around the scene. 
    // We have to do it using lat/long.
    if(anchorManager) {
        
        CLLocationCoordinate2D newCoord = {simpleAnnotation.coordinate.latitude + (up ? -delta : delta),
                                            simpleAnnotation.coordinate.longitude + (left ? -delta : delta)};
        simpleAnnotation.coordinate = newCoord;
        
        // Make sure that the gargolye does not go out of
        // bounds.
        double anchorDistance = [anchorManager.location getDistanceFrom:[[[CLLocation alloc] initWithLatitude:simpleAnnotation.coordinate.latitude
                                                                             longitude:simpleAnnotation.coordinate.longitude] autorelease]];
        
        // Views do not get drawn if they are above the maximum, in this case
        // the max is 100m. So we stop short so we don't get the flashy effect.
        if(anchorDistance > 99.0) {
         
            left = !left;
            up = !up;
            
        }
        
    }   
    
    return simpleAnnotation;
}

- (void) dealloc
{
    [anchorManager release];
    
    [super dealloc];    
}

@end
