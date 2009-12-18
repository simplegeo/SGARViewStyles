//
//  SGPersonAnnotationView.m
//  ARViewStyles
//
//  Created by Derek Smith on 11/10/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGPersonAnnotationView.h"


@implementation SGPersonAnnotationView

- (id) initAtPoint:(CGPoint)pt reuseIdentifier:(NSString *)identifier
{
    if(self = [super initAtPoint:pt reuseIdentifier:identifier]) {

        
        UIImage* mashRadarImage = [UIImage imageNamed:@"MashRadar.png"];
        
        [self.radarTargetButton setImage:mashRadarImage forState:UIControlStateNormal];
        self.radarTargetButton.frame = CGRectMake(0.0, 0.0,
                                                  mashRadarImage.size.width,
                                                  mashRadarImage.size.height);
        
    }
    
    return self;
}


@end
