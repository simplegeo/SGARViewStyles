//
//  SGForestAnnotationView.h
//  ARViewStyles
//
//  Created by Derek Smith on 10/13/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGAnnotationView.h"

/*
 * The different types of forest creatures.
 */
enum SGForestCreature {
    
    kSGForestCreature_Bat = 0,
    kSGForestCreature_Dog,
    kSGForestCreature_Duck, 
    kSGForestCreature_Elephant,
    kSGForestCreature_Fox,
    kSGForestCreature_Frog,
    kSGForestCreature_Kitty,
    kSGForestCreature_Lion,    
    kSGForestCreature_Panda,
    kSGForestCreature_Penguin,
    kSGForestCreature_Rat,
    kSGForestCreature_Tuqui,
    
    kSGForestCreature_Amount
};

typedef NSInteger SGForestCreature;

@interface SGForestAnnotationView : SGAnnotationView {

    BOOL big;
    
    @private
    NSInteger forestCreature;
    UIImage* creatureImage;
}

@property (nonatomic, assign) BOOL big;

@end
