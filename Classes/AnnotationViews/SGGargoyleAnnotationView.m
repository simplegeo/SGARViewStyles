//
//  SGGargoyleAnnotationView.m
//  SGARViewStyles
//
//  Copyright (c) 2009-2010, SimpleGeo
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, 
//  this list of conditions and the following disclaimer. Redistributions 
//  in binary form must reproduce the above copyright notice, this list of
//  conditions and the following disclaimer in the documentation and/or 
//  other materials provided with the distribution.
//  
//  Neither the name of the SimpleGeo nor the names of its contributors may
//  be used to endorse or promote products derived from this software 
//  without specific prior written permission.
//   
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
//  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
//  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  Created by Derek Smith.
//

#import "SGGargoyleAnnotationView.h"
#import "SGSimpleAnnotation.h"

// The distance to update the the view
// when moving it in the AR environment.
static double delta = 0.000005;

@implementation SGGargoyleAnnotationView

@synthesize anchorManager;

- (id) initAtPoint:(CGPoint)point reuseIdentifier:(NSString*)reuseIdentifier
{
    if(self = [super initAtPoint:point reuseIdentifier:reuseIdentifier]) {
        
        self.targetType = kSGAnnotationViewTargetType_Custom;
        
        UIImageView* gargoyleImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Gargoyle.png"]];
        [self addSubview:gargoyleImageView];
        self.frame = CGRectMake(0.0, 0.0,
                                gargoyleImageView.image.size.width,
                                gargoyleImageView.image.size.height);
                
        [self.radarTargetButton setImage:[UIImage imageNamed:@"GargoyleTarget.png"] forState:UIControlStateNormal];
        anchorManager = nil;
        
        // Make this view invicible, i.e. do not let the user
        // capture it.
        self.isCapturable = NO;
        
        up = rand() % 2;
        left = rand() % 2;
    }
    
    return self;
}

/*
 * Override this method so we can adjust the location of the annotation
 * everytime it is accessed in the AR view; which is essentially everytime
 * it needs to be drawn.
 */
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
        // the max is 100m. So we stop short so we don't get stuck in a boundary.
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
