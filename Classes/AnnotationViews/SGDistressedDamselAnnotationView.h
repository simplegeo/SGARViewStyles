//
//  SGDistressedDamselAnnotationView.h
//  ARViewStyles
//
//  Created by Derek Smith on 10/13/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

/*
 * The different types of damsels.
 */
enum SGDamsel {
    
    kSGDamsel_Cinderella = 0,
    kSGDamsel_SnowWhite,
    kSGDamsel_Jasmine,
    kSGDamsel_Meg,
    
    kSGDamsel_Amount
};

typedef NSInteger SGDamsel;

@interface SGDistressedDamselAnnotationView : SGAnnotationView {

    SGDamsel damsel;
    
    @private
    BOOL showingStats;
}

- (void) showStats;

@end
