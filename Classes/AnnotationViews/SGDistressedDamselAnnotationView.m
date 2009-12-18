//
//  SGDistressedDamselAnnotationView.m
//  ARViewStyles
//
//  Created by Derek Smith on 10/13/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGDistressedDamselAnnotationView.h"

@interface SGDistressedDamselAnnotationView (Private)

- (UIImage*) imageForDamsel:(SGDamsel)desiredDamsel;

@end


@implementation SGDistressedDamselAnnotationView

- (id) initAtPoint:(CGPoint)pt reuseIdentifier:(NSString *)identifier
{
    if(self = [super initAtPoint:pt reuseIdentifier:identifier]) {
        
        self.targetType = kSGAnnotationViewTargetType_Glass;
        self.inspectorType = kSGAnnotationViewInspectorType_Standard;
             
        [self.radarTargetButton setImage:[UIImage imageNamed:@"YellowExclamationMark.png"] forState:UIControlStateNormal];
        
        self.titleLabel.text = @"Help!!!";
        self.titleLabel.textColor = [UIColor redColor];
        
        // Put the view at ~eye-level
        self.altitude = 1.734;
        
        showingStats = NO;
        
        [self prepareForReuse];
    }
    
    return self;
}

- (void) prepareForReuse
{
    [super prepareForReuse];
    
    // Reset the damsel
    damsel = rand() % kSGDamsel_Amount;
    self.targetImageView.image = [self imageForDamsel:damsel];
}

- (void) showStats
{
    showingStats = !showingStats;
    [self inspectView:showingStats];
}

- (UIImage*) imageForDamsel:(SGDamsel)desiredDamsel
{
    NSString* damselImageName = @"";
    
    switch (desiredDamsel) {
            
        case kSGDamsel_Meg:
            damselImageName = @"Meg.png";
            break;
        case kSGDamsel_SnowWhite:
            damselImageName = @"SnowWhite.png";
            break;
        case kSGDamsel_Cinderella:
            damselImageName = @"Cinderella.png";
            break;
        case kSGDamsel_Jasmine:
            damselImageName = @"Jasmine.png";
            break;            
        default:
            break;
    }
    
    
    return [UIImage imageNamed:damselImageName];
}

@end
