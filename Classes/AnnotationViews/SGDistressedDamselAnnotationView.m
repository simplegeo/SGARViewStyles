//
//  SGDistressedDamselAnnotationView.m
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/13/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGDistressedDamselAnnotationView.h"

enum SGDamsel {
    
    kSGDamsel_Cinderella = 0,
    kSGDamsel_SnowWhite,
    kSGDamsel_Jasmine,
    kSGDamsel_Meg,
    
    kSGDamsel_Amount
};

typedef NSInteger SGDamsel;

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
        
        self.detailedLabel.textColor = [UIColor redColor];
        
        // Put the view at eye-level
        self.altitude = 3.0;
        
        showingStats = NO;
        
        [self prepareForReuse];
    }
    
    return self;
}

- (void) prepareForReuse
{
    [super prepareForReuse];
    damsel = rand() % kSGDamsel_Amount;
    
    self.targetImageView.image = [self imageForDamsel:damsel];
}

- (void) showStats
{
    showingStats = !showingStats;
    
    if(showingStats) {
     
        self.targetType = kSGAnnotationViewTargetType_Custom;
        
    } else {
        
        self.targetType = kSGAnnotationViewTargetType_Glass;
        
    }
    
    [self inspectView:NO];
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
